#include <SPI.h>

const int ssPin = 10;

void setup() {
  pinMode(MISO, OUTPUT);
  SPI.begin(); // Slave modunda SPI haberleşmesini başlat

  SPCR |= _BV(SPE); // Slave SPI modunu etkinleştir

  Serial.begin(9600);
}

void loop() {
  if (!(PINB & _BV(SS))) {  // SS pinini kontrol et (aktif düşük)
    byte receivedData = SPDR; // Master'dan gelen veriyi oku
    byte dataToSend = receivedData + 1; // Gelen veriyi +1 yaparak geri gönder
    SPDR = dataToSend; // SPDR'ye veriyi yükle (Master veriyi alacaktır)

    Serial.print("Received Data: ");
    Serial.println(receivedData, HEX);
    delay(500);
  }
}
