/* $Id: pdb2pov_output.c,v 1.2 1997/02/07 17:13:26 suchanek Exp $ */
/* File for POV-Ray specific output routines. These subroutines are
   part of pdb2pov, a program by Eric G. Suchanek, Ph.D. for the
   creation of POV-Ray input from molecular data.
   */

/* $Log: pdb2pov_output.c,v $
 * Revision 1.2  1997/02/07  17:13:26  suchanek
 * *** empty log message ***
 * */


#include "pdb2pov.h"

extern char *element_names[];

/* write the camera definitions out to the output file */
 
void write_camera(FILE *f, double xmin, double xmax, double ymin, 
		  double ymax, double zmin, double zmax)
{
  double xavg = (xmax - xmin) / 2.0;
  double yavg = (ymax - ymin) / 2.0;
  double zavg = (zmax - zmin) / 2.0;

  double theta = 25.0 / 57.298;
  double dist, distx, disty, distz;

  distx = -xavg / (tan(theta));
  disty = -yavg / (tan(theta));
  distz = -zavg / (tan(theta));

  dist = min(distx, disty);
  dist = min(dist, distz);

  fprintf(f,"camera {\n");
  fprintf(f,"   location < 0, 0, %.3lf > \n", dist);

  fprintf(f,"   direction < 0, 0, 1> \n");
  fprintf(f, "   up <0, 1, 0> \n");
  fprintf(f, "   right <4/3, 0, 0> \n");
  fprintf(f, "   look_at <0, 0, 0> \n");
  fprintf(f,"}\n");

}

/* write the lighting definitions out to the output file */

void write_light(FILE *f, double xmin, double xmax, double ymin, 
		 double ymax, double zmin, double zmax, int do_area)
{
  double xavg = (xmax - xmin) / 2.0;

  double theta = 20.0 / 57.298;
  double dist = 1.0;

  dist = -xavg / (tan(theta));

  fprintf(f,"object { \n");
  fprintf(f,"  light_source {\n");
  fprintf(f,"     <%.3lf, %.3lf, %.3lf> \n", xmax, ymax, dist);
  fprintf(f,"     color White \n");
  if (do_area)
    {
      fprintf(f,"     area_light <%.3lf, 0, 0>, <0, 0, %.3lf>, 9, 9 \n", xmax /
2.0, xmax / 2.0);
      fprintf(f,"     adaptive 1 \n");
      fprintf(f,"     jitter \n");
   }

  fprintf(f,"  }\n");
  fprintf(f,"}\n");

}

void write_sky(FILE *f)
{
 static char *SkyString = "#declare Sky = sky_sphere {\n\
  pigment {\n\
    gradient y\n\
    color_map {\n\
      [0.75  color CornflowerBlue]\n\
      [1.00  color MidnightBlue]\n\
    }\n\
    scale 2\n\
    translate <-1, -1, -1>\n\
  }\n\
  pigment {\n\
    bozo\n\
    turbulence 0.6\n\
    octaves 7\n\
    omega .49876\n\
    lambda 2.5432\n\
    color_map {\n\
      [0.0 color rgbf<.75, .75, .75, 0.1>]\n\
      [0.4 color rgbf<.9, .9, .9, .9>]\n\
      [0.7 color rgbf<1, 1, 1, 1>]\n\
    }\n\
    scale 6/10\n\
    scale <1, 0.3, 0.3>\n\
  }\n\
  pigment {\n\
    bozo\n\
    turbulence 0.6\n\
    octaves 8\n\
    omega .5123\n\
    lambda 2.56578\n\
    color_map {\n\
      [0.0 color rgbf<.375, .375, .375, 0.2>]\n\
      [0.4 color rgbf<.45, .45, .45, .9>]\n\
      [0.6 color rgbf<0.5, 0.5, 0.5, 1>]\n\
    }\n\
    scale 6/10\n\
    scale <1, 0.3, 0.3>\n\
  }\n\
}\n sky_sphere{Sky}\n\n";

		fprintf(f,"%s\n", SkyString);
}

void write_sky_plain(FILE *f)
{
  fprintf(f,"/* A plain white sky */ \n");
  fprintf(f,"background{White} \n\n");
}


/* write the ground definitions out to the output file */

void write_ground(FILE *f, double xmin, double xmax, double 
		  ymin, double ymax, double zmin, double zmax)
{
  double yavg = (ymax - ymin) / 2.0;

  fprintf(f,"object { \n");
  fprintf(f,"  plane { y, %3lf }\n",
	  -1.0 * (fabs(ymin) + fabs(yavg) / 2.0));
  fprintf(f," pigment {color RichBlue quick_color RichBlue} \n");
  fprintf(f," normal {bumps 0.2} \n");
  fprintf(f,"}\n");
}

void write_check(FILE *f, double xmin, double xmax, double 
		  ymin, double ymax, double zmin, double zmax)
{
  double xavg = (xmax - xmin) / 2.0;
  double yavg = (ymax - ymin) / 2.0;

  fprintf(f,"/* Create the beloved famous raytrace checkered floor */ \n");
  fprintf(f,"plane { y, %3lf \n", 	  -1.0 * (fabs(ymin) + fabs(yavg) / 2.0));
  fprintf(f,"      pigment { \n");
  fprintf(f,"      checker colour Black colour White \n");
  fprintf(f,"      scale %3lf \n", ((xavg + yavg) / 3.0));
  fprintf(f,"     } \n");
  fprintf(f,"     finish { \n");
  fprintf(f,"       ambient 0.2 \n");
  fprintf(f,"       diffuse 0.8 \n");
  fprintf(f,"     } \n");
  fprintf(f,"} \n");

}

/* compute the bounding sphere for the atom list. adds the constant MAX_RAD to
   account for the radii of the atoms (overestimate) */

double compute_sphere(int natoms, double **atoms)

{
  double rad = 0.0;
  double rad_max = -999.9;
  double x, y, z;
  int i;

  for (i = 0; i < natoms; i++)
    {
      x = atoms[i][0] ; y = atoms[i][1]; z = atoms[i][2];
      rad = sqrt((x * x + y * y + z * z)) + MAX_RAD;
      if (rad > rad_max) rad_max = rad;
    }


  return (rad_max);

}

int write_output(char *out, int natoms, double **atoms, int *atom_types, 
	     int **bonds, int nbonds, double rad_factor, int obj_only, 
	     int do_sky, int do_ground, int do_check,
	     int do_cpk, int do_cov, int do_vdw, int do_ball,
	     int do_hybrid, int do_area, int do_plain, int *aromatic)
{
#ifdef AMIGA
  char drive[FNSIZE], path[FMSIZE], node[FNSIZE], ext[FESIZE];
#endif

  FILE *f;
  FILE *fopen();
  int i;
  char tmp[128];

  char numb[8];
  double xmin, ymin, xmax, ymax, zmin, zmax;
  double sphere_rad = 0.0;
  int ok = 1;

  /* new code 12/30/96 -egs- */
	double dist, radi, radj, dx, dy, dz;
	double px, py, pz, qx, qy, qz;
	extern double Atom_Radii[];
	double center_x, center_y, center_z;
	int atom_start, atom_end;
	int type_start, type_end;

  time_t t;
  struct tm *gm;

  char date[10];
  char ttime[9];

  char time_string[20];

  time(&t);
  gm = localtime(&t);
  sprintf(date,"%02d/%02d/%02d \0", gm->tm_mon+1, gm->tm_mday, gm->tm_year);
  sprintf(ttime,"%02d:%02d:%02d\0", gm->tm_hour, gm->tm_min, gm->tm_sec);

  strcpy(time_string,date);
  strcat(time_string,ttime);

  if (obj_only)
    {
      sprintf(numb,".inc");
      strcpy(tmp,out);
      strcat(tmp,numb);
    }
  else
    {
      sprintf(numb,".pov");
      strcpy(tmp,out);
      strcat(tmp,numb);
    }

/* Amiga stuff */
#ifdef AMIGA
  strsfn(out, drive, path, node, ext);
#endif

  compute_extents(natoms,atoms,&xmin,&xmax,&ymin,&ymax,&zmin,&zmax);  
  sphere_rad = compute_sphere(natoms,atoms);
  sphere_rad += .02 * sphere_rad; /* fudge factor for bounding sphere */

  if ((f = fopen(tmp,"w")) == NULL) {
	fprintf(stderr,"\nCan't open output file (%s) for writing...\n",out);
	return(ERR_CANT_WRITE_OUTPUT);
  }
  
  printf("Writing output file <%s> \n", tmp);

/* Amiga stuff */
#ifdef AMIGA
  fprintf(f,"//\n// PDB2POV (Amiga) atom input prepared by pdb2pov %s\n",time_string);
#endif
/* Unix stuff */
#ifdef UNIX
  fprintf(f,"//\n// PDB2POV (UNIX) atom input prepared by pdb2pov %s\n",time_string);
#endif
/* Macintosh Metrowerks compiler */
#ifdef MAC_MW
  fprintf(f,"//\n// PDB2POV (Mac) atom input prepared by pdb2pov %s\n",time_string);
#endif

#ifdef DOS
  fprintf(f,"//\n// PDB2POV (DOS) atom input prepared by pdb2pov %s\n",time_string);
#endif

  fprintf(f,"// Author: Eric G. Suchanek, Ph.D. \n");
  fprintf(f,"// Mac port: Richard G. Rothwell, Ph.D. \n");
  fprintf(f,"//\tAtoms: %4d \n",natoms);
  fprintf(f,"//\tExtent:\tXmin: %.3f Xmax: %.3f, \n//\t\tYmin: %.3f, Ymax: %.3f\n", 
	  xmin, xmax, ymin, ymax);
  fprintf(f,"//\t\tZmin: %.3f Zmax: %.3f \n",zmin,zmax);
    fprintf(f,"//\tEnclosing Sphere: %.3f\n\n", sphere_rad);

	fprintf(f,"#version 3.0\n");
	fprintf(f,"global_settings {\n   max_trace_level 10 \n");
#ifdef MAC_MW
		fprintf(f,"   assumed_gamma 2.2 } \n\n");
#endif

#ifdef AMIGA
	fprintf(f,"   assumed_gamma 2.2 } \n\n");
#endif
	
#ifdef DOS
		fprintf(f,"   assumed_gamma 1.8 } \n\n");
#endif

  if (! obj_only)
    {
      fprintf(f,"#include \"colors.inc\"\n");
      fprintf(f,"#include \"shapes.inc\"\n");
      fprintf(f,"#include \"textures.inc\"\n");
	  fprintf(f,"#include \"skies.inc\"\n");
      if (do_cpk)
	{
	  fprintf(f,"#include \"atoms_vdw.inc\"\n"); /* radii */
	  fprintf(stderr,"This option is not supported, using defaults.\n");
	}

      else
	{
	  if (do_vdw)
	    fprintf(f,"#include \"atoms_vdw.inc\"\n"); /* radii */
	  else
	    {
	      if (do_cov)
		{
		  fprintf(f,"#include \"atoms_vdw.inc\"\n"); /* radii */
		  fprintf(stderr,"This option is not supported, using defaults.\n");
		}
	    }
	}

	fprintf(f,"#include \"atoms2.inc\"\n"); /* atom objects */
	  if (do_ball)
		  fprintf(f, "#include \"bonds.inc\"\n"); /* bond textures */

/*
      if (do_hybrid)
	fprintf(f,"#include \"atoms_glass2.inc\"\n");
*/
	write_camera(f, xmin, xmax, ymin, ymax, zmin, zmax);
      write_light(f, xmin, xmax, ymin, ymax, zmin, zmax, do_area);
      if (do_sky)
		write_sky(f);
      else
		write_sky_plain(f);
      if (do_ground)
		write_ground(f, xmin, xmax, ymin, ymax, zmin, zmax);
      else
	if (do_check)
	  write_check(f, xmin, xmax, ymin, ymax, zmin, zmax);

    }

  if (do_ball)
    {
      fprintf(f, "#declare BOND_RADIUS = %.2lf \n", BOND_RAD);
    }

  if (do_hybrid)
    {
      fprintf(f, "#declare ATM_SCL_B = %.2lf \n", rad_factor / .3);
    }

  fprintf(f, "#declare ATM_SCL = %.2lf \n \n", rad_factor);



  /* do the glass atoms */
  if (do_hybrid)
    {
/* Amiga stuff */
#ifdef AMIGA
      fprintf(f,"#declare %s_obj_glass = merge {\n",node); /* was out */
/* Unix & Mac stuff */
#else
      fprintf(f,"#declare %s_obj_glass = merge {\n",out); /* was out */
#endif      
      for (i = 0; i < natoms; i++)
	{
	    fprintf(f,"object {Atom_Glass_%s ", element_names[atom_types[i]]);
	    ok = 1;
	  if (ok)
	    {
	      fprintf(f,"scale <ATM_SCL_B, ATM_SCL_B, ATM_SCL_B> ");
	      fprintf(f,"translate <%.3f, %.3f, %.3f> }\n",
		      atoms[i][0],atoms[i][1],atoms[i][2]);
	    }
	  
	} /* for */
      fprintf(f,"}\n");   /* merge */
      
    }

/* Amiga stuff */
#ifdef AMIGA
  fprintf(f,"#declare %s_obj = union {\n",node);
/* Unix & Mac stuff */
#else
  fprintf(f,"#declare %s_obj = union {\n",out);
#endif

  /* do the atoms */
  for (i = 0; i < natoms; i++)
    {
	fprintf(f,"object {Atom_%s ", element_names[atom_types[i]]);
	ok = 1;
	if (ok)
	    {
		if (aromatic[i])
			fprintf(f,"scale ATM_SCL * .8 ");
		else
		    fprintf(f,"scale ATM_SCL ");
		fprintf(f,"translate <%.3f, %.3f, %.3f> }\n",
			atoms[i][0],atoms[i][1],atoms[i][2]);
	    }
	
    }


  /* do the bonds */
  /* new code 12/28/96 -egs- */
  if (do_ball)
    for (i = 0; i < nbonds; i++)
      {
		
#ifdef NOISY
	fprintf(stderr, "Bond %d, type: %d, type: %d name: %s name2: %s \n",
			i, type_start, type_end,  element_names[type_start],
			element_names[type_end]);
#endif
	
	atom_start = bonds[i][0]; 
	atom_end = bonds[i][1];
	
	type_start = atom_types[atom_start]; 
	type_end = atom_types[atom_end];

	if (type_start != type_end)
	  {
	    dx = atoms[atom_start][0] - atoms[atom_end][0];
	    dy = atoms[atom_start][1] - atoms[atom_end][1];
	    dx = atoms[atom_start][2] - atoms[atom_end][2];
	    
	    dist = sqrt ((dx * dx) + (dy * dy) + (dz * dz));

	    dx = -dx;
	    dy = -dy;
	    dz = -dz;

	    radi = Atom_Radii[type_start] * rad_factor;
	    radj = Atom_Radii[type_end] * rad_factor; 

	    px = atoms[atom_start][0] + radi * dx;
	    py = atoms[atom_start][1] + radi * dy;
	    pz = atoms[atom_start][2] + radi * dz;
	    
	    qx = atoms[atom_end][0] - radj * dx;
	    qy = atoms[atom_end][1] - radj * dy;
	    qz = atoms[atom_end][2] - radj * dz;

		/* this final position, then should exactly split the 
	       distance between the surfaces of the atoms. */
		 
	    center_x = (px + qx) / 2.0;
	    center_y = (py + qy) / 2.0;
	    center_z = (pz + qz) / 2.0;
	    
	    fprintf(f, "cylinder { <%.3lf, %.3lf, %.3lf>, <%.3lf, %.3lf, %.3lf>, BOND_RADIUS texture {Bond_%s} } \n", 
		    atoms[atom_start][0], 
		    atoms[atom_start][1], 
		    atoms[atom_start][2],
		    center_x, center_y, center_z,
		    element_names[type_start]);

	    fprintf(f, "cylinder { <%.3lf, %.3lf, %.3lf>, <%.3lf, %.3lf, %.3lf>, BOND_RADIUS texture {Bond_%s} } \n", 
		    center_x, center_y, center_z,
		    atoms[atom_end][0], 
		    atoms[atom_end][1], 
		    atoms[atom_end][2],
		    element_names[type_end]);
	  }

	else
	  fprintf(f, "cylinder { <%.3lf, %.3lf, %.3lf>, <%.3lf, %.3lf, %.3lf>, BOND_RADIUS texture {Bond_%s} } \n", 
		  atoms[atom_start][0], 
		  atoms[atom_start][1], 
		  atoms[atom_start][2],
		  atoms[atom_end][0], 
		  atoms[atom_end][1], 
		  atoms[atom_end][2],
		  element_names[type_start]);
      } /* for */

  if (do_hybrid)
    {
/* Amiga stuff */
#ifdef AMIGA
      fprintf(f, "object { %s_obj_glass} \n", node);
/* Unix & Mac stuff */
#else
      fprintf(f, "object { %s_obj_glass} \n", out);
#endif
    }
  fprintf(f,"}\n");   /* composite */

/* Amiga stuff */
#ifdef AMIGA
  fprintf(f,"\n#declare %s = object {\n\tobject { %s_obj } } \n", node, node);
/* Unix & Mac stuff */
#else
  fprintf(f,"\n#declare %s = object {\n\tobject { %s_obj } }\n ", out, out);
#endif
  
  if (! obj_only)
/* Amiga stuff */
#ifdef AMIGA
    fprintf(f,"\nobject { %s } \n", node);
/* Unix & Mac stuff */
#else
    fprintf(f,"\nobject { %s } \n", out);
#endif
	return(RETURN_OK);
}


/****** end of file pdb2pov_output.c ****************/
