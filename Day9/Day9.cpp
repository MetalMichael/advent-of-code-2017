// Day9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include<map>

using namespace std;

int parseInput(string input) {
	int total = 0;
	int currentLevel = 0;
	int garbageCount = 0;

	const int length = input.length();
	int pos = 0;
	bool isGarbage = false;
	while (pos < length) {
		char c = input[pos++];

		if (isGarbage) {
			if (c == '>') {
				isGarbage = false;
			} else if (c == '!') {
				pos++;
			} else {
				garbageCount++;
			}
		} else if (c == '{') {
			currentLevel++;
			total += currentLevel;
		} else if (c == '}') {
			currentLevel--;
		} else if (c == '<') {
			isGarbage = true;
		} else if (c == '!') {
			pos++;
		}
	}
	
	// return total;
	return garbageCount;
}

int main() {
	ifstream myfile("input.txt");
	string input;

	if (myfile.is_open()) {
		while (myfile.good()) {
			getline(myfile, input);	
		}
		myfile.close();
	} else {
		cout << "Unable to open file";
	}

	int total = parseInput(input);

	cout << "Total: " << total;

	string _;
	cin >> _;

	return 0;
}