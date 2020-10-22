#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <string>
#include "main.h"

// Extract The String
std::string ExtractTheStrDblQt(std::string lineString, std::string stringId)
{
	std::string extStr;
	//@pram: string for Extraction 
	auto GetStringPos = [&](std::string strForExt) {
		return static_cast<int>(lineString.find(strForExt));
	};
	auto chrPos = GetStringPos(stringId);


	if (chrPos != std::string::npos)
	{
		chrPos += static_cast<int>(stringId.length());
		//std::cout << chrPos << std::endl;
		auto idx = 0;		//double quotation  counter
		while (chrPos < lineString.length())
		{
			auto checkChar = lineString.at(chrPos);
			if (checkChar == '"') { idx++; 	chrPos++; }
			if (idx == 1)
			{
				checkChar = lineString.at(chrPos);
				if (checkChar == '"')
				{
					idx++;
				}
				else
				{
					extStr.push_back(checkChar);
				}
			}

			if (idx >= 2) { break; }
			chrPos++;
		}

	}

	return extStr;
}

int main()
{
	TMX_File tmxFile;
	std::string lineString;
	std::stringstream ss;
	auto filePos = 0;
	
	std::fstream FileStream("map.tmx", std::ios_base::in);

	auto opened = FileStream.is_open();

	if (!opened)
	{
		std::cout << "tmx file open failed!" << std::endl;
		return 0;
	}
	else {
		std::cout << "tmx file open succeed!" << std::endl;
	}

	auto Escape = [&]() {if (FileStream.eof()) { return false; }return true; };

	//@pram: string for Extraction 
	auto GetStringPos = [&](std::string strForExt) {
		return static_cast<int>(lineString.find(strForExt));
	};

	std::string line;

	while (Escape())
	{
		
		std::cout << lineString << std::endl;

		if (tmxFile.mode_ == ReadTmxMode::INIT)
		{
			std::getline(FileStream, lineString);
			if (tmxFile.encoding.length() == 0)
			{
				tmxFile.encoding=ExtractTheStrDblQt(lineString, "encoding");
				if(tmxFile.encoding.length() != 0)
				std::cout << tmxFile.encoding << std::endl;
			}
			
			if (tmxFile.orthogonal.length() == 0)
			{
				tmxFile.orthogonal = ExtractTheStrDblQt(lineString, "orientation");
				if (tmxFile.orthogonal.length() != 0)
					std::cout << "orientation:" << tmxFile.orthogonal << std::endl;
			}

			if (tmxFile.width_== 0)
			{
				tmxFile.width_ = atoi(ExtractTheStrDblQt(lineString, "width").data());
				if (tmxFile.width_ != 0)
					std::cout << "width:" << tmxFile.width_ << std::endl;
			}

			if (tmxFile.height_ == 0)
			{
				tmxFile.height_ = atoi(ExtractTheStrDblQt(lineString, "height").data());
				if (tmxFile.height_ != 0)
					std::cout << "height:" << tmxFile.height_ << std::endl;
			}

			if (tmxFile.tilewidth_ == 0)
			{
				tmxFile.tilewidth_ = atoi(ExtractTheStrDblQt(lineString, "tilewidth").data());
				if (tmxFile.tilewidth_ != 0)
					std::cout << "tilewidth:" << tmxFile.tilewidth_ << std::endl;
			}

			if (tmxFile.tileheight_ == 0)
			{
				tmxFile.tileheight_ = atoi(ExtractTheStrDblQt(lineString, "tileheight").data());
				if (tmxFile.tileheight_ != 0)
					std::cout << "tileheight:" << tmxFile.tileheight_ << std::endl;
			}

			if (tmxFile.nextlayerid_ == 0)
			{
				tmxFile.nextlayerid_ = atoi(ExtractTheStrDblQt(lineString, "nextlayerid").data());
				if (tmxFile.nextlayerid_ != 0)
					std::cout << "nextlayerid:" << tmxFile.nextlayerid_ << std::endl;
			}

			if (lineString.find(" </editorsettings>") != std::string::npos)
			{
				tmxFile.mode_ = ReadTmxMode::GENERATE;
			}
		}

		if (tmxFile.mode_ == ReadTmxMode::GENERATE)
		{
			std::getline(FileStream, lineString);

			std::string str;

			if (lineString.find("layer") != std::string::npos)
			{
				tmxFile.name_.push_back(ExtractTheStrDblQt(lineString, "name"));
				str=tmxFile.name_.back();
				tmxFile.tiledMap_.try_emplace(str, Tiled_Map());
			}
			if (tmxFile.name_.size() != 0) { str = tmxFile.name_.back(); }

			if (str.length() != 0)
			{
				if (lineString.find("data encoding")!=std::string::npos)
				{
					tmxFile.tiledMap_[str].dataEncoding_ = ExtractTheStrDblQt(lineString, "data encoding");
					if(tmxFile.tiledMap_[str].dataEncoding_.length()!=0)


						std::cout << tmxFile.tiledMap_[tmxFile.name_.back()].dataEncoding_ << std::endl;
					// embed the ID of the tile in this area.
					if (tmxFile.tiledMap_[tmxFile.name_.back()].dataEncoding_ == "csv")
					{
						tmxFile.tiledMap_[tmxFile.name_.back()].height_ = tmxFile.height_;
						tmxFile.tiledMap_[tmxFile.name_.back()].width_ = tmxFile.width_;
						if (tmxFile.tiledMap_[tmxFile.name_.back()].height_ != 0 &&
							tmxFile.tiledMap_[tmxFile.name_.back()].width_ != 0)
						{
							tmxFile.tiledMap_[tmxFile.name_.back()].prepreateTiles();
							tmxFile.mode_ = ReadTmxMode::INSERT;
							continue;
						}
						else
						{
							std::cout << "failed Inited!" << std::endl;
							std::cin.get();
							return -1;
						}
					}
				}
			}

		}

		if (tmxFile.mode_ == ReadTmxMode::INSERT)
		{
			auto idx = 0;
			tmxFile.mode_ = ReadTmxMode::GENERATE;
			while (idx <= tmxFile.tiledMap_[tmxFile.name_.back()].height_)
			{
				std::cout << "lineString:" << lineString << std::setw(20) << idx << std::endl;
				std::getline(FileStream, lineString);
				tmxFile.tiledMap_[tmxFile.name_.back()].SetTiles(idx,
					tmxFile.tiledMap_[tmxFile.name_.back()].width_, lineString);

				idx++;
			}

			std::getline(FileStream, lineString);
			std::cout << lineString << std::setw(20) << std::endl;

			while (lineString.find("</layer>")==std::string::npos)
			{
				std::cout  << lineString << std::setw(20) << std::endl;
			}
		}
	std::cin.get();
	}
	std::cin.get();
}

void Tiled_Map::prepreateTiles()
{
	titleData_.resize(static_cast<size_t>(width_ * height_));
	for (unsigned int idx = 0; idx < width_; idx++)
	{
		titleID_.emplace_back(&titleData_[idx * height_]);
	}
}

void Tiled_Map::SetTiles(int y, int width, std::string lineString)
{
	std::string num;
	std::stringstream ss;
	ss << lineString;

	for (int x = 0; x < width; x++)
	{
		std::getline(ss, num, ',');
		titleID_[x][y] = atoi(num.data());
		std::cout << titleID_[x][y];

	}
	std::cout << std::endl;
}
