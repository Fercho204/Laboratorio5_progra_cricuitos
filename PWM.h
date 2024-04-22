/*
 * PWM1.h
 *
 * Created: 15/4/2024 14:42:04
 *  Author: Fer
 */ 



// Incluye las definiciones necesarias para la correcta compilación de la función PWM1. 
#ifndef PWM1_H_
#define PWM1_H_

#include <avr/io.h> // Incluye las definiciones de los registros del microcontrolador AVR.
#include <stdint.h> // Incluye las definiciones de tipos de datos enteros estándar.

// Prototipo de la función PWM1.
int PWM1(uint8_t numeropot, uint8_t valoradc);

#endif // PWM1_H_
