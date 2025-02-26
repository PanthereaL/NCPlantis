//Definere Inputs for vann og fukt-avlesing
const int 
wsensorpin = A0,                                                            // water level sensor
msensorpin1 = A1, msensorpin2 = A2, msensorpin3 = A3, msensorpin4 = A4,     // moisture 1-4 sensor
lsensorpin = A5;                                                            // Lys nivaa (LDR)

int WaterLevel = 0, 
Moisture_1 = 0, Moisture_2 = 0, Moisture_3 = 0, Moisture_4 = 0,             //
Lys_Nivaa = 0;                                                              // Endringer her

// Definere Knapp input
const int knappPin = 8;          // Pin for knappen
bool knappStatus = false;        // Status for knappen


