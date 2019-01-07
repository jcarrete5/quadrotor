#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "serial.h"
#include "macros.h"
#include "adc.h"

#define BLINK_DELAY_MS 500

int main(void)
{
    /* Init serial communication */
    USART_init();
    puts("FOOBAR");

    // SBI(ADCSRA, ADEN);  /* Enable ADC */
    // SBI(ADCSRA, ADPS0); /**********************************/
    // SBI(ADCSRA, ADPS1); /* Set ADC prescaler value to 128 */
    // SBI(ADCSRA, ADPS2); /**********************************/
    // SBI(ADMUX, REFS0);  /* Use AVcc (~5V) as AREF voltage */
    // CBI(PRR, PRADC);    /* Turn off power reduction to the ADC */

    /* set pin 13 of PORTC for output */
    SBI(DDRC, DDC7);

    while (1) {
        // /* set pin 13 high to turn led on */
        SBI(PORTC, PORTC7);
        _delay_ms(BLINK_DELAY_MS);

        // /* set pin 13 low to turn led off */
        CBI(PORTC, PORTC7);
        _delay_ms(BLINK_DELAY_MS);

        /* Select x-axis for reading */
        // unsigned int x_axis = analog_read(A0);

        /* Select y-axis for reading */
        // unsigned int y_axis = analog_read(A1);

        // printf("x_axis = %u, y_axis = %u\n", x_axis, y_axis);
        // _delay_ms(50U);
    }
}
