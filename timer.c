#include <avr/io.h>

#include "timer.h"

void timer_init() {
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
