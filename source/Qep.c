#define _QEP_


#include "DSP2833x_Device.h"     // Headerfile Include File
#include "DSP2833x_Examples.h"   // Examples Include File
#include "Qep.h"

// Initialize eQEP1
void Init_eQEP1(void){//*EQep1�� �������͸� �����ϴ� �Լ�. 28335�� 2���� EQep ����� ������ �ִ�.

    //*EQep ���ڴ� ���� ��������*//
	// Setup eQEP1 Decoder Control 
	EQep1Regs.QDECCTL.bit.QSRC = 2;	// UP count mode for frequency measurement
	//*0: Quadrature count mode //QEPA(���ڴ� A���� ��ȣ)�� QEPB(���ڴ� A���� ��ȣ)�� ���ļ� 2bit�� ������ ����. QEPA�� QEPB�� high or low�� ���� 00 01 10 11�� �װ��� ���·� �з�.
	                            //������: 00 -> 10 -> 11 -> 01. �������� �� �� ���� ��ȭ���� QPOSCNT�� 1�� �����ϰ�, �������� ��� �� ���� ��ȭ���� QPOSCNT�� 1�� �����Ѵ�.(4ü��)
	//*1: Direction-count mode  //������ ȸ�����⿡ ���� QEPA �� position counter(QPOSCNT)�� ���� �Ǵ� ���ҽ�Ű�� ���. ������ ���� QEPA�� rising edge������ QPOSCNT�� ������Ű�ų�(1ü��), rising/falling edge ��� QPOSCNT�� ������ų �� �ִ�.(2ü��)
	//*2: UP count mode for frequency measurement  //������ ȸ������ ������� QEPA �� position-counter(QPOSCNT)�� 1�� ������Ű�� ���. ������ ���� QEPA�� rising edge������ QPOSCNT�� ������Ű�ų�(1ü��), rising/falling edge ��� QPOSCNT�� ������ų �� �ִ�.(2ü��)
	//*3: DOWN count mode for frequency measurement  //������ ȸ������ ������� QEPA �� position-counter(QPOSCNT)�� 1�� ���ҽ�Ű�� ���. ������ ���� QEPA�� rising edge������ QPOSCNT�� ������Ű�ų�(1ü��), rising/falling edge ��� QPOSCNT�� ������ų �� �ִ�.(2ü��)

	EQep1Regs.QDECCTL.bit.XCR = 1;
	//*QCLK�� ä�踦 �����ϴ� ��Ʈ. QCLK�� QPOSCNT(position-counter: ȸ�������� �����ϱ� ���� ���ڴ� ���� �޽��� ����ϴ� 32bit ��������), UPEVNT(Unit Position Event: QCTMR�� �ʱ�ȭ�ϴ� ��Ʈ)�ּ� �̿�ȴ�.
    //*0: 2x resolution: Count the rising/falling edge  //A, B������  rising/falling(4ä��) edge���� QCLK Ŭ�� �޽��� �߻��Ѵ�.
    //*1: 1x resolution: Count the rising edge only  //A, B������  rising(2ä��) edge���� QCLK Ŭ�� �޽��� �߻��Ѵ�.

	EQep1Regs.QDECCTL.bit.SOEN = 0;		// Disable position-compare sync output
	//*max count�� �����ؼ� � �̺�Ʈ�� �߻��ϵ��� �� ���ΰ� ����. �ʿ����
	//*0: Disable position-compare sync output
	//*1: Enable position-compare sync output



	//*unit timer�� �ֱ⸦ �����ϴ� 32bit ��������.*//
	// Setup eQEP1 Unit Timer Period(1ms)
	EQep1Regs.QUPRD = 300000; 			// SYSCLKOUT(=150MHz)/1000 = 1ms period
	//*unit timer�� ��ȭ �� ���� �������͵��� ���� ����� �������ͷ� �ű�� ���ͷ�Ʈ�� �߻���Ų��.
	//*unit timer period = QUPRD / SYSCLKOUT(150MHz)
	


	//*position counter�� �ʱ�ȭ�ϴ� ��������*// position counter�� ����ϴ� ���ڴ� ���� ���� �����ָ� ȸ�������� ������ �� �ִ�.
	// Setup eQEP1 Position Counter Initialization
	EQep1Regs.QPOSINIT = 0x00000000;
	//*32bit�� ���������� �Է��ؾ� �Ѵ�. 0x�� �տ� �ٴ� ���ڴ� 16�����̸� 16���������� �� ������ 2������ �� ������ ǥ���� �� �ִ�.
	


	//*position counter�� �ִ밪�� �ʱ�ȭ�ϴ� ��������.*//
	// Setup eQEP1 Maximum Position Counter
	EQep1Regs.QPOSMAX = 0xffffffff;
	//*32bit�� ���������� �Է��ؾ� �Ѵ�.

	

	//*EQep ���� ��������*//
	// Setup eQEP1 Control
	// Emulation Control Bits
	// position counter, watchdog counter, unit timer, capture timer is unaffected by emulation suspend 
	EQep1Regs.QEPCTL.bit.FREE_SOFT = 2;
	//*0: ���ķ����� ���� �� Position counter, Watchdog counter, Unit timer stops, Capture Timer ��� �ߴ��Ѵ�.
	//*1:
	//*2: ���ķ����� ������ ������� �ʴ´�.
	//*3: FREE_SOFT_2�� ����.
	
	EQep1Regs.QEPCTL.bit.PCRM = 1;	// Position counter reset on the index position
	//*0: Position counter reset on an index event
	//*1: Position counter reset on the maximum position
	//*2: Position counter reset on the first index event
	//*3: Position counter reset on a unit time event

	EQep1Regs.QEPCTL.bit.UTE = 1; 	// Enable unit timer
	//*0: eQEP unit timer ������� ����.
	//*1: unit timer ���.

	EQep1Regs.QEPCTL.bit.WDE = 0;	// Disable the eQEP2 watchdog timer
	//*0: eQEP watchdog timer ������� ����.
	//*1: watchdog timer ���.
	
	// Position counter, capture timer, capture period values is latched
	// into QPOSLAT, QCTMRLAT and QCPRDLAT register on unit time out  
	EQep1Regs.QEPCTL.bit.QCLM = 1;	// Latch on unit time out
	//*0: CPU�� [Position counter, capture timer, capture period values]�� ���� ���� �� ���� LAT ��������(���� �����ϴ� ��������)�� ����ȴ�.
	//*1: unit timer �ֱ⸶�� [Position counter(32bit), capture timer(16bit), capture period values(16bit)]�� ���� LAT ��������(���� �����ϴ� ��������)�� ����ȴ�.

	EQep1Regs.QEPCTL.bit.QPEN = 1; 	// Enable eQEP position counter
	//*0: eQEP peripheral ���� �۵� �÷��׿� �б� ���� �������͸� �缳��.
	//*1: eQEP Position counter ���.

    EQep1Regs.QEPCTL.bit.IEI = 10;
    //*0: �ƹ� �͵� ���� ����.
    //*1: �ƹ� �͵� ���� ����.
    //*2: ���ڴ� �ε��� �޽�(z�޽�)�� rising edge���� position counter �ʱ�ȭ. QEPI �޽�(Index Pulse)��  1ȸ�� �� 1���� �߻��ϴ� ȸ������ ���� ��ġ�� �����ϱ� ���� ��ȣ
    //*3: ���ڴ� �ε��� �޽�(z�޽�)�� falling edge���� position counter �ʱ�ȭ.


	
	//*EQep ��ġ �� ���� ��������*//
	// Setup eQEP2 Position-compare control
	EQep1Regs.QPOSCTL.bit.PCE = 0;	// Disable position compare unit
	//*0: eQEP position compare unit ������� ����.
	//*1: Position compare unit ���.
	


	//*EQep ĸ�� ���� ��������*//
	// Setup eQEP2 Capture Control
	EQep1Regs.QCAPCTL.bit.UPPS = 0;	// Unit position event prescaler(UPEVENT = QCLK/(2^1))
	//*Unit position event ���ֺ�. UPEVENT��  QCLK���� ���ֵȴ�.
	//*UPEVENT�� Capture Timer(QCTMR)�� �ʱ�ȭ��Ų��. QCTMR�� �ý��� Ŭ��(SYSCLKOUT)���� ���ֵ� ������ Ŭ��(CAPCLK)���� 1�� �������� Ÿ�̸��̴�. QCTMR ������ ���ڴ� �޽� �� �ֱ⸦ ������ �� �ִ�.
	//*4bit�� �Ҵ�� �������ͷ� 0 ~ 15���� �Է��� �� �ִ�. (UPEVENT = QCLK / 2^(UPPS))

	EQep1Regs.QCAPCTL.bit.CCPS = 4;	// eQEP2 capture timer clock prescaler(CAPCLK = SYSCLKOUT(=150MHz)/16)
	//*capture timer clock ���ֺ�. CAPCLK�� �ý��� Ŭ��(SYSCLKOUT)���� ���ֵȴ�.
	//*CAPCLK���� Capture Timer(QCTMR)�� 1�� �����Ѵ�.
	//*3bit�� �Ҵ�� �������ͷ� 0 ~ 7���� �Է��� �� �ִ�. (CAPCLK = QCLK / 2^(CCPS))

	EQep1Regs.QCAPCTL.bit.CEN = 1; 	// Enable eQEP2 capture unit
	//*0: eQEP capture unit ������� ����.
	//*1: capture unit ���.



	//*EQep ���ͷ�Ʈ ��� ��������*// EQep ���ͷ�Ʈ �߻� ������ �����ϴ� ��������
	// Setup eQEP2 Interrupt Enable
	EQep1Regs.QEINT.bit.UTO = 1;	// Unit time out interrupt enable
	//*0: eQEP unit timer �ֱ⸶�� ���ͷ�Ʈ ������� ����.
	//*1: unit timer �ֱ⸶�� ���ͷ�Ʈ ���.



   	// Setup GPIO and interrupt service routine for eQEP1
   	EALLOW;

   	//*GPIO B�׷� Ǯ�� ���� ��������*// �⺻�� 0�� �� GPIO�� Ǯ�� ����
 	GpioCtrlRegs.GPBPUD.bit.GPIO50 = 0;   // Enable pull-up on GPIO24 (EQEP1A)
    GpioCtrlRegs.GPBPUD.bit.GPIO51 = 0;   // Enable pull-up on GPIO25 (EQEP1B)
    GpioCtrlRegs.GPBPUD.bit.GPIO53 = 0;   // Enable pull-up on GPIO25 (EQEP1I)

    

    //*GPIO B�׷� �Է� �ڰ� ��������2*// GPIO �Է��� �ý��� Ŭ���� �� �踶�� ������ �����ϴ� ��������. �⺻�� 0�� �� �ý��� Ŭ������ GPIO �Է�
    GpioCtrlRegs.GPBQSEL2.bit.GPIO50 = 0; // Sync to SYSCLKOUT GPIO24 (EQEP1A)
    GpioCtrlRegs.GPBQSEL2.bit.GPIO51 = 0; // Sync to SYSCLKOUT GPIO25 (EQEP1B)
    GpioCtrlRegs.GPBQSEL2.bit.GPIO53 = 0; // Sync to SYSCLKOUT GPIO25 (EQEP1I)

    

    //*GPIO B�׷� ��Ƽ�÷��� ��������2*// �ش� GPIO�� EQEP1�� �ֺ����� ���
    GpioCtrlRegs.GPBMUX2.bit.GPIO50 = 1;  // Configure GPIO24 as EQEP1A
    GpioCtrlRegs.GPBMUX2.bit.GPIO51 = 1;  // Configure GPIO25 as EQEP1B
    GpioCtrlRegs.GPBMUX2.bit.GPIO53 = 1;  // Configure GPIO25 as EQEP1I



    PieVectTable.EQEP1_INT = &EQEP1_INT_ISR;  // for eQEP1 interrupt
	//EQEP1_INT_ISR
    //*�Լ� EQEP1_INT_ISR�� �ּҰ��� PieVectTable.EQEP1_INT�� �����Ͽ�, EQEP1 ���ͷ�Ʈ �߻� ��  EQEP1_INT_ISR()�� ����ǵ��� �Ѵ�.

	EDIS;

    // Enable CPU INT5 for eQEP2
	IER |= M_INT5;
	//*EQEP1 ���ͷ�Ʈ�� ���� CPU ���ͷ�Ʈ 5�� ����� �� �ְ���.

    // Enable eQEP1 INT in the PIE: Group 5 interrupt 1
	PieCtrlRegs.PIEIER5.bit.INTx1 = 1;
	//*EQEP1 ���ͷ�Ʈ�� ���� �ֺ���� ���ͷ�Ʈ 1�� ����� �� �ְ���.
}


// Initialize eQEP2
void Init_eQEP2(void){
	// Setup eQEP2 Decoder Control 
	EQep2Regs.QDECCTL.bit.QSRC = 2;		// Direction count mode
	EQep2Regs.QDECCTL.bit.XCR = 1;
	EQep2Regs.QDECCTL.bit.SOEN = 0;		// Disable position-compare sync output
	
	// Setup eQEP2 Unit Timer Period(1ms)
	EQep2Regs.QUPRD = 150000; 			// SYSCLKOUT(=150MHz)/1000 = 1ms period
	
	// Setup eQEP2 Position Counter Initialization
	EQep2Regs.QPOSINIT = 0x00000000;
	
	// Setup eQEP2 Maximum Position Counter
	EQep2Regs.QPOSMAX = 0xffffffff;
	
	// Setup eQEP2 Control
	// Emulation Control Bits
	// position counter, watchdog counter, unit timer, capture timer is unaffected by emulation suspend 
	EQep2Regs.QEPCTL.bit.FREE_SOFT = 2;
	
	// 00 : position counter is reset on an index event
	// 01 :                  is reset on the maximum position
	// 10 :                  is reset on the first index event
	// 11 :                  is reset on a unit timer event 
	EQep2Regs.QEPCTL.bit.PCRM = 0;	// Position counter reset on the index position
	EQep2Regs.QEPCTL.bit.UTE = 1; 	// Enable unit timer
	EQep2Regs.QEPCTL.bit.WDE = 0;	// Disable the eQEP2 watchdog timer
	
	// Position counter, capture timer, capture period values is latched
	// into QPOSLAT, QCTMRLAT and QCPRDLAT register on unit time out  
	EQep2Regs.QEPCTL.bit.QCLM = 1;	// Latch on unit time out
	EQep2Regs.QEPCTL.bit.QPEN = 1; 	// Enable eQEP position counter
	
	// Setup eQEP2 Position-compare control
	EQep2Regs.QPOSCTL.bit.PCE = 0;	// Disable position compare unit
	
	// Setup eQEP2 Capture Control
	EQep2Regs.QCAPCTL.bit.UPPS = 0;	// Unit position event prescaler(UPEVENT = QCLK/(2^1))
	EQep2Regs.QCAPCTL.bit.CCPS = 4;	// eQEP2 capture timer clock prescaler(CAPCLK = SYSCLKOUT(=150MHz)/16)
	EQep2Regs.QCAPCTL.bit.CEN = 1; 	// Enable eQEP2 capture unit
	
	// Setup eQEP2 Interrupt Enable
	EQep2Regs.QEINT.bit.UTO = 1;	// Unit time out interrupt enable

	EQep2Regs.QEPCTL.bit.IEI = 10;
   	
   	// Setup GPIO and interrupt service routine for eQEP2
   	EALLOW;
 	GpioCtrlRegs.GPAPUD.bit.GPIO24 = 0;   // Enable pull-up on GPIO24 (EQEP2A)
    GpioCtrlRegs.GPAPUD.bit.GPIO25 = 0;   // Enable pull-up on GPIO25 (EQEP2B)
    GpioCtrlRegs.GPAPUD.bit.GPIO26 = 0;    // Enable pull-up on GPIO26 (EQEP2I)
    
    GpioCtrlRegs.GPAQSEL2.bit.GPIO24 = 0; // Sync to SYSCLKOUT GPIO24 (EQEP2A)
    GpioCtrlRegs.GPAQSEL2.bit.GPIO25 = 0; // Sync to SYSCLKOUT GPIO25 (EQEP2B)
    GpioCtrlRegs.GPAQSEL2.bit.GPIO26 = 0; // Sync to SYSCLKOUT GPIO25 (EQEP2I)
        
    GpioCtrlRegs.GPAMUX2.bit.GPIO24 = 2;  // Configure GPIO24 as EQEP2A
    GpioCtrlRegs.GPAMUX2.bit.GPIO25 = 2;  // Configure GPIO25 as EQEP2B
    GpioCtrlRegs.GPAMUX2.bit.GPIO26 = 2;  // Configure GPIO25 as EQEP2I

    PieVectTable.EQEP2_INT = &EQEP2_INT_ISR;  // for eQEP2 interrupt
	//EQEP2_INT_ISR
	EDIS;

    // Enable CPU INT5 for eQEP2
	IER |= M_INT5;

    // Enable eQEP2 INT in the PIE: Group 5 interrupt 2
	PieCtrlRegs.PIEIER5.bit.INTx2 = 1;
}
