LiquidCrystal_I2C lcd(0x27, 16, 2);      

void LCD_Startup() {

  lcd.init();
  lcd.backlight();
  delay(650);                               //Vente tid for skjerm oppstart
  lcd.clear();                              //For å sørge for at skjermen er blank før neste kommando                        
}  
                                         
void WlcmtoNCGROW(){

  lcd.setCursor(0, 0);                      
  lcd.print("Velkommen Til");               //Info om fase/program som er aktivt
  lcd.setCursor(0, 1);                      
  lcd.print("Nova Cras GROW");              //Info om vann nivå , fukt nivå (W xxx, M xxx)
}

void dsplyMsg() {

  lcd.clear();                              //For å renske bort rester fra velkommst meldingen!                             
  lcd.setCursor(0, 0);                      
  lcd.print("Program x");                   //Info om fase/program som er aktivt         

}

void updateDisplay(int LysNivaa, int WaterLevel, bool motor1, bool motor2, bool motor3, bool motor4) {

  lcd.setCursor(0, 0);
  lcd.print("                "); 
  lcd.setCursor(0, 0); 
  lcd.print("Lys:"); 
  lcd.print(LysNivaa); 
  lcd.print(" W:"); 
  lcd.print(WaterLevel); 
  
  lcd.setCursor(0, 1); 
  lcd.print("                "); 
  lcd.setCursor(0, 1); 
  // Print til LCD status på motorer for å verifisere status og vite hvilken plante som får vann.
  lcd.print("1:"); 
  lcd.print(motor1 ? "O" : "I");  
  lcd.print(" 2:"); 
  lcd.print(motor2 ? "O" : "I"); 
  lcd.print(" 3:"); 
  lcd.print(motor3 ? "O" : "I"); 
  lcd.print(" 4:"); 
  lcd.print(motor4 ? "O" : "I");

}

