#ifndef SERIAL_H
#define SERIAL_H

/**
 * Initializes 8N1 Serial communication.
 * Intended to be used for sending data to a computer for debugging purposes.
 * After a call to this function, stdin, stdout, and stderr will be set.
 */
void USART_init();

#endif /* SERIAL_H */
