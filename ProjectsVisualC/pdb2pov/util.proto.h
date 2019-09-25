double hypot(double x, double y);
void EGS_error(char error_text[]);
double **dmatrix(int nrh,int nch);
void free_dmatrix(double **m,int nrh, int nch);
int **imatrix(int nrh,int nch);
void free_imatrix(int **m, int nrh, int nch);
char **cmatrix(int nrh,int nch);
void free_cmatrix(char **m, int nrh, int nch);
double *dvector(int nh);
void free_dvector(double *v,int nh);
int *ivector(int nh);
void free_ivector(int *v,int nh);

