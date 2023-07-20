#include <iostream>
#include "MergeSub.h"
using namespace std;

int main()
{
	MergeSub merge;
	merge.searchFileName();
	merge.readFile();
	merge.writeFile();
	cout << "Merge Compelete, Please check the files(updown.srt && downup.srt), Press Enter to quit!" << endl;
	cin.clear();
	cin.sync();
	cin.get();
	return 0;
}