
void Startup_sekvens() {

  LCD_Startup();  
  WlcmtoNCGROW();                         //Velkommst melding Velkommen til Nova Cras GROW
  delay(3000);                            //Hold tid på 30s
  dsplyMsg();
  
  setupSensors();                           //Aktiverer sensorene (W og M)
  Motor_og_ReleSetup();                     // Oppsett til Rele og Motorer
  setupLys();                               // Initialiser lyskontroll
  setupProgrammer();                        // Initialiser programmer (moduser)

}

void Motor_kontroll() {

  Motor_setup();
}







