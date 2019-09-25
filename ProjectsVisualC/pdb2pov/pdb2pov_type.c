/* $Id: pdb2pov_type.h,v 1.1 1999/03/23 21:14:00 suchanek Exp $ */

/* $Log: pdb2pov_type.h,v $
 * Revision 1.1  1999/03/23  21:14:00  suchanek
 *  return path cleanup
 *
 */



#include "pdb2pov.h"

extern char *amino_acid_names[], *element_names[];

/******************** New 'typing' functions ***********************/

/* This function makes the atom type indices by scanning the
   periodic table array twice - first for a literal element
   match, then for a first character match (the latter case
   usually works for things like proteins */

	
void makerestype(char **resnames, int natoms, int *restypes)
{
    int i,j, Found;

    for (i = 0; i < natoms; i++) {
	Found = 0;

	/* first pass - look for a literal element match */
	for (j = 0; j < NUMAMINOACIDS; j++)
	    {
		if ((stricmp(amino_acid_names[j], resnames[i])) == 0) /* found it */
		    {
			restypes[i] = j;
#ifdef NOISY2
	                fprintf(stderr,
				"Found type <%s> for residue <%s> - Pass 1.\n", 
				amino_acid_names[j], resnames[i]);
#endif
			Found = 1;
			break;
		    }
	    } /* for j */

	if (!Found) /* not found yet */
	    {
		restypes[i] = UNKNOWN_TYPE; /* the 'unknown' type */
#ifdef NOISY
	                fprintf(stderr,
				"Couldn't find type <%s> for residue <%s>.\n", 
				amino_acid_names[j], resnames[i]);
#endif

	    }
    }
}

/* assumes makerestype has been called first! */
/* returns the AminoAcid type or 0 */

int isAminoAcid(int atom_numb, int *restypes)
{

    if ((restypes[atom_numb] >= 0) && (restypes[atom_numb] < UNKNOWN_TYPE))
	return(restypes[atom_numb]);
    else
	return(NOT_AMINO_ACID);

}

/* This function makes the atom type indices by scanning the
   periodic table array twice - first for a literal element
   match, then for a first character match (the latter case
   usually works for things like proteins */

void
makeatomtype(char **atype, int natoms, int *atomtype, int *restypes)
{
    int i,j, Found;
    int       aa;

    for (i = 0; i < natoms; i++) {
	Found = 0;

	/* is it an AminoAcid ? If so, simply check the first letter for the
	   element type */

	if ((aa = isAminoAcid(i, restypes)) != NOT_AMINO_ACID) 
	    {
		for (j = 0; j < NUMB_ELEMENTS; j++)
		    {
			if ((strnicmp(element_names[j], atype[i],1)) == 0) /* found it */
			    {
				atomtype[i] = j;
#ifdef NOISY
				fprintf(stderr,
					"Found type <%s> for atom <%s> - Pass 1.\n", 
					element_names[j],atype[i]);
#endif
				Found = 1;
				break;
				
			    }
		    } /* for j */
	    } /* if isAmino... */

	/* first pass - look for a literal element match */
	if (!Found)
	    for (j = 0; j < NUMB_ELEMENTS; j++)
		{
		    if ((stricmp(element_names[j], atype[i])) == 0) /* found it */
			{
			    atomtype[i] = j;
#ifdef NOISY
			    fprintf(stderr,
				    "Found type <%s> for atom <%s> - Pass 1.\n", 
				    element_names[j],atype[i]);
#endif
			    Found = 1;
			    break;
			}
		} /* for j */
	
	/* if not found yet do second pass - look at first character only */
	if (!Found) /* not found yet */
	    for (j = 0; j < NUMB_ELEMENTS; j++)
		{
		    if ((strnicmp(element_names[j], atype[i],1)) == 0) /* found it */
			{
			    atomtype[i] = j;
#ifdef NOISY
			    fprintf(stderr,
				    "Found type <%s> for atom <%s> - Pass 1.\n", 
				    element_names[j],atype[i]);
#endif
			    Found = 1;
			    break;
			    
			}
		} /* for j */

	/* if we haven't found it after these two passes we blow up
	   and set the type to C */

	if (Found == 0)
	    {
		atomtype[i] = 5; /* carbon */
		fprintf(stderr,
			"Couldn't find type for atom <%s>, using Carbon... \n",
			atype[i]);
	    }
    } /* for i */
}

int isProton(char *a)
{
    if (a[0] == 'H' || a[0] == 'h')
	return(1);

    if (isdigit(a[0]))
	{
	    if (a[1] == 'H' || a[1] == 'h')	return(1);
		return(0);
	}
    else
	return(0);
}

int isCarbon(char *a)
{
    if (a[0] == 'C' || a[0] == 'c')
	return(1);

    if (isdigit(a[0]))
	{
	    if (a[1] == 'C' || a[1] == 'c')	return(1);
		return(0);
	}
    else
	return(0);
}

void print_coords(int natoms, double **atoms)
{
  int i;

  for (i = 0; i < natoms; i++) 
    fprintf(stderr,"Atom %d: %6.2f %6.2f %6.2f\n",i,atoms[i][0],atoms[i][1],
	atoms[i][2]);
  fprintf(stderr,"\n");
}

