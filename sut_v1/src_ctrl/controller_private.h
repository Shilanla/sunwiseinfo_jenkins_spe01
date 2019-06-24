/*
 * File: controller_private.h
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

#ifndef RTW_HEADER_controller_private_h_
#define RTW_HEADER_controller_private_h_
#include "rtwtypes.h"
#include "controller.h"

extern void OrbitDynamic_Init(const real_T rtu_u[3], const real_T rtu_u_a[3],
  DW_OrbitDynamic_T *localDW);
extern void OrbitDynamic(real_T rtu_u_b, real_T rty_u[3], real_T rty_u_a[3],
  DW_OrbitDynamic_T *localDW);
extern void controller_GyroChkValid_Init(uint32_T rty_idUsed[5],
  DW_GyroChkValid_controller_T *localDW);
extern void controller_GyroChkValid(const boolean_T rtu_bUse[6], uint32_T
  rty_idUsed[5], uint32_T *rty_numUsed, DW_GyroChkValid_controller_T *localDW);
extern void controller_GyroComptueDelta(const real_T rtu_gyroPls[6], const
  uint32_T rtu_gyroUsed[5], uint32_T rtu_gyroNum, const real_T rtu_IV_GYRO[18],
  real_T rty_dg[3], DW_GyroComptueDelta_controlle_T *localDW);
extern void ModeSwitch_Init(void);
extern void ModeSwitch_Enable(void);
extern void ModeSwitch(void);
extern void ProcessOrbit_Init(void);
extern void ProcessOrbit_Start(void);
extern void ProcessOrbit(void);
extern void ProcessGyroData_Init(void);
extern void ProcessGyroData(void);

#endif                                 /* RTW_HEADER_controller_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
