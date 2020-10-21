#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include "main.h"

using namespace std;
int main()
{
	TMX_File tmxFile;

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
	
	FileStream.getline()

	//while ()
	//{

	//	if (FileStream.eof())
	//	{
	//		break;
	//	}
	//}
	
}

