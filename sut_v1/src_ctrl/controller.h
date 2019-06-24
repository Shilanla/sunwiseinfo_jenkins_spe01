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

/* Block states (default storage) for system '<S891>/�������ѧ��������������' */
typedef struct {
  real_T _DSTATE[3];                   /* '<S894>/λ�û���' */
  real_T _DSTATE_c[3];                 /* '<S894>/�ٶȻ���' */
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
  real_T y;                            /* '<S4>/���ٶ���ֵ' */
  real_T u[3];                         /* '<S3>/��ʼλ�ã��ף�' */
  real_T u_m[3];                       /* '<S3>/��ʼ�ٶȣ���//�룩1' */
  real_T COI[9];                       /* '<S891>/����ϵ���ϵת����' */
  real_T q[4];                         /* '<Root>/����ģʽѡ��' */
  real_T u_h[4];                       /* '<S6>/����������' */
  real_T qbi[4];                       /* '<S12>/ComputeQbi' */
  real_T expected[4];                  /* '<S6>/����Ŀ��滮' */
  uint32_T idUsed[5];                  /* '<S4>/GyroChkValid' */
  controller_Chart_4_ModeType ChartMode;/* '<Root>/����ģʽѡ��' */
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
  real_T qSaved[4];                    /* '<Root>/����ģʽѡ��' */
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
  real_T sT[4];                        /* '<S6>/����Ŀ��滮' */
  real_T waitTime;                     /* '<S6>/����Ŀ��滮' */
  uint32_T cnt1;                       /* '<Root>/����ģʽѡ��' */
  uint32_T cnt2;                       /* '<Root>/����ģʽѡ��' */
  uint32_T cnt3;                       /* '<Root>/����ģʽѡ��' */
  uint32_T cnt4;                       /* '<Root>/����ģʽѡ��' */
  uint32_T cntFixed;                   /* '<Root>/����ģʽѡ��' */
  uint32_T _PREV_T;                    /* '<S1>/������Ԫ������' */
  uint32_T _PREV_T_p;                  /* '<S1>/��̬�ǿ���' */
  uint32_T _PREV_T_o;                  /* '<S1>/��ȫ���ٶȿ���' */
  uint32_T temporalCounter_i1;         /* '<S6>/����Ŀ��滮' */
  uint8_T is_active_c4_controller;     /* '<Root>/����ģʽѡ��' */
  uint8_T is_c4_controller;            /* '<Root>/����ģʽѡ��' */
  uint8_T is_work;                     /* '<Root>/����ģʽѡ��' */
  uint8_T is_ill;                      /* '<Root>/����ģʽѡ��' */
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
  uint8_T is_active_c2_controller;     /* '<S6>/����Ŀ��滮' */
  uint8_T is_c2_controller;            /* '<S6>/����Ŀ��滮' */
  boolean_T _RESET_ELAPS_T;            /* '<S1>/������Ԫ������' */
  boolean_T _RESET_ELAPS_T_j;          /* '<S1>/��̬�ǿ���' */
  boolean_T _RESET_ELAPS_T_l;          /* '<S1>/��ȫ���ٶȿ���' */
  DW_GyroComptueDelta_controlle_T sf_GyroComptueDelta;/* '<S4>/GyroComptueDelta' */
  DW_GyroChkValid_controller_T sf_GyroChkValid;/* '<S4>/GyroChkValid' */
  DW_OrbitDynamic_T u_j;               /* '<S891>/�������ѧ��������������' */
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
extern real_T ctrlInCmdOmg[3];         /* '<Root>/Ԥ�ڹ��ϵ��̬��' */
extern real_T ctrlInSensorGyro[6];     /* '<Root>/���ݲ���ֵ' */
extern real_T ctrlInSensorQ[4];        /* '<Root>/������Ԫ��' */
extern uint32_T flgCtrl;               /* '<Root>/����' */
extern real_T ctrlOutM[3];             /* '<S1>/���������ѡ��' */
extern real_T ctrlOmg[3];              /* '<S4>/GyroComptueDelta' */
extern real_T ctrlAngle[3];            /* '<S6>/ת��Ϊ���ϵ��̬��' */
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
                                        * Referenced by: '<Root>/���ݰ�װ����'
                                        */
extern real_T gParaInitPos[3];         /* Variable: gParaInitPos
                                        * Referenced by: '<S3>/��ʼλ�ã��ף�'
                                        */
extern real_T gParaInitVel[3];         /* Variable: gParaInitVel
                                        * Referenced by: '<S3>/��ʼ�ٶȣ���//�룩1'
                                        */
extern boolean_T gParaGyroUsed[6];     /* Variable: gParaGyroUsed
                                        * Referenced by: '<Root>/����ʹ�ñ�־'
                                        */
extern boolean_T gParaPauseEnable;     /* Variable: gParaPauseEnable
                                        * Referenced by: '<Root>/���������ͣģʽ'
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
 * '<S1>'   : 'controller/����ģʽ'
 * '<S2>'   : 'controller/����ģʽѡ��'
 * '<S3>'   : 'controller/�������'
 * '<S4>'   : 'controller/�������ݴ���'
 * '<S5>'   : 'controller/����ģʽ/ͣ��ģʽ'
 * '<S6>'   : 'controller/����ģʽ/��Ԫ��������'
 * '<S7>'   : 'controller/����ģʽ/��̬�ǿ���'
 * '<S8>'   : 'controller/����ģʽ/��ȫ���ٶȿ���'
 * '<S9>'   : 'controller/����ģʽ/������Ԫ������'
 * '<S10>'  : 'controller/����ģʽ/���������ֵ'
 * '<S11>'  : 'controller/����ģʽ/��Ԫ��������/����Ŀ��滮'
 * '<S12>'  : 'controller/����ģʽ/��Ԫ��������/����Ԥ�ڵĹ���ϵ��Ԫ��'
 * '<S13>'  : 'controller/����ģʽ/��Ԫ��������/ת��Ϊ���ϵ��̬��'
 * '<S14>'  : 'controller/����ģʽ/��Ԫ��������/����Ԥ�ڵĹ���ϵ��Ԫ��/Angle2Cbo'
 * '<S15>'  : 'controller/����ģʽ/��Ԫ��������/����Ԥ�ڵĹ���ϵ��Ԫ��/ComputeCbi'
 * '<S16>'  : 'controller/����ģʽ/��Ԫ��������/����Ԥ�ڵĹ���ϵ��Ԫ��/ComputeQbi'
 * '<S17>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX'
 * '<S18>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlY'
 * '<S19>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlZ'
 * '<S20>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/Anti-windup'
 * '<S21>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/D Gain'
 * '<S22>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/Filter'
 * '<S23>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/Filter ICs'
 * '<S24>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/I Gain'
 * '<S25>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/Ideal P Gain'
 * '<S26>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/Ideal P Gain Fdbk'
 * '<S27>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/Integrator'
 * '<S28>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/Integrator ICs'
 * '<S29>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/N Copy'
 * '<S30>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/N Gain'
 * '<S31>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/P Copy'
 * '<S32>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/Parallel P Gain'
 * '<S33>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/Reset Signal'
 * '<S34>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/Saturation'
 * '<S35>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/Saturation Fdbk'
 * '<S36>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/Sum'
 * '<S37>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/Sum Fdbk'
 * '<S38>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/Tracking Mode'
 * '<S39>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/Tracking Mode Sum'
 * '<S40>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/postSat Signal'
 * '<S41>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/preSat Signal'
 * '<S42>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/Anti-windup/Back Calculation'
 * '<S43>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/Anti-windup/Cont. Clamping Ideal'
 * '<S44>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/Anti-windup/Cont. Clamping Parallel'
 * '<S45>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/Anti-windup/Disabled'
 * '<S46>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/Anti-windup/Disc. Clamping Ideal'
 * '<S47>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/Anti-windup/Disc. Clamping Parallel'
 * '<S48>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/Anti-windup/Passthrough'
 * '<S49>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/D Gain/Disabled'
 * '<S50>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/D Gain/External Parameters'
 * '<S51>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/D Gain/Internal Parameters'
 * '<S52>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/Filter/Cont. Filter'
 * '<S53>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/Filter/Differentiator'
 * '<S54>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/Filter/Disabled'
 * '<S55>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/Filter/Disc. Backward Euler Filter'
 * '<S56>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/Filter/Disc. Forward Euler Filter'
 * '<S57>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/Filter/Disc. Trapezoidal Filter'
 * '<S58>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/Filter ICs/Disabled'
 * '<S59>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/Filter ICs/External IC'
 * '<S60>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/Filter ICs/Internal IC - Differentiator'
 * '<S61>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/Filter ICs/Internal IC - Filter'
 * '<S62>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/I Gain/Disabled'
 * '<S63>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/I Gain/External Parameters'
 * '<S64>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/I Gain/Internal Parameters'
 * '<S65>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/Ideal P Gain/External Parameters'
 * '<S66>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/Ideal P Gain/Internal Parameters'
 * '<S67>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/Ideal P Gain/Passthrough'
 * '<S68>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/Ideal P Gain Fdbk/Disabled'
 * '<S69>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/Ideal P Gain Fdbk/External Parameters'
 * '<S70>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/Ideal P Gain Fdbk/Internal Parameters'
 * '<S71>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/Ideal P Gain Fdbk/Passthrough'
 * '<S72>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/Integrator/Continuous'
 * '<S73>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/Integrator/Disabled'
 * '<S74>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/Integrator/Discrete'
 * '<S75>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/Integrator ICs/Disabled'
 * '<S76>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/Integrator ICs/External IC'
 * '<S77>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/Integrator ICs/Internal IC'
 * '<S78>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/N Copy/Disabled'
 * '<S79>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/N Copy/Disabled wSignal Specification'
 * '<S80>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/N Copy/External Parameters'
 * '<S81>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/N Copy/Internal Parameters'
 * '<S82>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/N Gain/Disabled'
 * '<S83>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/N Gain/External Parameters'
 * '<S84>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/N Gain/Internal Parameters'
 * '<S85>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/N Gain/Passthrough'
 * '<S86>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/P Copy/Disabled'
 * '<S87>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/P Copy/External Parameters Ideal'
 * '<S88>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/P Copy/Internal Parameters Ideal'
 * '<S89>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/Parallel P Gain/Disabled'
 * '<S90>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/Parallel P Gain/External Parameters'
 * '<S91>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/Parallel P Gain/Internal Parameters'
 * '<S92>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/Parallel P Gain/Passthrough'
 * '<S93>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/Reset Signal/Disabled'
 * '<S94>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/Reset Signal/External Reset'
 * '<S95>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/Saturation/Enabled'
 * '<S96>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/Saturation/Passthrough'
 * '<S97>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/Saturation Fdbk/Disabled'
 * '<S98>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/Saturation Fdbk/Enabled'
 * '<S99>'  : 'controller/����ģʽ/��̬�ǿ���/ctrlX/Saturation Fdbk/Passthrough'
 * '<S100>' : 'controller/����ģʽ/��̬�ǿ���/ctrlX/Sum/Passthrough_I'
 * '<S101>' : 'controller/����ģʽ/��̬�ǿ���/ctrlX/Sum/Passthrough_P'
 * '<S102>' : 'controller/����ģʽ/��̬�ǿ���/ctrlX/Sum/Sum_PD'
 * '<S103>' : 'controller/����ģʽ/��̬�ǿ���/ctrlX/Sum/Sum_PI'
 * '<S104>' : 'controller/����ģʽ/��̬�ǿ���/ctrlX/Sum/Sum_PID'
 * '<S105>' : 'controller/����ģʽ/��̬�ǿ���/ctrlX/Sum Fdbk/Disabled'
 * '<S106>' : 'controller/����ģʽ/��̬�ǿ���/ctrlX/Sum Fdbk/Enabled'
 * '<S107>' : 'controller/����ģʽ/��̬�ǿ���/ctrlX/Sum Fdbk/Passthrough'
 * '<S108>' : 'controller/����ģʽ/��̬�ǿ���/ctrlX/Tracking Mode/Disabled'
 * '<S109>' : 'controller/����ģʽ/��̬�ǿ���/ctrlX/Tracking Mode/Enabled'
 * '<S110>' : 'controller/����ģʽ/��̬�ǿ���/ctrlX/Tracking Mode Sum/Passthrough'
 * '<S111>' : 'controller/����ģʽ/��̬�ǿ���/ctrlX/Tracking Mode Sum/Tracking Mode'
 * '<S112>' : 'controller/����ģʽ/��̬�ǿ���/ctrlX/postSat Signal/Feedback_Path'
 * '<S113>' : 'controller/����ģʽ/��̬�ǿ���/ctrlX/postSat Signal/Forward_Path'
 * '<S114>' : 'controller/����ģʽ/��̬�ǿ���/ctrlX/preSat Signal/Feedback_Path'
 * '<S115>' : 'controller/����ģʽ/��̬�ǿ���/ctrlX/preSat Signal/Forward_Path'
 * '<S116>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/Anti-windup'
 * '<S117>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/D Gain'
 * '<S118>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/Filter'
 * '<S119>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/Filter ICs'
 * '<S120>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/I Gain'
 * '<S121>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/Ideal P Gain'
 * '<S122>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/Ideal P Gain Fdbk'
 * '<S123>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/Integrator'
 * '<S124>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/Integrator ICs'
 * '<S125>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/N Copy'
 * '<S126>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/N Gain'
 * '<S127>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/P Copy'
 * '<S128>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/Parallel P Gain'
 * '<S129>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/Reset Signal'
 * '<S130>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/Saturation'
 * '<S131>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/Saturation Fdbk'
 * '<S132>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/Sum'
 * '<S133>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/Sum Fdbk'
 * '<S134>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/Tracking Mode'
 * '<S135>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/Tracking Mode Sum'
 * '<S136>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/postSat Signal'
 * '<S137>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/preSat Signal'
 * '<S138>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/Anti-windup/Back Calculation'
 * '<S139>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/Anti-windup/Cont. Clamping Ideal'
 * '<S140>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/Anti-windup/Cont. Clamping Parallel'
 * '<S141>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/Anti-windup/Disabled'
 * '<S142>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/Anti-windup/Disc. Clamping Ideal'
 * '<S143>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/Anti-windup/Disc. Clamping Parallel'
 * '<S144>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/Anti-windup/Passthrough'
 * '<S145>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/D Gain/Disabled'
 * '<S146>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/D Gain/External Parameters'
 * '<S147>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/D Gain/Internal Parameters'
 * '<S148>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/Filter/Cont. Filter'
 * '<S149>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/Filter/Differentiator'
 * '<S150>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/Filter/Disabled'
 * '<S151>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/Filter/Disc. Backward Euler Filter'
 * '<S152>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/Filter/Disc. Forward Euler Filter'
 * '<S153>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/Filter/Disc. Trapezoidal Filter'
 * '<S154>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/Filter ICs/Disabled'
 * '<S155>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/Filter ICs/External IC'
 * '<S156>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/Filter ICs/Internal IC - Differentiator'
 * '<S157>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/Filter ICs/Internal IC - Filter'
 * '<S158>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/I Gain/Disabled'
 * '<S159>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/I Gain/External Parameters'
 * '<S160>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/I Gain/Internal Parameters'
 * '<S161>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/Ideal P Gain/External Parameters'
 * '<S162>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/Ideal P Gain/Internal Parameters'
 * '<S163>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/Ideal P Gain/Passthrough'
 * '<S164>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/Ideal P Gain Fdbk/Disabled'
 * '<S165>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/Ideal P Gain Fdbk/External Parameters'
 * '<S166>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/Ideal P Gain Fdbk/Internal Parameters'
 * '<S167>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/Ideal P Gain Fdbk/Passthrough'
 * '<S168>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/Integrator/Continuous'
 * '<S169>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/Integrator/Disabled'
 * '<S170>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/Integrator/Discrete'
 * '<S171>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/Integrator ICs/Disabled'
 * '<S172>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/Integrator ICs/External IC'
 * '<S173>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/Integrator ICs/Internal IC'
 * '<S174>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/N Copy/Disabled'
 * '<S175>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/N Copy/Disabled wSignal Specification'
 * '<S176>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/N Copy/External Parameters'
 * '<S177>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/N Copy/Internal Parameters'
 * '<S178>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/N Gain/Disabled'
 * '<S179>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/N Gain/External Parameters'
 * '<S180>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/N Gain/Internal Parameters'
 * '<S181>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/N Gain/Passthrough'
 * '<S182>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/P Copy/Disabled'
 * '<S183>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/P Copy/External Parameters Ideal'
 * '<S184>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/P Copy/Internal Parameters Ideal'
 * '<S185>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/Parallel P Gain/Disabled'
 * '<S186>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/Parallel P Gain/External Parameters'
 * '<S187>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/Parallel P Gain/Internal Parameters'
 * '<S188>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/Parallel P Gain/Passthrough'
 * '<S189>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/Reset Signal/Disabled'
 * '<S190>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/Reset Signal/External Reset'
 * '<S191>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/Saturation/Enabled'
 * '<S192>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/Saturation/Passthrough'
 * '<S193>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/Saturation Fdbk/Disabled'
 * '<S194>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/Saturation Fdbk/Enabled'
 * '<S195>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/Saturation Fdbk/Passthrough'
 * '<S196>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/Sum/Passthrough_I'
 * '<S197>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/Sum/Passthrough_P'
 * '<S198>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/Sum/Sum_PD'
 * '<S199>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/Sum/Sum_PI'
 * '<S200>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/Sum/Sum_PID'
 * '<S201>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/Sum Fdbk/Disabled'
 * '<S202>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/Sum Fdbk/Enabled'
 * '<S203>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/Sum Fdbk/Passthrough'
 * '<S204>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/Tracking Mode/Disabled'
 * '<S205>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/Tracking Mode/Enabled'
 * '<S206>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/Tracking Mode Sum/Passthrough'
 * '<S207>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/Tracking Mode Sum/Tracking Mode'
 * '<S208>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/postSat Signal/Feedback_Path'
 * '<S209>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/postSat Signal/Forward_Path'
 * '<S210>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/preSat Signal/Feedback_Path'
 * '<S211>' : 'controller/����ģʽ/��̬�ǿ���/ctrlY/preSat Signal/Forward_Path'
 * '<S212>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/Anti-windup'
 * '<S213>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/D Gain'
 * '<S214>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/Filter'
 * '<S215>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/Filter ICs'
 * '<S216>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/I Gain'
 * '<S217>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/Ideal P Gain'
 * '<S218>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/Ideal P Gain Fdbk'
 * '<S219>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/Integrator'
 * '<S220>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/Integrator ICs'
 * '<S221>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/N Copy'
 * '<S222>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/N Gain'
 * '<S223>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/P Copy'
 * '<S224>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/Parallel P Gain'
 * '<S225>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/Reset Signal'
 * '<S226>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/Saturation'
 * '<S227>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/Saturation Fdbk'
 * '<S228>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/Sum'
 * '<S229>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/Sum Fdbk'
 * '<S230>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/Tracking Mode'
 * '<S231>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/Tracking Mode Sum'
 * '<S232>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/postSat Signal'
 * '<S233>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/preSat Signal'
 * '<S234>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/Anti-windup/Back Calculation'
 * '<S235>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/Anti-windup/Cont. Clamping Ideal'
 * '<S236>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/Anti-windup/Cont. Clamping Parallel'
 * '<S237>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/Anti-windup/Disabled'
 * '<S238>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/Anti-windup/Disc. Clamping Ideal'
 * '<S239>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/Anti-windup/Disc. Clamping Parallel'
 * '<S240>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/Anti-windup/Passthrough'
 * '<S241>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/D Gain/Disabled'
 * '<S242>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/D Gain/External Parameters'
 * '<S243>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/D Gain/Internal Parameters'
 * '<S244>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/Filter/Cont. Filter'
 * '<S245>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/Filter/Differentiator'
 * '<S246>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/Filter/Disabled'
 * '<S247>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/Filter/Disc. Backward Euler Filter'
 * '<S248>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/Filter/Disc. Forward Euler Filter'
 * '<S249>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/Filter/Disc. Trapezoidal Filter'
 * '<S250>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/Filter ICs/Disabled'
 * '<S251>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/Filter ICs/External IC'
 * '<S252>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/Filter ICs/Internal IC - Differentiator'
 * '<S253>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/Filter ICs/Internal IC - Filter'
 * '<S254>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/I Gain/Disabled'
 * '<S255>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/I Gain/External Parameters'
 * '<S256>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/I Gain/Internal Parameters'
 * '<S257>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/Ideal P Gain/External Parameters'
 * '<S258>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/Ideal P Gain/Internal Parameters'
 * '<S259>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/Ideal P Gain/Passthrough'
 * '<S260>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/Ideal P Gain Fdbk/Disabled'
 * '<S261>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/Ideal P Gain Fdbk/External Parameters'
 * '<S262>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/Ideal P Gain Fdbk/Internal Parameters'
 * '<S263>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/Ideal P Gain Fdbk/Passthrough'
 * '<S264>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/Integrator/Continuous'
 * '<S265>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/Integrator/Disabled'
 * '<S266>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/Integrator/Discrete'
 * '<S267>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/Integrator ICs/Disabled'
 * '<S268>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/Integrator ICs/External IC'
 * '<S269>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/Integrator ICs/Internal IC'
 * '<S270>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/N Copy/Disabled'
 * '<S271>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/N Copy/Disabled wSignal Specification'
 * '<S272>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/N Copy/External Parameters'
 * '<S273>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/N Copy/Internal Parameters'
 * '<S274>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/N Gain/Disabled'
 * '<S275>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/N Gain/External Parameters'
 * '<S276>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/N Gain/Internal Parameters'
 * '<S277>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/N Gain/Passthrough'
 * '<S278>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/P Copy/Disabled'
 * '<S279>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/P Copy/External Parameters Ideal'
 * '<S280>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/P Copy/Internal Parameters Ideal'
 * '<S281>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/Parallel P Gain/Disabled'
 * '<S282>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/Parallel P Gain/External Parameters'
 * '<S283>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/Parallel P Gain/Internal Parameters'
 * '<S284>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/Parallel P Gain/Passthrough'
 * '<S285>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/Reset Signal/Disabled'
 * '<S286>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/Reset Signal/External Reset'
 * '<S287>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/Saturation/Enabled'
 * '<S288>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/Saturation/Passthrough'
 * '<S289>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/Saturation Fdbk/Disabled'
 * '<S290>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/Saturation Fdbk/Enabled'
 * '<S291>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/Saturation Fdbk/Passthrough'
 * '<S292>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/Sum/Passthrough_I'
 * '<S293>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/Sum/Passthrough_P'
 * '<S294>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/Sum/Sum_PD'
 * '<S295>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/Sum/Sum_PI'
 * '<S296>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/Sum/Sum_PID'
 * '<S297>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/Sum Fdbk/Disabled'
 * '<S298>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/Sum Fdbk/Enabled'
 * '<S299>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/Sum Fdbk/Passthrough'
 * '<S300>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/Tracking Mode/Disabled'
 * '<S301>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/Tracking Mode/Enabled'
 * '<S302>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/Tracking Mode Sum/Passthrough'
 * '<S303>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/Tracking Mode Sum/Tracking Mode'
 * '<S304>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/postSat Signal/Feedback_Path'
 * '<S305>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/postSat Signal/Forward_Path'
 * '<S306>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/preSat Signal/Feedback_Path'
 * '<S307>' : 'controller/����ģʽ/��̬�ǿ���/ctrlZ/preSat Signal/Forward_Path'
 * '<S308>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX'
 * '<S309>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY'
 * '<S310>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ'
 * '<S311>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/Anti-windup'
 * '<S312>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/D Gain'
 * '<S313>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/Filter'
 * '<S314>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/Filter ICs'
 * '<S315>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/I Gain'
 * '<S316>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/Ideal P Gain'
 * '<S317>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/Ideal P Gain Fdbk'
 * '<S318>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/Integrator'
 * '<S319>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/Integrator ICs'
 * '<S320>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/N Copy'
 * '<S321>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/N Gain'
 * '<S322>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/P Copy'
 * '<S323>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/Parallel P Gain'
 * '<S324>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/Reset Signal'
 * '<S325>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/Saturation'
 * '<S326>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/Saturation Fdbk'
 * '<S327>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/Sum'
 * '<S328>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/Sum Fdbk'
 * '<S329>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/Tracking Mode'
 * '<S330>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/Tracking Mode Sum'
 * '<S331>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/postSat Signal'
 * '<S332>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/preSat Signal'
 * '<S333>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/Anti-windup/Back Calculation'
 * '<S334>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/Anti-windup/Cont. Clamping Ideal'
 * '<S335>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/Anti-windup/Cont. Clamping Parallel'
 * '<S336>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/Anti-windup/Disabled'
 * '<S337>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/Anti-windup/Disc. Clamping Ideal'
 * '<S338>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/Anti-windup/Disc. Clamping Parallel'
 * '<S339>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/Anti-windup/Passthrough'
 * '<S340>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/D Gain/Disabled'
 * '<S341>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/D Gain/External Parameters'
 * '<S342>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/D Gain/Internal Parameters'
 * '<S343>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/Filter/Cont. Filter'
 * '<S344>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/Filter/Differentiator'
 * '<S345>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/Filter/Disabled'
 * '<S346>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/Filter/Disc. Backward Euler Filter'
 * '<S347>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/Filter/Disc. Forward Euler Filter'
 * '<S348>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/Filter/Disc. Trapezoidal Filter'
 * '<S349>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/Filter ICs/Disabled'
 * '<S350>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/Filter ICs/External IC'
 * '<S351>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/Filter ICs/Internal IC - Differentiator'
 * '<S352>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/Filter ICs/Internal IC - Filter'
 * '<S353>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/I Gain/Disabled'
 * '<S354>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/I Gain/External Parameters'
 * '<S355>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/I Gain/Internal Parameters'
 * '<S356>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/Ideal P Gain/External Parameters'
 * '<S357>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/Ideal P Gain/Internal Parameters'
 * '<S358>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/Ideal P Gain/Passthrough'
 * '<S359>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/Ideal P Gain Fdbk/Disabled'
 * '<S360>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/Ideal P Gain Fdbk/External Parameters'
 * '<S361>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/Ideal P Gain Fdbk/Internal Parameters'
 * '<S362>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/Ideal P Gain Fdbk/Passthrough'
 * '<S363>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/Integrator/Continuous'
 * '<S364>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/Integrator/Disabled'
 * '<S365>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/Integrator/Discrete'
 * '<S366>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/Integrator ICs/Disabled'
 * '<S367>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/Integrator ICs/External IC'
 * '<S368>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/Integrator ICs/Internal IC'
 * '<S369>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/N Copy/Disabled'
 * '<S370>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/N Copy/Disabled wSignal Specification'
 * '<S371>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/N Copy/External Parameters'
 * '<S372>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/N Copy/Internal Parameters'
 * '<S373>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/N Gain/Disabled'
 * '<S374>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/N Gain/External Parameters'
 * '<S375>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/N Gain/Internal Parameters'
 * '<S376>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/N Gain/Passthrough'
 * '<S377>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/P Copy/Disabled'
 * '<S378>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/P Copy/External Parameters Ideal'
 * '<S379>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/P Copy/Internal Parameters Ideal'
 * '<S380>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/Parallel P Gain/Disabled'
 * '<S381>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/Parallel P Gain/External Parameters'
 * '<S382>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/Parallel P Gain/Internal Parameters'
 * '<S383>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/Parallel P Gain/Passthrough'
 * '<S384>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/Reset Signal/Disabled'
 * '<S385>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/Reset Signal/External Reset'
 * '<S386>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/Saturation/Enabled'
 * '<S387>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/Saturation/Passthrough'
 * '<S388>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/Saturation Fdbk/Disabled'
 * '<S389>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/Saturation Fdbk/Enabled'
 * '<S390>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/Saturation Fdbk/Passthrough'
 * '<S391>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/Sum/Passthrough_I'
 * '<S392>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/Sum/Passthrough_P'
 * '<S393>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/Sum/Sum_PD'
 * '<S394>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/Sum/Sum_PI'
 * '<S395>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/Sum/Sum_PID'
 * '<S396>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/Sum Fdbk/Disabled'
 * '<S397>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/Sum Fdbk/Enabled'
 * '<S398>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/Sum Fdbk/Passthrough'
 * '<S399>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/Tracking Mode/Disabled'
 * '<S400>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/Tracking Mode/Enabled'
 * '<S401>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/Tracking Mode Sum/Passthrough'
 * '<S402>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/Tracking Mode Sum/Tracking Mode'
 * '<S403>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/postSat Signal/Feedback_Path'
 * '<S404>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/postSat Signal/Forward_Path'
 * '<S405>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/preSat Signal/Feedback_Path'
 * '<S406>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlX/preSat Signal/Forward_Path'
 * '<S407>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/Anti-windup'
 * '<S408>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/D Gain'
 * '<S409>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/Filter'
 * '<S410>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/Filter ICs'
 * '<S411>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/I Gain'
 * '<S412>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/Ideal P Gain'
 * '<S413>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/Ideal P Gain Fdbk'
 * '<S414>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/Integrator'
 * '<S415>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/Integrator ICs'
 * '<S416>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/N Copy'
 * '<S417>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/N Gain'
 * '<S418>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/P Copy'
 * '<S419>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/Parallel P Gain'
 * '<S420>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/Reset Signal'
 * '<S421>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/Saturation'
 * '<S422>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/Saturation Fdbk'
 * '<S423>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/Sum'
 * '<S424>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/Sum Fdbk'
 * '<S425>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/Tracking Mode'
 * '<S426>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/Tracking Mode Sum'
 * '<S427>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/postSat Signal'
 * '<S428>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/preSat Signal'
 * '<S429>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/Anti-windup/Back Calculation'
 * '<S430>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/Anti-windup/Cont. Clamping Ideal'
 * '<S431>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/Anti-windup/Cont. Clamping Parallel'
 * '<S432>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/Anti-windup/Disabled'
 * '<S433>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/Anti-windup/Disc. Clamping Ideal'
 * '<S434>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/Anti-windup/Disc. Clamping Parallel'
 * '<S435>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/Anti-windup/Passthrough'
 * '<S436>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/D Gain/Disabled'
 * '<S437>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/D Gain/External Parameters'
 * '<S438>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/D Gain/Internal Parameters'
 * '<S439>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/Filter/Cont. Filter'
 * '<S440>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/Filter/Differentiator'
 * '<S441>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/Filter/Disabled'
 * '<S442>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/Filter/Disc. Backward Euler Filter'
 * '<S443>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/Filter/Disc. Forward Euler Filter'
 * '<S444>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/Filter/Disc. Trapezoidal Filter'
 * '<S445>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/Filter ICs/Disabled'
 * '<S446>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/Filter ICs/External IC'
 * '<S447>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/Filter ICs/Internal IC - Differentiator'
 * '<S448>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/Filter ICs/Internal IC - Filter'
 * '<S449>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/I Gain/Disabled'
 * '<S450>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/I Gain/External Parameters'
 * '<S451>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/I Gain/Internal Parameters'
 * '<S452>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/Ideal P Gain/External Parameters'
 * '<S453>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/Ideal P Gain/Internal Parameters'
 * '<S454>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/Ideal P Gain/Passthrough'
 * '<S455>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/Ideal P Gain Fdbk/Disabled'
 * '<S456>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/Ideal P Gain Fdbk/External Parameters'
 * '<S457>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/Ideal P Gain Fdbk/Internal Parameters'
 * '<S458>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/Ideal P Gain Fdbk/Passthrough'
 * '<S459>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/Integrator/Continuous'
 * '<S460>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/Integrator/Disabled'
 * '<S461>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/Integrator/Discrete'
 * '<S462>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/Integrator ICs/Disabled'
 * '<S463>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/Integrator ICs/External IC'
 * '<S464>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/Integrator ICs/Internal IC'
 * '<S465>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/N Copy/Disabled'
 * '<S466>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/N Copy/Disabled wSignal Specification'
 * '<S467>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/N Copy/External Parameters'
 * '<S468>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/N Copy/Internal Parameters'
 * '<S469>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/N Gain/Disabled'
 * '<S470>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/N Gain/External Parameters'
 * '<S471>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/N Gain/Internal Parameters'
 * '<S472>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/N Gain/Passthrough'
 * '<S473>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/P Copy/Disabled'
 * '<S474>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/P Copy/External Parameters Ideal'
 * '<S475>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/P Copy/Internal Parameters Ideal'
 * '<S476>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/Parallel P Gain/Disabled'
 * '<S477>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/Parallel P Gain/External Parameters'
 * '<S478>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/Parallel P Gain/Internal Parameters'
 * '<S479>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/Parallel P Gain/Passthrough'
 * '<S480>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/Reset Signal/Disabled'
 * '<S481>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/Reset Signal/External Reset'
 * '<S482>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/Saturation/Enabled'
 * '<S483>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/Saturation/Passthrough'
 * '<S484>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/Saturation Fdbk/Disabled'
 * '<S485>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/Saturation Fdbk/Enabled'
 * '<S486>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/Saturation Fdbk/Passthrough'
 * '<S487>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/Sum/Passthrough_I'
 * '<S488>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/Sum/Passthrough_P'
 * '<S489>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/Sum/Sum_PD'
 * '<S490>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/Sum/Sum_PI'
 * '<S491>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/Sum/Sum_PID'
 * '<S492>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/Sum Fdbk/Disabled'
 * '<S493>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/Sum Fdbk/Enabled'
 * '<S494>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/Sum Fdbk/Passthrough'
 * '<S495>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/Tracking Mode/Disabled'
 * '<S496>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/Tracking Mode/Enabled'
 * '<S497>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/Tracking Mode Sum/Passthrough'
 * '<S498>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/Tracking Mode Sum/Tracking Mode'
 * '<S499>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/postSat Signal/Feedback_Path'
 * '<S500>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/postSat Signal/Forward_Path'
 * '<S501>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/preSat Signal/Feedback_Path'
 * '<S502>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlY/preSat Signal/Forward_Path'
 * '<S503>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/Anti-windup'
 * '<S504>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/D Gain'
 * '<S505>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/Filter'
 * '<S506>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/Filter ICs'
 * '<S507>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/I Gain'
 * '<S508>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/Ideal P Gain'
 * '<S509>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/Ideal P Gain Fdbk'
 * '<S510>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/Integrator'
 * '<S511>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/Integrator ICs'
 * '<S512>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/N Copy'
 * '<S513>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/N Gain'
 * '<S514>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/P Copy'
 * '<S515>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/Parallel P Gain'
 * '<S516>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/Reset Signal'
 * '<S517>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/Saturation'
 * '<S518>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/Saturation Fdbk'
 * '<S519>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/Sum'
 * '<S520>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/Sum Fdbk'
 * '<S521>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/Tracking Mode'
 * '<S522>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/Tracking Mode Sum'
 * '<S523>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/postSat Signal'
 * '<S524>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/preSat Signal'
 * '<S525>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/Anti-windup/Back Calculation'
 * '<S526>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/Anti-windup/Cont. Clamping Ideal'
 * '<S527>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/Anti-windup/Cont. Clamping Parallel'
 * '<S528>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/Anti-windup/Disabled'
 * '<S529>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/Anti-windup/Disc. Clamping Ideal'
 * '<S530>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/Anti-windup/Disc. Clamping Parallel'
 * '<S531>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/Anti-windup/Passthrough'
 * '<S532>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/D Gain/Disabled'
 * '<S533>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/D Gain/External Parameters'
 * '<S534>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/D Gain/Internal Parameters'
 * '<S535>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/Filter/Cont. Filter'
 * '<S536>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/Filter/Differentiator'
 * '<S537>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/Filter/Disabled'
 * '<S538>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/Filter/Disc. Backward Euler Filter'
 * '<S539>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/Filter/Disc. Forward Euler Filter'
 * '<S540>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/Filter/Disc. Trapezoidal Filter'
 * '<S541>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/Filter ICs/Disabled'
 * '<S542>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/Filter ICs/External IC'
 * '<S543>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/Filter ICs/Internal IC - Differentiator'
 * '<S544>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/Filter ICs/Internal IC - Filter'
 * '<S545>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/I Gain/Disabled'
 * '<S546>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/I Gain/External Parameters'
 * '<S547>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/I Gain/Internal Parameters'
 * '<S548>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/Ideal P Gain/External Parameters'
 * '<S549>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/Ideal P Gain/Internal Parameters'
 * '<S550>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/Ideal P Gain/Passthrough'
 * '<S551>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/Ideal P Gain Fdbk/Disabled'
 * '<S552>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/Ideal P Gain Fdbk/External Parameters'
 * '<S553>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/Ideal P Gain Fdbk/Internal Parameters'
 * '<S554>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/Ideal P Gain Fdbk/Passthrough'
 * '<S555>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/Integrator/Continuous'
 * '<S556>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/Integrator/Disabled'
 * '<S557>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/Integrator/Discrete'
 * '<S558>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/Integrator ICs/Disabled'
 * '<S559>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/Integrator ICs/External IC'
 * '<S560>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/Integrator ICs/Internal IC'
 * '<S561>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/N Copy/Disabled'
 * '<S562>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/N Copy/Disabled wSignal Specification'
 * '<S563>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/N Copy/External Parameters'
 * '<S564>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/N Copy/Internal Parameters'
 * '<S565>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/N Gain/Disabled'
 * '<S566>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/N Gain/External Parameters'
 * '<S567>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/N Gain/Internal Parameters'
 * '<S568>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/N Gain/Passthrough'
 * '<S569>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/P Copy/Disabled'
 * '<S570>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/P Copy/External Parameters Ideal'
 * '<S571>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/P Copy/Internal Parameters Ideal'
 * '<S572>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/Parallel P Gain/Disabled'
 * '<S573>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/Parallel P Gain/External Parameters'
 * '<S574>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/Parallel P Gain/Internal Parameters'
 * '<S575>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/Parallel P Gain/Passthrough'
 * '<S576>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/Reset Signal/Disabled'
 * '<S577>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/Reset Signal/External Reset'
 * '<S578>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/Saturation/Enabled'
 * '<S579>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/Saturation/Passthrough'
 * '<S580>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/Saturation Fdbk/Disabled'
 * '<S581>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/Saturation Fdbk/Enabled'
 * '<S582>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/Saturation Fdbk/Passthrough'
 * '<S583>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/Sum/Passthrough_I'
 * '<S584>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/Sum/Passthrough_P'
 * '<S585>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/Sum/Sum_PD'
 * '<S586>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/Sum/Sum_PI'
 * '<S587>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/Sum/Sum_PID'
 * '<S588>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/Sum Fdbk/Disabled'
 * '<S589>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/Sum Fdbk/Enabled'
 * '<S590>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/Sum Fdbk/Passthrough'
 * '<S591>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/Tracking Mode/Disabled'
 * '<S592>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/Tracking Mode/Enabled'
 * '<S593>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/Tracking Mode Sum/Passthrough'
 * '<S594>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/Tracking Mode Sum/Tracking Mode'
 * '<S595>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/postSat Signal/Feedback_Path'
 * '<S596>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/postSat Signal/Forward_Path'
 * '<S597>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/preSat Signal/Feedback_Path'
 * '<S598>' : 'controller/����ģʽ/��ȫ���ٶȿ���/ctrlZ/preSat Signal/Forward_Path'
 * '<S599>' : 'controller/����ģʽ/������Ԫ������/MATLAB Function'
 * '<S600>' : 'controller/����ģʽ/������Ԫ������/ctrlX'
 * '<S601>' : 'controller/����ģʽ/������Ԫ������/ctrlY'
 * '<S602>' : 'controller/����ģʽ/������Ԫ������/ctrlZ'
 * '<S603>' : 'controller/����ģʽ/������Ԫ������/ctrlX/Anti-windup'
 * '<S604>' : 'controller/����ģʽ/������Ԫ������/ctrlX/D Gain'
 * '<S605>' : 'controller/����ģʽ/������Ԫ������/ctrlX/Filter'
 * '<S606>' : 'controller/����ģʽ/������Ԫ������/ctrlX/Filter ICs'
 * '<S607>' : 'controller/����ģʽ/������Ԫ������/ctrlX/I Gain'
 * '<S608>' : 'controller/����ģʽ/������Ԫ������/ctrlX/Ideal P Gain'
 * '<S609>' : 'controller/����ģʽ/������Ԫ������/ctrlX/Ideal P Gain Fdbk'
 * '<S610>' : 'controller/����ģʽ/������Ԫ������/ctrlX/Integrator'
 * '<S611>' : 'controller/����ģʽ/������Ԫ������/ctrlX/Integrator ICs'
 * '<S612>' : 'controller/����ģʽ/������Ԫ������/ctrlX/N Copy'
 * '<S613>' : 'controller/����ģʽ/������Ԫ������/ctrlX/N Gain'
 * '<S614>' : 'controller/����ģʽ/������Ԫ������/ctrlX/P Copy'
 * '<S615>' : 'controller/����ģʽ/������Ԫ������/ctrlX/Parallel P Gain'
 * '<S616>' : 'controller/����ģʽ/������Ԫ������/ctrlX/Reset Signal'
 * '<S617>' : 'controller/����ģʽ/������Ԫ������/ctrlX/Saturation'
 * '<S618>' : 'controller/����ģʽ/������Ԫ������/ctrlX/Saturation Fdbk'
 * '<S619>' : 'controller/����ģʽ/������Ԫ������/ctrlX/Sum'
 * '<S620>' : 'controller/����ģʽ/������Ԫ������/ctrlX/Sum Fdbk'
 * '<S621>' : 'controller/����ģʽ/������Ԫ������/ctrlX/Tracking Mode'
 * '<S622>' : 'controller/����ģʽ/������Ԫ������/ctrlX/Tracking Mode Sum'
 * '<S623>' : 'controller/����ģʽ/������Ԫ������/ctrlX/postSat Signal'
 * '<S624>' : 'controller/����ģʽ/������Ԫ������/ctrlX/preSat Signal'
 * '<S625>' : 'controller/����ģʽ/������Ԫ������/ctrlX/Anti-windup/Back Calculation'
 * '<S626>' : 'controller/����ģʽ/������Ԫ������/ctrlX/Anti-windup/Cont. Clamping Ideal'
 * '<S627>' : 'controller/����ģʽ/������Ԫ������/ctrlX/Anti-windup/Cont. Clamping Parallel'
 * '<S628>' : 'controller/����ģʽ/������Ԫ������/ctrlX/Anti-windup/Disabled'
 * '<S629>' : 'controller/����ģʽ/������Ԫ������/ctrlX/Anti-windup/Disc. Clamping Ideal'
 * '<S630>' : 'controller/����ģʽ/������Ԫ������/ctrlX/Anti-windup/Disc. Clamping Parallel'
 * '<S631>' : 'controller/����ģʽ/������Ԫ������/ctrlX/Anti-windup/Passthrough'
 * '<S632>' : 'controller/����ģʽ/������Ԫ������/ctrlX/D Gain/Disabled'
 * '<S633>' : 'controller/����ģʽ/������Ԫ������/ctrlX/D Gain/External Parameters'
 * '<S634>' : 'controller/����ģʽ/������Ԫ������/ctrlX/D Gain/Internal Parameters'
 * '<S635>' : 'controller/����ģʽ/������Ԫ������/ctrlX/Filter/Cont. Filter'
 * '<S636>' : 'controller/����ģʽ/������Ԫ������/ctrlX/Filter/Differentiator'
 * '<S637>' : 'controller/����ģʽ/������Ԫ������/ctrlX/Filter/Disabled'
 * '<S638>' : 'controller/����ģʽ/������Ԫ������/ctrlX/Filter/Disc. Backward Euler Filter'
 * '<S639>' : 'controller/����ģʽ/������Ԫ������/ctrlX/Filter/Disc. Forward Euler Filter'
 * '<S640>' : 'controller/����ģʽ/������Ԫ������/ctrlX/Filter/Disc. Trapezoidal Filter'
 * '<S641>' : 'controller/����ģʽ/������Ԫ������/ctrlX/Filter ICs/Disabled'
 * '<S642>' : 'controller/����ģʽ/������Ԫ������/ctrlX/Filter ICs/External IC'
 * '<S643>' : 'controller/����ģʽ/������Ԫ������/ctrlX/Filter ICs/Internal IC - Differentiator'
 * '<S644>' : 'controller/����ģʽ/������Ԫ������/ctrlX/Filter ICs/Internal IC - Filter'
 * '<S645>' : 'controller/����ģʽ/������Ԫ������/ctrlX/I Gain/Disabled'
 * '<S646>' : 'controller/����ģʽ/������Ԫ������/ctrlX/I Gain/External Parameters'
 * '<S647>' : 'controller/����ģʽ/������Ԫ������/ctrlX/I Gain/Internal Parameters'
 * '<S648>' : 'controller/����ģʽ/������Ԫ������/ctrlX/Ideal P Gain/External Parameters'
 * '<S649>' : 'controller/����ģʽ/������Ԫ������/ctrlX/Ideal P Gain/Internal Parameters'
 * '<S650>' : 'controller/����ģʽ/������Ԫ������/ctrlX/Ideal P Gain/Passthrough'
 * '<S651>' : 'controller/����ģʽ/������Ԫ������/ctrlX/Ideal P Gain Fdbk/Disabled'
 * '<S652>' : 'controller/����ģʽ/������Ԫ������/ctrlX/Ideal P Gain Fdbk/External Parameters'
 * '<S653>' : 'controller/����ģʽ/������Ԫ������/ctrlX/Ideal P Gain Fdbk/Internal Parameters'
 * '<S654>' : 'controller/����ģʽ/������Ԫ������/ctrlX/Ideal P Gain Fdbk/Passthrough'
 * '<S655>' : 'controller/����ģʽ/������Ԫ������/ctrlX/Integrator/Continuous'
 * '<S656>' : 'controller/����ģʽ/������Ԫ������/ctrlX/Integrator/Disabled'
 * '<S657>' : 'controller/����ģʽ/������Ԫ������/ctrlX/Integrator/Discrete'
 * '<S658>' : 'controller/����ģʽ/������Ԫ������/ctrlX/Integrator ICs/Disabled'
 * '<S659>' : 'controller/����ģʽ/������Ԫ������/ctrlX/Integrator ICs/External IC'
 * '<S660>' : 'controller/����ģʽ/������Ԫ������/ctrlX/Integrator ICs/Internal IC'
 * '<S661>' : 'controller/����ģʽ/������Ԫ������/ctrlX/N Copy/Disabled'
 * '<S662>' : 'controller/����ģʽ/������Ԫ������/ctrlX/N Copy/Disabled wSignal Specification'
 * '<S663>' : 'controller/����ģʽ/������Ԫ������/ctrlX/N Copy/External Parameters'
 * '<S664>' : 'controller/����ģʽ/������Ԫ������/ctrlX/N Copy/Internal Parameters'
 * '<S665>' : 'controller/����ģʽ/������Ԫ������/ctrlX/N Gain/Disabled'
 * '<S666>' : 'controller/����ģʽ/������Ԫ������/ctrlX/N Gain/External Parameters'
 * '<S667>' : 'controller/����ģʽ/������Ԫ������/ctrlX/N Gain/Internal Parameters'
 * '<S668>' : 'controller/����ģʽ/������Ԫ������/ctrlX/N Gain/Passthrough'
 * '<S669>' : 'controller/����ģʽ/������Ԫ������/ctrlX/P Copy/Disabled'
 * '<S670>' : 'controller/����ģʽ/������Ԫ������/ctrlX/P Copy/External Parameters Ideal'
 * '<S671>' : 'controller/����ģʽ/������Ԫ������/ctrlX/P Copy/Internal Parameters Ideal'
 * '<S672>' : 'controller/����ģʽ/������Ԫ������/ctrlX/Parallel P Gain/Disabled'
 * '<S673>' : 'controller/����ģʽ/������Ԫ������/ctrlX/Parallel P Gain/External Parameters'
 * '<S674>' : 'controller/����ģʽ/������Ԫ������/ctrlX/Parallel P Gain/Internal Parameters'
 * '<S675>' : 'controller/����ģʽ/������Ԫ������/ctrlX/Parallel P Gain/Passthrough'
 * '<S676>' : 'controller/����ģʽ/������Ԫ������/ctrlX/Reset Signal/Disabled'
 * '<S677>' : 'controller/����ģʽ/������Ԫ������/ctrlX/Reset Signal/External Reset'
 * '<S678>' : 'controller/����ģʽ/������Ԫ������/ctrlX/Saturation/Enabled'
 * '<S679>' : 'controller/����ģʽ/������Ԫ������/ctrlX/Saturation/Passthrough'
 * '<S680>' : 'controller/����ģʽ/������Ԫ������/ctrlX/Saturation Fdbk/Disabled'
 * '<S681>' : 'controller/����ģʽ/������Ԫ������/ctrlX/Saturation Fdbk/Enabled'
 * '<S682>' : 'controller/����ģʽ/������Ԫ������/ctrlX/Saturation Fdbk/Passthrough'
 * '<S683>' : 'controller/����ģʽ/������Ԫ������/ctrlX/Sum/Passthrough_I'
 * '<S684>' : 'controller/����ģʽ/������Ԫ������/ctrlX/Sum/Passthrough_P'
 * '<S685>' : 'controller/����ģʽ/������Ԫ������/ctrlX/Sum/Sum_PD'
 * '<S686>' : 'controller/����ģʽ/������Ԫ������/ctrlX/Sum/Sum_PI'
 * '<S687>' : 'controller/����ģʽ/������Ԫ������/ctrlX/Sum/Sum_PID'
 * '<S688>' : 'controller/����ģʽ/������Ԫ������/ctrlX/Sum Fdbk/Disabled'
 * '<S689>' : 'controller/����ģʽ/������Ԫ������/ctrlX/Sum Fdbk/Enabled'
 * '<S690>' : 'controller/����ģʽ/������Ԫ������/ctrlX/Sum Fdbk/Passthrough'
 * '<S691>' : 'controller/����ģʽ/������Ԫ������/ctrlX/Tracking Mode/Disabled'
 * '<S692>' : 'controller/����ģʽ/������Ԫ������/ctrlX/Tracking Mode/Enabled'
 * '<S693>' : 'controller/����ģʽ/������Ԫ������/ctrlX/Tracking Mode Sum/Passthrough'
 * '<S694>' : 'controller/����ģʽ/������Ԫ������/ctrlX/Tracking Mode Sum/Tracking Mode'
 * '<S695>' : 'controller/����ģʽ/������Ԫ������/ctrlX/postSat Signal/Feedback_Path'
 * '<S696>' : 'controller/����ģʽ/������Ԫ������/ctrlX/postSat Signal/Forward_Path'
 * '<S697>' : 'controller/����ģʽ/������Ԫ������/ctrlX/preSat Signal/Feedback_Path'
 * '<S698>' : 'controller/����ģʽ/������Ԫ������/ctrlX/preSat Signal/Forward_Path'
 * '<S699>' : 'controller/����ģʽ/������Ԫ������/ctrlY/Anti-windup'
 * '<S700>' : 'controller/����ģʽ/������Ԫ������/ctrlY/D Gain'
 * '<S701>' : 'controller/����ģʽ/������Ԫ������/ctrlY/Filter'
 * '<S702>' : 'controller/����ģʽ/������Ԫ������/ctrlY/Filter ICs'
 * '<S703>' : 'controller/����ģʽ/������Ԫ������/ctrlY/I Gain'
 * '<S704>' : 'controller/����ģʽ/������Ԫ������/ctrlY/Ideal P Gain'
 * '<S705>' : 'controller/����ģʽ/������Ԫ������/ctrlY/Ideal P Gain Fdbk'
 * '<S706>' : 'controller/����ģʽ/������Ԫ������/ctrlY/Integrator'
 * '<S707>' : 'controller/����ģʽ/������Ԫ������/ctrlY/Integrator ICs'
 * '<S708>' : 'controller/����ģʽ/������Ԫ������/ctrlY/N Copy'
 * '<S709>' : 'controller/����ģʽ/������Ԫ������/ctrlY/N Gain'
 * '<S710>' : 'controller/����ģʽ/������Ԫ������/ctrlY/P Copy'
 * '<S711>' : 'controller/����ģʽ/������Ԫ������/ctrlY/Parallel P Gain'
 * '<S712>' : 'controller/����ģʽ/������Ԫ������/ctrlY/Reset Signal'
 * '<S713>' : 'controller/����ģʽ/������Ԫ������/ctrlY/Saturation'
 * '<S714>' : 'controller/����ģʽ/������Ԫ������/ctrlY/Saturation Fdbk'
 * '<S715>' : 'controller/����ģʽ/������Ԫ������/ctrlY/Sum'
 * '<S716>' : 'controller/����ģʽ/������Ԫ������/ctrlY/Sum Fdbk'
 * '<S717>' : 'controller/����ģʽ/������Ԫ������/ctrlY/Tracking Mode'
 * '<S718>' : 'controller/����ģʽ/������Ԫ������/ctrlY/Tracking Mode Sum'
 * '<S719>' : 'controller/����ģʽ/������Ԫ������/ctrlY/postSat Signal'
 * '<S720>' : 'controller/����ģʽ/������Ԫ������/ctrlY/preSat Signal'
 * '<S721>' : 'controller/����ģʽ/������Ԫ������/ctrlY/Anti-windup/Back Calculation'
 * '<S722>' : 'controller/����ģʽ/������Ԫ������/ctrlY/Anti-windup/Cont. Clamping Ideal'
 * '<S723>' : 'controller/����ģʽ/������Ԫ������/ctrlY/Anti-windup/Cont. Clamping Parallel'
 * '<S724>' : 'controller/����ģʽ/������Ԫ������/ctrlY/Anti-windup/Disabled'
 * '<S725>' : 'controller/����ģʽ/������Ԫ������/ctrlY/Anti-windup/Disc. Clamping Ideal'
 * '<S726>' : 'controller/����ģʽ/������Ԫ������/ctrlY/Anti-windup/Disc. Clamping Parallel'
 * '<S727>' : 'controller/����ģʽ/������Ԫ������/ctrlY/Anti-windup/Passthrough'
 * '<S728>' : 'controller/����ģʽ/������Ԫ������/ctrlY/D Gain/Disabled'
 * '<S729>' : 'controller/����ģʽ/������Ԫ������/ctrlY/D Gain/External Parameters'
 * '<S730>' : 'controller/����ģʽ/������Ԫ������/ctrlY/D Gain/Internal Parameters'
 * '<S731>' : 'controller/����ģʽ/������Ԫ������/ctrlY/Filter/Cont. Filter'
 * '<S732>' : 'controller/����ģʽ/������Ԫ������/ctrlY/Filter/Differentiator'
 * '<S733>' : 'controller/����ģʽ/������Ԫ������/ctrlY/Filter/Disabled'
 * '<S734>' : 'controller/����ģʽ/������Ԫ������/ctrlY/Filter/Disc. Backward Euler Filter'
 * '<S735>' : 'controller/����ģʽ/������Ԫ������/ctrlY/Filter/Disc. Forward Euler Filter'
 * '<S736>' : 'controller/����ģʽ/������Ԫ������/ctrlY/Filter/Disc. Trapezoidal Filter'
 * '<S737>' : 'controller/����ģʽ/������Ԫ������/ctrlY/Filter ICs/Disabled'
 * '<S738>' : 'controller/����ģʽ/������Ԫ������/ctrlY/Filter ICs/External IC'
 * '<S739>' : 'controller/����ģʽ/������Ԫ������/ctrlY/Filter ICs/Internal IC - Differentiator'
 * '<S740>' : 'controller/����ģʽ/������Ԫ������/ctrlY/Filter ICs/Internal IC - Filter'
 * '<S741>' : 'controller/����ģʽ/������Ԫ������/ctrlY/I Gain/Disabled'
 * '<S742>' : 'controller/����ģʽ/������Ԫ������/ctrlY/I Gain/External Parameters'
 * '<S743>' : 'controller/����ģʽ/������Ԫ������/ctrlY/I Gain/Internal Parameters'
 * '<S744>' : 'controller/����ģʽ/������Ԫ������/ctrlY/Ideal P Gain/External Parameters'
 * '<S745>' : 'controller/����ģʽ/������Ԫ������/ctrlY/Ideal P Gain/Internal Parameters'
 * '<S746>' : 'controller/����ģʽ/������Ԫ������/ctrlY/Ideal P Gain/Passthrough'
 * '<S747>' : 'controller/����ģʽ/������Ԫ������/ctrlY/Ideal P Gain Fdbk/Disabled'
 * '<S748>' : 'controller/����ģʽ/������Ԫ������/ctrlY/Ideal P Gain Fdbk/External Parameters'
 * '<S749>' : 'controller/����ģʽ/������Ԫ������/ctrlY/Ideal P Gain Fdbk/Internal Parameters'
 * '<S750>' : 'controller/����ģʽ/������Ԫ������/ctrlY/Ideal P Gain Fdbk/Passthrough'
 * '<S751>' : 'controller/����ģʽ/������Ԫ������/ctrlY/Integrator/Continuous'
 * '<S752>' : 'controller/����ģʽ/������Ԫ������/ctrlY/Integrator/Disabled'
 * '<S753>' : 'controller/����ģʽ/������Ԫ������/ctrlY/Integrator/Discrete'
 * '<S754>' : 'controller/����ģʽ/������Ԫ������/ctrlY/Integrator ICs/Disabled'
 * '<S755>' : 'controller/����ģʽ/������Ԫ������/ctrlY/Integrator ICs/External IC'
 * '<S756>' : 'controller/����ģʽ/������Ԫ������/ctrlY/Integrator ICs/Internal IC'
 * '<S757>' : 'controller/����ģʽ/������Ԫ������/ctrlY/N Copy/Disabled'
 * '<S758>' : 'controller/����ģʽ/������Ԫ������/ctrlY/N Copy/Disabled wSignal Specification'
 * '<S759>' : 'controller/����ģʽ/������Ԫ������/ctrlY/N Copy/External Parameters'
 * '<S760>' : 'controller/����ģʽ/������Ԫ������/ctrlY/N Copy/Internal Parameters'
 * '<S761>' : 'controller/����ģʽ/������Ԫ������/ctrlY/N Gain/Disabled'
 * '<S762>' : 'controller/����ģʽ/������Ԫ������/ctrlY/N Gain/External Parameters'
 * '<S763>' : 'controller/����ģʽ/������Ԫ������/ctrlY/N Gain/Internal Parameters'
 * '<S764>' : 'controller/����ģʽ/������Ԫ������/ctrlY/N Gain/Passthrough'
 * '<S765>' : 'controller/����ģʽ/������Ԫ������/ctrlY/P Copy/Disabled'
 * '<S766>' : 'controller/����ģʽ/������Ԫ������/ctrlY/P Copy/External Parameters Ideal'
 * '<S767>' : 'controller/����ģʽ/������Ԫ������/ctrlY/P Copy/Internal Parameters Ideal'
 * '<S768>' : 'controller/����ģʽ/������Ԫ������/ctrlY/Parallel P Gain/Disabled'
 * '<S769>' : 'controller/����ģʽ/������Ԫ������/ctrlY/Parallel P Gain/External Parameters'
 * '<S770>' : 'controller/����ģʽ/������Ԫ������/ctrlY/Parallel P Gain/Internal Parameters'
 * '<S771>' : 'controller/����ģʽ/������Ԫ������/ctrlY/Parallel P Gain/Passthrough'
 * '<S772>' : 'controller/����ģʽ/������Ԫ������/ctrlY/Reset Signal/Disabled'
 * '<S773>' : 'controller/����ģʽ/������Ԫ������/ctrlY/Reset Signal/External Reset'
 * '<S774>' : 'controller/����ģʽ/������Ԫ������/ctrlY/Saturation/Enabled'
 * '<S775>' : 'controller/����ģʽ/������Ԫ������/ctrlY/Saturation/Passthrough'
 * '<S776>' : 'controller/����ģʽ/������Ԫ������/ctrlY/Saturation Fdbk/Disabled'
 * '<S777>' : 'controller/����ģʽ/������Ԫ������/ctrlY/Saturation Fdbk/Enabled'
 * '<S778>' : 'controller/����ģʽ/������Ԫ������/ctrlY/Saturation Fdbk/Passthrough'
 * '<S779>' : 'controller/����ģʽ/������Ԫ������/ctrlY/Sum/Passthrough_I'
 * '<S780>' : 'controller/����ģʽ/������Ԫ������/ctrlY/Sum/Passthrough_P'
 * '<S781>' : 'controller/����ģʽ/������Ԫ������/ctrlY/Sum/Sum_PD'
 * '<S782>' : 'controller/����ģʽ/������Ԫ������/ctrlY/Sum/Sum_PI'
 * '<S783>' : 'controller/����ģʽ/������Ԫ������/ctrlY/Sum/Sum_PID'
 * '<S784>' : 'controller/����ģʽ/������Ԫ������/ctrlY/Sum Fdbk/Disabled'
 * '<S785>' : 'controller/����ģʽ/������Ԫ������/ctrlY/Sum Fdbk/Enabled'
 * '<S786>' : 'controller/����ģʽ/������Ԫ������/ctrlY/Sum Fdbk/Passthrough'
 * '<S787>' : 'controller/����ģʽ/������Ԫ������/ctrlY/Tracking Mode/Disabled'
 * '<S788>' : 'controller/����ģʽ/������Ԫ������/ctrlY/Tracking Mode/Enabled'
 * '<S789>' : 'controller/����ģʽ/������Ԫ������/ctrlY/Tracking Mode Sum/Passthrough'
 * '<S790>' : 'controller/����ģʽ/������Ԫ������/ctrlY/Tracking Mode Sum/Tracking Mode'
 * '<S791>' : 'controller/����ģʽ/������Ԫ������/ctrlY/postSat Signal/Feedback_Path'
 * '<S792>' : 'controller/����ģʽ/������Ԫ������/ctrlY/postSat Signal/Forward_Path'
 * '<S793>' : 'controller/����ģʽ/������Ԫ������/ctrlY/preSat Signal/Feedback_Path'
 * '<S794>' : 'controller/����ģʽ/������Ԫ������/ctrlY/preSat Signal/Forward_Path'
 * '<S795>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/Anti-windup'
 * '<S796>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/D Gain'
 * '<S797>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/Filter'
 * '<S798>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/Filter ICs'
 * '<S799>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/I Gain'
 * '<S800>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/Ideal P Gain'
 * '<S801>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/Ideal P Gain Fdbk'
 * '<S802>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/Integrator'
 * '<S803>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/Integrator ICs'
 * '<S804>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/N Copy'
 * '<S805>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/N Gain'
 * '<S806>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/P Copy'
 * '<S807>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/Parallel P Gain'
 * '<S808>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/Reset Signal'
 * '<S809>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/Saturation'
 * '<S810>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/Saturation Fdbk'
 * '<S811>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/Sum'
 * '<S812>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/Sum Fdbk'
 * '<S813>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/Tracking Mode'
 * '<S814>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/Tracking Mode Sum'
 * '<S815>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/postSat Signal'
 * '<S816>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/preSat Signal'
 * '<S817>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/Anti-windup/Back Calculation'
 * '<S818>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/Anti-windup/Cont. Clamping Ideal'
 * '<S819>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/Anti-windup/Cont. Clamping Parallel'
 * '<S820>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/Anti-windup/Disabled'
 * '<S821>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/Anti-windup/Disc. Clamping Ideal'
 * '<S822>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/Anti-windup/Disc. Clamping Parallel'
 * '<S823>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/Anti-windup/Passthrough'
 * '<S824>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/D Gain/Disabled'
 * '<S825>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/D Gain/External Parameters'
 * '<S826>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/D Gain/Internal Parameters'
 * '<S827>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/Filter/Cont. Filter'
 * '<S828>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/Filter/Differentiator'
 * '<S829>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/Filter/Disabled'
 * '<S830>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/Filter/Disc. Backward Euler Filter'
 * '<S831>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/Filter/Disc. Forward Euler Filter'
 * '<S832>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/Filter/Disc. Trapezoidal Filter'
 * '<S833>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/Filter ICs/Disabled'
 * '<S834>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/Filter ICs/External IC'
 * '<S835>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/Filter ICs/Internal IC - Differentiator'
 * '<S836>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/Filter ICs/Internal IC - Filter'
 * '<S837>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/I Gain/Disabled'
 * '<S838>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/I Gain/External Parameters'
 * '<S839>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/I Gain/Internal Parameters'
 * '<S840>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/Ideal P Gain/External Parameters'
 * '<S841>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/Ideal P Gain/Internal Parameters'
 * '<S842>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/Ideal P Gain/Passthrough'
 * '<S843>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/Ideal P Gain Fdbk/Disabled'
 * '<S844>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/Ideal P Gain Fdbk/External Parameters'
 * '<S845>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/Ideal P Gain Fdbk/Internal Parameters'
 * '<S846>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/Ideal P Gain Fdbk/Passthrough'
 * '<S847>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/Integrator/Continuous'
 * '<S848>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/Integrator/Disabled'
 * '<S849>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/Integrator/Discrete'
 * '<S850>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/Integrator ICs/Disabled'
 * '<S851>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/Integrator ICs/External IC'
 * '<S852>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/Integrator ICs/Internal IC'
 * '<S853>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/N Copy/Disabled'
 * '<S854>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/N Copy/Disabled wSignal Specification'
 * '<S855>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/N Copy/External Parameters'
 * '<S856>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/N Copy/Internal Parameters'
 * '<S857>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/N Gain/Disabled'
 * '<S858>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/N Gain/External Parameters'
 * '<S859>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/N Gain/Internal Parameters'
 * '<S860>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/N Gain/Passthrough'
 * '<S861>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/P Copy/Disabled'
 * '<S862>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/P Copy/External Parameters Ideal'
 * '<S863>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/P Copy/Internal Parameters Ideal'
 * '<S864>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/Parallel P Gain/Disabled'
 * '<S865>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/Parallel P Gain/External Parameters'
 * '<S866>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/Parallel P Gain/Internal Parameters'
 * '<S867>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/Parallel P Gain/Passthrough'
 * '<S868>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/Reset Signal/Disabled'
 * '<S869>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/Reset Signal/External Reset'
 * '<S870>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/Saturation/Enabled'
 * '<S871>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/Saturation/Passthrough'
 * '<S872>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/Saturation Fdbk/Disabled'
 * '<S873>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/Saturation Fdbk/Enabled'
 * '<S874>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/Saturation Fdbk/Passthrough'
 * '<S875>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/Sum/Passthrough_I'
 * '<S876>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/Sum/Passthrough_P'
 * '<S877>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/Sum/Sum_PD'
 * '<S878>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/Sum/Sum_PI'
 * '<S879>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/Sum/Sum_PID'
 * '<S880>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/Sum Fdbk/Disabled'
 * '<S881>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/Sum Fdbk/Enabled'
 * '<S882>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/Sum Fdbk/Passthrough'
 * '<S883>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/Tracking Mode/Disabled'
 * '<S884>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/Tracking Mode/Enabled'
 * '<S885>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/Tracking Mode Sum/Passthrough'
 * '<S886>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/Tracking Mode Sum/Tracking Mode'
 * '<S887>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/postSat Signal/Feedback_Path'
 * '<S888>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/postSat Signal/Forward_Path'
 * '<S889>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/preSat Signal/Feedback_Path'
 * '<S890>' : 'controller/����ģʽ/������Ԫ������/ctrlZ/preSat Signal/Forward_Path'
 * '<S891>' : 'controller/�������/�������'
 * '<S892>' : 'controller/�������/�������/λ���ٶ�ת��Ϊ����'
 * '<S893>' : 'controller/�������/�������/����ϵ���ϵת����'
 * '<S894>' : 'controller/�������/�������/�������ѧ��������������'
 * '<S895>' : 'controller/�������ݴ���/GyroChkValid'
 * '<S896>' : 'controller/�������ݴ���/GyroComptueDelta'
 * '<S897>' : 'controller/�������ݴ���/���ٶ���ֵ'
 */
#endif                                 /* RTW_HEADER_controller_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
