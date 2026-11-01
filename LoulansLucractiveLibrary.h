/*
---- Loulan's Lucrative Library ----
Loulan
Started on 3 Aug 2026
56243308

// -- Some interesting things to note: -- //

The MCS8051 runs at 11,0592MHz => 11059200 Hertz.

We have 12 clocks per cycle, thus:
    11059200 / 12 = 921600 Cycles per second.
    => 0.921600 Cycles per microsecond.
    We can take this to 8 clocks per cycle,
    but that is beyond the scope of first year.

How to read Baud Rates:
ex 9600, 8, N, 1
    9600 bps // Bits Per Second
    8 data bits per byte
    No parity // None
    1 Stop Bit

ex 2400, 8, O, 2
    2400 bps
    8 data bits
    Odd parity
    2 stop bits

Some terms:
    MOSI:   Master-Out-Slave-In
    UART:   Universal Asynchronous Receiver Transmitter
    TTL:    Transistor-Transistor Logic
    ALU:    Arithmetic Logic Unit
    MIPS:   Million Instructions per Second
    ALE:    Address Latch Enable
    SPI:    Serial Peripheral Interface
    Nibble: 4 bits || half of a byte
    Byte:   8 bits
    Word:   16 bits || 2 bytes
    GPIO:   General Purpose Input/Output
    IO:     Input/Output
    CS:     Chip Select (usually active low)
    PSEN:   Program Store Enable(d)

The PSEN button is on Port 4 Pin 5 (P4.5) (Active low)

On the SPI 7-Seg display, the f & g LED's are swapped.

*/

#ifndef LOULANS_LUCRATIVE_LIBRARY
#define LOULANS_LUCRATIVE_LIBRARY

// ---- DEFINES ---- //

// -- Timer -- //
#define TIMER_RELOAD_HIGH       0xFC
#define TIMER_RELOAD_LOW        0x65

#define TIMER0_OVERFLOW_FLAG    0x20

#define TIMER_OVERFLOW_LIMIT    0xFFFF // 65535_10

#define CYCLES_PER_SECOND       0xE1000 //921600
#define CYCLES_PER_MIRCOSECOND  0.921600 // (0xE1000 / 10^6)
//Used in TimerTest
#define TIME_MILISECOND         0X01
#define TIME_HUNDRED_MS         0x02
#define TIME_SECONDS            0x80

// -- Modes -- //
#define M0_OUTPUT   0x0000
#define M1_OUTPUT   0XFF
#define M0_INPUT    0xFF
#define M1_INPUT    0x0000

// -- 7 seg nums -- //
#define SEVEN_SEG_0     0x3F
#define SEVEN_SEG_1     0x06
#define SEVEN_SEG_2     0x5B
#define SEVEN_SEG_3     0x4F
#define SEVEN_SEG_4     0x66
#define SEVEN_SEG_5     0x6D
#define SEVEN_SEG_6     0x7D
#define SEVEN_SEG_7     0x07
#define SEVEN_SEG_8     0x7F
#define SEVEN_SEG_9     0x6F
#define SEVEN_SEG_DP    0x80
#define TOGGLE_DP       P0 ^= SEVEN_SEG_DP //Decimal Pointer

// - Gen Use - //
// Pins //
#define ONLY_PIN0    0x0001
#define ONLY_PIN1    0x0002
#define ONLY_PIN2    0x0004
#define ONLY_PIN3    0x0008
#define ONLY_PIN4    0x0010
#define ONLY_PIN5    0x0020
#define ONLY_PIN6    0x0040
#define ONLY_PIN7    0x0080
#define HIGH_NIBBLE_TRUE    0xF0
#define LOW_NIBBLE_TRUE     0x0F
/*
    Ex.
    Pin number       7654 3210
    Pin value        0000 0000
*/

// -- SPI -- //
#define SPI_WRITE_CMD   0x42    // Page 7 in MCP23008-MCP23S08-Data-Sheet-20001919F.pdf
#define SPI_READ_CMD    0x43    // Page 7 in MCP23008-MCP23S08-Data-Sheet-20001919F.pdf
// - Macros - //
#define SPI_CS_HIGH         P1 |= 0x10
#define SPI_CS_LOW          P1 &= ~0x10
#define SPI_CS_TOGGLE       P1 ^= 0x10

#define SPI_CLK_HIGH        P1 |= 0x40
#define SPI_CLK_LOW         P1 &= ~0x40
#define SPI_CLK_TOGGLE      P1 ^= 0x40

#define SPI_MOSI_HIGH       P1 |= 0x80
#define SPI_MOSI_LOW        P1 &= ~0x80
#define SPI_MOSI_TOGGLE     P1 ^= 0x80

#define SPI_MISO_INPUT      P1 & 0x20

#define WAIT_TIME           1
// Page 8 of the data sheet; The MCP23S08 SPI Extension.
#define MCP23S08_IODIR      0x00
#define MCP23S08_IPOL       0x01
#define MCP23S08_GPINTEN    0x02
#define MCP23S08_DEFVAL     0x03
#define MCP23S08_INTCON     0x04
#define MCP23S08_IOCON      0x05
#define MCP23S08_GPPU       0x06
#define MCP23S08_INTF       0x07
#define MCP23S08_INTCAP     0x08
#define MCP23S08_GPIO       0x09
#define MCP23S08_OLAT       0x0A

// ---- VAR ---- //

extern unsigned char TimerFlag;

extern unsigned char SEVEN_SEG_NUMS[10];


// ---- FUNTIONS ---- //
// --- 8051 --- //
// -- Ports -- //
void SetPortXOutput(int PortNum);
void SetPortXInput(int PortNum);
void DisplayNumPort0(int num);
// -- Timers -- //
void Timer0Init(void);
void InitTimer1HighVal(unsigned char timeHigh);
void InitTimer0Polling(int timeMicroSeconds);
void TimerTest(void);
// -- Serial Ports/Comms -- //
void InitSerialComm(void);
void InitSerialCommBaudRate(int baudRate);
void SendByteSerialPort(unsigned char data);
void SendStringSerialPort(unsigned char *data);
unsigned char ReadByteSerialPort(void);
// -- SPI -- //
void SetupPort1SPI(void);
void SendDataSPI(unsigned char address, unsigned char data);
unsigned char ReadDataSPI (unsigned char address);

// --- Gen --- //
int StrLen(char* input);

#endif // LOULANS_LUCRATIVE_LIBRARY
