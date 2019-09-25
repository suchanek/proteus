// point3d.cpp : implementation file
//

#include <math.h>
#include "point3d.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// point3d

point3d::point3d()
{
	_len = _x = _y = _z = 0.0;
}

point3d::point3d(double x, double y, double z)
{
	_x = x;
	_y = y;
	_z = z;
}

point3d::~point3d()
{
}


double point3d::x()
{
	return _x;
}

double point3d::y()
{
	return _y;
}

double point3d::z()
{
	return _z;
}


point3d::point3d(point3d& other)
{
	_x = other.x();
	_y = other.y();
	_z = other.z();
}

point3d& point3d::operator=(point3d& other)
{
	_x = other.x();
	_y = other.y();
	_z = other.z();	
	return *this;
}


point3d& point3d::setX(double x)
{
	_x = x;
	return *this;
}

point3d& point3d::setY(double y)
{
	_y = y;
	return *this;
}

point3d& point3d::setZ(double z)
{
	_z = z;
	return *this;
}

point3d point3d::operator+(point3d& vector)
{
	return point3d(_x + vector.x(), 
				   _y + vector.y(),
				   _z + vector.z());
}

point3d point3d::operator-(point3d& vector)
{
	return point3d(_x - vector.x(), 
				   _y - vector.y(),
				   _z - vector.z());
}

point3d point3d::operator*(double scale)
{
		return point3d(_x * scale, _y * scale, _z * scale);
}

point3d point3d::operator/(double scale)
{
	if (scale == 0.0)
		return point3d(_x, _y, _z);
	else
		return point3d(_x / scale, _y / scale, _z / scale);	
	}

double point3d::length()
{
	double temp = _x * _x + _y * _y + _z * _z;
	double len;
	len = temp > 0.0 ? sqrt(temp) : 1.0;
	return (len);
}

#include <iostream.h>

void point3d::print()
{
	cout << _x << " " << _y << " " << _z << endl;
}

point3d& point3d::make_unit(void)
{
	double len = this->length();

	if (len != 0.0)
	{
		_x /= len;
		_y /= len;
		_z /= len;
	}
	return *this;

}

point3d& point3d::operator-=(point3d& point)
{
	_x -= point.x();
	_y -= point.y();
	_z -= point.z();
	return *this;
}

point3d& point3d::operator+=(point3d& point)
{
	_x += point.x();
	_y += point.y();
	_z += point.z();
	return *this;
}

point3d& point3d::operator*=(double scale)
{
	_x *= scale;
	_y *= scale;
	_z *= scale;
	return *this;

}

point3d& point3d::operator/=(double scale)
{
	if (scale != 0.0)
	{
		_x /= scale;
		_y /= scale;
		_z /= scale;
	}
	return *this;
}
