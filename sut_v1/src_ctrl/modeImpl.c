/*
 * File: modeImpl.c
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

#include "modeImpl.h"

/* Include model header file for global data */
#include "controller.h"
#include "controller_private.h"

/* Named constants for Chart: '<S6>/控制目标规划' */
#define controller_IN_s0               ((uint8_T)1U)
#define controller_IN_s1               ((uint8_T)2U)

/* Forward declaration for local functions */
static void controller_ComputeST(const real_T t1[4], const real_T m1[4], real_T
  st[4], boolean_T *bBound);

/* Function for Chart: '<S6>/控制目标规划' */
static void controller_ComputeST(const real_T t1[4], const real_T m1[4], real_T
  st[4], boolean_T *bBound)
{
  real_T qNorm;
  real_T st_0;
  *bBound = false;
  st_0 = t1[0] - m1[0];
  if (st_0 > 0.1) {
    st_0 = 0.1;
    *bBound = true;
  } else {
    if (st_0 < -0.1) {
      st_0 = -0.1;
      *bBound = true;
    }
  }

  st_0 += m1[0];
  qNorm = st_0 * st_0;
  st[0] = st_0;
  st_0 = t1[1] - m1[1];
  if (st_0 > 0.1) {
    st_0 = 0.1;
    *bBound = true;
  } else {
    if (st_0 < -0.1) {
      st_0 = -0.1;
      *bBound = true;
    }
  }

  st_0 += m1[1];
  qNorm += st_0 * st_0;
  st[1] = st_0;
  st_0 = t1[2] - m1[2];
  if (st_0 > 0.1) {
    st_0 = 0.1;
    *bBound = true;
  } else {
    if (st_0 < -0.1) {
      st_0 = -0.1;
      *bBound = true;
    }
  }

  st_0 += m1[2];
  qNorm += st_0 * st_0;
  st[2] = st_0;
  st_0 = t1[3] - m1[3];
  if (st_0 > 0.1) {
    st_0 = 0.1;
    *bBound = true;
  } else {
    if (st_0 < -0.1) {
      st_0 = -0.1;
      *bBound = true;
    }
  }

  st_0 += m1[3];
  qNorm += st_0 * st_0;
  qNorm = sqrt(qNorm);
  if (qNorm > 1.0E-7) {
    st[0] /= qNorm;
    st[1] /= qNorm;
    st[2] /= qNorm;
    st[3] = st_0 / qNorm;
  } else {
    st[0] = 0.0;
    st[1] = 0.0;
    st[2] = 0.0;
    st[3] = 1.0;
  }
}

/* System initialize for atomic system: '<S6>/控制目标规划' */
void CtrlPlan_Init(void)
{
  controller_DW.waitTime = 200.0;
}

/* Output and update for atomic system: '<S6>/控制目标规划' */
void CtrlPlan(void)
{
  boolean_T bb;

  /* Chart: '<S6>/控制目标规划' incorporates:
   *  Inport: '<Root>/测量四元数'
   */
  if (controller_DW.temporalCounter_i1 < MAX_uint32_T) {
    controller_DW.temporalCounter_i1++;
  }

  if (controller_DW.is_active_c2_controller == 0U) {
    controller_DW.is_active_c2_controller = 1U;
    controller_DW.sT[0] = 0.0;
    controller_DW.sT[1] = 0.0;
    controller_DW.sT[2] = 0.0;
    controller_DW.sT[3] = 1.0;
    controller_DW.is_c2_controller = controller_IN_s0;
    controller_DW.temporalCounter_i1 = 0U;
  } else if (controller_DW.is_c2_controller == controller_IN_s0) {
    if (controller_DW.temporalCounter_i1 >= 2U) {
      controller_DW.is_c2_controller = controller_IN_s1;
      controller_DW.temporalCounter_i1 = 0U;
      controller_ComputeST(controller_B.qbi, ctrlInSensorQ, controller_DW.sT,
                           &bb);
      if (bb) {
        controller_DW.waitTime = 1562.0;
      } else {
        controller_DW.waitTime = 781.0;
      }
    } else {
      controller_B.expected[0] = controller_DW.sT[0];
      controller_B.expected[1] = controller_DW.sT[1];
      controller_B.expected[2] = controller_DW.sT[2];
      controller_B.expected[3] = controller_DW.sT[3];
    }
  } else if (controller_DW.temporalCounter_i1 >= (uint32_T)
             controller_DW.waitTime) {
    controller_DW.is_c2_controller = controller_IN_s1;
    controller_DW.temporalCounter_i1 = 0U;
    controller_ComputeST(controller_B.qbi, ctrlInSensorQ, controller_DW.sT, &bb);
    if (bb) {
      controller_DW.waitTime = 1562.0;
    } else {
      controller_DW.waitTime = 781.0;
    }
  } else {
    controller_B.expected[0] = controller_DW.sT[0];
    controller_B.expected[1] = controller_DW.sT[1];
    controller_B.expected[2] = controller_DW.sT[2];
    controller_B.expected[3] = controller_DW.sT[3];
  }

  /* End of Chart: '<S6>/控制目标规划' */
}

/* Output and update for atomic system: '<S12>/Angle2Cbo' */
void ComputeExpectQ(const real_T rtu_angle[3], real_T rty_cbo[9])
{
  real_T tmpCosz;
  real_T tmpSinz;
  real_T tmpCosx;
  real_T tmpSinx;
  real_T tmpCosy;
  real_T tmpSiny;
  static const int8_T b[3] = { 0, 0, 1 };

  real_T tmpCosy_0[9];
  real_T d[9];
  real_T tmpCosy_1[9];
  real_T tmpCosz_0[9];
  int32_T i;
  int32_T i_0;
  int32_T tmpCosy_tmp;
  int32_T tmpCosy_tmp_0;
  tmpCosz = cos(rtu_angle[0]);
  tmpSinz = sin(rtu_angle[0]);
  tmpCosx = cos(rtu_angle[1]);
  tmpSinx = sin(rtu_angle[1]);
  tmpCosy = cos(rtu_angle[2]);
  tmpSiny = sin(rtu_angle[2]);
  tmpCosy_0[0] = tmpCosy;
  tmpCosy_0[3] = 0.0;
  tmpCosy_0[6] = -tmpSiny;
  tmpCosy_0[2] = tmpSiny;
  tmpCosy_0[5] = 0.0;
  tmpCosy_0[8] = tmpCosy;
  tmpCosy_0[1] = 0.0;
  d[0] = 1.0;
  tmpCosy_0[4] = 1.0;
  d[3] = 0.0;
  tmpCosy_0[7] = 0.0;
  d[6] = 0.0;
  d[1] = 0.0;
  d[4] = tmpCosx;
  d[7] = tmpSinx;
  d[2] = 0.0;
  d[5] = -tmpSinx;
  d[8] = tmpCosx;
  tmpCosz_0[0] = tmpCosz;
  tmpCosz_0[3] = tmpSinz;
  tmpCosz_0[6] = 0.0;
  tmpCosz_0[1] = -tmpSinz;
  tmpCosz_0[4] = tmpCosz;
  tmpCosz_0[7] = 0.0;
  for (i = 0; i < 3; i++) {
    for (i_0 = 0; i_0 < 3; i_0++) {
      tmpCosy_tmp = i + 3 * i_0;
      tmpCosy_1[tmpCosy_tmp] = 0.0;
      tmpCosy_tmp_0 = 3 * i_0 + i;
      tmpCosy_1[tmpCosy_tmp] = tmpCosy_1[tmpCosy_tmp_0] + d[3 * i_0] *
        tmpCosy_0[i];
      tmpCosy_1[tmpCosy_tmp] = d[3 * i_0 + 1] * tmpCosy_0[i + 3] +
        tmpCosy_1[tmpCosy_tmp_0];
      tmpCosy_1[tmpCosy_tmp] = d[3 * i_0 + 2] * tmpCosy_0[i + 6] +
        tmpCosy_1[tmpCosy_tmp_0];
    }

    tmpCosz_0[2 + 3 * i] = b[i];
  }

  for (i = 0; i < 3; i++) {
    for (i_0 = 0; i_0 < 3; i_0++) {
      tmpCosy_tmp = i_0 + 3 * i;
      rty_cbo[tmpCosy_tmp] = 0.0;
      tmpCosy_tmp_0 = 3 * i + i_0;
      rty_cbo[tmpCosy_tmp] = rty_cbo[tmpCosy_tmp_0] + tmpCosz_0[3 * i] *
        tmpCosy_1[i_0];
      rty_cbo[tmpCosy_tmp] = tmpCosz_0[3 * i + 1] * tmpCosy_1[i_0 + 3] +
        rty_cbo[tmpCosy_tmp_0];
      rty_cbo[tmpCosy_tmp] = tmpCosz_0[3 * i + 2] * tmpCosy_1[i_0 + 6] +
        rty_cbo[tmpCosy_tmp_0];
    }
  }
}

/* Output and update for atomic system: '<S12>/ComputeCbi' */
void controller_ComputeCbi(const real_T rtu_cbo[9], const real_T rtu_coi[9],
  real_T rty_cbi[9])
{
  int32_T i;
  int32_T i_0;
  int32_T tmp;
  int32_T tmp_0;
  for (i = 0; i < 3; i++) {
    for (i_0 = 0; i_0 < 3; i_0++) {
      tmp = i + 3 * i_0;
      rty_cbi[tmp] = 0.0;
      tmp_0 = 3 * i_0 + i;
      rty_cbi[tmp] = rty_cbi[tmp_0] + rtu_coi[3 * i] * rtu_cbo[3 * i_0];
      rty_cbi[tmp] = rtu_coi[3 * i + 1] * rtu_cbo[3 * i_0 + 1] + rty_cbi[tmp_0];
      rty_cbi[tmp] = rtu_coi[3 * i + 2] * rtu_cbo[3 * i_0 + 2] + rty_cbi[tmp_0];
    }
  }
}

/* Output and update for atomic system: '<S12>/ComputeQbi' */
void controller_ComputeQbi(const real_T rtu_cbi[9], real_T rty_qbi[4])
{
  real_T a44;
  real_T b22;
  real_T c11;
  int32_T rtu_cbi_0;
  a44 = ((1.0 + rtu_cbi[0]) + rtu_cbi[4]) + rtu_cbi[8];
  b22 = ((1.0 - rtu_cbi[0]) + rtu_cbi[4]) - rtu_cbi[8];
  c11 = ((1.0 + rtu_cbi[0]) - rtu_cbi[4]) - rtu_cbi[8];
  if (a44 > 0.004) {
    b22 = sqrt(a44) / 2.0;
    rty_qbi[0] = (rtu_cbi[7] - rtu_cbi[5]) * 0.25 / b22;
    rty_qbi[1] = (rtu_cbi[2] - rtu_cbi[6]) * 0.25 / b22;
    rty_qbi[2] = (rtu_cbi[3] - rtu_cbi[1]) * 0.25 / b22;
    rty_qbi[3] = b22;
  } else if (b22 > 0.004) {
    a44 = rtu_cbi[2] - rtu_cbi[6];
    if (a44 < 0.0) {
      rtu_cbi_0 = -1;
    } else {
      rtu_cbi_0 = 1;
    }

    b22 = sqrt(b22) / 2.0 * (real_T)rtu_cbi_0;
    rty_qbi[0] = (rtu_cbi[1] + rtu_cbi[3]) * 0.25 / b22;
    rty_qbi[1] = b22;
    rty_qbi[2] = (rtu_cbi[5] + rtu_cbi[7]) * 0.25 / b22;
    rty_qbi[3] = a44 * 0.25 / b22;
  } else if (c11 > 0.004) {
    a44 = rtu_cbi[7] - rtu_cbi[5];
    if (a44 < 0.0) {
      rtu_cbi_0 = -1;
    } else {
      rtu_cbi_0 = 1;
    }

    b22 = sqrt(c11) / 2.0 * (real_T)rtu_cbi_0;
    rty_qbi[0] = b22;
    rty_qbi[1] = (rtu_cbi[1] + rtu_cbi[3]) * 0.25 / b22;
    rty_qbi[2] = (rtu_cbi[6] + rtu_cbi[2]) * 0.25 / b22;
    rty_qbi[3] = a44 * 0.25 / b22;
  } else {
    a44 = rtu_cbi[3] - rtu_cbi[1];
    if (a44 < 0.0) {
      rtu_cbi_0 = -1;
    } else {
      rtu_cbi_0 = 1;
    }

    b22 = sqrt(((1.0 - rtu_cbi[0]) - rtu_cbi[4]) + rtu_cbi[8]) / 2.0 * (real_T)
      rtu_cbi_0;
    rty_qbi[0] = (rtu_cbi[6] + rtu_cbi[2]) * 0.25 / b22;
    rty_qbi[1] = (rtu_cbi[7] + rtu_cbi[5]) * 0.25 / b22;
    rty_qbi[2] = b22;
    rty_qbi[3] = a44 * 0.25 / b22;
  }

  b22 = sqrt(((rty_qbi[0] * rty_qbi[0] + rty_qbi[1] * rty_qbi[1]) + rty_qbi[2] *
              rty_qbi[2]) + rty_qbi[3] * rty_qbi[3]);
  if (b22 > 1.0E-7) {
    rty_qbi[0] /= b22;
    rty_qbi[1] /= b22;
    rty_qbi[2] /= b22;
    rty_qbi[3] /= b22;
  } else {
    rty_qbi[0] = 0.0;
    rty_qbi[1] = 0.0;
    rty_qbi[2] = 0.0;
    rty_qbi[3] = 1.0;
  }
}

/* Output and update for atomic system: '<S6>/转换为轨道系姿态角' */
void TransferAngleOrbit(const real_T rtu_qbi[4], const real_T rtu_coi[9], real_T
  rty_angle[3])
{
  real_T cbo[9];
  real_T tmp[9];
  int32_T i;
  int32_T i_0;
  real_T tmp_0;
  real_T tmp_1;
  real_T tmp_2;
  real_T tmp_3;
  real_T tmp_4;
  real_T tmp_5;
  int32_T cbo_tmp;
  int32_T cbo_tmp_0;
  tmp_2 = 2.0 * rtu_qbi[2] * rtu_qbi[2];
  tmp_5 = 2.0 * rtu_qbi[1] * rtu_qbi[1];
  tmp[0] = (1.0 - tmp_5) - tmp_2;
  tmp_0 = 2.0 * rtu_qbi[0] * rtu_qbi[1];
  tmp_1 = 2.0 * rtu_qbi[2] * rtu_qbi[3];
  tmp[3] = tmp_0 + tmp_1;
  tmp_3 = 2.0 * rtu_qbi[0] * rtu_qbi[2];
  tmp_4 = 2.0 * rtu_qbi[1] * rtu_qbi[3];
  tmp[6] = tmp_3 - tmp_4;
  tmp[1] = tmp_0 - tmp_1;
  tmp_0 = 1.0 - 2.0 * rtu_qbi[0] * rtu_qbi[0];
  tmp[4] = tmp_0 - tmp_2;
  tmp_2 = 2.0 * rtu_qbi[1] * rtu_qbi[2];
  tmp_1 = 2.0 * rtu_qbi[0] * rtu_qbi[3];
  tmp[7] = tmp_2 + tmp_1;
  tmp[2] = tmp_3 + tmp_4;
  tmp[5] = tmp_2 - tmp_1;
  tmp[8] = tmp_0 - tmp_5;
  for (i_0 = 0; i_0 < 3; i_0++) {
    for (i = 0; i < 3; i++) {
      cbo_tmp = i + 3 * i_0;
      cbo[cbo_tmp] = 0.0;
      cbo_tmp_0 = 3 * i_0 + i;
      cbo[cbo_tmp] = cbo[cbo_tmp_0] + rtu_coi[3 * i_0] * tmp[i];
      cbo[cbo_tmp] = rtu_coi[3 * i_0 + 1] * tmp[i + 3] + cbo[cbo_tmp_0];
      cbo[cbo_tmp] = rtu_coi[3 * i_0 + 2] * tmp[i + 6] + cbo[cbo_tmp_0];
    }
  }

  rty_angle[0] = asin(cbo[7]);
  rty_angle[1] = atan2(cbo[6], cbo[8]);
  rty_angle[2] = atan2(cbo[1], cbo[4]);
}

/* System initialize for atomic system: '<S1>/四元数误差计算' */
void ComputeErrQ_Init(void)
{
  /* SystemInitialize for Chart: '<S6>/控制目标规划' */
  CtrlPlan_Init();
}

/* Output and update for atomic system: '<S1>/四元数误差计算' */
void ComputeErrQ(void)
{
  real_T rtb_cbo[9];
  real_T rtb_cbi[9];

  /* Outputs for Atomic SubSystem: '<S6>/计算预期的惯性系四元数' */

  /* MATLAB Function: '<S12>/Angle2Cbo' incorporates:
   *  Inport: '<Root>/预期轨道系姿态角'
   */
  ComputeExpectQ(ctrlInCmdOmg, rtb_cbo);

  /* MATLAB Function: '<S12>/ComputeCbi' */
  controller_ComputeCbi(rtb_cbo, controller_B.COI, rtb_cbi);

  /* MATLAB Function: '<S12>/ComputeQbi' */
  controller_ComputeQbi(rtb_cbi, controller_B.qbi);

  /* End of Outputs for SubSystem: '<S6>/计算预期的惯性系四元数' */

  /* Chart: '<S6>/控制目标规划' */
  CtrlPlan();

  /* Sum: '<S6>/控制误差计算' incorporates:
   *  Inport: '<Root>/测量四元数'
   */
  controller_B.u_h[0] = controller_B.expected[0] - ctrlInSensorQ[0];
  controller_B.u_h[1] = controller_B.expected[1] - ctrlInSensorQ[1];
  controller_B.u_h[2] = controller_B.expected[2] - ctrlInSensorQ[2];
  controller_B.u_h[3] = controller_B.expected[3] - ctrlInSensorQ[3];

  /* SignalConversion: '<S6>/TmpSignal ConversionAt转换为轨道系姿态角Outport1' incorporates:
   *  Inport: '<Root>/测量四元数'
   *  MATLAB Function: '<S6>/转换为轨道系姿态角'
   */
  TransferAngleOrbit(ctrlInSensorQ, controller_B.COI, ctrlAngle);
}

/* Output and update for function-call system: '<S1>/停控模式' */
void CtrlStop(void)
{
  /* SignalConversion: '<S5>/OutportBuffer_InsertedFor_控制量_at_inport_0' */
  ctrlOutM[0] = 0.0;
  ctrlOutM[1] = 0.0;
  ctrlOutM[2] = 0.0;
}

/* System reset for function-call system: '<S1>/安全角速度控制' */
void CtrlSafeOmg_Reset(void)
{
  /* InitializeConditions for DiscreteIntegrator: '<S347>/Filter' */
  controller_DW.Filter_DSTATE_f = 0.0;
  controller_DW.Filter_PREV_U_pl = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S365>/Integrator' */
  controller_DW.Integrator_DSTATE_m = 0.0;
  controller_DW.Integrator_PREV_U_aw = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S443>/Filter' */
  controller_DW.Filter_DSTATE_oe = 0.0;
  controller_DW.Filter_PREV_U_pw = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S461>/Integrator' */
  controller_DW.Integrator_DSTATE_n = 0.0;
  controller_DW.Integrator_PREV_U_a4 = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S539>/Filter' */
  controller_DW.Filter_DSTATE_oz = 0.0;
  controller_DW.Filter_PREV_U_lz = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S557>/Integrator' */
  controller_DW.Integrator_DSTATE_p = 0.0;
  controller_DW.Integrator_PREV_U_pc = 0.0;
}

/* Enable for function-call system: '<S1>/安全角速度控制' */
void CtrlSafeOmg_Enable(void)
{
  controller_DW._RESET_ELAPS_T_l = true;

  /* Enable for DiscreteIntegrator: '<S347>/Filter' */
  controller_DW.Filter_SYSTEM_ENABLE_c = 1U;

  /* Enable for DiscreteIntegrator: '<S365>/Integrator' */
  controller_DW.Integrator_SYSTEM_ENABLE_o = 1U;

  /* Enable for DiscreteIntegrator: '<S443>/Filter' */
  controller_DW.Filter_SYSTEM_ENABLE_h = 1U;

  /* Enable for DiscreteIntegrator: '<S461>/Integrator' */
  controller_DW.Integrator_SYSTEM_ENABLE_oz = 1U;

  /* Enable for DiscreteIntegrator: '<S539>/Filter' */
  controller_DW.Filter_SYSTEM_ENABLE_ck = 1U;

  /* Enable for DiscreteIntegrator: '<S557>/Integrator' */
  controller_DW.Integrator_SYSTEM_ENABLE_i = 1U;
}

/* Output and update for function-call system: '<S1>/安全角速度控制' */
void CtrlSafeOmg(void)
{
  real_T rtb_FilterCoefficient;
  real_T rtb_FilterCoefficient_oq;
  real_T rtb_FilterCoefficient_c;
  uint32_T _ELAPS_T_m;
  real_T u0;
  if (controller_DW._RESET_ELAPS_T_l) {
    _ELAPS_T_m = 0U;
  } else {
    _ELAPS_T_m = controller_M->Timing.clockTick0 - controller_DW._PREV_T_o;
  }

  controller_DW._PREV_T_o = controller_M->Timing.clockTick0;
  controller_DW._RESET_ELAPS_T_l = false;

  /* DiscreteIntegrator: '<S347>/Filter' */
  if (controller_DW.Filter_SYSTEM_ENABLE_c == 0) {
    controller_DW.Filter_DSTATE_f += 0.064 * (real_T)_ELAPS_T_m *
      controller_DW.Filter_PREV_U_pl;
  }

  /* End of DiscreteIntegrator: '<S347>/Filter' */

  /* Gain: '<S375>/Filter Coefficient' incorporates:
   *  Gain: '<S342>/Derivative Gain'
   *  Sum: '<S347>/SumD'
   *  Sum: '<S8>/误差计算'
   */
  rtb_FilterCoefficient = ((0.0 - ctrlOmg[0]) * 3.71002488048789 -
    controller_DW.Filter_DSTATE_f) * 1.16752880511307;

  /* DiscreteIntegrator: '<S365>/Integrator' */
  if (controller_DW.Integrator_SYSTEM_ENABLE_o == 0) {
    controller_DW.Integrator_DSTATE_m += 0.064 * (real_T)_ELAPS_T_m *
      controller_DW.Integrator_PREV_U_aw;
  }

  /* End of DiscreteIntegrator: '<S365>/Integrator' */

  /* Sum: '<S395>/Sum' incorporates:
   *  Gain: '<S382>/Proportional Gain'
   *  Sum: '<S8>/误差计算'
   */
  u0 = ((0.0 - ctrlOmg[0]) * 5.49680225814349 +
        controller_DW.Integrator_DSTATE_m) + rtb_FilterCoefficient;

  /* Saturate: '<S386>/Saturation' */
  if (u0 > 0.5) {
    ctrlOutM[0] = 0.5;
  } else if (u0 < -0.5) {
    ctrlOutM[0] = -0.5;
  } else {
    ctrlOutM[0] = u0;
  }

  /* End of Saturate: '<S386>/Saturation' */

  /* DiscreteIntegrator: '<S443>/Filter' */
  if (controller_DW.Filter_SYSTEM_ENABLE_h == 0) {
    controller_DW.Filter_DSTATE_oe += 0.064 * (real_T)_ELAPS_T_m *
      controller_DW.Filter_PREV_U_pw;
  }

  /* End of DiscreteIntegrator: '<S443>/Filter' */

  /* Gain: '<S471>/Filter Coefficient' incorporates:
   *  Gain: '<S438>/Derivative Gain'
   *  Sum: '<S443>/SumD'
   *  Sum: '<S8>/误差计算'
   */
  rtb_FilterCoefficient_oq = ((0.0 - ctrlOmg[1]) * 3.71002488048789 -
    controller_DW.Filter_DSTATE_oe) * 1.16752880511307;

  /* DiscreteIntegrator: '<S461>/Integrator' */
  if (controller_DW.Integrator_SYSTEM_ENABLE_oz == 0) {
    controller_DW.Integrator_DSTATE_n += 0.064 * (real_T)_ELAPS_T_m *
      controller_DW.Integrator_PREV_U_a4;
  }

  /* End of DiscreteIntegrator: '<S461>/Integrator' */

  /* Sum: '<S491>/Sum' incorporates:
   *  Gain: '<S478>/Proportional Gain'
   *  Sum: '<S8>/误差计算'
   */
  u0 = ((0.0 - ctrlOmg[1]) * 5.49680225814349 +
        controller_DW.Integrator_DSTATE_n) + rtb_FilterCoefficient_oq;

  /* Saturate: '<S482>/Saturation' */
  if (u0 > 0.5) {
    ctrlOutM[1] = 0.5;
  } else if (u0 < -0.5) {
    ctrlOutM[1] = -0.5;
  } else {
    ctrlOutM[1] = u0;
  }

  /* End of Saturate: '<S482>/Saturation' */

  /* DiscreteIntegrator: '<S539>/Filter' */
  if (controller_DW.Filter_SYSTEM_ENABLE_ck == 0) {
    controller_DW.Filter_DSTATE_oz += 0.064 * (real_T)_ELAPS_T_m *
      controller_DW.Filter_PREV_U_lz;
  }

  /* End of DiscreteIntegrator: '<S539>/Filter' */

  /* Gain: '<S567>/Filter Coefficient' incorporates:
   *  Gain: '<S534>/Derivative Gain'
   *  Sum: '<S539>/SumD'
   *  Sum: '<S8>/误差计算'
   */
  rtb_FilterCoefficient_c = ((0.0 - ctrlOmg[2]) * 2.9680199043946 -
    controller_DW.Filter_DSTATE_oz) * 1.16752880511307;

  /* DiscreteIntegrator: '<S557>/Integrator' */
  if (controller_DW.Integrator_SYSTEM_ENABLE_i == 0) {
    controller_DW.Integrator_DSTATE_p += 0.064 * (real_T)_ELAPS_T_m *
      controller_DW.Integrator_PREV_U_pc;
  }

  /* End of DiscreteIntegrator: '<S557>/Integrator' */

  /* Sum: '<S587>/Sum' incorporates:
   *  Gain: '<S574>/Proportional Gain'
   *  Sum: '<S8>/误差计算'
   */
  u0 = ((0.0 - ctrlOmg[2]) * 4.39744180652115 +
        controller_DW.Integrator_DSTATE_p) + rtb_FilterCoefficient_c;

  /* Saturate: '<S578>/Saturation' */
  if (u0 > 0.5) {
    ctrlOutM[2] = 0.5;
  } else if (u0 < -0.5) {
    ctrlOutM[2] = -0.5;
  } else {
    ctrlOutM[2] = u0;
  }

  /* End of Saturate: '<S578>/Saturation' */

  /* Update for DiscreteIntegrator: '<S347>/Filter' */
  controller_DW.Filter_SYSTEM_ENABLE_c = 0U;
  controller_DW.Filter_PREV_U_pl = rtb_FilterCoefficient;

  /* Update for DiscreteIntegrator: '<S365>/Integrator' incorporates:
   *  Gain: '<S355>/Integral Gain'
   *  Sum: '<S8>/误差计算'
   */
  controller_DW.Integrator_SYSTEM_ENABLE_o = 0U;
  controller_DW.Integrator_PREV_U_aw = (0.0 - ctrlOmg[0]) * 0.320036545501622;

  /* Update for DiscreteIntegrator: '<S443>/Filter' */
  controller_DW.Filter_SYSTEM_ENABLE_h = 0U;
  controller_DW.Filter_PREV_U_pw = rtb_FilterCoefficient_oq;

  /* Update for DiscreteIntegrator: '<S461>/Integrator' incorporates:
   *  Gain: '<S451>/Integral Gain'
   *  Sum: '<S8>/误差计算'
   */
  controller_DW.Integrator_SYSTEM_ENABLE_oz = 0U;
  controller_DW.Integrator_PREV_U_a4 = (0.0 - ctrlOmg[1]) * 0.320036545501622;

  /* Update for DiscreteIntegrator: '<S539>/Filter' */
  controller_DW.Filter_SYSTEM_ENABLE_ck = 0U;
  controller_DW.Filter_PREV_U_lz = rtb_FilterCoefficient_c;

  /* Update for DiscreteIntegrator: '<S557>/Integrator' incorporates:
   *  Gain: '<S547>/Integral Gain'
   *  Sum: '<S8>/误差计算'
   */
  controller_DW.Integrator_SYSTEM_ENABLE_i = 0U;
  controller_DW.Integrator_PREV_U_pc = (0.0 - ctrlOmg[2]) * 0.256029236401668;
}

/* System reset for function-call system: '<S1>/姿态角控制' */
void CtrlNormal_Reset(void)
{
  /* InitializeConditions for DiscreteIntegrator: '<S56>/Filter' */
  controller_DW.Filter_DSTATE_b = 0.0;
  controller_DW.Filter_PREV_U_b = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S74>/Integrator' */
  controller_DW.Integrator_DSTATE_dy = 0.0;
  controller_DW.Integrator_PREV_U_k = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S152>/Filter' */
  controller_DW.Filter_DSTATE_j = 0.0;
  controller_DW.Filter_PREV_U_l = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S170>/Integrator' */
  controller_DW.Integrator_DSTATE_g = 0.0;
  controller_DW.Integrator_PREV_U_p = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S248>/Filter' */
  controller_DW.Filter_DSTATE_m = 0.0;
  controller_DW.Filter_PREV_U_c = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S266>/Integrator' */
  controller_DW.Integrator_DSTATE_o = 0.0;
  controller_DW.Integrator_PREV_U_b = 0.0;
}

/* Enable for function-call system: '<S1>/姿态角控制' */
void CtrlNormal_Enable(void)
{
  controller_DW._RESET_ELAPS_T_j = true;

  /* Enable for DiscreteIntegrator: '<S56>/Filter' */
  controller_DW.Filter_SYSTEM_ENABLE_i = 1U;

  /* Enable for DiscreteIntegrator: '<S74>/Integrator' */
  controller_DW.Integrator_SYSTEM_ENABLE_a = 1U;

  /* Enable for DiscreteIntegrator: '<S152>/Filter' */
  controller_DW.Filter_SYSTEM_ENABLE_pa = 1U;

  /* Enable for DiscreteIntegrator: '<S170>/Integrator' */
  controller_DW.Integrator_SYSTEM_ENABLE_j = 1U;

  /* Enable for DiscreteIntegrator: '<S248>/Filter' */
  controller_DW.Filter_SYSTEM_ENABLE_f = 1U;

  /* Enable for DiscreteIntegrator: '<S266>/Integrator' */
  controller_DW.Integrator_SYSTEM_ENABLE_go = 1U;
}

/* Output and update for function-call system: '<S1>/姿态角控制' */
void CtrlNormal(void)
{
  real_T rtb_FilterCoefficient;
  real_T rtb_FilterCoefficient_j;
  real_T rtb_FilterCoefficient_go;
  uint32_T _ELAPS_T_i;
  real_T u0;
  if (controller_DW._RESET_ELAPS_T_j) {
    _ELAPS_T_i = 0U;
  } else {
    _ELAPS_T_i = controller_M->Timing.clockTick0 - controller_DW._PREV_T_p;
  }

  controller_DW._PREV_T_p = controller_M->Timing.clockTick0;
  controller_DW._RESET_ELAPS_T_j = false;

  /* DiscreteIntegrator: '<S56>/Filter' */
  if (controller_DW.Filter_SYSTEM_ENABLE_i == 0) {
    controller_DW.Filter_DSTATE_b += 0.064 * (real_T)_ELAPS_T_i *
      controller_DW.Filter_PREV_U_b;
  }

  /* End of DiscreteIntegrator: '<S56>/Filter' */

  /* Gain: '<S84>/Filter Coefficient' incorporates:
   *  Gain: '<S51>/Derivative Gain'
   *  Sum: '<S56>/SumD'
   */
  rtb_FilterCoefficient = (320.501340777763 * controller_B.u_h[0] -
    controller_DW.Filter_DSTATE_b) * 3.13827171021481;

  /* DiscreteIntegrator: '<S74>/Integrator' */
  if (controller_DW.Integrator_SYSTEM_ENABLE_a == 0) {
    controller_DW.Integrator_DSTATE_dy += 0.064 * (real_T)_ELAPS_T_i *
      controller_DW.Integrator_PREV_U_k;
  }

  /* End of DiscreteIntegrator: '<S74>/Integrator' */

  /* Sum: '<S104>/Sum' incorporates:
   *  Gain: '<S91>/Proportional Gain'
   */
  u0 = (26.2700961628852 * controller_B.u_h[0] +
        controller_DW.Integrator_DSTATE_dy) + rtb_FilterCoefficient;

  /* Saturate: '<S95>/Saturation' */
  if (u0 > 0.5) {
    ctrlOutM[0] = 0.5;
  } else if (u0 < -0.5) {
    ctrlOutM[0] = -0.5;
  } else {
    ctrlOutM[0] = u0;
  }

  /* End of Saturate: '<S95>/Saturation' */

  /* DiscreteIntegrator: '<S152>/Filter' */
  if (controller_DW.Filter_SYSTEM_ENABLE_pa == 0) {
    controller_DW.Filter_DSTATE_j += 0.064 * (real_T)_ELAPS_T_i *
      controller_DW.Filter_PREV_U_l;
  }

  /* End of DiscreteIntegrator: '<S152>/Filter' */

  /* Gain: '<S180>/Filter Coefficient' incorporates:
   *  Gain: '<S147>/Derivative Gain'
   *  Sum: '<S152>/SumD'
   */
  rtb_FilterCoefficient_j = (320.501350780946 * controller_B.u_h[1] -
    controller_DW.Filter_DSTATE_j) * 3.13827171021481;

  /* DiscreteIntegrator: '<S170>/Integrator' */
  if (controller_DW.Integrator_SYSTEM_ENABLE_j == 0) {
    controller_DW.Integrator_DSTATE_g += 0.064 * (real_T)_ELAPS_T_i *
      controller_DW.Integrator_PREV_U_p;
  }

  /* End of DiscreteIntegrator: '<S170>/Integrator' */

  /* Sum: '<S200>/Sum' incorporates:
   *  Gain: '<S187>/Proportional Gain'
   */
  u0 = (26.2700933216504 * controller_B.u_h[1] +
        controller_DW.Integrator_DSTATE_g) + rtb_FilterCoefficient_j;

  /* Saturate: '<S191>/Saturation' */
  if (u0 > 0.5) {
    ctrlOutM[1] = 0.5;
  } else if (u0 < -0.5) {
    ctrlOutM[1] = -0.5;
  } else {
    ctrlOutM[1] = u0;
  }

  /* End of Saturate: '<S191>/Saturation' */

  /* DiscreteIntegrator: '<S248>/Filter' */
  if (controller_DW.Filter_SYSTEM_ENABLE_f == 0) {
    controller_DW.Filter_DSTATE_m += 0.064 * (real_T)_ELAPS_T_i *
      controller_DW.Filter_PREV_U_c;
  }

  /* End of DiscreteIntegrator: '<S248>/Filter' */

  /* Gain: '<S276>/Filter Coefficient' incorporates:
   *  Gain: '<S243>/Derivative Gain'
   *  Sum: '<S248>/SumD'
   */
  rtb_FilterCoefficient_go = (256.401073137961 * controller_B.u_h[2] -
    controller_DW.Filter_DSTATE_m) * 3.13827171021481;

  /* DiscreteIntegrator: '<S266>/Integrator' */
  if (controller_DW.Integrator_SYSTEM_ENABLE_go == 0) {
    controller_DW.Integrator_DSTATE_o += 0.064 * (real_T)_ELAPS_T_i *
      controller_DW.Integrator_PREV_U_b;
  }

  /* End of DiscreteIntegrator: '<S266>/Integrator' */

  /* Sum: '<S296>/Sum' incorporates:
   *  Gain: '<S283>/Proportional Gain'
   */
  u0 = (21.0160761602212 * controller_B.u_h[2] +
        controller_DW.Integrator_DSTATE_o) + rtb_FilterCoefficient_go;

  /* Saturate: '<S287>/Saturation' */
  if (u0 > 0.5) {
    ctrlOutM[2] = 0.5;
  } else if (u0 < -0.5) {
    ctrlOutM[2] = -0.5;
  } else {
    ctrlOutM[2] = u0;
  }

  /* End of Saturate: '<S287>/Saturation' */

  /* Update for DiscreteIntegrator: '<S56>/Filter' */
  controller_DW.Filter_SYSTEM_ENABLE_i = 0U;
  controller_DW.Filter_PREV_U_b = rtb_FilterCoefficient;

  /* Update for DiscreteIntegrator: '<S74>/Integrator' incorporates:
   *  Gain: '<S64>/Integral Gain'
   */
  controller_DW.Integrator_SYSTEM_ENABLE_a = 0U;
  controller_DW.Integrator_PREV_U_k = 0.388207529632927 * controller_B.u_h[0];

  /* Update for DiscreteIntegrator: '<S152>/Filter' */
  controller_DW.Filter_SYSTEM_ENABLE_pa = 0U;
  controller_DW.Filter_PREV_U_l = rtb_FilterCoefficient_j;

  /* Update for DiscreteIntegrator: '<S170>/Integrator' incorporates:
   *  Gain: '<S160>/Integral Gain'
   */
  controller_DW.Integrator_SYSTEM_ENABLE_j = 0U;
  controller_DW.Integrator_PREV_U_p = 0.3882073189173 * controller_B.u_h[1];

  /* Update for DiscreteIntegrator: '<S248>/Filter' */
  controller_DW.Filter_SYSTEM_ENABLE_f = 0U;
  controller_DW.Filter_PREV_U_c = rtb_FilterCoefficient_go;

  /* Update for DiscreteIntegrator: '<S266>/Integrator' incorporates:
   *  Gain: '<S256>/Integral Gain'
   */
  controller_DW.Integrator_SYSTEM_ENABLE_go = 0U;
  controller_DW.Integrator_PREV_U_b = 0.310565974877205 * controller_B.u_h[2];
}

/* System reset for function-call system: '<S1>/惯性四元数控制' */
void CtrlInertiaQ_Reset(void)
{
  /* InitializeConditions for DiscreteIntegrator: '<S639>/Filter' */
  controller_DW.Filter_DSTATE = 0.0;
  controller_DW.Filter_PREV_U = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S657>/Integrator' */
  controller_DW.Integrator_DSTATE = 0.0;
  controller_DW.Integrator_PREV_U = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S735>/Filter' */
  controller_DW.Filter_DSTATE_o = 0.0;
  controller_DW.Filter_PREV_U_p = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S753>/Integrator' */
  controller_DW.Integrator_DSTATE_d = 0.0;
  controller_DW.Integrator_PREV_U_m = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S831>/Filter' */
  controller_DW.Filter_DSTATE_d = 0.0;
  controller_DW.Filter_PREV_U_f = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S849>/Integrator' */
  controller_DW.Integrator_DSTATE_h = 0.0;
  controller_DW.Integrator_PREV_U_a = 0.0;
}

/* Enable for function-call system: '<S1>/惯性四元数控制' */
void CtrlInertiaQ_Enable(void)
{
  controller_DW._RESET_ELAPS_T = true;

  /* Enable for DiscreteIntegrator: '<S639>/Filter' */
  controller_DW.Filter_SYSTEM_ENABLE = 1U;

  /* Enable for DiscreteIntegrator: '<S657>/Integrator' */
  controller_DW.Integrator_SYSTEM_ENABLE = 1U;

  /* Enable for DiscreteIntegrator: '<S735>/Filter' */
  controller_DW.Filter_SYSTEM_ENABLE_e = 1U;

  /* Enable for DiscreteIntegrator: '<S753>/Integrator' */
  controller_DW.Integrator_SYSTEM_ENABLE_g = 1U;

  /* Enable for DiscreteIntegrator: '<S831>/Filter' */
  controller_DW.Filter_SYSTEM_ENABLE_p = 1U;

  /* Enable for DiscreteIntegrator: '<S849>/Integrator' */
  controller_DW.Integrator_SYSTEM_ENABLE_p = 1U;
}

/* Output and update for function-call system: '<S1>/惯性四元数控制' */
void CtrlInertiaQ(void)
{
  real_T rtb_FilterCoefficient;
  real_T rtb_FilterCoefficient_m;
  real_T rtb_FilterCoefficient_o;
  uint32_T _ELAPS_T;
  real_T rtb_u_o_idx_0;
  real_T rtb_u_o_idx_1;
  real_T rtb_u_o_idx_2;
  real_T u0;
  if (controller_DW._RESET_ELAPS_T) {
    _ELAPS_T = 0U;
  } else {
    _ELAPS_T = controller_M->Timing.clockTick0 - controller_DW._PREV_T;
  }

  controller_DW._PREV_T = controller_M->Timing.clockTick0;
  controller_DW._RESET_ELAPS_T = false;

  /* Sum: '<S9>/控制误差计算' incorporates:
   *  Inport: '<Root>/测量四元数'
   */
  rtb_u_o_idx_0 = controller_B.q[0] - ctrlInSensorQ[0];
  rtb_u_o_idx_1 = controller_B.q[1] - ctrlInSensorQ[1];
  rtb_u_o_idx_2 = controller_B.q[2] - ctrlInSensorQ[2];

  /* DiscreteIntegrator: '<S639>/Filter' */
  if (controller_DW.Filter_SYSTEM_ENABLE == 0) {
    controller_DW.Filter_DSTATE += 0.064 * (real_T)_ELAPS_T
      * controller_DW.Filter_PREV_U;
  }

  /* End of DiscreteIntegrator: '<S639>/Filter' */

  /* Gain: '<S667>/Filter Coefficient' incorporates:
   *  Gain: '<S634>/Derivative Gain'
   *  MATLAB Function: '<S9>/MATLAB Function'
   *  Sum: '<S639>/SumD'
   */
  rtb_FilterCoefficient = (320.501340777763 * rtb_u_o_idx_0 -
    controller_DW.Filter_DSTATE) * 3.13827171021481;

  /* DiscreteIntegrator: '<S657>/Integrator' */
  if (controller_DW.Integrator_SYSTEM_ENABLE == 0) {
    controller_DW.Integrator_DSTATE += 0.064 * (real_T)_ELAPS_T
      * controller_DW.Integrator_PREV_U;
  }

  /* End of DiscreteIntegrator: '<S657>/Integrator' */

  /* Sum: '<S687>/Sum' incorporates:
   *  Gain: '<S674>/Proportional Gain'
   *  MATLAB Function: '<S9>/MATLAB Function'
   */
  u0 = (26.2700961628852 * rtb_u_o_idx_0 + controller_DW.Integrator_DSTATE) +
    rtb_FilterCoefficient;

  /* Saturate: '<S678>/Saturation' */
  if (u0 > 0.5) {
    ctrlOutM[0] = 0.5;
  } else if (u0 < -0.5) {
    ctrlOutM[0] = -0.5;
  } else {
    ctrlOutM[0] = u0;
  }

  /* End of Saturate: '<S678>/Saturation' */

  /* DiscreteIntegrator: '<S735>/Filter' */
  if (controller_DW.Filter_SYSTEM_ENABLE_e == 0) {
    controller_DW.Filter_DSTATE_o += 0.064 * (real_T)_ELAPS_T
      * controller_DW.Filter_PREV_U_p;
  }

  /* End of DiscreteIntegrator: '<S735>/Filter' */

  /* Gain: '<S763>/Filter Coefficient' incorporates:
   *  Gain: '<S730>/Derivative Gain'
   *  MATLAB Function: '<S9>/MATLAB Function'
   *  Sum: '<S735>/SumD'
   */
  rtb_FilterCoefficient_m = (320.501350780946 * rtb_u_o_idx_1 -
    controller_DW.Filter_DSTATE_o) * 3.13827171021481;

  /* DiscreteIntegrator: '<S753>/Integrator' */
  if (controller_DW.Integrator_SYSTEM_ENABLE_g == 0) {
    controller_DW.Integrator_DSTATE_d += 0.064 * (real_T)_ELAPS_T
      * controller_DW.Integrator_PREV_U_m;
  }

  /* End of DiscreteIntegrator: '<S753>/Integrator' */

  /* Sum: '<S783>/Sum' incorporates:
   *  Gain: '<S770>/Proportional Gain'
   *  MATLAB Function: '<S9>/MATLAB Function'
   */
  u0 = (26.2700933216504 * rtb_u_o_idx_1 + controller_DW.Integrator_DSTATE_d) +
    rtb_FilterCoefficient_m;

  /* Saturate: '<S774>/Saturation' */
  if (u0 > 0.5) {
    ctrlOutM[1] = 0.5;
  } else if (u0 < -0.5) {
    ctrlOutM[1] = -0.5;
  } else {
    ctrlOutM[1] = u0;
  }

  /* End of Saturate: '<S774>/Saturation' */

  /* DiscreteIntegrator: '<S831>/Filter' */
  if (controller_DW.Filter_SYSTEM_ENABLE_p == 0) {
    controller_DW.Filter_DSTATE_d += 0.064 * (real_T)_ELAPS_T
      * controller_DW.Filter_PREV_U_f;
  }

  /* End of DiscreteIntegrator: '<S831>/Filter' */

  /* Gain: '<S859>/Filter Coefficient' incorporates:
   *  Gain: '<S826>/Derivative Gain'
   *  MATLAB Function: '<S9>/MATLAB Function'
   *  Sum: '<S831>/SumD'
   */
  rtb_FilterCoefficient_o = (256.401073137961 * rtb_u_o_idx_2 -
    controller_DW.Filter_DSTATE_d) * 3.13827171021481;

  /* DiscreteIntegrator: '<S849>/Integrator' */
  if (controller_DW.Integrator_SYSTEM_ENABLE_p == 0) {
    controller_DW.Integrator_DSTATE_h += 0.064 * (real_T)_ELAPS_T
      * controller_DW.Integrator_PREV_U_a;
  }

  /* End of DiscreteIntegrator: '<S849>/Integrator' */

  /* Sum: '<S879>/Sum' incorporates:
   *  Gain: '<S866>/Proportional Gain'
   *  MATLAB Function: '<S9>/MATLAB Function'
   */
  u0 = (21.0160761602212 * rtb_u_o_idx_2 + controller_DW.Integrator_DSTATE_h) +
    rtb_FilterCoefficient_o;

  /* Saturate: '<S870>/Saturation' */
  if (u0 > 0.5) {
    ctrlOutM[2] = 0.5;
  } else if (u0 < -0.5) {
    ctrlOutM[2] = -0.5;
  } else {
    ctrlOutM[2] = u0;
  }

  /* End of Saturate: '<S870>/Saturation' */

  /* Update for DiscreteIntegrator: '<S639>/Filter' */
  controller_DW.Filter_SYSTEM_ENABLE = 0U;
  controller_DW.Filter_PREV_U = rtb_FilterCoefficient;

  /* Update for DiscreteIntegrator: '<S657>/Integrator' incorporates:
   *  Gain: '<S647>/Integral Gain'
   *  MATLAB Function: '<S9>/MATLAB Function'
   */
  controller_DW.Integrator_SYSTEM_ENABLE = 0U;
  controller_DW.Integrator_PREV_U = 0.388207529632927 * rtb_u_o_idx_0;

  /* Update for DiscreteIntegrator: '<S735>/Filter' */
  controller_DW.Filter_SYSTEM_ENABLE_e = 0U;
  controller_DW.Filter_PREV_U_p = rtb_FilterCoefficient_m;

  /* Update for DiscreteIntegrator: '<S753>/Integrator' incorporates:
   *  Gain: '<S743>/Integral Gain'
   *  MATLAB Function: '<S9>/MATLAB Function'
   */
  controller_DW.Integrator_SYSTEM_ENABLE_g = 0U;
  controller_DW.Integrator_PREV_U_m = 0.3882073189173 * rtb_u_o_idx_1;

  /* Update for DiscreteIntegrator: '<S831>/Filter' */
  controller_DW.Filter_SYSTEM_ENABLE_p = 0U;
  controller_DW.Filter_PREV_U_f = rtb_FilterCoefficient_o;

  /* Update for DiscreteIntegrator: '<S849>/Integrator' incorporates:
   *  Gain: '<S839>/Integral Gain'
   *  MATLAB Function: '<S9>/MATLAB Function'
   */
  controller_DW.Integrator_SYSTEM_ENABLE_p = 0U;
  controller_DW.Integrator_PREV_U_a = 0.310565974877205 * rtb_u_o_idx_2;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
