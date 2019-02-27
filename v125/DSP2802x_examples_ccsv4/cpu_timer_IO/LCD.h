#ifndef __LCD_H
#define __LCD_H

#include "DSP28x_Project.h"

#define	LCD_CS_SET()  	(GpioDataRegs.GPASET.bit.GPIO19 = 1)
#define	LCD_DC_SET()  	(GpioDataRegs.GPASET.bit.GPIO29 = 1)
#define	LCD_SDA_SET()  	(GpioDataRegs.AIOSET.bit.AIO6 = 1)
#define	LCD_SCL_SET()  	(GpioDataRegs.GPASET.bit.GPIO18 = 1)
#define	LCD_RST_SET()  	(GpioDataRegs.GPBSET.bit.GPIO34 = 1)

#define	LCD_CS_CLR()  	(GpioDataRegs.GPACLEAR.bit.GPIO19 = 1)
#define	LCD_DC_CLR()  	(GpioDataRegs.GPACLEAR.bit.GPIO29 = 1)
#define	LCD_SDA_CLR()  	(GpioDataRegs.AIOCLEAR.bit.AIO6 = 1)
#define	LCD_SCL_CLR()  	(GpioDataRegs.GPACLEAR.bit.GPIO18 = 1)
#define	LCD_RST_CLR()  	(GpioDataRegs.GPBCLEAR.bit.GPIO34 = 1)

//����LCD�ĳߴ�
#define LCD_W 240
#define LCD_H 320
extern Uint16 BACK_COLOR, POINT_COLOR;

//������ɫ
#define WHITE         	 0xFFFF
#define BLACK         	 0x0000	  
#define BLUE         	 0x001F  
#define BRED             0XF81F
#define GRED 			 0XFFE0
#define GBLUE			 0X07FF
#define RED           	 0xF800
#define MAGENTA       	 0xF81F
#define GREEN         	 0x07E0
#define CYAN          	 0x7FFF
#define YELLOW        	 0xFFE0
#define BROWN 			 0XBC40 //��ɫ
#define BRRED 			 0XFC07 //�غ�ɫ
#define GRAY  			 0X8430 //��ɫ
//GUI��ɫ
#define DARKBLUE      	 0X01CF	//����ɫ
#define LIGHTBLUE      	 0X7D7C	//ǳ��ɫ  
#define GRAYBLUE       	 0X5458 //����ɫ
//������ɫΪPANEL����ɫ 
#define LIGHTGREEN     	 0X841F //ǳ��ɫ
#define LGRAY 			 0XC618 //ǳ��ɫ(PANNEL),���屳��ɫ
#define LGRAYBLUE        0XA651 //ǳ����ɫ(�м����ɫ)
#define LBBLUE           0X2B12 //ǳ����ɫ(ѡ����Ŀ�ķ�ɫ)
void InitLCDGpio(void);
void Lcd_Init(void);
void LCD_Clear(Uint16 Color);
void LCD_Fill(Uint16 xsta, Uint16 ysta, Uint16 xend, Uint16 yend, Uint16 color);
void Address_set(Uint8 x1, Uint8 y1, Uint8 x2, Uint8 y2);
void LCD_ShowChar(Uint16 x, Uint16 y, Uint8 num, Uint8 mode); //��ʾһ���ַ�
void LCD_ShowNum(Uint16 x, Uint16 y, Uint32 num, Uint8 len); //��ʾ����
void LCD_Show2Num(Uint16 x, Uint16 y, Uint16 num, Uint8 len); //��ʾ2������
void LCD_ShowString(Uint16 x, Uint16 y, char *p);		 //��ʾһ���ַ���,16����

void LCD_DrawPoint(Uint16 x, Uint16 y);		 //����
void LCD_DrawPoint_big(Uint16 x, Uint16 y);		 //��һ�����
void LCD_DrawLine(Uint16 x1, Uint16 y1, Uint16 x2, Uint16 y2);
void LCD_DrawRectangle(Uint16 x1, Uint16 y1, Uint16 x2, Uint16 y2);
void Draw_Circle(Uint16 x0, Uint16 y0, Uint8 r);
void showimage(Uint8 *p);
void showimage2(Uint8 *p, Uint8 x, Uint8 y, Uint8 width, Uint8 height);
Uint32 mypow(Uint8 m, Uint8 n);
Uint16 LCD_ReadPoint(Uint16 x, Uint16 y); //����
#endif  

