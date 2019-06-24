#include "bsp.h"

#define TRAP(H)   		mov %psr, %l0; sethi %hi(H), %l4; jmp %l4+%lo(H); nop;
#define TRAPL(H)        mov %g0, %l0; sethi %hi(H), %l4; jmp %l4+%lo(H); nop;

#ifdef DEBUG /*调试模式*/
#define BAD_TRAP        ta 0; nop; nop; nop;             /*飞行默认陷阱处理为ta 0 直接挂掉*/
#else        /*飞行模式*/
#define BAD_TRAP        GOOD_TRAP
#endif

#define GOOD_TRAP       jmp  %l2; rett  %l2+4; nop; nop; /*飞行默认陷阱默认处理直接跳转到下一条指令*/

#ifdef DEBUG /*调试模式*/
#define SOFT_TRAP       BAD_TRAP                         /*陷阱处理方式入口*/
#else        /*飞行模式*/
#define SOFT_TRAP       GOOD_TRAP                         /*陷阱处理方式入口*/
#endif

#define SOFT_TA_4       jmp  %l2; restore; nop; nop;     /*陷阱4作为快速关中断处理*/

        .text
		.global _trap_table,start
		.global _privileged_exception
		.global  _fp_disable
        .global _window_overflow
        .global _window_underflow
        .global _window_overflow4
        .global _window_underflow4
        .global  _fp_exception
        .global _flush_windows

 /* don't edit contents below */
		.global __stack
		.global __ram_len
		.global text_start
		.global _text_start
		.global end
		.global _end
		.global __end

		.global ExtIntHandle
start:
_trap_table:
		TRAPL(_hardreset);							!00 reset trap
		BAD_TRAP;									!01 instruction_access_exception
		BAD_TRAP;									!02 illegal_instruction
		TRAP(_privileged_exception);  				!03 privileged_instruction
		BAD_TRAP;						            !04 fp_disabled
		TRAP(_window_overflow);					!05 window_overflow
		TRAP(_window_underflow);					!06 window_underflow
		BAD_TRAP;									!07 memory_address_not_aligned
		BAD_TRAP;						            !08 fp_exception
		BAD_TRAP;									!09 data_access_exception
		BAD_TRAP;									!0A tag_overflow
		BAD_TRAP;									!0B undefined
		BAD_TRAP;									!0C undefined
		BAD_TRAP;									!0D undefined
		BAD_TRAP;									!0E undefined
		BAD_TRAP;									!0F undefined
		BAD_TRAP;									!10 undefined

	  /* Interrupt entries */
		TRAP(irqtrap);								!11 interrupt level 1
		TRAP(irqtrap);								!12 interrupt level 2
		TRAP(irqtrap);								!13 interrupt level 3
		TRAP(ENXIT_ENTRY);							!14 interrupt level 4
		TRAP(ENXIT_ENTRY);							!15 interrupt level 5
		TRAP(ENXIT_ENTRY);							!16 interrupt level 6
		TRAP(ENXIT_ENTRY);							!17 interrupt level 7
		TRAP(irqtrap);								!18 interrupt level 8
		TRAP(irqtrap);								!19 interrupt level 9
		TRAP(irqtrap);								!1A interrupt level 1
		TRAP(irqtrap);								!1B interrupt level 11
		TRAP(irqtrap);								!1C interrupt level 12
		TRAP(irqtrap);								!1D interrupt level 13
		TRAP(irqtrap);								!1E interrupt level 14
		TRAP(irqtrap);								!1F interrupt level 15
		BAD_TRAP; BAD_TRAP; BAD_TRAP; BAD_TRAP;		!20 - 23 undefined
		TRAP(_cp_disable);							!24   cp_disabled
		BAD_TRAP; BAD_TRAP; BAD_TRAP;				!25 - 27 undefined
		BAD_TRAP;									!28   cp_exception
		BAD_TRAP; BAD_TRAP; BAD_TRAP;				!29 - 2B undefined
		BAD_TRAP; BAD_TRAP; BAD_TRAP; BAD_TRAP;		!2C - 2F undefined
		BAD_TRAP; BAD_TRAP; BAD_TRAP; BAD_TRAP;		!30 - 33 undefined
		BAD_TRAP; BAD_TRAP; BAD_TRAP; BAD_TRAP;		!34 - 37 undefined
		BAD_TRAP; BAD_TRAP; BAD_TRAP; BAD_TRAP;		!38 - 3B undefined
		BAD_TRAP; BAD_TRAP; BAD_TRAP; BAD_TRAP;		!3C - 3F undefined
		BAD_TRAP; BAD_TRAP; BAD_TRAP; BAD_TRAP;		!40 - 43 undefined
		BAD_TRAP; BAD_TRAP; BAD_TRAP; BAD_TRAP;		!44 - 47 undefined
		BAD_TRAP; BAD_TRAP; BAD_TRAP; BAD_TRAP;		!48 - 4B undefined
		BAD_TRAP; BAD_TRAP; BAD_TRAP; BAD_TRAP;		!4C - 4F undefined
		BAD_TRAP; BAD_TRAP; BAD_TRAP; BAD_TRAP;		!50 - 53 undefined
		BAD_TRAP; BAD_TRAP; BAD_TRAP; BAD_TRAP;		!54 - 57 undefined
		BAD_TRAP; BAD_TRAP; BAD_TRAP; BAD_TRAP;		!58 - 5B undefined
		BAD_TRAP; BAD_TRAP; BAD_TRAP; BAD_TRAP;		!5C - 5F undefined
		BAD_TRAP; BAD_TRAP; BAD_TRAP; BAD_TRAP;		!60 - 63 undefined
		BAD_TRAP; BAD_TRAP; BAD_TRAP; BAD_TRAP;		!64 - 67 undefined
		BAD_TRAP; BAD_TRAP; BAD_TRAP; BAD_TRAP;		!68 - 6B undefined
		BAD_TRAP; BAD_TRAP; BAD_TRAP; BAD_TRAP;		!6C - 6F undefined
		BAD_TRAP; BAD_TRAP; BAD_TRAP; BAD_TRAP;		!70 - 73 undefined
		BAD_TRAP; BAD_TRAP; BAD_TRAP; BAD_TRAP;		!74 - 77 undefined
		BAD_TRAP; BAD_TRAP; BAD_TRAP; BAD_TRAP;		!78 - 7B undefined
		BAD_TRAP; BAD_TRAP; BAD_TRAP; BAD_TRAP;		!7C - 7F undefined

	 /* Software traps */
	  	SOFT_TRAP; 									!80 使CPU进入错误模式
	  	SOFT_TRAP; 									!81 用于断点
	  	GOOD_TRAP; 									!82 用于整数除法除零异常
	  	TRAP(_flush_windows)						!83 用于setjmp 和 longjmp
	  	SOFT_TA_4; 									!84 用于实现快速关中断
	  	SOFT_TRAP; SOFT_TRAP; SOFT_TRAP;			!85 - 87
	  	SOFT_TRAP; SOFT_TRAP; SOFT_TRAP; SOFT_TRAP;	!88 - 8B
	  	SOFT_TRAP; SOFT_TRAP; SOFT_TRAP; SOFT_TRAP;	!8C - 8F
	  	SOFT_TRAP; SOFT_TRAP; SOFT_TRAP; SOFT_TRAP;	!90 - 93
	  	SOFT_TRAP; SOFT_TRAP; SOFT_TRAP; SOFT_TRAP;	!94 - 97
	  	SOFT_TRAP; SOFT_TRAP; SOFT_TRAP; SOFT_TRAP;	!98 - 9B
	  	SOFT_TRAP; SOFT_TRAP; SOFT_TRAP; SOFT_TRAP;	!9C - 9F
	  	SOFT_TRAP; SOFT_TRAP; SOFT_TRAP; SOFT_TRAP;	!A0 - A3
	  	SOFT_TRAP; SOFT_TRAP; SOFT_TRAP; SOFT_TRAP;	!A4 - A7
	  	SOFT_TRAP; SOFT_TRAP; SOFT_TRAP; SOFT_TRAP;	!A8 - AB
	  	SOFT_TRAP; SOFT_TRAP; SOFT_TRAP; SOFT_TRAP;	!AC - AF
	  	SOFT_TRAP; SOFT_TRAP; SOFT_TRAP; SOFT_TRAP;	!B0 - B3
	  	SOFT_TRAP; SOFT_TRAP; SOFT_TRAP; SOFT_TRAP;	!B4 - B7
	  	SOFT_TRAP; SOFT_TRAP; SOFT_TRAP; SOFT_TRAP;	!B8 - BB
	  	SOFT_TRAP; SOFT_TRAP; SOFT_TRAP; SOFT_TRAP;	!BC - BF
	  	SOFT_TRAP; SOFT_TRAP; SOFT_TRAP; SOFT_TRAP;	!C0 - C3
	  	SOFT_TRAP; SOFT_TRAP; SOFT_TRAP; SOFT_TRAP;	!C4 - C7
	  	SOFT_TRAP; SOFT_TRAP; SOFT_TRAP; SOFT_TRAP;	!C8 - CB
	  	SOFT_TRAP; SOFT_TRAP; SOFT_TRAP; SOFT_TRAP;	!CC - CF
	  	SOFT_TRAP; SOFT_TRAP; SOFT_TRAP; SOFT_TRAP;	!D0 - D3
	  	SOFT_TRAP; SOFT_TRAP; SOFT_TRAP; SOFT_TRAP;	!D4 - D7
	  	SOFT_TRAP; SOFT_TRAP; SOFT_TRAP; SOFT_TRAP;	!D8 - DB
	  	SOFT_TRAP; SOFT_TRAP; SOFT_TRAP; SOFT_TRAP;	!DC - DF
	  	SOFT_TRAP; SOFT_TRAP; SOFT_TRAP; SOFT_TRAP;	!E0 - E3
	  	SOFT_TRAP; SOFT_TRAP; SOFT_TRAP; SOFT_TRAP;	!E4 - E7
	  	SOFT_TRAP; SOFT_TRAP; SOFT_TRAP; SOFT_TRAP;	!E8 - EB
	  	SOFT_TRAP; SOFT_TRAP; SOFT_TRAP; SOFT_TRAP;	!EC - EF
	  	SOFT_TRAP; SOFT_TRAP; SOFT_TRAP; SOFT_TRAP;	!F0 - F3
	  	SOFT_TRAP; SOFT_TRAP; SOFT_TRAP; SOFT_TRAP;	!F4 - F7
	  	SOFT_TRAP; SOFT_TRAP; SOFT_TRAP; SOFT_TRAP;	!F8 - FB
	    SOFT_TRAP; SOFT_TRAP; SOFT_TRAP; SOFT_TRAP;	!FC - FF
_hardreset:
    	/*设置处理器状态寄存器 %psr */
    	set	0x10e7,%g2			!set PSR. cwp=7,et=1,ps=1.s=1,pil=0,ef=1
    	mov	%g2,%psr
    	nop
    	nop
    	nop
 	
    	/*设置cache寄存器 */
    	flush								
    	set		0x0,%g2									
    	sta		%g2,[%g0] 2							!disable all cache functions


    	/*设置TRAP表基地址%tbr 到0x0 */
    	set 	_trap_table,%g2		!set trap table base address
    	mov 	%g2,%tbr
    	nop
    	nop
    	nop

	
    	/*屏蔽所有可屏蔽的中断 */
    	set	BSPMECBASE,%g1
    	set 0x0, %g2
    	st 	%g2,[%g1+BSP_INTR_MKR]						!Mask all the interrupts

    	/*清除所有被阻塞的中断 */
    	set	0xFFFE,%g2
    	st  %g2,[%g1+BSP_INTR_CLR]						!Clear all the pending interrupts
		
		/* calm down WDG   */
		set   0xffffff,  %g2					!CPU watchdog is disabled after CPU reset
		st    %g2, [%g1 + 0x350]
		st    %g2, [%g1 + 0x354]
  
	/*将全局寄存器清零*/
	clr 	%g1
	clr 	%g2
	clr 	%g3
	clr 	%g4
	clr 	%g5
	clr 	%g6
	clr 	%g7
	
	/*Y寄存器清零*/
	mov 	%g0,%y

	/*置%wim为0，防止window trap 发生*/
	mov 	%g0,%wim    			!Set %wim as 0 to make the Window traps not occur
	
	/*窗口寄存器清零*/
	set 	8,%g1
w10:
	clr 	%i0
	clr 	%i1
	clr 	%i2
	clr 	%i3
	clr 	%i4
	clr 	%i5
	clr 	%i6
	clr 	%i7
	clr 	%l0
	clr 	%l1
	clr 	%l2
	clr 	%l3
	clr 	%l4
	clr 	%l5
	clr 	%l6
	clr 	%l7
	save
	subcc 	%g1,1,%g1
	bne 	w10
	nop
	

	/*初始化%wim寄存器*/
	set 	0x1,%g2
	mov 	%g2,%wim								!set wim as 1
	nop
	nop
	nop

	set	0,%g1
	nop

	/*浮点寄存器清零*/
	ld 	[%g1],%f0
	ld 	[%g1],%f1
	ld 	[%g1],%f2
	ld 	[%g1],%f3
	ld 	[%g1],%f4
	ld 	[%g1],%f5
	ld 	[%g1],%f6
	ld 	[%g1],%f7
	ld 	[%g1],%f8
	ld 	[%g1],%f9
	ld 	[%g1],%f10
	ld 	[%g1],%f11
	ld 	[%g1],%f12
	ld 	[%g1],%f13
	ld 	[%g1],%f14
	ld 	[%g1],%f15
	ld 	[%g1],%f16
	ld 	[%g1],%f17
	ld 	[%g1],%f18
	ld 	[%g1],%f19
	ld 	[%g1],%f20
	ld 	[%g1],%f21
	ld 	[%g1],%f22
	ld 	[%g1],%f23
	ld 	[%g1],%f24
	ld 	[%g1],%f25
	ld 	[%g1],%f26
	ld 	[%g1],%f27
	ld 	[%g1],%f28
	ld 	[%g1],%f29
	ld 	[%g1],%f30
	ld 	[%g1],%f31
	
	/*设置系统堆栈*/
	set	BSPRAMBASE,%i6			!ram base address
	set	BSPSTACK,%l4			!sys stack
	add %i6,%l4,%i6
	sub	%i6,BSPMINSTACKSIZE,%i6	!set frame pointer
	sub	%i6,BSPMINSTACKSIZE,%o6	!set stack pointer


	/*与用户相关的硬件初始化*/
	call	BSP_Init_CPU		!call user hardware initial procedure
	nop
	
	set		BSPCCR_INIT,%o2									
	sta		%o2,[%g0] 2											!config cache, 20130709,cannot use macro in C function BSP_Init_CPU(), therefore init cache control register here
	
		
	/*设置浮点状态寄存器*/
	set	1,%g2
	set	BSPFSR_INIT,%g3
	st	%g3,[%g2]
 	ld  [%g2], %fsr
	nop
	nop
	nop

    	!bss段清0
    	call   _userinit
    	nop

    	!进入用户主函数
    	call    SysMain
    	nop

_exit:
    	set  1 , %g1
  		ta   0
  		nop
  		nop

_userinit:
    	save
    	sethi  %hi(__bss_start),%g2
    	or     %g2,%lo(__bss_start),%g2  ! g2 = start of bss
    	sethi  %hi(_end),%g3
    	or     %g3,%lo(_end),%g3         ! g3 = end of bss
    	mov    %g0,%g1                   ! so std has two zeros
    	sub    %g3, %g2, %g3
    	cmp    %g3,0
    	be     over
    	nop
zerobss:
    	subcc  %g3, 8, %g3
    	bge,a   zerobss
    	std    %g0,[%g2+%g3]
    	set    _end, %o0
    	st     %g0,[%o0]
    	nop
 over:
        ret
        restore

_privileged_exception:
        !置位PSR中的 S PS ,进入特权模式
        set 0xc0,%g1
		mov %psr,%g2
		nop
		nop
		nop

		or  %g2,%g1,%g1
		mov %g1,%psr					! enable EF bit of psr
		nop
		nop
		nop

	    jmpl    %l1, %g0
        rett    %l2
        nop
        nop

/* _fp_disable */
/* 如果EF位为1则退出到产生异常的下一条指令，否则将EF位设置为1，退出到产生异常的指令重新执行*/
_fp_disable:
        set     0x1000,%l4
        andcc   %l0, %l4, %l3                 !judge EF bit of PSR register
        bnz     _fp_dis_npc_continue                 ! No, then continue
        nop

        !置位PSR中的EF
		or  %l4,%l0,%l0
		mov %l0,%psr					! enable EF bit of psr
		nop
		nop
		nop

	    jmpl    %l1, %g0
        rett    %l2
        nop
        nop

_fp_dis_npc_continue:
        mov     %l0, %psr    !restore psr
        nop
        nop
        nop
        jmpl    %l2, %g0
        rett    %l2 + 4
        nop
        nop
/* _cp_disable */
/* 如果EC位为1则退出到产生异常的下一条指令，否则将EC位设置为1，退出到产生异常的指令重新执行*/
_cp_disable:
        set     0x2000,%l4
        andcc   %l0, %l4, %l3                 !judge EC bit of PSR register
        bnz     _cp_dis_npc_continue                 ! No, then continue
        nop

        !置位PSR中的EC
		or  %l4,%l0,%l0
		mov %l0,%psr					! enable EC bit of psr
		nop
		nop
		nop

	    jmpl    %l1, %g0
        rett    %l2
        nop
        nop

_cp_dis_npc_continue:
        mov     %l0, %psr    !restore psr
        nop
        nop
        nop
        jmpl    %l2, %g0
        rett    %l2 + 4
        nop
        nop

  	 !Window overflow trap handler.
_window_overflow4:

  		mov  %wim, %l3       		! 计算下个窗口无效掩码
  		mov  %g1, %l7                        //保证如果wim模8
  		srl  %l3, 4, %g1
		sll  %l3, 4 , %l4
  		or   %l4, %g1, %g1

  		save                        ! 转4次窗口
  		save
  		save
  		save

    	std   %l0, [%sp + 0];   ! 保存窗口内寄存器
    	std   %l2, [%sp + 8];
    	std   %l4, [%sp + 16];
    	std   %l6, [%sp + 24];
    	std   %i0, [%sp + 32];
    	std   %i2, [%sp + 40];
    	std   %i4, [%sp + 48];
    	std   %i6, [%sp + 56];
  		restore                     ! 恢复窗口

  		mov  %g1, %wim              ! 给wim赋新值  ,移4位模8
  		nop; nop; nop

    	std   %l0, [%sp + 0];    ! 保存窗口内寄存器
    	std   %l2, [%sp + 8];
    	std   %l4, [%sp + 16];
    	std   %l6, [%sp + 24];
    	std   %i0, [%sp + 32];
    	std   %i2, [%sp + 40];
    	std   %i4, [%sp + 48];
    	std   %i6, [%sp + 56];

  		restore				! Go back to trap window.
    	std   %l0, [%sp + 0];   ! 保存窗口内寄存器
    	std   %l2, [%sp + 8];
    	std   %l4, [%sp + 16];
    	std   %l6, [%sp + 24];
    	std   %i0, [%sp + 32];
    	std   %i2, [%sp + 40];
    	std   %i4, [%sp + 48];
    	std   %i6, [%sp + 56];

    	restore				! Go back to trap window.
    	std   %l0, [%sp + 0];   ! 保存窗口内寄存器
    	std   %l2, [%sp + 8];
    	std   %l4, [%sp + 16];
    	std   %l6, [%sp + 24];
    	std   %i0, [%sp + 32];
    	std   %i2, [%sp + 40];
    	std   %i4, [%sp + 48];
    	std   %i6, [%sp + 56];

  		restore
  		mov  %l7, %g1                !恢复g1的值
  		jmp  %l1			! Re-execute save.
  		rett %l2
                                                                                        
  /* Window underflow trap handler.  */
_window_underflow4:

		mov  %wim, %l3			! Calculate next WIM
		sll  %l3, 4, %l4
  		srl  %l3, 4, %l5
  		or   %l5, %l4, %l5
  		mov  %l5, %wim
  		nop; nop; nop
  		restore				! Two restores to get into the
  		restore				! window to restore
  		ldd   [%sp + 0], %l0; 		! Restore window from the stack
    	ldd   [%sp + 8], %l2;
    	ldd   [%sp + 16], %l4;
    	ldd   [%sp + 24], %l6;
    	ldd   [%sp + 32], %i0;
    	ldd   [%sp + 40], %i2;
    	ldd   [%sp + 48], %i4;
    	ldd   [%sp + 56], %i6;
  		restore
    	ldd   [%sp + 0], %l0; 		! Restore window from the stack
    	ldd   [%sp + 8], %l2;
    	ldd   [%sp + 16], %l4;
    	ldd   [%sp + 24], %l6;
    	ldd   [%sp + 32], %i0;
    	ldd   [%sp + 40], %i2;
    	ldd   [%sp + 48], %i4;
    	ldd   [%sp + 56], %i6;
    	restore

    	ldd   [%sp + 0], %l0; 		! Restore window from the stack
    	ldd   [%sp + 8], %l2;
    	ldd   [%sp + 16], %l4;
    	ldd   [%sp + 24], %l6;
    	ldd   [%sp + 32], %i0;
    	ldd   [%sp + 40], %i2;
    	ldd   [%sp + 48], %i4;
    	ldd   [%sp + 56], %i6;

    	restore
    	ldd   [%sp + 0], %l0; 		! Restore window from the stack
    	ldd   [%sp + 8], %l2;
    	ldd   [%sp + 16], %l4;
    	ldd   [%sp + 24], %l6;
    	ldd   [%sp + 32], %i0;
    	ldd   [%sp + 40], %i2;
    	ldd   [%sp + 48], %i4;
    	ldd   [%sp + 56], %i6;
    	save
    	save
    	save
  		save				! Get back to the trap window.
  		save
  		jmp  %l1			! Re-execute restore.
  		rett  %l2

  	 		!Window overflow trap handler.
_window_overflow:

  		mov  %wim, %l3       		! Calculate next WIM
  		mov  %g1, %l7
  		srl  %l3, 1, %g1
		sll  %l3, 7 , %l4
  		or   %l4, %g1, %g1

  		save                              ! Get into window to be saved.
  		mov  %g1, %wim
  		nop; nop; nop
    	std   %l0, [%sp + 0];
    	std   %l2, [%sp + 8];
    	std   %l4, [%sp + 16];
    	std   %l6, [%sp + 24];
    	std   %i0, [%sp + 32];
    	std   %i2, [%sp + 40];
    	std   %i4, [%sp + 48];
    	std   %i6, [%sp + 56];
  		restore				! Go back to trap window.
  		mov  %l7, %g1
  		jmp  %l1			! Re-execute save.
  		rett %l2
                                                                                        
  /* Window underflow trap handler.  */
_window_underflow:

		mov  %wim, %l3			! Calculate next WIM
		sll  %l3, 1, %l4
  		srl  %l3, 7, %l5
  		or   %l5, %l4, %l5
  		mov  %l5, %wim
  		nop; nop; nop
  		restore				! Two restores to get into the
  		restore				! window to restore
    	ldd   [%sp + 0], %l0; 		! Restore window from the stack
    	ldd   [%sp + 8], %l2;
    	ldd   [%sp + 16], %l4;
    	ldd   [%sp + 24], %l6;
    	ldd   [%sp + 32], %i0;
    	ldd   [%sp + 40], %i2;
    	ldd   [%sp + 48], %i4;
    	ldd   [%sp + 56], %i6;
  		save				! Get back to the trap window.
  		save
  		jmp  %l1			! Re-execute restore.
  		rett  %l2

/* _fp_exception */
_fp_exception:
    	jmpl    %l2, %g0
    	rett    %l2 + 4
    	nop
    	nop

 /*
         *  Flush All Windows trap handler.
         *
         *  Flush all windows with valid contents except the current one
         *  and the one we will be returning to.
         *
         *  In examining the set register windows, one may logically divide
         *  the windows into sets (some of which may be empty) based on their
         *  current status:
         *
         *    + current (i.e. in use),
         *    + used (i.e. a restore would not trap)
         *    + invalid (i.e. 1 in corresponding bit in WIM)
         *    + unused
         *
         *  Either the used or unused set of windows may be empty.
         *
         *  NOTE: We assume only one bit is set in the WIM at a time.
         *
         *  Given a CWP of 5 and a WIM of 0x1, the registers are divided
         *  into sets as follows:
         *
         *    + 0   - invalid
         *    + 1-4 - unused
         *    + 5   - current
         *    + 6-7 - used
         *
         *  In this case, we only would save the used windows which we
         *  will not be returning to -- 6.
         *
         *    Register Usage while saving the windows:
         *      g1 = current PSR
         *      g2 = current wim
         *      g3 = CWP
         *      g4 = wim scratch
         *      g5 = scratch
         *
         *  On entry:
         *
         *    l0 = psr (from trap table)
         *    l1 = pc
         *    l2 = npc
*/
_flush_windows:
        /*
         *  Save the global registers we will be using
         */
        mov     %g1, %l3
        mov     %g2, %l4
        mov     %g3, %l5
        mov     %g4, %l6
        mov     %g5, %l7

        mov     %l0, %g1                      ! g1 = psr
        mov     %wim, %g2                     ! g2 = wim
        and     %l0, SPARC_PSR_CWP_MASK, %g3  ! g3 = CWP

        add     %g3, 1, %g5                   ! g5 = CWP + 1
        and     %g5, SPARC_NUMBER_OF_REGISTER_WINDOWS - 1, %g5

        mov     1, %g4
        sll     %g4, %g5, %g4                 ! g4 = WIM mask for CWP+1 invalid

        restore                               ! go back one register window

save_frame_loop:
        sll     %g4, 1, %g5                   ! rotate the "wim" left 1
        srl     %g4, SPARC_NUMBER_OF_REGISTER_WINDOWS - 1, %g4
        or      %g4, %g5, %g4                 ! g4 = wim if we do one restore

        /*
         *  If a restore would not underflow, then continue.
         */

        andcc   %g4, %g2, %g0                 ! Any windows to flush?
        bnz     done_flushing                 ! No, then continue
        nop

        restore                               ! back one window

        /*
         *  Now save the window just as if we overflowed to it.
         */

        std     %l0, [%sp + CPU_STACK_FRAME_L0_OFFSET]
        std     %l2, [%sp + CPU_STACK_FRAME_L2_OFFSET]
        std     %l4, [%sp + CPU_STACK_FRAME_L4_OFFSET]
        std     %l6, [%sp + CPU_STACK_FRAME_L6_OFFSET]

        std     %i0, [%sp + CPU_STACK_FRAME_I0_OFFSET]
        std     %i2, [%sp + CPU_STACK_FRAME_I2_OFFSET]
        std     %i4, [%sp + CPU_STACK_FRAME_I4_OFFSET]
        std     %i6, [%sp + CPU_STACK_FRAME_I6_FP_OFFSET]

        ba      save_frame_loop
        nop

done_flushing:

        add     %g3, 2, %g3                   ! calculate desired WIM
        and     %g3, SPARC_NUMBER_OF_REGISTER_WINDOWS - 1, %g3
        mov     1, %g4
        sll     %g4, %g3, %g4                 ! g4 = new WIM
        mov     %g4, %wim
        nop
        nop
        nop

        mov     %g1, %psr                     ! restore PSR
        nop
        nop
        nop

        /*
         *  Restore the global registers we used
         */

        mov     %l3, %g1
        mov     %l4, %g2
        mov     %l5, %g3
        mov     %l6, %g4
        mov     %l7, %g5

        jmpl    %l2, %g0
        rett    %l2 + 4


/*默认中断处理函数*/
.global _irqtbl

irqtrap:		
		jmp  %l2; rett  %l2+4; nop; nop;

.seg "data"
.align 8
.global _irqtbl

_irqtbl:
	.skip 0x40
	
/*外部中断处理函数*/
.global ENXIT_ENTRY

ENXIT_ENTRY:
/**************** Read Trap Base Register **************************/
        rd     %tbr, %l7
		srl    %l7, 0x4, %l7
		and    %l7, 0xff, %l7      ! 从TBR中读取陷阱类型
		sub    %l7, 0x14, %l7      ! 0x14 - 0x17 被分配给外部中断
		set    ExtIntHandle, %l6   ! 获取用户定义的外部中断服务地址表的基址
		sll    %l7, 0x2, %l7       ! 计算偏移量
		add    %l7, %l6, %l7
		ld     [%l7], %l7          ! 获取对应的用户定义的服务程序的入口地址
		                           ! 在完成中断处理之前, 不得修改寄存器l7

/****************Check window overflow******************************/
        mov    0x0E,%l3 
        rd     %psr,%l0
	    and    %l0,0x07,%l4           ! get CWP
	    mov    1,%l5
	    sll    %l5,%l4,%l5            !cwp is mapped to the bit
        rd     %wim,%l4               !get wim
        andcc  %l4,%l5,%g0            !judge whether the current window is invalid window
        be     Window_OK              !if current window is valid, jump to window_ok
        nop
 
/*****if the window is invalid save the window and adjust wim*******/
        save       
        std    %l0,[%sp + 0x00]
        std    %l2,[%sp + 0x08]
        std    %l4,[%sp + 0x10]
        std    %l6,[%sp + 0x18]
        std    %i0,[%sp + 0x20]
        std    %i2,[%sp + 0x28]
        std    %i4,[%sp + 0x30]
        std    %i6,[%sp + 0x38]
        rd     %wim,%l4
        srl    %l4, 1, %l5
        sll    %l4, 8-1, %l4
        or     %l4, %l5, %l4
        mov    %l4, %wim
        nop
        nop
        nop
        restore    
        nop

 Window_OK:
        sub    %fp, 0x60,%sp
        st     %l0, [%sp + 0x00]       !store LOCAL,IN and Global register to IntStack
        st     %l1, [%sp + 0x04]
        st     %l2, [%sp + 0x08]
        st     %l3, [%sp + 0x0c]
        st     %l4, [%sp + 0x10]
        st     %l5, [%sp + 0x14]
        st     %l6, [%sp + 0x18]
        st     %l7, [%sp + 0x1c]
        st     %i0, [%sp + 0x20]
        st     %i1, [%sp + 0x24]
        st     %i2, [%sp + 0x28]
        st     %i3, [%sp + 0x2c]
        st     %i4, [%sp + 0x30]
        st     %i5, [%sp + 0x34]
        st     %i6, [%sp + 0x38]
        st     %i7, [%sp + 0x3c]
        st     %g1, [%sp + 0x40]
        st     %g2, [%sp + 0x44]
        st     %g3, [%sp + 0x48]
        st     %g4, [%sp + 0x4c]
        st     %g5, [%sp + 0x50]
        st     %g6, [%sp + 0x54]
        st     %g7, [%sp + 0x58]
/******Enable traps and disable all the maskable interrupts ********/
        rd     %psr,%l4
        set    0xFFFFF0FF, %g2
        and    %g2,%l4, %l4
        sll    %l3, 0x08, %g2
        or     %l4,%g2, %l4
        mov    %l4,%psr                !disable all the maskable interrupts
        nop
        nop
        nop
        rd     %psr,%l4
        or     %l4,0x20,%l4
        nop
        nop
        mov    %l4,%psr                !enable trap
        nop
        nop
        nop
        call   %l7
        nop

        rd     %psr,%l4
        and    %l4,0xFFFFF0DF,%l4
        nop
        nop
        mov    %l4,%psr                !disable  trap 
        nop
        nop
        nop
Underflow_Check:
        rd     %psr,%l4
        and    %l4,0x07,%l4
        add    %l4,1,%l4
        and    %l4, 0x07, %l4          ! get CWP + 1 modulo NWINDOWS
        mov    1, %l5
        sll    %l5,%l4,%l5
        rd     %wim,%l4
        andcc  %l4, %l5, %g0           ! WIM & 2**(CWP+1)
        be     simple_return
        nop
        sll    %l4, 1, %l5             ! rotate WIM 1 place left
        srl    %l4, 8-1, %l4
        or     %l4, %l5, %l4
        wr     %l4, 0, %wim
        nop
        nop
        nop
  
        restore
        ldd    [%sp + 0x00], %l0
        ldd    [%sp + 0x08], %l2
        ldd    [%sp + 0x10], %l4
        ldd    [%sp + 0x18], %l6
        ldd    [%sp + 0x20], %i0
        ldd    [%sp + 0x28], %i2
        ldd    [%sp + 0x30], %i4
        ldd    [%sp + 0x38], %i6
        save
  
/**********************Simple Return********************************/
simple_return:
        ld     [%sp + 0x00],  %l0       !restore LOCAL,IN and Global register from IntStack
        ld     [%sp + 0x04],  %l1
        ld     [%sp + 0x08] , %l2
        ld     [%sp + 0x0c],  %l3
        ld     [%sp + 0x10],  %l4
        ld     [%sp + 0x14],  %l5
        ld     [%sp + 0x18],  %l6
        ld     [%sp + 0x1c],  %l7
        ld     [%sp + 0x20],  %i0
        ld     [%sp + 0x24],  %i1
        ld     [%sp + 0x28],  %i2
        ld     [%sp + 0x2c],  %i3
        ld     [%sp + 0x30],  %i4
        ld     [%sp + 0x34],  %i5
        ld     [%sp + 0x38],  %i6
        ld     [%sp + 0x3c],  %i7 
        ld     [%sp + 0x40],  %g1
        ld     [%sp + 0x44],  %g2
        ld     [%sp + 0x48],  %g3
        ld     [%sp + 0x4c],  %g4
        ld     [%sp + 0x50],  %g5
        ld     [%sp + 0x54],  %g6
        ld     [%sp + 0x58],  %g7 
/****clear the asfv bit and srfv bit of SYSFSR**********************/
/*********to make falling address be able to update*****************/
        rd     %psr,%l4
        and    %l4,0x07,%l4
        andn   %l0, 0x07, %l0
        or     %l0,%l4,%l0
        set    0x01000,%l4
        or     %l0,%l4,%l0
        andn   %l0, 0x20, %l0
        mov    %l0, %psr
        nop
        nop
        nop
  
        jmp    %l1
        rett   %l2
        nop
        nop	


	
	 
	                                     
