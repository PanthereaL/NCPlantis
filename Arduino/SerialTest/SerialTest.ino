void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  if(!Serial) {
    delay(2000);
  }
  if(!Serial) {
    while (1) {
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Serial connected!");
}
