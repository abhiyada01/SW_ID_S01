#include <Arduino.h>
#include <Arduino_FreeRTOS.h>

void Task_Print1(void *param);
void Task_Print2(void *param);

TaskHandle_t Task_Handl1;
TaskHandle_t Task_Handl2;

void setup(){
  Serial.begin(9600);
  pinMode(A0, OUTPUT);
    pinMode(A5, OUTPUT);
  xTaskCreate(Task_Print1, "Task1", 100, NULL, 1, &Task_Handl1);
    xTaskCreate(Task_Print2, "Task2", 100, NULL, 2, &Task_Handl2);
}

void loop(){


}

void Task_Print1(void *param){
  (void) param;
  while(1){
digitalWrite(A0, HIGH);
vTaskDelay(100/portTICK_PERIOD_MS);
digitalWrite(A0, LOW);
vTaskDelay(100/portTICK_PERIOD_MS);
  }

}

void Task_Print2(void *param){
  (void) param;
  while(1){
    digitalWrite(A5, HIGH);
    vTaskDelay(1000/portTICK_PERIOD_MS);
    digitalWrite(A5, LOW);
    vTaskDelay(1000/portTICK_PERIOD_MS);
  }
}
