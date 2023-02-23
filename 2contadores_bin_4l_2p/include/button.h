#ifndef BUTTON_H
#define BUTTON_H

#ifdef __cplusplus
extern "C" {
#endif

// ====================================================================================================
// Dependencies
// ====================================================================================================
#include <Arduino.h>
#include <stdint.h>

// ====================================================================================================
// Macro definitions (public)
// ====================================================================================================


// ====================================================================================================
// Type definitions
// ====================================================================================================
typedef struct
{
    uint8_t pin;
    unsigned char actualizacion;         // Lectura actual
    unsigned char boton_estadoA;         // Ultima lectura realizada
    unsigned char estado;                // Estado actual del boton
    unsigned char last_debounce_time;    // utlimot tiempo en el que se tardó para obtener el valor
    unsigned char debounce_delay;        // delay
} button_t;

// ====================================================================================================
// Public function definitions
// ====================================================================================================
/**
 * @brief Initializes a counter structure.
 * 
 * @param[in, out] Boton  Points to the button data structure.
 * @param[in] last_debounce_time               
 * @param[in] debounce_time          
 */

// esto no estoy segura de que hace 
static inline void init_boton(button_t * Boton)
{
    pinMode(Boton->pin, INPUT);
    c_self->led2 = l2;
    c_self->led3 = l3;
    c_self->led4 = l4;
}

// ====================================================================================================
// Public function prototypes
// ====================================================================================================
/**
 * @brief Gets the area of a room.
 * 
 * @param[in] c_self  Points to the room's data structure.
 * @return Room's area. 
 */
double
contador_init(contador_t * c_self);


/**
 * @brief Gets the volume of a room.
 * 
 * @param[in] c_self  Points to the room's data structure.
 * @return Room's volume. 
 */
double
room_calculate_volume(contador_t * c_self);


#ifdef __cplusplus
}
#endif

#endif /* COUNTER_H */