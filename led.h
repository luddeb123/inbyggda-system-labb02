#ifndef _LED_H_
#define _LED_H_

#define RED_PIN DDB3
#define GREEN_PIN DDB2
#define BLUE_PIN DDB1

#define RED PB3
#define GREEN PB2
#define BLUE PB1

void led_init(void);
void toggle_led(void);

#endif // _LED_H_
