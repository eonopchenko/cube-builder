/*
 * CubeTest.cpp
 *
 *  Created on: 25/03/2018
 *      Author: eugene
 */

#include "CubeTest.hpp"

using namespace std;

void CubeTest::runTest()
{
	vector<int> cubes;
	unsigned int size = cube->size();
	for (unsigned int i = 0; i < size*size*size; i++)
	{
		cubes.push_back(size*size*size - i);
	}

	cube->Build(cubes);

	vector<int>::iterator it = cubes.begin();
	int l = ((size-1) / 2) - ((size-1) % 2 == 0 ? 1 : 0);
	int r = (((size-1) / 2) + 1);

	cube->Traverse(l, r, it,
		[](vector3d &cube, int l, int r, vector<int>::iterator &block)
		{
			int cell = 0;
			for (int y = l; y <= r; y++)
			{
				for (int z = l; z <= r; z++)
				{
					if ((&cube[l][y][z] != &cube[l][l][l]))
					{
						CPPUNIT_ASSERT( (cube[l][y][z] - cell) == 1 );
					}
					cell = cube[l][y][z];
					CPPUNIT_ASSERT( (cube[r][l+r-y][l+r-z] - cell) == 1 );
					cell = cube[r][l+r-y][l+r-z];
				}
			}
			for (int x = l+1; x <= r-1; x++)
			{
				for (int y = l; y <= r; y++)
				{
					CPPUNIT_ASSERT( (cube[x][y][l] - cell) == 1 );
					cell = cube[x][y][l];
					CPPUNIT_ASSERT( (cube[l+r-x][l+r-y][r] - cell) == 1 );
					cell = cube[l+r-x][l+r-y][r];
				}
			}
			for (int x = l+1; x <= r-1; x++)
			{
				for (int z = l+1; z <= r-1; z++)
				{
					CPPUNIT_ASSERT( (cube[x][l][z] - cell) == 1 );
					cell = cube[x][l][z];
					CPPUNIT_ASSERT( (cube[l+r-x][r][l+r-z] - cell) == 1 );
					cell = cube[l+r-x][r][l+r-z];
				}
			}
		});
}
