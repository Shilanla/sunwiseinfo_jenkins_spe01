/*
 * File: controller.h
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

#ifndef RTW_HEADER_controller_h_
#define RTW_HEADER_controller_h_
#include <math.h>
#ifndef controller_COMMON_INCLUDES_
# define controller_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* controller_COMMON_INCLUDES_ */

#include "controller_types.h"

/* Child system includes */
#include "modeImpl.h"

/* Macros for accessing real-time model data structure */

/* Block states (default storage) for system '<S891>/轨道动力学（仅地球引力）' */
typedef struct {
  real_T _DSTATE[3];                   /* '<S894>/位置积分' */
  real_T _DSTATE_c[3];                 /* '<S894>/速度积分' */
} DW_OrbitDynamic_T;

/* Block states (default storage) for system '<S4>/GyroChkValid' */
typedef struct {
  uint32_T NUM;                        /* '<S4>/GyroChkValid' */
  uint32_T NUMUSED;                    /* '<S4>/GyroChkValid' */
} DW_GyroChkValid_controller_T;

/* Block states (default storage) for system '<S4>/GyroComptueDelta' */
typedef struct {
  real_T bg[15];                       /* '<S4>/GyroComptueDelta' */
  real_T g[5];                         /* '<S4>/GyroComptueDelta' */
} DW_GyroComptueDelta_controlle_T;

/* Block signals (default storage) */
typedef struct {
  real_T Delay;                        /* '<Root>/Delay' */
  real_T y;                            /* '<S4>/角速度最值' */
  real_T u[3];                         /* '<S3>/初始位置（米）' */
  real_T u_m[3];                       /* '<S3>/初始速度（米//秒）1' */
  real_T COI[9];                       /* '<S891>/惯性系轨道系转换阵' */
  real_T q[4];                         /* '<Root>/控制模式选择' */
  real_T u_h[4];                       /* '<S6>/控制误差计算' */
  real_T qbi[4];                       /* '<S12>/ComputeQbi' */
  real_T expected[4];                  /* '<S6>/控制目标规划' */
  uint32_T idUsed[5];                  /* '<S4>/GyroChkValid' */
  controller_Chart_4_ModeType ChartMode;/* '<Root>/控制模式选择' */
} B_controller_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Delay_DSTATE;                 /* '<Root>/Delay' */
  real_T Filter_DSTATE;                /* '<S639>/Filter' */
  real_T Integrator_DSTATE;            /* '<S657>/Integrator' */
  real_T Filter_DSTATE_o;              /* '<S735>/Filter' */
  real_T Integrator_DSTATE_d;          /* '<S753>/Integrator' */
  real_T Filter_DSTATE_d;              /* '<S831>/Filter' */
  real_T Integrator_DSTATE_h;          /* '<S849>/Integrator' */
  real_T Filter_DSTATE_b;              /* '<S56>/Filter' */
  real_T Integrator_DSTATE_dy;         /* '<S74>/Integrator' */
  real_T Filter_DSTATE_j;              /* '<S152>/Filter' */
  real_T Integrator_DSTATE_g;          /* '<S170>/Integrator' */
  real_T Filter_DSTATE_m;              /* '<S248>/Filter' */
  real_T Integrator_DSTATE_o;          /* '<S266>/Integrator' */
  real_T Filter_DSTATE_f;              /* '<S347>/Filter' */
  real_T Integrator_DSTATE_m;          /* '<S365>/Integrator' */
  real_T Filter_DSTATE_oe;             /* '<S443>/Filter' */
  real_T Integrator_DSTATE_n;          /* '<S461>/Integrator' */
  real_T Filter_DSTATE_oz;             /* '<S539>/Filter' */
  real_T Integrator_DSTATE_p;          /* '<S557>/Integrator' */
  real_T qSaved[4];                    /* '<Root>/控制模式选择' */
  real_T Filter_PREV_U;                /* '<S639>/Filter' */
  real_T Integrator_PREV_U;            /* '<S657>/Integrator' */
  real_T Filter_PREV_U_p;              /* '<S735>/Filter' */
  real_T Integrator_PREV_U_m;          /* '<S753>/Integrator' */
  real_T Filter_PREV_U_f;              /* '<S831>/Filter' */
  real_T Integrator_PREV_U_a;          /* '<S849>/Integrator' */
  real_T Filter_PREV_U_b;              /* '<S56>/Filter' */
  real_T Integrator_PREV_U_k;          /* '<S74>/Integrator' */
  real_T Filter_PREV_U_l;              /* '<S152>/Filter' */
  real_T Integrator_PREV_U_p;          /* '<S170>/Integrator' */
  real_T Filter_PREV_U_c;              /* '<S248>/Filter' */
  real_T Integrator_PREV_U_b;          /* '<S266>/Integrator' */
  real_T Filter_PREV_U_pl;             /* '<S347>/Filter' */
  real_T Integrator_PREV_U_aw;         /* '<S365>/Integrator' */
  real_T Filter_PREV_U_pw;             /* '<S443>/Filter' */
  real_T Integrator_PREV_U_a4;         /* '<S461>/Integrator' */
  real_T Filter_PREV_U_lz;             /* '<S539>/Filter' */
  real_T Integrator_PREV_U_pc;         /* '<S557>/Integrator' */
  real_T sT[4];                        /* '<S6>/控制目标规划' */
  real_T waitTime;                     /* '<S6>/控制目标规划' */
  uint32_T cnt1;                       /* '<Root>/控制模式选择' */
  uint32_T cnt2;                       /* '<Root>/控制模式选择' */
  uint32_T cnt3;                       /* '<Root>/控制模式选择' */
  uint32_T cnt4;                       /* '<Root>/控制模式选择' */
  uint32_T cntFixed;                   /* '<Root>/控制模式选择' */
  uint32_T _PREV_T;                    /* '<S1>/惯性四元数控制' */
  uint32_T _PREV_T_p;                  /* '<S1>/姿态角控制' */
  uint32_T _PREV_T_o;                  /* '<S1>/安全角速度控制' */
  uint32_T temporalCounter_i1;         /* '<S6>/控制目标规划' */
  uint8_T is_active_c4_controller;     /* '<Root>/控制模式选择' */
  uint8_T is_c4_controller;            /* '<Root>/控制模式选择' */
  uint8_T is_work;                     /* '<Root>/控制模式选择' */
  uint8_T is_ill;                      /* '<Root>/控制模式选择' */
  uint8_T Filter_SYSTEM_ENABLE;        /* '<S639>/Filter' */
  uint8_T Integrator_SYSTEM_ENABLE;    /* '<S657>/Integrator' */
  uint8_T Filter_SYSTEM_ENABLE_e;      /* '<S735>/Filter' */
  uint8_T Integrator_SYSTEM_ENABLE_g;  /* '<S753>/Integrator' */
  uint8_T Filter_SYSTEM_ENABLE_p;      /* '<S831>/Filter' */
  uint8_T Integrator_SYSTEM_ENABLE_p;  /* '<S849>/Integrator' */
  uint8_T Filter_SYSTEM_ENABLE_i;      /* '<S56>/Filter' */
  uint8_T Integrator_SYSTEM_ENABLE_a;  /* '<S74>/Integrator' */
  uint8_T Filter_SYSTEM_ENABLE_pa;     /* '<S152>/Filter' */
  uint8_T Integrator_SYSTEM_ENABLE_j;  /* '<S170>/Integrator' */
  uint8_T Filter_SYSTEM_ENABLE_f;      /* '<S248>/Filter' */
  uint8_T Integrator_SYSTEM_ENABLE_go; /* '<S266>/Integrator' */
  uint8_T Filter_SYSTEM_ENABLE_c;      /* '<S347>/Filter' */
  uint8_T Integrator_SYSTEM_ENABLE_o;  /* '<S365>/Integrator' */
  uint8_T Filter_SYSTEM_ENABLE_h;      /* '<S443>/Filter' */
  uint8_T Integrator_SYSTEM_ENABLE_oz; /* '<S461>/Integrator' */
  uint8_T Filter_SYSTEM_ENABLE_ck;     /* '<S539>/Filter' */
  uint8_T Integrator_SYSTEM_ENABLE_i;  /* '<S557>/Integrator' */
  uint8_T is_active_c2_controller;     /* '<S6>/控制目标规划' */
  uint8_T is_c2_controller;            /* '<S6>/控制目标规划' */
  boolean_T _RESET_ELAPS_T;            /* '<S1>/惯性四元数控制' */
  boolean_T _RESET_ELAPS_T_j;          /* '<S1>/姿态角控制' */
  boolean_T _RESET_ELAPS_T_l;          /* '<S1>/安全角速度控制' */
  DW_GyroComptueDelta_controlle_T sf_GyroComptueDelta;/* '<S4>/GyroComptueDelta' */
  DW_GyroChkValid_controller_T sf_GyroChkValid;/* '<S4>/GyroChkValid' */
  DW_OrbitDynamic_T u_j;               /* '<S891>/轨道动力学（仅地球引力）' */
} DW_controller_T;

/* Real-time Model Data Structure */
struct tag_RTM_controller_T {
  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
  } Timing;
};

/* Block signals (default storage) */
extern B_controller_T controller_B;

/* Block states (default storage) */
extern DW_controller_T controller_DW;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real_T ctrlInCmdOmg[3];         /* '<Root>/预期轨道系姿态角' */
extern real_T ctrlInSensorGyro[6];     /* '<Root>/陀螺测量值' */
extern real_T ctrlInSensorQ[4];        /* '<Root>/测量四元数' */
extern uint32_T flgCtrl;               /* '<Root>/启控' */
extern real_T ctrlOutM[3];             /* '<S1>/输出控制量选择' */
extern real_T ctrlOmg[3];              /* '<S4>/GyroComptueDelta' */
extern real_T ctrlAngle[3];            /* '<S6>/转换为轨道系姿态角' */
extern int32_T ctrlMode;               /* '<Root>/Data Type Conversion' */

/*
 * Exported Global Parameters
 *
 * Note: Exported global parameters are tunable parameters with an exported
 * global storage class designation.  Code generation will declare the memory for
 * these parameters and exports their symbols.
 *
 */
extern real_T gParaGyroIV[18];         /* Variable: gParaGyroIV
                                        * Referenced by: '<Root>/陀螺安装矩阵'
                                        */
extern real_T gParaInitPos[3];         /* Variable: gParaInitPos
                                        * Referenced by: '<S3>/初始位置（米）'
                                        */
extern real_T gParaInitVel[3];         /* Variable: gParaInitVel
                                        * Referenced by: '<S3>/初始速度（米//秒）1'
                                        */
extern boolean_T gParaGyroUsed[6];     /* Variable: gParaGyroUsed
                                        * Referenced by: '<Root>/陀螺使用标志'
                                        */
extern boolean_T gParaPauseEnable;     /* Variable: gParaPauseEnable
                                        * Referenced by: '<Root>/允许进入暂停模式'
                                        */

/* Model entry point functions */
extern void controller_initialize(void);
extern void controller_step(void);
extern void controller_terminate(void);

/* Real-time Model object */
extern RT_MODEL_controller_T *const controller_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'controller'
 * '<S1>'   : 'controller/控制模式'
 * '<S2>'   : 'controller/控制模式选择'
 * '<S3>'   : 'controller/轨道计算'
 * '<S4>'   : 'controller/陀螺数据处理'
 * '<S5>'   : 'controller/控制模式/停控模式'
 * '<S6>'   : 'controller/控制模式/四元数误差计算'
 * '<S7>'   : 'controller/控制模式/姿态角控制'
 * '<S8>'   : 'controller/控制模式/安全角速度控制'
 * '<S9>'   : 'controller/控制模式/惯性四元数控制'
 * '<S10>'  : 'controller/控制模式/控制误差最值'
 * '<S11>'  : 'controller/控制模式/四元数误差计算/控制目标规划'
 * '<S12>'  : 'controller/控制模式/四元数误差计算/计算预期的惯性系四元数'
 * '<S13>'  : 'controller/控制模式/四元数误差计算/转换为轨道系姿态角'
 * '<S14>'  : 'controller/控制模式/四元数误差计算/计算预期的惯性系四元数/Angle2Cbo'
 * '<S15>'  : 'controller/控制模式/四元数误差计算/计算预期的惯性系四元数/ComputeCbi'
 * '<S16>'  : 'controller/控制模式/四元数误差计算/计算预期的惯性系四元数/ComputeQbi'
 * '<S17>'  : 'controller/控制模式/姿态角控制/ctrlX'
 * '<S18>'  : 'controller/控制模式/姿态角控制/ctrlY'
 * '<S19>'  : 'controller/控制模式/姿态角控制/ctrlZ'
 * '<S20>'  : 'controller/控制模式/姿态角控制/ctrlX/Anti-windup'
 * '<S21>'  : 'controller/控制模式/姿态角控制/ctrlX/D Gain'
 * '<S22>'  : 'controller/控制模式/姿态角控制/ctrlX/Filter'
 * '<S23>'  : 'controller/控制模式/姿态角控制/ctrlX/Filter ICs'
 * '<S24>'  : 'controller/控制模式/姿态角控制/ctrlX/I Gain'
 * '<S25>'  : 'controller/控制模式/姿态角控制/ctrlX/Ideal P Gain'
 * '<S26>'  : 'controller/控制模式/姿态角控制/ctrlX/Ideal P Gain Fdbk'
 * '<S27>'  : 'controller/控制模式/姿态角控制/ctrlX/Integrator'
 * '<S28>'  : 'controller/控制模式/姿态角控制/ctrlX/Integrator ICs'
 * '<S29>'  : 'controller/控制模式/姿态角控制/ctrlX/N Copy'
 * '<S30>'  : 'controller/控制模式/姿态角控制/ctrlX/N Gain'
 * '<S31>'  : 'controller/控制模式/姿态角控制/ctrlX/P Copy'
 * '<S32>'  : 'controller/控制模式/姿态角控制/ctrlX/Parallel P Gain'
 * '<S33>'  : 'controller/控制模式/姿态角控制/ctrlX/Reset Signal'
 * '<S34>'  : 'controller/控制模式/姿态角控制/ctrlX/Saturation'
 * '<S35>'  : 'controller/控制模式/姿态角控制/ctrlX/Saturation Fdbk'
 * '<S36>'  : 'controller/控制模式/姿态角控制/ctrlX/Sum'
 * '<S37>'  : 'controller/控制模式/姿态角控制/ctrlX/Sum Fdbk'
 * '<S38>'  : 'controller/控制模式/姿态角控制/ctrlX/Tracking Mode'
 * '<S39>'  : 'controller/控制模式/姿态角控制/ctrlX/Tracking Mode Sum'
 * '<S40>'  : 'controller/控制模式/姿态角控制/ctrlX/postSat Signal'
 * '<S41>'  : 'controller/控制模式/姿态角控制/ctrlX/preSat Signal'
 * '<S42>'  : 'controller/控制模式/姿态角控制/ctrlX/Anti-windup/Back Calculation'
 * '<S43>'  : 'controller/控制模式/姿态角控制/ctrlX/Anti-windup/Cont. Clamping Ideal'
 * '<S44>'  : 'controller/控制模式/姿态角控制/ctrlX/Anti-windup/Cont. Clamping Parallel'
 * '<S45>'  : 'controller/控制模式/姿态角控制/ctrlX/Anti-windup/Disabled'
 * '<S46>'  : 'controller/控制模式/姿态角控制/ctrlX/Anti-windup/Disc. Clamping Ideal'
 * '<S47>'  : 'controller/控制模式/姿态角控制/ctrlX/Anti-windup/Disc. Clamping Parallel'
 * '<S48>'  : 'controller/控制模式/姿态角控制/ctrlX/Anti-windup/Passthrough'
 * '<S49>'  : 'controller/控制模式/姿态角控制/ctrlX/D Gain/Disabled'
 * '<S50>'  : 'controller/控制模式/姿态角控制/ctrlX/D Gain/External Parameters'
 * '<S51>'  : 'controller/控制模式/姿态角控制/ctrlX/D Gain/Internal Parameters'
 * '<S52>'  : 'controller/控制模式/姿态角控制/ctrlX/Filter/Cont. Filter'
 * '<S53>'  : 'controller/控制模式/姿态角控制/ctrlX/Filter/Differentiator'
 * '<S54>'  : 'controller/控制模式/姿态角控制/ctrlX/Filter/Disabled'
 * '<S55>'  : 'controller/控制模式/姿态角控制/ctrlX/Filter/Disc. Backward Euler Filter'
 * '<S56>'  : 'controller/控制模式/姿态角控制/ctrlX/Filter/Disc. Forward Euler Filter'
 * '<S57>'  : 'controller/控制模式/姿态角控制/ctrlX/Filter/Disc. Trapezoidal Filter'
 * '<S58>'  : 'controller/控制模式/姿态角控制/ctrlX/Filter ICs/Disabled'
 * '<S59>'  : 'controller/控制模式/姿态角控制/ctrlX/Filter ICs/External IC'
 * '<S60>'  : 'controller/控制模式/姿态角控制/ctrlX/Filter ICs/Internal IC - Differentiator'
 * '<S61>'  : 'controller/控制模式/姿态角控制/ctrlX/Filter ICs/Internal IC - Filter'
 * '<S62>'  : 'controller/控制模式/姿态角控制/ctrlX/I Gain/Disabled'
 * '<S63>'  : 'controller/控制模式/姿态角控制/ctrlX/I Gain/External Parameters'
 * '<S64>'  : 'controller/控制模式/姿态角控制/ctrlX/I Gain/Internal Parameters'
 * '<S65>'  : 'controller/控制模式/姿态角控制/ctrlX/Ideal P Gain/External Parameters'
 * '<S66>'  : 'controller/控制模式/姿态角控制/ctrlX/Ideal P Gain/Internal Parameters'
 * '<S67>'  : 'controller/控制模式/姿态角控制/ctrlX/Ideal P Gain/Passthrough'
 * '<S68>'  : 'controller/控制模式/姿态角控制/ctrlX/Ideal P Gain Fdbk/Disabled'
 * '<S69>'  : 'controller/控制模式/姿态角控制/ctrlX/Ideal P Gain Fdbk/External Parameters'
 * '<S70>'  : 'controller/控制模式/姿态角控制/ctrlX/Ideal P Gain Fdbk/Internal Parameters'
 * '<S71>'  : 'controller/控制模式/姿态角控制/ctrlX/Ideal P Gain Fdbk/Passthrough'
 * '<S72>'  : 'controller/控制模式/姿态角控制/ctrlX/Integrator/Continuous'
 * '<S73>'  : 'controller/控制模式/姿态角控制/ctrlX/Integrator/Disabled'
 * '<S74>'  : 'controller/控制模式/姿态角控制/ctrlX/Integrator/Discrete'
 * '<S75>'  : 'controller/控制模式/姿态角控制/ctrlX/Integrator ICs/Disabled'
 * '<S76>'  : 'controller/控制模式/姿态角控制/ctrlX/Integrator ICs/External IC'
 * '<S77>'  : 'controller/控制模式/姿态角控制/ctrlX/Integrator ICs/Internal IC'
 * '<S78>'  : 'controller/控制模式/姿态角控制/ctrlX/N Copy/Disabled'
 * '<S79>'  : 'controller/控制模式/姿态角控制/ctrlX/N Copy/Disabled wSignal Specification'
 * '<S80>'  : 'controller/控制模式/姿态角控制/ctrlX/N Copy/External Parameters'
 * '<S81>'  : 'controller/控制模式/姿态角控制/ctrlX/N Copy/Internal Parameters'
 * '<S82>'  : 'controller/控制模式/姿态角控制/ctrlX/N Gain/Disabled'
 * '<S83>'  : 'controller/控制模式/姿态角控制/ctrlX/N Gain/External Parameters'
 * '<S84>'  : 'controller/控制模式/姿态角控制/ctrlX/N Gain/Internal Parameters'
 * '<S85>'  : 'controller/控制模式/姿态角控制/ctrlX/N Gain/Passthrough'
 * '<S86>'  : 'controller/控制模式/姿态角控制/ctrlX/P Copy/Disabled'
 * '<S87>'  : 'controller/控制模式/姿态角控制/ctrlX/P Copy/External Parameters Ideal'
 * '<S88>'  : 'controller/控制模式/姿态角控制/ctrlX/P Copy/Internal Parameters Ideal'
 * '<S89>'  : 'controller/控制模式/姿态角控制/ctrlX/Parallel P Gain/Disabled'
 * '<S90>'  : 'controller/控制模式/姿态角控制/ctrlX/Parallel P Gain/External Parameters'
 * '<S91>'  : 'controller/控制模式/姿态角控制/ctrlX/Parallel P Gain/Internal Parameters'
 * '<S92>'  : 'controller/控制模式/姿态角控制/ctrlX/Parallel P Gain/Passthrough'
 * '<S93>'  : 'controller/控制模式/姿态角控制/ctrlX/Reset Signal/Disabled'
 * '<S94>'  : 'controller/控制模式/姿态角控制/ctrlX/Reset Signal/External Reset'
 * '<S95>'  : 'controller/控制模式/姿态角控制/ctrlX/Saturation/Enabled'
 * '<S96>'  : 'controller/控制模式/姿态角控制/ctrlX/Saturation/Passthrough'
 * '<S97>'  : 'controller/控制模式/姿态角控制/ctrlX/Saturation Fdbk/Disabled'
 * '<S98>'  : 'controller/控制模式/姿态角控制/ctrlX/Saturation Fdbk/Enabled'
 * '<S99>'  : 'controller/控制模式/姿态角控制/ctrlX/Saturation Fdbk/Passthrough'
 * '<S100>' : 'controller/控制模式/姿态角控制/ctrlX/Sum/Passthrough_I'
 * '<S101>' : 'controller/控制模式/姿态角控制/ctrlX/Sum/Passthrough_P'
 * '<S102>' : 'controller/控制模式/姿态角控制/ctrlX/Sum/Sum_PD'
 * '<S103>' : 'controller/控制模式/姿态角控制/ctrlX/Sum/Sum_PI'
 * '<S104>' : 'controller/控制模式/姿态角控制/ctrlX/Sum/Sum_PID'
 * '<S105>' : 'controller/控制模式/姿态角控制/ctrlX/Sum Fdbk/Disabled'
 * '<S106>' : 'controller/控制模式/姿态角控制/ctrlX/Sum Fdbk/Enabled'
 * '<S107>' : 'controller/控制模式/姿态角控制/ctrlX/Sum Fdbk/Passthrough'
 * '<S108>' : 'controller/控制模式/姿态角控制/ctrlX/Tracking Mode/Disabled'
 * '<S109>' : 'controller/控制模式/姿态角控制/ctrlX/Tracking Mode/Enabled'
 * '<S110>' : 'controller/控制模式/姿态角控制/ctrlX/Tracking Mode Sum/Passthrough'
 * '<S111>' : 'controller/控制模式/姿态角控制/ctrlX/Tracking Mode Sum/Tracking Mode'
 * '<S112>' : 'controller/控制模式/姿态角控制/ctrlX/postSat Signal/Feedback_Path'
 * '<S113>' : 'controller/控制模式/姿态角控制/ctrlX/postSat Signal/Forward_Path'
 * '<S114>' : 'controller/控制模式/姿态角控制/ctrlX/preSat Signal/Feedback_Path'
 * '<S115>' : 'controller/控制模式/姿态角控制/ctrlX/preSat Signal/Forward_Path'
 * '<S116>' : 'controller/控制模式/姿态角控制/ctrlY/Anti-windup'
 * '<S117>' : 'controller/控制模式/姿态角控制/ctrlY/D Gain'
 * '<S118>' : 'controller/控制模式/姿态角控制/ctrlY/Filter'
 * '<S119>' : 'controller/控制模式/姿态角控制/ctrlY/Filter ICs'
 * '<S120>' : 'controller/控制模式/姿态角控制/ctrlY/I Gain'
 * '<S121>' : 'controller/控制模式/姿态角控制/ctrlY/Ideal P Gain'
 * '<S122>' : 'controller/控制模式/姿态角控制/ctrlY/Ideal P Gain Fdbk'
 * '<S123>' : 'controller/控制模式/姿态角控制/ctrlY/Integrator'
 * '<S124>' : 'controller/控制模式/姿态角控制/ctrlY/Integrator ICs'
 * '<S125>' : 'controller/控制模式/姿态角控制/ctrlY/N Copy'
 * '<S126>' : 'controller/控制模式/姿态角控制/ctrlY/N Gain'
 * '<S127>' : 'controller/控制模式/姿态角控制/ctrlY/P Copy'
 * '<S128>' : 'controller/控制模式/姿态角控制/ctrlY/Parallel P Gain'
 * '<S129>' : 'controller/控制模式/姿态角控制/ctrlY/Reset Signal'
 * '<S130>' : 'controller/控制模式/姿态角控制/ctrlY/Saturation'
 * '<S131>' : 'controller/控制模式/姿态角控制/ctrlY/Saturation Fdbk'
 * '<S132>' : 'controller/控制模式/姿态角控制/ctrlY/Sum'
 * '<S133>' : 'controller/控制模式/姿态角控制/ctrlY/Sum Fdbk'
 * '<S134>' : 'controller/控制模式/姿态角控制/ctrlY/Tracking Mode'
 * '<S135>' : 'controller/控制模式/姿态角控制/ctrlY/Tracking Mode Sum'
 * '<S136>' : 'controller/控制模式/姿态角控制/ctrlY/postSat Signal'
 * '<S137>' : 'controller/控制模式/姿态角控制/ctrlY/preSat Signal'
 * '<S138>' : 'controller/控制模式/姿态角控制/ctrlY/Anti-windup/Back Calculation'
 * '<S139>' : 'controller/控制模式/姿态角控制/ctrlY/Anti-windup/Cont. Clamping Ideal'
 * '<S140>' : 'controller/控制模式/姿态角控制/ctrlY/Anti-windup/Cont. Clamping Parallel'
 * '<S141>' : 'controller/控制模式/姿态角控制/ctrlY/Anti-windup/Disabled'
 * '<S142>' : 'controller/控制模式/姿态角控制/ctrlY/Anti-windup/Disc. Clamping Ideal'
 * '<S143>' : 'controller/控制模式/姿态角控制/ctrlY/Anti-windup/Disc. Clamping Parallel'
 * '<S144>' : 'controller/控制模式/姿态角控制/ctrlY/Anti-windup/Passthrough'
 * '<S145>' : 'controller/控制模式/姿态角控制/ctrlY/D Gain/Disabled'
 * '<S146>' : 'controller/控制模式/姿态角控制/ctrlY/D Gain/External Parameters'
 * '<S147>' : 'controller/控制模式/姿态角控制/ctrlY/D Gain/Internal Parameters'
 * '<S148>' : 'controller/控制模式/姿态角控制/ctrlY/Filter/Cont. Filter'
 * '<S149>' : 'controller/控制模式/姿态角控制/ctrlY/Filter/Differentiator'
 * '<S150>' : 'controller/控制模式/姿态角控制/ctrlY/Filter/Disabled'
 * '<S151>' : 'controller/控制模式/姿态角控制/ctrlY/Filter/Disc. Backward Euler Filter'
 * '<S152>' : 'controller/控制模式/姿态角控制/ctrlY/Filter/Disc. Forward Euler Filter'
 * '<S153>' : 'controller/控制模式/姿态角控制/ctrlY/Filter/Disc. Trapezoidal Filter'
 * '<S154>' : 'controller/控制模式/姿态角控制/ctrlY/Filter ICs/Disabled'
 * '<S155>' : 'controller/控制模式/姿态角控制/ctrlY/Filter ICs/External IC'
 * '<S156>' : 'controller/控制模式/姿态角控制/ctrlY/Filter ICs/Internal IC - Differentiator'
 * '<S157>' : 'controller/控制模式/姿态角控制/ctrlY/Filter ICs/Internal IC - Filter'
 * '<S158>' : 'controller/控制模式/姿态角控制/ctrlY/I Gain/Disabled'
 * '<S159>' : 'controller/控制模式/姿态角控制/ctrlY/I Gain/External Parameters'
 * '<S160>' : 'controller/控制模式/姿态角控制/ctrlY/I Gain/Internal Parameters'
 * '<S161>' : 'controller/控制模式/姿态角控制/ctrlY/Ideal P Gain/External Parameters'
 * '<S162>' : 'controller/控制模式/姿态角控制/ctrlY/Ideal P Gain/Internal Parameters'
 * '<S163>' : 'controller/控制模式/姿态角控制/ctrlY/Ideal P Gain/Passthrough'
 * '<S164>' : 'controller/控制模式/姿态角控制/ctrlY/Ideal P Gain Fdbk/Disabled'
 * '<S165>' : 'controller/控制模式/姿态角控制/ctrlY/Ideal P Gain Fdbk/External Parameters'
 * '<S166>' : 'controller/控制模式/姿态角控制/ctrlY/Ideal P Gain Fdbk/Internal Parameters'
 * '<S167>' : 'controller/控制模式/姿态角控制/ctrlY/Ideal P Gain Fdbk/Passthrough'
 * '<S168>' : 'controller/控制模式/姿态角控制/ctrlY/Integrator/Continuous'
 * '<S169>' : 'controller/控制模式/姿态角控制/ctrlY/Integrator/Disabled'
 * '<S170>' : 'controller/控制模式/姿态角控制/ctrlY/Integrator/Discrete'
 * '<S171>' : 'controller/控制模式/姿态角控制/ctrlY/Integrator ICs/Disabled'
 * '<S172>' : 'controller/控制模式/姿态角控制/ctrlY/Integrator ICs/External IC'
 * '<S173>' : 'controller/控制模式/姿态角控制/ctrlY/Integrator ICs/Internal IC'
 * '<S174>' : 'controller/控制模式/姿态角控制/ctrlY/N Copy/Disabled'
 * '<S175>' : 'controller/控制模式/姿态角控制/ctrlY/N Copy/Disabled wSignal Specification'
 * '<S176>' : 'controller/控制模式/姿态角控制/ctrlY/N Copy/External Parameters'
 * '<S177>' : 'controller/控制模式/姿态角控制/ctrlY/N Copy/Internal Parameters'
 * '<S178>' : 'controller/控制模式/姿态角控制/ctrlY/N Gain/Disabled'
 * '<S179>' : 'controller/控制模式/姿态角控制/ctrlY/N Gain/External Parameters'
 * '<S180>' : 'controller/控制模式/姿态角控制/ctrlY/N Gain/Internal Parameters'
 * '<S181>' : 'controller/控制模式/姿态角控制/ctrlY/N Gain/Passthrough'
 * '<S182>' : 'controller/控制模式/姿态角控制/ctrlY/P Copy/Disabled'
 * '<S183>' : 'controller/控制模式/姿态角控制/ctrlY/P Copy/External Parameters Ideal'
 * '<S184>' : 'controller/控制模式/姿态角控制/ctrlY/P Copy/Internal Parameters Ideal'
 * '<S185>' : 'controller/控制模式/姿态角控制/ctrlY/Parallel P Gain/Disabled'
 * '<S186>' : 'controller/控制模式/姿态角控制/ctrlY/Parallel P Gain/External Parameters'
 * '<S187>' : 'controller/控制模式/姿态角控制/ctrlY/Parallel P Gain/Internal Parameters'
 * '<S188>' : 'controller/控制模式/姿态角控制/ctrlY/Parallel P Gain/Passthrough'
 * '<S189>' : 'controller/控制模式/姿态角控制/ctrlY/Reset Signal/Disabled'
 * '<S190>' : 'controller/控制模式/姿态角控制/ctrlY/Reset Signal/External Reset'
 * '<S191>' : 'controller/控制模式/姿态角控制/ctrlY/Saturation/Enabled'
 * '<S192>' : 'controller/控制模式/姿态角控制/ctrlY/Saturation/Passthrough'
 * '<S193>' : 'controller/控制模式/姿态角控制/ctrlY/Saturation Fdbk/Disabled'
 * '<S194>' : 'controller/控制模式/姿态角控制/ctrlY/Saturation Fdbk/Enabled'
 * '<S195>' : 'controller/控制模式/姿态角控制/ctrlY/Saturation Fdbk/Passthrough'
 * '<S196>' : 'controller/控制模式/姿态角控制/ctrlY/Sum/Passthrough_I'
 * '<S197>' : 'controller/控制模式/姿态角控制/ctrlY/Sum/Passthrough_P'
 * '<S198>' : 'controller/控制模式/姿态角控制/ctrlY/Sum/Sum_PD'
 * '<S199>' : 'controller/控制模式/姿态角控制/ctrlY/Sum/Sum_PI'
 * '<S200>' : 'controller/控制模式/姿态角控制/ctrlY/Sum/Sum_PID'
 * '<S201>' : 'controller/控制模式/姿态角控制/ctrlY/Sum Fdbk/Disabled'
 * '<S202>' : 'controller/控制模式/姿态角控制/ctrlY/Sum Fdbk/Enabled'
 * '<S203>' : 'controller/控制模式/姿态角控制/ctrlY/Sum Fdbk/Passthrough'
 * '<S204>' : 'controller/控制模式/姿态角控制/ctrlY/Tracking Mode/Disabled'
 * '<S205>' : 'controller/控制模式/姿态角控制/ctrlY/Tracking Mode/Enabled'
 * '<S206>' : 'controller/控制模式/姿态角控制/ctrlY/Tracking Mode Sum/Passthrough'
 * '<S207>' : 'controller/控制模式/姿态角控制/ctrlY/Tracking Mode Sum/Tracking Mode'
 * '<S208>' : 'controller/控制模式/姿态角控制/ctrlY/postSat Signal/Feedback_Path'
 * '<S209>' : 'controller/控制模式/姿态角控制/ctrlY/postSat Signal/Forward_Path'
 * '<S210>' : 'controller/控制模式/姿态角控制/ctrlY/preSat Signal/Feedback_Path'
 * '<S211>' : 'controller/控制模式/姿态角控制/ctrlY/preSat Signal/Forward_Path'
 * '<S212>' : 'controller/控制模式/姿态角控制/ctrlZ/Anti-windup'
 * '<S213>' : 'controller/控制模式/姿态角控制/ctrlZ/D Gain'
 * '<S214>' : 'controller/控制模式/姿态角控制/ctrlZ/Filter'
 * '<S215>' : 'controller/控制模式/姿态角控制/ctrlZ/Filter ICs'
 * '<S216>' : 'controller/控制模式/姿态角控制/ctrlZ/I Gain'
 * '<S217>' : 'controller/控制模式/姿态角控制/ctrlZ/Ideal P Gain'
 * '<S218>' : 'controller/控制模式/姿态角控制/ctrlZ/Ideal P Gain Fdbk'
 * '<S219>' : 'controller/控制模式/姿态角控制/ctrlZ/Integrator'
 * '<S220>' : 'controller/控制模式/姿态角控制/ctrlZ/Integrator ICs'
 * '<S221>' : 'controller/控制模式/姿态角控制/ctrlZ/N Copy'
 * '<S222>' : 'controller/控制模式/姿态角控制/ctrlZ/N Gain'
 * '<S223>' : 'controller/控制模式/姿态角控制/ctrlZ/P Copy'
 * '<S224>' : 'controller/控制模式/姿态角控制/ctrlZ/Parallel P Gain'
 * '<S225>' : 'controller/控制模式/姿态角控制/ctrlZ/Reset Signal'
 * '<S226>' : 'controller/控制模式/姿态角控制/ctrlZ/Saturation'
 * '<S227>' : 'controller/控制模式/姿态角控制/ctrlZ/Saturation Fdbk'
 * '<S228>' : 'controller/控制模式/姿态角控制/ctrlZ/Sum'
 * '<S229>' : 'controller/控制模式/姿态角控制/ctrlZ/Sum Fdbk'
 * '<S230>' : 'controller/控制模式/姿态角控制/ctrlZ/Tracking Mode'
 * '<S231>' : 'controller/控制模式/姿态角控制/ctrlZ/Tracking Mode Sum'
 * '<S232>' : 'controller/控制模式/姿态角控制/ctrlZ/postSat Signal'
 * '<S233>' : 'controller/控制模式/姿态角控制/ctrlZ/preSat Signal'
 * '<S234>' : 'controller/控制模式/姿态角控制/ctrlZ/Anti-windup/Back Calculation'
 * '<S235>' : 'controller/控制模式/姿态角控制/ctrlZ/Anti-windup/Cont. Clamping Ideal'
 * '<S236>' : 'controller/控制模式/姿态角控制/ctrlZ/Anti-windup/Cont. Clamping Parallel'
 * '<S237>' : 'controller/控制模式/姿态角控制/ctrlZ/Anti-windup/Disabled'
 * '<S238>' : 'controller/控制模式/姿态角控制/ctrlZ/Anti-windup/Disc. Clamping Ideal'
 * '<S239>' : 'controller/控制模式/姿态角控制/ctrlZ/Anti-windup/Disc. Clamping Parallel'
 * '<S240>' : 'controller/控制模式/姿态角控制/ctrlZ/Anti-windup/Passthrough'
 * '<S241>' : 'controller/控制模式/姿态角控制/ctrlZ/D Gain/Disabled'
 * '<S242>' : 'controller/控制模式/姿态角控制/ctrlZ/D Gain/External Parameters'
 * '<S243>' : 'controller/控制模式/姿态角控制/ctrlZ/D Gain/Internal Parameters'
 * '<S244>' : 'controller/控制模式/姿态角控制/ctrlZ/Filter/Cont. Filter'
 * '<S245>' : 'controller/控制模式/姿态角控制/ctrlZ/Filter/Differentiator'
 * '<S246>' : 'controller/控制模式/姿态角控制/ctrlZ/Filter/Disabled'
 * '<S247>' : 'controller/控制模式/姿态角控制/ctrlZ/Filter/Disc. Backward Euler Filter'
 * '<S248>' : 'controller/控制模式/姿态角控制/ctrlZ/Filter/Disc. Forward Euler Filter'
 * '<S249>' : 'controller/控制模式/姿态角控制/ctrlZ/Filter/Disc. Trapezoidal Filter'
 * '<S250>' : 'controller/控制模式/姿态角控制/ctrlZ/Filter ICs/Disabled'
 * '<S251>' : 'controller/控制模式/姿态角控制/ctrlZ/Filter ICs/External IC'
 * '<S252>' : 'controller/控制模式/姿态角控制/ctrlZ/Filter ICs/Internal IC - Differentiator'
 * '<S253>' : 'controller/控制模式/姿态角控制/ctrlZ/Filter ICs/Internal IC - Filter'
 * '<S254>' : 'controller/控制模式/姿态角控制/ctrlZ/I Gain/Disabled'
 * '<S255>' : 'controller/控制模式/姿态角控制/ctrlZ/I Gain/External Parameters'
 * '<S256>' : 'controller/控制模式/姿态角控制/ctrlZ/I Gain/Internal Parameters'
 * '<S257>' : 'controller/控制模式/姿态角控制/ctrlZ/Ideal P Gain/External Parameters'
 * '<S258>' : 'controller/控制模式/姿态角控制/ctrlZ/Ideal P Gain/Internal Parameters'
 * '<S259>' : 'controller/控制模式/姿态角控制/ctrlZ/Ideal P Gain/Passthrough'
 * '<S260>' : 'controller/控制模式/姿态角控制/ctrlZ/Ideal P Gain Fdbk/Disabled'
 * '<S261>' : 'controller/控制模式/姿态角控制/ctrlZ/Ideal P Gain Fdbk/External Parameters'
 * '<S262>' : 'controller/控制模式/姿态角控制/ctrlZ/Ideal P Gain Fdbk/Internal Parameters'
 * '<S263>' : 'controller/控制模式/姿态角控制/ctrlZ/Ideal P Gain Fdbk/Passthrough'
 * '<S264>' : 'controller/控制模式/姿态角控制/ctrlZ/Integrator/Continuous'
 * '<S265>' : 'controller/控制模式/姿态角控制/ctrlZ/Integrator/Disabled'
 * '<S266>' : 'controller/控制模式/姿态角控制/ctrlZ/Integrator/Discrete'
 * '<S267>' : 'controller/控制模式/姿态角控制/ctrlZ/Integrator ICs/Disabled'
 * '<S268>' : 'controller/控制模式/姿态角控制/ctrlZ/Integrator ICs/External IC'
 * '<S269>' : 'controller/控制模式/姿态角控制/ctrlZ/Integrator ICs/Internal IC'
 * '<S270>' : 'controller/控制模式/姿态角控制/ctrlZ/N Copy/Disabled'
 * '<S271>' : 'controller/控制模式/姿态角控制/ctrlZ/N Copy/Disabled wSignal Specification'
 * '<S272>' : 'controller/控制模式/姿态角控制/ctrlZ/N Copy/External Parameters'
 * '<S273>' : 'controller/控制模式/姿态角控制/ctrlZ/N Copy/Internal Parameters'
 * '<S274>' : 'controller/控制模式/姿态角控制/ctrlZ/N Gain/Disabled'
 * '<S275>' : 'controller/控制模式/姿态角控制/ctrlZ/N Gain/External Parameters'
 * '<S276>' : 'controller/控制模式/姿态角控制/ctrlZ/N Gain/Internal Parameters'
 * '<S277>' : 'controller/控制模式/姿态角控制/ctrlZ/N Gain/Passthrough'
 * '<S278>' : 'controller/控制模式/姿态角控制/ctrlZ/P Copy/Disabled'
 * '<S279>' : 'controller/控制模式/姿态角控制/ctrlZ/P Copy/External Parameters Ideal'
 * '<S280>' : 'controller/控制模式/姿态角控制/ctrlZ/P Copy/Internal Parameters Ideal'
 * '<S281>' : 'controller/控制模式/姿态角控制/ctrlZ/Parallel P Gain/Disabled'
 * '<S282>' : 'controller/控制模式/姿态角控制/ctrlZ/Parallel P Gain/External Parameters'
 * '<S283>' : 'controller/控制模式/姿态角控制/ctrlZ/Parallel P Gain/Internal Parameters'
 * '<S284>' : 'controller/控制模式/姿态角控制/ctrlZ/Parallel P Gain/Passthrough'
 * '<S285>' : 'controller/控制模式/姿态角控制/ctrlZ/Reset Signal/Disabled'
 * '<S286>' : 'controller/控制模式/姿态角控制/ctrlZ/Reset Signal/External Reset'
 * '<S287>' : 'controller/控制模式/姿态角控制/ctrlZ/Saturation/Enabled'
 * '<S288>' : 'controller/控制模式/姿态角控制/ctrlZ/Saturation/Passthrough'
 * '<S289>' : 'controller/控制模式/姿态角控制/ctrlZ/Saturation Fdbk/Disabled'
 * '<S290>' : 'controller/控制模式/姿态角控制/ctrlZ/Saturation Fdbk/Enabled'
 * '<S291>' : 'controller/控制模式/姿态角控制/ctrlZ/Saturation Fdbk/Passthrough'
 * '<S292>' : 'controller/控制模式/姿态角控制/ctrlZ/Sum/Passthrough_I'
 * '<S293>' : 'controller/控制模式/姿态角控制/ctrlZ/Sum/Passthrough_P'
 * '<S294>' : 'controller/控制模式/姿态角控制/ctrlZ/Sum/Sum_PD'
 * '<S295>' : 'controller/控制模式/姿态角控制/ctrlZ/Sum/Sum_PI'
 * '<S296>' : 'controller/控制模式/姿态角控制/ctrlZ/Sum/Sum_PID'
 * '<S297>' : 'controller/控制模式/姿态角控制/ctrlZ/Sum Fdbk/Disabled'
 * '<S298>' : 'controller/控制模式/姿态角控制/ctrlZ/Sum Fdbk/Enabled'
 * '<S299>' : 'controller/控制模式/姿态角控制/ctrlZ/Sum Fdbk/Passthrough'
 * '<S300>' : 'controller/控制模式/姿态角控制/ctrlZ/Tracking Mode/Disabled'
 * '<S301>' : 'controller/控制模式/姿态角控制/ctrlZ/Tracking Mode/Enabled'
 * '<S302>' : 'controller/控制模式/姿态角控制/ctrlZ/Tracking Mode Sum/Passthrough'
 * '<S303>' : 'controller/控制模式/姿态角控制/ctrlZ/Tracking Mode Sum/Tracking Mode'
 * '<S304>' : 'controller/控制模式/姿态角控制/ctrlZ/postSat Signal/Feedback_Path'
 * '<S305>' : 'controller/控制模式/姿态角控制/ctrlZ/postSat Signal/Forward_Path'
 * '<S306>' : 'controller/控制模式/姿态角控制/ctrlZ/preSat Signal/Feedback_Path'
 * '<S307>' : 'controller/控制模式/姿态角控制/ctrlZ/preSat Signal/Forward_Path'
 * '<S308>' : 'controller/控制模式/安全角速度控制/ctrlX'
 * '<S309>' : 'controller/控制模式/安全角速度控制/ctrlY'
 * '<S310>' : 'controller/控制模式/安全角速度控制/ctrlZ'
 * '<S311>' : 'controller/控制模式/安全角速度控制/ctrlX/Anti-windup'
 * '<S312>' : 'controller/控制模式/安全角速度控制/ctrlX/D Gain'
 * '<S313>' : 'controller/控制模式/安全角速度控制/ctrlX/Filter'
 * '<S314>' : 'controller/控制模式/安全角速度控制/ctrlX/Filter ICs'
 * '<S315>' : 'controller/控制模式/安全角速度控制/ctrlX/I Gain'
 * '<S316>' : 'controller/控制模式/安全角速度控制/ctrlX/Ideal P Gain'
 * '<S317>' : 'controller/控制模式/安全角速度控制/ctrlX/Ideal P Gain Fdbk'
 * '<S318>' : 'controller/控制模式/安全角速度控制/ctrlX/Integrator'
 * '<S319>' : 'controller/控制模式/安全角速度控制/ctrlX/Integrator ICs'
 * '<S320>' : 'controller/控制模式/安全角速度控制/ctrlX/N Copy'
 * '<S321>' : 'controller/控制模式/安全角速度控制/ctrlX/N Gain'
 * '<S322>' : 'controller/控制模式/安全角速度控制/ctrlX/P Copy'
 * '<S323>' : 'controller/控制模式/安全角速度控制/ctrlX/Parallel P Gain'
 * '<S324>' : 'controller/控制模式/安全角速度控制/ctrlX/Reset Signal'
 * '<S325>' : 'controller/控制模式/安全角速度控制/ctrlX/Saturation'
 * '<S326>' : 'controller/控制模式/安全角速度控制/ctrlX/Saturation Fdbk'
 * '<S327>' : 'controller/控制模式/安全角速度控制/ctrlX/Sum'
 * '<S328>' : 'controller/控制模式/安全角速度控制/ctrlX/Sum Fdbk'
 * '<S329>' : 'controller/控制模式/安全角速度控制/ctrlX/Tracking Mode'
 * '<S330>' : 'controller/控制模式/安全角速度控制/ctrlX/Tracking Mode Sum'
 * '<S331>' : 'controller/控制模式/安全角速度控制/ctrlX/postSat Signal'
 * '<S332>' : 'controller/控制模式/安全角速度控制/ctrlX/preSat Signal'
 * '<S333>' : 'controller/控制模式/安全角速度控制/ctrlX/Anti-windup/Back Calculation'
 * '<S334>' : 'controller/控制模式/安全角速度控制/ctrlX/Anti-windup/Cont. Clamping Ideal'
 * '<S335>' : 'controller/控制模式/安全角速度控制/ctrlX/Anti-windup/Cont. Clamping Parallel'
 * '<S336>' : 'controller/控制模式/安全角速度控制/ctrlX/Anti-windup/Disabled'
 * '<S337>' : 'controller/控制模式/安全角速度控制/ctrlX/Anti-windup/Disc. Clamping Ideal'
 * '<S338>' : 'controller/控制模式/安全角速度控制/ctrlX/Anti-windup/Disc. Clamping Parallel'
 * '<S339>' : 'controller/控制模式/安全角速度控制/ctrlX/Anti-windup/Passthrough'
 * '<S340>' : 'controller/控制模式/安全角速度控制/ctrlX/D Gain/Disabled'
 * '<S341>' : 'controller/控制模式/安全角速度控制/ctrlX/D Gain/External Parameters'
 * '<S342>' : 'controller/控制模式/安全角速度控制/ctrlX/D Gain/Internal Parameters'
 * '<S343>' : 'controller/控制模式/安全角速度控制/ctrlX/Filter/Cont. Filter'
 * '<S344>' : 'controller/控制模式/安全角速度控制/ctrlX/Filter/Differentiator'
 * '<S345>' : 'controller/控制模式/安全角速度控制/ctrlX/Filter/Disabled'
 * '<S346>' : 'controller/控制模式/安全角速度控制/ctrlX/Filter/Disc. Backward Euler Filter'
 * '<S347>' : 'controller/控制模式/安全角速度控制/ctrlX/Filter/Disc. Forward Euler Filter'
 * '<S348>' : 'controller/控制模式/安全角速度控制/ctrlX/Filter/Disc. Trapezoidal Filter'
 * '<S349>' : 'controller/控制模式/安全角速度控制/ctrlX/Filter ICs/Disabled'
 * '<S350>' : 'controller/控制模式/安全角速度控制/ctrlX/Filter ICs/External IC'
 * '<S351>' : 'controller/控制模式/安全角速度控制/ctrlX/Filter ICs/Internal IC - Differentiator'
 * '<S352>' : 'controller/控制模式/安全角速度控制/ctrlX/Filter ICs/Internal IC - Filter'
 * '<S353>' : 'controller/控制模式/安全角速度控制/ctrlX/I Gain/Disabled'
 * '<S354>' : 'controller/控制模式/安全角速度控制/ctrlX/I Gain/External Parameters'
 * '<S355>' : 'controller/控制模式/安全角速度控制/ctrlX/I Gain/Internal Parameters'
 * '<S356>' : 'controller/控制模式/安全角速度控制/ctrlX/Ideal P Gain/External Parameters'
 * '<S357>' : 'controller/控制模式/安全角速度控制/ctrlX/Ideal P Gain/Internal Parameters'
 * '<S358>' : 'controller/控制模式/安全角速度控制/ctrlX/Ideal P Gain/Passthrough'
 * '<S359>' : 'controller/控制模式/安全角速度控制/ctrlX/Ideal P Gain Fdbk/Disabled'
 * '<S360>' : 'controller/控制模式/安全角速度控制/ctrlX/Ideal P Gain Fdbk/External Parameters'
 * '<S361>' : 'controller/控制模式/安全角速度控制/ctrlX/Ideal P Gain Fdbk/Internal Parameters'
 * '<S362>' : 'controller/控制模式/安全角速度控制/ctrlX/Ideal P Gain Fdbk/Passthrough'
 * '<S363>' : 'controller/控制模式/安全角速度控制/ctrlX/Integrator/Continuous'
 * '<S364>' : 'controller/控制模式/安全角速度控制/ctrlX/Integrator/Disabled'
 * '<S365>' : 'controller/控制模式/安全角速度控制/ctrlX/Integrator/Discrete'
 * '<S366>' : 'controller/控制模式/安全角速度控制/ctrlX/Integrator ICs/Disabled'
 * '<S367>' : 'controller/控制模式/安全角速度控制/ctrlX/Integrator ICs/External IC'
 * '<S368>' : 'controller/控制模式/安全角速度控制/ctrlX/Integrator ICs/Internal IC'
 * '<S369>' : 'controller/控制模式/安全角速度控制/ctrlX/N Copy/Disabled'
 * '<S370>' : 'controller/控制模式/安全角速度控制/ctrlX/N Copy/Disabled wSignal Specification'
 * '<S371>' : 'controller/控制模式/安全角速度控制/ctrlX/N Copy/External Parameters'
 * '<S372>' : 'controller/控制模式/安全角速度控制/ctrlX/N Copy/Internal Parameters'
 * '<S373>' : 'controller/控制模式/安全角速度控制/ctrlX/N Gain/Disabled'
 * '<S374>' : 'controller/控制模式/安全角速度控制/ctrlX/N Gain/External Parameters'
 * '<S375>' : 'controller/控制模式/安全角速度控制/ctrlX/N Gain/Internal Parameters'
 * '<S376>' : 'controller/控制模式/安全角速度控制/ctrlX/N Gain/Passthrough'
 * '<S377>' : 'controller/控制模式/安全角速度控制/ctrlX/P Copy/Disabled'
 * '<S378>' : 'controller/控制模式/安全角速度控制/ctrlX/P Copy/External Parameters Ideal'
 * '<S379>' : 'controller/控制模式/安全角速度控制/ctrlX/P Copy/Internal Parameters Ideal'
 * '<S380>' : 'controller/控制模式/安全角速度控制/ctrlX/Parallel P Gain/Disabled'
 * '<S381>' : 'controller/控制模式/安全角速度控制/ctrlX/Parallel P Gain/External Parameters'
 * '<S382>' : 'controller/控制模式/安全角速度控制/ctrlX/Parallel P Gain/Internal Parameters'
 * '<S383>' : 'controller/控制模式/安全角速度控制/ctrlX/Parallel P Gain/Passthrough'
 * '<S384>' : 'controller/控制模式/安全角速度控制/ctrlX/Reset Signal/Disabled'
 * '<S385>' : 'controller/控制模式/安全角速度控制/ctrlX/Reset Signal/External Reset'
 * '<S386>' : 'controller/控制模式/安全角速度控制/ctrlX/Saturation/Enabled'
 * '<S387>' : 'controller/控制模式/安全角速度控制/ctrlX/Saturation/Passthrough'
 * '<S388>' : 'controller/控制模式/安全角速度控制/ctrlX/Saturation Fdbk/Disabled'
 * '<S389>' : 'controller/控制模式/安全角速度控制/ctrlX/Saturation Fdbk/Enabled'
 * '<S390>' : 'controller/控制模式/安全角速度控制/ctrlX/Saturation Fdbk/Passthrough'
 * '<S391>' : 'controller/控制模式/安全角速度控制/ctrlX/Sum/Passthrough_I'
 * '<S392>' : 'controller/控制模式/安全角速度控制/ctrlX/Sum/Passthrough_P'
 * '<S393>' : 'controller/控制模式/安全角速度控制/ctrlX/Sum/Sum_PD'
 * '<S394>' : 'controller/控制模式/安全角速度控制/ctrlX/Sum/Sum_PI'
 * '<S395>' : 'controller/控制模式/安全角速度控制/ctrlX/Sum/Sum_PID'
 * '<S396>' : 'controller/控制模式/安全角速度控制/ctrlX/Sum Fdbk/Disabled'
 * '<S397>' : 'controller/控制模式/安全角速度控制/ctrlX/Sum Fdbk/Enabled'
 * '<S398>' : 'controller/控制模式/安全角速度控制/ctrlX/Sum Fdbk/Passthrough'
 * '<S399>' : 'controller/控制模式/安全角速度控制/ctrlX/Tracking Mode/Disabled'
 * '<S400>' : 'controller/控制模式/安全角速度控制/ctrlX/Tracking Mode/Enabled'
 * '<S401>' : 'controller/控制模式/安全角速度控制/ctrlX/Tracking Mode Sum/Passthrough'
 * '<S402>' : 'controller/控制模式/安全角速度控制/ctrlX/Tracking Mode Sum/Tracking Mode'
 * '<S403>' : 'controller/控制模式/安全角速度控制/ctrlX/postSat Signal/Feedback_Path'
 * '<S404>' : 'controller/控制模式/安全角速度控制/ctrlX/postSat Signal/Forward_Path'
 * '<S405>' : 'controller/控制模式/安全角速度控制/ctrlX/preSat Signal/Feedback_Path'
 * '<S406>' : 'controller/控制模式/安全角速度控制/ctrlX/preSat Signal/Forward_Path'
 * '<S407>' : 'controller/控制模式/安全角速度控制/ctrlY/Anti-windup'
 * '<S408>' : 'controller/控制模式/安全角速度控制/ctrlY/D Gain'
 * '<S409>' : 'controller/控制模式/安全角速度控制/ctrlY/Filter'
 * '<S410>' : 'controller/控制模式/安全角速度控制/ctrlY/Filter ICs'
 * '<S411>' : 'controller/控制模式/安全角速度控制/ctrlY/I Gain'
 * '<S412>' : 'controller/控制模式/安全角速度控制/ctrlY/Ideal P Gain'
 * '<S413>' : 'controller/控制模式/安全角速度控制/ctrlY/Ideal P Gain Fdbk'
 * '<S414>' : 'controller/控制模式/安全角速度控制/ctrlY/Integrator'
 * '<S415>' : 'controller/控制模式/安全角速度控制/ctrlY/Integrator ICs'
 * '<S416>' : 'controller/控制模式/安全角速度控制/ctrlY/N Copy'
 * '<S417>' : 'controller/控制模式/安全角速度控制/ctrlY/N Gain'
 * '<S418>' : 'controller/控制模式/安全角速度控制/ctrlY/P Copy'
 * '<S419>' : 'controller/控制模式/安全角速度控制/ctrlY/Parallel P Gain'
 * '<S420>' : 'controller/控制模式/安全角速度控制/ctrlY/Reset Signal'
 * '<S421>' : 'controller/控制模式/安全角速度控制/ctrlY/Saturation'
 * '<S422>' : 'controller/控制模式/安全角速度控制/ctrlY/Saturation Fdbk'
 * '<S423>' : 'controller/控制模式/安全角速度控制/ctrlY/Sum'
 * '<S424>' : 'controller/控制模式/安全角速度控制/ctrlY/Sum Fdbk'
 * '<S425>' : 'controller/控制模式/安全角速度控制/ctrlY/Tracking Mode'
 * '<S426>' : 'controller/控制模式/安全角速度控制/ctrlY/Tracking Mode Sum'
 * '<S427>' : 'controller/控制模式/安全角速度控制/ctrlY/postSat Signal'
 * '<S428>' : 'controller/控制模式/安全角速度控制/ctrlY/preSat Signal'
 * '<S429>' : 'controller/控制模式/安全角速度控制/ctrlY/Anti-windup/Back Calculation'
 * '<S430>' : 'controller/控制模式/安全角速度控制/ctrlY/Anti-windup/Cont. Clamping Ideal'
 * '<S431>' : 'controller/控制模式/安全角速度控制/ctrlY/Anti-windup/Cont. Clamping Parallel'
 * '<S432>' : 'controller/控制模式/安全角速度控制/ctrlY/Anti-windup/Disabled'
 * '<S433>' : 'controller/控制模式/安全角速度控制/ctrlY/Anti-windup/Disc. Clamping Ideal'
 * '<S434>' : 'controller/控制模式/安全角速度控制/ctrlY/Anti-windup/Disc. Clamping Parallel'
 * '<S435>' : 'controller/控制模式/安全角速度控制/ctrlY/Anti-windup/Passthrough'
 * '<S436>' : 'controller/控制模式/安全角速度控制/ctrlY/D Gain/Disabled'
 * '<S437>' : 'controller/控制模式/安全角速度控制/ctrlY/D Gain/External Parameters'
 * '<S438>' : 'controller/控制模式/安全角速度控制/ctrlY/D Gain/Internal Parameters'
 * '<S439>' : 'controller/控制模式/安全角速度控制/ctrlY/Filter/Cont. Filter'
 * '<S440>' : 'controller/控制模式/安全角速度控制/ctrlY/Filter/Differentiator'
 * '<S441>' : 'controller/控制模式/安全角速度控制/ctrlY/Filter/Disabled'
 * '<S442>' : 'controller/控制模式/安全角速度控制/ctrlY/Filter/Disc. Backward Euler Filter'
 * '<S443>' : 'controller/控制模式/安全角速度控制/ctrlY/Filter/Disc. Forward Euler Filter'
 * '<S444>' : 'controller/控制模式/安全角速度控制/ctrlY/Filter/Disc. Trapezoidal Filter'
 * '<S445>' : 'controller/控制模式/安全角速度控制/ctrlY/Filter ICs/Disabled'
 * '<S446>' : 'controller/控制模式/安全角速度控制/ctrlY/Filter ICs/External IC'
 * '<S447>' : 'controller/控制模式/安全角速度控制/ctrlY/Filter ICs/Internal IC - Differentiator'
 * '<S448>' : 'controller/控制模式/安全角速度控制/ctrlY/Filter ICs/Internal IC - Filter'
 * '<S449>' : 'controller/控制模式/安全角速度控制/ctrlY/I Gain/Disabled'
 * '<S450>' : 'controller/控制模式/安全角速度控制/ctrlY/I Gain/External Parameters'
 * '<S451>' : 'controller/控制模式/安全角速度控制/ctrlY/I Gain/Internal Parameters'
 * '<S452>' : 'controller/控制模式/安全角速度控制/ctrlY/Ideal P Gain/External Parameters'
 * '<S453>' : 'controller/控制模式/安全角速度控制/ctrlY/Ideal P Gain/Internal Parameters'
 * '<S454>' : 'controller/控制模式/安全角速度控制/ctrlY/Ideal P Gain/Passthrough'
 * '<S455>' : 'controller/控制模式/安全角速度控制/ctrlY/Ideal P Gain Fdbk/Disabled'
 * '<S456>' : 'controller/控制模式/安全角速度控制/ctrlY/Ideal P Gain Fdbk/External Parameters'
 * '<S457>' : 'controller/控制模式/安全角速度控制/ctrlY/Ideal P Gain Fdbk/Internal Parameters'
 * '<S458>' : 'controller/控制模式/安全角速度控制/ctrlY/Ideal P Gain Fdbk/Passthrough'
 * '<S459>' : 'controller/控制模式/安全角速度控制/ctrlY/Integrator/Continuous'
 * '<S460>' : 'controller/控制模式/安全角速度控制/ctrlY/Integrator/Disabled'
 * '<S461>' : 'controller/控制模式/安全角速度控制/ctrlY/Integrator/Discrete'
 * '<S462>' : 'controller/控制模式/安全角速度控制/ctrlY/Integrator ICs/Disabled'
 * '<S463>' : 'controller/控制模式/安全角速度控制/ctrlY/Integrator ICs/External IC'
 * '<S464>' : 'controller/控制模式/安全角速度控制/ctrlY/Integrator ICs/Internal IC'
 * '<S465>' : 'controller/控制模式/安全角速度控制/ctrlY/N Copy/Disabled'
 * '<S466>' : 'controller/控制模式/安全角速度控制/ctrlY/N Copy/Disabled wSignal Specification'
 * '<S467>' : 'controller/控制模式/安全角速度控制/ctrlY/N Copy/External Parameters'
 * '<S468>' : 'controller/控制模式/安全角速度控制/ctrlY/N Copy/Internal Parameters'
 * '<S469>' : 'controller/控制模式/安全角速度控制/ctrlY/N Gain/Disabled'
 * '<S470>' : 'controller/控制模式/安全角速度控制/ctrlY/N Gain/External Parameters'
 * '<S471>' : 'controller/控制模式/安全角速度控制/ctrlY/N Gain/Internal Parameters'
 * '<S472>' : 'controller/控制模式/安全角速度控制/ctrlY/N Gain/Passthrough'
 * '<S473>' : 'controller/控制模式/安全角速度控制/ctrlY/P Copy/Disabled'
 * '<S474>' : 'controller/控制模式/安全角速度控制/ctrlY/P Copy/External Parameters Ideal'
 * '<S475>' : 'controller/控制模式/安全角速度控制/ctrlY/P Copy/Internal Parameters Ideal'
 * '<S476>' : 'controller/控制模式/安全角速度控制/ctrlY/Parallel P Gain/Disabled'
 * '<S477>' : 'controller/控制模式/安全角速度控制/ctrlY/Parallel P Gain/External Parameters'
 * '<S478>' : 'controller/控制模式/安全角速度控制/ctrlY/Parallel P Gain/Internal Parameters'
 * '<S479>' : 'controller/控制模式/安全角速度控制/ctrlY/Parallel P Gain/Passthrough'
 * '<S480>' : 'controller/控制模式/安全角速度控制/ctrlY/Reset Signal/Disabled'
 * '<S481>' : 'controller/控制模式/安全角速度控制/ctrlY/Reset Signal/External Reset'
 * '<S482>' : 'controller/控制模式/安全角速度控制/ctrlY/Saturation/Enabled'
 * '<S483>' : 'controller/控制模式/安全角速度控制/ctrlY/Saturation/Passthrough'
 * '<S484>' : 'controller/控制模式/安全角速度控制/ctrlY/Saturation Fdbk/Disabled'
 * '<S485>' : 'controller/控制模式/安全角速度控制/ctrlY/Saturation Fdbk/Enabled'
 * '<S486>' : 'controller/控制模式/安全角速度控制/ctrlY/Saturation Fdbk/Passthrough'
 * '<S487>' : 'controller/控制模式/安全角速度控制/ctrlY/Sum/Passthrough_I'
 * '<S488>' : 'controller/控制模式/安全角速度控制/ctrlY/Sum/Passthrough_P'
 * '<S489>' : 'controller/控制模式/安全角速度控制/ctrlY/Sum/Sum_PD'
 * '<S490>' : 'controller/控制模式/安全角速度控制/ctrlY/Sum/Sum_PI'
 * '<S491>' : 'controller/控制模式/安全角速度控制/ctrlY/Sum/Sum_PID'
 * '<S492>' : 'controller/控制模式/安全角速度控制/ctrlY/Sum Fdbk/Disabled'
 * '<S493>' : 'controller/控制模式/安全角速度控制/ctrlY/Sum Fdbk/Enabled'
 * '<S494>' : 'controller/控制模式/安全角速度控制/ctrlY/Sum Fdbk/Passthrough'
 * '<S495>' : 'controller/控制模式/安全角速度控制/ctrlY/Tracking Mode/Disabled'
 * '<S496>' : 'controller/控制模式/安全角速度控制/ctrlY/Tracking Mode/Enabled'
 * '<S497>' : 'controller/控制模式/安全角速度控制/ctrlY/Tracking Mode Sum/Passthrough'
 * '<S498>' : 'controller/控制模式/安全角速度控制/ctrlY/Tracking Mode Sum/Tracking Mode'
 * '<S499>' : 'controller/控制模式/安全角速度控制/ctrlY/postSat Signal/Feedback_Path'
 * '<S500>' : 'controller/控制模式/安全角速度控制/ctrlY/postSat Signal/Forward_Path'
 * '<S501>' : 'controller/控制模式/安全角速度控制/ctrlY/preSat Signal/Feedback_Path'
 * '<S502>' : 'controller/控制模式/安全角速度控制/ctrlY/preSat Signal/Forward_Path'
 * '<S503>' : 'controller/控制模式/安全角速度控制/ctrlZ/Anti-windup'
 * '<S504>' : 'controller/控制模式/安全角速度控制/ctrlZ/D Gain'
 * '<S505>' : 'controller/控制模式/安全角速度控制/ctrlZ/Filter'
 * '<S506>' : 'controller/控制模式/安全角速度控制/ctrlZ/Filter ICs'
 * '<S507>' : 'controller/控制模式/安全角速度控制/ctrlZ/I Gain'
 * '<S508>' : 'controller/控制模式/安全角速度控制/ctrlZ/Ideal P Gain'
 * '<S509>' : 'controller/控制模式/安全角速度控制/ctrlZ/Ideal P Gain Fdbk'
 * '<S510>' : 'controller/控制模式/安全角速度控制/ctrlZ/Integrator'
 * '<S511>' : 'controller/控制模式/安全角速度控制/ctrlZ/Integrator ICs'
 * '<S512>' : 'controller/控制模式/安全角速度控制/ctrlZ/N Copy'
 * '<S513>' : 'controller/控制模式/安全角速度控制/ctrlZ/N Gain'
 * '<S514>' : 'controller/控制模式/安全角速度控制/ctrlZ/P Copy'
 * '<S515>' : 'controller/控制模式/安全角速度控制/ctrlZ/Parallel P Gain'
 * '<S516>' : 'controller/控制模式/安全角速度控制/ctrlZ/Reset Signal'
 * '<S517>' : 'controller/控制模式/安全角速度控制/ctrlZ/Saturation'
 * '<S518>' : 'controller/控制模式/安全角速度控制/ctrlZ/Saturation Fdbk'
 * '<S519>' : 'controller/控制模式/安全角速度控制/ctrlZ/Sum'
 * '<S520>' : 'controller/控制模式/安全角速度控制/ctrlZ/Sum Fdbk'
 * '<S521>' : 'controller/控制模式/安全角速度控制/ctrlZ/Tracking Mode'
 * '<S522>' : 'controller/控制模式/安全角速度控制/ctrlZ/Tracking Mode Sum'
 * '<S523>' : 'controller/控制模式/安全角速度控制/ctrlZ/postSat Signal'
 * '<S524>' : 'controller/控制模式/安全角速度控制/ctrlZ/preSat Signal'
 * '<S525>' : 'controller/控制模式/安全角速度控制/ctrlZ/Anti-windup/Back Calculation'
 * '<S526>' : 'controller/控制模式/安全角速度控制/ctrlZ/Anti-windup/Cont. Clamping Ideal'
 * '<S527>' : 'controller/控制模式/安全角速度控制/ctrlZ/Anti-windup/Cont. Clamping Parallel'
 * '<S528>' : 'controller/控制模式/安全角速度控制/ctrlZ/Anti-windup/Disabled'
 * '<S529>' : 'controller/控制模式/安全角速度控制/ctrlZ/Anti-windup/Disc. Clamping Ideal'
 * '<S530>' : 'controller/控制模式/安全角速度控制/ctrlZ/Anti-windup/Disc. Clamping Parallel'
 * '<S531>' : 'controller/控制模式/安全角速度控制/ctrlZ/Anti-windup/Passthrough'
 * '<S532>' : 'controller/控制模式/安全角速度控制/ctrlZ/D Gain/Disabled'
 * '<S533>' : 'controller/控制模式/安全角速度控制/ctrlZ/D Gain/External Parameters'
 * '<S534>' : 'controller/控制模式/安全角速度控制/ctrlZ/D Gain/Internal Parameters'
 * '<S535>' : 'controller/控制模式/安全角速度控制/ctrlZ/Filter/Cont. Filter'
 * '<S536>' : 'controller/控制模式/安全角速度控制/ctrlZ/Filter/Differentiator'
 * '<S537>' : 'controller/控制模式/安全角速度控制/ctrlZ/Filter/Disabled'
 * '<S538>' : 'controller/控制模式/安全角速度控制/ctrlZ/Filter/Disc. Backward Euler Filter'
 * '<S539>' : 'controller/控制模式/安全角速度控制/ctrlZ/Filter/Disc. Forward Euler Filter'
 * '<S540>' : 'controller/控制模式/安全角速度控制/ctrlZ/Filter/Disc. Trapezoidal Filter'
 * '<S541>' : 'controller/控制模式/安全角速度控制/ctrlZ/Filter ICs/Disabled'
 * '<S542>' : 'controller/控制模式/安全角速度控制/ctrlZ/Filter ICs/External IC'
 * '<S543>' : 'controller/控制模式/安全角速度控制/ctrlZ/Filter ICs/Internal IC - Differentiator'
 * '<S544>' : 'controller/控制模式/安全角速度控制/ctrlZ/Filter ICs/Internal IC - Filter'
 * '<S545>' : 'controller/控制模式/安全角速度控制/ctrlZ/I Gain/Disabled'
 * '<S546>' : 'controller/控制模式/安全角速度控制/ctrlZ/I Gain/External Parameters'
 * '<S547>' : 'controller/控制模式/安全角速度控制/ctrlZ/I Gain/Internal Parameters'
 * '<S548>' : 'controller/控制模式/安全角速度控制/ctrlZ/Ideal P Gain/External Parameters'
 * '<S549>' : 'controller/控制模式/安全角速度控制/ctrlZ/Ideal P Gain/Internal Parameters'
 * '<S550>' : 'controller/控制模式/安全角速度控制/ctrlZ/Ideal P Gain/Passthrough'
 * '<S551>' : 'controller/控制模式/安全角速度控制/ctrlZ/Ideal P Gain Fdbk/Disabled'
 * '<S552>' : 'controller/控制模式/安全角速度控制/ctrlZ/Ideal P Gain Fdbk/External Parameters'
 * '<S553>' : 'controller/控制模式/安全角速度控制/ctrlZ/Ideal P Gain Fdbk/Internal Parameters'
 * '<S554>' : 'controller/控制模式/安全角速度控制/ctrlZ/Ideal P Gain Fdbk/Passthrough'
 * '<S555>' : 'controller/控制模式/安全角速度控制/ctrlZ/Integrator/Continuous'
 * '<S556>' : 'controller/控制模式/安全角速度控制/ctrlZ/Integrator/Disabled'
 * '<S557>' : 'controller/控制模式/安全角速度控制/ctrlZ/Integrator/Discrete'
 * '<S558>' : 'controller/控制模式/安全角速度控制/ctrlZ/Integrator ICs/Disabled'
 * '<S559>' : 'controller/控制模式/安全角速度控制/ctrlZ/Integrator ICs/External IC'
 * '<S560>' : 'controller/控制模式/安全角速度控制/ctrlZ/Integrator ICs/Internal IC'
 * '<S561>' : 'controller/控制模式/安全角速度控制/ctrlZ/N Copy/Disabled'
 * '<S562>' : 'controller/控制模式/安全角速度控制/ctrlZ/N Copy/Disabled wSignal Specification'
 * '<S563>' : 'controller/控制模式/安全角速度控制/ctrlZ/N Copy/External Parameters'
 * '<S564>' : 'controller/控制模式/安全角速度控制/ctrlZ/N Copy/Internal Parameters'
 * '<S565>' : 'controller/控制模式/安全角速度控制/ctrlZ/N Gain/Disabled'
 * '<S566>' : 'controller/控制模式/安全角速度控制/ctrlZ/N Gain/External Parameters'
 * '<S567>' : 'controller/控制模式/安全角速度控制/ctrlZ/N Gain/Internal Parameters'
 * '<S568>' : 'controller/控制模式/安全角速度控制/ctrlZ/N Gain/Passthrough'
 * '<S569>' : 'controller/控制模式/安全角速度控制/ctrlZ/P Copy/Disabled'
 * '<S570>' : 'controller/控制模式/安全角速度控制/ctrlZ/P Copy/External Parameters Ideal'
 * '<S571>' : 'controller/控制模式/安全角速度控制/ctrlZ/P Copy/Internal Parameters Ideal'
 * '<S572>' : 'controller/控制模式/安全角速度控制/ctrlZ/Parallel P Gain/Disabled'
 * '<S573>' : 'controller/控制模式/安全角速度控制/ctrlZ/Parallel P Gain/External Parameters'
 * '<S574>' : 'controller/控制模式/安全角速度控制/ctrlZ/Parallel P Gain/Internal Parameters'
 * '<S575>' : 'controller/控制模式/安全角速度控制/ctrlZ/Parallel P Gain/Passthrough'
 * '<S576>' : 'controller/控制模式/安全角速度控制/ctrlZ/Reset Signal/Disabled'
 * '<S577>' : 'controller/控制模式/安全角速度控制/ctrlZ/Reset Signal/External Reset'
 * '<S578>' : 'controller/控制模式/安全角速度控制/ctrlZ/Saturation/Enabled'
 * '<S579>' : 'controller/控制模式/安全角速度控制/ctrlZ/Saturation/Passthrough'
 * '<S580>' : 'controller/控制模式/安全角速度控制/ctrlZ/Saturation Fdbk/Disabled'
 * '<S581>' : 'controller/控制模式/安全角速度控制/ctrlZ/Saturation Fdbk/Enabled'
 * '<S582>' : 'controller/控制模式/安全角速度控制/ctrlZ/Saturation Fdbk/Passthrough'
 * '<S583>' : 'controller/控制模式/安全角速度控制/ctrlZ/Sum/Passthrough_I'
 * '<S584>' : 'controller/控制模式/安全角速度控制/ctrlZ/Sum/Passthrough_P'
 * '<S585>' : 'controller/控制模式/安全角速度控制/ctrlZ/Sum/Sum_PD'
 * '<S586>' : 'controller/控制模式/安全角速度控制/ctrlZ/Sum/Sum_PI'
 * '<S587>' : 'controller/控制模式/安全角速度控制/ctrlZ/Sum/Sum_PID'
 * '<S588>' : 'controller/控制模式/安全角速度控制/ctrlZ/Sum Fdbk/Disabled'
 * '<S589>' : 'controller/控制模式/安全角速度控制/ctrlZ/Sum Fdbk/Enabled'
 * '<S590>' : 'controller/控制模式/安全角速度控制/ctrlZ/Sum Fdbk/Passthrough'
 * '<S591>' : 'controller/控制模式/安全角速度控制/ctrlZ/Tracking Mode/Disabled'
 * '<S592>' : 'controller/控制模式/安全角速度控制/ctrlZ/Tracking Mode/Enabled'
 * '<S593>' : 'controller/控制模式/安全角速度控制/ctrlZ/Tracking Mode Sum/Passthrough'
 * '<S594>' : 'controller/控制模式/安全角速度控制/ctrlZ/Tracking Mode Sum/Tracking Mode'
 * '<S595>' : 'controller/控制模式/安全角速度控制/ctrlZ/postSat Signal/Feedback_Path'
 * '<S596>' : 'controller/控制模式/安全角速度控制/ctrlZ/postSat Signal/Forward_Path'
 * '<S597>' : 'controller/控制模式/安全角速度控制/ctrlZ/preSat Signal/Feedback_Path'
 * '<S598>' : 'controller/控制模式/安全角速度控制/ctrlZ/preSat Signal/Forward_Path'
 * '<S599>' : 'controller/控制模式/惯性四元数控制/MATLAB Function'
 * '<S600>' : 'controller/控制模式/惯性四元数控制/ctrlX'
 * '<S601>' : 'controller/控制模式/惯性四元数控制/ctrlY'
 * '<S602>' : 'controller/控制模式/惯性四元数控制/ctrlZ'
 * '<S603>' : 'controller/控制模式/惯性四元数控制/ctrlX/Anti-windup'
 * '<S604>' : 'controller/控制模式/惯性四元数控制/ctrlX/D Gain'
 * '<S605>' : 'controller/控制模式/惯性四元数控制/ctrlX/Filter'
 * '<S606>' : 'controller/控制模式/惯性四元数控制/ctrlX/Filter ICs'
 * '<S607>' : 'controller/控制模式/惯性四元数控制/ctrlX/I Gain'
 * '<S608>' : 'controller/控制模式/惯性四元数控制/ctrlX/Ideal P Gain'
 * '<S609>' : 'controller/控制模式/惯性四元数控制/ctrlX/Ideal P Gain Fdbk'
 * '<S610>' : 'controller/控制模式/惯性四元数控制/ctrlX/Integrator'
 * '<S611>' : 'controller/控制模式/惯性四元数控制/ctrlX/Integrator ICs'
 * '<S612>' : 'controller/控制模式/惯性四元数控制/ctrlX/N Copy'
 * '<S613>' : 'controller/控制模式/惯性四元数控制/ctrlX/N Gain'
 * '<S614>' : 'controller/控制模式/惯性四元数控制/ctrlX/P Copy'
 * '<S615>' : 'controller/控制模式/惯性四元数控制/ctrlX/Parallel P Gain'
 * '<S616>' : 'controller/控制模式/惯性四元数控制/ctrlX/Reset Signal'
 * '<S617>' : 'controller/控制模式/惯性四元数控制/ctrlX/Saturation'
 * '<S618>' : 'controller/控制模式/惯性四元数控制/ctrlX/Saturation Fdbk'
 * '<S619>' : 'controller/控制模式/惯性四元数控制/ctrlX/Sum'
 * '<S620>' : 'controller/控制模式/惯性四元数控制/ctrlX/Sum Fdbk'
 * '<S621>' : 'controller/控制模式/惯性四元数控制/ctrlX/Tracking Mode'
 * '<S622>' : 'controller/控制模式/惯性四元数控制/ctrlX/Tracking Mode Sum'
 * '<S623>' : 'controller/控制模式/惯性四元数控制/ctrlX/postSat Signal'
 * '<S624>' : 'controller/控制模式/惯性四元数控制/ctrlX/preSat Signal'
 * '<S625>' : 'controller/控制模式/惯性四元数控制/ctrlX/Anti-windup/Back Calculation'
 * '<S626>' : 'controller/控制模式/惯性四元数控制/ctrlX/Anti-windup/Cont. Clamping Ideal'
 * '<S627>' : 'controller/控制模式/惯性四元数控制/ctrlX/Anti-windup/Cont. Clamping Parallel'
 * '<S628>' : 'controller/控制模式/惯性四元数控制/ctrlX/Anti-windup/Disabled'
 * '<S629>' : 'controller/控制模式/惯性四元数控制/ctrlX/Anti-windup/Disc. Clamping Ideal'
 * '<S630>' : 'controller/控制模式/惯性四元数控制/ctrlX/Anti-windup/Disc. Clamping Parallel'
 * '<S631>' : 'controller/控制模式/惯性四元数控制/ctrlX/Anti-windup/Passthrough'
 * '<S632>' : 'controller/控制模式/惯性四元数控制/ctrlX/D Gain/Disabled'
 * '<S633>' : 'controller/控制模式/惯性四元数控制/ctrlX/D Gain/External Parameters'
 * '<S634>' : 'controller/控制模式/惯性四元数控制/ctrlX/D Gain/Internal Parameters'
 * '<S635>' : 'controller/控制模式/惯性四元数控制/ctrlX/Filter/Cont. Filter'
 * '<S636>' : 'controller/控制模式/惯性四元数控制/ctrlX/Filter/Differentiator'
 * '<S637>' : 'controller/控制模式/惯性四元数控制/ctrlX/Filter/Disabled'
 * '<S638>' : 'controller/控制模式/惯性四元数控制/ctrlX/Filter/Disc. Backward Euler Filter'
 * '<S639>' : 'controller/控制模式/惯性四元数控制/ctrlX/Filter/Disc. Forward Euler Filter'
 * '<S640>' : 'controller/控制模式/惯性四元数控制/ctrlX/Filter/Disc. Trapezoidal Filter'
 * '<S641>' : 'controller/控制模式/惯性四元数控制/ctrlX/Filter ICs/Disabled'
 * '<S642>' : 'controller/控制模式/惯性四元数控制/ctrlX/Filter ICs/External IC'
 * '<S643>' : 'controller/控制模式/惯性四元数控制/ctrlX/Filter ICs/Internal IC - Differentiator'
 * '<S644>' : 'controller/控制模式/惯性四元数控制/ctrlX/Filter ICs/Internal IC - Filter'
 * '<S645>' : 'controller/控制模式/惯性四元数控制/ctrlX/I Gain/Disabled'
 * '<S646>' : 'controller/控制模式/惯性四元数控制/ctrlX/I Gain/External Parameters'
 * '<S647>' : 'controller/控制模式/惯性四元数控制/ctrlX/I Gain/Internal Parameters'
 * '<S648>' : 'controller/控制模式/惯性四元数控制/ctrlX/Ideal P Gain/External Parameters'
 * '<S649>' : 'controller/控制模式/惯性四元数控制/ctrlX/Ideal P Gain/Internal Parameters'
 * '<S650>' : 'controller/控制模式/惯性四元数控制/ctrlX/Ideal P Gain/Passthrough'
 * '<S651>' : 'controller/控制模式/惯性四元数控制/ctrlX/Ideal P Gain Fdbk/Disabled'
 * '<S652>' : 'controller/控制模式/惯性四元数控制/ctrlX/Ideal P Gain Fdbk/External Parameters'
 * '<S653>' : 'controller/控制模式/惯性四元数控制/ctrlX/Ideal P Gain Fdbk/Internal Parameters'
 * '<S654>' : 'controller/控制模式/惯性四元数控制/ctrlX/Ideal P Gain Fdbk/Passthrough'
 * '<S655>' : 'controller/控制模式/惯性四元数控制/ctrlX/Integrator/Continuous'
 * '<S656>' : 'controller/控制模式/惯性四元数控制/ctrlX/Integrator/Disabled'
 * '<S657>' : 'controller/控制模式/惯性四元数控制/ctrlX/Integrator/Discrete'
 * '<S658>' : 'controller/控制模式/惯性四元数控制/ctrlX/Integrator ICs/Disabled'
 * '<S659>' : 'controller/控制模式/惯性四元数控制/ctrlX/Integrator ICs/External IC'
 * '<S660>' : 'controller/控制模式/惯性四元数控制/ctrlX/Integrator ICs/Internal IC'
 * '<S661>' : 'controller/控制模式/惯性四元数控制/ctrlX/N Copy/Disabled'
 * '<S662>' : 'controller/控制模式/惯性四元数控制/ctrlX/N Copy/Disabled wSignal Specification'
 * '<S663>' : 'controller/控制模式/惯性四元数控制/ctrlX/N Copy/External Parameters'
 * '<S664>' : 'controller/控制模式/惯性四元数控制/ctrlX/N Copy/Internal Parameters'
 * '<S665>' : 'controller/控制模式/惯性四元数控制/ctrlX/N Gain/Disabled'
 * '<S666>' : 'controller/控制模式/惯性四元数控制/ctrlX/N Gain/External Parameters'
 * '<S667>' : 'controller/控制模式/惯性四元数控制/ctrlX/N Gain/Internal Parameters'
 * '<S668>' : 'controller/控制模式/惯性四元数控制/ctrlX/N Gain/Passthrough'
 * '<S669>' : 'controller/控制模式/惯性四元数控制/ctrlX/P Copy/Disabled'
 * '<S670>' : 'controller/控制模式/惯性四元数控制/ctrlX/P Copy/External Parameters Ideal'
 * '<S671>' : 'controller/控制模式/惯性四元数控制/ctrlX/P Copy/Internal Parameters Ideal'
 * '<S672>' : 'controller/控制模式/惯性四元数控制/ctrlX/Parallel P Gain/Disabled'
 * '<S673>' : 'controller/控制模式/惯性四元数控制/ctrlX/Parallel P Gain/External Parameters'
 * '<S674>' : 'controller/控制模式/惯性四元数控制/ctrlX/Parallel P Gain/Internal Parameters'
 * '<S675>' : 'controller/控制模式/惯性四元数控制/ctrlX/Parallel P Gain/Passthrough'
 * '<S676>' : 'controller/控制模式/惯性四元数控制/ctrlX/Reset Signal/Disabled'
 * '<S677>' : 'controller/控制模式/惯性四元数控制/ctrlX/Reset Signal/External Reset'
 * '<S678>' : 'controller/控制模式/惯性四元数控制/ctrlX/Saturation/Enabled'
 * '<S679>' : 'controller/控制模式/惯性四元数控制/ctrlX/Saturation/Passthrough'
 * '<S680>' : 'controller/控制模式/惯性四元数控制/ctrlX/Saturation Fdbk/Disabled'
 * '<S681>' : 'controller/控制模式/惯性四元数控制/ctrlX/Saturation Fdbk/Enabled'
 * '<S682>' : 'controller/控制模式/惯性四元数控制/ctrlX/Saturation Fdbk/Passthrough'
 * '<S683>' : 'controller/控制模式/惯性四元数控制/ctrlX/Sum/Passthrough_I'
 * '<S684>' : 'controller/控制模式/惯性四元数控制/ctrlX/Sum/Passthrough_P'
 * '<S685>' : 'controller/控制模式/惯性四元数控制/ctrlX/Sum/Sum_PD'
 * '<S686>' : 'controller/控制模式/惯性四元数控制/ctrlX/Sum/Sum_PI'
 * '<S687>' : 'controller/控制模式/惯性四元数控制/ctrlX/Sum/Sum_PID'
 * '<S688>' : 'controller/控制模式/惯性四元数控制/ctrlX/Sum Fdbk/Disabled'
 * '<S689>' : 'controller/控制模式/惯性四元数控制/ctrlX/Sum Fdbk/Enabled'
 * '<S690>' : 'controller/控制模式/惯性四元数控制/ctrlX/Sum Fdbk/Passthrough'
 * '<S691>' : 'controller/控制模式/惯性四元数控制/ctrlX/Tracking Mode/Disabled'
 * '<S692>' : 'controller/控制模式/惯性四元数控制/ctrlX/Tracking Mode/Enabled'
 * '<S693>' : 'controller/控制模式/惯性四元数控制/ctrlX/Tracking Mode Sum/Passthrough'
 * '<S694>' : 'controller/控制模式/惯性四元数控制/ctrlX/Tracking Mode Sum/Tracking Mode'
 * '<S695>' : 'controller/控制模式/惯性四元数控制/ctrlX/postSat Signal/Feedback_Path'
 * '<S696>' : 'controller/控制模式/惯性四元数控制/ctrlX/postSat Signal/Forward_Path'
 * '<S697>' : 'controller/控制模式/惯性四元数控制/ctrlX/preSat Signal/Feedback_Path'
 * '<S698>' : 'controller/控制模式/惯性四元数控制/ctrlX/preSat Signal/Forward_Path'
 * '<S699>' : 'controller/控制模式/惯性四元数控制/ctrlY/Anti-windup'
 * '<S700>' : 'controller/控制模式/惯性四元数控制/ctrlY/D Gain'
 * '<S701>' : 'controller/控制模式/惯性四元数控制/ctrlY/Filter'
 * '<S702>' : 'controller/控制模式/惯性四元数控制/ctrlY/Filter ICs'
 * '<S703>' : 'controller/控制模式/惯性四元数控制/ctrlY/I Gain'
 * '<S704>' : 'controller/控制模式/惯性四元数控制/ctrlY/Ideal P Gain'
 * '<S705>' : 'controller/控制模式/惯性四元数控制/ctrlY/Ideal P Gain Fdbk'
 * '<S706>' : 'controller/控制模式/惯性四元数控制/ctrlY/Integrator'
 * '<S707>' : 'controller/控制模式/惯性四元数控制/ctrlY/Integrator ICs'
 * '<S708>' : 'controller/控制模式/惯性四元数控制/ctrlY/N Copy'
 * '<S709>' : 'controller/控制模式/惯性四元数控制/ctrlY/N Gain'
 * '<S710>' : 'controller/控制模式/惯性四元数控制/ctrlY/P Copy'
 * '<S711>' : 'controller/控制模式/惯性四元数控制/ctrlY/Parallel P Gain'
 * '<S712>' : 'controller/控制模式/惯性四元数控制/ctrlY/Reset Signal'
 * '<S713>' : 'controller/控制模式/惯性四元数控制/ctrlY/Saturation'
 * '<S714>' : 'controller/控制模式/惯性四元数控制/ctrlY/Saturation Fdbk'
 * '<S715>' : 'controller/控制模式/惯性四元数控制/ctrlY/Sum'
 * '<S716>' : 'controller/控制模式/惯性四元数控制/ctrlY/Sum Fdbk'
 * '<S717>' : 'controller/控制模式/惯性四元数控制/ctrlY/Tracking Mode'
 * '<S718>' : 'controller/控制模式/惯性四元数控制/ctrlY/Tracking Mode Sum'
 * '<S719>' : 'controller/控制模式/惯性四元数控制/ctrlY/postSat Signal'
 * '<S720>' : 'controller/控制模式/惯性四元数控制/ctrlY/preSat Signal'
 * '<S721>' : 'controller/控制模式/惯性四元数控制/ctrlY/Anti-windup/Back Calculation'
 * '<S722>' : 'controller/控制模式/惯性四元数控制/ctrlY/Anti-windup/Cont. Clamping Ideal'
 * '<S723>' : 'controller/控制模式/惯性四元数控制/ctrlY/Anti-windup/Cont. Clamping Parallel'
 * '<S724>' : 'controller/控制模式/惯性四元数控制/ctrlY/Anti-windup/Disabled'
 * '<S725>' : 'controller/控制模式/惯性四元数控制/ctrlY/Anti-windup/Disc. Clamping Ideal'
 * '<S726>' : 'controller/控制模式/惯性四元数控制/ctrlY/Anti-windup/Disc. Clamping Parallel'
 * '<S727>' : 'controller/控制模式/惯性四元数控制/ctrlY/Anti-windup/Passthrough'
 * '<S728>' : 'controller/控制模式/惯性四元数控制/ctrlY/D Gain/Disabled'
 * '<S729>' : 'controller/控制模式/惯性四元数控制/ctrlY/D Gain/External Parameters'
 * '<S730>' : 'controller/控制模式/惯性四元数控制/ctrlY/D Gain/Internal Parameters'
 * '<S731>' : 'controller/控制模式/惯性四元数控制/ctrlY/Filter/Cont. Filter'
 * '<S732>' : 'controller/控制模式/惯性四元数控制/ctrlY/Filter/Differentiator'
 * '<S733>' : 'controller/控制模式/惯性四元数控制/ctrlY/Filter/Disabled'
 * '<S734>' : 'controller/控制模式/惯性四元数控制/ctrlY/Filter/Disc. Backward Euler Filter'
 * '<S735>' : 'controller/控制模式/惯性四元数控制/ctrlY/Filter/Disc. Forward Euler Filter'
 * '<S736>' : 'controller/控制模式/惯性四元数控制/ctrlY/Filter/Disc. Trapezoidal Filter'
 * '<S737>' : 'controller/控制模式/惯性四元数控制/ctrlY/Filter ICs/Disabled'
 * '<S738>' : 'controller/控制模式/惯性四元数控制/ctrlY/Filter ICs/External IC'
 * '<S739>' : 'controller/控制模式/惯性四元数控制/ctrlY/Filter ICs/Internal IC - Differentiator'
 * '<S740>' : 'controller/控制模式/惯性四元数控制/ctrlY/Filter ICs/Internal IC - Filter'
 * '<S741>' : 'controller/控制模式/惯性四元数控制/ctrlY/I Gain/Disabled'
 * '<S742>' : 'controller/控制模式/惯性四元数控制/ctrlY/I Gain/External Parameters'
 * '<S743>' : 'controller/控制模式/惯性四元数控制/ctrlY/I Gain/Internal Parameters'
 * '<S744>' : 'controller/控制模式/惯性四元数控制/ctrlY/Ideal P Gain/External Parameters'
 * '<S745>' : 'controller/控制模式/惯性四元数控制/ctrlY/Ideal P Gain/Internal Parameters'
 * '<S746>' : 'controller/控制模式/惯性四元数控制/ctrlY/Ideal P Gain/Passthrough'
 * '<S747>' : 'controller/控制模式/惯性四元数控制/ctrlY/Ideal P Gain Fdbk/Disabled'
 * '<S748>' : 'controller/控制模式/惯性四元数控制/ctrlY/Ideal P Gain Fdbk/External Parameters'
 * '<S749>' : 'controller/控制模式/惯性四元数控制/ctrlY/Ideal P Gain Fdbk/Internal Parameters'
 * '<S750>' : 'controller/控制模式/惯性四元数控制/ctrlY/Ideal P Gain Fdbk/Passthrough'
 * '<S751>' : 'controller/控制模式/惯性四元数控制/ctrlY/Integrator/Continuous'
 * '<S752>' : 'controller/控制模式/惯性四元数控制/ctrlY/Integrator/Disabled'
 * '<S753>' : 'controller/控制模式/惯性四元数控制/ctrlY/Integrator/Discrete'
 * '<S754>' : 'controller/控制模式/惯性四元数控制/ctrlY/Integrator ICs/Disabled'
 * '<S755>' : 'controller/控制模式/惯性四元数控制/ctrlY/Integrator ICs/External IC'
 * '<S756>' : 'controller/控制模式/惯性四元数控制/ctrlY/Integrator ICs/Internal IC'
 * '<S757>' : 'controller/控制模式/惯性四元数控制/ctrlY/N Copy/Disabled'
 * '<S758>' : 'controller/控制模式/惯性四元数控制/ctrlY/N Copy/Disabled wSignal Specification'
 * '<S759>' : 'controller/控制模式/惯性四元数控制/ctrlY/N Copy/External Parameters'
 * '<S760>' : 'controller/控制模式/惯性四元数控制/ctrlY/N Copy/Internal Parameters'
 * '<S761>' : 'controller/控制模式/惯性四元数控制/ctrlY/N Gain/Disabled'
 * '<S762>' : 'controller/控制模式/惯性四元数控制/ctrlY/N Gain/External Parameters'
 * '<S763>' : 'controller/控制模式/惯性四元数控制/ctrlY/N Gain/Internal Parameters'
 * '<S764>' : 'controller/控制模式/惯性四元数控制/ctrlY/N Gain/Passthrough'
 * '<S765>' : 'controller/控制模式/惯性四元数控制/ctrlY/P Copy/Disabled'
 * '<S766>' : 'controller/控制模式/惯性四元数控制/ctrlY/P Copy/External Parameters Ideal'
 * '<S767>' : 'controller/控制模式/惯性四元数控制/ctrlY/P Copy/Internal Parameters Ideal'
 * '<S768>' : 'controller/控制模式/惯性四元数控制/ctrlY/Parallel P Gain/Disabled'
 * '<S769>' : 'controller/控制模式/惯性四元数控制/ctrlY/Parallel P Gain/External Parameters'
 * '<S770>' : 'controller/控制模式/惯性四元数控制/ctrlY/Parallel P Gain/Internal Parameters'
 * '<S771>' : 'controller/控制模式/惯性四元数控制/ctrlY/Parallel P Gain/Passthrough'
 * '<S772>' : 'controller/控制模式/惯性四元数控制/ctrlY/Reset Signal/Disabled'
 * '<S773>' : 'controller/控制模式/惯性四元数控制/ctrlY/Reset Signal/External Reset'
 * '<S774>' : 'controller/控制模式/惯性四元数控制/ctrlY/Saturation/Enabled'
 * '<S775>' : 'controller/控制模式/惯性四元数控制/ctrlY/Saturation/Passthrough'
 * '<S776>' : 'controller/控制模式/惯性四元数控制/ctrlY/Saturation Fdbk/Disabled'
 * '<S777>' : 'controller/控制模式/惯性四元数控制/ctrlY/Saturation Fdbk/Enabled'
 * '<S778>' : 'controller/控制模式/惯性四元数控制/ctrlY/Saturation Fdbk/Passthrough'
 * '<S779>' : 'controller/控制模式/惯性四元数控制/ctrlY/Sum/Passthrough_I'
 * '<S780>' : 'controller/控制模式/惯性四元数控制/ctrlY/Sum/Passthrough_P'
 * '<S781>' : 'controller/控制模式/惯性四元数控制/ctrlY/Sum/Sum_PD'
 * '<S782>' : 'controller/控制模式/惯性四元数控制/ctrlY/Sum/Sum_PI'
 * '<S783>' : 'controller/控制模式/惯性四元数控制/ctrlY/Sum/Sum_PID'
 * '<S784>' : 'controller/控制模式/惯性四元数控制/ctrlY/Sum Fdbk/Disabled'
 * '<S785>' : 'controller/控制模式/惯性四元数控制/ctrlY/Sum Fdbk/Enabled'
 * '<S786>' : 'controller/控制模式/惯性四元数控制/ctrlY/Sum Fdbk/Passthrough'
 * '<S787>' : 'controller/控制模式/惯性四元数控制/ctrlY/Tracking Mode/Disabled'
 * '<S788>' : 'controller/控制模式/惯性四元数控制/ctrlY/Tracking Mode/Enabled'
 * '<S789>' : 'controller/控制模式/惯性四元数控制/ctrlY/Tracking Mode Sum/Passthrough'
 * '<S790>' : 'controller/控制模式/惯性四元数控制/ctrlY/Tracking Mode Sum/Tracking Mode'
 * '<S791>' : 'controller/控制模式/惯性四元数控制/ctrlY/postSat Signal/Feedback_Path'
 * '<S792>' : 'controller/控制模式/惯性四元数控制/ctrlY/postSat Signal/Forward_Path'
 * '<S793>' : 'controller/控制模式/惯性四元数控制/ctrlY/preSat Signal/Feedback_Path'
 * '<S794>' : 'controller/控制模式/惯性四元数控制/ctrlY/preSat Signal/Forward_Path'
 * '<S795>' : 'controller/控制模式/惯性四元数控制/ctrlZ/Anti-windup'
 * '<S796>' : 'controller/控制模式/惯性四元数控制/ctrlZ/D Gain'
 * '<S797>' : 'controller/控制模式/惯性四元数控制/ctrlZ/Filter'
 * '<S798>' : 'controller/控制模式/惯性四元数控制/ctrlZ/Filter ICs'
 * '<S799>' : 'controller/控制模式/惯性四元数控制/ctrlZ/I Gain'
 * '<S800>' : 'controller/控制模式/惯性四元数控制/ctrlZ/Ideal P Gain'
 * '<S801>' : 'controller/控制模式/惯性四元数控制/ctrlZ/Ideal P Gain Fdbk'
 * '<S802>' : 'controller/控制模式/惯性四元数控制/ctrlZ/Integrator'
 * '<S803>' : 'controller/控制模式/惯性四元数控制/ctrlZ/Integrator ICs'
 * '<S804>' : 'controller/控制模式/惯性四元数控制/ctrlZ/N Copy'
 * '<S805>' : 'controller/控制模式/惯性四元数控制/ctrlZ/N Gain'
 * '<S806>' : 'controller/控制模式/惯性四元数控制/ctrlZ/P Copy'
 * '<S807>' : 'controller/控制模式/惯性四元数控制/ctrlZ/Parallel P Gain'
 * '<S808>' : 'controller/控制模式/惯性四元数控制/ctrlZ/Reset Signal'
 * '<S809>' : 'controller/控制模式/惯性四元数控制/ctrlZ/Saturation'
 * '<S810>' : 'controller/控制模式/惯性四元数控制/ctrlZ/Saturation Fdbk'
 * '<S811>' : 'controller/控制模式/惯性四元数控制/ctrlZ/Sum'
 * '<S812>' : 'controller/控制模式/惯性四元数控制/ctrlZ/Sum Fdbk'
 * '<S813>' : 'controller/控制模式/惯性四元数控制/ctrlZ/Tracking Mode'
 * '<S814>' : 'controller/控制模式/惯性四元数控制/ctrlZ/Tracking Mode Sum'
 * '<S815>' : 'controller/控制模式/惯性四元数控制/ctrlZ/postSat Signal'
 * '<S816>' : 'controller/控制模式/惯性四元数控制/ctrlZ/preSat Signal'
 * '<S817>' : 'controller/控制模式/惯性四元数控制/ctrlZ/Anti-windup/Back Calculation'
 * '<S818>' : 'controller/控制模式/惯性四元数控制/ctrlZ/Anti-windup/Cont. Clamping Ideal'
 * '<S819>' : 'controller/控制模式/惯性四元数控制/ctrlZ/Anti-windup/Cont. Clamping Parallel'
 * '<S820>' : 'controller/控制模式/惯性四元数控制/ctrlZ/Anti-windup/Disabled'
 * '<S821>' : 'controller/控制模式/惯性四元数控制/ctrlZ/Anti-windup/Disc. Clamping Ideal'
 * '<S822>' : 'controller/控制模式/惯性四元数控制/ctrlZ/Anti-windup/Disc. Clamping Parallel'
 * '<S823>' : 'controller/控制模式/惯性四元数控制/ctrlZ/Anti-windup/Passthrough'
 * '<S824>' : 'controller/控制模式/惯性四元数控制/ctrlZ/D Gain/Disabled'
 * '<S825>' : 'controller/控制模式/惯性四元数控制/ctrlZ/D Gain/External Parameters'
 * '<S826>' : 'controller/控制模式/惯性四元数控制/ctrlZ/D Gain/Internal Parameters'
 * '<S827>' : 'controller/控制模式/惯性四元数控制/ctrlZ/Filter/Cont. Filter'
 * '<S828>' : 'controller/控制模式/惯性四元数控制/ctrlZ/Filter/Differentiator'
 * '<S829>' : 'controller/控制模式/惯性四元数控制/ctrlZ/Filter/Disabled'
 * '<S830>' : 'controller/控制模式/惯性四元数控制/ctrlZ/Filter/Disc. Backward Euler Filter'
 * '<S831>' : 'controller/控制模式/惯性四元数控制/ctrlZ/Filter/Disc. Forward Euler Filter'
 * '<S832>' : 'controller/控制模式/惯性四元数控制/ctrlZ/Filter/Disc. Trapezoidal Filter'
 * '<S833>' : 'controller/控制模式/惯性四元数控制/ctrlZ/Filter ICs/Disabled'
 * '<S834>' : 'controller/控制模式/惯性四元数控制/ctrlZ/Filter ICs/External IC'
 * '<S835>' : 'controller/控制模式/惯性四元数控制/ctrlZ/Filter ICs/Internal IC - Differentiator'
 * '<S836>' : 'controller/控制模式/惯性四元数控制/ctrlZ/Filter ICs/Internal IC - Filter'
 * '<S837>' : 'controller/控制模式/惯性四元数控制/ctrlZ/I Gain/Disabled'
 * '<S838>' : 'controller/控制模式/惯性四元数控制/ctrlZ/I Gain/External Parameters'
 * '<S839>' : 'controller/控制模式/惯性四元数控制/ctrlZ/I Gain/Internal Parameters'
 * '<S840>' : 'controller/控制模式/惯性四元数控制/ctrlZ/Ideal P Gain/External Parameters'
 * '<S841>' : 'controller/控制模式/惯性四元数控制/ctrlZ/Ideal P Gain/Internal Parameters'
 * '<S842>' : 'controller/控制模式/惯性四元数控制/ctrlZ/Ideal P Gain/Passthrough'
 * '<S843>' : 'controller/控制模式/惯性四元数控制/ctrlZ/Ideal P Gain Fdbk/Disabled'
 * '<S844>' : 'controller/控制模式/惯性四元数控制/ctrlZ/Ideal P Gain Fdbk/External Parameters'
 * '<S845>' : 'controller/控制模式/惯性四元数控制/ctrlZ/Ideal P Gain Fdbk/Internal Parameters'
 * '<S846>' : 'controller/控制模式/惯性四元数控制/ctrlZ/Ideal P Gain Fdbk/Passthrough'
 * '<S847>' : 'controller/控制模式/惯性四元数控制/ctrlZ/Integrator/Continuous'
 * '<S848>' : 'controller/控制模式/惯性四元数控制/ctrlZ/Integrator/Disabled'
 * '<S849>' : 'controller/控制模式/惯性四元数控制/ctrlZ/Integrator/Discrete'
 * '<S850>' : 'controller/控制模式/惯性四元数控制/ctrlZ/Integrator ICs/Disabled'
 * '<S851>' : 'controller/控制模式/惯性四元数控制/ctrlZ/Integrator ICs/External IC'
 * '<S852>' : 'controller/控制模式/惯性四元数控制/ctrlZ/Integrator ICs/Internal IC'
 * '<S853>' : 'controller/控制模式/惯性四元数控制/ctrlZ/N Copy/Disabled'
 * '<S854>' : 'controller/控制模式/惯性四元数控制/ctrlZ/N Copy/Disabled wSignal Specification'
 * '<S855>' : 'controller/控制模式/惯性四元数控制/ctrlZ/N Copy/External Parameters'
 * '<S856>' : 'controller/控制模式/惯性四元数控制/ctrlZ/N Copy/Internal Parameters'
 * '<S857>' : 'controller/控制模式/惯性四元数控制/ctrlZ/N Gain/Disabled'
 * '<S858>' : 'controller/控制模式/惯性四元数控制/ctrlZ/N Gain/External Parameters'
 * '<S859>' : 'controller/控制模式/惯性四元数控制/ctrlZ/N Gain/Internal Parameters'
 * '<S860>' : 'controller/控制模式/惯性四元数控制/ctrlZ/N Gain/Passthrough'
 * '<S861>' : 'controller/控制模式/惯性四元数控制/ctrlZ/P Copy/Disabled'
 * '<S862>' : 'controller/控制模式/惯性四元数控制/ctrlZ/P Copy/External Parameters Ideal'
 * '<S863>' : 'controller/控制模式/惯性四元数控制/ctrlZ/P Copy/Internal Parameters Ideal'
 * '<S864>' : 'controller/控制模式/惯性四元数控制/ctrlZ/Parallel P Gain/Disabled'
 * '<S865>' : 'controller/控制模式/惯性四元数控制/ctrlZ/Parallel P Gain/External Parameters'
 * '<S866>' : 'controller/控制模式/惯性四元数控制/ctrlZ/Parallel P Gain/Internal Parameters'
 * '<S867>' : 'controller/控制模式/惯性四元数控制/ctrlZ/Parallel P Gain/Passthrough'
 * '<S868>' : 'controller/控制模式/惯性四元数控制/ctrlZ/Reset Signal/Disabled'
 * '<S869>' : 'controller/控制模式/惯性四元数控制/ctrlZ/Reset Signal/External Reset'
 * '<S870>' : 'controller/控制模式/惯性四元数控制/ctrlZ/Saturation/Enabled'
 * '<S871>' : 'controller/控制模式/惯性四元数控制/ctrlZ/Saturation/Passthrough'
 * '<S872>' : 'controller/控制模式/惯性四元数控制/ctrlZ/Saturation Fdbk/Disabled'
 * '<S873>' : 'controller/控制模式/惯性四元数控制/ctrlZ/Saturation Fdbk/Enabled'
 * '<S874>' : 'controller/控制模式/惯性四元数控制/ctrlZ/Saturation Fdbk/Passthrough'
 * '<S875>' : 'controller/控制模式/惯性四元数控制/ctrlZ/Sum/Passthrough_I'
 * '<S876>' : 'controller/控制模式/惯性四元数控制/ctrlZ/Sum/Passthrough_P'
 * '<S877>' : 'controller/控制模式/惯性四元数控制/ctrlZ/Sum/Sum_PD'
 * '<S878>' : 'controller/控制模式/惯性四元数控制/ctrlZ/Sum/Sum_PI'
 * '<S879>' : 'controller/控制模式/惯性四元数控制/ctrlZ/Sum/Sum_PID'
 * '<S880>' : 'controller/控制模式/惯性四元数控制/ctrlZ/Sum Fdbk/Disabled'
 * '<S881>' : 'controller/控制模式/惯性四元数控制/ctrlZ/Sum Fdbk/Enabled'
 * '<S882>' : 'controller/控制模式/惯性四元数控制/ctrlZ/Sum Fdbk/Passthrough'
 * '<S883>' : 'controller/控制模式/惯性四元数控制/ctrlZ/Tracking Mode/Disabled'
 * '<S884>' : 'controller/控制模式/惯性四元数控制/ctrlZ/Tracking Mode/Enabled'
 * '<S885>' : 'controller/控制模式/惯性四元数控制/ctrlZ/Tracking Mode Sum/Passthrough'
 * '<S886>' : 'controller/控制模式/惯性四元数控制/ctrlZ/Tracking Mode Sum/Tracking Mode'
 * '<S887>' : 'controller/控制模式/惯性四元数控制/ctrlZ/postSat Signal/Feedback_Path'
 * '<S888>' : 'controller/控制模式/惯性四元数控制/ctrlZ/postSat Signal/Forward_Path'
 * '<S889>' : 'controller/控制模式/惯性四元数控制/ctrlZ/preSat Signal/Feedback_Path'
 * '<S890>' : 'controller/控制模式/惯性四元数控制/ctrlZ/preSat Signal/Forward_Path'
 * '<S891>' : 'controller/轨道计算/轨道外推'
 * '<S892>' : 'controller/轨道计算/轨道外推/位置速度转换为根数'
 * '<S893>' : 'controller/轨道计算/轨道外推/惯性系轨道系转换阵'
 * '<S894>' : 'controller/轨道计算/轨道外推/轨道动力学（仅地球引力）'
 * '<S895>' : 'controller/陀螺数据处理/GyroChkValid'
 * '<S896>' : 'controller/陀螺数据处理/GyroComptueDelta'
 * '<S897>' : 'controller/陀螺数据处理/角速度最值'
 */
#endif                                 /* RTW_HEADER_controller_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
