const std::vector<int> SIGNAL_OUT_PIN = {1,2,3};
const std::vector<int> DATA_IN_PIN = {A0, A1, A2};

void setup() {
  // put your setup code here, to run once:
  
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < SIGNAL_OUT_PIN.length; i++) {
    for int j = 0; j < DATA_IN_PIN.length; j++) {
      digitalWrite(SIGNAL_OUT_PIN[i], HIGH);
      delay(20);
      analogRead(DATA_IN_PIN[j]); //I should send this to somewhere
      digitalWrite(SIGNAL_OUT_PIN[i],LOW);
    }
  }
}
