#include <avr/io.h>

#include "timer.h"

void timer_init() {
	
	//Timer/Counter Control Register 0 A. Sätter andra biten(WGM01) till 1 och första biten(WGM00) till 0(den defaultar till 0 men gör det för säkerherts skull) för Clear OC0A on Compare Match.
	TCCR0A |=  (1 << WGM01);	// 1
	TCCR0A &=  ~(1 << WGM00);	// 0 sätter den även fast den defaultar till 0

	//Timer/Counter Control Register 0 B. Sätter första(CS00) och tredje(CS02) till 1 samt andra(CS01) till 0 för prescaler=1024 
	TCCR0B |=  (1 << CS02); // 1
	TCCR0B &= ~(1 << CS01); // 0 sätter den även fast den defaultar till 0
	TCCR0B |=  (1 << CS00); // 1
	
	//Timer/Counter Register (stores the counter value). Sätter till 0 för att initiera. 
	TCNT0 = 0;
	
	//Output Compare Register. Sätter till 156 för att: 16000000/1024=15625 per sekund. sen 15625/100 för att få 100 gånger per sekund(10ms).
	OCR0A = 156; 
}

