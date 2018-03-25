/*
 * Cube.cpp
 *
 *  Created on: 25/03/2018
 *      Author: eugene
 */

#include <algorithm>

#include "Cube.hpp"

/*! \brief Cube traversal function.
 *
 */
void Cube::Traverse(int l, int r, vector<int>::iterator &it,
	function<void (vector3d&, int, int, vector<int>::iterator&)> handle)
{
	if (l < 0)
	{
		return;
	}

	/// Handle the current cube
	handle(cub, l, r, it);

	/// Recursion
	Traverse(l-1, r+1, it, handle);
}

/*! \brief Build a new cube, based on cube set.
 *
 */
void Cube::Build(vector<int> &cubes)
{
	unsigned int size = cub.size();

	/// Check input vector dimension
	if (cubes.size() < size*size*size)
	{
		throw "Exception: Incorrect input vector size!";
	}

	/// Sort the input vector
	/// IMPORTANT! Suppose that the lower value means lower transparency
	sort(cubes.begin(), cubes.end());

	vector<int>::iterator it = cubes.begin();

	/// Calculate current cube boundaries (smaller to bigger)
	int l = ((size-1) / 2) - ((size-1) % 2 == 0 ? 1 : 0);
	int r = (((size-1) / 2) + 1);

	if ((size-1) % 2 == 0)
	{
		cub[l+1][l+1][l+1] = *it++;
	}

	/// Traverse the cube
	Traverse(l, r, it,
		[](vector3d &cube, int l, int r, vector<int>::iterator &block)
		{
			/// Fix X-coordinate
			for (int y = l; y <= r; y++)
			{
				for (int z = l; z <= r; z++)
				{
					cube[l][y][z] = *block++;
					cube[r][l+r-y][l+r-z] = *block++;
				}
			}

			/// Fix Z-coordinate
			for (int x = l+1; x <= r-1; x++)
			{
				for (int y = l; y <= r; y++)
				{
					cube[x][y][l] = *block++;
					cube[l+r-x][l+r-y][r] = *block++;
				}
			}

			/// Fix Y-coordinate
			for (int x = l+1; x <= r-1; x++)
			{
				for (int z = l+1; z <= r-1; z++)
				{
					cube[x][l][z] = *block++;
					cube[l+r-x][r][l+r-z] = *block++;
				}
			}
		});
}

/*! \brief Constructor.
 *
 */
Cube::Cube(int dimension)
{
	/// Create the new cube with given dimension
	vector1d x;
	vector2d y;

	for (int i = 0; i < dimension; i++)
	{
		x.push_back(-1);
	}
	for (int i = 0; i < dimension; i++)
	{
		y.push_back(x);
	}
	for (int i = 0; i < dimension; i++)
	{
		cub.push_back(y);
	}
}

/*! \brief Print the cube to stdout.
 *
 */
void Cube::Print() const
{
	/// Traverse the cube and print nodes to the stdout
	int index = cub.size()-1;
	int x = 0;
	int y = 0;
	int z = 0;
	for (auto itX = cub.begin(); itX != cub.end(); ++itX)
	{
		for (int i = 0; i < index; i++)
		{
			cout << "\t";
		}
		cout << "/" << endl;
		for (auto itY = itX->begin(); itY != itX->end(); ++itY)
		{
			for (int i = 0; i < index; i++)
			{
				cout << "\t";
			}
			for (auto itZ = itY->begin(); itZ != itY->end(); ++itZ)
			{
				cout << "[";

				if ((*itZ < 10) && (*itZ >= 0)) cout << "   ";
				else if ((*itZ < 100) || (*itZ < 0)) cout << "  ";
				else cout << " ";

				cout << *itZ << "(" << x << y << z << ")] ";
				z++;
			}
			cout << endl;
			z = 0;
			y++;
		}
		index--;
		z = 0;
		y = 0;
		x++;
	}
}
