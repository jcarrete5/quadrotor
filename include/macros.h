#ifndef MACROS_H
#define MACROS_H

#include <avr/sfr_defs.h>

/* Sets the bit in the specified register */
#define SBI(reg, bit) (reg) |= _BV(bit)
/* Clears the bit in the specified register */
#define CBI(reg, bit) (reg) &= ~_BV(bit)

#endif /* MACROS_H */
