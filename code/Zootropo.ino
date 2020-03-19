const int controlPin1 =2;  // We define our pins
const int controlPin2 =3;
const int enablePin =9;
const int  directionSwitchPin =4;
const int onOffSwitchStateSwitchPin=5;
const int potPin = A0;
const int LedPin = 1;
const int pinLedR=13; //LED RED 
const int pinLedG=12; //LED GREEN 
const int pinLedB=11; //LED BLUE 
int onOffSwitchState =0;  // We define our variables
int previousOnOffSwitchState = 0;
int directionSwitchState = 0;
int previousDirectionSwitchState = 0;
int motorEnabled=0;
int motorSpeed=0;
int motorDirection=1;
int i=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(directionSwitchPin, INPUT);  // We define if our pins are OUTPUT or INPUT
  pinMode(onOffSwitchStateSwitchPin, INPUT);
  pinMode(controlPin1,OUTPUT);
  pinMode(controlPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);
  digitalWrite(enablePin, LOW);
  pinMode(LedPin, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:  
  onOffSwitchState = digitalRead(onOffSwitchStateSwitchPin); // To save if the motor is ON or OFF
  delay(1);
  directionSwitchState = digitalRead(directionSwitchPin);  // To save if the direction is 0 or 1. Depends if the button is pulsed or not
  motorSpeed = analogRead(potPin)/16;  // Defines the speed of the motor. We use /16 to avoid too much speed
  if(onOffSwitchState != previousOnOffSwitchState) // If the ON/OFF state has changed, it will enter this loop
  {
    if(onOffSwitchState == HIGH)  //If the button is pulsed
    {
      motorEnabled = !motorEnabled;  // Changes the motor from ON to OFF or from OFF to ON
    }
  }
  if (directionSwitchState != previousDirectionSwitchState) // If the direction has changed
  {
  if (directionSwitchState == HIGH) // If the button is pulsed
  {
    motorDirection = !motorDirection; // Changes the motor direction
    }
  }
  if (motorDirection == 1) // If the motor is 1 (one of the directions)
  {
    digitalWrite(controlPin1, HIGH); 
    digitalWrite(controlPin2, LOW); // We say to the motor to rotate in a certain direction
  }
  else {
    digitalWrite(controlPin1, LOW);
    digitalWrite(controlPin2, HIGH); // We say to the motor to rotate in the other direction
  }

  if (motorEnabled == 1) // If the motor is enabled
  {
    analogWrite(enablePin, motorSpeed); // We make the motor rotate at a certain speed that we have defined previously
  }
   else 
   {
    analogWrite(enablePin, 0);  // We stop the motor
  }
  previousDirectionSwitchState = directionSwitchState; // We change the values to adapt them to the actual reality
  previousOnOffSwitchState = onOffSwitchState;
    // We say to the Led to be Red
    digitalWrite(pinLedR, HIGH); 
    digitalWrite(pinLedG, LOW);    
    digitalWrite(pinLedB, LOW);  

    if (motorEnabled==1) // In case that the motor is rotating, we say to the Led to be Green
    {
          digitalWrite(pinLedR, LOW); //green   
          digitalWrite(pinLedG, HIGH);    
          digitalWrite(pinLedB, LOW);           
    }
  }
