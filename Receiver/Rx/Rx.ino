//Receiver Code (Hand) - Mert Arduino and Tech

#include <Servo.h>        //SERVO LIBRARY
#include <SPI.h>      
#include "RF24.h"         //NRF24L01 LIBRARY
#include <nRF24L01.h> 


Servo Servo1;
Servo Servo2;
Servo Servo3;

RF24 radio(9,10);     

const uint64_t pipe = 0xE8E8F0F0E1LL;       //NRF24L01 ADDRESS/PASSWORD

int msg[2];

void setup(){

  //DEFINE OUTPUTS

  pinMode(5, OUTPUT);
  Servo1.attach(15);                //A1
  Servo2.attach(16);                //A2
  Servo3.attach(17);                //A3
  
  
  //SERVO VALUES
  Servo1.write(0);                  //A1
  Servo2.write(0);                  //A2
  Servo3.write(175);                //A3
    delay(2000);

Serial.begin(9600);
radio.begin();                    
radio.openReadingPipe(1, pipe);   
radio.startListening();           

  }


void loop(){
  if (radio.available()){
    radio.read(msg, sizeof(msg));
    Servo1.write(msg[0]);                 //A1
    Servo2.write(msg[1]);                 //A2
    Servo3.write(175-msg[1]);             //A3
    delay(100);
 
    }  
  }
 




