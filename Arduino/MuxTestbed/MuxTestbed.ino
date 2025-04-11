int sensor_pin1 = A0;
int sensor_pin2 = A1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(analogRead(sensor_pin1) + "," + analogRead(sensor_pin2));
  delay(500);

}
