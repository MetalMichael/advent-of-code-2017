// Day10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

const int TARGET_LENGTH = 256;

vector<int> splitInput(string s) {
	vector<int> result;
	istringstream iss(s);

	for (string token; getline(iss, token, ','); ) {
		result.push_back(stoi(move(token)));
	}

	return result;
}

vector<int> createTarget() {
	vector<int> target(TARGET_LENGTH);
	for (int i = 0; i < TARGET_LENGTH; i++) {
		target[i] = i;
	}
	return target;
}

int main() {
	const string input = "192,69,168,160,78,1,166,28,0,83,198,2,254,255,41,12";
	const string input2 = "3,4,1,5";

	auto target = createTarget();
	auto lengths = splitInput(input);
	int skip = 0;
	int currentIndex = 0;

	for each (int length in lengths) {
		
		auto originalList = vector<int>();
		int index = currentIndex;
		for (int i = length; i > 0; i--) {
			originalList.push_back(target[index]);
			
			index = (index + 1) % TARGET_LENGTH;
		}
		reverse(originalList.begin(), originalList.end());

		index = currentIndex;
		for each (int value in originalList) {
			target[index] = value;
			index = (index + 1) % TARGET_LENGTH;
		}

		currentIndex = (currentIndex + length + skip++) % TARGET_LENGTH;
	}

	cout << "Result: " << (target[0] * target[1]);

	string _;
	cin >> _;
    return 0;
}

