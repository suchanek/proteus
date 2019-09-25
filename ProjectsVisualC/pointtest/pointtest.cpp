#include <iostream.h>
#include <math.h>
#include "point3d.h"

void main(int argc, char *argv[])
{

	point3d a;
	point3d b(2.2, 3.3, 4.4);
	point3d c;
	double scale;

	a.print();
	a.setX(2.0); a.setY(3.0); a.setZ(4.4);

	a.print();

	c = a + b;
	c.print();
	c = c - b;
	c.print();
	c = c * 5.0;
	c.print();
	c = c / 0.0;
	c.print();
	c.make_unit();
	c.print();
}	

