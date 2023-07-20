#include <iostream>
#include "MergeSub.h"

bool MergeSub::readFile()
{
	std::ifstream is1;
	std::ifstream is2;
	std::string line1;
	std::string line2;
	is1.open(FileName1);
	is2.open(FileName2);
	
	while (getline(is1, line1) && getline(is2, line2)) {
		if (line1 == line2) {
			MergedStr1 += line1 + '\n';
			MergedStr2 += line2 + '\n';
		}
		else {
			MergedStr1 += line1 + '\n' + line2 + '\n';
			MergedStr2 += line2 + '\n' + line1 + '\n';
		}
	}
	is1.close();
	is2.close();
	return true;
}

bool MergeSub::searchFileName()
{
	bool ret;
	for (auto& i : std::filesystem::directory_iterator(".")) {
		if (".srt" == i.path().extension() && "updown.srt" != i.path().filename() && "downup.srt" != i.path().filename()) {
			if(FileName1 == "") {
				FileName1 = i.path().string();
			}
			else {
				FileName2 = i.path().string();
			}
		}
	}
	std::cout << "Original Subtitle file1: " << FileName1 << "\n" << "Original Subtitle file2: "<<FileName2 << std::endl;
	ret = (FileName1 == "" || FileName2 == "") ? false : true;
	if (ret == false) {
		std::cout << "Cannot Load .srt Subtitle file(Except for updown.srt and downup.srt), Press Enter to quit£¡" << std::endl;
		std::cin.clear();
		std::cin.sync();
		std::cin.get();
		std::exit(-1);
	}
	return ret;
}

bool MergeSub::writeFile()
{
	std::ofstream os;
	os.open("updown.srt");
	os << MergedStr1;
	os.close();
	os.open("downup.srt");
	os << MergedStr2;
	os.close();
    return false;
}
