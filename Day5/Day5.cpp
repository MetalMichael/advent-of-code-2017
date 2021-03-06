// Day5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <sstream>
#include <fstream>

using namespace std;

int processInstructions(vector<int> instructions) {
	int count = 0;
	int currentIndex = 0;
	int oldIndex;
	int totalLength = instructions.size();

	while (currentIndex > -1 && currentIndex < totalLength) {
		//currentIndex += instructions[currentIndex]++;
		oldIndex = currentIndex;
		currentIndex += instructions[currentIndex];
		if (instructions[oldIndex] >= 3) {
			instructions[oldIndex]--;
		} else {
			instructions[oldIndex]++;
		}
		count++;
	}

	return count;
}

int main()
{
	ifstream myfile("input.txt");
	string line;

	vector<int> instructions;

	if (myfile.is_open()) {
		while (myfile.good()) {
			getline(myfile, line);

			instructions.push_back(stoi(line));
		}
		myfile.close();
	} else {
		cout << "Unable to open file";
	}

	int count = processInstructions(instructions);

	cout << "Total: " << count;

	string _;
	cin >> _;

    return 0;
}

