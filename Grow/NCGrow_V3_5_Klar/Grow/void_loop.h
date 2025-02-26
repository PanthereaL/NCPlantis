
void loop_sensor_funksjoner() {

  SensorFunctions();                      //Oppdaterer sensorverdier og skriver til Serial Monitor
  updateDisplay(Lys_Nivaa, WaterLevel, sjekkMotor(M_1), sjekkMotor(M_2), sjekkMotor(M_3), sjekkMotor(M_4));  //
}

void sjekk() {                            // Sjekker om motor(er) er på eller av

  if (sjekker_motor_tilstand()) {
    interval = 1000;                      // Sjekker s.status hvert sekund når på
  } 
    else {
      interval =1200000;                  // Sjekk hvert 20. min når av
    }
  // Status sjekk
  if (aktuellMillis - tidligereMillis >= interval) {
    tidligereMillis = aktuellMillis;
    loop_sensor_funksjoner();
    
  }
}

void loop_motor_Off_ON() {

  Motor_Off_ON(
    Moisture_1 < m_grense,
    Moisture_2 < m_grense,
    Moisture_3 < m_grense,
    Moisture_4 < m_grense
  );

  delay(1000);

}






