#ifndef _MAX262_H_ 
#define _MAX262_H_  

#include "sys.h"

#define PI 3.141592653 

//PDL口(从高到低):Wr,空,D1,D0,A3,A2,A1,A0 
//#define setWr1      GPIO_SetBits(GPIOD,GPIO_Pin_2) 
//#define resetWr1    GPIO_ResetBits(GPIOD,GPIO_Pin_2) 

//#define setWr2      GPIO_SetBits(GPIOB,GPIO_Pin_3) 
//#define resetWr2    GPIO_ResetBits(GPIOB,GPIO_Pin_3) 

//#define setWr3      GPIO_SetBits(GPIOB,GPIO_Pin_4) 
//#define resetWr3    GPIO_ResetBits(GPIOB,GPIO_Pin_4) 

#define fclkk      PAout(1)
 
extern enum {modeOne=0,modeTwo,modeThree,modeFour} workMode;
extern enum {lowPass=0,highPass,bandPass,allPass,bandStop} passMode; 
extern enum {channelA=0,channelB,channelAB} channel;  
extern u8 channel_se;

/***************************************************************  
*IO口初始化
***************************************************************/
 void MAX262_Init(void);
/***************************************************************     
* 名称：write（） 
* 功能：写两比特的数据到某地址 
* 入口参数：A3到A0的地址add,D1和D0的2bit数据dat2bit 
* 出口参数：无 
* 说明：D1和D0取dat2bit的最低两位。 
***************************************************************/    
void write(u8 add,u8 dat2bit); 
/***************************************************************     
* 名称：setAf（） 
* 功能：设置A通道F值 
* 入口参数：A通道F值datF
* 出口参数：无 * 说明：无 
***************************************************************/ 
void setAf(u8 datF); 
  
/*************************************************************** 
* 名称：setAQ（）
* 功能：设置A通道Q值 
* 入口参数：A通道Q值datQ
* 出口参数：无 
* 说明：无 
***************************************************************/    
void setAQ(u8 datQ);   
/***************************************************************    
* 名称：setBf（） 
* 功能：设置B通道F值 
* 入口参数：B通道F值datF
* 出口参数：无 
* 说明：无 
***************************************************************/ 
void setBf(u8 datF);   
/***************************************************************
* 名称：setBQ（） 
* 功能：设置B通道Q值 
* 入口参数：B通道Q值datQ 
* 出口参数：无 
* 说明：无 
***************************************************************/     
void setBQ(u8 datQ); 
  
/***************************************************************     
* 名称：lh_Getf0（） 
* 功能：计算滤波器的中心频率f0 
* 入口参数：截止频率fc、品质因数Q和通过模式passMode 
* 出口参数：中心频率f0 
* 说明：仅适用于低通和高通。 
***************************************************************/ 
float lh_Getf0(float fc,float Q,u8 passMode); 
/***************************************************************     
* 名称：lhp_WorkFclk（） 
* 功能：设置低通和高通滤波器工作并取得时钟频率fclk 
* 入口参数：截止频率fc、品质因数Q、通过模式passMode、工作模式workMode和输出通道channel
* 出口参数：时钟频率fclk 
* 说明：需要将时钟给出之后才能正常工作；Q越大，频率曲线波动越大。
* 使用说明：模式二时Q值要大于0.707；仅适用于低通和高通。 
***************************************************************/ 
float lhp_WorkFclk(float fc,float Q,u8 passMode,u8 workMode,u8 channel);   
/***************************************************************     
* 名称：bp_WorkFclk（） 
* 功能：设置带通滤波器工作并取得时钟频率fclk 
* 入口参数：上限截止频率fh、下限截止频率fl、工作模式workMode和输出通道channel 
* 出口参数：时钟频率fclk 
* 说明：需要将时钟给出之后才能正常工作。 
* 使用说明：模式二时Q值要大于0.707；仅适用于带通。 
***************************************************************/ 
float bp_WorkFclk(float fh,float fl,u8 workMode,u8 channel); 
/***************************************************************     
* 名称：bs_WorkFclk（） 
* 功能：设置陷波滤波器工作并取得时钟频率fclk 
* 入口参数：陷波频率fn、品质因数Q、工作模式workMode和输出通道channel 
* 出口参数：时钟频率fclk 
* 说明：需要将时钟给出之后才能正常工作；Q越大，频率曲线波动越大；仅适用于陷波；模式二时Q值要大于0.707。 
* 使用说明：只有模式1才能正常陷波fn=f0;模式2只能陷下去fn=0.725f0。
***************************************************************/ 
float bs_WorkFclk(float f0,float Q,u8 workMode,u8 channel);   
/***************************************************************     
* 名称：ap_WorkFclk（） 
* 功能：设置全通滤波器工作并取得时钟频率fclk 
* 入口参数：中心频率f0、品质因数Q和输出通道channel 
* 出口参数：时钟频率fclk 
* 说明：需要将时钟给出之后才能正常工作；仅适用于全通。 
* 使用说明：Q值不能太大，否则f0附近有起伏。 
***************************************************************/
float ap_WorkFclk(float f0,float Q,u8 channel);



u8 FnFin_config(float f0,u8 workMode);


#endif



