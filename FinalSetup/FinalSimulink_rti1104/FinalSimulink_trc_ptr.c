/***************************************************************************

   Source file FinalSimulink_trc_ptr.c:

   Definition of function that initializes the global TRC pointers

   RTI1104 6.6 (29-Nov-2010)
   Wed Dec 03 14:35:15 2014

   (c) Copyright 2008, dSPACE GmbH. All rights reserved.

 *****************************************************************************/

/* Include header file. */
#include "FinalSimulink_trc_ptr.h"

/* Definition of Global pointers to data type transitions (for TRC-file access) */
volatile real_T *p_FinalSimulink_B_real_T_0 = 0;
volatile real_T *p_FinalSimulink_P_real_T_0 = 0;
volatile real_T *p_FinalSimulink_DWork_real_T_0 = 0;
volatile uint32_T *p_FinalSimulink_DWork_uint32_T_1 = 0;
volatile uint8_T *p_FinalSimulink_DWork_uint8_T_2 = 0;
volatile boolean_T *p_FinalSimulink_DWork_boolean_T_3 = 0;
volatile real_T *p_FinalSimulink_X_real_T_0 = 0;
volatile real_T *p_FinalSimulink_Y_real_T_0 = 0;
