/*
 * File: modeImpl.h
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

#ifndef RTW_HEADER_modeImpl_h_
#define RTW_HEADER_modeImpl_h_
#include <math.h>
#ifndef controller_COMMON_INCLUDES_
# define controller_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* controller_COMMON_INCLUDES_ */

#include "controller_types.h"

extern void ComputeExpectQ(const real_T rtu_angle[3], real_T rty_cbo[9]);
extern void controller_ComputeCbi(const real_T rtu_cbo[9], const real_T rtu_coi
  [9], real_T rty_cbi[9]);
extern void controller_ComputeQbi(const real_T rtu_cbi[9], real_T rty_qbi[4]);
extern void TransferAngleOrbit(const real_T rtu_qbi[4], const real_T rtu_coi[9],
  real_T rty_angle[3]);
extern void CtrlPlan_Init(void);
extern void CtrlPlan(void);
extern void ComputeErrQ_Init(void);
extern void ComputeErrQ(void);
extern void CtrlStop(void);
extern void CtrlSafeOmg_Reset(void);
extern void CtrlSafeOmg_Enable(void);
extern void CtrlSafeOmg(void);
extern void CtrlNormal_Reset(void);
extern void CtrlNormal_Enable(void);
extern void CtrlNormal(void);
extern void CtrlInertiaQ_Reset(void);
extern void CtrlInertiaQ_Enable(void);
extern void CtrlInertiaQ(void);

#endif                                 /* RTW_HEADER_modeImpl_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
