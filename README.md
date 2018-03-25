## Cube Builder

1. Cube is built based on the initial set of smaller cubes
2. Transparency of the cube is determined by the light transmission
3. It means that we need to avoid cubes with lower transparency in the outer layers
4. Cubes with lower transparency are placed in the center of the cube
5. Whereas cubes with higher transparency are placed in the outer layers to avoid light blocking

    ------------
   /   /   /   /|    
  /   /   /   / |
 /   /   /   /  |
 |-----------| /|
 | 1 | 3 | 4 |/ |
 |-----------| /|
 | 7 | 0 | 8 |/ |
 |-----------|  /
 | 6 | 5 | 2 | /
 |-----------|/

NOTE
To build the project CppUnit lib required https://github.com/epronk/cppunit.git