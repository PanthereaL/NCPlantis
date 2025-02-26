
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Initialiser LCD-skjerm med I2C-adresse 0x27 og skjermstørrelse 16x2

void LCD_Startup() {
    lcd.init();              // Initialiser LCD-skjermen
    lcd.backlight();         // Skru på bakgrunnsbelysningen
    delay(650);              // Ventetid for skjermoppstart
    lcd.clear();             // Sørg for at skjermen er blank før neste kommando
}

void WlcmtoNCGROW() {
    lcd.setCursor(0, 0);          // Sett markøren på første rad, første kolonne
    lcd.print("Velkommen Til");   // Skriv "Velkommen Til" på skjermen
    lcd.setCursor(0, 1);          // Sett markøren på andre rad, første kolonne
    lcd.print("Nova Cras GROW");  // Skriv "Nova Cras GROW" på skjermen
}

void dsplyMsg() {
    lcd.clear();             // Fjern eventuelle rester fra velkomstmeldingen
    lcd.setCursor(0, 0);     // Sett markøren på første rad, første kolonne
    lcd.print("Program x");  // Skriv "Program x" for å vise aktivt program
}

void updateDisplay(int LysNivaa, int WaterLevel, bool motor1, bool motor2, bool motor3, bool motor4) {
    lcd.setCursor(0, 0);
    lcd.print("                ");    // Tømmer første rad
    lcd.setCursor(0, 0);
    lcd.print("P: "); 
    lcd.print(m_grense);              // Print m_grense
    lcd.print(" Lys: ");
    lcd.print(lysStatus ? "I" : "O"); // Print lysstatus (I/O)

    lcd.setCursor(0, 1);
    lcd.print("                "); // Tømmer andre rad
    lcd.setCursor(0, 1);
    lcd.print("1:"); 
    lcd.print(motor1 ? "O" : "I"); // Vis status for motor 1 (PÅ/AV)
    lcd.print(" 2:"); 
    lcd.print(motor2 ? "O" : "I"); // Vis status for motor 2 (PÅ/AV)
    lcd.print(" 3:"); 
    lcd.print(motor3 ? "O" : "I"); // Vis status for motor 3 (PÅ/AV)
    lcd.print(" 4:"); 
    lcd.print(motor4 ? "O" : "I"); // Vis status for motor 4 (PÅ/AV)
}
