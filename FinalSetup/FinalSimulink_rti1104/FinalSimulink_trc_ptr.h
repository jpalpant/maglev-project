  /*********************** dSPACE target specific file *************************

   Header file FinalSimulink_trc_ptr.h:

   Declaration of function that initializes the global TRC pointers

   RTI1104 6.6 (29-Nov-2010)
   Wed Dec 03 14:35:15 2014

   (c) Copyright 2008, dSPACE GmbH. All rights reserved.

  *****************************************************************************/
  #ifndef RTI_HEADER_FinalSimulink_trc_ptr_h_
  #define RTI_HEADER_FinalSimulink_trc_ptr_h_
  /* Include the model header file. */
  #include "FinalSimulink.h"
  #include "FinalSimulink_private.h"

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
              EXTERN_C volatile  real_T *p_FinalSimulink_B_real_T_0;
              EXTERN_C volatile  real_T *p_FinalSimulink_P_real_T_0;
              EXTERN_C volatile  real_T *p_FinalSimulink_DWork_real_T_0;
              EXTERN_C volatile  uint32_T *p_FinalSimulink_DWork_uint32_T_1;
              EXTERN_C volatile  uint8_T *p_FinalSimulink_DWork_uint8_T_2;
              EXTERN_C volatile  boolean_T *p_FinalSimulink_DWork_boolean_T_3;
              EXTERN_C volatile  real_T *p_FinalSimulink_X_real_T_0;
              EXTERN_C volatile  real_T *p_FinalSimulink_Y_real_T_0;

   #define RTI_INIT_TRC_POINTERS() \
              p_FinalSimulink_B_real_T_0 = &FinalSimulink_B.Clock;\
              p_FinalSimulink_P_real_T_0 = &FinalSimulink_P.Switch_Value;\
              p_FinalSimulink_DWork_real_T_0 = &FinalSimulink_DWork.ni;\
              p_FinalSimulink_DWork_uint32_T_1 = &FinalSimulink_DWork.v4_state;\
              p_FinalSimulink_DWork_uint8_T_2 = &FinalSimulink_DWork.method;\
              p_FinalSimulink_DWork_boolean_T_3 = &FinalSimulink_DWork.twister_state_not_empty;\
              p_FinalSimulink_X_real_T_0 = &FinalSimulink_X.integr_CSTATE;\
              p_FinalSimulink_Y_real_T_0 = &FinalSimulink_Y.SensorVoltage;\

   #endif                       /* RTI_HEADER_FinalSimulink_trc_ptr_h_ */
