#include "DSP2833x_Device.h"     // Headerfile Include File
#include "DSP2833x_Examples.h"   // Examples Include File
#include "float.h"
#include "math.h"
#include "dac_easyDSP.h"
#include "Timer.h"
#include "Qep.h"
#include "DSP2833x_Adc.h"
#include "DSP2833x_GlobalPrototypes.h"


void main(void)
{
    DINT;
    InitPieCtrl();
    IER = 0x0000;
    IFR = 0x0000;
    InitPieVectTable();
    EINT; // Enable Global interrupt INTM
    ERTM; // Enable Global realtime interrupt DBGM

    InitSysCtrl();
    dac_setup();

    InitEPwm1Gpio();
    InitEPwm2Gpio();
    InitEPwm3Gpio();
    InitEPwm4Gpio();
    InitEPwm5Gpio();
    InitEPwm6Gpio();
    InitTzGpio();

    InitECanGpio();

    Timer_Init(); //Timer(CPU clock, ���ͷ�Ʈ) �ʱ�ȭ
    InitAdc(); //ADC Register �ʱ�ȭ
    Init_Code(); //easy_DSP���� Code

    easyDSP_SCI_Init(); //easy_DSP�� SCI���� Code

    InitEPWM();
    InitGpio();

    Init_eQEP1();
    Init_eQEP2();

    InitECan();

    InitParameter();
    EnableInterrupts();

    Mode_GC;


    Set_DA_Offset(0.,0.,0.,0.); // ��ǥ���� OFFSET
    Set_DA_Scale(10.,10.,10.,10.); // ���Ƿν������󿡼� ������ϴ� Scale

    while(1)
    {

    }

}

