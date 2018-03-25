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

typedef vector<int> vector1d;					/*!< 1-dimensional vector typedef */
typedef vector<vector<int>> vector2d;			/*!< 2-dimensional vector typedef */
typedef vector<vector<vector<int>>> vector3d;	/*!< 3-dimensional vector typedef */

/*! \class Cube
    \brief Cube logic implementation.
*/
class Cube {
public:
	//!< Build a new cube, based on cube set.
	void Build(vector<int> &cubes);

	//!< Print the cube to stdout.
	void Print() const;

	//!< Get cube size.
	size_t size()
	{
		return cub.size();
	}

	//!< Constructor.
	Cube(int dimension);

	//!< Default constructor.
	Cube() = delete;

private:
	//!< Cube traversal function.
	void Traverse(int l, int r, vector<int>::iterator &it,
			function<void (vector3d&, int, int, vector<int>::iterator&)> handle);

	vector3d cub;	/*!< Cube vector */

	friend class CubeTest;	/*!< Allow Test Class Cube access */
};

#endif /* CUBE_HPP_ */
