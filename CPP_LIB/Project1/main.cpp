#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <string>
#include "main.h"

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
		std::getline(FileStream, lineString);
		std::cout << lineString << std::endl;

		std::string stringId = "encoding";
		auto chrPos = GetStringPos(stringId);


		if (chrPos != std::string::npos)
		{
			chrPos += stringId.length();
			std::cout << chrPos << std::endl;
			auto idx = 0;		//double quotation  counter
			while (chrPos<lineString.length())
			{
				auto checkChar = lineString.at(chrPos);
				if (checkChar == '"') { idx++; }
				if (idx == 1)
				{
					chrPos++;
					checkChar = lineString.at(chrPos);
					if (checkChar == '"')
					{
						idx++;
					}
					else
					{
						tmxFile.encoding.push_back(checkChar);
					}
				}
			
				if (idx >= 2) { break; }
				chrPos++;
			}
			std::cout << tmxFile.encoding << std::endl;

		}

		if (lineString.find("width") != std::string::npos)
		{

		}

		if (lineString.find("height") != std::string::npos)
		{

		}

		if (lineString.find("tilewidth") != std::string::npos)
		{

		}

		if (lineString.find("tileheight") != std::string::npos)
		{

		}

		if (lineString.find("nextlayerid") != std::string::npos)
		{

		}

	std::cin.get();
	}
	std::cin.get();
}

