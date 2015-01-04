  /*********************** dSPACE target specific file *************************

   Header file MaglevModel_trc_ptr.h:

   Declaration of function that initializes the global TRC pointers

   RTI1104 6.6 (29-Nov-2010)
   Tue Nov 25 13:28:08 2014

   (c) Copyright 2008, dSPACE GmbH. All rights reserved.

  *****************************************************************************/
  #ifndef RTI_HEADER_MaglevModel_trc_ptr_h_
  #define RTI_HEADER_MaglevModel_trc_ptr_h_
  /* Include the model header file. */
  #include "MaglevModel.h"
  #include "MaglevModel_private.h"

  #ifdef EXTERN_C
  #undef EXTERN_C
  #endif

  #ifdef __cplusplus
  #define EXTERN_C                       extern "C"
  #else
  #define EXTERN_C                       extern
  #endif

  /*
   *  Declare the global TRC pointers
   */
              EXTERN_C volatile  real_T *p_MaglevModel_B_real_T_0;
              EXTERN_C volatile  real_T *p_MaglevModel_P_real_T_0;
              EXTERN_C volatile  real_T *p_MaglevModel_DWork_real_T_0;
              EXTERN_C volatile  uint32_T *p_MaglevModel_DWork_uint32_T_1;
              EXTERN_C volatile  uint8_T *p_MaglevModel_DWork_uint8_T_2;
              EXTERN_C volatile  boolean_T *p_MaglevModel_DWork_boolean_T_3;
              EXTERN_C volatile  real_T *p_MaglevModel_X_real_T_0;
              EXTERN_C volatile  real_T *p_MaglevModel_Y_real_T_0;

   #define RTI_INIT_TRC_POINTERS() \
              p_MaglevModel_B_real_T_0 = &MaglevModel_B.Clock;\
              p_MaglevModel_P_real_T_0 = &MaglevModel_P.Switch_Value;\
              p_MaglevModel_DWork_real_T_0 = &MaglevModel_DWork.ni;\
              p_MaglevModel_DWork_uint32_T_1 = &MaglevModel_DWork.v4_state;\
              p_MaglevModel_DWork_uint8_T_2 = &MaglevModel_DWork.method;\
              p_MaglevModel_DWork_boolean_T_3 = &MaglevModel_DWork.twister_state_not_empty;\
              p_MaglevModel_X_real_T_0 = &MaglevModel_X.integr_CSTATE;\
              p_MaglevModel_Y_real_T_0 = &MaglevModel_Y.SensorVoltage;\

   #endif                       /* RTI_HEADER_MaglevModel_trc_ptr_h_ */
