// C++ code
//

#define TRIG 13 // TRIG ги
#define ECHO 12 // ECHO ги

int led_r = 7;
int led_g = 8;


void setup()
{
  Serial.begin(9600);
  pinMode(led_r, OUTPUT);
  pinMode(led_g, OUTPUT);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
}

void loop()
{
  
  long duration, distance;
  delayMicroseconds(2); //delay(2)
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  
  duration = pulseIn(ECHO, HIGH);
  
  distance = duration / 58.2;
  Serial.println(duration);
  Serial.print("\nDistance : ");
  Serial.print(distance);
  Serial.println(" CM");
  
  delay(1000); // Wait for 1000 millisecond(s)
  
}

