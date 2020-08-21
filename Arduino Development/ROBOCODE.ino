//Define Pins

int R_ENA = 5; //Enable Pin of the Right Motor (must be PWM)
int IN1 = 6; //Control Pin
int IN2 = 7;

int Threshold = 700; // Sets value for WHITE space 

int L_ENB = 10 ; //Enable Pin of the Left Motor (must be PWM)
int IN3 = 8;
int IN4 = 9;

//Speed of the Motors
#define RIGHTSpeed 255
#define LEFTSpeed 255

int Sensor1pin = A4;
int Sensor2pin = A3;
int Sensor3pin = A2;
int Sensor4pin = A1;
int Sensor5pin = A0;

int Sensor1value = 0;
int Sensor2value = 0;
int Sensor3value = 0;
int Sensor4value = 0;
int Sensor5value = 0;


int Light1 = 8;
int Light2 = 9;
int Light3 = 10;
int Light4 = 11;
int Light5 = 13;


void setup() {
  
  Serial.begin(9600);

  pinMode(R_ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(L_ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(Light1, OUTPUT);
  pinMode(Light2, OUTPUT);
  pinMode(Light3, OUTPUT);
  pinMode(Light4, OUTPUT);
  pinMode(Light5, OUTPUT);

  pinMode(Sensor1pin, INPUT);
  pinMode(Sensor2pin, INPUT);
  pinMode(Sensor3pin, INPUT);
  pinMode(Sensor4pin, INPUT);
  pinMode(Sensor5pin, INPUT);

}

void loop() {
// put your main code here, to run repeatedly:

// Read Sensor Values, Display them on Serial Moniter - WORKS 
  Sensor1value = analogRead(Sensor1pin);
  Sensor2value = analogRead(Sensor2pin);
  Sensor3value = analogRead(Sensor3pin);
  Sensor4value = analogRead(Sensor4pin);
  Sensor5value = analogRead(Sensor5pin);
  Serial.println("Sensor 1:");
  Serial.println(Sensor1value);
  Serial.println("Sensor 2:");
  Serial.println(Sensor2value);
  Serial.println("Sensor 3:");
  Serial.println(Sensor3value);
  Serial.println("Sensor 4:");
  Serial.println(Sensor4value);
  Serial.println("Sensor 5:");
  Serial.println(Sensor5value);
  Serial.println("------------------");
//  delay (500);

//TEST FUNCTION CALLS
RightFWDFast();
RightFWDSlow();

LeftFWDFast();
LeftFWDSlow();

Forward ();
TurnRight();
TurnLeft();
FindTheLine();

LightsOn (Sensor1value, Sensor2value, Sensor3value, Sensor4value, Sensor5value);
DoTheThing (Sensor1value, Sensor2value, Sensor3value, Sensor4value, Sensor5value, Threshold);
}

void LightsOn (int S1, int S2, int S3, int S4, int S5){

  //Read Values from each Sensor
  Sensor1value = analogRead(Sensor1pin);
  Sensor2value = analogRead(Sensor2pin);
  Sensor3value = analogRead(Sensor3pin);
  Sensor4value = analogRead(Sensor4pin);
  Sensor5value = analogRead(Sensor5pin);


//  If the value read is above the threshold, turn the light on. Otherwise, Leave it off (5 iterations for each LED/Sensor)

   if (Sensor1value < Threshold) {
    digitalWrite(Light1, HIGH);
    Serial.print("lightOn1");
    Serial.print("\t");
  }
  else {
    digitalWrite(Light1, LOW);
    Serial.print("lightOff1");
    Serial.print("\t");
  }

  if (Sensor2value < Threshold) {
    digitalWrite(Light2, HIGH);
    Serial.print("lightOn2");
    Serial.print("\t");
  }
  else {

    digitalWrite(Light2, LOW);
    Serial.print("lightOff2");
    Serial.print("\t");
  }

  if (Sensor3value < Threshold) {
    digitalWrite(Light3, HIGH);
    Serial.print("lightOn3");
    Serial.print("\t");
  }
  else {
    digitalWrite(Light3, LOW);
    Serial.print("lightOff3");
    Serial.print("\t");
  }

  if (Sensor4value < Threshold) {
    digitalWrite(Light4, HIGH);
    Serial.print("lightOn4");
    Serial.print("\t");
  }
  else {
    digitalWrite(Light4, LOW);
    Serial.print("lightOff4");
    Serial.print("\t");
  }

  if (Sensor5value < Threshold) {
    digitalWrite(Light5, HIGH);
    Serial.println("lightOn5");

  }
  else {
    digitalWrite(Light5, LOW);
    Serial.println("lightOff5");
  }

  
}

void RightFWDFast (){ // WORKS
//// Motor RIGHT FWD FAST
  digitalWrite(IN1, HIGH);//
  digitalWrite(IN2, LOW);
  analogWrite(R_ENA, 200); // RIGHT ON
  delay(120);
  analogWrite(R_ENA,0); // RIGHT OFF
  delay(10);
}
void RightFWDSlow (){ // WORKS
// Motor RIGHT FWD (slow)
  digitalWrite(IN1, HIGH);//
  digitalWrite(IN2, LOW);
  analogWrite(R_ENA, 255); // RIGHT ON
  delay(20);
  analogWrite(R_ENA,0); // RIGHT OFF
  delay(10);
}  
void LeftFWDFast (){ //WORKS
// Motor LEFT Forward (Fast)
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(L_ENB, 150); // LEFT ON
  delay(70);
  analogWrite(L_ENB, 0); // LEFT OFF
  delay(10);
}
void LeftFWDSlow (){ // WORKS
// Motor LEFT Forward (Slow)
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(L_ENB, 150); // LEFT ON
  delay(20);
  analogWrite(L_ENB, 0); // LEFT OFF
  delay(10);
}

void Stop()
{
  digitalWrite(IN1, LOW);//
  digitalWrite(IN2, LOW); 
  analogWrite(L_ENB, 0); //
  digitalWrite(IN3, LOW);//
  digitalWrite(IN4, LOW);
  analogWrite(R_ENA, 0); // RIGHT OFF
}

void Forward (){ //JANKY, but works. Favours 
    Stop();
    RightFWDFast();
    LeftFWDFast();
}

void TurnRight(){ // I SAID TURN RIGHT BITCH
    Stop();
    RightFWDFast();
    
}
void TurnLeft(){ // I SAID TURN LEFT BITCH
    Stop();
    LeftFWDFast();
    
}
  
void FindTheLine(){ // FIGURE UR SHIT OUT
  Stop();
  LeftFWDFast();
  
}
void DoTheThing (int Sensor1value, int Sensor2value, int Sensor3value, int Sensor4value, int Sensor5value, int Threshold){
  
  Sensor1value = analogRead(Sensor1pin);
  Sensor2value = analogRead(Sensor2pin);
  Sensor3value = analogRead(Sensor3pin);
  Sensor4value = analogRead(Sensor4pin);
  Sensor5value = analogRead(Sensor5pin);
  // delay(400);
  
// 1: If center sensor reads black & both outside sensors read white, go FORWARD
  if (Sensor3value < Threshold && Sensor1value > Threshold && Sensor5value > Threshold){ 
    
    Forward();
  }
  
// 2: If C & CR are black & the rest white, turn LEFT 

  else if (Sensor1value > Threshold && Sensor2value > Threshold && Sensor3value < Threshold && Sensor4value < Threshold && Sensor5value > Threshold){ 

    TurnLeft();
  }
  
// 3: If C & CL are black & the rest white, turn RIGHT

   else if (Sensor1value > Threshold && Sensor2value < Threshold && Sensor3value < Threshold && Sensor4value > Threshold && Sensor5value > Threshold){ 

    TurnRight();
  } 
  
// 4: If L & CL are black & the rest white, turn RIGHT

   else if (Sensor1value < Threshold && Sensor2value < Threshold && Sensor3value > Threshold && Sensor4value > Threshold && Sensor5value > Threshold){ 

    TurnRight();
  } 

// 5: If R & CR are black & the rest white, turn LEFT 

  else if (Sensor1value > Threshold && Sensor2value > Threshold && Sensor3value > Threshold && Sensor4value < Threshold && Sensor5value < Threshold){ 

    TurnLeft();
  }

// 6: If R is black & the rest white, turn LEFT 

  else if (Sensor1value > Threshold && Sensor2value > Threshold && Sensor3value > Threshold && Sensor4value > Threshold && Sensor5value < Threshold){ 

    TurnLeft();
  }

// 7: If L is black & the rest white, turn RIGHT 

  else if (Sensor1value < Threshold && Sensor2value > Threshold && Sensor3value > Threshold && Sensor4value > Threshold && Sensor5value > Threshold){ 

    TurnRight();
  }

// 8: If CL is black & the rest white, turn RIGHT 

  else if (Sensor1value > Threshold && Sensor2value < Threshold && Sensor3value > Threshold && Sensor4value > Threshold && Sensor5value > Threshold){ 

    TurnRight();
  }
  
// 9: If CR is black & the rest white, turn LEFT 

  else if (Sensor1value > Threshold && Sensor2value > Threshold && Sensor3value > Threshold && Sensor4value < Threshold && Sensor5value > Threshold){ 

    TurnLeft();
  }
  
// 10: If ALL are black Go FWD

  else if (Sensor1value < Threshold && Sensor2value < Threshold && Sensor3value < Threshold && Sensor4value < Threshold && Sensor5value < Threshold){ 

    Forward();
  }
// 11: If L, CL, & C are black Go LEFT

  else if (Sensor1value < Threshold && Sensor2value < Threshold && Sensor3value < Threshold && Sensor4value > Threshold && Sensor5value > Threshold){ 

    TurnLeft();
  }
// 12: If R, CR, & C are black Go RIGHT

  else if (Sensor1value > Threshold && Sensor2value > Threshold && Sensor3value < Threshold && Sensor4value < Threshold && Sensor5value < Threshold){ 

    TurnRight();
  }
// 13: If R, CR, & C & CL are black Go RIGHT

  else if (Sensor1value > Threshold && Sensor2value < Threshold && Sensor3value < Threshold && Sensor4value < Threshold && Sensor5value < Threshold){ 

    TurnRight();
  }
// 11: If L, CL, & C &CR are black Go LEFT

  else if (Sensor1value < Threshold && Sensor2value < Threshold && Sensor3value < Threshold && Sensor4value < Threshold && Sensor5value > Threshold){ 

    TurnLeft();
  }
  else {
    Forward();
  }
}
