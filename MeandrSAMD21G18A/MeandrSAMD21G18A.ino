//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// генератор сигнала 50 Гц на трёх каналах со сдвигом фаз в 120 градусов
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include "CorePinScenario.h"
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define DURATION 9875 // мкс между состояниями дадут нам меандр с частотой, близкой к 50 Гц
#define PHASE_SHIFT (DURATION/3) // сдвиг угла одной фазы относительно другой
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define LINE1 A4 // номер пина для линии 1
#define LINE2 A3 // номер пина для линии 2
#define LINE3 A2 // номер пина для линии 3
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
CorePinScenario scene1;
CorePinScenario scene2;
CorePinScenario scene3;
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void setup() 
{
  //scene1.add({LINE1,HIGH,200});
   scene1.add({LINE1,HIGH,DURATION}); 
  scene1.add({LINE1,LOW,DURATION});
 

  scene2.add({LINE2,HIGH,DURATION});
  scene2.add({LINE2,LOW,DURATION});

  scene3.add({LINE3,HIGH,DURATION});
  scene3.add({LINE3,LOW,DURATION});
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void loop() 
{

  // сдвигаем фазы при старте

  delay(1);
  scene1.update();
  delayMicroseconds(PHASE_SHIFT);
  scene2.update();
  delayMicroseconds(PHASE_SHIFT);
  scene3.update();
  
  while(1)
  {
    scene1.update();
    scene2.update();
    scene3.update();
  }

}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------

