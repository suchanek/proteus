
#include <math.h>
#include "pdb2pov.h"

int makebonds(register double **apos, char **atype, int natoms, 
	      int maxnbonds, double threshold, int **bonds)
{
    /*
     * Generate into bonds the indices into apos of neighbors. Returns number
     * of bonds. 
     *
     * This version is a simple-minded distance check with special case code to
     * prevent hydrogen over-connectivity. Mike Pique 
     */

    register int i, j;
    register int nbonds;
    register int nbonds_this_atom;
    register double dx, dy, dxy, dz;
    extern int isProton(char *a);

    nbonds = 0;
    for (i = natoms - 1; i > 0; i--) {
	 nbonds_this_atom = 0;
	 for (j = i - 1; j >= 0 && nbonds < maxnbonds; j--) {
	    /*
	     * The outer loop index 'i' is AFTER the inner loop 'j': 'i'
	     * leads 'j' in the list: since hydrogens traditionally follow
	     * the heavy atom they're bonded to, this makes it easy to quit
	     * bonding to hydrogens after one bond is made by breaking out of
	     * the 'j' loop when 'i' is a hydrogen and we make a bond to it.
	     * Working backwards like this makes it easy to find the heavy
	     * atom that came 'just before' the Hydrogen. mp 
	     */

	    /* never bond hydrogens to each other... */
	    if (isProton(atype[i]) && isProton(atype[j]))
		continue;


	    dx = apos[i][0] - apos[j][0];
	    if (dx < 0)
		  dx = -dx;

	    if (dx > threshold)
		  continue;

	    dy = apos[i][1] - apos[j][1];
	    if (dy < 0)
		  dy = -dy;
	    if (dy > threshold)
		  continue;

	    if ((dxy = sqrt((dx * dx) + (dy *dy))) > threshold) 
		  continue;

	    dz = apos[i][2] - apos[j][2];
	    if (dz < 0)
		  dz = -dz;
	    if (dz > threshold)
		  continue;
	    if (hypot(dxy, dz) > threshold)
		  continue;

	    bonds[nbonds][0] = j;
	    bonds[nbonds][1] = i;
#ifdef DEBUG
	    printf("bond[%d] %d to %d\n", nbonds, i, j);
#endif
	    nbonds++;
	    nbonds_this_atom++;

	    if (isProton(atype[i])) /* only one bond per hydrogen */
		break;

	  } /* for j */
	 
    }   /* for */

    return nbonds;
}

int computebonds(register double **apos, char **atype, int natoms, double
threshold, int *aromatic)
{
    /*
     * Generate into bonds the indices into apos of neighbors. Returns number
     * of bonds. 
     *
     * This version is a simple-minded distance check with special case code to
     * prevent hydrogen over-connectivity. Mike Pique 
     */

    register int i, j;
    register int nbonds;
    register int nbonds_this_atom;
    register double dx, dy, dxy, dz;

    nbonds = 0;
    for (i = natoms - 1; i > 0; i--) {
	  nbonds_this_atom = 0;
	  for (j = i - 1; j >= 0 ; j--) {
	    /*
	     * The outer loop index 'i' is AFTER the inner loop 'j': 'i'
	     * leads 'j' in the list: since hydrogens traditionally follow
	     * the heavy atom they're bonded to, this makes it easy to quit
	     * bonding to hydrogens after one bond is made by breaking out of
	     * the 'j' loop when 'i' is a hydrogen and we make a bond to it.
	     * Working backwards like this makes it easy to find the heavy
	     * atom that came 'just before' the Hydrogen. mp 
	     */

	    /* never bond hydrogens to each other... */
	    if (atype[i][0] == 'H' && atype[j][0] == 'H')
		continue;

	    dx = apos[i][0] - apos[j][0];
	    if (dx < 0)
		dx = -dx;
	    if (dx > threshold)
		continue;
	    dy = apos[i][1] - apos[j][1];
	    if (dy < 0)
		dy = -dy;
	    if (dy > threshold)
		continue;
	    if ((dxy = hypot(dx, dy)) > threshold)
		continue;

	    dz = apos[i][2] - apos[j][2];
	    if (dz < 0)
		dz = -dz;
	    if (dz > threshold)
		continue;
	    if (hypot(dxy, dz) > threshold)
		continue;

	    nbonds++;
	    nbonds_this_atom++;
	    if (atype[i][0] == 'H')
		 break;		/* only one bond per hydrogen */
	    if (atype[i][0] == 'h')
		 break;		/* only one bond per hydrogen */
	  }  // for j

	  if ((nbonds_this_atom < 4) && (atype[i][0] == 'C' || 
 
							  atype[i][1] == 'c'))
	  {
		 // printf("found aromatic at atom %d \n",i);
		 aromatic[i] = 1;
		 
	  }
	  else
		  aromatic[i] = 0;

    }   // for i

    printf("Found %d bonds\n", nbonds);
    return nbonds;
}

