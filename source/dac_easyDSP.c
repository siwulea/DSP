#define _DAC_

#include "DSP2833x_Device.h"     // Headerfile Include File
#include "DSP2833x_Examples.h"   // Examples Include File
#include "dac_easyDSP.h"

//ADC adc;

void Init_Code()
{
    register int ri=0;

/*  for(;ri<256;ri++)
    {
        data_ptr[ri] = cfft.CurrentOutPtr[ri];
    }*/

    data_ptr[ri++] = &duty_ref;         // 0 100개의 DA변수 생성
    data_ptr[ri++] = &Ia_sensor;        // 1 TEST버젼에서는 TEST1부터 TEST6까
    data_ptr[ri++] = &Ia_ref;           // 2
    data_ptr[ri++] = &V_emf;            // 3
    data_ptr[ri++] = &V_ref;           // 4
    data_ptr[ri++] = &Wm_ref;           // 5
    data_ptr[ri++] = &Wm_esti;           // 6
    data_ptr[ri++] = &V_emf_v;           // 7
    data_ptr[ri++] = &Wm_esti_v;           // 8
    data_ptr[ri++] = &fdummy;           // 9

    data_ptr[ri++] = &fdummy;           // 10
    data_ptr[ri++] = &fdummy;           // 11
    data_ptr[ri++] = &fdummy;           // 12
    data_ptr[ri++] = &fdummy;           // 13
    data_ptr[ri++] = &fdummy;           // 14
    data_ptr[ri++] = &fdummy;           // 15
    data_ptr[ri++] = &fdummy;           // 16
    data_ptr[ri++] = &fdummy;           // 17
    data_ptr[ri++] = &fdummy;           // 18
    data_ptr[ri++] = &fdummy;           // 19

    data_ptr[ri++] = &fdummy;           // 20
    data_ptr[ri++] = &fdummy;           // 21
    data_ptr[ri++] = &fdummy;           // 22
    data_ptr[ri++] = &fdummy;           // 23 Vqse_ref
    data_ptr[ri++] = &fdummy;           // 24
    data_ptr[ri++] = &fdummy;           // 25
    data_ptr[ri++] = &fdummy;           // 26
    data_ptr[ri++] = &fdummy;           // 27
    data_ptr[ri++] = &fdummy;           // 28
    data_ptr[ri++] = &fdummy;           // 29 Vqss_ref

    data_ptr[ri++] = &fdummy;           // 30
    data_ptr[ri++] = &fdummy;           // 31
    data_ptr[ri++] = &fdummy;           // 32
    data_ptr[ri++] = &fdummy;           // 33
    data_ptr[ri++] = &fdummy;           // 34
    data_ptr[ri++] = &fdummy;           // 35
    data_ptr[ri++] = &fdummy;           // 36
    data_ptr[ri++] = &fdummy;           // 37
    data_ptr[ri++] = &fdummy;           // 38
    data_ptr[ri++] = &fdummy;           // 39

    data_ptr[ri++] = &fdummy;           // 40
    data_ptr[ri++] = &fdummy;           // 41
    data_ptr[ri++] = &fdummy;           // 42
    data_ptr[ri++] = &fdummy;           // 43
    data_ptr[ri++] = &fdummy;           // 44
    data_ptr[ri++] = &fdummy;           // 45
    data_ptr[ri++] = &fdummy;           // 46
    data_ptr[ri++] = &fdummy;           // 47
    data_ptr[ri++] = &fdummy;           // 48
    data_ptr[ri++] = &fdummy;           // 49

    data_ptr[ri++] = &fdummy;           // 50
    data_ptr[ri++] = &fdummy;           // 51
    data_ptr[ri++] = &fdummy;           // 52
    data_ptr[ri++] = &fdummy;           // 53
    data_ptr[ri++] = &fdummy;           // 54
    data_ptr[ri++] = &fdummy;           // 55
    data_ptr[ri++] = &fdummy;           // 56
    data_ptr[ri++] = &fdummy;           // 57
    data_ptr[ri++] = &fdummy;           // 58
    data_ptr[ri++] = &fdummy;           // 59

    data_ptr[ri++] = &fdummy;           // 60
    data_ptr[ri++] = &fdummy;           // 61
    data_ptr[ri++] = &fdummy;           // 62
    data_ptr[ri++] = &fdummy;           // 63
    data_ptr[ri++] = &fdummy;           // 64
    data_ptr[ri++] = &fdummy;           // 65
    data_ptr[ri++] = &fdummy;           // 66
    data_ptr[ri++] = &fdummy;           // 67
    data_ptr[ri++] = &fdummy;           // 68
    data_ptr[ri++] = &fdummy;           // 69

    data_ptr[ri++] = &fdummy;           // 70
    data_ptr[ri++] = &fdummy;           // 71
    data_ptr[ri++] = &fdummy;           // 72
    data_ptr[ri++] = &fdummy;           // 73
    data_ptr[ri++] = &fdummy;           // 74
    data_ptr[ri++] = &fdummy;           // 75
    data_ptr[ri++] = &fdummy;           // 76
    data_ptr[ri++] = &fdummy;           // 77
    data_ptr[ri++] = &fdummy;           // 78

    /**************************************************/
    /*            Full Order Observer Param.           */
    /**************************************************/
    data_ptr[ri++] = &fdummy;           // 79
    data_ptr[ri++] = &fdummy;           // 80
    data_ptr[ri++] = &fdummy;           // 81
    data_ptr[ri++] = &fdummy;           // 82
    data_ptr[ri++] = &fdummy;           // 83 &fdummy 빈자리에 sin1값 넣어줌
    data_ptr[ri++] = &fdummy;           // 84 &fdummy 빈자리에 sin2값 넣어줌
    data_ptr[ri++] = &fdummy;           // 85 &fdummy 빈자리에 sin3값 넣어줌
    data_ptr[ri++] = &fdummy;           // 86
    data_ptr[ri++] = &fdummy;           // 87      DC Motor Control Project
    data_ptr[ri++] = &fdummy;           // 88
    data_ptr[ri++] = &fdummy;           // 89

    data_ptr[ri++] = &fdummy;           // 90
    data_ptr[ri++] = &fdummy;           // 91
    data_ptr[ri++] = &fdummy;           // 92
    data_ptr[ri++] = &fdummy;           // 93
    data_ptr[ri++] = &fdummy;           // 94
    data_ptr[ri++] = &fdummy;           // 95
    data_ptr[ri++] = &fdummy;           // 96
    data_ptr[ri++] = &fdummy;           // 97
    data_ptr[ri++] = &fdummy;           // 98
    data_ptr[ri++] = &fdummy;           // 99
}

void Set_DA_Code(int ch0,int ch1, int ch2, int ch3) //AD에서 값을 받아온 값이 DA에서 처리되기 위해 들어가는 변수
{
    DA_Code_ch0 = ch0;
    DA_Code_ch1 = ch1;
    DA_Code_ch2 = ch2;
    DA_Code_ch3 = ch3;
}

void Set_DA_Offset(float ch0, float ch1, float ch2, float ch3) //좌표축 OFFSET
{
    DA_Offset_ch0 = ch0;
    DA_Offset_ch1 = ch1;
    DA_Offset_ch2 = ch2;
    DA_Offset_ch3 = ch3;
}

void Set_DA_Scale(float ch0, float ch1, float ch2, float ch3)
{
    DA_Scale_ch0 = ch0;
    DA_Scale_ch1 = ch1;
    DA_Scale_ch2 = ch2;
    DA_Scale_ch3 = ch3;
}

void dac_setup()
{
    EALLOW;

    GpioCtrlRegs.GPAMUX2.bit.GPIO30 = 0;  //LED ON_OFF
    GpioCtrlRegs.GPADIR.bit.GPIO30 = 1;
    // Initialize GPIO for SPI-A according to DAC7617U
    GpioCtrlRegs.GPBPUD.bit.GPIO54 = 0;   // Enable pull-up on GPIO54 (SPISIMOA)
    GpioCtrlRegs.GPBPUD.bit.GPIO56 = 0;   // Enable pull-up on GPIO56 (SPICLKA)
    GpioCtrlRegs.GPBPUD.bit.GPIO57 = 0;   // Enable pull-up on GPIO57 (SPISTEA)

    /* Set qualification for selected pins to asynch only */

    GpioCtrlRegs.GPBQSEL2.bit.GPIO54 = 3; // Asynch input GPIO54 (SPISIMOA) //일정 CLK이내는 NOISE
    GpioCtrlRegs.GPBQSEL2.bit.GPIO56 = 3; // Asynch input GPIO56 (SPICLKA)  //3은 Asynch 사용 안함
    GpioCtrlRegs.GPBQSEL2.bit.GPIO57 = 3; // Asynch input GPIO57 (SPISTEA)

    /* Configure SPI-A pins using GPIO regs*/


    GpioCtrlRegs.GPBMUX2.bit.GPIO54 = 1;  // Configure GPIO54 as SPISIMOA
    GpioCtrlRegs.GPBMUX2.bit.GPIO56 = 1;  // Configure GPIO56 as SPICLKA
    GpioCtrlRegs.GPBMUX2.bit.GPIO57 = 1;  // Configure GPIO57 as SPISTEA

    /* Configure /LDAC (MCP AD5327BRUZ)*/

    GpioCtrlRegs.GPBMUX2.bit.GPIO55 = 0;  // Configure GPIO55 as GPIO(/LDAC)
    GpioCtrlRegs.GPBDIR.bit.GPIO55 = 1;   // Output Mode
    GpioDataRegs.GPBSET.bit.GPIO55 = 1;

    EDIS;

    // Disable the FIFO operation
    SpiaRegs.SPIFFTX.all = 0xA000; // FIFO가 계속 이루어지도록 설정 (Re-enable Transmit)
    SpiaRegs.SPIFFRX.all = 0x2000; // (Re-enable Receive)
    SpiaRegs.SPIFFCT.all = 0x0;    // FIFO Trans. delay 결정

    SpiaRegs.SPICCR.all =0x000F;    // Reset on, rising edge, 16-bit char bits
    SpiaRegs.SPICTL.all =0x000E;    // Enable master mode, one half-cycle delay phase,
                                    // Enable TALK, and SPI int disabled. DA의 인터럽트 가능

    // SPI clock speed가 20MHz(DAC소자가 지원하는 최대속도)가 넘지 않도록 설정함
    SpiaRegs.SPIBRR =0x0000;        // Maximum SPI speed(LSPCLK/4 = 150MHz/16 = 9.375MHz)
    SpiaRegs.SPICCR.all =0x008F;    // Relinquish SPI from Reset
    SpiaRegs.SPIPRI.bit.FREE = 1;   // Set so breakpoints don't disturb xmission
}

void OutputDAC()
{

    DA_Data_ch0 = *(float*)data_ptr[DA_Code_ch0];  // AD에서 넘어온 값(0<Code<3)이 형변환 되어 Data변수에 저장
    DA_Data_ch1 = *(float*)data_ptr[DA_Code_ch1];
    DA_Data_ch2 = *(float*)data_ptr[DA_Code_ch2];
    DA_Data_ch3 = *(float*)data_ptr[DA_Code_ch3];

/*
    2048 * Data / Scale  AD로부터(Code) 넘어온 Data값이 2048이 곱함으로 -2048~2048사이의
    비트로 표현되고, 여기에 Scale을 곱함으로 오실로 스코프상에 보기원하는 전체 값으로 표현
    */

    dac_data0 = (int)((DA_Data_ch0 - DA_Offset_ch0) * 2048 / DA_Scale_ch0) + 0x800;  //(-)를 없애고 0부터 시작
    SpiaRegs.SPITXBUF = 0x0000 | (dac_data0 & 0x0fff);                               //버퍼에 데이터 저장
    while(!SpiaRegs.SPISTS.bit.INT_FLAG);                                            //12bit 신호가 다 들어오는 것을 보장
    dac_temp = SpiaRegs.SPIRXBUF;                                                    //버퍼에 있는 값을 temp에 저장

    dac_data1 = (int)((DA_Data_ch1 - DA_Offset_ch1) * 2048 / DA_Scale_ch1) + 0x800;
    SpiaRegs.SPITXBUF = 0x4000|(dac_data1 & 0x0fff);
    while(!SpiaRegs.SPISTS.bit.INT_FLAG);
    dac_temp = SpiaRegs.SPIRXBUF;

    dac_data2 = (int)((DA_Data_ch2 - DA_Offset_ch2) * 2048 / DA_Scale_ch2) + 0x800;
    SpiaRegs.SPITXBUF = 0x8000|(dac_data2 & 0x0fff);
    while(!SpiaRegs.SPISTS.bit.INT_FLAG);
    dac_temp = SpiaRegs.SPIRXBUF;

    dac_data3 = (int)((DA_Data_ch3 - DA_Offset_ch3) * 2048 / DA_Scale_ch3) + 0x800;
    SpiaRegs.SPITXBUF = 0xc000|(dac_data3 & 0x0fff);
    while(!SpiaRegs.SPISTS.bit.INT_FLAG);
    dac_temp = SpiaRegs.SPIRXBUF;
}


