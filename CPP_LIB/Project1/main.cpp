#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;
int main()
{

	auto filePos = 0;
	
	std::fstream FileStream("map.tmx", std::ios_base::in);
	auto opened = FileStream.is_open();
	if (!opened)
	{
		std::cout << "tmx file open failed!" << std::endl;
	}
	else {
		std::cout << "tmx file open succeed!" << std::endl;
	}

	if (FileStream.eof())
	{
		
	}
	
}

