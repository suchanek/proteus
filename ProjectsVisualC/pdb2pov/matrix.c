#include <math.h>
#include "pdb2pov.h"

/*********************** New Matrix functions *************************/
/* multiply the old and new matrices; replace old with product */

void matmul(double new[3][3], double old[3][3])
{
  double tmp[3][3];

    tmp[0][0]= new[0][0]*old[0][0]+new[0][1]*old[1][0]+new[0][2]*old[2][0]; 
    tmp[0][1]= new[0][0]*old[0][1]+new[0][1]*old[1][1]+new[0][2]*old[2][1]; 
    tmp[0][2]= new[0][0]*old[0][2]+new[0][1]*old[1][2]+new[0][2]*old[2][2]; 

    tmp[1][0]= new[1][0]*old[0][0]+new[1][1]*old[1][0]+new[1][2]*old[2][0]; 
    tmp[1][1]= new[1][0]*old[0][1]+new[1][1]*old[1][1]+new[1][2]*old[2][1]; 
    tmp[1][2]= new[1][0]*old[0][2]+new[1][1]*old[1][2]+new[1][2]*old[2][2]; 

    tmp[2][0]= new[2][0]*old[0][0]+new[2][1]*old[1][0]+new[2][2]*old[2][0]; 
    tmp[2][1]= new[2][0]*old[0][1]+new[2][1]*old[1][1]+new[2][2]*old[2][1]; 
    tmp[2][2]= new[2][0]*old[0][2]+new[2][1]*old[1][2]+new[2][2]*old[2][2]; 

    old[0][0]= tmp[0][0];
    old[0][1]= tmp[0][1];
    old[0][2]= tmp[0][2];

    old[1][0]= tmp[1][0];
    old[1][1]= tmp[1][1];
    old[1][2]= tmp[1][2];

    old[2][0]= tmp[2][0];
    old[2][1]= tmp[2][1];
    old[2][2]= tmp[2][2];
}

/* increment the rotation matrix by x, y, z */

void make_rotmat(double rotmat[3][3], double gamma, double beta, double theta)
/* x-axis y-axis z-axis */
{

  double g = gamma / 57.29;
  double b = beta / 57.29;
  double t = theta / 57.29;

  register double sing = sin(g);
  register double cosg = cos(g);
  register double sinb = sin(b);
  register double cosb = cos(b);
  register double sint = sin(t);
  register double cost = cos(t);

  rotmat[0][0] = cost * cosb; 
  rotmat[0][1] = sint * cosg + cost * sinb * sing;
  rotmat[0][2] = sint * sing - cost * sinb * cosg;
  rotmat[1][0] = -sint * cosb;
  rotmat[1][1] = cost * cosg - sint * sinb * sing;
  rotmat[1][2] = cost * sing + sint * sinb * cosg;
  rotmat[2][0] = sinb;
  rotmat[2][1] = -cosb * sing;
  rotmat[2][2] = cosb * cosg;
  
}

void inc_rotmat(double rotmat[3][3], double gamma, double beta, 
		double theta) /* x-axis y-axis z-axis */
{

  double g = gamma / 57.29;
  double b = beta / 57.29;
  double t = theta / 57.29;

  double newmat[3][3];

  register double sing = sin(g);
  register double cosg = cos(g);
  register double sinb = sin(b);
  register double cosb = cos(b);
  register double sint = sin(t);
  register double cost = cos(t);

  newmat[0][0] = cost * cosb; 
  newmat[0][1] = sint * cosg + cost * sinb * sing;
  newmat[0][2] = sint * sing - cost * sinb * cosg;
  newmat[1][0] = -sint * cosb;
  newmat[1][1] = cost * cosg - sint * sinb * sing;
  newmat[1][2] = cost * sing + sint * sinb * cosg;
  newmat[2][0] = sinb;
  newmat[2][1] = -cosb * sing;
  newmat[2][2] = cosb * cosg;
  
  matmul(newmat, rotmat);
}


int matrix_times_vector(double matrix[3][3], double *x, double *y, double *z)
{
  register double xx, yy, zz;

  xx = matrix[0][0] * *x + matrix[0][1] * *y + matrix[0][2] * *z;
  yy = matrix[1][0] * *x + matrix[1][1] * *y + matrix[1][2] * *z;
  zz = matrix[2][0] * *x + matrix[2][1] * *y + matrix[2][2] * *z;
  *x = xx; *y = yy; *z = zz;
  return(1);
}