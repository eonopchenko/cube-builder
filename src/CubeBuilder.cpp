//============================================================================
// Name        : CubeBuilder.cpp
// Author      : Eugene Onopchenko
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : EROAD test task (CubeBuilder)
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>

#include "Cube.hpp"

using namespace std;
const int dimension = 5;

int main() {

	vector<int> cubes;
	for (int i = 0; i < (dimension*dimension*dimension); i++)
	{
		cubes.push_back(i);
	}
	sort(cubes.begin(), cubes.end());

	Cube cube(dimension);

	try
	{
		cube.Build(cubes);
	}
	catch (const char* msg)
	{
		cerr << msg << endl;
		return 1;
	}

	cube.Print();

	return 0;
}
