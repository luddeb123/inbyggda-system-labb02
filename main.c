#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>

#include <stdio.h>

#include "led.h"
#include "serial.h"
#include "timer.h"

int main (void) {
    int overflowCount = 0;

    uart_init(); 	
	timer_init();	
    led_init();		

    while (1) {
        while ((TIFR0 & (1 << OCF0A)) > 0) { // Timer/Counter Interrupt Flag Register. Väntar på ett overflow event.
            overflowCount++;
            if (overflowCount == 10) {
                toggle_led();
                overflowCount = 0;
            }
            TIFR0 |= (1 << OCF0A);  // Rensar overflow flaggan
        }
    }
}
