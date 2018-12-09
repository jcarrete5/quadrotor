#ifndef ADC_H
#define ADC_H

enum analog_pin {
    A0, A1, A2, A3, A4, A5, A6, A7, A8
};

/**
 * Start a conversion and wait until it is completed. Then read the values in
 * the `ADCH` and `ADCL` registers and return them as an unsigned int value.
 * Same behavior regardless of `ADLAR`'s value.
 */
unsigned int analog_read(enum analog_pin pin);

#endif /* ADC_H */
