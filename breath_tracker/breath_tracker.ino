// Variable resistance stretch cord testing code! Made Jan 29 by Erin Gee for Instructables

int sensorPin = A0;    // select the input pin for the potentiometer
int scaleValue = 2;  //This scales the input into something the LED can handle
int offset = 130;
float sensorValue, fadeValue;

int buzzer = 10;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT); 
}

void loop() {
  
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  // divide it into a value from 0-255
  fadeValue = (sensorValue/scaleValue)-offset;
  //write these values to Serial Window
  Serial.println(fadeValue);

  if (fadeValue>80){
    tone(buzzer, 1000);
    delay(10);
    noTone(buzzer);
  }
  
  delay(5);                
}
