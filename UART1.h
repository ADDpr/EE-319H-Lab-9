// UART.h
// Runs on TM4C123

// EE319H tasks
// 1) Convert to UART1 PC4 PC5
// 2) Implement the FIFO as a class
// 3) Run transmitter with busy-wait synchronization
// 4) Run receiver with 1/2 full FIFO interrupt
// Daniel and Jonathan Valvano
// 1/12/2021

// EE319K Lab 9, U1Rx connected to PC4 interrupt
// EE319K Lab 9, U1Tx connected to PC5 busy wait
// EE319K Lab 9 hardware
// System 1        System 2
//   PC4 ----<<----- PC5
//   PC5 ---->>----- PC4
//   Gnd ----------- Gnd
// When running on one board connect PC4 to PC5

#ifndef __UART_H__
#define __UART_H__
#include <stdint.h>
// standard ASCII symbols
#define STX  0x02
#define ETX  0x03
#define CR   0x0D
#define LF   0x0A
#define BS   0x08
#define ESC  0x1B
#define SP   0x20
#define DEL  0x7F

//------------UART1_Init------------
// Initialize the UART for 1000 baud rate (assuming 80 MHz clock),
// 8 bit word length, no parity bits, one stop bit, FIFOs enabled
// Input: none
// Output: none
void UART1_Init(void);

//------------UART1_InChar------------
// Wait for new serial port input
// spin if software RxFifo is empty
// Input: none
// Output: ASCII code for key typed
char UART1_InChar(void);

//------------UART1_InStatus------------
// check for possible input ready
// Input: none
// Output: true if some input is ready
bool UART1_InStatus(void);

//------------UART1_OutChar------------
// Output 8-bit to serial port
// busy-wait
// Input: letter is an 8-bit ASCII character to be transferred
// Output: none
void UART1_OutChar(char data);

//------------UART1_InMessage------------
// Accepts ASCII characters from the serial port
//    and adds them to a string until ETX is typed
//    or until max length of the string is reached.
// Input: pointer to empty buffer of 8 characters
// Output: Null terminated string
// removes STX CR ETX
void UART1_InMessage(char *bufPt);

#endif 
