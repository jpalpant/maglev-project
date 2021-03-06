/*
 * FinalSimulink.c
 *
 * Real-Time Workshop code generation for Simulink model "FinalSimulink.mdl".
 *
 * Model version              : 1.64
 * Real-Time Workshop version : 7.6.1  (R2010bSP1)  28-Jan-2011
 * C source code generated on : Wed Dec 03 14:35:15 2014
 *
 * Target selection: rti1104.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "FinalSimulink_trc_ptr.h"
#include "FinalSimulink.h"
#include "FinalSimulink_private.h"

/* Block signals (auto storage) */
BlockIO_FinalSimulink FinalSimulink_B;

/* Continuous states */
ContinuousStates_FinalSimulink FinalSimulink_X;

/* Block states (auto storage) */
D_Work_FinalSimulink FinalSimulink_DWork;

/* External outputs (root outports fed by signals with auto storage) */
ExternalOutputs_FinalSimulink FinalSimulink_Y;

/* Real-time model */
RT_MODEL_FinalSimulink FinalSimulink_M_;
RT_MODEL_FinalSimulink *FinalSimulink_M = &FinalSimulink_M_;

/* Forward declaration for local functions */
static real_T FinalS_refp1_eml_rand_mt19937ar(uint32_T state[625]);
static real_T FinalSimulink_rand(void);

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 1;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  FinalSimulink_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  FinalSimulink_output(0);
  FinalSimulink_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  FinalSimulink_output(0);
  FinalSimulink_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Function for Embedded MATLAB: '<Root>/Changing Set Point' */
static real_T FinalS_refp1_eml_rand_mt19937ar(uint32_T state[625])
{
  real_T b_r;
  uint32_T u[2];
  uint32_T mti;
  uint32_T y;
  int32_T j;
  int32_T kk;

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
    u[0] = 0U;
    u[1] = 0U;
    for (j = 0; j < 2; j++) {
      mti = state[624] + 1U;
      if (mti >= 625U) {
        for (kk = 0; kk < 227; kk++) {
          y = (state[kk + 1] & 2147483647U) | (state[kk] & 2147483648U);
          if ((int32_T)(y & 1U) == 0) {
            mti = y >> 1U;
          } else {
            mti = y >> 1U ^ 2567483615U;
          }

          state[kk] = state[kk + 397] ^ mti;
        }

        for (kk = 228; kk < 624; kk++) {
          y = (state[kk - 1] & 2147483648U) | (state[kk] & 2147483647U);
          if ((int32_T)(y & 1U) == 0) {
            mti = y >> 1U;
          } else {
            mti = y >> 1U ^ 2567483615U;
          }

          state[kk - 1] = state[kk - 228] ^ mti;
        }

        y = (state[623] & 2147483648U) | (state[0] & 2147483647U);
        if ((int32_T)(y & 1U) == 0) {
          mti = y >> 1U;
        } else {
          mti = y >> 1U ^ 2567483615U;
        }

        state[623] = state[396] ^ mti;
        mti = 1U;
      }

      y = state[(int32_T)mti - 1];
      state[624] = mti;
      y ^= y >> 11U;
      y ^= y << 7U & 2636928640U;
      y ^= y << 15U & 4022730752U;
      y ^= y >> 18U;
      u[j] = y;
    }

    u[0] = u[0] >> 5U;
    u[1] = u[1] >> 6U;
    b_r = ((real_T)u[0] * 6.7108864E+7 + (real_T)u[1]) * 1.1102230246251565E-16;
  } while (!(b_r != 0.0));

  return b_r;
}

/* Function for Embedded MATLAB: '<Root>/Changing Set Point' */
static real_T FinalSimulink_rand(void)
{
  int32_T hi;
  uint32_T test;
  uint32_T test_0;
  if (FinalSimulink_DWork.method == 2) {
    if (!FinalSimulink_DWork.twister_state_not_empty) {
      memset((void *)(&FinalSimulink_DWork.twister_state[0]), (int32_T)0U, 625U *
             sizeof(uint32_T));
      test = 5489U;
      FinalSimulink_DWork.twister_state[0] = 5489U;
      for (hi = 2; hi < 625; hi++) {
        test = (test >> 30U ^ test) * 1812433253U + (uint32_T)(hi - 1);
        FinalSimulink_DWork.twister_state[hi - 1] = test;
      }

      FinalSimulink_DWork.twister_state[624] = 624U;
      FinalSimulink_DWork.twister_state_not_empty = TRUE;
    }

    return FinalS_refp1_eml_rand_mt19937ar(&FinalSimulink_DWork.twister_state[0]);
  } else {
    hi = (int32_T)(FinalSimulink_DWork.v4_state / 127773U);
    test = (FinalSimulink_DWork.v4_state - (uint32_T)hi * 127773U) * 16807U;
    test_0 = 2836U * (uint32_T)hi;
    if (test < test_0) {
      test += 2147483647U - test_0;
    } else {
      test -= test_0;
    }

    FinalSimulink_DWork.v4_state = test;
    return (real_T)test * 4.6566128752457969E-10;
  }
}

/* Model output function */
void FinalSimulink_output(int_T tid)
{
  /* local block i/o variables */
  real_T rtb_integr;
  real_T x;
  real_T rtb_N;
  real_T rtb_n;
  if (rtmIsMajorTimeStep(FinalSimulink_M)) {
    /* set solver stop time */
    if (!(FinalSimulink_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&FinalSimulink_M->solverInfo,
                            ((FinalSimulink_M->Timing.clockTickH0 + 1) *
        FinalSimulink_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&FinalSimulink_M->solverInfo,
                            ((FinalSimulink_M->Timing.clockTick0 + 1) *
        FinalSimulink_M->Timing.stepSize0 + FinalSimulink_M->Timing.clockTickH0 *
        FinalSimulink_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(FinalSimulink_M)) {
    FinalSimulink_M->Timing.t[0] = rtsiGetT(&FinalSimulink_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(FinalSimulink_M)) {
    /* S-Function (rti_commonblock): '<S3>/S-Function' */
    /* This comment workarounds a Real-Time Workshop code generation problem */

    /* dSPACE I/O Board DS1104 #1 Unit:ADC Group:NON_MUX */
    FinalSimulink_Y.SensorVoltage = (real_T) ds1104_adc_read_conv(2);
  }

  /* Clock: '<Root>/Clock' */
  FinalSimulink_B.Clock = FinalSimulink_M->Timing.t[0];

  /* Embedded MATLAB: '<Root>/Changing Set Point' */
  /* Embedded MATLAB Function 'Changing Set Point': '<S1>:1' */
  if (FinalSimulink_B.Clock - floor(FinalSimulink_B.Clock) == 0.0) {
    /* '<S1>:1:8' */
    /* '<S1>:1:9' */
    x = FinalSimulink_rand();
    rtb_n = FinalSimulink_rand();
    FinalSimulink_DWork.ni = x * 0.05 - rtb_n * 0.05;
  } else {
    /* '<S1>:1:11' */
  }

  /* '<S1>:1:14' */
  FinalSimulink_B.n = FinalSimulink_DWork.ni;

  /* Embedded MATLAB: '<Root>/Sine Wave' incorporates:
   *  Constant: '<Root>/Sine Amplitude'
   *  Constant: '<Root>/Sine Frequency'
   */
  /* Embedded MATLAB Function 'Sine Wave': '<S8>:1' */
  /* '<S8>:1:2' */
  rtb_N = sin(6.2831853071795862 * FinalSimulink_P.SineFrequency_Value *
              FinalSimulink_B.Clock) * FinalSimulink_P.SineAmplitude_Value;

  /* Embedded MATLAB: '<Root>/Changing Set Point1' incorporates:
   *  Constant: '<Root>/Pulse Amplitude'
   *  Constant: '<Root>/Pulse Frequency'
   */
  /* Embedded MATLAB Function 'Changing Set Point1': '<S2>:1' */
  /* '<S2>:1:2' */
  x = FinalSimulink_P.PulseFrequency_Value * FinalSimulink_B.Clock;
  if (x < 0.0) {
    x = ceil(x - 0.5);
  } else {
    x = floor(x + 0.5);
  }

  /* '<S2>:1:3' */
  rtb_n = FinalSimulink_P.PulseAmplitude_Value * rt_pow_snf(-1.0, x);
  if (rtmIsMajorTimeStep(FinalSimulink_M)) {
    /* S-Function (rti_commonblock): '<S4>/S-Function' */
    /* This comment workarounds a Real-Time Workshop code generation problem */

    /* dSPACE I/O Board DS1104 #1 Unit:ADC Group:NON_MUX */
    FinalSimulink_B.SFunction_l = (real_T) ds1104_adc_read_conv(3);

    /* Bias: '<Root>/Bias' */
    FinalSimulink_B.Bias = FinalSimulink_B.SFunction_l +
      FinalSimulink_P.Bias_Bias;
  }

  /* MultiPortSwitch: '<Root>/Multiport Switch' incorporates:
   *  Constant: '<Root>/Set Point'
   *  Constant: '<Root>/Switch'
   */
  switch ((int32_T)FinalSimulink_P.Switch_Value) {
   case 1:
    rtb_N = FinalSimulink_B.n;
    break;

   case 2:
    break;

   case 3:
    rtb_N = FinalSimulink_P.SetPoint_Value;
    break;

   case 4:
    rtb_N = rtb_n;
    break;

   default:
    rtb_N = FinalSimulink_B.Bias;
    break;
  }

  /* Sum: '<Root>/Sum2' */
  FinalSimulink_B.Sum2 = FinalSimulink_Y.SensorVoltage + rtb_N;

  /* Gain: '<S6>/Kp' */
  x = FinalSimulink_P.Kp_Gain * FinalSimulink_B.Sum2;

  /* Derivative: '<S6>/deriv' */
  {
    real_T t = FinalSimulink_M->Timing.t[0];
    real_T timeStampA = FinalSimulink_DWork.deriv_RWORK.TimeStampA;
    real_T timeStampB = FinalSimulink_DWork.deriv_RWORK.TimeStampB;
    real_T *lastU = &FinalSimulink_DWork.deriv_RWORK.LastUAtTimeA;
    if (timeStampA >= t && timeStampB >= t) {
      rtb_integr = 0.0;
    } else {
      real_T deltaT;
      real_T lastTime = timeStampA;
      if (timeStampA < timeStampB) {
        if (timeStampB < t) {
          lastTime = timeStampB;
          lastU = &FinalSimulink_DWork.deriv_RWORK.LastUAtTimeB;
        }
      } else if (timeStampA >= t) {
        lastTime = timeStampB;
        lastU = &FinalSimulink_DWork.deriv_RWORK.LastUAtTimeB;
      }

      deltaT = t - lastTime;
      rtb_integr = (FinalSimulink_B.Sum2 - *lastU++) / deltaT;
    }
  }

  /* Gain: '<S6>/Kd' */
  rtb_n = FinalSimulink_P.Kd_Gain * rtb_integr;

  /* Integrator: '<S6>/integr'
   *
   * Regarding '<S6>/integr':
   *  Limited Integrator
   */
  if (FinalSimulink_X.integr_CSTATE >= FinalSimulink_P.integr_UpperSat ) {
    FinalSimulink_X.integr_CSTATE = FinalSimulink_P.integr_UpperSat;
  } else if (FinalSimulink_X.integr_CSTATE <= FinalSimulink_P.integr_LowerSat )
  {
    FinalSimulink_X.integr_CSTATE = FinalSimulink_P.integr_LowerSat;
  }

  rtb_integr = FinalSimulink_X.integr_CSTATE;

  /* Sum: '<S6>/Sum' incorporates:
   *  Gain: '<S6>/Ki'
   */
  FinalSimulink_B.Sum = (x + rtb_n) + FinalSimulink_P.Ki_Gain * rtb_integr;

  /* Outport: '<Root>/VoltageToMaglev' */
  FinalSimulink_Y.VoltageToMaglev = FinalSimulink_B.Sum;

  /* Outport: '<Root>/RealSet' incorporates:
   *  Gain: '<Root>/Gain'
   */
  FinalSimulink_Y.RealSet = FinalSimulink_P.Gain_Gain * rtb_N;
  if (rtmIsMajorTimeStep(FinalSimulink_M)) {
    /* S-Function (rti_commonblock): '<S5>/S-Function1' */
    /* This comment workarounds a Real-Time Workshop code generation problem */

    /* dSPACE I/O Board DS1104 #1 Unit:DAC */
    ds1104_dac_write(1, FinalSimulink_B.Sum);
  }

  /* user code (Output function Trailer) */

  /* dSPACE Data Capture block: (none) */
  /* ... Service number: 1 */
  /* ... Service name:   (default) */
  if (rtmIsContinuousTask(FinalSimulink_M, 0) && rtmIsMajorTimeStep
      (FinalSimulink_M)) {
    host_service(1, rtk_current_task_absolute_time_ptr_get());
  }

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model update function */
void FinalSimulink_update(int_T tid)
{
  /* Update for Derivative: '<S6>/deriv' */
  {
    real_T timeStampA = FinalSimulink_DWork.deriv_RWORK.TimeStampA;
    real_T timeStampB = FinalSimulink_DWork.deriv_RWORK.TimeStampB;
    real_T* lastTime = &FinalSimulink_DWork.deriv_RWORK.TimeStampA;
    real_T* lastU = &FinalSimulink_DWork.deriv_RWORK.LastUAtTimeA;
    if (timeStampA != rtInf) {
      if (timeStampB == rtInf) {
        lastTime = &FinalSimulink_DWork.deriv_RWORK.TimeStampB;
        lastU = &FinalSimulink_DWork.deriv_RWORK.LastUAtTimeB;
      } else if (timeStampA >= timeStampB) {
        lastTime = &FinalSimulink_DWork.deriv_RWORK.TimeStampB;
        lastU = &FinalSimulink_DWork.deriv_RWORK.LastUAtTimeB;
      }
    }

    *lastTime = FinalSimulink_M->Timing.t[0];
    *lastU++ = FinalSimulink_B.Sum2;
  }

  if (rtmIsMajorTimeStep(FinalSimulink_M)) {
    rt_ertODEUpdateContinuousStates(&FinalSimulink_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++FinalSimulink_M->Timing.clockTick0)) {
    ++FinalSimulink_M->Timing.clockTickH0;
  }

  FinalSimulink_M->Timing.t[0] = rtsiGetSolverStopTime
    (&FinalSimulink_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++FinalSimulink_M->Timing.clockTick1)) {
      ++FinalSimulink_M->Timing.clockTickH1;
    }

    FinalSimulink_M->Timing.t[1] = FinalSimulink_M->Timing.clockTick1 *
      FinalSimulink_M->Timing.stepSize1 + FinalSimulink_M->Timing.clockTickH1 *
      FinalSimulink_M->Timing.stepSize1 * 4294967296.0;
  }

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Derivatives for root system: '<Root>' */
void FinalSimulink_derivatives(void)
{
  /* Derivatives for Integrator: '<S6>/integr' */
  {
    boolean_T lsat;
    boolean_T usat;
    lsat = ( FinalSimulink_X.integr_CSTATE <= FinalSimulink_P.integr_LowerSat );
    usat = ( FinalSimulink_X.integr_CSTATE >= FinalSimulink_P.integr_UpperSat );
    if ((!lsat && !usat) ||
        (lsat && (FinalSimulink_B.Sum2 > 0)) ||
        (usat && (FinalSimulink_B.Sum2 < 0)) ) {
      ((StateDerivatives_FinalSimulink *) FinalSimulink_M->ModelData.derivs)
        ->integr_CSTATE = FinalSimulink_B.Sum2;
    } else {
      /* in saturation */
      ((StateDerivatives_FinalSimulink *) FinalSimulink_M->ModelData.derivs)
        ->integr_CSTATE = 0.0;
    }
  }
}

/* Model initialize function */
void FinalSimulink_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)FinalSimulink_M, 0,
                sizeof(RT_MODEL_FinalSimulink));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&FinalSimulink_M->solverInfo,
                          &FinalSimulink_M->Timing.simTimeStep);
    rtsiSetTPtr(&FinalSimulink_M->solverInfo, &rtmGetTPtr(FinalSimulink_M));
    rtsiSetStepSizePtr(&FinalSimulink_M->solverInfo,
                       &FinalSimulink_M->Timing.stepSize0);
    rtsiSetdXPtr(&FinalSimulink_M->solverInfo,
                 &FinalSimulink_M->ModelData.derivs);
    rtsiSetContStatesPtr(&FinalSimulink_M->solverInfo,
                         &FinalSimulink_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&FinalSimulink_M->solverInfo,
      &FinalSimulink_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&FinalSimulink_M->solverInfo, (&rtmGetErrorStatus
      (FinalSimulink_M)));
    rtsiSetRTModelPtr(&FinalSimulink_M->solverInfo, FinalSimulink_M);
  }

  rtsiSetSimTimeStep(&FinalSimulink_M->solverInfo, MAJOR_TIME_STEP);
  FinalSimulink_M->ModelData.intgData.y = FinalSimulink_M->ModelData.odeY;
  FinalSimulink_M->ModelData.intgData.f[0] = FinalSimulink_M->ModelData.odeF[0];
  FinalSimulink_M->ModelData.intgData.f[1] = FinalSimulink_M->ModelData.odeF[1];
  FinalSimulink_M->ModelData.intgData.f[2] = FinalSimulink_M->ModelData.odeF[2];
  FinalSimulink_M->ModelData.contStates = ((real_T *) &FinalSimulink_X);
  rtsiSetSolverData(&FinalSimulink_M->solverInfo, (void *)
                    &FinalSimulink_M->ModelData.intgData);
  rtsiSetSolverName(&FinalSimulink_M->solverInfo,"ode3");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = FinalSimulink_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    FinalSimulink_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    FinalSimulink_M->Timing.sampleTimes =
      (&FinalSimulink_M->Timing.sampleTimesArray[0]);
    FinalSimulink_M->Timing.offsetTimes =
      (&FinalSimulink_M->Timing.offsetTimesArray[0]);

    /* task periods */
    FinalSimulink_M->Timing.sampleTimes[0] = (0.0);
    FinalSimulink_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    FinalSimulink_M->Timing.offsetTimes[0] = (0.0);
    FinalSimulink_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(FinalSimulink_M, &FinalSimulink_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = FinalSimulink_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    FinalSimulink_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(FinalSimulink_M, -1);
  FinalSimulink_M->Timing.stepSize0 = 0.001;
  FinalSimulink_M->Timing.stepSize1 = 0.001;
  FinalSimulink_M->solverInfoPtr = (&FinalSimulink_M->solverInfo);
  FinalSimulink_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&FinalSimulink_M->solverInfo, 0.001);
  rtsiSetSolverMode(&FinalSimulink_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  FinalSimulink_M->ModelData.blockIO = ((void *) &FinalSimulink_B);
  (void) memset(((void *) &FinalSimulink_B), 0,
                sizeof(BlockIO_FinalSimulink));

  /* parameters */
  FinalSimulink_M->ModelData.defaultParam = ((real_T *)&FinalSimulink_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &FinalSimulink_X;
    FinalSimulink_M->ModelData.contStates = (x);
    (void) memset((void *)&FinalSimulink_X, 0,
                  sizeof(ContinuousStates_FinalSimulink));
  }

  /* states (dwork) */
  FinalSimulink_M->Work.dwork = ((void *) &FinalSimulink_DWork);
  (void) memset((void *)&FinalSimulink_DWork, 0,
                sizeof(D_Work_FinalSimulink));

  /* external outputs */
  FinalSimulink_M->ModelData.outputs = (&FinalSimulink_Y);
  (void) memset((void *)&FinalSimulink_Y, 0,
                sizeof(ExternalOutputs_FinalSimulink));

  {
    /* user code (registration function declaration) */
    /*Call the macro that initializes the global TRC pointers
       inside the model initialization/registration function. */
    RTI_INIT_TRC_POINTERS();
  }
}

/* Model terminate function */
void FinalSimulink_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of GRT compatible call interface                                 *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  FinalSimulink_output(tid);
}

void MdlUpdate(int_T tid)
{
  FinalSimulink_update(tid);
}

void MdlInitializeSizes(void)
{
  FinalSimulink_M->Sizes.numContStates = (1);/* Number of continuous states */
  FinalSimulink_M->Sizes.numY = (3);   /* Number of model outputs */
  FinalSimulink_M->Sizes.numU = (0);   /* Number of model inputs */
  FinalSimulink_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  FinalSimulink_M->Sizes.numSampTimes = (2);/* Number of sample times */
  FinalSimulink_M->Sizes.numBlocks = (29);/* Number of blocks */
  FinalSimulink_M->Sizes.numBlockIO = (7);/* Number of block outputs */
  FinalSimulink_M->Sizes.numBlockPrms = (14);/* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
  /* InitializeConditions for Embedded MATLAB: '<Root>/Changing Set Point' */
  FinalSimulink_DWork.twister_state_not_empty = FALSE;
  FinalSimulink_DWork.ni = 0.0;
  FinalSimulink_DWork.method = 2U;
  FinalSimulink_DWork.v4_state = 1144108930U;

  /* InitializeConditions for Derivative: '<S6>/deriv' */
  FinalSimulink_DWork.deriv_RWORK.TimeStampA = rtInf;
  FinalSimulink_DWork.deriv_RWORK.TimeStampB = rtInf;

  /* InitializeConditions for Integrator: '<S6>/integr' */
  FinalSimulink_X.integr_CSTATE = FinalSimulink_P.integr_IC;
}

void MdlStart(void)
{
  MdlInitialize();
}

void MdlTerminate(void)
{
  FinalSimulink_terminate();
}

RT_MODEL_FinalSimulink *FinalSimulink(void)
{
  FinalSimulink_initialize(1);
  return FinalSimulink_M;
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
