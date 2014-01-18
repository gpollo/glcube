#ifndef CUBE_H
#define CUBE_H

#include <cmath>
#include <new>

#include "global.h"

const uint8_t colorScheme[7][3] =  {{  0,   0,   0},  //0 Black
									{255, 255, 255},  //1 White
									{255, 255,   0},  //2 Yellow
									{  0,   0, 255},  //3 Blue
									{  0, 255,   0},  //4 Green
									{255,   0,   0},  //5 red
									{255, 155,   0}}; //6 Orange
const uint8_t CUBEVER[8][3]     =  {{0, 0, 0},
									{1, 0, 0},
									{1, 1, 0},
									{0, 1, 0},
									{0, 0, 1},
									{1, 0, 1},
									{1, 1, 1},
									{0, 1, 1}};
const uint8_t CUBEFACE[6][4]    =  {{4, 5, 6, 7},
									{0, 1, 2, 3},
									{3, 2, 6, 7},
									{0, 1, 5, 4},
									{1, 2, 6, 5},
									{0, 3, 7, 4}};

struct cubies
{
	uint8_t color[6];   //1, 2, 3, 4, 5, 6
	uint8_t rot[3];
	uint8_t pos[3];
	uint8_t type;       //0 = center; 1 = edge; 2 = corner
	uint8_t isrotating;
	
	cubies()
	{
		int a;
		for(a = 0; a<6; a++)
			color[a] = 0;
		for(a = 0; a<6; a++)
		{
			rot[a] = 0;
			pos[a] = 0;
		}
		type       = 0;
		isrotating = 3;
	}
};

class cube
{
	public:
		cube();

		void generate();
		void draw();
		void layer_up();
		void layer_down();
		void rotate_front(int r);
void inset_square(int x[4], int y[4], int z[4]);
		~cube();

	private:
		uint8_t color[6];  //F B T D R L
		uint8_t center[6]; //F B T D R L (color undeterminated)
		uint8_t num_layer;
		uint8_t side_rotating;
		float sti_mar;
		float side_rotation[6];
		cubies *cubes;

		void draw_cube(int index);
		void swap_pieces(int a, int b);
		
		int test_corner(int x, int y, int z);
		int test_edge(int x, int y, int z);
};

#endif









