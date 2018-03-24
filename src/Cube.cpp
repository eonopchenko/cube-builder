/*
 * Cube.cpp
 *
 *  Created on: 25/03/2018
 *      Author: eugene
 */

#include "Cube.hpp"

void Cube::Traverse(int l, int r, vector<int>::iterator &it, function<void (vector3d&, int, int, vector<int>::iterator&)> fill)
{
	if (l < 0)
	{
		return;
	}

	fill(cub, l, r, it);

	Traverse(l-1, r+1, it, fill);
}

void Cube::Build(vector<int> &cubes)
{
	unsigned int size = cub.size();

	if (cubes.size() < size*size*size)
	{
		throw "Exception: Incorrect input vector size!";
	}

	vector<int>::iterator it = cubes.begin();

	int l = ((size-1) / 2) - ((size-1) % 2 == 0 ? 1 : 0);
	int r = (((size-1) / 2) + 1);

	if ((size-1) % 2 == 0)
	{
		cub[l+1][l+1][l+1] = *it++;
	}

	Traverse(l, r, it,
		[](vector3d &cube, int l, int r, vector<int>::iterator &block)
		{
			for (int y = l; y <= r; y++)
			{
				for (int z = l; z <= r; z++)
				{
					cube[l][y][z] = *block++;
					cube[r][l+r-y][l+r-z] = *block++;
				}
			}
			for (int x = l+1; x <= r-1; x++)
			{
				for (int y = l; y <= r; y++)
				{
					cube[x][y][l] = *block++;
					cube[l+r-x][l+r-y][r] = *block++;
				}
			}
			for (int x = l+1; x <= r-1; x++)
			{
				for (int z = l+1; z <= r-1; z++)
				{
					cube[x][l][z] = *block++;
					cube[l+r-x][r][l+r-z] = *block++;
				}
			}
		});

	if (it != cubes.end())
	{
		cout << "warning!" << endl;
	}
}

Cube::Cube(int dimension)
{
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

void Cube::Print() const
{
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
