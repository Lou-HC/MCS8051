/*
---- Loulan's Lucrative Library ----
Louis H Combrink
3 Aug 2026
56243308
*/
#include <mcs51/8051.h>
#include "LoulansLucractiveLibrary.h"

// ---- GLOBAL VAR ---- //

unsigned char TimerFlag = 0;

// ---- Function Prototypes ---- //

void SetPortXOutput(int PortNum);

void SetPortXInput(int PortNum);

void DisplayNumPort0(int num);

void Timer0Init(void);

void TimerTest(void);

int StrLen(char *input);


// ---- Functions ---- //

void SetPortXOutput(int PortNum)
{
    switch (PortNum)
    {
    case 0:
        {
            P0M0 = M0_OUTPUT;
            P0M1 = M1_OUTPUT;
            break;
        }
    case 1:
        {
            P1M0 = M0_OUTPUT;
            P1M1 = M1_OUTPUT;
            break;
        }
    case 2:
        {
            P2M0 = M0_OUTPUT;
            P2M1 = M1_OUTPUT;
            break;
        }
    case 3:
        {
            P3M0 = M0_OUTPUT;
            P3M1 = M1_OUTPUT;
            break;
        }
    case 4:
        {
            P4M0 = M0_OUTPUT;
            P4M1 = M1_OUTPUT;
            break;
        }
    }

}

void SetPortXInput(int PortNum)
{
        switch (PortNum)
    {
    case 0:
        {
            P0M0 = M0_INPUT;
            P0M1 = M1_INPUT;
            break;
        }
    case 1:
        {
            P1M0 = M0_INPUT;
            P1M1 = M1_INPUT;
            break;
        }
    case 2:
        {
            P2M0 = M0_INPUT;
            P2M1 = M1_INPUT;
            break;
        }
    case 3:
        {
            P3M0 = M0_INPUT;
            P3M1 = M1_INPUT;
            break;
        }
    case 4:
        {
            P4M0 = M0_INPUT;
            P4M1 = M1_INPUT;
            break;
        }
    }
}

void DisplayNumPort0(int num)
{
    switch (num)
    {
    case 0:
        {
            P0 = SEVEN_SEG_0;
            break;
        }
    case 1:
        {
            P0 = SEVEN_SEG_1;
            break;
        }
    case 2:
        {
            P0 = SEVEN_SEG_2;
            break;
        }
    case 3:
        {
            P0 = SEVEN_SEG_3;
            break;
        }
    case 4:
        {
            P0 = SEVEN_SEG_4;
            break;
        }
    case 5:
        {
            P0 = SEVEN_SEG_5;
            break;
        }
    case 6:
        {
            P0 = SEVEN_SEG_6;
            break;
        }
    case 7:
        {
            P0 = SEVEN_SEG_7;
            break;
        }
    case 8:
        {
            P0 = SEVEN_SEG_8;
            break;
        }
    case 9:
        {
            P0 = SEVEN_SEG_9;
            break;
        }
    default:
        {
            //if reach default, toggle DP
            P0 = SEVEN_SEG_DP;
        }

    }
}

void Timer0Init(void)
{
    //Timer mode and control
    //since we're in timer0, we use the low nibble.


    TMOD =      0x01;
    //Turns it on
    //TCON =      0x10;
    //Does the same this; this does not override the whole value
    TR0 =       1;

    //Timer high and low values
    TH0 =       TIMER_RELOAD_HIGH;
    TL0 =       TIMER_RELOAD_LOW;

    //Reload high and low values
    RH0 =       TIMER_RELOAD_HIGH;
    RL0 =       TIMER_RELOAD_LOW;
}

void TimerTest(void)
{
    //This is the Pollo... Pollon... Polling something method; not the interrupt.
    //Timer should be running; Init has been called.


    /*
    TimerFlag = 0000 0000
    One hundred miliseconds stored in 0000 0001
    One Second stored in 0000 0010
    */
    static unsigned char TimeHMS = 0;//hundred ms
    static unsigned char TimeSec = 0;
    //static means var is stored in a definite address; always present.
    //static means that we only initialise it once. If we call the function again, it won't re-initialise the var.
    if (TCON & TIMER0_OVERFLOW_FLAG) // if the timer has overflowed
    {
        //1ms
        TimerFlag |= TIME_MILISECOND;
        TCON &= ~TIMER0_OVERFLOW_FLAG; //clears the overflow flag.

        TimeHMS++;
        if (TimeHMS >= 100)
        {
            TimeHMS = 0;
            TimerFlag |= TIME_HUNDRED_MS;

            /*
                0000 0001   tf
                0000 0001   0x01
                0000 0001
            */
            //one hundred ms have passed.
            TimeSec++;
            if (TimeSec >= 10)
            {
                TimeSec = 0;
                TimerFlag |= TIME_SECONDS; //one second has passed.
                /*
                0000 0001 100ms
                0000 0010 1 second
                       11
                */
            }


        }
    }
    /*
    TimerFlag
    1000 0000 1 Second
    0000 0010 100 ms
    0000 0001 1ms
    */
}
int StrLen(char *input)
{
    int i = 0;
    for (i = 0; input[i] != '\0'; i++)
    {
        continue;
    }
    return i;
}


