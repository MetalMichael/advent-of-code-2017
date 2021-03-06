// Day4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <sstream>
#include <fstream>

using namespace std;

vector<string> splitString(string s, char delim) {
	vector<string> result;
	istringstream iss(s);

	for (string token; getline(iss, token, delim); )
	{
		result.push_back(std::move(token));
	}

	return result;
}

bool isValidPassphrase(string passphrase) {
	auto parts = splitString(passphrase, ' ');

	set<string> existing;
	for each (auto part in parts) {
		if (existing.find(part) != existing.end()) {
			return false;
		}
		existing.insert(part);
	}
	return true;
}

bool areAnagrams(string str1, string str2) {
	vector<int> char1Count(255);
	vector<int> char2Count(255);

	for each (char c in str1) {
		char1Count[c] ++;
	}
	for each (char c in str2) {
		char2Count[c] ++;
	}

	for (int i = 0; i < 255; i++) {
		if (char1Count[i] != char2Count[i]) {
			return false;
		}
	}

	return true;
}

bool isValidPassphrase2(string passphrase) {
	auto parts = splitString(passphrase, ' ');

	vector<string> existing;
	for each (auto part in parts) {
		for each (auto existing in existing) {
			if (areAnagrams(part, existing)) {
				return false;
			}
		}
		existing.push_back(part);
	}
	return true;
}

int main()
{
	ifstream myfile("input.txt");
	string line;
	int total = 0;

	if (myfile.is_open()) {
		while (myfile.good()) {
			getline(myfile, line);

			bool res = isValidPassphrase2(line);
			if (res) {
				total++;
			}
		}
		myfile.close();
	} else {
		cout << "Unable to open file";
	}

	cout << "Total: " << total;

	string _;
	cin >> _;

    return 0;
}

