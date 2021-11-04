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
        OCR2A = 50;
        _delay_ms(1000);
        OCR2A = 100;
        _delay_ms(1000);
        OCR2A = 150;
        _delay_ms(1000);
        OCR2A = 200;
        _delay_ms(1000);
    }
}
