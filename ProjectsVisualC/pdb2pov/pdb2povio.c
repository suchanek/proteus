
#include "pdb2pov.h"
#include "pdb2pov_errors.h"

/* Amiga stuff */
#ifdef AMIGA
#define CRET 0x0D
#define LF 0x0A

int getline(char *linebuf, int numb, struct AsyncFile *file)
{
  int i = 0;
  LONG read = 0;

  while (((read = ReadCharAsync(file)) >= 0) && (i < numb))
    {
      if (read == LF || read == CRET || read == 0)
	{
	  if (read == CRET)
	    read = ReadCharAsync(file); /* eat the linefeed */
	  if (read < 0)
	    return(0);

	  linebuf[i] = '\0';
	  return(i);
	}
      else
	{
	  if (read < 0)
	    {
	      return(NULL); /* Possible portability problem */
	    }
	  else
	    linebuf[i++] = (char)read;
	}
    }
}
#endif
/* End of Amiga stuff */

/*  PDB file I/O */

int getpdb(char *fname, int maxnatoms, double **apos, 
	   char **atype, double *charge, char **amino)
{
  int natoms;

/* Amiga stuff */
#ifdef AMIGA
  struct AsyncFile *file_in;
  LONG IO_buffersize = 32768;
  
  if (!(file_in = OpenAsync(fname, MODE_READ, IO_buffersize)))
    {
      fprintf(stderr,"can't open file %s\n",fname);
      return(-1);
    }
/* Unix & Mac stuff */
#else
  FILE *file_in;
  FILE *fopen();

  file_in = fopen(fname, "r");
  if(file_in==NULL) {
    fprintf(stderr,"can't open file %s\n",fname);
    return -1;
  }

#endif

  natoms = fgetpdb(file_in, maxnatoms, apos, atype, charge,amino);
  if (natoms > maxnatoms)
    {
      fprintf(stderr,"Too many atoms! Truncated to <%d> \n", maxnatoms);
    }

  if (file_in)
/* Amiga stuff */
#ifdef AMIGA
    CloseAsync(file_in);
/* Unix & Mac stuff */
#else
  fclose(file_in);
#endif

  return natoms;
}

/* Amiga stuff */
#ifdef AMIGA
int fgetpdb(struct AsyncFile *in, int maxnatoms, 
	    double **apos, char **atype, double *charge, char **amino)
{
/* Unix & Mac stuff */
#else
int fgetpdb(FILE *f, int maxnatoms, 
	    double **apos, char **atype, double *charge, char **amino)
{
#endif
/*
 * Read a Brookhaven file putting the coords into apos and the char
 *  string names into atype. Return number of atoms.  M Pique
 * Stop reading on End-of-file, or 'END' line, or line with just a ".".
 * Here is some sample input: 
ATOM     19  HN  THR     2      15.386  10.901   4.600
ATOM     20  HOG THR     2      14.161   9.481   4.420
ATOM     21  N   CYS     3      13.507  11.238   8.398
ATOM     22  CA  CYS     3      13.659  10.715   9.763
ATOM     23  C   CYS     3      12.265  10.443  10.307
HETATM   99  FE  XXX     4      33.265  10.443  10.307
ATOM         OT  OME    52     -16.009  30.871 -13.037                -0.543
HETATM       CU+2CU    152     -20.577   2.601 -14.587                 2.000
HETATM       ZN+2ZN    152     -17.911   1.372 -19.974                 2.000
END
                                                         These charge values
							 are non-standard
							 and are not genuine
							 PDB. They are optional.
 */
  char linebuf[200];
  register int n; /* number of atoms */
  double tcharge;

  n=0;
/* Amiga stuff */
#ifdef AMIGA
  while(getline(linebuf, sizeof(linebuf), in)!=NULL && n < maxnatoms &&
/* Unix & Mac stuff */
#else
  while(fgets(linebuf, sizeof linebuf, f)!=NULL && n < maxnatoms &&
#endif
	 0!=strcmp(".", linebuf) &&  0!=strncmp("END", linebuf,3) &&  0!=strncmp("end", linebuf,3))
  {
		if( (0==strncmp("ATOM",linebuf,4)||	0==strncmp("atom",linebuf,4) || 
			0==strncmp("HETATM",linebuf,6) ||
			0==strncmp("hetatm",linebuf,6) )
		&& 1==sscanf(&linebuf[12]," %3s", atype[n])
		&& 1==sscanf(&linebuf[17],"%3s", amino[n])
		&& 3==sscanf(&linebuf[30],"%lf %lf %lf",
		&apos[n][0],  &apos[n][1], &apos[n][2]) ) {
#ifdef DEBUG
			printf("atom %d type %s %s at %lf %lf %lf\n",
			  n, atype[n], amino[n], apos[n][0],  apos[n][1], apos[n][2]);
#endif
			if(1==sscanf(&linebuf[70],"%lf", &tcharge))
			 charge[n] = tcharge;
			else charge[n] = 0.00;
			if ((0 == strncmp("ATOM", linebuf,4)) && ((0 == strncmp(atype[n],"ca",2))
								  || (0 == strncmp(atype[n],"CA",2))))
			  atype[n][1] = ' ';
			n++;
			}
		}
	return n;
	}

/* Amiga stuff */
#ifdef AMIGA
int fgetpdbxyz(struct AsyncFile *in, int maxnatoms, double **apos)
/* Unix & Mac stuff */
#else
int fgetpdbxyz(FILE *in, int maxnatoms, double **apos)
#endif
{
/*
 * Read a Brookhaven file putting the coords into apos only
 * Return number of atoms read before end-of-file or line with END or .
 */
char linebuf[200];
register int n; /* number of atoms */

	n=0;

/* Amiga stuff */
#ifdef AMIGA
  while(getline(linebuf, sizeof(linebuf), in)!=NULL && n < maxnatoms &&
/* Unix & Mac stuff */
#else
  while(fgets(linebuf, sizeof linebuf, in)!=NULL && n < maxnatoms &&
#endif
	 0!=strcmp(".", linebuf) &&
	 0!=strncmp("END", linebuf,3) &&
	 0!=strncmp("end", linebuf,3)
	) {
		if( (0==strncmp("ATOM",linebuf,4)||
			0==strncmp("atom",linebuf,4) ||
			0==strncmp("HETATM",linebuf,6) ||
			0==strncmp("hetatm",linebuf,6) )
		&& 3==sscanf(&linebuf[30],"%lf %lf %lf",
		&apos[n][0],  &apos[n][1], &apos[n][2]) ) {
#ifdef DEBUG
			printf("atom %d at %lf %lf %lf\n",
			  n, apos[n][0],  apos[n][1], apos[n][2]);
#endif
			n++;
			}
		}
	return n;
	}


int getpdb_atnum(char *fname)
{
  int natoms;
/* Amiga stuff */
#ifdef AMIGA
  struct AsyncFile *file_in;
  LONG IO_buffersize = 32768;
  
  if (!(file_in = OpenAsync(fname, MODE_READ, IO_buffersize)))
    {
      fprintf(stderr,"can't open file %s\n",fname);
      return(ERR_CANT_READ_INPUT);
    }
/* Unix & Mac stuff */
#else

  FILE *file_in;

  file_in = fopen(fname, "r");
  if(file_in==NULL) {
    fprintf(stderr,"can't open file %s\n",fname);
    return ERR_CANT_READ_INPUT;
  }

#endif

  natoms = fgetpdb_atnum(file_in);

  if (file_in)
/* Amiga stuff */
#ifdef AMIGA
    CloseAsync(file_in);
/* Unix & Mac stuff */
#else
    fclose(file_in);
#endif
  return natoms;
}

/* Amiga stuff */
#ifdef AMIGA
int fgetpdb_atnum(struct AsyncFile *in)
/* Unix & Mac stuff */
#else
int fgetpdb_atnum(FILE *in)
#endif
{
  char linebuf[200];
  register int n; /* number of atoms */

  n=0;

/* Amiga stuff */
#ifdef AMIGA
  while(getline(linebuf, sizeof(linebuf), in)!=NULL && 
/* Unix & Mac stuff */
#else
  while(fgets(linebuf, sizeof linebuf, in)!=NULL && 
#endif
	0!=strcmp(".", linebuf) && 0!=strncmp("END", linebuf,3) &&
	0!=strncmp("end", linebuf,3) )
    {
      if( (0==strncmp("ATOM",linebuf,4)||
	   0==strncmp("atom",linebuf,4) ||
	   0==strncmp("HETATM",linebuf,6) ||
	   0==strncmp("hetatm",linebuf,6) ) )
	{
	  n++;
	}
    }
  return n;
}


/* .atm File I/O */

int getatm(char *fname, int maxnatoms, double **apos, char **atype, double
*charge)
{
FILE *f;
int natoms;
	f = fopen(fname, "r");
        if(f==NULL) {
		fprintf(stderr,"can't open file %s\n",fname);
		return -1;
		}
	natoms = fgetatm(f, maxnatoms, apos, atype, charge);
	fclose(f);
	return natoms;
	}



int fgetatm(FILE *f, int maxnatoms, double **apos, char **atype, double *charge)
/*
 * Read a Brookhaven file putting the coords into apos and the char
 *  string names into atype. Return number of atoms.  M Pique
 * Stop reading on End-of-file, or 'END' line, or line with just a ".".
 * Here is some sample input: 
  1 0x7042  Ca  0.0335223  5.4441102  0.0069856   20    0   sp    Ca    0x3
  2 0x7042  Ca -2.3324949  8.1159780  1.7203546   20    0   sp    Ca    0x3
  3 0x7042   P  2.0533851  3.0058572  1.7203546   15    0  sp3     P    0x3
  END
 */
{
  char linebuf[200];
  register int n; /* number of atoms */

  char temp[7];
  int atnumb;

  n=0;
  while(fgets(linebuf, sizeof linebuf, f)!=NULL && n < maxnatoms &&
	0!=strncmp("END", linebuf,3) &&
	0!=strncmp("end", linebuf,3))
    {
      sscanf(linebuf,"%d %s %3s %lf %lf %lf", &atnumb, temp, atype[n],
	     &apos[n][0], &apos[n][1], &apos[n][2]);
#ifdef DEBUG
      printf("atom %d type %s %s at %lf %lf %lf\n",
	     n, atype[n], apos[n][0],  apos[n][1], apos[n][2]);
#endif
      charge[n] = 0.00;
      n++;
    }
  return n;
}
