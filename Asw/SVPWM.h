/*
 * File: SVPWM.h
 *
 * Code generated for Simulink model 'SVPWM'.
 *
 * Model version                  : 4.180
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Sun Dec  7 21:29:23 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef SVPWM_h_
#define SVPWM_h_
#ifndef SVPWM_COMMON_INCLUDES_
#define SVPWM_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* SVPWM_COMMON_INCLUDES_ */

#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_SVPWM_T RT_MODEL_SVPWM_T;

/* Real-time Model Data Structure */
struct tag_RTM_SVPWM_T {
  const char_T * volatile errorStatus;
};

/* Model entry point functions */
extern void SVPWM_initialize(RT_MODEL_SVPWM_T *const SVPWM_M, real32_T
  SVPWM_U_u_abc[3], real32_T *SVPWM_U_Vbus, real32_T *SVPWM_Y_y_PWMA, real32_T
  *SVPWM_Y_y_PWMB, real32_T *SVPWM_Y_y_PWMC, real32_T *SVPWM_Y_duty_n);
extern void SVPWM_step(RT_MODEL_SVPWM_T *const SVPWM_M, real32_T SVPWM_U_u_abc[3],
  real32_T SVPWM_U_Vbus, real32_T *SVPWM_Y_y_PWMA, real32_T *SVPWM_Y_y_PWMB,
  real32_T *SVPWM_Y_y_PWMC, real32_T *SVPWM_Y_duty_n);
extern void SVPWM_terminate(RT_MODEL_SVPWM_T *const SVPWM_M);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Gain' : Eliminated nontunable gain of 1
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('FourLegs/SVPWM')    - opens subsystem FourLegs/SVPWM
 * hilite_system('FourLegs/SVPWM/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'FourLegs'
 * '<S1>'   : 'FourLegs/SVPWM'
 * '<S2>'   : 'FourLegs/SVPWM/eth3'
 * '<S3>'   : 'FourLegs/SVPWM/eth3/MATLAB Function'
 */
#endif                                 /* SVPWM_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
