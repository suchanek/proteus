/* pdb2pov_mol.c - functions to manipulate atoms and molecules for the
   pdb2pov conversion program.

  Author: Eric G. Suchanek, Ph.D.
*/

#include <math.h>
#include "pdb2pov.h"

/* function translates molecule to LOCAL geometric center of coordinates */
 
void center_molecule(int natoms, double **atoms, double center[])
{
  register int i;
  register double xcenter, ycenter, zcenter;

  xcenter = ycenter = zcenter = 0.0;

  for (i = 0; i < natoms; i++) {
    xcenter += atoms[i][0];
    ycenter += atoms[i][1];
    zcenter += atoms[i][2];
  }
  
  xcenter /= natoms;
  ycenter /= natoms;
  zcenter /= natoms;

  for (i = 0; i < natoms; i++) {
    atoms[i][0] -= xcenter; 
    atoms[i][1] -= ycenter;
    atoms[i][2] -= zcenter;
  }
  center[X] = xcenter; center[Y] = ycenter; center[Z] = zcenter;
}

void molecule_cofmass(int natoms, double **atoms,double center[])
{

  register int i;
  register double xcenter, ycenter, zcenter;

  xcenter = ycenter = zcenter = 0.0;

  for (i = 0; i < natoms; i++) {
    xcenter += atoms[i][0];
    ycenter += atoms[i][1];
    zcenter += atoms[i][2];
  }
  
  xcenter /= natoms;
  ycenter /= natoms;
  zcenter /= natoms;

  center[X] = xcenter; center[Y] = ycenter; center[Z] = zcenter;
}

/* function translates molecule (in COFmass coords) to the center of the
   screen (640,512) and then auto-scales to fill window */

 
void translate_molecule(int natoms, double **atoms, int MAX_X, int MAX_Y)
{

  register int i;

  for (i = 0; i < natoms; i++) {
    atoms[i][0] += CENTER_X;
    atoms[i][1] += CENTER_Y;
  }
}


/* computes the bounding box for the atom list */
void compute_extents(int natoms, double **atoms, double *xmin, double *xmax,
double *ymin, 
		double *ymax, double *zmin, double *zmax)
{
  double xm,xma,ym,yma,zm,zma;
  int i;

  xm = ym = zm = 9999.9;
  xma = yma = zma = -9999.9;

  for (i = 0; i < natoms; i++) 
    {
      xm = min(atoms[i][0],xm);
      xma = max(atoms[i][0],xma);
      ym = min(atoms[i][1],ym);
      yma = max(atoms[i][1],yma);
      zm = min(atoms[i][2],zm);
      zma = max(atoms[i][2],zma);
    }

  /* NOTE: MAX_RAD is the maximum atom radius in Angstroms ! */

  *xmin = xm - MAX_RAD; *xmax = xma + MAX_RAD;
  *ymin = ym - MAX_RAD; *ymax = yma + MAX_RAD;
  *zmin = zm - MAX_RAD; *zmax = zma + MAX_RAD;


#ifdef DBG
  fprintf(stderr,"\nXmin:%6.2f Xmax: %6.2f\nYmin: %6.2f Ymax: %6.2f\nZmin: %6.2f
Zmax: %6.2f\n",*xmin,*xmax,*ymin,*ymax,*zmin,*zmax); 
#endif
}

/* function rotates an atom list about a specific axis and center point by
'amount' degrees. */

void rotate_molecule(int natoms, double **atoms, double **patoms, 
		    double xrot, double yrot, double zrot)
{
   int i;
   double matrix[3][3] = {{1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, 
			        {0.0, 0.0, 1.0}};
   make_rotmat(matrix,xrot, yrot, zrot);

   for (i = 0; i < natoms; i++) 
      {
	patoms[i][0] = atoms[i][0];
	patoms[i][1] = atoms[i][1];
	patoms[i][2] = atoms[i][2];
      }

   for (i = 0; i < natoms; i++) 
     {
       double tmp[3];

       tmp[0] = patoms[i][0]; tmp[1] = patoms[i][1]; tmp[2] = patoms[i][2]; 

       matrix_times_vector(matrix, &tmp[0], &tmp[1], &tmp[2]);
       patoms[i][0] = tmp[0]; patoms[i][1] = tmp[1]; patoms[i][2] = tmp[2];
     }
 }

