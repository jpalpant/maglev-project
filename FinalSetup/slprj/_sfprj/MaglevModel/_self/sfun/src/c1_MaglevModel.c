/* Include files */

#include "blascompat32.h"
#include "MaglevModel_sfun.h"
#include "c1_MaglevModel.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "MaglevModel_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char *c1_debug_family_names[6] = { "nargin", "nargout", "t", "f",
  "A", "N" };

/* Function Declarations */
static void initialize_c1_MaglevModel(SFc1_MaglevModelInstanceStruct
  *chartInstance);
static void initialize_params_c1_MaglevModel(SFc1_MaglevModelInstanceStruct
  *chartInstance);
static void enable_c1_MaglevModel(SFc1_MaglevModelInstanceStruct *chartInstance);
static void disable_c1_MaglevModel(SFc1_MaglevModelInstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_MaglevModel
  (SFc1_MaglevModelInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_MaglevModel
  (SFc1_MaglevModelInstanceStruct *chartInstance);
static void set_sim_state_c1_MaglevModel(SFc1_MaglevModelInstanceStruct
  *chartInstance, const mxArray *c1_st);
static void finalize_c1_MaglevModel(SFc1_MaglevModelInstanceStruct
  *chartInstance);
static void sf_c1_MaglevModel(SFc1_MaglevModelInstanceStruct *chartInstance);
static void compInitSubchartSimstructsFcn_c1_MaglevModel
  (SFc1_MaglevModelInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static const mxArray *c1_sf_marshall(void *chartInstanceVoid, void *c1_u);
static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[15]);
static const mxArray *c1_b_sf_marshall(void *chartInstanceVoid, void *c1_u);
static real_T c1_emlrt_marshallIn(SFc1_MaglevModelInstanceStruct *chartInstance,
  const mxArray *c1_N, const char_T *c1_name);
static uint8_T c1_b_emlrt_marshallIn(SFc1_MaglevModelInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_MaglevModel, const char_T
  *c1_name);
static void init_dsm_address_info(SFc1_MaglevModelInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c1_MaglevModel(SFc1_MaglevModelInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_is_active_c1_MaglevModel = 0U;
}

static void initialize_params_c1_MaglevModel(SFc1_MaglevModelInstanceStruct
  *chartInstance)
{
}

static void enable_c1_MaglevModel(SFc1_MaglevModelInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_MaglevModel(SFc1_MaglevModelInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_MaglevModel
  (SFc1_MaglevModelInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c1_MaglevModel
  (SFc1_MaglevModelInstanceStruct *chartInstance)
{
  const mxArray *c1_st = NULL;
  const mxArray *c1_y = NULL;
  real_T c1_hoistedGlobal;
  real_T c1_u;
  const mxArray *c1_b_y = NULL;
  uint8_T c1_b_hoistedGlobal;
  uint8_T c1_b_u;
  const mxArray *c1_c_y = NULL;
  real_T *c1_N;
  c1_N = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(2));
  c1_hoistedGlobal = *c1_N;
  c1_u = c1_hoistedGlobal;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_b_hoistedGlobal = chartInstance->c1_is_active_c1_MaglevModel;
  c1_b_u = c1_b_hoistedGlobal;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c1_y, 1, c1_c_y);
  sf_mex_assign(&c1_st, c1_y);
  return c1_st;
}

static void set_sim_state_c1_MaglevModel(SFc1_MaglevModelInstanceStruct
  *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  real_T *c1_N;
  c1_N = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c1_doneDoubleBufferReInit = TRUE;
  c1_u = sf_mex_dup(c1_st);
  *c1_N = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 0)),
    "N");
  chartInstance->c1_is_active_c1_MaglevModel = c1_b_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 1)),
     "is_active_c1_MaglevModel");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_MaglevModel(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_MaglevModel(SFc1_MaglevModelInstanceStruct
  *chartInstance)
{
}

static void sf_c1_MaglevModel(SFc1_MaglevModelInstanceStruct *chartInstance)
{
  int32_T c1_previousEvent;
  real_T c1_hoistedGlobal;
  real_T c1_b_hoistedGlobal;
  real_T c1_c_hoistedGlobal;
  real_T c1_t;
  real_T c1_f;
  real_T c1_A;
  uint32_T c1_debug_family_var_map[6];
  real_T c1_nargin = 3.0;
  real_T c1_nargout = 1.0;
  real_T c1_N;
  real_T c1_b;
  real_T c1_y;
  real_T c1_a;
  real_T c1_b_b;
  real_T c1_b_y;
  real_T c1_x;
  real_T c1_b_x;
  real_T c1_c_x;
  real_T c1_b_a;
  real_T c1_c_b;
  real_T *c1_b_t;
  real_T *c1_b_N;
  real_T *c1_b_f;
  real_T *c1_b_A;
  c1_b_A = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c1_b_f = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_b_N = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_b_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0);
  _SFD_DATA_RANGE_CHECK(*c1_b_t, 0U);
  _SFD_DATA_RANGE_CHECK(*c1_b_N, 1U);
  _SFD_DATA_RANGE_CHECK(*c1_b_f, 2U);
  _SFD_DATA_RANGE_CHECK(*c1_b_A, 3U);
  c1_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0);
  c1_hoistedGlobal = *c1_b_t;
  c1_b_hoistedGlobal = *c1_b_f;
  c1_c_hoistedGlobal = *c1_b_A;
  c1_t = c1_hoistedGlobal;
  c1_f = c1_b_hoistedGlobal;
  c1_A = c1_c_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 6U, 6U, c1_debug_family_names,
    c1_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c1_nargin, c1_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c1_nargout, c1_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c1_t, c1_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c1_f, c1_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c1_A, c1_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(&c1_N, c1_sf_marshall, 5U);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0, 2);
  c1_b = c1_f;
  c1_y = 6.2831853071795862 * c1_b;
  c1_a = c1_y;
  c1_b_b = c1_t;
  c1_b_y = c1_a * c1_b_b;
  c1_x = c1_b_y;
  c1_b_x = c1_x;
  c1_c_x = c1_b_x;
  c1_b_x = c1_c_x;
  c1_b_x = muDoubleScalarSin(c1_b_x);
  c1_b_a = c1_A;
  c1_c_b = c1_b_x;
  c1_N = c1_b_a * c1_c_b;
  _SFD_EML_CALL(0, -2);
  sf_debug_symbol_scope_pop();
  *c1_b_N = c1_N;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0);
  _sfEvent_ = c1_previousEvent;
  sf_debug_check_for_state_inconsistency(_MaglevModelMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void compInitSubchartSimstructsFcn_c1_MaglevModel
  (SFc1_MaglevModelInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

static const mxArray *c1_sf_marshall(void *chartInstanceVoid, void *c1_u)
{
  const mxArray *c1_y = NULL;
  real_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  SFc1_MaglevModelInstanceStruct *chartInstance;
  chartInstance = (SFc1_MaglevModelInstanceStruct *)chartInstanceVoid;
  c1_y = NULL;
  c1_b_u = *((real_T *)c1_u);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

const mxArray *sf_c1_MaglevModel_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_ResolvedFunctionInfo c1_info[15];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i0;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_info_helper(c1_info);
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 15));
  for (c1_i0 = 0; c1_i0 < 15; c1_i0 = c1_i0 + 1) {
    c1_r0 = &c1_info[c1_i0];
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->context)), "context",
                    "nameCaptureInfo", c1_i0);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c1_r0->name)), "name",
                    "nameCaptureInfo", c1_i0);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c1_i0);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c1_i0);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c1_i0);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c1_i0);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c1_i0);
  }

  sf_mex_assign(&c1_nameCaptureInfo, c1_m0);
  return c1_nameCaptureInfo;
}

static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[15])
{
  c1_info[0].context = "";
  c1_info[0].name = "pi";
  c1_info[0].dominantType = "";
  c1_info[0].resolved = "[B]pi";
  c1_info[0].fileLength = 0U;
  c1_info[0].fileTime1 = 0U;
  c1_info[0].fileTime2 = 0U;
  c1_info[1].context = "";
  c1_info[1].name = "mtimes";
  c1_info[1].dominantType = "double";
  c1_info[1].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[1].fileLength = 3425U;
  c1_info[1].fileTime1 = 1251053472U;
  c1_info[1].fileTime2 = 0U;
  c1_info[2].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[2].name = "nargin";
  c1_info[2].dominantType = "";
  c1_info[2].resolved = "[B]nargin";
  c1_info[2].fileLength = 0U;
  c1_info[2].fileTime1 = 0U;
  c1_info[2].fileTime2 = 0U;
  c1_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[3].name = "gt";
  c1_info[3].dominantType = "double";
  c1_info[3].resolved = "[B]gt";
  c1_info[3].fileLength = 0U;
  c1_info[3].fileTime1 = 0U;
  c1_info[3].fileTime2 = 0U;
  c1_info[4].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[4].name = "isa";
  c1_info[4].dominantType = "double";
  c1_info[4].resolved = "[B]isa";
  c1_info[4].fileLength = 0U;
  c1_info[4].fileTime1 = 0U;
  c1_info[4].fileTime2 = 0U;
  c1_info[5].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[5].name = "isinteger";
  c1_info[5].dominantType = "double";
  c1_info[5].resolved = "[B]isinteger";
  c1_info[5].fileLength = 0U;
  c1_info[5].fileTime1 = 0U;
  c1_info[5].fileTime2 = 0U;
  c1_info[6].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[6].name = "isscalar";
  c1_info[6].dominantType = "double";
  c1_info[6].resolved = "[B]isscalar";
  c1_info[6].fileLength = 0U;
  c1_info[6].fileTime1 = 0U;
  c1_info[6].fileTime2 = 0U;
  c1_info[7].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[7].name = "strcmp";
  c1_info[7].dominantType = "char";
  c1_info[7].resolved = "[B]strcmp";
  c1_info[7].fileLength = 0U;
  c1_info[7].fileTime1 = 0U;
  c1_info[7].fileTime2 = 0U;
  c1_info[8].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[8].name = "size";
  c1_info[8].dominantType = "double";
  c1_info[8].resolved = "[B]size";
  c1_info[8].fileLength = 0U;
  c1_info[8].fileTime1 = 0U;
  c1_info[8].fileTime2 = 0U;
  c1_info[9].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[9].name = "eq";
  c1_info[9].dominantType = "double";
  c1_info[9].resolved = "[B]eq";
  c1_info[9].fileLength = 0U;
  c1_info[9].fileTime1 = 0U;
  c1_info[9].fileTime2 = 0U;
  c1_info[10].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[10].name = "class";
  c1_info[10].dominantType = "double";
  c1_info[10].resolved = "[B]class";
  c1_info[10].fileLength = 0U;
  c1_info[10].fileTime1 = 0U;
  c1_info[10].fileTime2 = 0U;
  c1_info[11].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[11].name = "not";
  c1_info[11].dominantType = "logical";
  c1_info[11].resolved = "[B]not";
  c1_info[11].fileLength = 0U;
  c1_info[11].fileTime1 = 0U;
  c1_info[11].fileTime2 = 0U;
  c1_info[12].context = "";
  c1_info[12].name = "sin";
  c1_info[12].dominantType = "double";
  c1_info[12].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c1_info[12].fileLength = 324U;
  c1_info[12].fileTime1 = 1203469642U;
  c1_info[12].fileTime2 = 0U;
  c1_info[13].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c1_info[13].name = "eml_scalar_sin";
  c1_info[13].dominantType = "double";
  c1_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c1_info[13].fileLength = 601U;
  c1_info[13].fileTime1 = 1209352390U;
  c1_info[13].fileTime2 = 0U;
  c1_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c1_info[14].name = "isreal";
  c1_info[14].dominantType = "double";
  c1_info[14].resolved = "[B]isreal";
  c1_info[14].fileLength = 0U;
  c1_info[14].fileTime1 = 0U;
  c1_info[14].fileTime2 = 0U;
}

static const mxArray *c1_b_sf_marshall(void *chartInstanceVoid, void *c1_u)
{
  const mxArray *c1_y = NULL;
  boolean_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  SFc1_MaglevModelInstanceStruct *chartInstance;
  chartInstance = (SFc1_MaglevModelInstanceStruct *)chartInstanceVoid;
  c1_y = NULL;
  c1_b_u = *((boolean_T *)c1_u);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static real_T c1_emlrt_marshallIn(SFc1_MaglevModelInstanceStruct *chartInstance,
  const mxArray *c1_N, const char_T *c1_name)
{
  real_T c1_y;
  real_T c1_d0;
  sf_mex_import(c1_name, sf_mex_dup(c1_N), &c1_d0, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d0;
  sf_mex_destroy(&c1_N);
  return c1_y;
}

static uint8_T c1_b_emlrt_marshallIn(SFc1_MaglevModelInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_MaglevModel,
  const char_T *c1_name)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_name, sf_mex_dup(c1_b_is_active_c1_MaglevModel), &c1_u0, 1, 3,
                0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_b_is_active_c1_MaglevModel);
  return c1_y;
}

static void init_dsm_address_info(SFc1_MaglevModelInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c1_MaglevModel_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1302804162U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2842702606U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2089941993U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4062657894U);
}

mxArray *sf_c1_MaglevModel_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(1703100965U);
    pr[1] = (double)(2191588917U);
    pr[2] = (double)(2862481156U);
    pr[3] = (double)(135262897U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  return(mxAutoinheritanceInfo);
}

static mxArray *sf_get_sim_state_info_c1_MaglevModel(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"N\",},{M[8],M[0],T\"is_active_c1_MaglevModel\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_MaglevModel_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_MaglevModelInstanceStruct *chartInstance;
    chartInstance = (SFc1_MaglevModelInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_MaglevModelMachineNumber_,
           1,
           1,
           1,
           4,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_MaglevModelMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_MaglevModelMachineNumber_,
            chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_MaglevModelMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"t");
          _SFD_SET_DATA_PROPS(1,2,0,1,"N");
          _SFD_SET_DATA_PROPS(2,1,1,0,"f");
          _SFD_SET_DATA_PROPS(3,1,1,0,"A");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of EML Model Coverage */
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,49);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshall);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshall);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshall);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshall);

        {
          real_T *c1_t;
          real_T *c1_N;
          real_T *c1_f;
          real_T *c1_A;
          c1_A = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c1_f = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c1_N = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c1_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c1_t);
          _SFD_SET_DATA_VALUE_PTR(1U, c1_N);
          _SFD_SET_DATA_VALUE_PTR(2U, c1_f);
          _SFD_SET_DATA_VALUE_PTR(3U, c1_A);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_MaglevModelMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c1_MaglevModel(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_MaglevModelInstanceStruct*) chartInstanceVar)
    ->S,0);
  initialize_params_c1_MaglevModel((SFc1_MaglevModelInstanceStruct*)
    chartInstanceVar);
  initialize_c1_MaglevModel((SFc1_MaglevModelInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_MaglevModel(void *chartInstanceVar)
{
  enable_c1_MaglevModel((SFc1_MaglevModelInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_MaglevModel(void *chartInstanceVar)
{
  disable_c1_MaglevModel((SFc1_MaglevModelInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_MaglevModel(void *chartInstanceVar)
{
  sf_c1_MaglevModel((SFc1_MaglevModelInstanceStruct*) chartInstanceVar);
}

static mxArray* sf_internal_get_sim_state_c1_MaglevModel(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_MaglevModel
    ((SFc1_MaglevModelInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = sf_get_sim_state_info_c1_MaglevModel();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

static void sf_internal_set_sim_state_c1_MaglevModel(SimStruct* S, const mxArray
  *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_MaglevModel();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_MaglevModel((SFc1_MaglevModelInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static mxArray* sf_opaque_get_sim_state_c1_MaglevModel(SimStruct* S)
{
  return sf_internal_get_sim_state_c1_MaglevModel(S);
}

static void sf_opaque_set_sim_state_c1_MaglevModel(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c1_MaglevModel(S, st);
}

static void sf_opaque_terminate_c1_MaglevModel(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_MaglevModelInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c1_MaglevModel((SFc1_MaglevModelInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  compInitSubchartSimstructsFcn_c1_MaglevModel((SFc1_MaglevModelInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_MaglevModel(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_MaglevModel((SFc1_MaglevModelInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_MaglevModel(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"MaglevModel","MaglevModel",1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"MaglevModel","MaglevModel",1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"MaglevModel",
      "MaglevModel",1,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"MaglevModel","MaglevModel",1,3);
      sf_mark_chart_reusable_outputs(S,"MaglevModel","MaglevModel",1,1);
    }

    sf_set_rtw_dwork_info(S,"MaglevModel","MaglevModel",1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2074398739U));
  ssSetChecksum1(S,(965557171U));
  ssSetChecksum2(S,(2293078826U));
  ssSetChecksum3(S,(598775794U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c1_MaglevModel(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "MaglevModel", "MaglevModel",1);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_MaglevModel(SimStruct *S)
{
  SFc1_MaglevModelInstanceStruct *chartInstance;
  chartInstance = (SFc1_MaglevModelInstanceStruct *)malloc(sizeof
    (SFc1_MaglevModelInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_MaglevModelInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c1_MaglevModel;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c1_MaglevModel;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c1_MaglevModel;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_MaglevModel;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_MaglevModel;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c1_MaglevModel;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c1_MaglevModel;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_MaglevModel;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_MaglevModel;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_MaglevModel;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c1_MaglevModel;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c1_MaglevModel_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_MaglevModel(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_MaglevModel(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_MaglevModel(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_MaglevModel_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
