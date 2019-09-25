/* util.c - some general memory allocation utilities */
/* $Id: util.c,v 1.1 1995/09/21 19:20:09 suchanek Exp $ */
/* $Log: util.c,v $
 * Revision 1.1  1995/09/21  19:20:09  suchanek
 * Initial revision
 *
 * Revision 1.5  1994/03/15  18:06:57  eric
 * re-ordered since math.h wasn't included in the generic version!
 * messed up bond calculation
 *
 * Revision 1.4  1993/11/17  17:19:37  eric
 * added additional define for the amiga-specific hypot function
 *
 * Revision 1.2  1993/11/16  18:35:36  eric
 * added conditionals for UNIX/AMIGA, hypot fxn
 *
 * Revision 1.1  1993/11/13  12:54:12  eric
 * Initial revision
 * */
#ifdef AMIGA
#include <exec/types.h>
#include <math.h>
#define  __USE_SYSBASE

#ifdef _M68881
#include <m68881.h>

#include <proto/all.h>
#endif
#endif

#include <stdlib.h>
#include <stdio.h>

#include "util.proto.h"

#ifdef AMIGA
double hypot(double x, double y)
{
  return((sqrt((x*x + y*y))));

}
#endif

void EGS_error(char error_text[])
     
{
  fprintf(stderr,"Run-time error...\n");
  fprintf(stderr,"%s\n",error_text);
  fprintf(stderr,"...now exiting to system...\n");
  exit(-10);
}



/* allocate a double matrix with subscript range m[nrl..nrh][ncl..nch] */

/* double **mat;
   mat = dmatrix(10,10)
*/

double **dmatrix(int nrh,int nch)
{
  int i;
  double **m;
  int nrl = 0;
  int ncl = 0;

  /* allocate pointers to rows */
  
  m=(double **) malloc((unsigned) (nrh-nrl + 1)*sizeof(double *))-nrl;
  if (!m) {
    EGS_error("allocation failure 1 in dmatrix()");
    return(NULL);
  }
  
  /* allocate rows and set pointers to them */
  
  for(i=nrl;i<=nrh;i++) {
    m[i]=(double *) malloc((unsigned) (nch-ncl)*sizeof(double))-ncl;
    if (!m[i]) {
      EGS_error("allocation failure 2 in dmatrix()");
      return(NULL);
    }
  }
  
  /* return pointer to array of pointers to rows */
  
  return m;
}

/* free a double matrix allocated by dmatrix() */

void free_dmatrix(double **m, int nrh, int nch)

{
  int i;
  int nrl = 0;
  int ncl = 0;
  
  for(i=nrh;i>=nrl;i--) free((char*) (m[i]+ncl));
  free((char*) (m+nrl));
}

int **imatrix(int nrh,int nch)
{
  int i;
  int **m;
  int nrl = 0;
  int ncl = 0;

  /* allocate pointers to rows */
  
  m=(int **) malloc((unsigned) (nrh-nrl + 1)*sizeof(int *))-nrl;
  if (!m) {
    EGS_error("allocation failure 1 in imatrix()");
    return(NULL);
  }
  
  /* allocate rows and set pointers to them */
  
  for(i=nrl;i<=nrh;i++) {
    m[i]=(int *) malloc((unsigned) (nch-ncl)*sizeof(int))-ncl;
    if (!m[i]) {
      EGS_error("allocation failure 2 in imatrix()");
      return(NULL);
    }
  }
  
  /* return pointer to array of pointers to rows */
  
  return m;
}

/* free a int matrix allocated by imatrix() */

void free_imatrix(int **m, int nrh, int nch)
{     
  int i;
  int nrl = 0;
  int ncl = 0;
  
  for(i=nrh;i>=nrl;i--) free((char*) (m[i]+ncl));
  free((char*) (m+nrl));
}

char **cmatrix(int nrh,int nch)
{
  int i;
  char **m;
  int nrl = 0;
  int ncl = 0;

  /* allocate pointers to rows */
  
  m=(char **) malloc((unsigned) (nrh-nrl+1)*sizeof(char *))-nrl;
  if (!m) {
    EGS_error("allocation failure 1 in cmatrix()");
    return(NULL);
  }
  
  /* allocate rows and set pointers to them */
  
  for(i=nrl;i<=nrh;i++) {
    m[i]=(char *) malloc((unsigned) (nch-ncl)*sizeof(char))-ncl;
    if (!m[i]) {
      EGS_error("allocation failure 2 in cmatrix()");
      return(NULL);
    }
  }
  
  /* return pointer to array of pointers to rows */
  
  return m;
}

/* free a double matrix allocated by dmatrix() */

void free_cmatrix(char **m, int nrh, int nch)
{
  int i;
  int nrl = 0;
  int ncl = 0;
  
  for(i=nrh;i>=nrl;i--) free((char*) (m[i]+ncl));
  free((char*) (m+nrl));
}


double *dvector(int nh)
{
        int nl = 0;
	double *v;

	v=(double *)malloc((unsigned) (nh-nl+1)*sizeof(double));
	if (!v) EGS_error("allocation failure in dvector()");
	return v;
}

void free_dvector(double *v, int nh)
{
  int nl = 0;
  free((char*) (v+nl));
}


int *ivector(int nh)
{
        int nl = 0;
	int *v;

	v=(int *)malloc((unsigned) (nh-nl+1)*sizeof(int));
	if (!v) EGS_error("allocation failure in ivector()");
	return v;
}

void free_ivector(int *v, int nh)
{
  int nl = 0;
  free((char*) (v+nl));
}

//
// end of file util.c


