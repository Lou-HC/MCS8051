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

/*
Sets the pins of the port that was input as an argument
to output mode. (All pins.).
*/

void SetPortXInput(int PortNum);

/*
Sets the pins of the port that was input as an argument
to input mode. (All pins.).
*/

void DisplayNumPort0(int num);

/*
Takes a number as input and outputs the value to Port 0,
thus outputting it on the 7-segment display.

Requires P0 to be in output mode.
*/

void Timer0Init(void);

/*
Switches the timer on and resets its value(s).
*/

void TimerTest(void);

/*
Runs the timer to get the following values in TimerFlag:
    TimerFlag:
    0000 0001   1   ms
    0000 0010   100 ms
    1000 0000   1   s

Note that this function does not clear TimerFlag.
It is is thus the responsibility of the user to
reset it after a condition has been met, if need be.

Upon calling this function, two Static Unsigned Characters
are declared, meaning that they are ever-present henceforth.

Requires the calling of Timer0Init(), or an action with
similar results.
*/

int StrLen(char *input);

/*
Reads through the string until a '\0' has been found,
then returns the number of characters read.
*/


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
    //This is the Polling method; not the interrupt.
    //Timer should be running => Init has been called.

    static unsigned char TimeHMS = 0;//hundred ms
    static unsigned char TimeSec = 0;
    //static means var is stored in a definite address; always present.
    //static means that we only initialise it once. If we call the function again,
    //it won't re-initialise the var.

    if (TCON & TIMER0_OVERFLOW_FLAG) // if the timer has overflowed
    {
        //1ms
        TimerFlag |= TIME_MILISECOND;
        TCON &= ~TIMER0_OVERFLOW_FLAG; //clears the overflow flag.

        TimeHMS++;
        if (TimeHMS >= 100) //one hundred ms have passed.
        {
            TimeHMS = 0;
            TimerFlag |= TIME_HUNDRED_MS;

            TimeSec++;
            if (TimeSec >= 10) //one second has passed.
            {
                TimeSec = 0;
                TimerFlag |= TIME_SECONDS;
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


