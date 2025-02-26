//Skjerm og info ut
#include <LiquidCrystal_I2C.h>                        // Bibliotek for I2C skjerm (lastetned)
#include "Lcd_Funksjoner.h"                           // kode for lcd skjerm funksjoner

//Data og Input-Data 
#include "Parametre.h"                                // Parametre som ligger over void setup!
#include "Inputs.h"                                   // Sensor inputs, knapper, RFID ++

//Funksjoner
#include "Sensor_Funksjoner.h"                        // Sensor funksjoner og oppsett
#include "Rele_og_motor.h"                            // Rele og motor oppsett + funskjoner
#include "Lys_kontroll.h"                             // Lys styring

//Programstyring
#include "RFID_setup.h"                               // RFID oppsett
#include "Programmer.h"                               // Programmer som gir oppsettet for funksjoner


//Kode oppsett for utføring av oppgave
#include "void_setup.h"                               // Void setup, for å få bedre oversikt, dele opp for struktur
#include "void_loop.h"                                // For oppdeling av loops, 



