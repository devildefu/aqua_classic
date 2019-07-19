#ifndef __DEBUG_H_
#define __DEBUG_H_

#include <stdlib.h>
#include <string.h>

#ifdef __i386__
    #include <devices/serial.h>

    /* TODO: make it nicer */
    //#define debug(msg) com_print(COM1_PORT, "(");com_print(COM1_PORT, __FILE__);com_print(COM1_PORT, ":");char line[100];itoa(__LINE__, line);com_print(COM1_PORT, line);com_print(COM1_PORT, ") ");com_print(COM1_PORT, msg);com_print(COM1_PORT, "\r\n")
    #define debug(msg) com_printf(COM1_PORT, "(%s:%i) %s\r\n", __FILE__, __LINE__, msg)
    #define fail(msg) debug(msg);abort()
#else
    #define debug(msg) 
    #define fail(msg) abort()
#endif

#endif