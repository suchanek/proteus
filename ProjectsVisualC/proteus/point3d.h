// point3d.h : header file
//


/////////////////////////////////////////////////////////////////////////////
// point3d window

class point3d
{
// Construction
public:
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
	

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(point3d)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~point3d();

	// Generated message map functions
protected:
	//{{AFX_MSG(point3d)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
//	DECLARE_MESSAGE_MAP()
private:
	double _len;
	double _z;
	double _y;
	double _x;
};

/////////////////////////////////////////////////////////////////////////////
