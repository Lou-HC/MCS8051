/*
---- Loulan's Lucrative Library ----
Loulan
Started on 3 Aug 2026
56243308

V 1.7
*/
#include <mcs51/8051.h>
#include "LoulansLucractiveLibrary.h"

// ---- GLOBAL VAR ---- //

unsigned char TimerFlag = 0;

unsigned char SEVEN_SEG_NUMS[10] = {SEVEN_SEG_0, SEVEN_SEG_1, SEVEN_SEG_2, SEVEN_SEG_3, SEVEN_SEG_4, SEVEN_SEG_5, SEVEN_SEG_6, SEVEN_SEG_7, SEVEN_SEG_8, SEVEN_SEG_9};

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
This is for 1 unit = 1ms. View TimerFlag under TimerTest.
*/

void InitTimer0Polling(int timeMicroSeconds);

/*
    InitTimer0Polling:
    1000 0000   1000 units
    0000 0010   100  units
    0000 0001   1    unit

    Takes the time in microseconds and initialises Timer0
    to tick TimerFlag (with the TimerTest function) with
    that time.
*/

void TimerTest(void);

/*
Runs the timer to get the following values in TimerFlag:
*** Timer0Init: ***
    TimerFlag:
    0000 0001   1   ms
    0000 0010   100 ms
    1000 0000   1   s
*** InitTimer0Polling: ***
    0000 0001   1    unit
    0000 0010   100  units
    1000 0000   1000 units

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

int IntPow(int base, int exp);

void InitSerialComm(void);


// ---- Functions ---- // ---- Functions ---- // ---- Functions ---- //
// ---- Functions ---- // ---- Functions ---- // ---- Functions ---- //

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

void InitTimer0Polling(int timeMicroSeconds)
{
    /*
    Still in development
    */
    int countCycles = TIMER_OVERFLOW_LIMIT - (timeMicroSeconds * CYCLES_PER_MIRCOSECOND);
    int highVal = countCycles - (0x00FF & countCycles);
    int lowVal  = countCycles - (0xFF00 & countCycles);
    highVal = highVal >> 8;


    TMOD =      0x01;
    //Turns it on

    TR0 =       1;
    //Timer high and low values
    TH0 =       highVal;
    TL0 =       lowVal;

    //Reload high and low values
    RH0 =       highVal;
    RL0 =       lowVal;
    /*
    The mathematics behind this is:
    according to the formula:
    we have 11 059 200 instructions per second
    we also have 921600 cycles per second (11 059 200 / 12)
    take 921600 * time in second
    = number of instructions in that time.
    thus, to get the number of clock cycles per given time
    for the timer, we take:
    countCycles =  TIMER_OVERFLOW_LIMIT - (timeMicroSeconds * 0.921600)

    the 0.921600 is to account for the fact that timeMicroSeconds is in
    microseconds, and we use it here as a normal int (no 10^-6), but ergo
    we include that in in the 921600 => 0,921600.


    then we have to find only the high byte of the word, ie
    only 1111 1111 0000 0000 where the 1's represent any value.
    but, we want it to be 1111 1111, not 1111 1111 0000 0000. Thus,
    we bitshift it right 8 times after subtracting the low byte.
    Similarly, we get the low byte 0000 0000 1111 1111. But, since
    leading zeroes are ignored, there is no need for a bitshift.

    0xFF00 for Low Byte
    1111 1111 0000 0000
    If we subtract this from countCycles, we get only the low Byte
    in the form:
    0000 0000 XXXX XXXX -> XXXX XXXX

    0x00FF for High Byte
    0000 0000 1111 1111
    If we subtract this from countCycles, we get only the high Byte
    in the form:
    XXXX XXXX 0000 0000
    We then shift the bits right 8 times to get:
    XXXX XXXX

    Where X is either a one or a zero (1, 0).

    */

}

void TimerTest(void)
{
    /*
    THIS FUNCTION OUTPUTS DIFFERENT VALUES DEPENDING ON WHICH
    INIT HAS BEEN CALLED. VIEW THE COMMENT AT THE BOTTOM OF THE
    FUNCTION FOR MORE INFORMATION.
    */
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
    Timer0Init:
    TimerFlag
    1000 0000 1     Second
    0000 0010 100   ms
    0000 0001 1     ms

    InitTimer0Polling:
    1000 0000   1000 units
    0000 0010   100  units
    0000 0001   1    unit
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

int IntPow(int base, int exp)
{
    long int ans = base;
    for (int i = 1; i <= exp; i++)
    {
        ans *= base;
    }
    return ans;
}

void InitSerialComm(void)
{

    /*
    ex.
    9600, 8, None, 1
    9600 Board rate -> 9600 bits per second (bps)
    8 Data bits
    None -> no parity bit
    1 Stop bit
    */

    SCON = 0x50; //in 8 bit variable UART mode, with REN enabled.

    TMOD |= 0x20; //Does not override the current value.

    TH1 = 253;
    /*
    Calculated using formula at SCON on datasheet.
    Bottom of page 114
    9600 bps.
    */

    TR1 = 1; // timer on
}

//Note to self, make a sendData function. Perhaps also a receiveData.
