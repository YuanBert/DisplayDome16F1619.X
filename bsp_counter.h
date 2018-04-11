/* 
 * File:   bsp_counter.h
 * Author: bertz
 *
 * Created on April 10, 2018, 4:46 PM
 */

#ifndef BSP_COUNTER_H
#define	BSP_COUNTER_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include "mcc_generated_files/mcc.h"
    
    
#define     SMALLBOXSIZE        140
#define     MIDDLEBOXSIZE       283
#define     LARGEBOXSIZE        424
//#define     ALARMBOXSIZE        2000
#define     JAMSIZE             500

    typedef struct{
        unsigned char TimeCntStartFlag;
        unsigned char TimeCntEndFlag;
        unsigned char AlarmFlag;
        unsigned char JamFlag;
        unsigned char DisplayReflashFlag;
        unsigned long SingleTimeCnt;
        unsigned int  SmallBoxCnt;
        unsigned int  MiddleBoxCnt;
        unsigned int  LargeBoxCnt;
        unsigned int  JamCnt;   //????
        unsigned long BoxSum;   //????
    }BoxCntStruct;

    
    void bsp_CounterInit(void);
    void bsp_RA2InterruptISRCallback(void);
    void bsp_TimerInterruptISRCallback(void);
    
#ifdef	__cplusplus
}
#endif

#endif	/* BSP_COUNTER_H */

