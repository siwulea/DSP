// TI File $Revision: /main/11 $
// Checkin $Date: May 12, 2008   14:30:08 $
//###########################################################################
//
// FILE:   DSP2833x_GlobalPrototypes.h
//
// TITLE:  Global prototypes for DSP2833x Examples
//
//###########################################################################
// $TI Release: DSP2833x/DSP2823x Header Files V1.20 $
// $Release Date: August 1, 2008 $
//###########################################################################

#ifndef DSP2833x_GLOBALPROTOTYPES_H
#define DSP2833x_GLOBALPROTOTYPES_H
#define LED_ON GpioDataRegs.GPACLEAR.bit.GPIO30 = 1; 
#define LED_OFF GpioDataRegs.GPASET.bit.GPIO30 = 1;
#define LED_TOGGLE GpioDataRegs.GPATOGGLE.bit.GPIO30 = 1;
#define GATINGON EPwm1Regs.TZCLR.bit.OST = TZ_ENABLE; \
                EPwm2Regs.TZCLR.bit.OST = TZ_ENABLE; \
                EPwm3Regs.TZCLR.bit.OST = TZ_ENABLE;
#define GATINGOFF EPwm1Regs.TZFRC.bit.OST = TZ_ENABLE; \
                EPwm2Regs.TZFRC.bit.OST = TZ_ENABLE; \
                EPwm3Regs.TZFRC.bit.OST = TZ_ENABLE;




#ifdef __cplusplus
extern "C" {
#endif

/*---- shared global function prototypes -----------------------------------*/
extern Uint32 Vin_MSB;
extern float Vin_volt;
extern float Vin_volt_old;
extern float Vin_APF;
extern float Wc;
extern float Gain;
extern float Offset;

//DC motor control project
//Ia_ref
extern void Ia_ref_generator(void);
extern void Ia_Control(void);
extern int Ia_ref_counter;
extern int Ia_ref_up_width;
extern int Ia_ref_zero_width;
extern int Ia_ref_down_width;
extern int Ia_ref_mode;
extern float Ia_ref_value;
extern float Ia_ref_up_height;
extern float Ia_ref_down_height;
extern float Wcs3;

//Ia controller
extern float Ia_sensored;
extern float Vdc_sensored;
extern float Ia_error;
extern float CurrentControl_out_p;
extern float CurrentControl_out_i;
extern float CurrentControl_out_a;
extern float CurrentControl_out_Vavg;
extern float CurrentControl_out_Vavg_saturation;
extern float CurrentControl_out_duty;
extern float CurrentControl_Duty_Max;
//Ia controller parameters
extern float CurrentControl_Ki;
extern float CurrentControl_Kp;
extern float CurrentControl_Ka;
extern float T_switching;

//Default setting
extern void InitAdc(void);
extern void sorting(void);
extern void InitParameter(void);
extern void DQs_Trans(void);
extern void SpeedControl(void);
extern void Speed_estimation(void);
extern void Flux_estimate(void);
extern void Flux_Control(void);
extern void Current_Control(void);
extern void VF_Control(void);
extern void PulseWidthModulation(void);
extern void OverModulation(void);
extern void SoCtoOCVCaculate(void);
extern void easyDSP_SCI_Init(void);
extern void CalculateADC(void);
extern void CalculateADCOffset(void);
extern void CalculateADCScale(void);
extern void GenerateIaRef(void);
extern void GenerateWmRef(void);
extern void StartCurrentControl(void);
extern void StartSpeedControl(void);
extern void CalibrateADC(void);
extern void Init_Code(void);
extern void Init_eQEP1(void);
extern void Init_eQEP2(void);
extern void InitEPWM(void);
extern void OutputDAC(void);
extern void OverModulation(void);
extern void DMAInitialize(void);
// DMA Channel 1
extern void DMACH1AddrConfig(volatile Uint16 *DMA_Dest,volatile Uint16 *DMA_Source);
extern void DMACH1BurstConfig(Uint16 bsize, int16 srcbstep, int16 desbstep);
extern void DMACH1TransferConfig(Uint16 tsize, int16 srctstep, int16 deststep);
extern void DMACH1WrapConfig(Uint16 srcwsize, int16 srcwstep, Uint16 deswsize, int16 deswstep);
extern void DMACH1ModeConfig(Uint16 persel, Uint16 perinte, Uint16 oneshot, Uint16 cont, Uint16 synce, Uint16 syncsel, Uint16 ovrinte, Uint16 datasize, Uint16 chintmode, Uint16 chinte);
extern void StartDMACH1(void);
// DMA Channel 2
extern void DMACH2AddrConfig(volatile Uint16 *DMA_Dest,volatile Uint16 *DMA_Source);
extern void DMACH2BurstConfig(Uint16 bsize, int16 srcbstep, int16 desbstep);
extern void DMACH2TransferConfig(Uint16 tsize, int16 srctstep, int16 deststep);
extern void DMACH2WrapConfig(Uint16 srcwsize, int16 srcwstep, Uint16 deswsize, int16 deswstep);
extern void DMACH2ModeConfig(Uint16 persel, Uint16 perinte, Uint16 oneshot, Uint16 cont, Uint16 synce, Uint16 syncsel, Uint16 ovrinte, Uint16 datasize, Uint16 chintmode, Uint16 chinte);
extern void StartDMACH2(void);
// DMA Channel 3
extern void DMACH3AddrConfig(volatile Uint16 *DMA_Dest,volatile Uint16 *DMA_Source);
extern void DMACH3BurstConfig(Uint16 bsize, int16 srcbstep, int16 desbstep);
extern void DMACH3TransferConfig(Uint16 tsize, int16 srctstep, int16 deststep);
extern void DMACH3WrapConfig(Uint16 srcwsize, int16 srcwstep, Uint16 deswsize, int16 deswstep);
extern void DMACH3ModeConfig(Uint16 persel, Uint16 perinte, Uint16 oneshot, Uint16 cont, Uint16 synce, Uint16 syncsel, Uint16 ovrinte, Uint16 datasize, Uint16 chintmode, Uint16 chinte);
extern void StartDMACH3(void);
// DMA Channel 4
extern void DMACH4AddrConfig(volatile Uint16 *DMA_Dest,volatile Uint16 *DMA_Source);
extern void DMACH4BurstConfig(Uint16 bsize, int16 srcbstep, int16 desbstep);
extern void DMACH4TransferConfig(Uint16 tsize, int16 srctstep, int16 deststep);
extern void DMACH4WrapConfig(Uint16 srcwsize, int16 srcwstep, Uint16 deswsize, int16 deswstep);
extern void DMACH4ModeConfig(Uint16 persel, Uint16 perinte, Uint16 oneshot, Uint16 cont, Uint16 synce, Uint16 syncsel, Uint16 ovrinte, Uint16 datasize, Uint16 chintmode, Uint16 chinte);
extern void StartDMACH4(void);
// DMA Channel 5
extern void DMACH5AddrConfig(volatile Uint16 *DMA_Dest,volatile Uint16 *DMA_Source);
extern void DMACH5BurstConfig(Uint16 bsize, int16 srcbstep, int16 desbstep);
extern void DMACH5TransferConfig(Uint16 tsize, int16 srctstep, int16 deststep);
extern void DMACH5WrapConfig(Uint16 srcwsize, int16 srcwstep, Uint16 deswsize, int16 deswstep);
extern void DMACH5ModeConfig(Uint16 persel, Uint16 perinte, Uint16 oneshot, Uint16 cont, Uint16 synce, Uint16 syncsel, Uint16 ovrinte, Uint16 datasize, Uint16 chintmode, Uint16 chinte);
extern void StartDMACH5(void);
// DMA Channel 6
extern void DMACH6AddrConfig(volatile Uint16 *DMA_Dest,volatile Uint16 *DMA_Source);
extern void DMACH6BurstConfig(Uint16 bsize,Uint16 srcbstep, int16 desbstep);
extern void DMACH6TransferConfig(Uint16 tsize, int16 srctstep, int16 deststep);
extern void DMACH6WrapConfig(Uint16 srcwsize, int16 srcwstep, Uint16 deswsize, int16 deswstep);
extern void DMACH6ModeConfig(Uint16 persel, Uint16 perinte, Uint16 oneshot, Uint16 cont, Uint16 synce, Uint16 syncsel, Uint16 ovrinte, Uint16 datasize, Uint16 chintmode, Uint16 chinte);
extern void StartDMACH6(void);

extern void InitPeripherals(void);
#if DSP28_ECANA
extern void InitECan(void);
extern void InitECana(void);
extern void InitECanGpio(void);
extern void InitECanaGpio(void);
#endif // endif DSP28_ECANA
#if DSP28_ECANB
extern void InitECanb(void);
extern void InitECanbGpio(void);
#endif // endif DSP28_ECANB
extern void InitECap(void);
extern void InitECapGpio(void);
extern void InitECap1Gpio(void);
extern void InitECap2Gpio(void);
#if DSP28_ECAP3
extern void InitECap3Gpio(void);
#endif // endif DSP28_ECAP3
#if DSP28_ECAP4
extern void InitECap4Gpio(void);
#endif // endif DSP28_ECAP4
#if DSP28_ECAP5
extern void InitECap5Gpio(void);
#endif // endif DSP28_ECAP5
#if DSP28_ECAP6
extern void InitECap6Gpio(void);
#endif // endif DSP28_ECAP6
extern void InitEPwm(void);
extern void InitEPwmGpio(void);
extern void InitEPwm1Gpio(void);
extern void InitEPwm2Gpio(void);
extern void InitEPwm3Gpio(void);
#if DSP28_EPWM4
extern void InitEPwm4Gpio(void);
#endif // endif DSP28_EPWM4
#if DSP28_EPWM5
extern void InitEPwm5Gpio(void);
#endif // endif DSP28_EPWM5
#if DSP28_EPWM6
extern void InitEPwm6Gpio(void);
#endif // endif DSP28_EPWM6
#if DSP28_EQEP1
extern void InitEQep(void);
extern void InitEQepGpio(void);
extern void InitEQep1Gpio(void);
#endif // if DSP28_EQEP1
#if DSP28_EQEP2
extern void InitEQep2Gpio(void);
#endif // endif DSP28_EQEP2
extern void InitGpio(void);
extern void InitI2CGpio(void);

extern void InitMcbsp(void);
extern void InitMcbspa(void);
extern void delay_loop(void);
extern void InitMcbspaGpio(void);
extern void InitMcbspa8bit(void);
extern void InitMcbspa12bit(void);
extern void InitMcbspa16bit(void);
extern void InitMcbspa20bit(void);
extern void InitMcbspa24bit(void);
extern void InitMcbspa32bit(void);
#if DSP28_MCBSPB
extern void InitMcbspb(void);
extern void InitMcbspbGpio(void);
extern void InitMcbspb8bit(void);
extern void InitMcbspb12bit(void);
extern void InitMcbspb16bit(void);
extern void InitMcbspb20bit(void);
extern void InitMcbspb24bit(void);
extern void InitMcbspb32bit(void);
#endif // endif DSP28_MCBSPB

extern void InitPieCtrl(void);
extern void InitPieVectTable(void);

extern void InitSci(void);
extern void InitSciGpio(void);
extern void InitSciaGpio(void);
#if DSP28_SCIB
extern void InitScibGpio(void);
#endif // endif DSP28_SCIB
#if DSP28_SCIC
extern void InitScicGpio(void);
#endif
extern void InitSpi(void);
extern void InitSpiGpio(void);
extern void InitSpiaGpio(void);
extern void InitSysCtrl(void);
extern void InitTzGpio(void);
extern void InitXIntrupt(void);
extern void XintfInit(void);
extern void InitXintf16Gpio();
extern void InitXintf32Gpio();
extern void InitPll(Uint16 pllcr, Uint16 clkindiv);
extern void InitPeripheralClocks(void);
extern void EnableInterrupts(void);
extern void DSP28x_usDelay(Uint32 Count);
extern void ADC_cal (void);
#define KickDog ServiceDog     // For compatiblity with previous versions
extern void ServiceDog(void);
extern void DisableDog(void);
extern Uint16 CsmUnlock(void);

// DSP28_DBGIER.asm
extern void SetDBGIER(Uint16 dbgier);

//                 CAUTION
// This function MUST be executed out of RAM. Executing it
// out of OTP/Flash will yield unpredictable results
extern void InitFlash(void);

extern void InitWindcase(void);
extern void WindPattern(void);
extern void TorqueSimulation(void);
extern void TorqueRefVolt(void);


void MemCopy(Uint16 *SourceAddr, Uint16* SourceEndAddr, Uint16* DestAddr);


//---------------------------------------------------------------------------
// External symbols created by the linker cmd file
// DSP28 examples will use these to relocate code from one LOAD location
// in either Flash or XINTF to a different RUN location in internal
// RAM
extern Uint16 RamfuncsLoadStart;
extern Uint16 RamfuncsLoadEnd;
extern Uint16 RamfuncsRunStart;

extern Uint16 XintffuncsLoadStart;
extern Uint16 XintffuncsLoadEnd;
extern Uint16 XintffuncsRunStart;


/* For SC & VC Call */
#define     SC_CALL         10
#define     VC_CALL         10


// System Mode
#define CALIBRATION     0               // Calculate CalGain, CalOffset
#define CALOFFSET       1               // Calculate Sensing Offset value
#define CHECKeCAN       2               // Cell to main communication check
#define CHECKVCS        3               // Check main VCS status
#define PRECHARGE       4               // Perform DC-Link precharging
#define READY           5               // Wait for main command
#define NORMAL          6               // Normal operating status
#define FAULT           9               // System fault

#define OPEN            0
#define CLOSE           1

#define NUM_CALOFFSET   10000
#define PI 3.14159265
#define SQRT2 1.414213562
#define INV_SQRT2 0.70710678
#define INV_SQRT3 0.57735026
#define SQRT3 1.7320508

#define ABS(x) ((x>=0)? (x) : -(x))  //절대값의 정의

#define Mode_LV GpioDataRegs.GPBCLEAR.bit.GPIO32 = 1;
#define Mode_GC GpioDataRegs.GPBSET.bit.GPIO32 = 1;


//#define OFF_DBR GpioDataRegs.GPBCLEAR.bit.GPIO48 = 1;
//#define ON_DBR GpioDataRegs.GPBSET.bit.GPIO48 = 1;
#define ON_MC1 GpioDataRegs.GPBCLEAR.bit.GPIO48 = 1;
#define OFF_MC1 GpioDataRegs.GPBSET.bit.GPIO48 = 1;
#define ON_MC2 GpioDataRegs.GPBCLEAR.bit.GPIO49 = 1;
#define OFF_MC2 GpioDataRegs.GPBSET.bit.GPIO49 = 1;


#define ON_DBR GpioDataRegs.GPBCLEAR.bit.GPIO49 = 1;
#define OFF_DBR GpioDataRegs.GPBSET.bit.GPIO49 = 1;

#define CNTT1PERIOD 9375

typedef struct {
    float scale[16];
    int   offset[16];
    float tmp[16];
    int conv_val[16];
}   ADC;


    extern float Ia;
    extern float usrGain;
    extern float usrOffset;
    extern float count;
    extern float fsw;
    extern float wcc;
    extern float Wm_esti;
    extern float Ra;
    extern float La;
    extern float Ia_ref;
    extern float Ia_err_anti;
    extern float Ia_err_int;
    extern float Ia_sensor;
    extern float V;
    extern float V_ref;
    extern float V_ref_fb;
    extern float V_ref_ff;
    extern float Ia_err;
    extern float Ts;
    extern float Ia_err_sum;
    extern float Ia_lim;
    extern float Ia_out;
    extern float Ia_anti;
    extern float P_cl;
    extern float I_cl;
    extern float Kpc;
    extern float Wcc;
    extern float Kic;
    extern float Kac;
    extern float J;
    extern float duty;
    extern float duty_ref;
    extern float Ia_ref_amp;
    extern float Vdc;
    extern int Gen_Ref_Chk;
    extern float Ref_time;

    extern float V_emf;
    extern float Ke;
    extern float Kt;

    extern float count_emf;
    extern float Ia_sensor_old;

    extern int Str_Controller_Chk;


    // Speed Control
    extern float Wm_err;
    extern float Wm_ref;
    extern float Wm_err_anti;
    extern float Wm_err_int;
    extern float Wm_ref_amp;
    extern float Wm_anti;

    extern float Wcs;
    extern float Kas;
    extern float Kps;
    extern float Kis;

    extern float Ia_ref_fb;
    extern float Ia_stall;

    extern float V_emf_v;
    extern float Wm_esti_v;

    /*------------------------------*/
    /*  Protection Variables        */
    /*------------------------------*/

/* ADC Calibration */
    extern float yH;
    extern float yL;
    extern float CalGain;
    extern float CalOffset;
    extern float CalGainError;
    extern float CalOffsetError;
    extern long Cal_Offset_Chk;

/* ADC Offset Calculate */
    extern float A1OffsetSum;
    extern float A2OffsetSum;
    extern float A3OffsetSum;
    extern float A4OffsetSum;

    extern float A1OffsetCal;
    extern float A2OffsetCal;
    extern float A3OffsetCal;
    extern float A4OffsetCal;

/* Limit value */
    extern long CntSequenceTime;

/* easy_dsp */
    extern void *data_ptr[99];

    extern int DA_Code_ch0;
    extern int DA_Code_ch1;
    extern int DA_Code_ch2;
    extern int DA_Code_ch3;

    extern float DA_Data_ch0;
    extern float DA_Data_ch1;
    extern float DA_Data_ch2;
    extern float DA_Data_ch3;

    extern float DA_ScaleIn_ch0;
    extern float DA_ScaleIn_ch1;
    extern float DA_ScaleIn_ch2;
    extern float DA_ScaleIn_ch3;

    extern float DA_Offset_ch0;
    extern float DA_Offset_ch1;
    extern float DA_Offset_ch2;
    extern float DA_Offset_ch3;

    extern float DA_Scale_ch0;
    extern float DA_Scale_ch1;
    extern float DA_Scale_ch2;
    extern float DA_Scale_ch3;

    extern float DA_Scale[4];

    extern int  dac_data0, dac_data1, dac_data2, dac_data3;
    extern float fdummy;

/* ePWM Setting */
    extern Uint32 CMP1;
    extern Uint32 CMP2;
    extern Uint32 CMP3;


#ifdef __cplusplus
}
#endif /* extern "C" */

#endif   // - end of DSP2833x_GLOBALPROTOTYPES_H

//===========================================================================
// End of file.
//===========================================================================
