//defining pins for sensor
int trigPin = 13;   
int echoPin = 12; //use analog

int trigPin2 = 4;   //15 is the output
int echoPin2 = 5;

void setup() {
  // put your setup code here, to run once:

    Serial.begin(9600); //Start Serial Terminal
    pinMode(trigPin,OUTPUT);
    pinMode(echoPin,INPUT);

    pinMode(trigPin2,OUTPUT);
    pinMode(echoPin2,INPUT);
    
}

void loop() {
    // put your main code here, to run repeatedly:
    /*digitalWrite(digi1,HIGH);
    delay(3000);
    analogWrite(ana1,200);
    */
    long duration, inches, cm;
   
    digitalWrite(trigPin,LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin,HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin,LOW);

    duration = pulseIn(echoPin,HIGH);
    inches = msti(duration);
    cm = mstc(duration);
    
/*
    if(cm>5 && cm<10){
      Serial.print("Blink the LED     ");
      digitalWrite(digi1,HIGH);
      digitalWrite(digi2,LOW);
      delay(100);
    }
    else if(cm<5){
      Serial.print("Blink the LED     ");
      digitalWrite(digi1,LOW);
      digitalWrite(digi2,HIGH);
      delay(100);
    }
    else{
      digitalWrite(digi1,HIGH);
      digitalWrite(digi2,HIGH);
      delay(100);
    }
 */
    Serial.print("Sensor 1: ");
    Serial.print(cm);
    Serial.print(" cm");
    delay(50);
    
    digitalWrite(trigPin2,LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin2,HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin2,LOW);

    duration = pulseIn(echoPin2,HIGH);
    inches = msti(duration);
    cm = mstc(duration);
    
    Serial.print("   Sensor 2: ");
    Serial.print(cm);
    Serial.print(" cm");
    Serial.println();

    delay(50);
}

long msti(long ms){
  return ms /74 /2;
}

long mstc(long ms){
  return ms /29 /2;
}

float msti(float ms){
  return ms /74 /2;
}

float mstc(float ms){
  return ms /29/2;
}
