// point3d.h : header file
//


/////////////////////////////////////////////////////////////////////////////
// point3d window

class point3d
{
// Construction
public:
	point3d& operator/=(double scale);
	point3d& make_unit(void);
	void print();
	double length();
	point3d(point3d&);
	point3d(double x, double y, double z);
	point3d();	
	
// Attributes
public:
	point3d& setZ(double);
	point3d& setY(double);
	point3d& setX(double);
	
	double z();
	double y();
	double x();

// Operations
public:
	point3d operator/(double scale);
	point3d operator*(double scale);
	point3d& operator=(point3d&);
	point3d  operator-(point3d&);
	point3d operator+(point3d& vector);
	point3d& operator*=(double scale);
	point3d& operator+=(point3d& point);
	point3d& operator-=(point3d& point);

// Implementation
public:
	virtual ~point3d();

	// Generated message map functions

private:
	double _len;
	double _z;
	double _y;
	double _x;
};

/////////////////////////////////////////////////////////////////////////////
