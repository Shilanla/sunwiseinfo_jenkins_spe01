/*
 * File: controller.c
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

#include "controller.h"
#include "controller_private.h"

/* Named constants for Chart: '<Root>/控制模式选择' */
#define controller_IN_NO_ACTIVE_CHILD_h ((uint8_T)0U)
#define controller_IN_fixedQ           ((uint8_T)1U)
#define controller_IN_ill              ((uint8_T)1U)
#define controller_IN_normal           ((uint8_T)2U)
#define controller_IN_pause            ((uint8_T)3U)
#define controller_IN_safe             ((uint8_T)2U)
#define controller_IN_safeTwice        ((uint8_T)3U)
#define controller_IN_stop             ((uint8_T)1U)
#define controller_IN_work             ((uint8_T)2U)

/* Exported block signals */
real_T ctrlInCmdOmg[3];                /* '<Root>/预期轨道系姿态角' */
real_T ctrlInSensorGyro[6];            /* '<Root>/陀螺测量值' */
real_T ctrlInSensorQ[4];               /* '<Root>/测量四元数' */
uint32_T flgCtrl;                      /* '<Root>/启控' */
real_T ctrlOutM[3];                    /* '<S1>/输出控制量选择' */
real_T ctrlOmg[3];                     /* '<S4>/GyroComptueDelta' */
real_T ctrlAngle[3];                   /* '<S6>/转换为轨道系姿态角' */
int32_T ctrlMode;                      /* '<Root>/Data Type Conversion' */

/* Exported block parameters */
real_T gParaGyroIV[18] = { 0.0, -0.52483353, -0.7071063, -0.27925809, 0.7071063,
  0.80409162, 0.81649603, 0.62547225, -0.40824801, -0.76725529, -0.40824801,
  0.14178305, 0.57735105, 0.57735105, 0.57735105, 0.57735105, 0.57735105,
  0.57735105 } ;                       /* Variable: gParaGyroIV
                                        * Referenced by: '<Root>/陀螺安装矩阵'
                                        */

real_T gParaInitPos[3] = { -4.1740252026873119E+7, -5.9543391439830232E+6, 0.0 }
;                                      /* Variable: gParaInitPos
                                        * Referenced by: '<S3>/初始位置（米）'
                                        */

real_T gParaInitVel[3] = { 417.40410231773728, -2926.0262149157088,
  847.53419327145173 } ;               /* Variable: gParaInitVel
                                        * Referenced by: '<S3>/初始速度（米//秒）1'
                                        */

boolean_T gParaGyroUsed[6] = { 1, 1, 1, 1, 1, 0 } ;/* Variable: gParaGyroUsed
                                                    * Referenced by: '<Root>/陀螺使用标志'
                                                    */

boolean_T gParaPauseEnable = 0;        /* Variable: gParaPauseEnable
                                        * Referenced by: '<Root>/允许进入暂停模式'
                                        */

/* Block signals (default storage) */
B_controller_T controller_B;

/* Block states (default storage) */
DW_controller_T controller_DW;

/* Real-time model */
RT_MODEL_controller_T controller_M_;
RT_MODEL_controller_T *const controller_M = &controller_M_;

/* Forward declaration for local functions */
static uint32_T controller_check(real_T x, uint32_T c, real_T t);
static uint32_T controller_checkSafe(real_T x, uint32_T c, real_T t);

/* Function for Chart: '<Root>/控制模式选择' */
static uint32_T controller_check(real_T x, uint32_T c, real_T t)
{
  uint32_T y;
  if (x > t) {
    y = c + /*MW:OvSatOk*/ 1U;
    if (y < c) {
      y = MAX_uint32_T;
    }
  } else {
    y = 0U;
  }

  return y;
}

/* Function for Chart: '<Root>/控制模式选择' */
static uint32_T controller_checkSafe(real_T x, uint32_T c, real_T t)
{
  uint32_T y;
  if (x < t) {
    y = c + /*MW:OvSatOk*/ 1U;
    if (y < c) {
      y = MAX_uint32_T;
    }
  } else {
    y = 0U;
  }

  return y;
}

/* System initialize for atomic system: '<Root>/控制模式选择' */
void ModeSwitch_Init(void)
{
  controller_DW.qSaved[0] = 0.0;
  controller_DW.qSaved[1] = 0.0;
  controller_DW.qSaved[2] = 0.0;
  controller_DW.qSaved[3] = 1.0;
  controller_B.ChartMode = controller_Chart_4_ModeType_None;
}

/* Enable for atomic system: '<Root>/控制模式选择' */
void ModeSwitch_Enable(void)
{
  /* SystemReset for Function Call SubSystem: '<S1>/安全角速度控制' */
  CtrlSafeOmg_Reset();

  /* End of SystemReset for SubSystem: '<S1>/安全角速度控制' */

  /* Enable for Function Call SubSystem: '<S1>/安全角速度控制' */
  CtrlSafeOmg_Enable();

  /* End of Enable for SubSystem: '<S1>/安全角速度控制' */

  /* SystemReset for Function Call SubSystem: '<S1>/姿态角控制' */
  CtrlNormal_Reset();

  /* End of SystemReset for SubSystem: '<S1>/姿态角控制' */

  /* Enable for Function Call SubSystem: '<S1>/姿态角控制' */
  CtrlNormal_Enable();

  /* End of Enable for SubSystem: '<S1>/姿态角控制' */

  /* SystemReset for Function Call SubSystem: '<S1>/惯性四元数控制' */
  CtrlInertiaQ_Reset();

  /* End of SystemReset for SubSystem: '<S1>/惯性四元数控制' */

  /* Enable for Function Call SubSystem: '<S1>/惯性四元数控制' */
  CtrlInertiaQ_Enable();

  /* End of Enable for SubSystem: '<S1>/惯性四元数控制' */
}

/* Output and update for atomic system: '<Root>/控制模式选择' */
void ModeSwitch(void)
{
  /* Chart: '<Root>/控制模式选择' incorporates:
   *  Constant: '<Root>/允许进入暂停模式'
   *  Inport: '<Root>/测量四元数'
   *  Inport: '<Root>/启控'
   */
  if (controller_DW.is_active_c4_controller == 0U) {
    controller_DW.is_active_c4_controller = 1U;
    controller_DW.is_c4_controller = controller_IN_work;
    controller_DW.cnt1 = 0U;
    controller_DW.is_work = controller_IN_normal;
    controller_B.ChartMode = controller_Chart_4_ModeType_normal;
    controller_DW.cnt2 = 0U;
    controller_DW.cnt3 = 0U;
    controller_DW.cnt4 = 0U;
  } else if (controller_DW.is_c4_controller == controller_IN_stop) {
    switch (flgCtrl) {
     case 1U:
      controller_DW.is_c4_controller = controller_IN_work;
      controller_DW.cnt1 = 0U;
      controller_DW.is_work = controller_IN_normal;
      controller_B.ChartMode = controller_Chart_4_ModeType_normal;
      controller_DW.cnt2 = 0U;
      controller_DW.cnt3 = 0U;
      controller_DW.cnt4 = 0U;
      break;

     case 2U:
      controller_DW.is_c4_controller = controller_IN_work;
      controller_DW.cnt1 = 0U;
      controller_DW.is_work = controller_IN_ill;
      controller_DW.is_ill = controller_IN_fixedQ;
      controller_B.ChartMode = controller_Chart_4_ModeType_fixedQ;
      controller_DW.qSaved[0] = ctrlInSensorQ[0];
      controller_DW.qSaved[1] = ctrlInSensorQ[1];
      controller_DW.qSaved[2] = ctrlInSensorQ[2];
      controller_DW.qSaved[3] = ctrlInSensorQ[3];
      controller_DW.cnt2 = 0U;
      controller_DW.cnt3 = 0U;
      break;

     default:
      /* Outputs for Function Call SubSystem: '<S1>/停控模式' */
      CtrlStop();

      /* End of Outputs for SubSystem: '<S1>/停控模式' */
      break;
    }
  } else if (controller_DW.cnt1 > 100U) {
    controller_DW.is_ill = controller_IN_NO_ACTIVE_CHILD_h;
    controller_DW.is_work = controller_IN_NO_ACTIVE_CHILD_h;
    controller_DW.is_c4_controller = controller_IN_stop;
    controller_B.ChartMode = controller_Chart_4_ModeType_stop;
  } else {
    controller_DW.cnt1 = controller_check(controller_B.y, controller_DW.cnt1,
      1.0);
    switch (controller_DW.is_work) {
     case controller_IN_ill:
      if (flgCtrl == 1U) {
        controller_DW.is_ill = controller_IN_NO_ACTIVE_CHILD_h;
        controller_DW.is_work = controller_IN_normal;
        controller_B.ChartMode = controller_Chart_4_ModeType_normal;
        controller_DW.cnt2 = 0U;
        controller_DW.cnt3 = 0U;
        controller_DW.cnt4 = 0U;
      } else {
        switch (controller_DW.is_ill) {
         case controller_IN_fixedQ:
          if (controller_DW.cnt2 > 100U) {
            controller_DW.is_ill = controller_IN_safeTwice;
            controller_B.ChartMode = controller_Chart_4_ModeType_safeTwice;
          } else if ((controller_DW.cnt3 > 10000U) && (controller_DW.cntFixed <
                      5U)) {
            controller_DW.is_ill = controller_IN_NO_ACTIVE_CHILD_h;
            controller_DW.is_work = controller_IN_normal;
            controller_B.ChartMode = controller_Chart_4_ModeType_normal;
            controller_DW.cnt2 = 0U;
            controller_DW.cnt3 = 0U;
            controller_DW.cnt4 = 0U;
          } else {
            controller_DW.cnt2 = controller_check(controller_B.y,
              controller_DW.cnt2, 0.5);
            controller_DW.cnt3 = controller_checkSafe(controller_B.y,
              controller_DW.cnt3, 0.005);
            controller_B.q[0] = controller_DW.qSaved[0];
            controller_B.q[1] = controller_DW.qSaved[1];
            controller_B.q[2] = controller_DW.qSaved[2];
            controller_B.q[3] = controller_DW.qSaved[3];

            /* Outputs for Function Call SubSystem: '<S1>/惯性四元数控制' */
            CtrlInertiaQ();

            /* End of Outputs for SubSystem: '<S1>/惯性四元数控制' */
          }
          break;

         case controller_IN_safe:
          if (controller_DW.cnt2 > 1000U) {
            controller_DW.cntFixed++;
            controller_DW.is_ill = controller_IN_fixedQ;
            controller_B.ChartMode = controller_Chart_4_ModeType_fixedQ;
            controller_DW.qSaved[0] = ctrlInSensorQ[0];
            controller_DW.qSaved[1] = ctrlInSensorQ[1];
            controller_DW.qSaved[2] = ctrlInSensorQ[2];
            controller_DW.qSaved[3] = ctrlInSensorQ[3];
            controller_DW.cnt2 = 0U;
            controller_DW.cnt3 = 0U;
          } else {
            controller_DW.cnt2 = controller_checkSafe(controller_B.y,
              controller_DW.cnt2, 0.01);

            /* Outputs for Function Call SubSystem: '<S1>/安全角速度控制' */
            CtrlSafeOmg();

            /* End of Outputs for SubSystem: '<S1>/安全角速度控制' */
          }
          break;

         default:
          /* Outputs for Function Call SubSystem: '<S1>/安全角速度控制' */
          CtrlSafeOmg();

          /* End of Outputs for SubSystem: '<S1>/安全角速度控制' */
          break;
        }
      }
      break;

     case controller_IN_normal:
      if (controller_DW.cnt2 > 100U) {
        controller_DW.is_work = controller_IN_ill;
        controller_DW.is_ill = controller_IN_safe;
        controller_B.ChartMode = controller_Chart_4_ModeType_safe;
        controller_DW.cnt2 = 0U;
      } else if (gParaPauseEnable && (controller_DW.cnt3 > 100U) &&
                 (controller_DW.cnt4 > 100U)) {
        controller_DW.is_work = controller_IN_pause;
        controller_B.ChartMode = controller_Chart_4_ModeType_pause;
        controller_DW.cnt3 = 0U;
        controller_DW.cnt4 = 0U;
      } else {
        controller_DW.cnt2 = controller_check(controller_B.y, controller_DW.cnt2,
          0.5);
        controller_DW.cnt3 = controller_checkSafe(controller_B.y,
          controller_DW.cnt3, 0.001);
        controller_DW.cnt4 = controller_checkSafe(controller_B.Delay,
          controller_DW.cnt4, 0.001);

        /* Outputs for Function Call SubSystem: '<S1>/姿态角控制' */
        CtrlNormal();

        /* End of Outputs for SubSystem: '<S1>/姿态角控制' */
      }
      break;

     default:
      if ((controller_DW.cnt3 > 20U) || (controller_DW.cnt4 > 20U)) {
        controller_DW.is_work = controller_IN_normal;
        controller_B.ChartMode = controller_Chart_4_ModeType_normal;
        controller_DW.cnt2 = 0U;
        controller_DW.cnt3 = 0U;
        controller_DW.cnt4 = 0U;
      } else {
        controller_DW.cnt3 = controller_check(controller_B.y, controller_DW.cnt3,
          0.01);
        controller_DW.cnt4 = controller_check(controller_B.Delay,
          controller_DW.cnt4, 0.002);

        /* Outputs for Function Call SubSystem: '<S1>/停控模式' */
        CtrlStop();

        /* End of Outputs for SubSystem: '<S1>/停控模式' */
      }
      break;
    }
  }

  /* End of Chart: '<Root>/控制模式选择' */
}

/* System initialize for atomic system: '<S891>/轨道动力学（仅地球引力）' */
void OrbitDynamic_Init(const real_T rtu_u[3], const real_T rtu_u_a[3],
  DW_OrbitDynamic_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S894>/位置积分' */
  localDW->_DSTATE[0] = rtu_u_a[0];

  /* InitializeConditions for DiscreteIntegrator: '<S894>/速度积分' */
  localDW->_DSTATE_c[0] = rtu_u[0];

  /* InitializeConditions for DiscreteIntegrator: '<S894>/位置积分' */
  localDW->_DSTATE[1] = rtu_u_a[1];

  /* InitializeConditions for DiscreteIntegrator: '<S894>/速度积分' */
  localDW->_DSTATE_c[1] = rtu_u[1];

  /* InitializeConditions for DiscreteIntegrator: '<S894>/位置积分' */
  localDW->_DSTATE[2] = rtu_u_a[2];

  /* InitializeConditions for DiscreteIntegrator: '<S894>/速度积分' */
  localDW->_DSTATE_c[2] = rtu_u[2];
}

/* Output and update for atomic system: '<S891>/轨道动力学（仅地球引力）' */
void OrbitDynamic(real_T rtu_u_b, real_T rty_u[3], real_T rty_u_a[3],
                  DW_OrbitDynamic_T *localDW)
{
  real_T rtb_Sqrt;
  real_T rtb_Multiply;
  real_T rty_u_0;

  /* DiscreteIntegrator: '<S894>/位置积分' */
  rty_u[0] = localDW->_DSTATE[0];

  /* DotProduct: '<S894>/Dot Product' */
  rty_u_0 = rty_u[0] * rty_u[0];

  /* DiscreteIntegrator: '<S894>/速度积分' */
  rty_u_a[0] = localDW->_DSTATE_c[0];

  /* Update for DiscreteIntegrator: '<S894>/位置积分' */
  localDW->_DSTATE[0] += 0.064 * rty_u_a[0];

  /* DiscreteIntegrator: '<S894>/位置积分' */
  rty_u[1] = localDW->_DSTATE[1];

  /* DotProduct: '<S894>/Dot Product' */
  rty_u_0 += rty_u[1] * rty_u[1];

  /* DiscreteIntegrator: '<S894>/速度积分' */
  rty_u_a[1] = localDW->_DSTATE_c[1];

  /* Update for DiscreteIntegrator: '<S894>/位置积分' */
  localDW->_DSTATE[1] += 0.064 * rty_u_a[1];

  /* DiscreteIntegrator: '<S894>/位置积分' */
  rty_u[2] = localDW->_DSTATE[2];

  /* DotProduct: '<S894>/Dot Product' */
  rty_u_0 += rty_u[2] * rty_u[2];

  /* DiscreteIntegrator: '<S894>/速度积分' */
  rty_u_a[2] = localDW->_DSTATE_c[2];

  /* Update for DiscreteIntegrator: '<S894>/位置积分' */
  localDW->_DSTATE[2] += 0.064 * rty_u_a[2];

  /* Sqrt: '<S894>/Sqrt' incorporates:
   *  DotProduct: '<S894>/Dot Product'
   */
  rtb_Sqrt = sqrt(rty_u_0);

  /* Product: '<S894>/Multiply' */
  rtb_Multiply = rtb_Sqrt * rtb_Sqrt * rtb_Sqrt;

  /* Update for DiscreteIntegrator: '<S894>/速度积分' incorporates:
   *  Product: '<S894>/Divide1'
   *  Product: '<S894>/Multiply1'
   *  UnaryMinus: '<S894>/Unary Minus'
   */
  localDW->_DSTATE_c[0] += -(rtu_u_b * rty_u[0]) / rtb_Multiply * 0.064;
  localDW->_DSTATE_c[1] += -(rtu_u_b * rty_u[1]) / rtb_Multiply * 0.064;
  localDW->_DSTATE_c[2] += -(rtu_u_b * rty_u[2]) / rtb_Multiply * 0.064;
}

/* System initialize for atomic system: '<Root>/轨道计算' */
void ProcessOrbit_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S3>/轨道外推' */
  /* SystemInitialize for Atomic SubSystem: '<S891>/轨道动力学（仅地球引力）' */
  OrbitDynamic_Init(controller_B.u_m, controller_B.u, &controller_DW.u_j);

  /* End of SystemInitialize for SubSystem: '<S891>/轨道动力学（仅地球引力）' */
  /* End of SystemInitialize for SubSystem: '<S3>/轨道外推' */
}

/* Start for atomic system: '<Root>/轨道计算' */
void ProcessOrbit_Start(void)
{
  /* Start for Constant: '<S3>/初始位置（米）' */
  controller_B.u[0] = gParaInitPos[0];

  /* Start for Constant: '<S3>/初始速度（米//秒）1' */
  controller_B.u_m[0] = gParaInitVel[0];

  /* Start for Constant: '<S3>/初始位置（米）' */
  controller_B.u[1] = gParaInitPos[1];

  /* Start for Constant: '<S3>/初始速度（米//秒）1' */
  controller_B.u_m[1] = gParaInitVel[1];

  /* Start for Constant: '<S3>/初始位置（米）' */
  controller_B.u[2] = gParaInitPos[2];

  /* Start for Constant: '<S3>/初始速度（米//秒）1' */
  controller_B.u_m[2] = gParaInitVel[2];
}

/* Output and update for atomic system: '<Root>/轨道计算' */
void ProcessOrbit(void)
{
  real_T r;
  real_T cosu;
  real_T rtb_u_e[3];
  real_T rtb_u_je[3];
  real_T sinu[9];
  real_T cosOmg[9];
  int32_T i;
  int32_T i_0;
  real_T h_idx_0;
  real_T h_idx_1;
  real_T h_idx_2;
  real_T i_tmp;
  int32_T COI_tmp;
  int32_T COI_tmp_0;

  /* Constant: '<S3>/初始位置（米）' */
  controller_B.u[0] = gParaInitPos[0];

  /* Constant: '<S3>/初始速度（米//秒）1' */
  controller_B.u_m[0] = gParaInitVel[0];

  /* Constant: '<S3>/初始位置（米）' */
  controller_B.u[1] = gParaInitPos[1];

  /* Constant: '<S3>/初始速度（米//秒）1' */
  controller_B.u_m[1] = gParaInitVel[1];

  /* Constant: '<S3>/初始位置（米）' */
  controller_B.u[2] = gParaInitPos[2];

  /* Constant: '<S3>/初始速度（米//秒）1' */
  controller_B.u_m[2] = gParaInitVel[2];

  /* Outputs for Atomic SubSystem: '<S3>/轨道外推' */
  /* Outputs for Atomic SubSystem: '<S891>/轨道动力学（仅地球引力）' */
  /* Constant: '<S891>/地球引力常数' */
  OrbitDynamic(3.986004418E+14, rtb_u_je, rtb_u_e, &controller_DW.u_j);

  /* End of Outputs for SubSystem: '<S891>/轨道动力学（仅地球引力）' */

  /* MATLAB Function: '<S891>/位置速度转换为根数' incorporates:
   *  MATLAB Function: '<S891>/惯性系轨道系转换阵'
   */
  r = sqrt((rtb_u_je[0] * rtb_u_je[0] + rtb_u_je[1] * rtb_u_je[1]) + rtb_u_je[2]
           * rtb_u_je[2]);
  h_idx_0 = rtb_u_je[1] * rtb_u_e[2] - rtb_u_je[2] * rtb_u_e[1];
  h_idx_1 = rtb_u_je[2] * rtb_u_e[0] - rtb_u_je[0] * rtb_u_e[2];
  h_idx_2 = rtb_u_je[0] * rtb_u_e[1] - rtb_u_je[1] * rtb_u_e[0];
  i_tmp = h_idx_0 * h_idx_0 + h_idx_1 * h_idx_1;
  h_idx_2 = acos(h_idx_2 / sqrt(i_tmp + h_idx_2 * h_idx_2));
  i_tmp = acos(-h_idx_1 / sqrt(i_tmp));
  if (h_idx_0 < 0.0) {
    i_tmp = -i_tmp;
  }

  h_idx_0 = sin(h_idx_2);
  h_idx_1 = sin(i_tmp);
  i_tmp = cos(i_tmp);
  cosu = atan2(rtb_u_je[2] / (r * h_idx_0), (rtb_u_je[0] * i_tmp + rtb_u_je[1] *
    h_idx_1) / r);

  /* MATLAB Function: '<S891>/惯性系轨道系转换阵' incorporates:
   *  MATLAB Function: '<S891>/位置速度转换为根数'
   */
  r = sin(cosu);
  cosu = cos(cosu);
  h_idx_2 = cos(h_idx_2);
  sinu[0] = -r;
  sinu[3] = cosu;
  sinu[6] = 0.0;
  sinu[1] = 0.0;
  sinu[4] = 0.0;
  sinu[7] = -1.0;
  sinu[2] = -cosu;
  sinu[5] = -r;
  sinu[8] = 0.0;
  cosOmg[0] = i_tmp;
  cosOmg[3] = h_idx_1;
  cosOmg[6] = 0.0;
  cosOmg[1] = -h_idx_2 * h_idx_1;
  cosOmg[4] = h_idx_2 * i_tmp;
  cosOmg[7] = h_idx_0;
  cosOmg[2] = h_idx_0 * h_idx_1;
  cosOmg[5] = -h_idx_0 * i_tmp;
  cosOmg[8] = h_idx_2;
  for (i_0 = 0; i_0 < 3; i_0++) {
    for (i = 0; i < 3; i++) {
      COI_tmp = i + 3 * i_0;
      controller_B.COI[COI_tmp] = 0.0;
      COI_tmp_0 = 3 * i_0 + i;
      controller_B.COI[COI_tmp] = controller_B.COI[COI_tmp_0] + cosOmg[3 * i_0] *
        sinu[i];
      controller_B.COI[COI_tmp] = cosOmg[3 * i_0 + 1] * sinu[i + 3] +
        controller_B.COI[COI_tmp_0];
      controller_B.COI[COI_tmp] = cosOmg[3 * i_0 + 2] * sinu[i + 6] +
        controller_B.COI[COI_tmp_0];
    }
  }

  /* End of Outputs for SubSystem: '<S3>/轨道外推' */
}

/* System initialize for atomic system: '<S4>/GyroChkValid' */
void controller_GyroChkValid_Init(uint32_T rty_idUsed[5],
  DW_GyroChkValid_controller_T *localDW)
{
  localDW->NUM = 9U;
  localDW->NUMUSED = 5U;
  rty_idUsed[0] = 0U;
  rty_idUsed[1] = 0U;
  rty_idUsed[2] = 0U;
  rty_idUsed[3] = 0U;
  rty_idUsed[4] = 0U;
}

/* Output and update for atomic system: '<S4>/GyroChkValid' */
void controller_GyroChkValid(const boolean_T rtu_bUse[6], uint32_T rty_idUsed[5],
  uint32_T *rty_numUsed, DW_GyroChkValid_controller_T *localDW)
{
  uint32_T i;

  /* Chart: '<S4>/GyroChkValid' */
  i = 1U;
  *rty_numUsed = 0U;
  while ((i <= localDW->NUM) && (*rty_numUsed < localDW->NUMUSED)) {
    if (rtu_bUse[(int32_T)i - 1]) {
      (*rty_numUsed)++;
      rty_idUsed[(int32_T)*rty_numUsed - 1] = i;
    }

    i++;
  }

  /* End of Chart: '<S4>/GyroChkValid' */
}

/* Output and update for atomic system: '<S4>/GyroComptueDelta' */
void controller_GyroComptueDelta(const real_T rtu_gyroPls[6], const uint32_T
  rtu_gyroUsed[5], uint32_T rtu_gyroNum, const real_T rtu_IV_GYRO[18], real_T
  rty_dg[3], DW_GyroComptueDelta_controlle_T *localDW)
{
  real_T y[9];
  real_T x[9];
  int32_T p1;
  int32_T p2;
  int32_T p3;
  real_T absx11;
  real_T absx21;
  real_T absx31;
  int32_T itmp;
  uint32_T i;
  real_T y_tmp[15];
  real_T y_0[15];

  /* Chart: '<S4>/GyroComptueDelta' */
  if (rtu_gyroNum < 3U) {
    rty_dg[0] = 0.0;
    rty_dg[1] = 0.0;
    rty_dg[2] = 0.0;
  } else {
    for (i = 1U; i <= rtu_gyroNum; i++) {
      p2 = (int32_T)i - 1;
      p1 = (int32_T)rtu_gyroUsed[p2];
      localDW->g[p2] = rtu_gyroPls[p1 - 1];
      p2 = (int32_T)i;
      localDW->bg[p2 - 1] = rtu_IV_GYRO[p1 - 1];
      localDW->bg[p2 + 4] = rtu_IV_GYRO[p1 + 5];
      localDW->bg[p2 + 9] = rtu_IV_GYRO[p1 + 11];
    }

    for (p1 = 0; p1 < 5; p1++) {
      y_tmp[3 * p1] = localDW->bg[p1];
      y_tmp[1 + 3 * p1] = localDW->bg[p1 + 5];
      y_tmp[2 + 3 * p1] = localDW->bg[p1 + 10];
    }

    for (p1 = 0; p1 < 3; p1++) {
      for (p2 = 0; p2 < 3; p2++) {
        p3 = p2 + 3 * p1;
        y[p3] = 0.0;
        for (itmp = 0; itmp < 5; itmp++) {
          y[p3] = y_tmp[3 * itmp + p2] * localDW->bg[5 * p1 + itmp] + y[3 * p1 +
            p2];
        }
      }
    }

    for (p1 = 0; p1 < 9; p1++) {
      x[p1] = y[p1];
    }

    p1 = 0;
    p2 = 3;
    p3 = 6;
    absx11 = fabs(y[0]);
    absx21 = fabs(y[1]);
    absx31 = fabs(y[2]);
    if ((absx21 > absx11) && (absx21 > absx31)) {
      p1 = 3;
      p2 = 0;
      x[0] = y[1];
      x[1] = y[0];
      x[3] = y[4];
      x[4] = y[3];
      x[6] = y[7];
      x[7] = y[6];
    } else {
      if (absx31 > absx11) {
        p1 = 6;
        p3 = 0;
        x[0] = y[2];
        x[2] = y[0];
        x[3] = y[5];
        x[5] = y[3];
        x[6] = y[8];
        x[8] = y[6];
      }
    }

    absx11 = x[1] / x[0];
    x[1] = absx11;
    absx21 = x[2] / x[0];
    x[2] = absx21;
    x[4] -= absx11 * x[3];
    x[5] -= absx21 * x[3];
    x[7] -= absx11 * x[6];
    x[8] -= absx21 * x[6];
    if (fabs(x[5]) > fabs(x[4])) {
      itmp = p2;
      p2 = p3;
      p3 = itmp;
      x[1] = absx21;
      x[2] = absx11;
      absx11 = x[4];
      x[4] = x[5];
      x[5] = absx11;
      absx11 = x[7];
      x[7] = x[8];
      x[8] = absx11;
    }

    absx11 = x[5] / x[4];
    x[8] -= absx11 * x[7];
    absx21 = (absx11 * x[1] - x[2]) / x[8];
    absx31 = -(x[7] * absx21 + x[1]) / x[4];
    y[p1] = ((1.0 - x[3] * absx31) - x[6] * absx21) / x[0];
    y[p1 + 1] = absx31;
    y[p1 + 2] = absx21;
    absx21 = -absx11 / x[8];
    absx31 = (1.0 - x[7] * absx21) / x[4];
    y[p2] = -(x[3] * absx31 + x[6] * absx21) / x[0];
    y[p2 + 1] = absx31;
    y[p2 + 2] = absx21;
    absx21 = 1.0 / x[8];
    absx31 = -x[7] * absx21 / x[4];
    y[p3] = -(x[3] * absx31 + x[6] * absx21) / x[0];
    y[p3 + 1] = absx31;
    y[p3 + 2] = absx21;
    for (p1 = 0; p1 < 3; p1++) {
      rty_dg[p1] = 0.0;
      for (p2 = 0; p2 < 5; p2++) {
        p3 = p1 + 3 * p2;
        y_0[p3] = 0.0;
        itmp = 3 * p2 + p1;
        y_0[p3] = y_0[itmp] + y_tmp[3 * p2] * y[p1];
        y_0[p3] = y_tmp[3 * p2 + 1] * y[p1 + 3] + y_0[itmp];
        y_0[p3] = y_tmp[3 * p2 + 2] * y[p1 + 6] + y_0[itmp];
        rty_dg[p1] += y_0[itmp] * localDW->g[p2];
      }
    }
  }

  /* End of Chart: '<S4>/GyroComptueDelta' */
}

/* System initialize for atomic system: '<Root>/陀螺数据处理' */
void ProcessGyroData_Init(void)
{
  /* SystemInitialize for Chart: '<S4>/GyroChkValid' */
  controller_GyroChkValid_Init(controller_B.idUsed,
    &controller_DW.sf_GyroChkValid);
}

/* Output and update for atomic system: '<Root>/陀螺数据处理' */
void ProcessGyroData(void)
{
  uint32_T rtb_numUsed;
  real_T x_idx_1;
  real_T x_idx_2;

  /* Chart: '<S4>/GyroChkValid' incorporates:
   *  Constant: '<Root>/陀螺使用标志'
   */
  controller_GyroChkValid(gParaGyroUsed, controller_B.idUsed, &rtb_numUsed,
    &controller_DW.sf_GyroChkValid);

  /* SignalConversion: '<S4>/TmpSignal ConversionAtGyroComptueDeltaOutport1' incorporates:
   *  Chart: '<S4>/GyroComptueDelta'
   *  Constant: '<Root>/陀螺安装矩阵'
   *  Inport: '<Root>/陀螺测量值'
   */
  controller_GyroComptueDelta(ctrlInSensorGyro, controller_B.idUsed, rtb_numUsed,
    gParaGyroIV, ctrlOmg, &controller_DW.sf_GyroComptueDelta);

  /* MATLAB Function: '<S4>/角速度最值' */
  controller_B.y = fabs(ctrlOmg[0]);
  x_idx_1 = fabs(ctrlOmg[1]);
  x_idx_2 = fabs(ctrlOmg[2]);
  if (controller_B.y < x_idx_1) {
    controller_B.y = x_idx_1;
  }

  if (controller_B.y < x_idx_2) {
    controller_B.y = x_idx_2;
  }

  /* End of MATLAB Function: '<S4>/角速度最值' */
}

/* Model step function */
void controller_step(void)
{
  real_T x_idx_1;
  real_T x_idx_2;

  /* Outputs for Atomic SubSystem: '<Root>/轨道计算' */
  ProcessOrbit();

  /* End of Outputs for SubSystem: '<Root>/轨道计算' */

  /* Outputs for Atomic SubSystem: '<Root>/陀螺数据处理' */
  ProcessGyroData();

  /* End of Outputs for SubSystem: '<Root>/陀螺数据处理' */

  /* Outputs for Atomic SubSystem: '<S1>/四元数误差计算' */
  ComputeErrQ();

  /* End of Outputs for SubSystem: '<S1>/四元数误差计算' */

  /* Delay: '<Root>/Delay' */
  controller_B.Delay = controller_DW.Delay_DSTATE;

  /* Chart: '<Root>/控制模式选择' */
  ModeSwitch();

  /* DataTypeConversion: '<Root>/Data Type Conversion' */
  ctrlMode = controller_B.ChartMode;

  /* MATLAB Function: '<S1>/控制误差最值' */
  controller_DW.Delay_DSTATE = fabs(controller_B.u_h[0]);
  x_idx_1 = fabs(controller_B.u_h[1]);
  x_idx_2 = fabs(controller_B.u_h[2]);
  if (controller_DW.Delay_DSTATE < x_idx_1) {
    controller_DW.Delay_DSTATE = x_idx_1;
  }

  if (controller_DW.Delay_DSTATE < x_idx_2) {
    controller_DW.Delay_DSTATE = x_idx_2;
  }

  /* End of MATLAB Function: '<S1>/控制误差最值' */

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.064, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  controller_M->Timing.clockTick0++;
}

/* Model initialize function */
void controller_initialize(void)
{
  /* Start for Atomic SubSystem: '<Root>/轨道计算' */
  ProcessOrbit_Start();

  /* End of Start for SubSystem: '<Root>/轨道计算' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/轨道计算' */
  ProcessOrbit_Init();

  /* End of SystemInitialize for SubSystem: '<Root>/轨道计算' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/陀螺数据处理' */
  ProcessGyroData_Init();

  /* End of SystemInitialize for SubSystem: '<Root>/陀螺数据处理' */

  /* SystemInitialize for Atomic SubSystem: '<S1>/四元数误差计算' */
  ComputeErrQ_Init();

  /* End of SystemInitialize for SubSystem: '<S1>/四元数误差计算' */

  /* SystemInitialize for Chart: '<Root>/控制模式选择' */
  ModeSwitch_Init();

  /* Enable for Chart: '<Root>/控制模式选择' */
  ModeSwitch_Enable();
}

/* Model terminate function */
void controller_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
