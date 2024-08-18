// TI File $Revision: /main/2 $
// Checkin $Date: March 5, 2007   12:20:33 $
//###########################################################################
//
// FILE:    DSP2833x_GlobalVariableDefs.c
//
// TITLE:   DSP2833x Global Variables and Data Section Pragmas.
//
//###########################################################################
// $TI Release: DSP2833x Header Files V1.00 $
// $Release Date: September 7, 2007 $
//###########################################################################

#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Device.h" 
#include "DSP2833x_GlobalPrototypes.h" 


//---------------------------------------------------------------------------
// Define Global Peripheral Variables:
//
//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("AdcRegsFile")
#else
#pragma DATA_SECTION(AdcRegs,"AdcRegsFile");
#endif
volatile struct ADC_REGS AdcRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("AdcMirrorFile")
#else
#pragma DATA_SECTION(AdcMirror,"AdcMirrorFile");
#endif
volatile struct ADC_RESULT_MIRROR_REGS AdcMirror;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("CpuTimer0RegsFile")
#else
#pragma DATA_SECTION(CpuTimer0Regs,"CpuTimer0RegsFile");
#endif
volatile struct CPUTIMER_REGS CpuTimer0Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("CpuTimer1RegsFile")
#else
#pragma DATA_SECTION(CpuTimer1Regs,"CpuTimer1RegsFile");
#endif
volatile struct CPUTIMER_REGS CpuTimer1Regs;


//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("CpuTimer2RegsFile")
#else
#pragma DATA_SECTION(CpuTimer2Regs,"CpuTimer2RegsFile");
#endif
volatile struct CPUTIMER_REGS CpuTimer2Regs;


//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("CsmPwlFile")
#else
#pragma DATA_SECTION(CsmPwl,"CsmPwlFile");
#endif
volatile struct CSM_PWL CsmPwl;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("CsmRegsFile")
#else
#pragma DATA_SECTION(CsmRegs,"CsmRegsFile");
#endif
volatile struct CSM_REGS CsmRegs;



//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("DevEmuRegsFile")
#else
#pragma DATA_SECTION(DevEmuRegs,"DevEmuRegsFile");
#endif
volatile struct DEV_EMU_REGS DevEmuRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("DmaRegsFile")
#else
#pragma DATA_SECTION(DmaRegs,"DmaRegsFile");
#endif
volatile struct DMA_REGS DmaRegs;


//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("ECanaRegsFile")
#else
#pragma DATA_SECTION(ECanaRegs,"ECanaRegsFile");
#endif
volatile struct ECAN_REGS ECanaRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("ECanaMboxesFile")
#else
#pragma DATA_SECTION(ECanaMboxes,"ECanaMboxesFile");
#endif
volatile struct ECAN_MBOXES ECanaMboxes;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("ECanaLAMRegsFile")
#else
#pragma DATA_SECTION(ECanaLAMRegs,"ECanaLAMRegsFile");
#endif
volatile struct LAM_REGS ECanaLAMRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("ECanaMOTSRegsFile")
#else
#pragma DATA_SECTION(ECanaMOTSRegs,"ECanaMOTSRegsFile");
#endif
volatile struct MOTS_REGS ECanaMOTSRegs;


//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("ECanaMOTORegsFile")
#else
#pragma DATA_SECTION(ECanaMOTORegs,"ECanaMOTORegsFile");
#endif
volatile struct MOTO_REGS ECanaMOTORegs;


//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("ECanbRegsFile")
#else
#pragma DATA_SECTION(ECanbRegs,"ECanbRegsFile");
#endif
volatile struct ECAN_REGS ECanbRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("ECanbMboxesFile")
#else
#pragma DATA_SECTION(ECanbMboxes,"ECanbMboxesFile");
#endif
volatile struct ECAN_MBOXES ECanbMboxes;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("ECanbLAMRegsFile")
#else
#pragma DATA_SECTION(ECanbLAMRegs,"ECanbLAMRegsFile");
#endif
volatile struct LAM_REGS ECanbLAMRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("ECanbMOTSRegsFile")
#else
#pragma DATA_SECTION(ECanbMOTSRegs,"ECanbMOTSRegsFile");
#endif
volatile struct MOTS_REGS ECanbMOTSRegs;


//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("ECanbMOTORegsFile")
#else
#pragma DATA_SECTION(ECanbMOTORegs,"ECanbMOTORegsFile");
#endif
volatile struct MOTO_REGS ECanbMOTORegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EPwm1RegsFile")
#else
#pragma DATA_SECTION(EPwm1Regs,"EPwm1RegsFile");
#endif
volatile struct EPWM_REGS EPwm1Regs;


//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EPwm2RegsFile")
#else
#pragma DATA_SECTION(EPwm2Regs,"EPwm2RegsFile");
#endif
volatile struct EPWM_REGS EPwm2Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EPwm3RegsFile")
#else
#pragma DATA_SECTION(EPwm3Regs,"EPwm3RegsFile");
#endif
volatile struct EPWM_REGS EPwm3Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EPwm4RegsFile")
#else
#pragma DATA_SECTION(EPwm4Regs,"EPwm4RegsFile");
#endif
volatile struct EPWM_REGS EPwm4Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EPwm5RegsFile")
#else
#pragma DATA_SECTION(EPwm5Regs,"EPwm5RegsFile");
#endif
volatile struct EPWM_REGS EPwm5Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EPwm6RegsFile")
#else
#pragma DATA_SECTION(EPwm6Regs,"EPwm6RegsFile");
#endif
volatile struct EPWM_REGS EPwm6Regs;


//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("ECap1RegsFile")
#else
#pragma DATA_SECTION(ECap1Regs,"ECap1RegsFile");
#endif
volatile struct ECAP_REGS ECap1Regs;


//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("ECap2RegsFile")
#else
#pragma DATA_SECTION(ECap2Regs,"ECap2RegsFile");
#endif
volatile struct ECAP_REGS ECap2Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("ECap3RegsFile")
#else
#pragma DATA_SECTION(ECap3Regs,"ECap3RegsFile");
#endif
volatile struct ECAP_REGS ECap3Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("ECap4RegsFile")
#else
#pragma DATA_SECTION(ECap4Regs,"ECap4RegsFile");
#endif
volatile struct ECAP_REGS ECap4Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("ECap5RegsFile")
#else
#pragma DATA_SECTION(ECap5Regs,"ECap5RegsFile");
#endif
volatile struct ECAP_REGS ECap5Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("ECap6RegsFile")
#else
#pragma DATA_SECTION(ECap6Regs,"ECap6RegsFile");
#endif
volatile struct ECAP_REGS ECap6Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EQep1RegsFile")
#else
#pragma DATA_SECTION(EQep1Regs,"EQep1RegsFile");
#endif
volatile struct EQEP_REGS EQep1Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EQep2RegsFile")
#else
#pragma DATA_SECTION(EQep2Regs,"EQep2RegsFile");
#endif
volatile struct EQEP_REGS EQep2Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("GpioCtrlRegsFile")
#else
#pragma DATA_SECTION(GpioCtrlRegs,"GpioCtrlRegsFile");
#endif
volatile struct GPIO_CTRL_REGS GpioCtrlRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("GpioDataRegsFile")
#else
#pragma DATA_SECTION(GpioDataRegs,"GpioDataRegsFile");
#endif
volatile struct GPIO_DATA_REGS GpioDataRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("GpioIntRegsFile")
#else
#pragma DATA_SECTION(GpioIntRegs,"GpioIntRegsFile");
#endif
volatile struct GPIO_INT_REGS GpioIntRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("I2caRegsFile")
#else
#pragma DATA_SECTION(I2caRegs,"I2caRegsFile");
#endif
volatile struct I2C_REGS I2caRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("McbspaRegsFile")
#else
#pragma DATA_SECTION(McbspaRegs,"McbspaRegsFile");
#endif
volatile struct MCBSP_REGS McbspaRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("McbspbRegsFile")
#else
#pragma DATA_SECTION(McbspbRegs,"McbspbRegsFile");
#endif
volatile struct MCBSP_REGS McbspbRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("PieCtrlRegsFile")
#else
#pragma DATA_SECTION(PieCtrlRegs,"PieCtrlRegsFile");
#endif
volatile struct PIE_CTRL_REGS PieCtrlRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("PieVectTableFile")
#else
#pragma DATA_SECTION(PieVectTable,"PieVectTableFile");
#endif
struct PIE_VECT_TABLE PieVectTable;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("SciaRegsFile")
#else
#pragma DATA_SECTION(SciaRegs,"SciaRegsFile");
#endif
volatile struct SCI_REGS SciaRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("ScibRegsFile")
#else
#pragma DATA_SECTION(ScibRegs,"ScibRegsFile");
#endif
volatile struct SCI_REGS ScibRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("ScicRegsFile")
#else
#pragma DATA_SECTION(ScicRegs,"ScicRegsFile");
#endif
volatile struct SCI_REGS ScicRegs;


//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("SpiaRegsFile")
#else
#pragma DATA_SECTION(SpiaRegs,"SpiaRegsFile");
#endif
volatile struct SPI_REGS SpiaRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("SysCtrlRegsFile")
#else
#pragma DATA_SECTION(SysCtrlRegs,"SysCtrlRegsFile");
#endif
volatile struct SYS_CTRL_REGS SysCtrlRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("FlashRegsFile")
#else
#pragma DATA_SECTION(FlashRegs,"FlashRegsFile");
#endif
volatile struct FLASH_REGS FlashRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("XIntruptRegsFile")
#else
#pragma DATA_SECTION(XIntruptRegs,"XIntruptRegsFile");
#endif
volatile struct XINTRUPT_REGS XIntruptRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("XintfRegsFile")
#else
#pragma DATA_SECTION(XintfRegs,"XintfRegsFile");
#endif


volatile struct XINTF_REGS XintfRegs;

    float Ia = 0.;
    float usrOffset = 1.52; // 1.507
    float usrGain = 6.3; // 6.3
    float fsw = 0.0;
    float Ra = 0.0;
    float La = 0.0;
    float Wcc = 0.0;
    float Wm_esti= 0.0;
    float count = 0.;
    float Ia_ref = 0.;
    float Ia_ref_amp = 0.;
    float Ia_err_anti = 0.;
    float Ia_sensor = 0.;
    float V = 0.;
    float V_ref = 0.;
    float V_ref_fb = 0.;
    float V_ref_ff = 0.;
    float Vdc = 0.;
    float Ts = 0.0001;
    float Ia_err_int = 0.;
    float Ia_err = 0.;
    float Ia_err_sum = 0.;
    float Ia_out = 0.;
    float Ia_lim = 0.;
    float Ia_anti = 0.;
    float P_cl = 0.;
    float I_cl = 0.;
    float J = 0.0;
    float Kpc = 0.0;
    float Kic = 0.0;
    float Kac = 0.0;
    float duty = 3750.0;
    float duty_ref = 0.;

    int Gen_Ref_Chk = 0;
    float Ref_time = 0.;

    float V_emf = 0.0;
    float Kt = 0.0;
    float Ke = 0.0;

    float count_emf = 0.0;
    float Ia_sensor_old = 0.0;

    int Str_Controller_Chk = 0.0;

    // Speed Control
    float Wm_err = 0.0;
    float Wm_ref = 0.0;
    float Wm_err_anti = 0.0;
    float Wm_err_int = 0.0;
    float Wm_ref_amp = 0.0;
    float Wm_anti = 0.0;

    float Wcs = 0.0;
    float Kas = 0.0;
    float Kps = 0.0;
    float Kis = 0.0;

    float Ia_ref_fb = 0.0;
    float Ia_stall = 0.0;

    float V_emf_v = 0.0;
    float Wm_esti_v = 0.0;

/*------------------------------*/
/*  Protection Variables        */
/*------------------------------*/

/* ADC Calibration*/
    float yH = 0.;
    float yL = 0.;
    float CalGain = 0.;
    float CalOffset = 0.;
    float CalGainError = 0.;
    float CalOffsetError = 0.;
    long Cal_Offset_Chk = 0;

/* ADC Offset Calculate */

    float A1OffsetSum=0.;
    float A2OffsetSum=0.;
    float A3OffsetSum=0.;
    float A4OffsetSum=0.;

    float A1OffsetCal=0.;
    float A2OffsetCal=0.;
    float A3OffsetCal=0.;
    float A4OffsetCal=0.;

    long CntSequenceTime = 0;


/* easy_dsp */
    void *data_ptr[99];

    int DA_Code_ch0 = 0;
    int DA_Code_ch1 = 0;
    int DA_Code_ch2 = 0;
    int DA_Code_ch3 = 0;

    float DA_Data_ch0 = 0;
    float DA_Data_ch1 = 0;
    float DA_Data_ch2 = 0;
    float DA_Data_ch3 = 0;

    float DA_ScaleIn_ch0 = 0;
    float DA_ScaleIn_ch1 = 0;
    float DA_ScaleIn_ch2 = 0;
    float DA_ScaleIn_ch3 = 0;

    float DA_Offset_ch0 = 0;
    float DA_Offset_ch1 = 0;
    float DA_Offset_ch2 = 0;
    float DA_Offset_ch3 = 0;

    float DA_Scale_ch0 = 0;
    float DA_Scale_ch1 = 0;
    float DA_Scale_ch2 = 0;
    float DA_Scale_ch3 = 0;

    float DA_Mid_ch0 = 0;
    float DA_Mid_ch1 = 0;
    float DA_Mid_ch2 = 0;
    float DA_Mid_ch3 = 0;

    float DA_Scale[4];

    int  dac_data0 = 0, dac_data1 = 0, dac_data2 = 0, dac_data3 = 0;
    float fdummy = 0.;


/* ePWM Setting */
    Uint32 CMP1 = 375; //450//Init Vaiue//375
    Uint32 CMP2 = 375;
    Uint32 CMP3 = 375;

//===========================================================================
// End of file.
//===========================================================================
