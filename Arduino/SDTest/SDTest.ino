#include <SPI.h>
#include <SD.h>

File testFile;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  if (!Serial) {
    delay(1000);
  }

  Serial.println("Initializing SD card...");
  if (!SD.begin(SS)) {
    Serial.println("Failed to initialize SD card");
    while (1)
      ;
  } else {
    Serial.println("Successfully initialized card");
  }

  Serial.println("Writing to SD card...");
  testFile = SD.open("test.txt", FILE_WRITE);
  testFile.println("A test string");
  testFile.close();
  Serial.println("Successfully wrote to file!");
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:

}
