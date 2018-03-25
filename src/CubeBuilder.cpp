//============================================================================
// Name        : CubeBuilder.cpp
// Author      : Eugene Onopchenko
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : EROAD test task (CubeBuilder)
//============================================================================

#include <cppunit/Test.h>
#include <iostream>
#include <vector>

#include "cppunit/ui/text/TestRunner.h"
#include "CubeTest.hpp"
#include "Cube.hpp"

using namespace std;

const int ver_minor = 0;
const int ver_major = 1;

const int dimension = 5;

int main() {

	cout << "v." << ver_major << "." << ver_minor << " (c++" << __cplusplus << ")" << endl;

#ifdef __TEST__
	cout << "Unit Tests: " << endl;
	CppUnit::TextUi::TestRunner runner;
	runner.addTest(new CubeTest(dimension));
	runner.run();
#else

#ifdef __DEBUG__
	cout << "Debug build: " << endl;
#elif (defined __RELEASE__)
	cout << "Release build: " << endl;
#else
	cout << "Unknown build: " << endl;
	return 1;
#endif

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

#endif // #ifdef __TEST__

	return 0;
}
