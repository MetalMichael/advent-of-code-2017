// Day3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

enum Direction {
	Up, Down, Left, Right
};

int sumAdjacentValues(vector<vector<int>> values, int x, int y) {
	int sum = 0;
	sum += values[x + 1][y];
	sum += values[x + 1][y + 1];
	sum += values[x][y + 1];
	sum += values[x-1][y + 1];
	sum += values[x-1][y];
	sum += values[x-1][y - 1];
	sum += values[x][y - 1];
	sum += values[x+1][y - 1];

	if (sum == 0) {
		return 1;
	}
	return sum;
}

int main()
{
	const int input = 289326;

	int dimension = ceil(sqrt(input));
	if (dimension % 2 == 0) {
		dimension++;
	}
	auto maxNumber = pow(dimension, 2);
	auto center = ((dimension + 1) / 2) - 1;

	cout << "Dimension " << dimension << "\n";

	int x, y;
	x = y = center;

	int min = center;
	int max = center;

	vector<vector<int>> values(dimension);
	for(int i = 0; i < dimension; i++) {
		values[i] = vector<int>(dimension);
	}
	

	Direction currentDirection = Right;

	int currentNumber = 1;
	while (true) {
		// Part 2
		currentNumber = sumAdjacentValues(values, x, y);
		values[x][y] = currentNumber;
		if (currentNumber > input) {
			break;
		}

		switch (currentDirection) {
		case Up:
			if (y == min) {
				currentDirection = Left;
				x--;
			} else {
				y--;
			}
			break;
		case Left:
			if (x == min) {
				currentDirection = Down;
				y++;
			} else {
				x--;
			}
			break;
		case Right:
			if (x == max) {
				currentDirection = Up;
				min--;
				max++;
				x++;
			} else {
				x++;
			}
			break;
		case Down:
			if (y == max) {
				currentDirection = Right;
				x++;
			} else {
				y++;
			}
			break;
		}
		currentNumber++;
	}

	cout << "Current Number: " << currentNumber;

	//cout << "X: " << x << "\nY: " << y << "\n";
	//cout << "Center: (" << center << "," << center << ")\n";


	//int manhattan = abs(x - center) + abs(y - center);

	//cout << "Distance: " << manhattan;

	string _;
	getline(cin, _);
	
    return 0;
}

