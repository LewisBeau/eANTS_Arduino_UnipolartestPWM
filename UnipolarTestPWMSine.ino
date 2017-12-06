
/*
 * 
 * This is the first attempt at driving a unipolar stepper motor using an 
 * Arduino Mega and modified H-Bridge
 * 
 * This versio uses pulse width modulation to introduce a form of microstepping
 * between the phases, with the aim of creating smoother phase transitions (avoiding
 * a "hiccup" during phase changes)
 * 
 * This code is designed for a unipolar (4 lead) microstepper connected to 
 * the following PWM pins:
 * 
 * A1 = 2
 * A2 = 3
 * B1 = 4
 * B2 = 5
 */
//The pins to H-Bridge
const int pinA1 = 2;
const int pinA2 = 3;
const int pinB1 = 4;
const int pinB2 = 5;

//Array containing the current 
const int phaseValues[] = {0, 40, 79, 116, 150, 180, 206, 227, 243, 252, 255};

 //20 normal phases per rotation, 255 steps per phase
const int delayTime = 10;

int valueA1 = 0;  //Between 0 and 10, index in phaseValues array
int valueA2 = 0;
int valueB1 = 0;
int valueB2 = 0;



void setup() {

  /*
   *  * Originally for the non microstepping code
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);  
  pinMode(5, OUTPUT);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  */

  //Default position for pins to avoid illegal motor state
  analogWrite(3, 255);
  analogWrite(4, 0);
  analogWrite(5, 0);
  analogWrite(6, 0);
  
}

void loop() {

  /*
  writeA1();
  delay(delayTime);
  writeB1();
  delay(delayTime);
  writeA2();
  delay(delayTime);
  writeB2();
  delay(delayTime);
  
  
  writeA1();
  delay(500);
  writeA2();
  delay(500);
  */

  for(int i = 0;i < 10;i++){
    decrementA1();
    incrementB1();
    delay(delayTime);
  }
  for(int i = 0;i < 10;i++){
    decrementB1();
    incrementA2();
    delay(delayTime);
  }
  for(int i = 0;i < 10;i++){
    decrementA2();
    incrementB2();
    delay(delayTime);
  }
  for(int i = 0;i < 10;i++){
    decrementB2();
    incrementA1();
    delay(delayTime);
  }
}

//Increase value of phase position 1
void incrementA1(){
  if(valueA1 < 10)valueA1++;
  analogWrite(pinA1, phaseValues[valueA1]);
}
//Increase value of phase position 1
void decrementA1(){
  if(valueA1 > 0)valueA1--;
  analogWrite(pinA1, phaseValues[valueA1]);
}

//Increase value of phase position 2
void incrementA2(){
  if(valueA2 < 10)valueA2++;
  analogWrite(pinA2, phaseValues[valueA2]);
}
//Increase value of phase position 2
void decrementA2(){
  if(valueA2 > 0)valueA2--;
  analogWrite(pinA2, phaseValues[valueA2]);
}

//Increase value of phase position 3
void incrementB1(){
  if(valueB1 < 10)valueB1++;
  analogWrite(pinB1, phaseValues[valueB1]);
}
//Increase value of phase position 3
void decrementB1(){
  if(valueB1 > 0)valueB1--;
  analogWrite(pinB1, phaseValues[valueB1]);
}

//Increase value of phase position 4
void incrementB2(){
  if(valueB2 < 10)valueB2++;
  analogWrite(pinB2, phaseValues[valueB2]);
}
//Increase value of phase position 4
void decrementB2(){
  if(valueB2 > 0)valueB2--;
  analogWrite(pinB2, phaseValues[valueB2]);
}



//Set to phase position 1
void writeA1(){

  analogWrite(2, 0);
  analogWrite(3, 0);
  analogWrite(4, 0);
  analogWrite(5, 0);
  delay(1);
  analogWrite(2, 255);
  analogWrite(3, 0);
  analogWrite(4, 0);
  analogWrite(5, 0);

}

//Set to phase position 2
void writeA2(){

  analogWrite(2, 0);
  analogWrite(3, 0);
  analogWrite(4, 0);
  analogWrite(5, 0);
  delay(1);
  analogWrite(2, 0);
  analogWrite(3, 255);
  analogWrite(4, 0);
  analogWrite(5, 0);

}

//Set to phase position 3
void writeB1(){

  analogWrite(2, 0);
  analogWrite(3, 0);
  analogWrite(4, 0);
  analogWrite(5, 0);
  delay(1);
  analogWrite(2, 0);
  analogWrite(3, 0);
  analogWrite(4, 255);
  analogWrite(5, 0);

}

//Set to phase position 4
void writeB2(){

  analogWrite(2, 0);
  analogWrite(3, 0);
  analogWrite(4, 0);
  analogWrite(5, 0);
  delay(1);
  analogWrite(2, 0);
  analogWrite(3, 0);
  analogWrite(4, 0);
  analogWrite(5, 255);

}


