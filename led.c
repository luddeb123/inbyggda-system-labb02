#include <avr/io.h>
#include <util/delay.h>
#include "led.h"

void led_init() {
	// Sätter bitarna i port B till output.
	DDRB |= (1 << RED_PIN);
	DDRB |= (1 << GREEN_PIN);
	DDRB |= (1 << BLUE_PIN);
	// Sätter alla bitar höga så att de är av (common anode)
	PORTB |= (1 << RED);
	PORTB |= (1 << GREEN);
	PORTB |= (1 << BLUE);
}
void toggle_led() {
	PORTB ^= (1 << BLUE);
}