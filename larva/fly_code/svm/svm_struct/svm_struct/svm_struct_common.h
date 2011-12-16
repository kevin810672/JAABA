/***********************************************************************/
/*                                                                     */
/*   svm_struct_common.h                                               */
/*                                                                     */
/*   Functions and types used by multiple components of SVM-struct.    */
/*                                                                     */
/*   Author: Thorsten Joachims                                         */
/*   Date: 31.10.05                                                    */
/*                                                                     */
/*   Copyright (c) 2005  Thorsten Joachims - All rights reserved       */
/*                                                                     */
/*   This software is available for non-commercial use only. It must   */
/*   not be modified and distributed without prior permission of the   */
/*   author. The author is not responsible for implications from the   */
/*   use of this software.                                             */
/*                                                                     */
/***********************************************************************/

#ifndef svm_struct_common
#define svm_struct_common

//#ifdef DEBUG > 0 
//extern char *g_currFile; // CSC 20110420: hack to pass current filename for debug purposes
//#endif

# define STRUCT_VERSION       "V3.10"
# define STRUCT_VERSION_DATE  "14.08.08"

class SVMStructMethod;

#include "../svm_light/svm_common.h"
#include "../svm_struct_api_types.h"

class StructuredSVMOnlineLearner;

typedef struct example {  /* an example is a pair of pattern and label */
  SPATTERN x;
  LABEL y;
  char labelname[1001]; // CSC 20110420: store filename labels are loaded from here, used for debug purposes
} EXAMPLE;

typedef struct sample { /* a sample is a set of examples */
  int     n;            /* n is the total number of examples */
  EXAMPLE *examples;
} SAMPLE;

typedef struct constset { /* a set of linear inequality constrains of
			     for lhs[i]*w >= rhs[i] */
  int     m;            /* m is the total number of constrains */
  DOC     **lhs;
  double  *rhs;
} CONSTSET;


/**** print methods ****/
void printIntArray(int*,int);
void printDoubleArray(double*,int);
void printWordArray(SWORD*);
void printModel(MODEL *);
void printW(double *, long, long, double);
void save_const_set(CONSTSET cset, const char *fname);
CONSTSET load_const_set(const char *fname);

void train_main(int argc, const char** argv, STRUCT_LEARN_PARM *struct_parm, STRUCTMODEL *structmodel, SVMStructMethod *m=NULL, StructuredSVMOnlineLearner **learner_ptr=NULL);
int test_main(int argc, const char* argv[], STRUCT_LEARN_PARM *struct_parm, STRUCTMODEL *structmodel=NULL, SVMStructMethod *m=NULL);

extern long   struct_verbosity;              /* verbosity level (0-4) */

#endif