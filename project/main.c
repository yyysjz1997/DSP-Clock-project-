/*
 * main.c
 */
#include "DSP28x_Project.h"
#include "LCD.h"
#include "LED_TM1638.h"

interrupt void cpu_timer0_isr(void);    //timer0
// extern Uint16 RamfuncsLoadStart;
// extern Uint16 RamfuncsLoadEnd;
// extern Uint16 RamfuncsRunStart;

int hourH = 0,hourL=0,minH=0,minL=0,secH=0,secL=0;

void main(void) {
	
	InitSysCtrl();  	//��ʼ��ϵͳʱ�ӣ�ѡ���ڲ�����1��10MHZ��12��Ƶ��2��Ƶ����ʼ������ʱ�ӣ���������,4��Ƶ
	DINT; 				//�����ж�
	IER = 0x0000;  	 	//��CPU�ж�ʹ��
	IFR = 0x0000;   	//��CPU�жϱ�־
	InitPieCtrl();  	//��pie�ж�
	InitPieVectTable();	//���ж�������

	EALLOW;				/**�����ж�������*****/
	PieVectTable.TINT0 = &cpu_timer0_isr;
	EDIS;


	// MemCopy(&RamfuncsLoadStart, &RamfuncsLoadEnd, &RamfuncsRunStart);
	InitFlash();

	InitCpuTimers();   	// ��ʼ��ʱ��
	ConfigCpuTimer(&CpuTimer0, 60,1000000);
	CpuTimer0Regs.TCR.all = 0x4041;

    PieCtrlRegs.PIECTRL.bit.ENPIE = 1;      // Enable the PIE block
    PieCtrlRegs.PIEIER1.bit.INTx7 = 1;      // TINT0
    IER |= M_INT1;      /**ʹ��CPU�ж�**/

	TM1638_Init(); 		//��ʼ��LED
//	Lcd_Init();
	EINT;
	ERTM;
//	LCD_Clear(WHITE);
//	POINT_COLOR = BLACK;    			//���û���Ϊ��ɫ
//	LCD_ShowString(10,100,"now time is:");
	while(1){
		LED_Show(1,secL,0);
		LED_Show(2,secH,0);
		LED_Show(3,minL,1);
		LED_Show(4,minH,0);
		LED_Show(5,hourL,1);
		LED_Show(6,hourH,0);
//		LCD_ShowNum(40,120,hourH,1);
//		LCD_ShowNum(48,120,hourL,1);
//		LCD_ShowChar(56,120,':',0);
//		LCD_ShowNum(70,120,minH,1);
//		LCD_ShowNum(78,120,minL,1);
//		LCD_ShowChar(86,120,':',0);
//		LCD_ShowNum(100,120,secH,1);
//		LCD_ShowNum(108,120,secL,1);
	}
}

interrupt void cpu_timer0_isr(void) {
	if(secL==9){
		secL=0;
		secH++;
	}
	else secL++;
	if(secH==6){
		secH=0;
		minL++;
	}
	if(minL==10){
		minL=0;
		minH++;
	}
	if(minH==6){
		minH=0;
		hourL++;
	}
	if(hourL==4 && hourH==2){
		hourL=0;
		hourH=0;
	}
	else if(hourL==10){
		hourL=0;
		hourH++;
	}
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
}

