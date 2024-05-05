#define dirPin1 52 /* Z-Axis*/
#define stepPin1 53 /* Z-Axis*/
#define dirPin2 44 /* Z-Axis*/
#define stepPin2 45 /* Z-Axis*/
#define stepsPerRevolution 1600
const int BUTTON_PIN3 = 3; /* Z-Axis*/
const int BUTTON_PIN2 = 2; /* Z-Axis*/
int lastState3 = HIGH; /* Z-Axis*/
int lastState2 = HIGH; /* Z-Axis*/
int currentState3; /* Z-Axis*/
int currentState2; /* Z-Axis*/

#define dirPin3 50 /* X-Axis*/
#define stepPin3 51 /* X-Axis*/
#define dirPin4 46 /* X-Axis*/
#define stepPin4 47 /* X-Axis*/
const int BUTTON_PIN5 = 5; /* X-Axis*/
const int BUTTON_PIN4 = 4; /* X-Axis*/
int lastState5 = HIGH; /* X-Axis*/
int lastState4 = HIGH; /* X-Axis*/
int currentState5; /* X-Axis*/
int currentState4; /* X-Axis*/

#define dirPin5 48 /* Y-Axis*/
#define stepPin5 49 /* Y-Axis*/
const int BUTTON_PIN7 = 7; /* Y-Axis*/
const int BUTTON_PIN6 = 6; /* Y-Axis*/
int lastState7 = HIGH; /* Y-Axis*/
int lastState6 = HIGH; /* Y-Axis*/
int currentState7; /* Y-Axis*/
int currentState6; /* Y-Axis*/





void setup()
{
  Serial.begin(9600);
  pinMode(BUTTON_PIN3, INPUT_PULLUP); /* Z-Axis*/
  pinMode(BUTTON_PIN2, INPUT_PULLUP); /* Z-Axis*/
  pinMode(stepPin1, OUTPUT); /* Z-Axis*/
  pinMode(dirPin1, OUTPUT); /* Z-Axis*/
  pinMode(stepPin2, OUTPUT); /* Z-Axis*/
  pinMode(dirPin2, OUTPUT); /* Z-Axis*/

  pinMode(BUTTON_PIN5, INPUT_PULLUP); /* X-Axis*/
  pinMode(BUTTON_PIN4, INPUT_PULLUP); /* X-Axis*/
  pinMode(stepPin3, OUTPUT); /* X-Axis*/
  pinMode(dirPin3, OUTPUT); /* X-Axis*/
  pinMode(stepPin4, OUTPUT); /* X-Axis*/
  pinMode(dirPin4, OUTPUT); /* X-Axis*/

  pinMode(BUTTON_PIN7, INPUT_PULLUP); /* X-Axis*/
  pinMode(BUTTON_PIN6, INPUT_PULLUP); /* X-Axis*/
  pinMode(stepPin5, OUTPUT); /* X-Axis*/
  pinMode(dirPin5, OUTPUT); /* X-Axis*/
  


}

void loop() {
  currentState3 = digitalRead(BUTTON_PIN3); /* Z-Axis*/
  currentState2 = digitalRead(BUTTON_PIN2); /* Z-Axis*/
  
  currentState5 = digitalRead(BUTTON_PIN5); /* X-Axis*/
  currentState4 = digitalRead(BUTTON_PIN4); /* X-Axis*/

  currentState7 = digitalRead(BUTTON_PIN7); /* Y-Axis*/
  currentState6 = digitalRead(BUTTON_PIN6); /* Y-Axis*/

  if(lastState2 == HIGH && currentState2 == LOW && currentState3 == HIGH){
    digitalWrite(dirPin1, HIGH);
    digitalWrite(dirPin2, HIGH);
     Serial.println("UP");
      for (int i=0; i < 0.1 * stepsPerRevolution; i++) {
    // These four lines result in 1 step:
        digitalWrite(stepPin1, HIGH);
        digitalWrite(stepPin2, HIGH);
        
        delayMicroseconds(125);
        digitalWrite(stepPin1, LOW);
        digitalWrite(stepPin2, LOW);
      
        delayMicroseconds(125);
    } 

  }

   if(lastState3 == HIGH && currentState3 == LOW && currentState2 == HIGH){
    digitalWrite(dirPin1, LOW);
    digitalWrite(dirPin2, LOW);
     Serial.println("DOWN");
      for (int i=0; i < 0.1 * stepsPerRevolution; i++) {
    // These four lines result in 1 step:
        digitalWrite(stepPin1, HIGH);
        digitalWrite(stepPin2, HIGH);
        
        delayMicroseconds(125);
        digitalWrite(stepPin1, LOW);
        digitalWrite(stepPin2, LOW);
        delayMicroseconds(125);
    }

  }

  if(lastState4 == HIGH && currentState4 == LOW && currentState5 == HIGH){
    digitalWrite(dirPin3, LOW);
    digitalWrite(dirPin4, HIGH);
     Serial.println("FORWARD");
      for (int i=0; i < 0.1 * stepsPerRevolution; i++) {
    // These four lines result in 1 step:
        digitalWrite(stepPin3, HIGH);
        digitalWrite(stepPin4, HIGH);
        
        delayMicroseconds(125);
        digitalWrite(stepPin3, LOW);
        digitalWrite(stepPin4, LOW);
        delayMicroseconds(125);
    }

  }
    
   if(lastState5 == HIGH && currentState5 == LOW && currentState4 == HIGH){
    digitalWrite(dirPin3, HIGH);
    digitalWrite(dirPin4, LOW);
     Serial.println("BACKWARD");
      for (int i=0; i < 0.1 * stepsPerRevolution; i++) {
    // These four lines result in 1 step:
        digitalWrite(stepPin3, HIGH);
        digitalWrite(stepPin4, HIGH);
        
        delayMicroseconds(125);
        digitalWrite(stepPin3, LOW);
        digitalWrite(stepPin4, LOW);
        delayMicroseconds(125);
    }

  }

  if(lastState6 == HIGH && currentState6 == LOW && currentState7 == HIGH){
    digitalWrite(dirPin5, LOW);
     Serial.println("RIGHT");
      for (int i=0; i < 0.1 * stepsPerRevolution; i++) {
    // These four lines result in 1 step:
        digitalWrite(stepPin5, HIGH);
        
        delayMicroseconds(125);
        digitalWrite(stepPin5, LOW);
        delayMicroseconds(125);
    }

  }
    
   if(lastState7 == HIGH && currentState7 == LOW && currentState6 == HIGH){
    digitalWrite(dirPin5, HIGH);
     Serial.println("LEFT");
      for (int i=0; i < 0.1 * stepsPerRevolution; i++) {
    // These four lines result in 1 step:
        digitalWrite(stepPin5, HIGH);
        
        delayMicroseconds(125);
        digitalWrite(stepPin5, LOW);
        delayMicroseconds(125);
    }

  }

    

  
    




  
  
}