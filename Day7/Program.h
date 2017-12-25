#pragma once

#include <string>
#include <vector>
#include <map>

using namespace std;

class Program
{
	string name;
	int weight;
	int totalWeight = -1;

	vector<string> children;
	Program* parent;

public:
	Program();
	~Program();
	void setup(string line);

	Program* getParent() const {
		return parent;
	}

	void setParent(Program* p) {
		parent = p;
	}

	string getName() const {
		return name;
	}

	int getWeight() const {
		return weight;
	}

	int calculateTotalWeight(map<string, Program> allPrograms) {
		if (totalWeight > -1) {
			return totalWeight;
		}

		int total = weight;
		for each (auto child in children) {
			auto p = allPrograms[child];
			total += p.calculateTotalWeight(allPrograms);
		}
		totalWeight = total;
		return total;
	}

	vector<string> getChildren() const {
		return children;
	}
};

