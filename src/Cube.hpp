/*
 * Cube.hpp
 *
 *  Created on: 25/03/2018
 *      Author: eugene
 */

#ifndef CUBE_HPP_
#define CUBE_HPP_

#include <iostream>
#include <vector>
#include <functional>
using namespace std;

typedef vector<int> vector1d;
typedef vector<vector<int>> vector2d;
typedef vector<vector<vector<int>>> vector3d;

class Cube {
public:
	void Print() const;
	void Build(vector<int> &cubes);

	size_t size()
	{
		return cub.size();
	}

	Cube(int dimension);
	Cube() = delete;

private:
	void Traverse(int l, int r, vector<int>::iterator &it,
			function<void (vector3d&, int, int, vector<int>::iterator&)> handle);

	vector3d cub;

	friend class CubeTest;
};

#endif /* CUBE_HPP_ */
