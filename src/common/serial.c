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
    loop_until_bit_is_set(UCSR0A, UDRE0);
    /* set the data register with some data */
    UDR0 = data;
    return 0;
}

static int USART_getchar(FILE *stream)
{
    /* wait until there is data in the receive data register */
    loop_until_bit_is_set(UCSR0A, RXC0);
    /* return data in receive data register */
    return UDR0;
}

void USART_init(void)
{
    /* set baud rate */
    UBRR0H = UBRRH_VALUE;
    UBRR0L = UBRRL_VALUE;

    #if	USE_2X
        UCSR0A |= _BV(U2X0);
    #else
        UCSR0A &= ~_BV(U2X0);
    #endif

    /* enable RX and TX */
    UCSR0B = _BV(RXEN0) | _BV(TXEN0);
    /* 8 data bits, 1 stop bit, no parity */
    UCSR0C = _BV(UCSZ01) | _BV(UCSZ00);

    /* opens a stream with write intent and sets stdout and stderr */
    fdevopen(USART_putchar, NULL);
    /* opens a stream with read intent and sets stdin */
    fdevopen(NULL, USART_getchar);
}
