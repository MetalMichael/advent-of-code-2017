// Day6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <sstream>

using namespace std;

vector<string> splitString(string s, char delim) {
	vector<string> result;
	istringstream iss(s);

	for (string token; getline(iss, token, delim); ) {
		result.push_back(std::move(token));
	}

	return result;
}

vector<int> reallocateBlocks(vector<int> blocks) {
	int maxIndex = 0;
	int maxValue = 0;
	int length = blocks.size();

	for (int i = 0; i < length; i++) {
		if (blocks[i] > maxValue) {
			maxValue = blocks[i];
			maxIndex = i;
		}
	}

	blocks[maxIndex] = 0;
	int pos = maxIndex;
	while (maxValue > 0) {
		pos = (pos + 1) % length;
		blocks[pos]++;
		maxValue--;
	}

	return blocks;
}

string getKey(vector<int> blocks) {
	string key = "";
	for each (auto block in blocks) {
		if (key != "") {
			key += ",";
		}
		key += block;
	}
	return key;
}

int main() {
	const string input = "10 3 15 10 5 15 5 15 9 2 5 8 5 2 3 6";

	set<string> previousPatterns;
	vector<string> previousPatternsList;
	vector<int> currentPattern;

	auto parts = splitString(input, ' ');
	for each (auto part in parts) {
		currentPattern.push_back(stoi(part));
	}

	string key;
	while (true) {
		key = getKey(currentPattern);

		if (previousPatterns.find(getKey(currentPattern)) != previousPatterns.end()) {
			break;
		}

		previousPatterns.insert(key);
		previousPatternsList.push_back(key);
		currentPattern = reallocateBlocks(currentPattern);
	}

	cout << "First repeat: ";
	for each (auto blockCount in currentPattern) {
		cout << blockCount << " ";
	}

	int total = previousPatterns.size();
	cout << "\nRepeat times: " << total;
	cout << "\nTimes since last: ";
	for (int i = 0; i < total; i++) {
		if (previousPatternsList[i] == key) {
			cout << (total - i);
			break;
		}
	}

	string _;
	cin >> _;

    return 0;
}