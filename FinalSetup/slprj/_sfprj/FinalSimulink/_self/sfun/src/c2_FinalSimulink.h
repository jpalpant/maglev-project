#ifndef __c2_FinalSimulink_h__
#define __c2_FinalSimulink_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
typedef struct {
  const char *context;
  const char *name;
  const char *dominantType;
  const char *resolved;
  uint32_T fileLength;
  uint32_T fileTime1;
  uint32_T fileTime2;
} c2_ResolvedFunctionInfo;

typedef struct {
  real_T c2_ni;
  SimStruct *S;
  uint32_T c2_twister_state[625];
  uint32_T c2_v4_state;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c2_doneDoubleBufferReInit;
  boolean_T c2_isStable;
  boolean_T c2_method_not_empty;
  boolean_T c2_ni_not_empty;
  boolean_T c2_twister_state_not_empty;
  boolean_T c2_v4_state_not_empty;
  uint8_T c2_is_active_c2_FinalSimulink;
  uint8_T c2_method;
  ChartInfoStruct chartInfo;
} SFc2_FinalSimulinkInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c2_FinalSimulink_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c2_FinalSimulink_get_check_sum(mxArray *plhs[]);
extern void c2_FinalSimulink_method_dispatcher(SimStruct *S, int_T method, void *
  data);

#endif
