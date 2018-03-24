/*
 * CubeTest.hpp
 *
 *  Created on: 25/03/2018
 *      Author: eugene
 */

#ifndef CUBE_TEST_HPP_
#define CUBE_TEST_HPP_

#include <functional>
#include "Cube.hpp"

class CubeTest {
friend class Cube;
public:
	void TestCase1();
	CubeTest(int dimension) : cube(new Cube(dimension)) {};
private:
	Cube *cube;

	friend void Cube::Traverse(int l, int r, vector<int>::iterator &it,
		function<void (vector3d&, int, int, vector<int>::iterator&)> handle);
};

#endif /* CUBE_TEST_HPP_ */
