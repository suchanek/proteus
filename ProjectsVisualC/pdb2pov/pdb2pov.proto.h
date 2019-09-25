void compute_extents(int natoms, double **atoms, double *xmin, double *xmax,
double *ymin, double *ymax, double *zmin, double *zmax);
void make_rotmat(double rotmat[3][3], double gamma, double beta, double theta); 
void matmul(double new[3][3], double old[3][3]);
void print_coords(int natoms, double **atoms);
void flip_yaxis(int natoms, double **atoms, int maximum_y);
void flip_zaxis(int natoms,double **atoms);
int parse_inputs(int argc,char **argv,char *in,char *out,double *inc,int *axis,
				int *frame_counter,int *increment,
	     double *radii_scale, int *obj_only, int *do_pdb, 
	     int *do_sky, int *do_ground, int *do_check,
	     int *do_vdw, int *do_cov, int *do_cpk, int *do_ball,
	     double *threshold, int *do_hybrid, int *do_area, int *do_plain);
void center_molecule(int natoms, double **atoms, double center[]);
void molecule_cofmass(int natoms, double **atoms,double center[]);
void translate_molecule(int natoms, double **atoms, int MAX_X, int MAX_Y);
double compute_max_scale(int natoms, double **atoms, int MAX_X, int MAX_Y);
void rotate_molecule(int natoms, double **atoms, double **patoms, 
		    double xrot, double yrot, double zrot);
void write_camera(FILE *f, double xmin, double xmax, double ymin, 
		  double ymax, double zmin, double zmax);
void write_light(FILE *f, double xmin, double xmax, double ymin, 
		 double ymax, double zmin, double zmax, int do_area);
void write_sky(FILE *f);
void write_sky_plain(FILE *f);
void write_ground(FILE *f, double xmin, double xmax, double 
		  ymin, double ymax, double zmin, double zmax);
void write_check(FILE *f, double xmin, double xmax, double 
		  ymin, double ymax, double zmin, double zmax);
double compute_sphere(int natoms, double **atoms);
int write_output(char *out, int natoms, double **atoms, int *atom_types, 
	     int **bonds, int nbonds, double rad_factor, int obj_only, 
	     int do_sky, int do_ground, int do_check,
	     int do_cpk, int do_cov, int do_vdw, int do_ball, int do_hybrid, int
do_area, int do_plain, int *aromatic);
void inc_rotmat(double rotmat[3][3], double gamma, double beta, 
		double theta) ;
int matrix_times_vector(double matrix[3][3], double *x, double *y, double *z);
int getpdb(char *fname, int maxnatoms, double **apos, 
	   char **atype, double *charge, char **amino);
int fgetpdb(FILE *f, int maxnatoms, 
	    double **apos, char **atype, double *charge, char **amino);
int fgetpdbxyz(FILE *in, int maxnatoms, double **apos);
int getpdb_atnum(char *fname);
int fgetpdb_atnum(FILE *in);
int getatm(char *fname, int maxnatoms, double **apos, char **atype, double
*charge);
int fgetatm(FILE *f, int maxnatoms, double **apos, char **atype, double
*charge);
void makeatomtype(char **atype, int natoms, int *atomtype, int *restype);
void makerestype(char **resnames, int natoms, int *restypes);

int isAminoAcid(int atom_numb, int *restypes);

int makebonds(register double **apos, char **atype, int natoms, 
	      int maxnbonds, double threshold, int **bonds);
int computebonds(register double **apos, char **atype, int natoms, double
threshold, int *aromatic);

int isCarbon (char *a);

