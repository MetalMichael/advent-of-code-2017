// Day8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include<map>

using namespace std;

vector<string> splitString(string s, char delim) {
	vector<string> result;
	istringstream iss(s);

	for (string token; getline(iss, token, delim); ) {
		result.push_back(std::move(token));
	}

	return result;
}

int getValueFromRegister(map<string, int> reg, string key) {
	if (reg.find(key) != reg.end()) {
		return reg[key];
	}
	return 0;
}

int processInstructions(vector<string> instructions) {

	map<string, int> registerValues;
	int maxValue = 0;

	for each (auto instruction in instructions) {
		auto parts = splitString(instruction, ' ');

		string target = parts[0];
		string op = parts[1];
		int value = stoi(parts[2]);

		string compTarget = parts[4];
		string comparator = parts[5];
		int compValue = stoi(parts[6]);

		bool result = false;
		if (comparator == ">") {
			result = getValueFromRegister(registerValues, compTarget) > compValue;
		} else if (comparator == ">=") {
			result = getValueFromRegister(registerValues, compTarget) >= compValue;
		} else if (comparator == "<") {
			result = getValueFromRegister(registerValues, compTarget) < compValue;
		} else if (comparator == "<=") {
			result = getValueFromRegister(registerValues, compTarget) <= compValue;
		} else if (comparator == "==") {
			result = getValueFromRegister(registerValues, compTarget) == compValue;
		} else if (comparator == "!=") {
			result = getValueFromRegister(registerValues, compTarget) != compValue;
		} else {
			cout << "Unknown comparator: " << comparator;
		}

		if (!result) {
			continue;
		}

		int newValue;
		if (op == "inc") {
			registerValues[target] += value;
			if (registerValues[target] > maxValue) {
				maxValue = registerValues[target];
			}
		} else if (op == "dec") {
			registerValues[target] -= value;
			if (registerValues[target] > maxValue) {
				maxValue = registerValues[target];
			}
		} else {
			cout << "Unknown operator: " << op;
		}
	}

	int max = 0;
	for (auto it = registerValues.begin(); it != registerValues.end(); it++) {
		if (it->second > max) {
			max = it->second;
		}
	}

	//return max;
	return maxValue;
}

int main()
{
	ifstream myfile("input.txt");
	string line;

	vector<string> instructions;

	if (myfile.is_open()) {
		while (myfile.good()) {
			getline(myfile, line);

			instructions.push_back(line);
		}
		myfile.close();
	} else {
		cout << "Unable to open file";
	}

	int max = processInstructions(instructions);

	cout << "Total: " << max;

	string _;
	cin >> _;

	return 0;
}

