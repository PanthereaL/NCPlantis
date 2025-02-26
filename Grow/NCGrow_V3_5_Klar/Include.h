// Data og Input-Data
#include "Parametre.h"                 // Parametre som ligger over void setup!
#include "Inputs.h"                    // Sensorinputs, knapper, RFID ++

// Definerer alle funksjoner på ett sted
#include "void_definer_funksjoner.h"

// Skjerm og info ut
#include <LiquidCrystal_I2C.h>         // Bibliotek for I2C-skjerm (lastet ned)
#include "Lcd_Funksjoner.h"            // Kode for LCD-skjermfunksjoner

// Serial Monitor utskrifter
#include "Serial_monitor.h"            // Inkluderer Serial Monitor header for alle Serial.print-utsrifter

// Funksjoner
#include "Sensor_Funksjoner.h"         // Sensorfunksjoner og oppsett
#include "Rele_og_motor.h"             // Rele- og motoroppsett + funksjoner
#include "Lys_kontroll.h"              // Lysstyring

// Definere Innstillinger og variabler
#include "Innstilling_variabel.h"

// Kodeoppsett for utføring av oppgave
#include "void_setup.h"                // Void setup, for bedre oversikt og oppdeling
#include "void_loop.h"                 // For oppdeling av loops

// Reset for å forhindre potensielle minnelekkasjer, opprettholder stabiliteten i systemet
#include "reset.h"                     // Funksjonalitet for automatisk reset
#include <EEPROM.h>                    // Lagrer verdi for ekstra sikkerhet (Ikke i bruk i denne versjonen)
