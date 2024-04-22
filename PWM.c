/*
 * PWM1.c
 *
 * Created: 15/4/2024 14:48:06
 *  Author: Fer
 */ 

#include "PWM1.h"

/*
 * Función PWM1: Controla la señal PWM en un microcontrolador AVR.
 */ 
int PWM1(uint8_t numeropot, uint8_t valoradc){
    uint16_t valortotal;
    // Dependiendo del valor de 'numeropot', configura el canal ADC correspondiente.
    if (numeropot == 1)
    {
        ADMUX = (ADMUX & 0xF0) | numeropot;
        // Inicia la conversión ADC para leer el valor del potenciómetro.
        ADCSRA |= (1<<ADSC);
        // Para 'numeropot == 1', realiza un mapeo lineal del valor leído para establecer el ancho de pulso del servo.
        valortotal = (32.94*valoradc)+1199.06;//mapeo(valoradc, 0, 255, 19, 39);
        OCR1AH = (valortotal & 0xFF00) >> 8;
        OCR1AL |= valortotal & 0x00FF;
    }
    else if (numeropot == 0)
    {
        ADMUX = (ADMUX & 0xF0) | numeropot;
        // Inicia la conversión ADC para leer el valor del potenciómetro.
        ADCSRA |= (1<<ADSC);
        // Para 'numeropot == 0', calcula directamente el valor para el registro 'OCR2A'.
        OCR2A = (0.094*valoradc)+6.7;
    }
    else if (numeropot == 2)
    {
        ADMUX = (ADMUX & 0xF0) | numeropot;
        // Inicia la conversión ADC para leer el valor del potenciómetro.
        ADCSRA |= (1<<ADSC);
        // Para 'numeropot == 2', asigna el valor leído directamente al registro 'OCR0A'.
        OCR0A = valoradc;
    }
    // Espera hasta que la conversión ADC esté completa antes de devolver el valor leído.
    while (ADCSRA & (1 << ADSC));
    return ADC;
}

