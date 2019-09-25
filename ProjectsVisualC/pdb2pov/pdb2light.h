/* $Id $ */

#include <stdio.h>
#include <math.h>


#define MAX_ATOMS 	500
#define O_COLOR 	1
#define N_COLOR 	8
#define C_COLOR 	2
#define S_COLOR 	4
#define H_COLOR 	0
#define P_COLOR 	4
#define FE_COLOR 	10
#define CA_COLOR 	11
#define REFLECTIVITY 	4
#define MAX_RADIUS 	100
#define CENTER_X	(MAX_X / 2) 
#define CENTER_Y	(MAX_Y / 2)
#define X		0
#define Y		1
#define Z		2
/*
#define H_TYPE 		7
#define C_TYPE		2
#define O_TYPE		4
#define N_TYPE		3
#define S_TYPE		6
#define P_TYPE		8
#define CA_TYPE		9
#define ANY_TYPE	5
#define FE_TYPE         10
*/
#define C_RAD		((float) 2.0)
#define N_RAD		((float) 1.8)
#define O_RAD		((float) 2.2)
#define H_RAD		((float) 1.0)
#define S_RAD		((float) 1.9)
#define P_RAD		((float) 2.1)
#define CA_RAD		((float) 2.4)
#define FACTOR		((float) 1.0)
#define MAX_RAD		((float) 2.5)


#define streq(a,b) (0==strcmp(a,b))

typedef float CoordSys[4][3];

#define P 0
#define H 1
#define L 2
#define U 3
#define X 0
#define Y 1
#define Z 2

struct atom_struct {
  double pos[3];
  char atype[4];
  char amino[4];
  char charges[4];
};


