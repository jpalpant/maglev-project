/* Include files */

#include "blascompat32.h"
#include "FinalSimulink_sfun.h"
#include "c2_FinalSimulink.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "FinalSimulink_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char *c2_debug_family_names[5] = { "nargin", "nargout", "t", "n",
  "ni" };

/* Function Declarations */
static void initialize_c2_FinalSimulink(SFc2_FinalSimulinkInstanceStruct
  *chartInstance);
static void initialize_params_c2_FinalSimulink(SFc2_FinalSimulinkInstanceStruct *
  chartInstance);
static void enable_c2_FinalSimulink(SFc2_FinalSimulinkInstanceStruct
  *chartInstance);
static void disable_c2_FinalSimulink(SFc2_FinalSimulinkInstanceStruct
  *chartInstance);
static void c2_update_debugger_state_c2_FinalSimulink
  (SFc2_FinalSimulinkInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_FinalSimulink
  (SFc2_FinalSimulinkInstanceStruct *chartInstance);
static void set_sim_state_c2_FinalSimulink(SFc2_FinalSimulinkInstanceStruct
  *chartInstance, const mxArray *c2_st);
static void finalize_c2_FinalSimulink(SFc2_FinalSimulinkInstanceStruct
  *chartInstance);
static void sf_c2_FinalSimulink(SFc2_FinalSimulinkInstanceStruct *chartInstance);
static void compInitSubchartSimstructsFcn_c2_FinalSimulink
  (SFc2_FinalSimulinkInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static void c2_eml_scalar_eg(SFc2_FinalSimulinkInstanceStruct *chartInstance);
static real_T c2_rand(SFc2_FinalSimulinkInstanceStruct *chartInstance);
static void c2_eml_rand_mt19937ar(SFc2_FinalSimulinkInstanceStruct
  *chartInstance, uint32_T c2_state[625]);
static void c2_b_eml_rand_mt19937ar(SFc2_FinalSimulinkInstanceStruct
  *chartInstance, uint32_T c2_state[625], uint32_T c2_b_state[625], real_T *c2_r);
static const mxArray *c2_sf_marshall(void *chartInstanceVoid, void *c2_u);
static const mxArray *c2_b_sf_marshall(void *chartInstanceVoid, void *c2_u);
static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[51]);
static const mxArray *c2_c_sf_marshall(void *chartInstanceVoid, void *c2_u);
static real_T c2_emlrt_marshallIn(SFc2_FinalSimulinkInstanceStruct
  *chartInstance, const mxArray *c2_n, const char_T *c2_name);
static uint8_T c2_b_emlrt_marshallIn(SFc2_FinalSimulinkInstanceStruct
  *chartInstance, const mxArray *c2_b_method, const char_T *c2_name);
static real_T c2_c_emlrt_marshallIn(SFc2_FinalSimulinkInstanceStruct
  *chartInstance, const mxArray *c2_b_ni, const char_T *c2_name);
static void c2_d_emlrt_marshallIn(SFc2_FinalSimulinkInstanceStruct
  *chartInstance, const mxArray *c2_b_twister_state, const char_T *c2_name,
  uint32_T c2_y[625]);
static uint32_T c2_e_emlrt_marshallIn(SFc2_FinalSimulinkInstanceStruct
  *chartInstance, const mxArray *c2_b_v4_state, const char_T *c2_name);
static uint8_T c2_f_emlrt_marshallIn(SFc2_FinalSimulinkInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_FinalSimulink, const char_T
  *c2_name);
static void init_dsm_address_info(SFc2_FinalSimulinkInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c2_FinalSimulink(SFc2_FinalSimulinkInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_ni_not_empty = FALSE;
  chartInstance->c2_method_not_empty = FALSE;
  chartInstance->c2_v4_state_not_empty = FALSE;
  chartInstance->c2_twister_state_not_empty = FALSE;
  chartInstance->c2_is_active_c2_FinalSimulink = 0U;
}

static void initialize_params_c2_FinalSimulink(SFc2_FinalSimulinkInstanceStruct *
  chartInstance)
{
}

static void enable_c2_FinalSimulink(SFc2_FinalSimulinkInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_FinalSimulink(SFc2_FinalSimulinkInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_FinalSimulink
  (SFc2_FinalSimulinkInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c2_FinalSimulink
  (SFc2_FinalSimulinkInstanceStruct *chartInstance)
{
  const mxArray *c2_st = NULL;
  const mxArray *c2_y = NULL;
  real_T c2_hoistedGlobal;
  real_T c2_u;
  const mxArray *c2_b_y = NULL;
  uint8_T c2_b_hoistedGlobal;
  uint8_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  real_T c2_c_hoistedGlobal;
  real_T c2_c_u;
  const mxArray *c2_d_y = NULL;
  int32_T c2_i0;
  uint32_T c2_d_hoistedGlobal[625];
  int32_T c2_i1;
  uint32_T c2_d_u[625];
  const mxArray *c2_e_y = NULL;
  uint32_T c2_e_hoistedGlobal;
  uint32_T c2_e_u;
  const mxArray *c2_f_y = NULL;
  uint8_T c2_f_hoistedGlobal;
  uint8_T c2_f_u;
  const mxArray *c2_g_y = NULL;
  real_T *c2_n;
  c2_n = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(6));
  c2_hoistedGlobal = *c2_n;
  c2_u = c2_hoistedGlobal;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_b_hoistedGlobal = chartInstance->c2_method;
  c2_b_u = c2_b_hoistedGlobal;
  c2_c_y = NULL;
  if (!chartInstance->c2_method_not_empty) {
    sf_mex_assign(&c2_c_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0));
  } else {
    sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 3, 0U, 0U, 0U, 0));
  }

  sf_mex_setcell(c2_y, 1, c2_c_y);
  c2_c_hoistedGlobal = chartInstance->c2_ni;
  c2_c_u = c2_c_hoistedGlobal;
  c2_d_y = NULL;
  if (!chartInstance->c2_ni_not_empty) {
    sf_mex_assign(&c2_d_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0));
  } else {
    sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_c_u, 0, 0U, 0U, 0U, 0));
  }

  sf_mex_setcell(c2_y, 2, c2_d_y);
  for (c2_i0 = 0; c2_i0 < 625; c2_i0 = c2_i0 + 1) {
    c2_d_hoistedGlobal[c2_i0] = chartInstance->c2_twister_state[c2_i0];
  }

  for (c2_i1 = 0; c2_i1 < 625; c2_i1 = c2_i1 + 1) {
    c2_d_u[c2_i1] = c2_d_hoistedGlobal[c2_i1];
  }

  c2_e_y = NULL;
  if (!chartInstance->c2_twister_state_not_empty) {
    sf_mex_assign(&c2_e_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0));
  } else {
    sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_d_u, 7, 0U, 1U, 0U, 1, 625));
  }

  sf_mex_setcell(c2_y, 3, c2_e_y);
  c2_e_hoistedGlobal = chartInstance->c2_v4_state;
  c2_e_u = c2_e_hoistedGlobal;
  c2_f_y = NULL;
  if (!chartInstance->c2_v4_state_not_empty) {
    sf_mex_assign(&c2_f_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0));
  } else {
    sf_mex_assign(&c2_f_y, sf_mex_create("y", &c2_e_u, 7, 0U, 0U, 0U, 0));
  }

  sf_mex_setcell(c2_y, 4, c2_f_y);
  c2_f_hoistedGlobal = chartInstance->c2_is_active_c2_FinalSimulink;
  c2_f_u = c2_f_hoistedGlobal;
  c2_g_y = NULL;
  sf_mex_assign(&c2_g_y, sf_mex_create("y", &c2_f_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 5, c2_g_y);
  sf_mex_assign(&c2_st, c2_y);
  return c2_st;
}

static void set_sim_state_c2_FinalSimulink(SFc2_FinalSimulinkInstanceStruct
  *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_u;
  uint32_T c2_uv0[625];
  int32_T c2_i2;
  real_T *c2_n;
  c2_n = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  *c2_n = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)),
    "n");
  chartInstance->c2_method = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 1)), "method");
  chartInstance->c2_ni = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 2)), "ni");
  c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 3)),
                        "twister_state", c2_uv0);
  for (c2_i2 = 0; c2_i2 < 625; c2_i2 = c2_i2 + 1) {
    chartInstance->c2_twister_state[c2_i2] = c2_uv0[c2_i2];
  }

  chartInstance->c2_v4_state = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 4)), "v4_state");
  chartInstance->c2_is_active_c2_FinalSimulink = c2_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 5)),
     "is_active_c2_FinalSimulink");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_FinalSimulink(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_FinalSimulink(SFc2_FinalSimulinkInstanceStruct
  *chartInstance)
{
}

static void sf_c2_FinalSimulink(SFc2_FinalSimulinkInstanceStruct *chartInstance)
{
  int32_T c2_previousEvent;
  real_T c2_hoistedGlobal;
  real_T c2_t;
  uint32_T c2_debug_family_var_map[5];
  real_T c2_nargin = 1.0;
  real_T c2_nargout = 1.0;
  real_T c2_n;
  real_T c2_x;
  real_T c2_xk;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_d_x;
  real_T c2_r;
  real_T c2_a;
  real_T c2_y;
  real_T c2_b_a;
  real_T c2_b_y;
  real_T *c2_b_t;
  real_T *c2_b_n;
  c2_b_n = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_b_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1);
  _SFD_DATA_RANGE_CHECK(*c2_b_t, 0U);
  _SFD_DATA_RANGE_CHECK(*c2_b_n, 1U);
  c2_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1);
  c2_hoistedGlobal = *c2_b_t;
  c2_t = c2_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 5U, 5U, c2_debug_family_names,
    c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c2_nargin, c2_b_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c2_nargout, c2_b_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c2_t, c2_b_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c2_n, c2_b_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&chartInstance->c2_ni, c2_sf_marshall, 4U);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0, 4);
  if (CV_EML_IF(0, 0, !chartInstance->c2_ni_not_empty)) {
    _SFD_EML_CALL(0, 5);
    chartInstance->c2_ni = 0.0;
    chartInstance->c2_ni_not_empty = TRUE;
  }

  _SFD_EML_CALL(0, 8);
  c2_x = c2_t;
  c2_eml_scalar_eg(chartInstance);
  c2_xk = c2_x;
  c2_b_x = c2_xk;
  c2_eml_scalar_eg(chartInstance);
  c2_c_x = c2_b_x;
  c2_d_x = c2_c_x;
  c2_d_x = muDoubleScalarFloor(c2_d_x);
  c2_r = c2_b_x - c2_d_x;
  if (CV_EML_IF(0, 1, c2_r == 0.0)) {
    _SFD_EML_CALL(0, 9);
    c2_a = c2_rand(chartInstance);
    c2_y = c2_a * 0.05;
    c2_b_a = c2_rand(chartInstance);
    c2_b_y = c2_b_a * 0.05;
    chartInstance->c2_ni = c2_y - c2_b_y;
  } else {
    _SFD_EML_CALL(0, 11);
  }

  _SFD_EML_CALL(0, 14);
  c2_n = chartInstance->c2_ni;
  _SFD_EML_CALL(0, -14);
  sf_debug_symbol_scope_pop();
  *c2_b_n = c2_n;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1);
  _sfEvent_ = c2_previousEvent;
  sf_debug_check_for_state_inconsistency(_FinalSimulinkMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void compInitSubchartSimstructsFcn_c2_FinalSimulink
  (SFc2_FinalSimulinkInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static void c2_eml_scalar_eg(SFc2_FinalSimulinkInstanceStruct *chartInstance)
{
}

static real_T c2_rand(SFc2_FinalSimulinkInstanceStruct *chartInstance)
{
  uint32_T c2_uv1[625];
  int32_T c2_i3;
  int32_T c2_i4;
  uint32_T c2_uv2[625];
  real_T c2_d0;
  uint32_T c2_b_twister_state[625];
  int32_T c2_i5;
  uint32_T c2_hoistedGlobal;
  uint32_T c2_state;
  uint32_T c2_b_v4_state;
  uint32_T c2_s;
  uint32_T c2_u0;
  uint32_T c2_hi;
  uint32_T c2_lo;
  uint32_T c2_test1;
  uint32_T c2_test2;
  uint32_T c2_b_state;
  real_T c2_a;
  real_T c2_b_r;
  real_T c2_d1;
  if (!chartInstance->c2_method_not_empty) {
    chartInstance->c2_method = 2U;
    chartInstance->c2_method_not_empty = TRUE;
  }

  if (chartInstance->c2_method == 2) {
    if (!chartInstance->c2_twister_state_not_empty) {
      c2_eml_rand_mt19937ar(chartInstance, c2_uv1);
      for (c2_i3 = 0; c2_i3 < 625; c2_i3 = c2_i3 + 1) {
        chartInstance->c2_twister_state[c2_i3] = c2_uv1[c2_i3];
      }

      chartInstance->c2_twister_state_not_empty = TRUE;
    }

    for (c2_i4 = 0; c2_i4 < 625; c2_i4 = c2_i4 + 1) {
      c2_uv2[c2_i4] = chartInstance->c2_twister_state[c2_i4];
    }

    c2_b_eml_rand_mt19937ar(chartInstance, c2_uv2, c2_b_twister_state, &c2_d0);
    for (c2_i5 = 0; c2_i5 < 625; c2_i5 = c2_i5 + 1) {
      chartInstance->c2_twister_state[c2_i5] = c2_b_twister_state[c2_i5];
    }

    return c2_d0;
  } else {
    if (!chartInstance->c2_v4_state_not_empty) {
      chartInstance->c2_v4_state = 1144108930U;
      chartInstance->c2_v4_state_not_empty = TRUE;
    }

    c2_hoistedGlobal = chartInstance->c2_v4_state;
    c2_state = c2_hoistedGlobal;
    c2_b_v4_state = c2_state;
    c2_s = c2_b_v4_state;
    c2_u0 = 127773U;
    c2_hi = c2_u0 == (uint32_T)0 ? MAX_uint32_T : c2_s / c2_u0;
    c2_lo = c2_s - c2_hi * 127773U;
    c2_test1 = 16807U * c2_lo;
    c2_test2 = 2836U * c2_hi;
    if (c2_test1 < c2_test2) {
      c2_b_state = (2147483647U - c2_test2) + c2_test1;
    } else {
      c2_b_state = c2_test1 - c2_test2;
    }

    c2_a = (real_T)c2_b_state;
    c2_b_r = c2_a * 4.6566128752457969E-10;
    c2_b_v4_state = c2_b_state;
    c2_d1 = c2_b_r;
    chartInstance->c2_v4_state = c2_b_v4_state;
    return c2_d1;
  }
}

static void c2_eml_rand_mt19937ar(SFc2_FinalSimulinkInstanceStruct
  *chartInstance, uint32_T c2_state[625])
{
  int32_T c2_i6;
  uint32_T c2_r;
  real_T c2_mti;
  real_T c2_b_mti;
  real_T c2_d2;
  real_T c2_d3;
  real_T c2_d4;
  uint32_T c2_u1;
  for (c2_i6 = 0; c2_i6 < 625; c2_i6 = c2_i6 + 1) {
    c2_state[c2_i6] = 0U;
  }

  c2_r = 5489U;
  c2_state[0] = 5489U;
  for (c2_mti = 2.0; c2_mti <= 624.0; c2_mti = c2_mti + 1.0) {
    c2_b_mti = c2_mti;
    c2_d2 = c2_b_mti - 1.0;
    c2_d3 = c2_d2;
    c2_d3 = c2_d3 < 0.0 ? muDoubleScalarCeil(c2_d3 - 0.5) : muDoubleScalarFloor
      (c2_d3 + 0.5);
    c2_d4 = c2_d3;
    if (c2_d4 < 4.294967296E+9) {
      if (c2_d4 >= 0.0) {
        c2_u1 = (uint32_T)c2_d4;
      } else {
        c2_u1 = 0U;
      }
    } else if (c2_d4 >= 4.294967296E+9) {
      c2_u1 = MAX_uint32_T;
    } else {
      c2_u1 = 0U;
    }

    c2_r = (c2_r ^ c2_r >> 30U) * 1812433253U + c2_u1;
    c2_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c2_b_mti), 1, 625, 1, 0) - 1] = c2_r;
  }

  c2_state[624] = 624U;
}

static void c2_b_eml_rand_mt19937ar(SFc2_FinalSimulinkInstanceStruct
  *chartInstance, uint32_T c2_state[625], uint32_T c2_b_state[625
  ], real_T *c2_r)
{
  int32_T c2_i7;
  int32_T c2_i8;
  uint32_T c2_mt[625];
  int32_T c2_i9;
  uint32_T c2_c_state[625];
  int32_T c2_i10;
  uint32_T c2_b_mt[625];
  int32_T c2_i11;
  uint32_T c2_c_mt[625];
  int32_T c2_i12;
  uint32_T c2_u[2];
  real_T c2_j;
  real_T c2_b_j;
  uint32_T c2_mti;
  real_T c2_kk;
  real_T c2_b_kk;
  uint32_T c2_y;
  uint32_T c2_b_y;
  uint32_T c2_c_y;
  real_T c2_c_kk;
  uint32_T c2_d_y;
  uint32_T c2_e_y;
  uint32_T c2_f_y;
  uint32_T c2_g_y;
  int32_T c2_i13;
  int32_T c2_i14;
  uint32_T c2_b_u[2];
  real_T c2_a;
  real_T c2_h_y;
  real_T c2_b;
  real_T c2_b_r;
  int32_T c2_i15;
  for (c2_i7 = 0; c2_i7 < 625; c2_i7 = c2_i7 + 1) {
    c2_b_state[c2_i7] = c2_state[c2_i7];
  }

  for (c2_i8 = 0; c2_i8 < 625; c2_i8 = c2_i8 + 1) {
    c2_mt[c2_i8] = c2_b_state[c2_i8];
  }

  for (c2_i9 = 0; c2_i9 < 625; c2_i9 = c2_i9 + 1) {
    c2_c_state[c2_i9] = c2_mt[c2_i9];
  }

  /* <LEGAL>   This is a uniform (0,1) pseudorandom number generator based on: */
  /* <LEGAL> */
  /* <LEGAL>    A C-program for MT19937, with initialization improved 2002/1/26. */
  /* <LEGAL>    Coded by Takuji Nishimura and Makoto Matsumoto. */
  /* <LEGAL> */
  /* <LEGAL>    Copyright (C) 1997 - 2002, Makoto Matsumoto and Takuji Nishimura, */
  /* <LEGAL>    All rights reserved. */
  /* <LEGAL> */
  /* <LEGAL>    Redistribution and use in source and binary forms, with or without */
  /* <LEGAL>    modification, are permitted provided that the following conditions */
  /* <LEGAL>    are met: */
  /* <LEGAL> */
  /* <LEGAL>      1. Redistributions of source code must retain the above copyright */
  /* <LEGAL>         notice, this list of conditions and the following disclaimer. */
  /* <LEGAL> */
  /* <LEGAL>      2. Redistributions in binary form must reproduce the above copyright */
  /* <LEGAL>         notice, this list of conditions and the following disclaimer in the */
  /* <LEGAL>         documentation and/or other materials provided with the distribution. */
  /* <LEGAL> */
  /* <LEGAL>      3. The names of its contributors may not be used to endorse or promote */
  /* <LEGAL>         products derived from this software without specific prior written */
  /* <LEGAL>         permission. */
  /* <LEGAL> */
  /* <LEGAL>    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS */
  /* <LEGAL>    "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT */
  /* <LEGAL>    LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR */
  /* <LEGAL>    A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR */
  /* <LEGAL>    CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, */
  /* <LEGAL>    EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, */
  /* <LEGAL>    PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR */
  /* <LEGAL>    PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF */
  /* <LEGAL>    LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING */
  /* <LEGAL>    NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS */
  /* <LEGAL>    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. */
  do {
    for (c2_i10 = 0; c2_i10 < 625; c2_i10 = c2_i10 + 1) {
      c2_b_mt[c2_i10] = c2_c_state[c2_i10];
    }

    for (c2_i11 = 0; c2_i11 < 625; c2_i11 = c2_i11 + 1) {
      c2_c_mt[c2_i11] = c2_b_mt[c2_i11];
    }

    for (c2_i12 = 0; c2_i12 < 2; c2_i12 = c2_i12 + 1) {
      c2_u[c2_i12] = 0U;
    }

    for (c2_j = 1.0; c2_j <= 2.0; c2_j = c2_j + 1.0) {
      c2_b_j = c2_j;
      c2_mti = c2_c_mt[624] + 1U;
      if ((real_T)c2_mti >= 625.0) {
        for (c2_kk = 1.0; c2_kk <= 227.0; c2_kk = c2_kk + 1.0) {
          c2_b_kk = c2_kk;
          c2_y = (c2_c_mt[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                   _SFD_INTEGER_CHECK("", c2_b_kk), 1, 625, 1, 0) - 1] &
                  2147483648U) | (
            c2_c_mt[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
            "", c2_b_kk + 1.0), 1, 625, 1, 0) - 1] & 2147483647U);
          c2_b_y = c2_y;
          c2_c_y = c2_b_y;
          if ((real_T)(c2_c_y & 1U) == 0.0) {
            c2_c_y = c2_c_y >> 1U;
          } else {
            c2_c_y = c2_c_y >> 1U ^ 2567483615U;
          }

          c2_c_mt[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            c2_b_kk), 1, 625, 1, 0) - 1] = c2_c_mt[
            _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            c2_b_kk + 397.0), 1, 625, 1, 0) - 1] ^ c2_c_y;
        }

        for (c2_c_kk = 228.0; c2_c_kk <= 623.0; c2_c_kk = c2_c_kk + 1.0) {
          c2_b_kk = c2_c_kk;
          c2_y = (c2_c_mt[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                   _SFD_INTEGER_CHECK("", c2_b_kk), 1, 625, 1, 0) - 1] &
                  2147483648U) | (
            c2_c_mt[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
            "", c2_b_kk + 1.0), 1, 625, 1, 0) - 1] & 2147483647U);
          c2_d_y = c2_y;
          c2_e_y = c2_d_y;
          if ((real_T)(c2_e_y & 1U) == 0.0) {
            c2_e_y = c2_e_y >> 1U;
          } else {
            c2_e_y = c2_e_y >> 1U ^ 2567483615U;
          }

          c2_c_mt[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            c2_b_kk), 1, 625, 1, 0) - 1] = c2_c_mt[
            _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (c2_b_kk + 1.0) - 228.0), 1, 625, 1, 0) - 1] ^ c2_e_y;
        }

        c2_y = (c2_c_mt[623] & 2147483648U) | (c2_c_mt[0] & 2147483647U);
        c2_f_y = c2_y;
        c2_g_y = c2_f_y;
        if ((real_T)(c2_g_y & 1U) == 0.0) {
          c2_g_y = c2_g_y >> 1U;
        } else {
          c2_g_y = c2_g_y >> 1U ^ 2567483615U;
        }

        c2_c_mt[623] = c2_c_mt[396] ^ c2_g_y;
        c2_mti = 1U;
      }

      c2_y = c2_c_mt[(int32_T)(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        (uint32_T)_SFD_INTEGER_CHECK("", (real_T)c2_mti), 1, 625
        , 1, 0) - 1];
      c2_c_mt[624] = c2_mti;
      c2_y = c2_y ^ c2_y >> 11U;
      c2_y = c2_y ^ (c2_y << 7U & 2636928640U);
      c2_y = c2_y ^ (c2_y << 15U & 4022730752U);
      c2_y = c2_y ^ c2_y >> 18U;
      c2_u[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        c2_b_j), 1, 2, 1, 0) - 1] = c2_y;
    }

    for (c2_i13 = 0; c2_i13 < 625; c2_i13 = c2_i13 + 1) {
      c2_c_state[c2_i13] = c2_c_mt[c2_i13];
    }

    for (c2_i14 = 0; c2_i14 < 2; c2_i14 = c2_i14 + 1) {
      c2_b_u[c2_i14] = c2_u[c2_i14];
    }

    c2_b_u[0] = c2_b_u[0] >> 5U;
    c2_b_u[1] = c2_b_u[1] >> 6U;
    c2_a = (real_T)c2_b_u[0];
    c2_h_y = c2_a * 6.7108864E+7;
    c2_b = c2_h_y + (real_T)c2_b_u[1];
    c2_b_r = 1.1102230246251565E-16 * c2_b;
  } while (!(c2_b_r != 0.0));

  for (c2_i15 = 0; c2_i15 < 625; c2_i15 = c2_i15 + 1) {
    c2_b_state[c2_i15] = c2_c_state[c2_i15];
  }

  *c2_r = c2_b_r;
}

static const mxArray *c2_sf_marshall(void *chartInstanceVoid, void *c2_u)
{
  const mxArray *c2_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  SFc2_FinalSimulinkInstanceStruct *chartInstance;
  chartInstance = (SFc2_FinalSimulinkInstanceStruct *)chartInstanceVoid;
  c2_y = NULL;
  c2_b_u = *((real_T *)c2_u);
  c2_b_y = NULL;
  if (!chartInstance->c2_ni_not_empty) {
    sf_mex_assign(&c2_b_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0));
  } else {
    sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0));
  }

  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_b_sf_marshall(void *chartInstanceVoid, void *c2_u)
{
  const mxArray *c2_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  SFc2_FinalSimulinkInstanceStruct *chartInstance;
  chartInstance = (SFc2_FinalSimulinkInstanceStruct *)chartInstanceVoid;
  c2_y = NULL;
  c2_b_u = *((real_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

const mxArray *sf_c2_FinalSimulink_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_ResolvedFunctionInfo c2_info[51];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i16;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_info_helper(c2_info);
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 51));
  for (c2_i16 = 0; c2_i16 < 51; c2_i16 = c2_i16 + 1) {
    c2_r0 = &c2_info[c2_i16];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context",
                    "nameCaptureInfo", c2_i16);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name",
                    "nameCaptureInfo", c2_i16);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c2_i16);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c2_i16);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c2_i16);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c2_i16
                    );
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c2_i16
                    );
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[51])
{
  c2_info[0].context = "";
  c2_info[0].name = "mod";
  c2_info[0].dominantType = "double";
  c2_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m";
  c2_info[0].fileLength = 960U;
  c2_info[0].fileTime1 = 1228115388U;
  c2_info[0].fileTime2 = 0U;
  c2_info[1].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m";
  c2_info[1].name = "nargin";
  c2_info[1].dominantType = "";
  c2_info[1].resolved = "[B]nargin";
  c2_info[1].fileLength = 0U;
  c2_info[1].fileTime1 = 0U;
  c2_info[1].fileTime2 = 0U;
  c2_info[2].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m";
  c2_info[2].name = "gt";
  c2_info[2].dominantType = "double";
  c2_info[2].resolved = "[B]gt";
  c2_info[2].fileLength = 0U;
  c2_info[2].fileTime1 = 0U;
  c2_info[2].fileTime2 = 0U;
  c2_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m";
  c2_info[3].name = "isreal";
  c2_info[3].dominantType = "double";
  c2_info[3].resolved = "[B]isreal";
  c2_info[3].fileLength = 0U;
  c2_info[3].fileTime1 = 0U;
  c2_info[3].fileTime2 = 0U;
  c2_info[4].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m";
  c2_info[4].name = "isa";
  c2_info[4].dominantType = "double";
  c2_info[4].resolved = "[B]isa";
  c2_info[4].fileLength = 0U;
  c2_info[4].fileTime1 = 0U;
  c2_info[4].fileTime2 = 0U;
  c2_info[5].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m";
  c2_info[5].name = "class";
  c2_info[5].dominantType = "double";
  c2_info[5].resolved = "[B]class";
  c2_info[5].fileLength = 0U;
  c2_info[5].fileTime1 = 0U;
  c2_info[5].fileTime2 = 0U;
  c2_info[6].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m";
  c2_info[6].name = "eml_scalar_eg";
  c2_info[6].dominantType = "double";
  c2_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[6].fileLength = 3068U;
  c2_info[6].fileTime1 = 1240283610U;
  c2_info[6].fileTime2 = 0U;
  c2_info[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m!any_enums";
  c2_info[7].name = "false";
  c2_info[7].dominantType = "";
  c2_info[7].resolved = "[B]false";
  c2_info[7].fileLength = 0U;
  c2_info[7].fileTime1 = 0U;
  c2_info[7].fileTime2 = 0U;
  c2_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[8].name = "isstruct";
  c2_info[8].dominantType = "double";
  c2_info[8].resolved = "[B]isstruct";
  c2_info[8].fileLength = 0U;
  c2_info[8].fileTime1 = 0U;
  c2_info[8].fileTime2 = 0U;
  c2_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m!zerosum";
  c2_info[9].name = "eq";
  c2_info[9].dominantType = "double";
  c2_info[9].resolved = "[B]eq";
  c2_info[9].fileLength = 0U;
  c2_info[9].fileTime1 = 0U;
  c2_info[9].fileTime2 = 0U;
  c2_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m!zerosum";
  c2_info[10].name = "cast";
  c2_info[10].dominantType = "double";
  c2_info[10].resolved = "[B]cast";
  c2_info[10].fileLength = 0U;
  c2_info[10].fileTime1 = 0U;
  c2_info[10].fileTime2 = 0U;
  c2_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m!zerosum";
  c2_info[11].name = "plus";
  c2_info[11].dominantType = "double";
  c2_info[11].resolved = "[B]plus";
  c2_info[11].fileLength = 0U;
  c2_info[11].fileTime1 = 0U;
  c2_info[11].fileTime2 = 0U;
  c2_info[12].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m";
  c2_info[12].name = "eml_scalexp_alloc";
  c2_info[12].dominantType = "double";
  c2_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c2_info[12].fileLength = 932U;
  c2_info[12].fileTime1 = 1261973470U;
  c2_info[12].fileTime2 = 0U;
  c2_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c2_info[13].name = "minus";
  c2_info[13].dominantType = "double";
  c2_info[13].resolved = "[B]minus";
  c2_info[13].fileLength = 0U;
  c2_info[13].fileTime1 = 0U;
  c2_info[13].fileTime2 = 0U;
  c2_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c2_info[14].name = "isscalar";
  c2_info[14].dominantType = "double";
  c2_info[14].resolved = "[B]isscalar";
  c2_info[14].fileLength = 0U;
  c2_info[14].fileTime1 = 0U;
  c2_info[14].fileTime2 = 0U;
  c2_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c2_info[15].name = "not";
  c2_info[15].dominantType = "logical";
  c2_info[15].resolved = "[B]not";
  c2_info[15].fileLength = 0U;
  c2_info[15].fileTime1 = 0U;
  c2_info[15].fileTime2 = 0U;
  c2_info[16].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m";
  c2_info[16].name = "eml_scalar_mod";
  c2_info[16].dominantType = "double";
  c2_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_mod.m";
  c2_info[16].fileLength = 1103U;
  c2_info[16].fileTime1 = 1228115384U;
  c2_info[16].fileTime2 = 0U;
  c2_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_mod.m";
  c2_info[17].name = "isinteger";
  c2_info[17].dominantType = "double";
  c2_info[17].resolved = "[B]isinteger";
  c2_info[17].fileLength = 0U;
  c2_info[17].fileTime1 = 0U;
  c2_info[17].fileTime2 = 0U;
  c2_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_mod.m";
  c2_info[18].name = "eml_scalar_floor";
  c2_info[18].dominantType = "double";
  c2_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c2_info[18].fileLength = 260U;
  c2_info[18].fileTime1 = 1209352390U;
  c2_info[18].fileTime2 = 0U;
  c2_info[19].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_mod.m";
  c2_info[19].name = "times";
  c2_info[19].dominantType = "double";
  c2_info[19].resolved = "[B]times";
  c2_info[19].fileLength = 0U;
  c2_info[19].fileTime1 = 0U;
  c2_info[19].fileTime2 = 0U;
  c2_info[20].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_mod.m";
  c2_info[20].name = "eml_scalar_round";
  c2_info[20].dominantType = "double";
  c2_info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m";
  c2_info[20].fileLength = 523U;
  c2_info[20].fileTime1 = 1203469608U;
  c2_info[20].fileTime2 = 0U;
  c2_info[21].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m";
  c2_info[21].name = "isfloat";
  c2_info[21].dominantType = "double";
  c2_info[21].resolved = "[B]isfloat";
  c2_info[21].fileLength = 0U;
  c2_info[21].fileTime1 = 0U;
  c2_info[21].fileTime2 = 0U;
  c2_info[22].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m!scalar_round";
  c2_info[22].name = "lt";
  c2_info[22].dominantType = "double";
  c2_info[22].resolved = "[B]lt";
  c2_info[22].fileLength = 0U;
  c2_info[22].fileTime1 = 0U;
  c2_info[22].fileTime2 = 0U;
  c2_info[23].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_mod.m";
  c2_info[23].name = "eml_scalar_abs";
  c2_info[23].dominantType = "double";
  c2_info[23].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c2_info[23].fileLength = 461U;
  c2_info[23].fileTime1 = 1203469560U;
  c2_info[23].fileTime2 = 0U;
  c2_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c2_info[24].name = "ischar";
  c2_info[24].dominantType = "double";
  c2_info[24].resolved = "[B]ischar";
  c2_info[24].fileLength = 0U;
  c2_info[24].fileTime1 = 0U;
  c2_info[24].fileTime2 = 0U;
  c2_info[25].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c2_info[25].name = "islogical";
  c2_info[25].dominantType = "double";
  c2_info[25].resolved = "[B]islogical";
  c2_info[25].fileLength = 0U;
  c2_info[25].fileTime1 = 0U;
  c2_info[25].fileTime2 = 0U;
  c2_info[26].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_mod.m";
  c2_info[26].name = "eps";
  c2_info[26].dominantType = "char";
  c2_info[26].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c2_info[26].fileLength = 1331U;
  c2_info[26].fileTime1 = 1246631312U;
  c2_info[26].fileTime2 = 0U;
  c2_info[27].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c2_info[27].name = "eml_is_float_class";
  c2_info[27].dominantType = "char";
  c2_info[27].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c2_info[27].fileLength = 226U;
  c2_info[27].fileTime1 = 1197872040U;
  c2_info[27].fileTime2 = 0U;
  c2_info[28].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c2_info[28].name = "strcmp";
  c2_info[28].dominantType = "char";
  c2_info[28].resolved = "[B]strcmp";
  c2_info[28].fileLength = 0U;
  c2_info[28].fileTime1 = 0U;
  c2_info[28].fileTime2 = 0U;
  c2_info[29].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c2_info[29].name = "uminus";
  c2_info[29].dominantType = "double";
  c2_info[29].resolved = "[B]uminus";
  c2_info[29].fileLength = 0U;
  c2_info[29].fileTime1 = 0U;
  c2_info[29].fileTime2 = 0U;
  c2_info[30].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_mod.m";
  c2_info[30].name = "mtimes";
  c2_info[30].dominantType = "double";
  c2_info[30].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[30].fileLength = 3425U;
  c2_info[30].fileTime1 = 1251053472U;
  c2_info[30].fileTime2 = 0U;
  c2_info[31].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[31].name = "size";
  c2_info[31].dominantType = "double";
  c2_info[31].resolved = "[B]size";
  c2_info[31].fileLength = 0U;
  c2_info[31].fileTime1 = 0U;
  c2_info[31].fileTime2 = 0U;
  c2_info[32].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_mod.m";
  c2_info[32].name = "le";
  c2_info[32].dominantType = "double";
  c2_info[32].resolved = "[B]le";
  c2_info[32].fileLength = 0U;
  c2_info[32].fileTime1 = 0U;
  c2_info[32].fileTime2 = 0U;
  c2_info[33].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_mod.m";
  c2_info[33].name = "zeros";
  c2_info[33].dominantType = "char";
  c2_info[33].resolved = "[B]zeros";
  c2_info[33].fileLength = 0U;
  c2_info[33].fileTime1 = 0U;
  c2_info[33].fileTime2 = 0U;
  c2_info[34].context = "";
  c2_info[34].name = "rand";
  c2_info[34].dominantType = "double";
  c2_info[34].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/rand.m";
  c2_info[34].fileLength = 4050U;
  c2_info[34].fileTime1 = 1270505720U;
  c2_info[34].fileTime2 = 0U;
  c2_info[35].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/rand.m";
  c2_info[35].name = "uint8";
  c2_info[35].dominantType = "double";
  c2_info[35].resolved = "[B]uint8";
  c2_info[35].fileLength = 0U;
  c2_info[35].fileTime1 = 0U;
  c2_info[35].fileTime2 = 0U;
  c2_info[36].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/rand.m";
  c2_info[36].name = "eml_rand_mt19937ar";
  c2_info[36].dominantType = "char";
  c2_info[36].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_rand_mt19937ar.m";
  c2_info[36].fileLength = 24334U;
  c2_info[36].fileTime1 = 1273865860U;
  c2_info[36].fileTime2 = 0U;
  c2_info[37].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_rand_mt19937ar.m";
  c2_info[37].name = "nargout";
  c2_info[37].dominantType = "";
  c2_info[37].resolved = "[B]nargout";
  c2_info[37].fileLength = 0U;
  c2_info[37].fileTime1 = 0U;
  c2_info[37].fileTime2 = 0U;
  c2_info[38].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_rand_mt19937ar.m!twister_state_vector";
  c2_info[38].name = "uint32";
  c2_info[38].dominantType = "double";
  c2_info[38].resolved = "[B]uint32";
  c2_info[38].fileLength = 0U;
  c2_info[38].fileTime1 = 0U;
  c2_info[38].fileTime2 = 0U;
  c2_info[39].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_rand_mt19937ar.m!genrandu";
  c2_info[39].name = "true";
  c2_info[39].dominantType = "";
  c2_info[39].resolved = "[B]true";
  c2_info[39].fileLength = 0U;
  c2_info[39].fileTime1 = 0U;
  c2_info[39].fileTime2 = 0U;
  c2_info[40].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_rand_mt19937ar.m!is_valid_state";
  c2_info[40].name = "isequal";
  c2_info[40].dominantType = "double";
  c2_info[40].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c2_info[40].fileLength = 180U;
  c2_info[40].fileTime1 = 1226598870U;
  c2_info[40].fileTime2 = 0U;
  c2_info[41].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c2_info[41].name = "eml_isequal_core";
  c2_info[41].dominantType = "double";
  c2_info[41].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c2_info[41].fileLength = 4192U;
  c2_info[41].fileTime1 = 1258085810U;
  c2_info[41].fileTime2 = 0U;
  c2_info[42].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c2_info[42].name = "ge";
  c2_info[42].dominantType = "double";
  c2_info[42].resolved = "[B]ge";
  c2_info[42].fileLength = 0U;
  c2_info[42].fileTime1 = 0U;
  c2_info[42].fileTime2 = 0U;
  c2_info[43].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c2_info[43].name = "isnumeric";
  c2_info[43].dominantType = "double";
  c2_info[43].resolved = "[B]isnumeric";
  c2_info[43].fileLength = 0U;
  c2_info[43].fileTime1 = 0U;
  c2_info[43].fileTime2 = 0U;
  c2_info[44].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!same_size";
  c2_info[44].name = "ndims";
  c2_info[44].dominantType = "double";
  c2_info[44].resolved = "[B]ndims";
  c2_info[44].fileLength = 0U;
  c2_info[44].fileTime1 = 0U;
  c2_info[44].fileTime2 = 0U;
  c2_info[45].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!same_size";
  c2_info[45].name = "ne";
  c2_info[45].dominantType = "double";
  c2_info[45].resolved = "[B]ne";
  c2_info[45].fileLength = 0U;
  c2_info[45].fileTime1 = 0U;
  c2_info[45].fileTime2 = 0U;
  c2_info[46].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!binary_isequal";
  c2_info[46].name = "isempty";
  c2_info[46].dominantType = "double";
  c2_info[46].resolved = "[B]isempty";
  c2_info[46].fileLength = 0U;
  c2_info[46].fileTime1 = 0U;
  c2_info[46].fileTime2 = 0U;
  c2_info[47].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!isequal_scalar";
  c2_info[47].name = "isnan";
  c2_info[47].dominantType = "double";
  c2_info[47].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c2_info[47].fileLength = 541U;
  c2_info[47].fileTime1 = 1271427188U;
  c2_info[47].fileTime2 = 0U;
  c2_info[48].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_rand_mt19937ar.m!genrand_uint32_vector";
  c2_info[48].name = "ones";
  c2_info[48].dominantType = "char";
  c2_info[48].resolved = "[B]ones";
  c2_info[48].fileLength = 0U;
  c2_info[48].fileTime1 = 0U;
  c2_info[48].fileTime2 = 0U;
  c2_info[49].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_rand_mt19937ar.m!genrandu";
  c2_info[49].name = "double";
  c2_info[49].dominantType = "uint32";
  c2_info[49].resolved = "[B]double";
  c2_info[49].fileLength = 0U;
  c2_info[49].fileTime1 = 0U;
  c2_info[49].fileTime2 = 0U;
  c2_info[50].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/rand.m";
  c2_info[50].name = "eml_rand_mcg16807";
  c2_info[50].dominantType = "char";
  c2_info[50].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_rand_mcg16807.m";
  c2_info[50].fileLength = 5995U;
  c2_info[50].fileTime1 = 1245124002U;
  c2_info[50].fileTime2 = 0U;
}

static const mxArray *c2_c_sf_marshall(void *chartInstanceVoid, void *c2_u)
{
  const mxArray *c2_y = NULL;
  boolean_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  SFc2_FinalSimulinkInstanceStruct *chartInstance;
  chartInstance = (SFc2_FinalSimulinkInstanceStruct *)chartInstanceVoid;
  c2_y = NULL;
  c2_b_u = *((boolean_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static real_T c2_emlrt_marshallIn(SFc2_FinalSimulinkInstanceStruct
  *chartInstance, const mxArray *c2_n, const char_T *c2_name)
{
  real_T c2_y;
  real_T c2_d5;
  sf_mex_import(c2_name, sf_mex_dup(c2_n), &c2_d5, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d5;
  sf_mex_destroy(&c2_n);
  return c2_y;
}

static uint8_T c2_b_emlrt_marshallIn(SFc2_FinalSimulinkInstanceStruct
  *chartInstance, const mxArray *c2_b_method, const char_T *
  c2_name)
{
  uint8_T c2_y;
  uint8_T c2_u2;
  if (mxIsEmpty(c2_b_method)) {
    chartInstance->c2_method_not_empty = FALSE;
  } else {
    chartInstance->c2_method_not_empty = TRUE;
    sf_mex_import(c2_name, sf_mex_dup(c2_b_method), &c2_u2, 1, 3, 0U, 0, 0U, 0);
    c2_y = c2_u2;
  }

  sf_mex_destroy(&c2_b_method);
  return c2_y;
}

static real_T c2_c_emlrt_marshallIn(SFc2_FinalSimulinkInstanceStruct
  *chartInstance, const mxArray *c2_b_ni, const char_T *c2_name)
{
  real_T c2_y;
  real_T c2_d6;
  if (mxIsEmpty(c2_b_ni)) {
    chartInstance->c2_ni_not_empty = FALSE;
  } else {
    chartInstance->c2_ni_not_empty = TRUE;
    sf_mex_import(c2_name, sf_mex_dup(c2_b_ni), &c2_d6, 1, 0, 0U, 0, 0U, 0);
    c2_y = c2_d6;
  }

  sf_mex_destroy(&c2_b_ni);
  return c2_y;
}

static void c2_d_emlrt_marshallIn(SFc2_FinalSimulinkInstanceStruct
  *chartInstance, const mxArray *c2_b_twister_state, const char_T *
  c2_name, uint32_T c2_y[625])
{
  uint32_T c2_uv3[625];
  int32_T c2_i17;
  if (mxIsEmpty(c2_b_twister_state)) {
    chartInstance->c2_twister_state_not_empty = FALSE;
  } else {
    chartInstance->c2_twister_state_not_empty = TRUE;
    sf_mex_import(c2_name, sf_mex_dup(c2_b_twister_state), c2_uv3, 1, 7, 0U, 1,
                  0U, 1, 625);
    for (c2_i17 = 0; c2_i17 < 625; c2_i17 = c2_i17 + 1) {
      c2_y[c2_i17] = c2_uv3[c2_i17];
    }
  }

  sf_mex_destroy(&c2_b_twister_state);
}

static uint32_T c2_e_emlrt_marshallIn(SFc2_FinalSimulinkInstanceStruct
  *chartInstance, const mxArray *c2_b_v4_state, const char_T *
  c2_name)
{
  uint32_T c2_y;
  uint32_T c2_u3;
  if (mxIsEmpty(c2_b_v4_state)) {
    chartInstance->c2_v4_state_not_empty = FALSE;
  } else {
    chartInstance->c2_v4_state_not_empty = TRUE;
    sf_mex_import(c2_name, sf_mex_dup(c2_b_v4_state), &c2_u3, 1, 7, 0U, 0, 0U, 0);
    c2_y = c2_u3;
  }

  sf_mex_destroy(&c2_b_v4_state);
  return c2_y;
}

static uint8_T c2_f_emlrt_marshallIn(SFc2_FinalSimulinkInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_FinalSimulink
  , const char_T *c2_name)
{
  uint8_T c2_y;
  uint8_T c2_u4;
  sf_mex_import(c2_name, sf_mex_dup(c2_b_is_active_c2_FinalSimulink), &c2_u4, 1,
                3, 0U, 0, 0U, 0);
  c2_y = c2_u4;
  sf_mex_destroy(&c2_b_is_active_c2_FinalSimulink);
  return c2_y;
}

static void init_dsm_address_info(SFc2_FinalSimulinkInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c2_FinalSimulink_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4288687908U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1816969528U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1573093479U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(18759034U);
}

mxArray *sf_c2_FinalSimulink_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(2303438692U);
    pr[1] = (double)(1614225630U);
    pr[2] = (double)(3606677897U);
    pr[3] = (double)(790318148U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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

static mxArray *sf_get_sim_state_info_c2_FinalSimulink(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x6'type','srcId','name','auxInfo'{{M[1],M[5],T\"n\",},{M[4],M[0],T\"method\",S'l','i','p'{{M1x2[380 386],M[1],T\"C:/Program Files (x86)/MATLAB/R2010bSP1/toolbox/eml/lib/matlab/elmat/rand.m\"}}},{M[4],M[0],T\"ni\",S'l','i','p'{{M1x2[34 36],M[0],}}},{M[4],M[0],T\"twister_state\",S'l','i','p'{{M1x2[396 409],M[1],T\"C:/Program Files (x86)/MATLAB/R2010bSP1/toolbox/eml/lib/matlab/elmat/rand.m\"}}},{M[4],M[0],T\"v4_state\",S'l','i','p'{{M1x2[387 395],M[1],T\"C:/Program Files (x86)/MATLAB/R2010bSP1/toolbox/eml/lib/matlab/elmat/rand.m\"}}},{M[8],M[0],T\"is_active_c2_FinalSimulink\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 6, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_FinalSimulink_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_FinalSimulinkInstanceStruct *chartInstance;
    chartInstance = (SFc2_FinalSimulinkInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_FinalSimulinkMachineNumber_,
           2,
           1,
           1,
           2,
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
          init_script_number_translation(_FinalSimulinkMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_FinalSimulinkMachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_FinalSimulinkMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"t");
          _SFD_SET_DATA_PROPS(1,2,0,1,"n");
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
        _SFD_CV_INIT_EML(0,1,2,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,140);
        _SFD_CV_INIT_EML_IF(0,0,37,51,-1,65);
        _SFD_CV_INIT_EML_IF(0,1,67,81,112,129);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshall);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshall);

        {
          real_T *c2_t;
          real_T *c2_n;
          c2_n = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c2_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_t);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_n);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_FinalSimulinkMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c2_FinalSimulink(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_FinalSimulinkInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_FinalSimulink((SFc2_FinalSimulinkInstanceStruct*)
    chartInstanceVar);
  initialize_c2_FinalSimulink((SFc2_FinalSimulinkInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c2_FinalSimulink(void *chartInstanceVar)
{
  enable_c2_FinalSimulink((SFc2_FinalSimulinkInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_FinalSimulink(void *chartInstanceVar)
{
  disable_c2_FinalSimulink((SFc2_FinalSimulinkInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_FinalSimulink(void *chartInstanceVar)
{
  sf_c2_FinalSimulink((SFc2_FinalSimulinkInstanceStruct*) chartInstanceVar);
}

static mxArray* sf_internal_get_sim_state_c2_FinalSimulink(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_FinalSimulink
    ((SFc2_FinalSimulinkInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = sf_get_sim_state_info_c2_FinalSimulink();/* state var info */
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

static void sf_internal_set_sim_state_c2_FinalSimulink(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_FinalSimulink();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_FinalSimulink((SFc2_FinalSimulinkInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static mxArray* sf_opaque_get_sim_state_c2_FinalSimulink(SimStruct* S)
{
  return sf_internal_get_sim_state_c2_FinalSimulink(S);
}

static void sf_opaque_set_sim_state_c2_FinalSimulink(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c2_FinalSimulink(S, st);
}

static void sf_opaque_terminate_c2_FinalSimulink(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_FinalSimulinkInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c2_FinalSimulink((SFc2_FinalSimulinkInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  compInitSubchartSimstructsFcn_c2_FinalSimulink
    ((SFc2_FinalSimulinkInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_FinalSimulink(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_FinalSimulink((SFc2_FinalSimulinkInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_FinalSimulink(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"FinalSimulink","FinalSimulink",2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"FinalSimulink","FinalSimulink",2,
                "RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"FinalSimulink",
      "FinalSimulink",2,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"FinalSimulink","FinalSimulink",2,1);
      sf_mark_chart_reusable_outputs(S,"FinalSimulink","FinalSimulink",2,1);
    }

    sf_set_rtw_dwork_info(S,"FinalSimulink","FinalSimulink",2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3891627530U));
  ssSetChecksum1(S,(1785742595U));
  ssSetChecksum2(S,(1856421821U));
  ssSetChecksum3(S,(3469010053U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_FinalSimulink(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "FinalSimulink", "FinalSimulink",2);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_FinalSimulink(SimStruct *S)
{
  SFc2_FinalSimulinkInstanceStruct *chartInstance;
  chartInstance = (SFc2_FinalSimulinkInstanceStruct *)malloc(sizeof
    (SFc2_FinalSimulinkInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_FinalSimulinkInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c2_FinalSimulink;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_FinalSimulink;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c2_FinalSimulink;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_FinalSimulink;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_FinalSimulink;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_FinalSimulink;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_FinalSimulink;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_FinalSimulink;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_FinalSimulink;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_FinalSimulink;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_FinalSimulink;
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

void c2_FinalSimulink_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_FinalSimulink(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_FinalSimulink(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_FinalSimulink(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_FinalSimulink_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
