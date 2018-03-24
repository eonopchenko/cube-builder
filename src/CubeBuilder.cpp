//============================================================================
// Name        : CubeBuilder.cpp
// Author      : Eugene Onopchenko
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : EROAD test task (CubeBuilder)
//============================================================================

#include <iostream>
#include <vector>

#include "Cube.hpp"
#include "CubeTest.hpp"

using namespace std;

const int ver_minor = 0;
const int ver_major = 1;

const int dimension = 5;

int main() {

	cout << "v." << ver_major << "." << ver_minor << " (c++" << __cplusplus << ")" << endl;

#if 0
	vector<int> cubes;
	for (int i = 0; i < (dimension*dimension*dimension); i++)
	{
		cubes.push_back(i);
	}

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
#endif

	CubeTest test(5);
	test.TestCase1();

	return 0;
}
