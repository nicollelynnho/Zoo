#define pin_pwm 5
#define pin_L298_IN1 6	// not referenced, just here for mapping
#define pin_L298_IN2 7	// not referenced, just here for mapping

volatile byte debug, move_state;


void setup(){
	debug = true ;

						// set direction
	DDRD |= 0xE0 ;		// pins 7 through 5 used for motor control on port D

	if(debug){
		Serial.begin(9600);
		Serial.println("starting...");
	}
	delay(1000); // i want this
}

void loop(){
	motor_control(1); // forward
	delay(5000);
	motor_control(0); // turn off
	delay(5000);
	motor_control(2); // backward
	delay(5000);
	motor_control(0); // turn off
	delay(5000);
} // END PROCESSOR LOOP



void motor_control(byte data){
	move_state = data ;

	switch(data){
		case 1: // "forward"
			PORTD = PORTD & 0xBF ;	// set bit 6/pin 6 LOW
			PORTD = PORTD | 0x80 ;	// set bit 7/pin 7 HIGH
			break;

		case 2: // "backward"
			PORTD = PORTD & 0x7F ;	// bit 7/pin 7 LOW 
			PORTD = PORTD | 0x40 ;	// bit 6/pin 6 HIGH
			break;

		default: // off
			PORTD &= 0x3F;
			digitalWrite(pin_pwm, LOW);
			break;
	}

	if(data != 0x0){
		analogWrite(pin_pwm, 180);  // PWM LEFT and RIGHT MOTORS
	}
	else{
		digitalWrite(pin_pwm, LOW);
	}
}


