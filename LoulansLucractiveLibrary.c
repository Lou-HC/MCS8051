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

// ---- Function Prototypes ---- //// ---- Function Prototypes ---- //
// ---- Function Prototypes ---- //// ---- Function Prototypes ---- //
// ---- Function Prototypes ---- //// ---- Function Prototypes ---- //

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

void InitTimer1HighVal(unsigned char timeHigh);

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
/*
Initialises the serial comms to a default of 9600, 8, N, 1
*/

void InitSerialCommBaudRate(int baudRate);
/*
This function follows the Garbage In Garbage Out principle.
It has no safeguards against incorrect data.
It will work with correct Baudrates, and seem to work with incorrect ones.
Use only with std baudrates, such as 2400; 9600 etc.
This function also assumes that SMOD0 is 0 (the def value.)
If that is not the case, make the necessary adjustments.
*/

void SendByteSerialPort(unsigned char data);
/*
Sends a literal byte, i.e 48 => '0'.
*/

void SendStringSerialPort(unsigned char *data);
/*
Sends multiple bytes.
*/

unsigned char ReadByteSerialPort(void);

void SetupPort1SPI(void);

void SendDataSPI(unsigned char address, unsigned char data);

unsigned char ReadDataSPI (unsigned char address);



// ---- Functions ---- // ---- Functions ---- // ---- Functions ---- //
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
    int countCycles = CYCLES_PER_MIRCOSECOND * timeMicroSeconds + 1;
    int highVal = TIMER_OVERFLOW_LIMIT - (0x00FF & countCycles);
    int lowVal  = TIMER_OVERFLOW_LIMIT - (0xFF00 & countCycles);
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
   Thank you to Jess E. Blom for this formula.
   The +1 is to account for how C handles float to integer casting.
   i.e. This function is accurate to 1us, not 100%.

    */

}

void InitTimer1HighVal(unsigned char timeHigh)
{
    TMOD |= 0x20; //no override

    TH1 = timeHigh;

    TR1 = 1;//turns it on
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

    InitTimer1HighVal(253);
    /*
    Calculated using formula at SCON on datasheet.
    Bottom of page 114
    9600 bps.
    */

}

void InitSerialCommBaudRate(int baudRate)
{
    unsigned char timer1HighVal;
    timer1HighVal = ((8192 * baudRate - CYCLES_PER_SECOND) / (32 * baudRate));
    InitTimer1HighVal(timer1HighVal);

    /*
    This was calculated with the formula:
    BR = ((2 ^ SMOD0) / 32) * (freq / (256 - TH1))
    */
}

void SendByteSerialPort(unsigned char data)
{
    TI = 0;
    SBUF = data;
    while (TI == 0);
}

void sendStringSerialPort(unsigned char *data)
{
    unsigned char i = 0;

    do
    {
        SendByteSerialPort(data[i]);
    } while (data[++i] != '\0');
}

unsigned char ReadByteSerialPort(void)
{
    unsigned char InputRx = 0x00;
    if (RI)
    {
        RI = 0;//software clears RI
        InputRx = SBUF;
    };
    return InputRx;
    /*
    This function returns either a '\r' or the input character.
    If the user presses enter or completes the message, it will read
    as '\r', otherwise it will be some character.
    Until something is read, the function will return 0x00.
    */
}
void SetupPort1SPI(void)
{
    P1M0 &= ~0xF0;  // Reset the high nibble to zeros
    P1M1 &= ~0xF0;  // Reset the high nibble to zeros

    P1M0 |= 0x20;   // P1.5 MISO set to input // 0010 = 0x2
    P1M1 |= 0xD0;   // P1.7 = MOSI, P1.6 = CS, P1.4 = CLCK set to Ouputs // 1101 = 0xD

    P1 &= ~0xF0;    // Make the high nibble all zeros
    SPI_CS_HIGH;
    SPI_CLK_HIGH;
}

void SendDataSPI(unsigned char address, unsigned char data)
{
    volatile unsigned char SendData = SPI_WRITE_CMD;
    volatile unsigned char LoopTimes;

    // Note the follwong from the diagram:
    // 1. The data is clocked on the falling edge
    // 2. The data on SO will be set when the clck is LOW
    // 3. The MSB - Most Significant Bit will be send first and the LSB - Least Significant Bit last

    // In the Setup of the port GPIO the CS and CLK was set high
    // The clock will start LOW and then the CS will be made LOW,
    // else if the CS go first LOW the CLK will load data into the IC when going LOW
    // We will have some wat time, a for loop.

    // The following bytes must be send
    // 1. IC address - see the header file and it must be a write
    // 2. The address in the MCP23S08 pg 8: TABLE 1-3: CONFIGURATION AND CONTROL REGISTERS
    // 3. The SetupData that needs to be setup

    SPI_CLK_LOW;
    SPI_CS_LOW; //we are active.
     // 8-bits must be send
    LoopTimes = 8;
    // 1. IC address - see the header file and it must be a write
    do
    {
        // write the first bit (MSB) onto MOSI PIN, HIGH or LOW by testing the bit
        if (SendData & 0x80)
            SPI_MOSI_HIGH;
        else
            SPI_MOSI_LOW;
        // Shift to the next bit
        SendData <<= 1;
        SPI_CLK_HIGH;
        SPI_CLK_LOW;
   }
    while (--LoopTimes > 0);

    // 8-bits must be send
    LoopTimes = 8;
    // 2. The address in the MCP23S08 pg 8: TABLE 1-3: CONFIGURATION AND CONTROL REGISTERS
    SendData = address;
    do
    {
        // write the first bit (MSB) onto MOSI PIN, HIGH or LOW by testing the bit
        if (SendData & 0x80)
            SPI_MOSI_HIGH;
        else
            SPI_MOSI_LOW;
        // Shift to the next bit
        SendData <<= 1;
        SPI_CLK_HIGH;
        SPI_CLK_LOW;
  }
    while (--LoopTimes > 0);

    // 8-bits must be send
    LoopTimes = 8;
    // 3. The SetupData that needs to be setup
    SendData = data;
    do
    {
        // write the first bit (MSB) onto MOSI PIN, HIGH or LOW by testing the bit
        if (data & 0x80)
            SPI_MOSI_HIGH;
        else
            SPI_MOSI_LOW;
        // Shift to the next bit
        SendData <<= 1;
        SPI_CLK_HIGH;
        SPI_CLK_LOW;
   }
    while (--LoopTimes > 0);
    // Data Send Done, make CS high
    SPI_CS_HIGH;

    /*
    This code was made by Piet Van Huyssteen and altered by Loulan.
    According to my understanding of the code, the following happens:
    1. We send SPI_WRITE_CMD to the SPI, meaning that we tell the SPI:
        "Hey, I will be writing to you."
    2. Thereafter, we send the address:
        "Hey, here is where I'll be writing to you."
    3. Finally, we send the data:
        "Hey, here is what the new value is."
    Kachow.
    */
}

unsigned char ReadDataSPI (unsigned char address)
{
    volatile unsigned char SendData = SPI_READ_CMD;
    volatile unsigned char LoopTimes;
    unsigned char ReadByte = 0;

    // Note the following from the diagram:
    // 1. The data is clocked on the falling edge
    // 2. The data on SO will be set when the clck is LOW
    // 3. The MSB - Most Significant Bit will be send first and the LSB - Least Significant Bit last

    // In the Setup of the port GPIO the CS and CLK was set high
    // The clock will start LOW and then the CS will be made LOW,
    // else if the CS go first LOW the CLK will load data into the IC when going LOW
    // We will have some wat time, a for loop.

    // The following bytes must be send
    // 1. IC address - see the header file and it must be a write
    // 2. The address in the MCP23S08 pg 8: TABLE 1-3: CONFIGURATION AND CONTROL REGISTERS
    // 3. The SetupData that needs to be setup

    SPI_CLK_LOW;
    SPI_CS_LOW;
    // 8-bits must be send
    LoopTimes = 8;
    // 1. IC address - see the header file and it must be a write
    do
    {
        // write the first bit (MSB) onto MOSI PIN, HIGH or LOW by testing the bit
        if (SendData & 0x80)
            SPI_MOSI_HIGH;
        else
            SPI_MOSI_LOW;
        // Shift to the next bit
        SendData <<= 1;
        // wait a moment
        SPI_CLK_HIGH;
        SPI_CLK_LOW;
   }
    while (--LoopTimes > 0);

    // 8-bits must be send
    LoopTimes = 8;
    // 2. The address in the MCP23S08 pg 8: TABLE 1-3: CONFIGURATION AND CONTROL REGISTERS
    SendData = address;
    do
    {
        // write the first bit (MSB) onto MOSI PIN, HIGH or LOW by testing the bit
        if (SendData & 0x80)
            SPI_MOSI_HIGH;
        else
            SPI_MOSI_LOW;
        // Shift to the next bit
        SendData <<= 1;
        SPI_CLK_HIGH;
        SPI_CLK_LOW;
  }
    while (--LoopTimes > 0);

    // 8-bits must be read
    LoopTimes = 8;
    // 3. The SetupData that needs to be setup
    SendData = 0x00;
    do
    {
        // write the first bit (MSB) onto MOSI PIN, HIGH or LOW by testing the bit
        if (SendData & 0x80)
            SPI_MOSI_HIGH;
        else
            SPI_MOSI_LOW;
        // Shift to the next bit
        SendData <<= 1;
        SPI_CLK_HIGH;
        ReadByte <<= 0x01;
        if (SPI_MISO_INPUT)
            ReadByte |= 0x01;
        SPI_CLK_LOW;
  //      for (Wait = 0; Wait < WAIT_TIME; Wait++);
   }
    while (--LoopTimes > 0);
    // Data Read Done, make CS high
    SPI_CS_HIGH;

    return ReadByte;
}



