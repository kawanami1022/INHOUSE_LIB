#pragma once
#include <iostream>
 struct Functional1
{
	bool operator()()
	{
		std::cout << "Functional1" << std::endl;
		return true;
	}
};

struct Functional2{
	bool operator()(){
		std::cout << "Functional2" << std::endl;
		return true;
	}
};