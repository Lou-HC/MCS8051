/*
---- Loulan's Lucrative Library ----
Louis H Combrink
3 Aug 2026
56243308
*/

#ifndef LOULANS_LUCRATIVE_LIBRARY
#define LOULANS_LUCRATIVE_LIBRARY

// ---- DEFINES ---- //

// -- Timer -- //
#define TIMER_RELOAD_HIGH       0xFC
#define TIMER_RELOAD_LOW        0x65

#define TIMER0_OVERFLOW_FLAG    0x20

#define TIMER_OVERFLOW_LIMIT    0xFFFF //65535

#define TIME_MILISECOND         0X01
#define TIME_HUNDRED_MS         0x02
#define TIME_SECONDS            0x80

// -- Const -- //
// - Modes - //
#define M0_OUTPUT   0x0000
#define M1_OUTPUT   0XFFFF
#define M0_INPUT    0xFFFF
#define M1_INPUT    0x0000

// - 7 seg nums - //
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
/*
    Ex.
    Pin number       7654 3210
    Pin value        0000 0000
*/

#define HIGH_NIBBLE_TRUE    0xF0
#define LOW_NIBBLE_TRUE     0x0F
// ---- VAR ---- //

extern unsigned char TimerFlag;


// ---- FUNTIONS ---- //
// --- 8051 --- //
void SetPortXOutput(int PortNum);
void SetPortXInput(int PortNum);
void DisplayNumPort0(int num);
void Timer0Init(void);
void InitTimer0Polling(int timeMicroSeconds);
void TimerTest(void);

// --- Gen --- //
int StrLen(char* input);

#endif // LOULANS_LUCRATIVE_LIBRARY
