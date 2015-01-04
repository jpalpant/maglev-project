/***************************************************************************

   Source file MaglevModel_trc_ptr.c:

   Definition of function that initializes the global TRC pointers

   RTI1104 6.6 (29-Nov-2010)
   Tue Nov 25 13:28:08 2014

   (c) Copyright 2008, dSPACE GmbH. All rights reserved.

 *****************************************************************************/

/* Include header file. */
#include "MaglevModel_trc_ptr.h"

/* Definition of Global pointers to data type transitions (for TRC-file access) */
volatile real_T *p_MaglevModel_B_real_T_0 = 0;
volatile real_T *p_MaglevModel_P_real_T_0 = 0;
volatile real_T *p_MaglevModel_DWork_real_T_0 = 0;
volatile uint32_T *p_MaglevModel_DWork_uint32_T_1 = 0;
volatile uint8_T *p_MaglevModel_DWork_uint8_T_2 = 0;
volatile boolean_T *p_MaglevModel_DWork_boolean_T_3 = 0;
volatile real_T *p_MaglevModel_X_real_T_0 = 0;
volatile real_T *p_MaglevModel_Y_real_T_0 = 0;
