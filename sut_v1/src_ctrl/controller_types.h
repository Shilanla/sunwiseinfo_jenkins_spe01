/*
 * File: controller_types.h
 *
 * Code generated for Simulink model 'controller'.
 *
 * Model version                  : 1.614
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Fri Jan 18 14:15:50 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_controller_types_h_
#define RTW_HEADER_controller_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_controller_Chart_4_ModeType_
#define DEFINED_TYPEDEF_FOR_controller_Chart_4_ModeType_

typedef enum {
  controller_Chart_4_ModeType_None = 0,/* Default value */
  controller_Chart_4_ModeType_normal,
  controller_Chart_4_ModeType_safe,
  controller_Chart_4_ModeType_fixedQ,
  controller_Chart_4_ModeType_safeTwice,
  controller_Chart_4_ModeType_pause,
  controller_Chart_4_ModeType_stop
} controller_Chart_4_ModeType;

#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_controller_T RT_MODEL_controller_T;

#endif                                 /* RTW_HEADER_controller_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
