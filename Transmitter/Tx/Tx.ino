#include <SPI.h>                     
#include "RF24.h"                    
#include <nRF24L01.h>

int msg[2]; 

//DEFINE INPUT PIN

int flex_2 = A2;
int flex_1 = A1;

int flex_2_val;
int flex_1_val;

RF24 radio(9,10);                  
                                      
const uint64_t pipe = 0xE8E8F0F0E1LL;     //NRF24L01 ADDRESS/PASSWORD


void setup(void){
  Serial.begin(9600);                     //START SERIAL PORT
  radio.begin();                          //START NRF24L01
  radio.openWritingPipe(pipe);        
}

void loop(void){
 
  flex_2_val = analogRead(flex_2);

  flex_2_val = map(flex_2_val, 520, 780, 90, 175);
  
  flex_1_val = analogRead(flex_1);

  flex_1_val = map(flex_1_val, 480, 700, 90, 175);
  if (flex_2_val>175)
 { flex_2_val=175;
  }
    if (flex_2_val<=90)
 { flex_2_val=0;
  }

    if (flex_1_val>175)
 { flex_1_val=175;
  }
    if (flex_1_val<=90)
 { flex_1_val=0;
  }
 
  msg[1] = flex_2_val;
  msg[0] = flex_1_val;
  
  
  radio.write(&msg, sizeof(msg));
  Serial.println(msg[0]);
  Serial.println(msg[1]);
  delay(100);
}
