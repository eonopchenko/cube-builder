//============================================================================
// Name        : CubeBuilder.cpp
// Author      : Eugene Onopchenko
// Version     :
// Copyright   : Your copyright notice
// Description : EROAD test task (CubeBuilder)
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string.h>
using namespace std;

typedef vector<int> vector1d;
typedef vector<vector<int>> vector2d;
typedef vector<vector<vector<int>>> vector3d;

const int dimension = 5;

void traverseCube(vector3d &cube, int l, int r, vector<int>::iterator &it, function<void (vector3d&, int, int, vector<int>::iterator&)> fill);


void buildCube(vector3d &v, int dim);
void printCube(const vector3d &v);

int main() {
	vector<int> cubes;

	for (int i = 0; i < (dimension * dimension * dimension); i++)
	{
		cubes.push_back(i);
	}

	sort(cubes.begin(), cubes.end());

	vector3d z;
	buildCube(z, dimension);

	vector<int>::iterator it = cubes.begin();
	int l = ((z.size()-1) / 2) - ((z.size()-1) % 2 == 0 ? 1 : 0);
	int r = (((z.size()-1) / 2) + 1);

	if ((z.size()-1) % 2 == 0)
	{
		z[l+1][l+1][l+1] = *it++;
	}

	traverseCube(z, l, r, it,
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

	printCube(z);

	return 0;
}

void traverseCube(vector3d &cube, int l, int r, vector<int>::iterator &it, function<void (vector3d&, int, int, vector<int>::iterator&)> fill)
{
	if (l < 0)
	{
		return;
	}

	fill(cube, l, r, it);

	traverseCube(cube, l-1, r+1, it, fill);
}

void buildCube(vector3d &v, int dim)
{
	vector1d x;
	vector2d y;

	for (int i = 0; i < dim; i++)
	{
		x.push_back(-1);
	}
	for (int i = 0; i < dim; i++)
	{
		y.push_back(x);
	}
	for (int i = 0; i < dim; i++)
	{
		v.push_back(y);
	}
}

void printCube(const vector3d &v)
{
	int index = v.size()-1;
	int x = 0;
	int y = 0;
	int z = 0;
	for (auto itX = v.begin(); itX != v.end(); ++itX)
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
