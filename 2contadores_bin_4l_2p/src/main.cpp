#include <Arduino.h>

#define EXAMPLE 1   // seleccionar el ejemplo

// ====================================================================================================
// Ejemplo 1: "multithreading" con protothreads
// ----------------------------------------------------------------------------------------------------
#if EXAMPLE == 1
// ====================================================================================================
#include <pt.h>

#define LED1_PIN    (9)
#define LED2_PIN    (10)
#define LED3_PIN    (11)
#define BUTTON_PIN  (5)

// Estructuras de datos para los protothreads
static struct pt pt1, pt2, pt3;

// El primer protothread debe hacer parpadear al LED1 cada 1 segundo
static int 
blink_led1_thread(struct pt *pt)
{
  static unsigned long last_time_blink = 0;
  PT_BEGIN(pt);
  while(1) 
  {
    last_time_blink = millis();
    PT_YIELD_UNTIL(pt, millis() - last_time_blink > 1000);
    digitalWrite(LED1_PIN, HIGH);
    last_time_blink = millis();
    PT_YIELD_UNTIL(pt, millis() - last_time_blink > 1000);
    digitalWrite(LED1_PIN, LOW);
  }
  PT_END(pt);
}

// El segundo protothread debe hacer parpadear al LED2 cada 0.5 segundos
static int 
blink_led2_thread(struct pt *pt)
{
  static unsigned long last_time_blink = 0;
  PT_BEGIN(pt);
  while(1) 
  {
    last_time_blink = millis();
    PT_YIELD_UNTIL(pt, millis() - last_time_blink > 500);
    digitalWrite(LED2_PIN, HIGH);
    last_time_blink = millis();
    PT_YIELD_UNTIL(pt, millis() - last_time_blink > 500);
    digitalWrite(LED2_PIN, LOW);
  }
  PT_END(pt);
}

// El tercer protothread enciende el LED3 si se presionó el push button
static int 
push_button_thread(struct pt *pt)
{
  static unsigned long last_time_check = 0;
  PT_BEGIN(pt);
  while(1) 
  {
    last_time_check = millis();
    PT_YIELD_UNTIL(pt, digitalRead(BUTTON_PIN) == HIGH);
    digitalWrite(LED3_PIN, HIGH);
    PT_YIELD_UNTIL(pt, digitalRead(BUTTON_PIN) == LOW);
    digitalWrite(LED3_PIN, LOW);
  }
  PT_END(pt);
}

// En el setup se colocan todos los LEDs como OUTPUTS, el botón como
// INPUT y se inicializan todos los protothreads
void 
setup() 
{
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  pinMode(LED3_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  PT_INIT(&pt1);
  PT_INIT(&pt2);
  PT_INIT(&pt3);
}

// En el ciclo principal basta con llamar a los protothreads
void 
loop() 
{
  PT_SCHEDULE(blink_led1_thread(&pt1));
  PT_SCHEDULE(blink_led2_thread(&pt2));
  PT_SCHEDULE(push_button_thread(&pt3));
}
// ----------------------------------------------------------------------------------------------------
#endif
// ====================================================================================================


// ====================================================================================================
// Ejemplo 2: programación orientada a objetos
// ----------------------------------------------------------------------------------------------------
#if EXAMPLE == 2
// ====================================================================================================
#include "room.h"

room_t kitchen;

void 
setup()
{
  Serial.begin(9600);
  room_init_data(&kitchen, 2.5, 3.5, 2);
}


void
loop()
{
  Serial.print("Area: ");
  Serial.println(room_calculate_area(&kitchen));
  Serial.print("Volume: ");
  Serial.println(room_calculate_volume(&kitchen));
  delay(1000);
}

// ----------------------------------------------------------------------------------------------------
#endif
// ====================================================================================================