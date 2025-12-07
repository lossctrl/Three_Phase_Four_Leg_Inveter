/*
 * File: SVPWM.c
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

#include "SVPWM.h"
#include "rtwtypes.h"
#include <math.h>
#include <string.h>

static real32_T SVPWM_eth3(const real32_T rtu_y_abc_spwm[3]);
static void SVPWM_SVPWM(const real32_T rtu_u_abc[3], real32_T rtu_Vbus, real32_T
  rty_y_PWMA[3], real32_T *rty_duty_n);

/*===========*
 * Constants *
 *===========*/
#define RT_PI                          3.14159265358979323846
#define RT_PIF                         3.1415927F
#define RT_LN_10                       2.30258509299404568402
#define RT_LN_10F                      2.3025851F
#define RT_LOG10E                      0.43429448190325182765
#define RT_LOG10EF                     0.43429449F
#define RT_E                           2.7182818284590452354
#define RT_EF                          2.7182817F

/*
 * UNUSED_PARAMETER(x)
 *   Used to specify that a function parameter (argument) is required but not
 *   accessed by the function body.
 */
#ifndef UNUSED_PARAMETER
#if defined(__LCC__)
#define UNUSED_PARAMETER(x)                                      /* do nothing */
#else

/*
 * This is the semi-ANSI standard way of indicating that an
 * unused function parameter is required.
 */
#define UNUSED_PARAMETER(x)            (void) (x)
#endif
#endif

/* Output and update for atomic system: '<S1>/eth3' */
static real32_T SVPWM_eth3(const real32_T rtu_y_abc_spwm[3])
{
  real32_T rty_duty_n_0;
  real32_T rtb_Gain;
  real32_T rtb_Max;

  /* MinMax: '<S2>/Max' */
  rtb_Max = fmaxf(fmaxf(rtu_y_abc_spwm[0], rtu_y_abc_spwm[1]), rtu_y_abc_spwm[2]);

  /* MinMax: '<S2>/Max1' */
  rty_duty_n_0 = fminf(fminf(rtu_y_abc_spwm[0], rtu_y_abc_spwm[1]),
                       rtu_y_abc_spwm[2]);

  /* Gain: '<S2>/Gain' incorporates:
   *  Sum: '<S2>/Add'
   */
  rtb_Gain = (rtb_Max + rty_duty_n_0) * -0.5F;

  /* Gain: '<S2>/Gain1' */
  rtb_Max *= -0.5F;

  /* Gain: '<S2>/Gain2' */
  rty_duty_n_0 *= -0.5F;

  /* MATLAB Function: '<S2>/MATLAB Function' */
  if (((rtb_Max > rty_duty_n_0) && (rtb_Max < rtb_Gain)) || ((rtb_Max > rtb_Gain)
       && (rtb_Max < rty_duty_n_0))) {
    rty_duty_n_0 = rtb_Max;
  } else if (((!(rty_duty_n_0 > rtb_Max)) || (!(rty_duty_n_0 < rtb_Gain))) && ((
               !(rty_duty_n_0 > rtb_Gain)) || (!(rty_duty_n_0 < rtb_Max)))) {
    rty_duty_n_0 = rtb_Gain;
  }

  /* End of MATLAB Function: '<S2>/MATLAB Function' */
  return rty_duty_n_0;
}

/* Output and update for atomic system: '<Root>/SVPWM' */
static void SVPWM_SVPWM(const real32_T rtu_u_abc[3], real32_T rtu_Vbus, real32_T
  rty_y_PWMA[3], real32_T *rty_duty_n)
{
  /* Outputs for Atomic SubSystem: '<S1>/eth3' */
  *rty_duty_n = SVPWM_eth3(rtu_u_abc);

  /* End of Outputs for SubSystem: '<S1>/eth3' */

  /* Gain: '<S1>/Gain1' incorporates:
   *  Constant: '<S1>/Constant'
   *  Product: '<S1>/Divide'
   *  Sum: '<S1>/Add'
   *  Sum: '<S1>/Add1'
   */
  rty_y_PWMA[0] = ((*rty_duty_n + rtu_u_abc[0]) / rtu_Vbus + 0.5F) * 3000.0F;
  rty_y_PWMA[1] = ((*rty_duty_n + rtu_u_abc[1]) / rtu_Vbus + 0.5F) * 3000.0F;
  rty_y_PWMA[2] = ((*rty_duty_n + rtu_u_abc[2]) / rtu_Vbus + 0.5F) * 3000.0F;

  /* Gain: '<S1>/Gain2' incorporates:
   *  Constant: '<S1>/Constant1'
   *  Product: '<S1>/Divide1'
   *  Sum: '<S1>/Add2'
   */
  *rty_duty_n = (*rty_duty_n / rtu_Vbus + 0.5F) * 3000.0F;
}

/* Model step function */
void SVPWM_step(RT_MODEL_SVPWM_T *const SVPWM_M, real32_T SVPWM_U_u_abc[3],
                real32_T SVPWM_U_Vbus, real32_T *SVPWM_Y_y_PWMA, real32_T
                *SVPWM_Y_y_PWMB, real32_T *SVPWM_Y_y_PWMC, real32_T
                *SVPWM_Y_duty_n)
{
  real32_T rtb_pwm_UVW[3];

  /* Outputs for Atomic SubSystem: '<Root>/SVPWM' */

  /* Inport: '<Root>/u_abc' incorporates:
   *  Inport: '<Root>/Vbus'
   *  Outport: '<Root>/duty_n'
   */
  SVPWM_SVPWM(SVPWM_U_u_abc, SVPWM_U_Vbus, rtb_pwm_UVW, SVPWM_Y_duty_n);

  /* End of Outputs for SubSystem: '<Root>/SVPWM' */

  /* Outport: '<Root>/y_PWMA' */
  *SVPWM_Y_y_PWMA = rtb_pwm_UVW[0];

  /* Outport: '<Root>/y_PWMB' */
  *SVPWM_Y_y_PWMB = rtb_pwm_UVW[1];

  /* Outport: '<Root>/y_PWMC' */
  *SVPWM_Y_y_PWMC = rtb_pwm_UVW[2];
  UNUSED_PARAMETER(SVPWM_M);
}

/* Model initialize function */
void SVPWM_initialize(RT_MODEL_SVPWM_T *const SVPWM_M, real32_T SVPWM_U_u_abc[3],
                      real32_T *SVPWM_U_Vbus, real32_T *SVPWM_Y_y_PWMA, real32_T
                      *SVPWM_Y_y_PWMB, real32_T *SVPWM_Y_y_PWMC, real32_T
                      *SVPWM_Y_duty_n)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(SVPWM_M, (NULL));

  /* external inputs */
  (void)memset(&SVPWM_U_u_abc[0], 0, 3U * sizeof(real32_T));
  *SVPWM_U_Vbus = 0.0F;

  /* external outputs */
  *SVPWM_Y_y_PWMA = 0.0F;
  *SVPWM_Y_y_PWMB = 0.0F;
  *SVPWM_Y_y_PWMC = 0.0F;
  *SVPWM_Y_duty_n = 0.0F;
  UNUSED_PARAMETER(SVPWM_M);
}

/* Model terminate function */
void SVPWM_terminate(RT_MODEL_SVPWM_T *const SVPWM_M)
{
  /* (no terminate code required) */
  UNUSED_PARAMETER(SVPWM_M);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
