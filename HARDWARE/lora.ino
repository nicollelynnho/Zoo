#include <SoftwareSerial.h>


#define TRANS 1
#define LEDPIN 7

int incomingByte;

SoftwareSerial reyaxMaster(8, 9); // RX, TX
SoftwareSerial reyaxSlave(10, 11);

void setup() {
  // put your setup code here, to run once:


  reyaxMaster.begin(115200);
  delay(2000);
  reyaxMaster.println("AT+RESET");
  delay(2000);
  reyaxMaster.println("AT+IPR=115200");
  delay(2000);
  reyaxMaster.println("AT+ADDRESS=101");
  delay(2000);
  reyaxMaster.println("AT+NETWORKID=5");
  delay(2000);
  reyaxMaster.println("AT+MODE=1");
  delay(2000);
  reyaxMaster.println("AT+BAND=915000000");
  delay(2000);
  reyaxMaster.println("AT+PARAMETER=10,7,1,7");
  delay(2000);

  reyaxSlave.begin(115200);
  delay(2000);
  reyaxSlave.println("AT+IPR=115200");
  delay(2000);
  reyaxSlave.println("AT+ADDRESS=404");
  delay(2000);
  reyaxSlave.println("AT+NETWORKID=5");
  delay(2000);
  reyaxSlave.println("AT+MODE=1");
  delay(2000);
  reyaxSlave.println("AT+BAND=915000000");
  delay(2000);
  reyaxSlave.println("AT+PARAMETER=10,7,1,7");
  delay(2000);

  Serial.begin(115200);
  delay(2000);
}

String incomingString = "";

void loop() {
  	// Master Lora, send the word "Tests"
	reyaxMaster.println("AT+SEND=404,5,Tests");
	
	delay(3000); // wait 3 agonizing seconds
	if(reyaxSlave.available()){
		incomingString = reyaxSlave.readString();
		Serial.println(incomingString);
	}
	delay(2000);
}


