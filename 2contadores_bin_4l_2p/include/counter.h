#ifndef COUNTER_H
#define COUNTER_H

#ifdef __cplusplus
extern "C" {
#endif

// ====================================================================================================
// Dependencies
// ====================================================================================================


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
} contadorled_t;


// ====================================================================================================
// Public function definitions
// ====================================================================================================
/**
 * @brief Initializes a counter structure.
 * 
 * @param[in, out] p_self   Points to the counter's data structure.
 * @param[in] l1           Counter led 1.        
 * @param[in] l2          Counter led 2.
 * @param[in] l3          Counter led 3.
 * @param[in] l4           Counter led 4.
 */
static inline void
init_contador_led(contadorled_t * p_self, unsigned char l1, unsigned char l2, unsigned char l3, unsigned char l4)
{
    p_self->led1 = l1;
    p_self->led2 = l2;
    p_self->led3 = l3;
    p_self->led4 = l4;

    pinMode(p_self->led1,OUTPUT);
    pinMode(p_self->led2,OUTPUT);
    pinMode(p_self->led3,OUTPUT);
    pinMode(p_self->led4,OUTPUT);
}

// ====================================================================================================
// Public function prototypes
// ====================================================================================================
/**
 * @brief Show the value of the counter into leds
 * 
 * @param[in] p_self  Points to the counter_led structure.
 * @param[in] numero Set the value of the counter that will show
 */
void
mostrar_contador(contadorled_t * p_self, int numero);


#ifdef __cplusplus
}
#endif

#endif /* COUNTER_H */