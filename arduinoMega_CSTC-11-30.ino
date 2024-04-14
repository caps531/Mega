#include <Servo.h>
#define trigPin1 2
#define echoPin1 3
#define trigPin2 4
#define echoPin2 5
#define trigPin3 6
#define echoPin3 7

Servo myservo1;
Servo myservo25;
int tin=0;
int alum=0;
int plas=0;
int plas15=0;
int reset=0;
int tinCost = 0;//price
int alumCost = 0;//price
int plasCost = 0;//price
int plasCost15 = 0;//pricce
int switchStatetin = 0;
int switchStatealum = 0;
int switchStateplas = 0;
int switchStateplas15 = 0;
float pulseCounttin = 1.0;
float pulseCountalum = 1.0;
float pulseCountplas = 0.25;
float pulseCountplas15 = 1.0;
int prevStatetin = 0;
int prevStatealum = 0;
int prevStateplas = 0;
int prevStateplas15 = 0;

long duration, distance, tinBin,alumBin,petBin;
void setup() {
  Serial.begin(9600);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  pinMode(13, INPUT_PULLUP);
  pinMode(21, INPUT_PULLUP);
  myservo1.attach(9);
  myservo25.attach(8);
  myservo1.write(0);
  myservo25.write(0);
  pinMode(22, INPUT_PULLUP);//tin
  pinMode(24, INPUT_PULLUP);//alum
  pinMode(26, INPUT_PULLUP);//pet
  pinMode(28, INPUT_PULLUP);//pet15
  pinMode(14, OUTPUT);//for tin counting
  pinMode(15, OUTPUT);// for aluminum counting
  pinMode(16, OUTPUT);//for PET counting
  pinMode(17, OUTPUT);//for PET15 counting
  pinMode(18, OUTPUT);//tinbin level notif
  pinMode(19, OUTPUT);//alumbin level notif
  pinMode(20, OUTPUT);//petbin level notif
   pinMode(30, OUTPUT);
    pinMode(32, OUTPUT);
     pinMode(34, OUTPUT);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  digitalWrite(14, HIGH);
  digitalWrite(15, HIGH);
  digitalWrite(16, HIGH);
  digitalWrite(17, HIGH);
  digitalWrite(18, HIGH);
  digitalWrite(19, HIGH);
  digitalWrite(20, HIGH);
  digitalWrite(30, HIGH);
  digitalWrite(32, HIGH);
  digitalWrite(34, HIGH);
  delay(10);
}

void loop() {
  Serial.begin(9600);
SonarSensor(trigPin1, echoPin1);
tinBin = distance;
SonarSensor(trigPin2, echoPin2);
alumBin = distance;
SonarSensor(trigPin3, echoPin3);
petBin = distance;
  reset=digitalRead(21); //reset pin
   tinCost=digitalRead(10);
  alumCost=digitalRead(11);
  plasCost=digitalRead(12);
  plasCost15=digitalRead(13);
  
  
  switchStatetin = digitalRead(tinCost);
  switchStatealum = digitalRead(alumCost);
  switchStateplas = digitalRead(plasCost);
  switchStateplas15 = digitalRead(plasCost15);
  tin=digitalRead(22);
  alum=digitalRead(24);
  plas=digitalRead(26);
  plas15=digitalRead(28);
  

  if (tinCost==LOW) {
     
       pulseCounttin = pulseCounttin + 0.25;
  }
   tinCost=HIGH;

 if (alumCost==LOW) {
     
       pulseCountalum = pulseCountalum + 0.25;
  }
   alumCost=HIGH;
    
 if (plasCost==LOW) {
     
       pulseCountplas = pulseCountplas + 0.25;
  }
   plasCost=HIGH;

   if (plasCost15==LOW) {
     
       pulseCountplas15 = pulseCountplas15 + 0.25;
  }
   plasCost15=HIGH;
   
   
 Serial.println("PET");
 Serial.println(pulseCountplas);
 Serial.println("PET 1.5");
 Serial.println(pulseCountplas15);
 Serial.println("alum");
  Serial.println(pulseCountalum);
 Serial.println( "tin");
 Serial.println( pulseCounttin);
 
  if ((tin==LOW)&&(pulseCounttin==1.0)){
  digitalWrite(14, HIGH);
  digitalWrite(15, HIGH);
  digitalWrite(16, LOW);
  Serial.println("tin P1");
    myservo1.write(90);
    delay(7000);
  digitalWrite(14, HIGH);
  digitalWrite(15, HIGH);
  digitalWrite(16, HIGH);
    myservo1.write(0);
    delay(1000);
  }

  if ((tin==LOW)&&(pulseCounttin==1.25)){
      digitalWrite(14, HIGH);
  digitalWrite(15, HIGH);
  digitalWrite(16, LOW);
    myservo1.write(90);
    myservo25.write(90);
    delay(1000);
  digitalWrite(14, HIGH);
  digitalWrite(15, HIGH);
  digitalWrite(16, HIGH);
    myservo1.write(0);
    myservo25.write(0);
    delay(1000);
  }
    if ((tin==LOW)&&(pulseCounttin==1.50)){
     digitalWrite(14, HIGH);
  digitalWrite(15, HIGH);
  digitalWrite(16, LOW);
    myservo1.write(90);
    myservo25.write(90);
    delay(1000);
     digitalWrite(14, HIGH);
  digitalWrite(15, HIGH);
  digitalWrite(16, HIGH);
    myservo1.write(0);
    myservo25.write(0);
    delay(1000);
    myservo25.write(90);
    delay(1000);
    myservo25.write(0);
    delay(1000);
  }
    
    if ((tin==LOW)&&(pulseCounttin==1.75)){
     digitalWrite(14, HIGH);
  digitalWrite(15, HIGH);
  digitalWrite(16, LOW);
    myservo1.write(90);
    myservo25.write(90);
    delay(1000);
    digitalWrite(14, HIGH);
  digitalWrite(15, HIGH);
  digitalWrite(16, HIGH);
    myservo1.write(0);
    myservo25.write(0);
    delay(1000);
    myservo25.write(90);
    delay(1000);
    myservo25.write(0);
    delay(1000);
     myservo25.write(90);
    delay(1000);
    myservo25.write(0);
    delay(1000);
  }
    

   if ((tin==LOW)&&(pulseCounttin==2.0)){
     digitalWrite(14, HIGH);
  digitalWrite(15, HIGH);
  digitalWrite(16, LOW);
    myservo1.write(90);
    delay(1000);
  digitalWrite(14, HIGH);
  digitalWrite(15, HIGH);
  digitalWrite(16, HIGH);
    myservo1.write(0);
    delay(1000);
    myservo1.write(90);
    delay(1000);
    myservo1.write(0);
    delay(1000);
  }  

   if ((alum==LOW)&&(pulseCountalum==1.0)){
     digitalWrite(14, LOW);
  digitalWrite(15, LOW);
  digitalWrite(16, HIGH);
    myservo1.write(90);
    Serial.println("alum 1");
    delay(7000);
     digitalWrite(14, HIGH);
    digitalWrite(15, HIGH);
    digitalWrite(16, HIGH);
    myservo1.write(0);
    delay(1000);
    
  }

   if ((alum==LOW)&&(pulseCountalum==1.25)){
       digitalWrite(14, LOW);
  digitalWrite(15, LOW);
  digitalWrite(16, HIGH);
    myservo1.write(90);
    myservo25.write(90);
    delay(1000);
    digitalWrite(14, HIGH);
  digitalWrite(15, HIGH);
  digitalWrite(16, HIGH);
    myservo1.write(0);
    myservo25.write(0);
    delay(1000);
    
  }

   if ((alum==LOW)&&(pulseCountalum==1.50)){
       digitalWrite(14, LOW);
  digitalWrite(15, LOW);
  digitalWrite(16, HIGH);
    myservo1.write(90);
    myservo25.write(90);
    delay(1000);
    digitalWrite(14, HIGH);
  digitalWrite(15, HIGH);
  digitalWrite(16, HIGH);
    myservo1.write(0);
    myservo25.write(0);
    delay(1000);
    myservo25.write(90);
    delay(1000);
    myservo25.write(0);
    delay(1000);
    
  }

   if ((alum==LOW)&&(pulseCountalum==1.75)){
       digitalWrite(14, LOW);
  digitalWrite(15, LOW);
  digitalWrite(16, HIGH);
    myservo1.write(90);
    myservo25.write(90);
    delay(1000);
    digitalWrite(14, HIGH);
  digitalWrite(15, HIGH);
  digitalWrite(16, HIGH);
    myservo1.write(0);
    myservo25.write(0);
    delay(1000);
    myservo25.write(90);
    delay(1000);
    myservo25.write(0);
    delay(1000);
    myservo25.write(90);
    delay(1000);
    myservo25.write(0);
    delay(1000);
    
  }

  if ((alum==LOW)&&(pulseCountalum==2.0)){
       digitalWrite(14, LOW);
  digitalWrite(15, LOW);
  digitalWrite(16, HIGH);
    myservo1.write(90);
    delay(1000);
    digitalWrite(14, HIGH);
  digitalWrite(15, HIGH);
  digitalWrite(16, HIGH);
    myservo1.write(0);
    delay(1000);
     myservo1.write(90);
    delay(1000);
    myservo1.write(0);
    delay(1000);
    
  }
    if ((plas==LOW)&&(pulseCountplas==0.25)){
     digitalWrite(14, LOW);
  digitalWrite(15, HIGH);
  digitalWrite(16, HIGH);
    myservo25.write(90);
    Serial.println("PET 0.25");
    delay(7000);
  digitalWrite(14, HIGH);
  digitalWrite(15, HIGH);
  digitalWrite(16, HIGH);
     myservo25.write(0);
    delay(1000);
    }
 if ((plas==LOW)&&(pulseCountplas==0.50)){
     digitalWrite(14, LOW);
  digitalWrite(15, HIGH);
  digitalWrite(16, HIGH);
    myservo25.write(90);
    delay(1000);
    digitalWrite(14, HIGH);
  digitalWrite(15, HIGH);
  digitalWrite(16, HIGH);
     myservo25.write(0);
    delay(1000);
    myservo25.write(90);
    delay(1000);
     myservo25.write(0);
    delay(1000);
    }   
if ((plas==LOW)&&(pulseCountplas==0.75)){
     digitalWrite(14, LOW);
  digitalWrite(15, HIGH);
  digitalWrite(16, HIGH);
    myservo25.write(90);
    delay(1000);
    digitalWrite(16, HIGH);
     myservo25.write(0);
    delay(1000);
    myservo25.write(90);
    delay(1000);
     myservo25.write(0);
    delay(1000);
     myservo25.write(90);
    delay(1000);
     myservo25.write(0);
    delay(1000);
    }
    if ((plas==LOW)&&(pulseCountplas==1.0)){
     digitalWrite(14, LOW);
  digitalWrite(15, HIGH);
  digitalWrite(16, HIGH);
    myservo1.write(90);
    delay(1000);
    digitalWrite(14, HIGH);
  digitalWrite(15, HIGH);
  digitalWrite(16, HIGH);
    myservo1.write(0);
    delay(1000);
    }

     if ((plas==LOW)&&(pulseCountplas==1.25)){
     digitalWrite(14, LOW);
  digitalWrite(15, HIGH);
  digitalWrite(16, HIGH);
    myservo1.write(90);
    myservo25.write(90);
    delay(1000);
    digitalWrite(14, HIGH);
  digitalWrite(15, HIGH);
  digitalWrite(16, HIGH);
    myservo1.write(0);
     myservo25.write(0);
    delay(1000);
    }

    if ((plas==LOW)&&(pulseCountplas==1.50)){
    digitalWrite(14, LOW);
  digitalWrite(15, HIGH);
  digitalWrite(16, HIGH);
    myservo1.write(90);
    myservo25.write(90);
    delay(1000);
    digitalWrite(14, HIGH);
  digitalWrite(15, HIGH);
  digitalWrite(16, HIGH);
    myservo1.write(0);
     myservo25.write(0);
    delay(1000);
    myservo25.write(90);
    delay(1000);
     myservo25.write(0);
    delay(1000);
    }

    
    if ((plas==LOW)&&(pulseCountplas==1.75)){
     digitalWrite(14, LOW);
  digitalWrite(15, HIGH);
  digitalWrite(16, HIGH);
    myservo1.write(90);
    myservo25.write(90);
    delay(1000);
    digitalWrite(14, HIGH);
  digitalWrite(15, HIGH);
  digitalWrite(16, HIGH);
    myservo1.write(0);
     myservo25.write(0);
    delay(1000);
    myservo25.write(90);
    delay(1000);
     myservo25.write(0);
    delay(1000);
     myservo25.write(90);
    delay(1000);
     myservo25.write(0);
    delay(1000);
    }
if ((plas==LOW)&&(pulseCountplas==2.0)){
     digitalWrite(14, LOW);
  digitalWrite(15, HIGH);
  digitalWrite(16, HIGH);
    myservo1.write(90);
    delay(1000);
    digitalWrite(14, HIGH);
  digitalWrite(15, HIGH);
  digitalWrite(16, HIGH);
    myservo1.write(0);
    delay(1000);
    myservo1.write(90);
    delay(1000);
     myservo1.write(0);
    delay(1000);
}

  if ((plas15==LOW)&&(pulseCountplas15==1.0)){
     digitalWrite(14, HIGH);
  digitalWrite(15, LOW);
  digitalWrite(16, HIGH);
    myservo1.write(90);
    Serial.println("PET 1");
    delay(7000);
    digitalWrite(14, HIGH);
  digitalWrite(15, HIGH);
  digitalWrite(16, HIGH);
    myservo1.write(0);
    delay(1000);
    }

     if ((plas15==LOW)&&(pulseCountplas15==1.25)){
    digitalWrite(14, HIGH);
  digitalWrite(15, LOW);
  digitalWrite(16, HIGH);
    myservo1.write(90);
    myservo25.write(90);
    delay(1000);
  digitalWrite(14, HIGH);
  digitalWrite(15, HIGH);
  digitalWrite(16, HIGH);
    myservo1.write(0);
     myservo25.write(0);
    delay(1000);
    }

    if ((plas15==LOW)&&(pulseCountplas15==1.50)){
    digitalWrite(14, HIGH);
  digitalWrite(15, LOW);
  digitalWrite(16, HIGH);
    myservo1.write(90);
    myservo25.write(90);
    delay(1000);
  digitalWrite(14, HIGH);
  digitalWrite(15, HIGH);
  digitalWrite(16, HIGH);
    myservo1.write(0);
     myservo25.write(0);
    delay(1000);
    myservo25.write(90);
    delay(1000);
     myservo25.write(0);
    delay(1000);
    }

    
    if ((plas15==LOW)&&(pulseCountplas15==1.75)){
    digitalWrite(14, HIGH);
  digitalWrite(15, LOW);
  digitalWrite(16, HIGH);
    myservo1.write(90);
    myservo25.write(90);
    delay(1000);
  digitalWrite(14, HIGH);
  digitalWrite(15, HIGH);
  digitalWrite(16, HIGH);
    myservo1.write(0);
     myservo25.write(0);
    delay(1000);
    myservo25.write(90);
    delay(1000);
     myservo25.write(0);
    delay(1000);
     myservo25.write(90);
    delay(1000);
     myservo25.write(0);
    delay(1000);
    }
if ((plas15==LOW)&&(pulseCountplas15==2.0)){
    digitalWrite(14, HIGH);
  digitalWrite(15, LOW);
  digitalWrite(16, HIGH);
    myservo1.write(90);
    delay(1000);
    digitalWrite(14, HIGH);
  digitalWrite(15, HIGH);
  digitalWrite(16, HIGH);
    myservo1.write(0);
    delay(1000);
    myservo1.write(90);
    delay(1000);
     myservo1.write(0);
    delay(1000);
}

if (tinBin<10){
    digitalWrite(18, LOW);
    digitalWrite(30, LOW);
    delay(1);
}
if (tinBin>10){
    digitalWrite(18, HIGH);
    digitalWrite(30, HIGH);
    delay(1);
}

if (alumBin<10){
    digitalWrite(19, LOW);
    digitalWrite(32, LOW);
    delay(1);
}
if (alumBin>10){
    digitalWrite(19, HIGH);
    digitalWrite(32, HIGH);
    delay(1);
}

if (petBin<10){
    digitalWrite(20, LOW);
    digitalWrite(34, LOW);
    delay(1);
}
if (petBin>10){
    digitalWrite(20, HIGH);
    digitalWrite(34, HIGH);
    delay(1);
}

if (reset==LOW){
pulseCounttin = 1.0;
pulseCountalum = 1.0;
pulseCountplas = 0.25;
pulseCountplas15 = 1.0;
}

    delay(500);
}    
   void SonarSensor(int trigPin,int echoPin)
{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;

} 


