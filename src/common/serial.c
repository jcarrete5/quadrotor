#include <avr/io.h>
#include <stdio.h>

#define BAUD 9600
#include <util/setbaud.h>

static int USART_putchar(char data, FILE *stream)
{
    /* prepend carriage return to newline */
    if (data == '\n') {
        USART_putchar('\r', stream);
    }
    /* wait until transmit data register is empty */
    loop_until_bit_is_set(UCSR1A, UDRE1);
    /* set the data register with some data */
    UDR1 = data;
    return 0;
}

static int USART_getchar(FILE *stream)
{
    /* wait until there is data in the receive data register */
    loop_until_bit_is_set(UCSR1A, RXC1);
    /* return data in receive data register */
    return UDR1;
}

void USART_init(void)
{
    /* set baud rate */
    UBRR1H = UBRRH_VALUE;
    UBRR1L = UBRRL_VALUE;

    #if	USE_2X
        UCSR0A |= _BV(U2X0);
    #else
        UCSR1A &= ~_BV(U2X1);
    #endif

    /* enable RX and TX */
    UCSR1B = _BV(RXEN1) | _BV(TXEN1);
    /* 8 data bits, 1 stop bit, no parity */
    UCSR1C = _BV(UCSZ11) | _BV(UCSZ10);

    /* opens a stream with write intent and sets stdout and stderr */
    fdevopen(USART_putchar, NULL);
    /* opens a stream with read intent and sets stdin */
    fdevopen(NULL, USART_getchar);
}
