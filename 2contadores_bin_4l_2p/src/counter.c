#include "counter.h"

// ====================================================================================================
// Private variables
// ====================================================================================================
static int leds[4];

// ====================================================================================================
// Private functions
// ====================================================================================================


// ====================================================================================================
// Public function definitions
// ====================================================================================================
void
mostrar_contador(contadorled_t * p_self, int numero)
{
   for (int i = 0; i < 5; i++)
   {
    leds[i] = bitRead(numero,i);
   }
   digitalWritte(p_self->led1,leds[0]);
   digitalWritte(p_self->led2,leds[1]);
   digitalWritte(p_self->led3,leds[2]);
   digitalWritte(p_self->led4,leds[3]);
}
