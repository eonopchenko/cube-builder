//============================================================================
// Name        : CubeBuilder.cpp
// Author      : Eugene Onopchenko
// Version     : 1.0
// Copyright   : Copyright notice
// Description : EROAD test task (CubeBuilder)
//============================================================================

#include <cppunit/Test.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono>

#include "cppunit/ui/text/TestRunner.h"
#include "CubeTest.hpp"
#include "Cube.hpp"

using namespace std;

const int ver_minor = 0;	/*!< Version minor number */
const int ver_major = 1;	/*!< Version major number */

const int dimension = 3;	/*!< Cube dimension */

/*! \brief Main function.
 *
 */
int main() {

	auto t1 = chrono::high_resolution_clock::now();

	/// Print release version and c++ version
	cout << "v." << ver_major << "." << ver_minor << " (c++" << __cplusplus << ")" << endl;

	/// Test build
#ifdef __TEST__
	cout << "Unit Tests: " << endl;
	CppUnit::TextUi::TestRunner runner;
	runner.addTest(new CubeTest(dimension));
	runner.run();
	return 0;
#endif

	/// Debug build
#ifdef __DEBUG__
	cout << "Debug build: " << endl;
	/// Release build
#elif (defined __RELEASE__)
	cout << "Release build: " << endl;
	/// Unknown build type
#else
	cout << "Unknown build: " << endl;
	return 1;
#endif

	/// Generate initial cube set
	vector<int> cubes;
	for (int i = 0; i < (dimension*dimension*dimension); i++)
	{
		cubes.push_back(rand() % 100);
	}

	/// Create a new cube
	Cube cube(dimension);

	/// Build cube, based on the cube set
	try
	{
		cube.Build(cubes);
	}
	catch (const char* msg)
	{
		cerr << msg << endl;
		return 1;
	}

	/// Print result
	cube.Print();

	auto t2 = chrono::high_resolution_clock::now();
	auto time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
	cout << "---" << endl << "Total execution time: " << time_span.count() << " seconds." << endl;

	return 0;
}
