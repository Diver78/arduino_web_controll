#include <Servo.h> 
 
Servo myservo;

void setup() {
  Serial.begin(9600);
}

String getParam(){
	String re;
	while (Serial.available()) {
		re.concat(Serial.read()-48);
	}
	return re;
}

int getPin(String p){
  	return p.substring(0,2).toInt();
}

int getVal(String p){
  	return p.substring(2,6).toInt();
}

// Главный цикл
void loop() {
	while (Serial.available()) {
		char command = (char)Serial.read();
		String param = getParam();
		int pin = getPin(param);
		int p;
		switch (command) {
			case '0':
				pinMode(pin,OUTPUT);
				digitalWrite(pin, LOW);
		      	break;
		    case '1':
				pinMode(pin,OUTPUT);
				digitalWrite(pin, HIGH);
		      	break;
		    case '2':
				myservo.attach(pin);
				p = getVal(param);
				myservo.write(p);
		      	break;
		    case '3':
				pinMode(pin,INPUT);
				Serial.print(digitalRead(pin));
		      	break;
		    case '4': {
		    	int aPin = A0;
		    	switch (pin) {
		    		case 1: aPin = A1;	break;
		    		case 2: aPin = A2;	break;
		    		case 3: aPin = A3;	break;
		    		case 4: aPin = A4;	break;
		    		case 5: aPin = A5;	break;
		    		}
				Serial.print(analogRead(aPin));
				}
		      	break;
		    case '5':
				pinMode(pin,OUTPUT);
				p = getVal(param);
				analogWrite(pin, p);
		      	break;
		}
	}
}
