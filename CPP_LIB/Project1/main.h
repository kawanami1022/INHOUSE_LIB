#pragma once
#include <unordered_map>
#include <memory>
#include <string>

struct Tiled_Map
{
	unsigned int width_;
	unsigned int height_;
	std::unique_ptr<int> titleID_;
	std::string dataEncoding_;
	std::string layerName_;
};

struct TMX_File
{
public:
	std::string encoding;
	std::string orthogonal;
	
	std::vector<std::string> layerName_;
	std::unordered_map<std::string, Tiled_Map> tiledMap_;
	unsigned int layer_;

	int tileSizeWidth_;
	int tileSizeHeight_;
};