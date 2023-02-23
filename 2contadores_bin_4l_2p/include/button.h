#ifndef COUNTER_H
#define COUNTER_H

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
    unsigned char led1;  /**<Led1 for counter */
    unsigned char led2; /**<Led2 for counter */
    unsigned char led3;  /**<Led3 for counter */
    unsigned char led4; /**<Led4 for counter*/
} contador_t;


// ====================================================================================================
// Public function definitions
// ====================================================================================================
/**
 * @brief Initializes a counter structure.
 * 
 * @param[in, out] c_self   Points to the counter's data structure.
 * @param[in] l1           Counter led 1.        
 * @param[in] l2          Counter led 2.
 * @param[in] l3          Counter led 3.
 * @param[in] l4           Counter led 4.
 */
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