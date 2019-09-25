/****************************************************************************/
/*        $Id: pdb2pov.c,v 1.23 1995/09/22 13:26:29 suchanek Exp suchanek$  */
/*  A program to convert brookhaven PDB format atomic files into the POV    */
/*  format files needed for the POV ray-tracing program.	                */		   
/*  Author: Eric G. Suchanek, Ph.D.      				                    */
/*  Copyright 1993-1997 Eric G. Suchanek, Ph.D. All Rights Reserved         */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  */

/* $Log: pdb2pov.c,v $
 * Revision 1.24  1997/01/01  00:00:00 suchanek
 * additions for Win32, split out into multiple files,
 * added code to do split bonds.
 *
 *
 * Revision 1.23  1995/09/22  13:26:29  suchanek
 * added stuff to handle amino acid parsing, some clean up
 *
 * Revision 1.22  1995/09/21  19:19:19  suchanek
 * added code to handle full periodic table
 *
 *
 * Revision 1.21  1995/01/27  19:38:36  suchanek
 * porting stuff for MAC version
 *
 * Revision 1.19  1994/07/18  21:32:26  eric
 * added the -p option for plain sky, no ground
 *
 * Revision 1.18  1994/05/04  22:01:46  eric
 * changed bond radius to 0.17 rather than 0.3
 *
 * Revision 1.17  1994/03/15  18:06:28  eric
 * updated version string
 *
 * Revision 1.16  1994/01/22  22:23:48  eric
 * changed to use make_rotmat rather than inc_rotmat. Now rotations
 * are absolute, not relative
 *
 * Revision 1.15  1993/11/26  09:12:24  eric
 * added -a option for area lights
 *
 * Revision 1.14  1993/11/25  19:58:23  eric
 * added additional error checking and return values
 *
 * Revision 1.12  1993/11/23  18:50:32  eric
 * changed the default to NOT render the checkered ground, and to
 * generate covalent radii
 *
 * Revision 1.11  1993/11/17  17:19:08  eric
 * added code to handle the ball&stick/glass atom hybrid
 *
 * Revision 1.8  1993/11/16  18:35:01  eric
 * many additions, ball and stick mode, conditional defines for UNIX/AMIGA, etc
 * */
 
 /* Porting to the Macintosh by Richard Rothwell
	email: chergr@lure.latrobe.edu.au
 */

#include "pdb2pov.h"
#include "pdb2pov_errors.h"

/* Author's message */
static char rcsid[] = "$Id: pdb2pov.c,v 1.24 1997/1/01 13:26:29 suchanek Exp suchanek $";

static char vers[] = "\0$VER: pdb2pov 1.24 (1/1/97)";

#include "pdb2pov_usage.h"

/* Unix stuff & Mac */
#ifdef MAC_MW
#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))
#endif

/* Global rotation angles */
double xrot = 0.0;
double yrot = 0.0;
double zrot = 0.0;

enum restypes_indices {ALA_TYPE=0, ARG_TYPE, ASN_TYPE, ASP_TYPE, CYS_TYPE,
		       GLN_TYPE, GLU_TYPE, GLY_TYPE, HIS_TYPE, ILE_TYPE, LEU_TYPE, LYS_TYPE,
		       MET_TYPE, PHE_TYPE, PRO_TYPE, SER_TYPE, THR_TYPE, TRP_TYPE, TYR_TYPE, 
		       VAL_TYPE, UNK_TYPE};


char *amino_acid_names[NUMAMINOACIDS] = 
{"Ala", "Arg", "Asn", "Asp", "Cys", "Gln", "Glu", "Gly", "His", "Ile", "Leu",
 "Lys", "Met", "Phe", "Pro", "Ser", "Thr", "Trp", "Tyr", "Val", "XXX" };



/* New stuff for the full periodic table */

enum atypes_indices { H_TYPE=0, HE_TYPE, LI_TYPE, BE_TYPE, B_TYPE, C_TYPE, N_TYPE,
O_TYPE, F_TYPE, NE_TYPE, NA_TYPE, MG_TYPE, AL_TYPE, S_TYPE, P_TYPE, SI_TYPE,
CL_TYPE, AR_TYPE, K_TYPE, CA_TYPE, SC_TYPE, TI_TYPE, V_TYPE, CR_TYPE, MN_TYPE,
FE_TYPE, CO_TYPE, NI_TYPE, CU_TYPE, ZN_TYPE, GA_TYPE, GE_TYPE, AS_TYPE, SE_TYPE,
BR_TYPE, KR_TYPE, RB_TYPE, SR_TYPE, Y_TYPE, ZR_TYPE, NB_TYPE, MO_TYPE, TC_TYPE, RU_TYPE,
RH_TYPE, PD_TYPE, AG_TYPE, CD_TYPE, IN_TYPE, SN_TYPE, SB_TYPE, TE_TYPE, I_TYPE, XE_TYPE,
CS_TYPE, BA_TYPE, LA_TYPE, CE_TYPE, PR_TYPE, ND_TYPE, PM_TYPE, SM_TYPE, EU_TYPE, GD_TYPE,
TB_TYPE, Dy_TYPE, HO_TYPE, ER_TYPE, TM_TYPE, YB_TYPE, LU_TYPE, HF_TYPE, TA_TYPE, WB_TYPE,
RE_TYPE, OS_TYPE, IR_TYPE, PT_TYPE, AU_TYPE, HG_TYPE, TL_TYPE, PB_TYPE, BI_TYPE, PO_TYPE, 
AT_TYPE, RN_TYPE, FR_TYPE, RA_TYPE, AC_TYPE, TH_TYPE, PA_TYPE, U_TYPE, NP_TYPE, PU_TYPE, 
AM_TYPE, CM_TYPE, BK_TYPE, CF_TYPE, ES_TYPE, FM_TYPE, MD_TYPE, NO_TYPE, LR_TYPE, HYBRID_TYPE, ANY_TYPE};

/* new stuff 12/31/96 -egs- */

double Atom_Radii[] = { H_RAD, HE_RAD, LI_RAD, BE_RAD, B_RAD, C_RAD, N_RAD,
O_RAD, F_RAD, NE_RAD, NA_RAD, MG_RAD, AL_RAD, S_RAD, P_RAD, SI_RAD,
CL_RAD, AR_RAD, K_RAD, CA_RAD, SC_RAD, TI_RAD, V_RAD, CR_RAD, MN_RAD,
FE_RAD, CO_RAD, NI_RAD, CU_RAD, ZN_RAD, GA_RAD, GE_RAD, AS_RAD, SE_RAD,
BR_RAD, KR_RAD, RB_RAD, SR_RAD, Y_RAD, ZR_RAD, NB_RAD, MO_RAD, TC_RAD, RU_RAD,
RH_RAD, PD_RAD, AG_RAD, CD_RAD, IN_RAD, SN_RAD, SB_RAD, TE_RAD, I_RAD, XE_RAD,
CS_RAD, BA_RAD, LA_RAD, CE_RAD, PR_RAD, ND_RAD, PM_RAD, SM_RAD, EU_RAD, GD_RAD,
TB_RAD, DY_RAD, HO_RAD, ER_RAD, TM_RAD, YB_RAD, LU_RAD, HF_RAD, TA_RAD, WB_RAD,
RE_RAD, OS_RAD, IR_RAD, PT_RAD, AU_RAD, HG_RAD, TL_RAD, PB_RAD, BI_RAD, PO_RAD, 
AT_RAD, RN_RAD, FR_RAD, RA_RAD, AC_RAD, TH_RAD, PA_RAD, U_RAD, NP_RAD, PU_RAD, 
AM_RAD, CM_RAD, BK_RAD, CF_RAD, ES_RAD, FM_RAD, MD_RAD, NO_RAD, LR_RAD, HYBRID_RAD, ANY_RAD};

/* the actual atom names:
   these are in periodic table order except S and Si are switched.  Why - because
   proteins use Sg for S, and I use proteins more than organics... 
*/

char *element_names[NUMB_ELEMENTS] = 
{"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al", "S",
"P", "Si", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", 
"Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y", "Zr", "Nb", "Mo",
"Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te", "I", "Xe", "Cs", "Ba",
"La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb",
"Lu", "Hf", "Ta", "Wb", "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po",
"At", "Rn", "Fr", "Ra", "Ac", "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf",
"Es", "Fm", "Md", "No", "Lr", "C"};

/* function repositions y coordinates such that the origin (0,0) is in the */
/* lower left corner of the screen					   */
 
void flip_yaxis(int natoms, double **atoms, int maximum_y)
{
  register int index;

  for (index = 0; index < natoms; index++) 
    atoms[index][Y] = maximum_y -  atoms[index][Y];
}

/* correct for a left-handed display system */

void flip_zaxis(int natoms,double **atoms)
{
  register int index;

  for (index = 0; index < natoms; index++) 
    atoms[index][Z] = -atoms[index][Z];
}


int parse_inputs(int argc,char **argv,char *in,char *out,double *inc,int *axis,
				int *frame_counter,int *increment,
				double *radii_scale, int *obj_only, int *do_pdb, 
				int *do_sky, int *do_ground, int *do_check,
				int *do_vdw, int *do_cov, int *do_cpk, int *do_ball,
				double *threshold, int *do_hybrid, int *do_area, int *do_plain)
{
  int i,frames,rot_increment;
  double fudge,rad_scale;
  double thresh = 0.0;

  if (argc < 3) {
    fprintf(stderr,PDB2POV_USAGE,argv[0],argv[0]);
    return(0);
  }

  *axis = X; frames = 1; fudge = 1.0; rad_scale = 1.0;
  *radii_scale = 1.0;

  for (i = 3; i < argc && (*argv[i] == '-'); ++i) {
	switch(*(argv[i]+1)) {
	case 'v':
	  *do_vdw = 1;
	  *do_cpk = 0;
	  *do_cov = 0;
	  break;
	case 'c':
	  *do_vdw = 0;
	  *do_cpk = 0;
	  *do_cov = 1;
	  break;
	case 'b':
	  *do_ball = 1;
	  break;
	case 'd':
	  sscanf(argv[++i], " %lf",&thresh);
	  *threshold = thresh;
	  break;
	case 'm':
	  fudge = atof(argv[++i]);
	  break;
	case 'x':
	case 'X':
	  sscanf(argv[++i]," %lf",&xrot);
	  break;
	case 'y':
	case 'Y':
	  sscanf(argv[++i]," %lf",&yrot);
	  break;
	case 'z':
	case 'Z':
	  sscanf(argv[++i]," %lf",&zrot);
	  break;
	case 'i':
	case 'I':
	  sscanf(argv[++i]," %d",&rot_increment);
	  break;
	case 'r':
	  rad_scale = atof(argv[++i]);
	  *radii_scale = rad_scale <= 0.0 ? 1.0 : rad_scale;
	  break; 
	case 'o':
	case 'O':
	  *obj_only = 1;
	  break;
	case 't':
	case 'T':
	  *do_pdb = 0;
	  break;
	case 'a':
	case 'A':
	  *do_area = 1;
	  break;
	case 'p':
	case 'P':
	  *do_check = 0;
	  *do_ground = 0;
	  *do_sky = 0;
	  *do_plain = 1;
	  break;
	case 's':
	case 'S':
	  *do_sky = 1;
	  *do_plain = 0;
	  break;
	  
	case 'g':
	case 'G':
	  *do_ground = 1;
	  *do_check = 0;
	  break;
	case 'h':
	case 'H':
	  *do_check = 1;
	  *do_ground = 0;
	  break;
	case 'q':
	case 'Q':
	  *do_ball = 1;
	  *do_hybrid = 1;
	  break;
	default:
	  fprintf(stderr,"Parse error: Argument %s not understood exiting....\n",
argv[i]);
	  return(0);
	  break;
        }	/* switch */
      }		/* for    */ 
  
  if (*do_pdb == 1)
    {
      strcpy(in,argv[1]);
      strcat(in,".pdb");
    }
  else
    {
      strcpy(in,argv[1]);
      strcat(in,".atm");
    }

  strcpy(out,argv[2]);

  *frame_counter = frames;
  *increment = rot_increment;
  *inc = fudge <= 0.0 ? 1.0 : fudge;
  return(1);
}



/* The main module begins */

main(int argc,char **argv)
{
  
  double fudge;
  double center_position[3];

  double **atoms = NULL;
  double **patoms = NULL;
  double *charges = NULL;
  int    *atom_types = NULL;
  int    *res_types = NULL;
  int    *aromatic = NULL;
  int    **bonds = NULL;
  int    nbonds = 0;

  char **atype = NULL;
  char **amino = NULL;

  double max_scale;

  int do_pdb = 1;
  int do_sky = 0;
  int do_ground = 0;
  int do_check = 0;
  int do_cpk = 0;
  int do_cov = 0;
  int do_vdw = 1;
  int do_ball = 0;
  int do_hybrid = 0;
  int do_area = 0;
  int do_plain = 1;

  double rad_factor = 1.0;
  double threshold = 2.2;

  int natoms;
  int rotation_axis, rotation_frames, rotation_increment;
  int myerr = 0;

  int obj_only = 0;
  char inputfname[128],outputfname[128];
  

  /* Input routine for Mac to fake command line input */
#ifdef MAC_MW
#define max_line 80
  char mac_command_line[max_line];
  int mac_line_length;
  char a[16][64];			/* Storage for strings */
  char *mac_argv[16];		/* Array of pointers to strings */
  int i;
  fgets(mac_command_line,max_line,stdin);	/* Get line of user input from mac
window */
  argc=sscanf(mac_command_line,"%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
  			a[0],a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8]
  			,a[9],a[10],a[11],a[12],a[13],a[14],a[15]);
  for(i=0;i<=15;i++)
  		mac_argv[i]=&a[i][0];		/* Build array of pointers to strings */
  argv = mac_argv;					/* Use this array for argv */
#endif
  /* End of input routine for Mac */
  
  if (0 == parse_inputs(argc,argv,inputfname,outputfname,&fudge,
			&rotation_axis,&rotation_frames,
			&rotation_increment,&rad_factor, 
			&obj_only, &do_pdb, &do_sky, &do_ground, &do_check,
			&do_vdw, &do_cov, &do_cpk, &do_ball, &threshold,
			&do_hybrid, &do_area, &do_plain)) 
    {
      return(ERR_PARSE_ARGS);
    }

  printf("Scanning  atom file <%s>... ", inputfname);
  natoms = getpdb_atnum(inputfname);

  if (natoms <= 0)
    {
      printf("Couldn't read any atoms from <%s>! Aborting.\n", inputfname);
      myerr = ERR_NO_ATOMS;
      exit(myerr);
    }

  printf("Got <%d> atoms. \n", natoms);

  if ((atoms = dmatrix(natoms, 3)) != NULL) {
      if ((patoms = dmatrix(natoms, 3)) != NULL) {
	  if ((charges = dvector(natoms)) != NULL) {
	      if ((atype = cmatrix(natoms, 4)) != NULL) {
		  if ((amino = cmatrix(natoms, 4)) != NULL) {
		      if ((atom_types = ivector(natoms)) != NULL) {
			  if ((res_types = ivector(natoms)) != NULL) {
			      if (do_pdb)
				  getpdb(inputfname,natoms,atoms,atype,charges,amino);
			      else
				  getatm(inputfname,natoms,atoms,atype,charges);
			      
			      /* must call makerestype first to set up AminoAcids! */
			      makerestype(amino,natoms,res_types);
			      makeatomtype(atype, natoms, atom_types, res_types);

			      max_scale = 1;
			      
			      printf("Re-orienting and positioning molecule. \n");
			      
			      rotate_molecule(natoms,atoms,patoms,xrot, yrot, zrot); 
			      center_molecule(natoms,patoms,center_position);
			      
			      flip_zaxis(natoms,patoms); /* for left handed coordinate system */
			      
				  printf("Computing bonds: ");
				  if ((aromatic = ivector(natoms)) == NULL)
					{
					      free_ivector(res_types, natoms);
					      free_ivector(atom_types, natoms);
					      free_cmatrix(amino, natoms, 4);
					      free_cmatrix(atype, natoms, 4);
					      free_dvector(charges, natoms);
					      free_dmatrix(patoms, natoms, 3);
					      free_dmatrix(atoms, natoms, 3);
					      myerr = ERR_NO_BONDS;
					      printf("No space for aromatics! Errorcode is: %d\n", ERR_NO_BONDS);
					      exit(myerr);
					  }

				  if ((nbonds = computebonds(patoms, atype, natoms, threshold,
					                         aromatic)) <= 0)
					  {
					      free_ivector(res_types, natoms);
					      free_ivector(atom_types, natoms);
					      free_cmatrix(amino, natoms, 4);
					      free_cmatrix(atype, natoms, 4);
					      free_dvector(charges, natoms);
					      free_dmatrix(patoms, natoms, 3);
					      free_dmatrix(atoms, natoms, 3);
					      myerr = ERR_NO_BONDS;
					      printf("No bonds found? Errorcode is: %d\n", ERR_NO_BONDS);
					      exit(myerr);
					  }

				if (do_ball)
				  {
				    if ((bonds = imatrix(nbonds,2))!=NULL)
					  {
					      makebonds(patoms, atype, natoms, nbonds, threshold, bonds);
					      rad_factor *= .3;
					      write_output(outputfname, natoms, patoms, atom_types, 
							   bonds, nbonds, rad_factor, obj_only, 
							   do_sky, do_ground, do_check, do_cpk, 
							   do_cov, do_vdw, do_ball, do_hybrid, do_area, do_plain,
							   aromatic);
					      free_imatrix(bonds,nbonds,2);
					  }
				      else
					  {
						  free_ivector(aromatic, natoms);
					      free_ivector(res_types, natoms);
					      free_ivector(atom_types, natoms);
					      free_cmatrix(amino, natoms, 4);
					      free_cmatrix(atype, natoms, 4);
					      free_dvector(charges, natoms);
					      free_dmatrix(patoms, natoms, 3);
					      free_dmatrix(atoms, natoms, 3);
					      printf("can't allocate memory for bonds??\n");
					      myerr = ERR_CANT_ALLOC_BONDS;
					      exit(myerr);
					  }
				  }
			      else
				  write_output(outputfname, natoms, patoms, atom_types, 
					       bonds, nbonds, rad_factor, obj_only, 
					       do_sky, do_ground, do_check, do_cpk, 
					       do_cov, do_vdw, do_ball, do_hybrid, do_area, 
						   do_plain, aromatic);
			      free_ivector(res_types, natoms);
				  free_ivector(aromatic, natoms);
			  }
			  free_ivector(atom_types, natoms);
		      }
		      free_cmatrix(amino, natoms, 4);
		  }
		  free_cmatrix(atype, natoms, 4);
	      }
	      free_dvector(charges, natoms);
	  }
	  free_dmatrix(patoms, natoms, 3);
      }
      free_dmatrix(atoms, natoms, 3);
  }
  exit(0);
}

/******************************* End of pdb2pov.c ****************************/
