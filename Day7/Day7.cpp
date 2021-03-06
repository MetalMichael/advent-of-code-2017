// Day7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Program.h"
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <sstream>
#include <fstream>

using namespace std;


int main() {
	ifstream myfile("input.txt");
	string line;

	map<string, Program> programs;

	if (myfile.is_open()) {
		while (myfile.good()) {
			getline(myfile, line);

			Program program;
			program.setup(line);

			programs[program.getName()] = program;
		}
		myfile.close();
	} else {
		cout << "Unable to open file";
	}

	map<string, Program>::iterator it;
	for (it = programs.begin(); it != programs.end(); it++) {
		for each (auto child in it->second.getChildren()) {
			programs[child].setParent(&it->second);
		}
	}

	Program* rootNode = 0;
	for (it = programs.begin(); it != programs.end(); it++) {
		if (it->second.getParent() == 0) {
			rootNode = &it->second;
			cout << "Root node: " << it->first << endl;
			break;
		}
	}

	for (it = programs.begin(); it != programs.end(); it++) {
		int weight = -1;
		map<string, int> childWeights;
		map<int, int> weightOccurrances;
		for each (auto childName in it->second.getChildren()) {
			Program* child = &programs[childName];
			int weight = child->calculateTotalWeight(programs);
			childWeights[child->getName()] = weight;
			weightOccurrances[weight]++;
		}

		map<string, int>::iterator it2;
		for (it2 = childWeights.begin(); it2 != childWeights.end(); it2++) {
			if (weightOccurrances[it2->second] == 1) {
				cout << "Incorrect weight for child of " << it->first;
				cout << ": " << it2->first << "(" << it2->second << ")" << endl;
			}
		}
	}

	cout << "done";

	string _;
	cin >> _;

    return 0;
}

