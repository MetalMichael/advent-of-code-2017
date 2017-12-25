#include "stdafx.h"
#include <string>
#include <vector>
#include <sstream>
#include "Program.h"

using namespace std;

vector<string> splitStringByString(string s, string delim) {
	size_t pos = 0;
	string token;
	vector<string> parts;
	while ((pos = s.find(delim)) != std::string::npos) {
		token = s.substr(0, pos);
		parts.push_back(token);
		s.erase(0, pos + delim.length());
	}
	parts.push_back(s);
	return parts;
}


vector<string> splitStringByChar(string s, char delim) {
	vector<string> result;
	istringstream iss(s);

	for (string token; getline(iss, token, delim); ) {
		result.push_back(std::move(token));
	}

	return result;
}

void Program::setup(string line) {
	auto parts = splitStringByString(line, " -> ");

	auto nameWeightParts = splitStringByChar(parts[0], ' ');
	this->name = nameWeightParts[0];
	this->weight = stoi(nameWeightParts[1].substr(1, nameWeightParts[1].size()-2));

	if (parts.size() > 1) {
		for each (auto child in splitStringByString(parts[1], ", ")) {
			this->children.push_back(child);
		}
	}
}

Program::Program() {

}

Program::~Program() {
}
