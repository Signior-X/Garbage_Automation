//defining pins for sensor
int trigPin = 13;   
int echoPin = 12; //For sensor 1

int trigPin2 = 4;   
int echoPin2 = 5; //For sensor 2

int ledpin=16;  //For ledpin
int fl=0;  //use as a flag variable
void setup() {
  // put your setup code here, to run once:

    Serial.begin(9600); //Start Serial Terminal
    pinMode(trigPin,OUTPUT);
    pinMode(echoPin,INPUT);

    pinMode(trigPin2,OUTPUT);
    pinMode(echoPin2,INPUT);

    pinMode(ledpin,OUTPUT);
    
}

void loop() {

    // put your main code here, to run repeatedly:
    fl=0;   //Initially all the bins are empty.

    long duration, inches, cm;
   
    digitalWrite(trigPin,LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin,HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin,LOW);

    duration = pulseIn(echoPin,HIGH);
    inches = msti(duration);
    cm = mstc(duration);
    
    Serial.print("Sensor 1: ");
    Serial.print(cm);
    Serial.print(" cm");
    if(cm<20){
	serial.print("1st Dustbin needs to be cleaned");
	fl=1
    }
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

    if(cm<20){
	serial.print("2nd Dustbin needs to be cleaned");
	fl=1;
    }
    delay(50);

    if(fl==1){
	digitalWrite(ledpin,HIGH);	
    }
    else{
	digitalWrite(ledpin,LOW);
    }

	delay(5000);  //To wait for 5 seconds until next calculation
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
