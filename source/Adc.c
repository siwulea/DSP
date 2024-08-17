//###########################################################################
//
// FILE:    DSP283x_Adc.c
//
// TITLE:   DSP283x ADC Initialization & Support Functions.
//
//###########################################################################

#define _ADC_

#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // Examples Include File
#include "DSP2833x_Adc.h"  
#include "DSP2833x_GlobalPrototypes.h"
#include <math.h>

/**********************************************************************
* Function: InitAdc()
*
* Description: Initializes the ADC on the F28335
**********************************************************************/


void InitAdc(void)
{

    // Reset the ADC module
    AdcRegs.ADCTRL1.bit.RESET = 1; // Reset the ADC module
    asm("\tRPT #16||NOP");         // Wait 12-cycles for ADC Reset to Avoid Incorrect Value


    /*** Must follow the proper ADC power-up sequence ***/
    AdcRegs.ADCTRL3.bit.rsvd1     = 0x0;    // 15:8
    AdcRegs.ADCTRL3.bit.ADCBGRFDN = 0x3;    // 7:6  first power-up ref and bandgap circuits
    AdcRegs.ADCTRL3.bit.ADCPWDN   = 0x0;    // 5    reference power, 1=power on
                                            //      bandgap power, 1=power on
    AdcRegs.ADCTRL3.bit.ADCCLKPS  = 8;      // 4:1  clock prescaler, ADCLK=HSPCLK/(2*ADCCLKPS)->9.375MHz(107 ns),HSPCLK=75MHz
    AdcRegs.ADCTRL3.bit.SMODE_SEL = 0x1;    // 0    0 = sequential sampling, 1 = simultaneous sampling
    /*
    bit 15-8      0's:    reserved
    bit 7         1:      ADCRFDN, reference power, 1=power on
    bit 6         1:      ADCBGDN, bandgap power, 1=power on
    bit 5         0:      ADCPWDN, main ADC power, 1=power on
    bit 4-1       0100:   ADCCLKPS, clock prescaler, ADCLK=HSPCLK/(2*ADCCLKPS) -> 9.375MHz(107 ns)
    bit 0         1:      SMODE_SEL, 0=sequential sampling, 1=simultaneous sampling
    */
    DELAY_US(7000);                             // Wait 7ms before setting ADCPWDN
    AdcRegs.ADCTRL3.bit.ADCPWDN = 1;            // Set ADCPWDN=1 to power main ADC
    DELAY_US(30);                               // Wait 20us before using the ADC

    // Configure the other ADC register
    AdcRegs.ADCMAXCONV.all = 0x07;                      // Amount of Conversion(8 Conversion) - ADC 16 채널 사용
    /*
    bit 15-7      0's:    reserved
    bit 6-4       000:    MAX_CONV2 value
    bit 3-0       0111:   MAX_CONV1 value (0111 means 8 conversion)
    */

    //ADC Conversion Sequence Setting (Conv00 -> Conv01 -> Conv02 -> ...)
    AdcRegs.ADCCHSELSEQ1.bit.CONV00 = 0x0;              //ADCINA0  -> ADCRESULT0
    AdcRegs.ADCCHSELSEQ1.bit.CONV01 = 0x1;              //ADCINA1  -> ADCRESULT1        or ADCRESULT2
    AdcRegs.ADCCHSELSEQ1.bit.CONV02 = 0x2;              //ADCINA2  -> ADCRESULT2
    AdcRegs.ADCCHSELSEQ1.bit.CONV03 = 0x3;              //ADCINA3  -> ADCRESULT3
    AdcRegs.ADCCHSELSEQ2.bit.CONV04 = 0x4;              //ADCINA4  -> ADCRESULT4
    AdcRegs.ADCCHSELSEQ2.bit.CONV05 = 0x5;              //ADCINA5  -> ADCRESULT5
    AdcRegs.ADCCHSELSEQ2.bit.CONV06 = 0x6;              //ADCINA6  -> ADCRESULT6        회로 구조 상 이용 못함
    AdcRegs.ADCCHSELSEQ2.bit.CONV07 = 0x7;              //ADCINA7  -> ADCRESULT7        회로 구조 상 이용 못함


    AdcRegs.ADCTRL1.bit.rsvd1    = 0x00;    // Reserved
    AdcRegs.ADCTRL1.bit.SEQ_CASC = 0x1;     // (0:Dual Sequencer Mode, 1:Cascaded Sequencer Mode)
    AdcRegs.ADCTRL1.bit.SEQ_OVRD = 0x00;    // (0:No Override, 1:Sequencer Override)
    AdcRegs.ADCTRL1.bit.CONT_RUN = 0;       // (0:Demonstrate ADC 1 time, 1:Continuous Run)
    AdcRegs.ADCTRL1.bit.CPS      = 1;       //1 ADC core clock pre-scalar(9.375MHz / 2) = 4.6875MHz
    AdcRegs.ADCTRL1.bit.ACQ_PS   = 8;       //8// 11:8  Acquisition window size(Sample and Hold Clock = 16)
    AdcRegs.ADCTRL1.bit.SUSMOD   = 0x02;    // 13:12 Emulation suspend mode(after Current Conversion)
    AdcRegs.ADCTRL1.bit.RESET    = 0x00;    // 14    ADC reset
    AdcRegs.ADCTRL1.bit.rsvd2    = 0x00;    // 15    reserved

    /*
    bit 15        0:      reserved
    bit 14        0:      RESET, 0=no action, 1=reset ADC
    bit 13-12     10:     SUSMOD, 10=stop after current conversion on emulator suspend
    bit 11-8      1111:   ACQ_PS (Acquisition), 0111 = 8 x Fclk
    bit 7         1:      CPS (Core clock), 0: Fclk=CLK/1, 1: Fclk=CLK/2
    bit 6         0:      CONT_RUN, 0=start/stop mode, 1=continuous run
    bit 5         0:      reserved
    bit 4         1:      SEQ_CASC, 0=dual sequencer, 1=cascaded sequencer
    bit 3-0       0000:   reserved
    */

    AdcRegs.ADCTRL2.all = 0x8900;
    // AdcRegs.ADCTRL2.all = 0x2000;
    /*
    AdcRegs.ADCTRL2.bit.EPWM_SOCB_SEQ=0x1;  // 15
    AdcRegs.ADCTRL2.bit.RST_SEQ1=0x0;       // 14
    AdcRegs.ADCTRL2.bit.SOC_SEQ1=0x0;       // 13
    AdcRegs.ADCTRL2.bit.rsvd4=0x0;          // 12
    AdcRegs.ADCTRL2.bit.INT_ENA_SEQ1=0x1;   // 11
    AdcRegs.ADCTRL2.bit.INT_MOD_SEQ1=0x0;   // 10
    AdcRegs.ADCTRL2.bit.rsvd3=0x0;          // 9
    AdcRegs.ADCTRL2.bit.EPWM_SOCA_SEQ1=0x1; // 8
    AdcRegs.ADCTRL2.bit.EXT_SOC_SEQ1=0x0;   // 7
    AdcRegs.ADCTRL2.bit.RST_SEQ2=0x0;       // 6
    AdcRegs.ADCTRL2.bit.SOC_SEQ2=0x0;       // 5
    AdcRegs.ADCTRL2.bit.rsvd2=0x0;          // 4
    AdcRegs.ADCTRL2.bit.INT_ENA_SEQ2=0x0;   // 3
    AdcRegs.ADCTRL2.bit.INT_MOD_SEQ2=0x0;   // 2
    AdcRegs.ADCTRL2.bit.rsvd1=0x0;          // 1
    AdcRegs.ADCTRL2.bit.EPWM_SOCB_SEQ2=0x0; // 0
    */
    /*
    bit 15        1:      EVB_SOC_SEQ, 0=no action
    bit 14        0:      RST_SEQ1, 0=no action
    bit 13        0:      SOC_SEQ1, 0=clear any pending SOCs
    bit 12        1:      reserved
    bit 11        1:      INT_ENA_SEQ1, 1=enable interrupt
    bit 10        0:      INT_MOD_SEQ1, 0=int on every other SEQ1 conv,1=int on every SEQ1 conv
    bit 9         1:      reserved
    bit 8         0:      EVA_SOC_SEQ1, 1=SEQ1 start from EVA
    bit 7         0:      EXT_SOC_SEQ1, 1=SEQ1 start from ADCSOC pin
    bit 6         0:      RST_SEQ2, 0=no action
    bit 5         0:      SOC_SEQ2, no effect in cascaded mode
    bit 4         0:      reserved
    bit 3         0:      INT_ENA_SEQ2, 0=int disabled
    bit 2         0:      INT_MOD_SEQ2, 0=int on every other SEQ2 conv
    bit 1         0:      reserved
    bit 0         0:      EVB_SOC_SEQ2, 1=SEQ2 started by EVB
    */

    AdcRegs.ADCTRL2.bit.EPWM_SOCA_SEQ1 = 1;
    AdcRegs.ADCTRL2.bit.RST_SEQ1 = 1;      // Reset SEQ1 to CONV00 state

    IER |= M_INT1;
    PieCtrlRegs.PIEIER1.bit.INTx6 = 1;
}



void CalibrateADC() //*ADC 보정값을 구하기 위한 함수
{
    yH += (long)((AdcRegs.ADCRESULT12>>4)&0x0FFF);      // ADCIN6 = 1.25[V]  1610  1.06
    yL += (long)((AdcRegs.ADCRESULT14>>4)&0x0FFF);      // ADCIN7 = 0.625[V] 805

    if(++CntSequenceTime >= NUM_CALOFFSET){
        yH /= NUM_CALOFFSET;
        yL /= NUM_CALOFFSET;

        CalGain = ((4095*0.625/3.0)/(yH-yL));               // CalGain   : IQ18//0.625

        CalOffset =(((yL)*CalGain) - (4095*0.625/3.0)); // CalOffset : IQ18

        CalGainError = abs(1 - CalGain);
        CalOffsetError = abs(CalOffset);


        Cal_Offset_Chk = 1;
        //*ADC 보정값을 구하는 첫번째 단계를 거쳤음을 알리는 변수값 1

        CntSequenceTime = 0;
    }
}

/*--------------------------------------*/
/*  call calculateADCOffset()           */
/*--------------------------------------*/
void CalculateADCOffset()   //*ADC 입력 시 DC 오프셋 값을 구하는 함수. 여기서 구한 DC 오프셋을 빼주면  AC값만 구할 수 있다.
{
//    A1OffsetSum += ((long)(AdcRegs.ADCRESULT0 >> 4) * CalGain) - CalOffset;


    A1OffsetSum += ((long)(AdcRegs.ADCRESULT2 >> 4) * CalGain) - CalOffset;
//    A2OffsetSum += ((long)(AdcRegs.ADCRESULT0 >> 4) * CalGain) - CalOffset;
    A3OffsetSum += ((long)(AdcRegs.ADCRESULT3 >> 4) * CalGain) - CalOffset;
    A4OffsetSum += ((long)(AdcRegs.ADCRESULT1 >> 4) * CalGain) - CalOffset;
    if( ++CntSequenceTime >= NUM_CALOFFSET)
    {
                A1OffsetSum /= NUM_CALOFFSET;
                A1OffsetCal =A1OffsetSum;

                A2OffsetSum /= NUM_CALOFFSET;
                A2OffsetCal =A2OffsetSum;

                A3OffsetSum /= NUM_CALOFFSET;
                A3OffsetCal =A3OffsetSum;

                A4OffsetSum /= NUM_CALOFFSET;
                A4OffsetCal =A4OffsetSum;
                Cal_Offset_Chk = 2;
    }
}

/*------------------------------------------*/
/*  call calculateADC()                     */
/*------------------------------------------*/
void CalculateADC()
{
    Ia_sensor = (((long)(AdcRegs.ADCRESULT2 >> 4)* 3.0 / 4096.0) - usrOffset) * usrGain;
}


/*------------------------------------------*/
/*  Generate Ia_ref Waveform generateIaRef() */
/*------------------------------------------*/
void GenerateIaRef()
{
	    // 전류 지령값 생성
	    if(count < Ref_time*20000)
	    {
	       Ia_ref = Ia_ref_amp;

	       count++;
	    }
//	    } else if (count >= Ia_ref_time*20000 && count < Ia_ref_time*40000)
//	    {
//	    	Ia_ref = 0;
//	        count++;
//	    }
//	     else if (count >= Ia_ref_time*40000 && count < Ia_ref_time*60000)
//	    {
//	    	Ia_ref = -Ia_ref_amp;
//	        count++;
//	    } else if (count >= Ia_ref_time*60000 && count < Ia_ref_time*80000)
//	    {
//	    	Ia_ref = 0;
//	        count++;
//	    } else
	       else
	    {
	        count = 0;
	        Gen_Ref_Chk = 0;
	    }
}

/*------------------------------------------*/
/*  Generate Wm_Ref Waveform generateWmRef() */
/*------------------------------------------*/
void GenerateWmRef()
{
        // 속도 지령값 생성
        if(count < Ref_time*20000)
        {
           Wm_ref = Wm_ref_amp;
           count++;
        }
//      } else if (count >= Ia_ref_time*20000 && count < Ia_ref_time*40000)
//      {
//          Ia_ref = 0;
//          count++;
//      }
//       else if (count >= Ia_ref_time*40000 && count < Ia_ref_time*60000)
//      {
//          Ia_ref = -Ia_ref_amp;
//          count++;
//      } else if (count >= Ia_ref_time*60000 && count < Ia_ref_time*80000)
//      {
//          Ia_ref = 0;
//          count++;
//      } else
           else
        {
            count = 0;
            Gen_Ref_Chk = 0;
        }
}


/*------------------------------------------*/
/*  Start Current Control  StartCurrentControl() */
/*------------------------------------------*/
void StartCurrentControl()
{
    // Calculate back EMF using Speed
    if(Ia_ref != 0.0)
    {
        if(V_emf > Vdc) V_emf =  Vdc;
        else if(V_emf < - Vdc) V_emf = -Vdc;
        else
        {
            Wm_esti += Kt*Ia_sensor*Ts/J;
            V_emf = Ke*Wm_esti/9.55;
        }
    }
    else
    {
        Wm_esti = 0.0;
        V_emf = 0.0;
    }

    // Operate Current Control
    Ia_err = Ia_ref - Ia_sensor;
    Ia_err_anti = Ia_err - Kac*Ia_anti;
    Ia_err_int += Kic*Ts*Ia_err_anti;
    V_ref_ff = Ia_err_int + Kpc*Ia_err;
//    V_ref_ff = V_ref_fb + V_emf;

    if (V_ref_ff > Vdc) V_ref = Vdc;
    else if (V_ref_ff < -Vdc) V_ref = -Vdc;
    else V_ref = V_ref_ff;

    Ia_anti = V_ref_ff - V_ref;

    Ia_sensor_old = Ia_sensor;
}

/*------------------------------------------*/
/*  Start Speed Control  StartSpeedControl() */
/*------------------------------------------*/
void StartSpeedControl()
{
    // Calculate back EMF using Speed
    if(Ia_ref != 0.0)
    {
        if(V_emf > Vdc) V_emf =  Vdc;
        else if(V_emf < - Vdc) V_emf = -Vdc;
        else
        {
            Wm_esti += Kt*Ia_sensor*Ts/J;
            V_emf = Ke*Wm_esti/9.55;
        }
    }
    else
    {
        Wm_esti = 0.0;
        V_emf = 0.0;
    }

    // Operate Speed Control
    Wm_err = Wm_ref - Wm_esti;
    Wm_err_anti = Wm_err - Kas * Wm_anti;
    Wm_err_int += Kis * Ts * Wm_err_anti;
    Ia_ref_fb = Wm_err_int + Kps * Wm_err;

    if (Ia_ref_fb > Ia_stall) Ia_ref = Ia_stall;
    else if (Ia_ref_fb < -Ia_stall) Ia_ref = -Ia_stall;
    else Ia_ref_fb = Ia_ref;

    Wm_anti = Ia_ref_fb - Ia_ref;

    // Operate Current Control
    Ia_err = Ia_ref - Ia_sensor;
    Ia_err_anti = Ia_err - Kac*Ia_anti;
    Ia_err_int += Kic*Ts*Ia_err_anti;
    V_ref_ff = Ia_err_int + Kpc*Ia_err;

    if (V_ref_ff > Vdc) V_ref = Vdc;
    else if (V_ref_ff < -Vdc) V_ref = -Vdc;
    else V_ref = V_ref_ff;

    Ia_anti = V_ref_ff - V_ref;

    Ia_sensor_old = Ia_sensor;
}
