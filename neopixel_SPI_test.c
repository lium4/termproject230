//File Name: neopixel_SPI_test.c
//Source: https://github.com/mjmeli/MSP430-NeoPixel-WS2812-Library.
//use SPI SIMO to generate neopixel timing signal.
//Jianjian Song
//Date: Feb-11-2025
/*
 *
*                MSP432P4111
 *              -----------------
 *             |                 |
 *             |                 |
 *             |                 |
 *             |             P2.3|-> Data Out (UCA1SIMO)- neopixel data pin
 *             |                 |
 *             |             P2.2|<- Data In (UCA1SOMI)
 *             |                 |
 *             |             P2.1|-> Serial Clock Out (UCA1CLK)
 *             |                 |
 *             |             P2.0|-> STE indicate slave on this unit is ready
*/

#include <msp.h>
#include "spi_ws2812.h"
#include "SPIsubroutines_JJS.h"

int main(void) {

    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;

//Use External 48MHz oscillator. Set MCLK at 48 MHz for CPU.
//Set SMCLK at 48 MHz. Set ACLK at 32kHz.
    SetClocks();

    // initialize LED strip
    initStrip();  // ***** HAVE YOU SET YOUR NUM_LEDS DEFINE IN WS2812.H? ******

    // set strip color red
    fillStrip(0xFF, 0x00, 0x00);

    // show the strip
    showStrip();

    // gradually fill for ever and ever
    while (1) {
        gradualFill(NUM_LEDS, 0x00, 0xFF, 0x00);  // green
        gradualFill(NUM_LEDS, 0x00, 0x00, 0xFF);  // blue
        gradualFill(NUM_LEDS, 0xFF, 0x00, 0xFF);  // magenta
        gradualFill(NUM_LEDS, 0xFF, 0xFF, 0x00);  // yellow
        gradualFill(NUM_LEDS, 0x00, 0xFF, 0xFF);  // cyan
        gradualFill(NUM_LEDS, 0xFF, 0x00, 0x00);  // red
    }
}

