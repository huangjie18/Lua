/**********************************************************
* @ File name -> usart.h
* @ Version   -> V1.0
* @ Date      -> 12-26-2013
* @ Brief     -> 系统串口设置相关的函数
**********************************************************/

#ifndef _usart_h_
#define _usart_h_

/**********************************************************
                     外部函数头文件                        
**********************************************************/

#include "stdio.h"	//printf函数头文件

#include "sys.h" 

/**********************************************************
                     定义相关应用项
**********************************************************/

#define USART_REC_LEN					63	//定义最大接收字节数
#define EN_USART1_RX					1	//串口接收使能。0：禁止接收
                                            //              1：允许接收

/**********************************************************
                     外部调用功能函数
**********************************************************/

#if EN_USART1_RX	//使能了串口接收

	extern uint8_t  USART_RX_BUF[USART_REC_LEN];	//接收缓冲，最大USART_REC_LEN个字节，末字节为换行符 
	extern uint16_t USART_RX_STA;					//接收状态标记

#endif

void USARTx_Init(uint32_t bound);	//初始化IO 串口1


#endif

