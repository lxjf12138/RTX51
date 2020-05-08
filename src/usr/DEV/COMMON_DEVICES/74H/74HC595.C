/************************************************************
* ��֯���ƣ�
* �ļ�����: K:\��Ƭ�����\���Ӵ���������\HARDWARE\DEVICES\COMMON_DEVICES\74H\74HC595.C
* ����:     
* �汾:    
* ����:     2017/07/10
* ����: 595����������
* ��ʷ�޸ļ�¼:
* <����> <ʱ��> <�汾 > <����>
* 
***********************************************************/

#include "74HC595.H"
#include "../../../BSP/GPIO.h"
//��δ���
void HC595_Init(pin1,pin2)
{
	GPIO_InitTypeDef HC595_Pin;
	HC595_Pin.Mode = GPIO_PullUp;
	HC595_Pin.Pin = pin1;
	GPIO_Inilize(GPIO_P0,&HC595_Pin);
}
//��δ���
void HC595SendData(unsigned char SendVal)
{
	unsigned char i;
	for (i = 0; i < 8; i++)
	{
		if ((SendVal << i) & 0x80)
		{	
			MOSIO_HIGH;
		}
		else
		{
			MOSIO_LOW;
		}	
		S_CLK_LOW;
		NOP2();
		S_CLK_HIGH;
	}
	R_CLK_LOW;
	NOP2();
	R_CLK_HIGH;
}