#define _TIMER_

#include "DSP2833x_Device.h"         // Headerfile Include File
#include "DSP2833x_Examples.h"       // Examples Include File
#include "Timer.h"

#define ABS(x) ((x>=0)? (x) : -(x))  //���밪�� ����

#include "DSP2833x_GlobalPrototypes.h"
//#include "FPU.h"
#include <math.h>



void Timer_Init(void)
{
    DINT;
    IER = 0x0000;               // Disable CPU interrupts and clear all CPU interrupt flags
    IFR = 0x0000;

    InitPieCtrl();              //Initialize the PIE control registers
    InitPieVectTable();         //Initialize the PIE vector table with pointers

    InitCpuTimers();
    //Timer ����  (CpuTimer0  , �ý���Ŭ��[MHz],  ���ͷ�Ʈ�ֱ�[usec])
    ConfigCpuTimer(&CpuTimer0, 150, 500); // 10000�̸� 10[ms]���� �ѹ��� ���ͷ�Ʈ ����, 50=50usec���� timer0 ����
    StartCpuTimer0();

    IER |= M_INT1;  // Disable CPU interrupts

    PieCtrlRegs.PIEIER1.bit.INTx7 = 1;   //INTx.7�� TIMER0�� �ִ� ��
 
    EINT;   // Enable Global interrupt INTM
    ERTM;   // Enable Global realtime interrupt DBGM
}



