#pragma once
#include <string>
#include <filesystem>
#include<fstream>

class MergeSub
{
private:
	std::string FileName1;
	std::string FileName2;
	std::string MergedStr1;
	std::string MergedStr2;
public:
	bool readFile();
	bool writeFile();
	bool searchFileName();
};

