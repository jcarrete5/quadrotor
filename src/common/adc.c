#include <avr/io.h>
#include "macros.h"
#include "adc.h"

static void select_pin(enum analog_pin pin)
{
    if (pin & 0x1) {
        SBI(ADMUX, MUX0);
    } else {
        CBI(ADMUX, MUX0);
    }
    if (pin & 0x2) {
        SBI(ADMUX, MUX1);
    } else {
        CBI(ADMUX, MUX1);
    }
    if (pin & 0x4) {
        SBI(ADMUX, MUX2);
    } else {
        CBI(ADMUX, MUX2);
    }
    if (pin & 0x8) {
        SBI(ADMUX, MUX3);
    } else {
        CBI(ADMUX, MUX3);
    }
}

unsigned int analog_read(enum analog_pin pin)
{
    select_pin(pin);

    /* Start conversion */
    SBI(ADCSRA, ADSC);
    loop_until_bit_is_clear(ADCSRA, ADSC);

    /* Read value */
    unsigned int val;
    if (bit_is_set(ADMUX, ADLAR)) {
        val = ADCL >> 6;
        val |= ADCH << 2;
    } else {
        val = ADCL;
        val |= ADCH << 8;
    }
    return val;
}
