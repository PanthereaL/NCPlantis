//#include "Inputs.h" //Når inkludert i Include.h må denne vere deaktivert, og visa versa!

void setupSensors() {                                  //

  pinMode(msensorpin1, INPUT);                         //Satt som input
  pinMode(msensorpin2, INPUT);                         //Satt som input
  pinMode(msensorpin3, INPUT);                         //Satt som input
  pinMode(msensorpin4, INPUT);                         //Satt som input

  pinMode(wsensorpin, INPUT);                          //satt som input

  pinMode(lsensorpin, INPUT);                          //Satt som input
}


void SensorFunctions() {                               //void loop for å minimalisere hoved kode

  WaterLevel = analogRead(wsensorpin);                 // Leser av Vannnivå
  Moisture_1 = analogRead(msensorpin1);                // Leser av fukt 1
  Moisture_2 = analogRead(msensorpin2);                //               2
  Moisture_3 = analogRead(msensorpin3);                //               3
  Moisture_4 = analogRead(msensorpin4);                //               4
  Lys_Nivaa  = analogRead(lsensorpin);                 // Lys sensetiv motstand 5549 (LDR)

    //Verdier sendes til Serial Monitor for kalibrering og koding!
    Serial.print("Vannnivå: ");
    Serial.print(WaterLevel);
    Serial.print(" | Fuktnivå 1: ");
    Serial.println(Moisture_1);
    Serial.print(" | Fuktnivå 2: ");
    Serial.println(Moisture_2);
    Serial.print(" | Fuktnivå 3: ");
    Serial.println(Moisture_3);
    Serial.print(" | Fuktnivå 4: ");
    Serial.println(Moisture_4);

}

//void Sensor_avlesing_fukt() {

//}
