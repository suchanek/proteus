/* $Id $ */
/* Master include file for pdb2pov */
/* Author: Eric G. Suchanek, Ph.D. */

#ifndef PDB2POV_INCLUDE
#define PDB2POV_INCLUDE

/* Set operating system here. Could also do this on command line */

/* #define UNIX */
/* #define AMIGA */
/* #define MAC_MW */

#define DOS 1

#define FNSIZE 256
#define FMSIZE 256
#define FESIZE 256


/* Include Mac stuff here */
#ifdef MAC_MW
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#endif

/* Include Dos stuff here */
#ifdef DOS
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#endif

/* Include unix stuff here */
#ifdef UNIX
#include <malloc.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include <math.h>
#endif

/* Include Amiga stuff here */
#ifdef AMIGA
#include <exec/types.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#ifdef _M68881
#include <m68881.h>
#endif

#define  __USE_SYSBASE
#include <proto/exec.h>
#include <proto/all.h>

#endif 

/* More Amiga stuff */
#ifdef AMIGA
#include "asyncio.h"
#include "asyncio_protos.h"
#include "pdb2pov_protos.h"
#include "util.proto.h"

long __stack = 8192;
#endif

#include <stdio.h>
#include <time.h>

/* More Mac stuff */
#ifdef MAC_MW
#include "pdb2pov.proto.h"
#include "util.proto.h"
#endif

/* More DOS stuff */
#ifdef DOS
#include "pdb2pov.proto.h"
#include "util.proto.h"
#endif

#ifdef UNIX
#include "pdb2pov.proto.h"
#include "util.proto.h"
#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))
#endif

/* General includes */
#include "pdb2pov_errors.h"


/* Program specific defines */

#define MAX_ATOMS 	500
#define O_COLOR 	1
#define N_COLOR 	8
#define C_COLOR 	2
#define S_COLOR 	4
#define H_COLOR 	0
#define P_COLOR 	4
#define FE_COLOR 	10
#define CA_COLOR 	11
#define REFLECTIVITY 	4
#define MAX_RADIUS 	100
#define CENTER_X	(MAX_X / 2) 
#define CENTER_Y	(MAX_Y / 2)
#define X		0
#define Y		1
#define Z		2

#define BOND_RAD 0.20

// added an element for aromatic types

#define NUMB_ELEMENTS 104
#define ATOM_NAME_LEN 2

/* new stuff 12/31/96 -egs- */

#define FUDGE (float) 1.0

#define H_RAD ((float) 1.2000)
#define HE_RAD ((float) 1.2200)
#define LI_RAD ((float) 1.5200)
#define BE_RAD ((float) 1.7000)
#define B_RAD ((float) 2.0800)
#define C_RAD ((float) 1.8500)
#define HYBRID_RAD ((float) 1.5)

#define N_RAD ((float) 1.5400)
#define O_RAD ((float) 1.4000)
#define F_RAD ((float) 1.3500)
#define NE_RAD ((float) 1.6000)
#define NA_RAD ((float) 2.3100)
#define MG_RAD ((float) 1.7000)
#define AL_RAD ((float) 2.0500)
#define SI_RAD ((float) 2.0000)
#define P_RAD ((float) 1.9000)
#define S_RAD ((float) 1.8500)
#define CL_RAD ((float) 1.8100)
#define AR_RAD ((float) 1.9100)
#define K_RAD ((float) 2.3100)
#define CA_RAD ((float) 1.9730)
#define SC_RAD ((float) 1.7000)
#define TI_RAD ((float) 1.7000)
#define V_RAD ((float) 1.7000)
#define CR_RAD ((float) 1.7000)
#define MN_RAD ((float) 1.7000)
#define FE_RAD ((float) 1.7000)
#define CO_RAD ((float) 1.7000)
#define NI_RAD ((float) 1.7000)
#define CU_RAD ((float) 1.7000)
#define ZN_RAD ((float) 1.7000)
#define GA_RAD ((float) 1.7000)
#define GE_RAD ((float) 1.7000)
#define AS_RAD ((float) 2.0000)
#define SE_RAD ((float) 2.0000)
#define BR_RAD ((float) 2.1000)
#define KR_RAD ((float) 1.7000)
#define RB_RAD ((float) 1.7000)
#define SR_RAD ((float) 1.7000)
#define Y_RAD ((float) 1.7000)
#define ZR_RAD ((float) 1.7000)
#define NB_RAD ((float) 1.7000)
#define MO_RAD ((float) 1.7000)
#define TC_RAD ((float) 1.7000)
#define RU_RAD ((float) 1.7000)
#define RH_RAD ((float) 1.7000)
#define PD_RAD ((float) 1.7000)
#define AG_RAD ((float) 1.7000)
#define CD_RAD ((float) 1.7000)
#define IN_RAD ((float) 1.7000)
#define SN_RAD ((float) 1.7000)
#define SB_RAD ((float) 2.2000)
#define TE_RAD ((float) 2.2000)
#define I_RAD ((float) 2.1500)
#define XE_RAD ((float) 1.7000)
#define CS_RAD ((float) 1.7000)
#define BA_RAD ((float) 1.7000)
#define LA_RAD ((float) 1.7000)
#define CE_RAD ((float) 1.7000)
#define PR_RAD ((float) 1.7000)
#define ND_RAD ((float) 1.7000)
#define PM_RAD ((float) 1.7000)
#define SM_RAD ((float) 1.7000)
#define EU_RAD ((float) 1.7000)
#define GD_RAD ((float) 1.7000)
#define TB_RAD ((float) 1.7000)
#define DY_RAD ((float) 1.7000)
#define HO_RAD ((float) 1.7000)
#define ER_RAD ((float) 1.7000)
#define TM_RAD ((float) 1.7000)
#define YB_RAD ((float) 1.7000)
#define LU_RAD ((float) 1.7000)
#define HF_RAD ((float) 1.7000)
#define TA_RAD ((float) 1.7000)
#define WB_RAD ((float) 1.7000)
#define RE_RAD ((float) 1.7000)
#define OS_RAD ((float) 1.7000)
#define IR_RAD ((float) 1.7000)
#define PT_RAD ((float) 1.7000)
#define AU_RAD ((float) 1.7000)
#define HG_RAD ((float) 1.7000)
#define TL_RAD ((float) 1.7000)
#define PB_RAD ((float) 1.7000)
#define BI_RAD ((float) 1.7000)
#define PO_RAD ((float) 1.7000)
#define AT_RAD ((float) 1.7000)
#define RN_RAD ((float) 1.7000)
#define FR_RAD ((float) 1.7000)
#define RA_RAD ((float) 1.7000)
#define AC_RAD ((float) 1.7000)
#define TH_RAD ((float) 1.7000)
#define PA_RAD ((float) 1.7000)
#define U_RAD ((float) 1.7000)
#define NP_RAD ((float) 1.7000)
#define PU_RAD ((float) 0.9000)
#define AM_RAD ((float) 0.0010)
#define CM_RAD ((float) 0.0010)
#define BK_RAD ((float) 0.0010)
#define CF_RAD ((float) 0.0010)
#define ES_RAD ((float) 0.0010)
#define FM_RAD ((float) 0.0010)
#define MD_RAD ((float) 0.0010)
#define NO_RAD ((float) 0.0010)
#define LR_RAD  ((float) 0.0010)
#define ANY_RAD ((float) 1.7)
#define MAX_RAD ((float) 2.3)

#define streq(a,b) (0==strcmp(a,b))

typedef float CoordSys[4][3];

#define P 0
#define H 1
#define L 2
#define U 3
#define X 0
#define Y 1
#define Z 2

struct atom_struct {
  double pos[3];
  char atype[4];
  char amino[4];
  char charges[4];
};

/* New stuff for Amino Acid names */
#define NUMAMINOACIDS 21
#define UNKNOWN_TYPE 21
#define NOT_AMINO_ACID -1

#endif  /* ifndef PDB2POV_INCLUDE */
