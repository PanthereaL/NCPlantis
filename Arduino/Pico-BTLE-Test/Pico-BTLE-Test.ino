#include "SPI.h" //Allows the use of SPI pins
#include "RF24.h" //Works with the particular RF module
#include "BTLE.h" //Library for BlueTooth Low Energy

RF24 radio(17,20);
BTLE btle(&radio);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  if (!Serial) {delay(1000);}
  Serial.println("BTLE test");
  btle.begin("foobar");
}

void loop() {
  // put your main code here, to run repeatedly:
  float temp=30;

  nrf_service_data buf;
  buf.service_uuid = NRF_TEMPERATURE_SERVICE_UUID; //0x1809

  buf.value = BTLE::to_nRF_Float(temp);

  btle.advertise(0x16, &buf, sizeof(buf));
  btle.hopChannel();

  Serial.print(".");

}
