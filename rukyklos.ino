int sensePin = 0;
int laserPin = 12;
int ventilatoriusPin = 9;
int zvakePin = 2;

void setup()
{
  pinMode(zvakePin, OUTPUT);
  pinMode(ventilatoriusPin, OUTPUT);
  pinMode(laserPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(laserPin, HIGH);
  while (analogRead(sensePin) < 10)
  {
    delay(10000);
    digitalWrite(zvakePin, HIGH);
    digitalWrite(ventilatoriusPin, HIGH);
    delay(10000);
    digitalWrite(zvakePin, LOW);
    delay(10000);
  }
  while (analogRead(sensePin) > 700)
  {
    digitalWrite(ventilatoriusPin, LOW);
    delay(1000);
    if (analogRead(sensePin) > 750)
    {
      digitalWrite(laserPin, LOW);
      delay(10000);
      digitalWrite(laserPin, HIGH);
      delay(100);
    }
  }
  if (analogRead(sensePin) > 10)
  {
    digitalWrite(zvakePin, LOW);
    int val = analogRead(sensePin);
    val = constrain(val, 15, 800);
    int ledLevel = map(val, 15, 800, 255, 0);
    analogWrite(ventilatoriusPin, ledLevel);
  }
}
