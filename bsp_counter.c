#include "bsp_counter.h"

extern BoxCntStruct gBoxCntStruct;
extern volatile unsigned char gEnterFlag;
extern volatile unsigned char gExitFlag;
void bsp_CounterInit(void)
{
    gBoxCntStruct.AlarmFlag = 0;
    gBoxCntStruct.JamFlag = 0;
    gBoxCntStruct.LargeBoxCnt = 0;
    gBoxCntStruct.MiddleBoxCnt = 0;
    gBoxCntStruct.SmallBoxCnt = 0;
    gBoxCntStruct.SingleTimeCnt = 0;
    gBoxCntStruct.TimeCntEndFlag = 0;
    gBoxCntStruct.TimeCntStartFlag = 0;
    gBoxCntStruct.DisplayReflashFlag = 0;
}
void bsp_RA2InterruptISRCallback(void)
{
    if(gEnterFlag && 0 == gExitFlag)
    {
        gBoxCntStruct.TimeCntStartFlag = 1;
        gBoxCntStruct.TimeCntEndFlag = 0;
        gEnterFlag = 0;
        gExitFlag = 0;
    }
    if(0 == gEnterFlag && 1 == gExitFlag )
    {
        gBoxCntStruct.TimeCntStartFlag = 0;
        gBoxCntStruct.TimeCntEndFlag = 1;
        gEnterFlag = 0;
        gExitFlag = 0;
    }
}

void bsp_TimerInterruptISRCallback(void)
{
    if(0 == gBoxCntStruct.TimeCntStartFlag && 0 == gBoxCntStruct.TimeCntEndFlag)
    {
        return;
    }
    
    if(1 == gBoxCntStruct.TimeCntStartFlag)
    {
        gBoxCntStruct.SingleTimeCnt++;
        if(JAMSIZE < gBoxCntStruct.SingleTimeCnt)
        {
            gBoxCntStruct.JamFlag = 1;
            gBoxCntStruct.AlarmFlag = 1;
            gBoxCntStruct.SingleTimeCnt = 0;
            gBoxCntStruct.TimeCntEndFlag = 0;
            gBoxCntStruct.TimeCntStartFlag = 0;
            gBoxCntStruct.DisplayReflashFlag = 1;
        }
        return;
    }
    
    
    
    if(1 == gBoxCntStruct.TimeCntEndFlag)
    {
        gBoxCntStruct.TimeCntEndFlag = 0;
        gBoxCntStruct.TimeCntStartFlag = 0;
        
        if(10 > gBoxCntStruct.SingleTimeCnt)
        {
            gBoxCntStruct.SingleTimeCnt = 0;
            return;
        }
        
        gBoxCntStruct.DisplayReflashFlag = 1;
        
        if(LARGEBOXSIZE < gBoxCntStruct.SingleTimeCnt)
        {
            gBoxCntStruct.AlarmFlag = 1;
            gBoxCntStruct.SingleTimeCnt = 0;
            return;
        }
        
        if(SMALLBOXSIZE < gBoxCntStruct.SingleTimeCnt && MIDDLEBOXSIZE > gBoxCntStruct.SingleTimeCnt)
        {
            gBoxCntStruct.MiddleBoxCnt++;
            gBoxCntStruct.SingleTimeCnt = 0;
            return;
        }
        
        if(MIDDLEBOXSIZE < gBoxCntStruct.SingleTimeCnt && LARGEBOXSIZE > gBoxCntStruct.SingleTimeCnt)
        {
            gBoxCntStruct.LargeBoxCnt++;
            gBoxCntStruct.SingleTimeCnt = 0;
            return ;
        }
        
        if(SMALLBOXSIZE > gBoxCntStruct.SingleTimeCnt)
        {
            gBoxCntStruct.SmallBoxCnt++;
            gBoxCntStruct.SingleTimeCnt = 0;
            return;
        } 
    }   
}
