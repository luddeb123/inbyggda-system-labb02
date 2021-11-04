#include <avr/io.h>

#include "timer.h"

uint16_t OCRvalue(uint16_t prescaler, uint8_t milliseconds){
    uint16_t freq_scaled = F_CPU/prescaler; //15625
    uint16_t seconds = milliseconds/1000;   //0,016
    uint16_t ticks = freq_scaled*seconds;   //250
    ticks = ticks - 1;                        //Correct for starting at 0

    return ticks;
}

void timer0_init() {
	//Timer/Counter Control Register 2 A och B för Fast PWM
	TCCR2A |= (1 << WGM20);
	TCCR2A |= (1 << WGM21);
	TCCR2B &= ~(1 << WGM22);

	// Timer/Counter Control Register 2 A värdena för Non inverting Mode
	TCCR2A &= ~(1 << COM2A0);
	TCCR2A |= (1 << COM2A1);

	//Timer/Counter Control Register 2 B värdena för prescaler=64
	TCCR2B &= ~(1 << CS20);
	TCCR2B |= (1 << CS21);
	TCCR2B |= (1 << CS22);
}

void timer2_init() {
    // Timer/Counter Control Register 0 A sätts för Clear OC0A on Compare Match.
    TCCR0A &= ~(1 << WGM02);
    TCCR0A |= (1 << WGM01);
	TCCR0A &= ~(1 << WGM00);

    // Timer/Counter Control Register 0 B och A sätts för prescaler=1024 
    TCCR0A &= ~(1 << CS01);
    TCCR0B |= (1 << CS00);
	TCCR0B |= (1 << CS02);

    //Timer/Counter Register (stores the counter value). Sätter till 0 för att initiera. 
    TCNT0 = 0;

    //Output Compare Register.
	OCR0A = OCRvalue(1024, 16);
}

