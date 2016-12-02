
#include <VirtualWire.h>
int ledpin =  9 ; 

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);    // Debugging only
    Serial.println("setup");
    // Initialise the IO and ISR
    vw_setup(2000);  // Bits per sec
    vw_set_tx_pin(3);
    pinMode( ledpin,INPUT);
     digitalWrite(ledpin,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
char *msg2;
  
  if(digitalRead(ledpin) == LOW)//if the forward button is pressed
  {
    char *msg2 = "1";//send 1 to the receiver
    digitalWrite(13, true); // Flash a light to show transmitting
    vw_send((uint8_t *)msg2, strlen(msg2));//send the byte to the receiver
    vw_wait_tx(); // Wait until the whole message is gone
    digitalWrite(13, false);
  }
  
}
