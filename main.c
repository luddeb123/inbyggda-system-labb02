#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>

#include <stdio.h>

#include "led.h"
#include "serial.h"
#include "timer.h"

int main (void) {
    int overflowCount = 0;
	uint8_t direction = 1;
	uint8_t pwmvalue = 0;

    uart_init();
	timer0_init();
	timer2_init();
	led_init();


	while (1) {
		if(TIFR0 & (1<<OCF0A)){ // kollar timer 2 ifall värdet är över 0
			TIFR0 |= (1<<OCF0A); // tömmer flaggan
			OCR2A = simple_ramp(&pwmvalue, &direction); // uppdaterar timer0
		}
	}
}

