/*
 * This code is intended to write to a predetermined file on a
 * Connected SD card on the RP2040 Zero by WaveShare.
 */
//Includes
#include <SPI.h>
#include <SD.h>

File myFile;

void setup() {
  Serial.begin(9600); //Not necessary, but nice for debug
  while (!Serial) {
    ; //Make sure Serial is connected before moving on
  }


  Serial.print("\nInitializing SD card...");

  if (!SD.begin(SS,SPI1)) { //Using SPI1 profile because it's a Zero
    Serial.println("Initialization failed, please check that your card is properly wired and inserted.");
    while (1);
  } else {
    Serial.println("Successfully initialized card.");
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  myFile = SD.open("test.txt", FILE_WRITE);
  if (myFile) {
    Serial.print("Opened file, writing...");
    myFile.println("This is a piece of sample text.");
    myFile.close();
    Serial.println("Writing complete.");
  } else {
    Serial.println("Failed to open file.");
  }
  while (1);
}
