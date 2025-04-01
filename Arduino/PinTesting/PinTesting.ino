int TEST_PIN[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 26, 27, 28 };
int numOfPins = 26;

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < numOfPins; i++) {
    pinMode(TEST_PIN[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0 ; i < numOfPins ; i++) {
  digitalWrite(TEST_PIN[i], HIGH);
  delay(1500);
  digitalWrite(TEST_PIN[i], LOW);
  delay(10000);
  }
}
