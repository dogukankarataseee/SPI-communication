#include <SPI.h>

const int ssPin = 10;

void setup() {
  pinMode(ssPin, OUTPUT);
  digitalWrite(ssPin, HIGH);  // Slave'ı başlatırken devre dışı bırak
  
  // SPI ayarları: 4 MHz saat hızı, MSB önce, SPI Modu 0
  SPI.beginTransaction(SPISettings(4000000, MSBFIRST, SPI_MODE0));
  SPI.begin();  // SPI haberleşmesini başlat

  Serial.begin(9600);
}

void loop() {
  digitalWrite(ssPin, LOW); // Slave'ı seç
  byte dataToSend = 0x42; // Gönderilecek veri
  
  // SPI veri gönderme ve alma işlemi
  byte receivedData = SPI.transfer(dataToSend);
  
  digitalWrite(ssPin, HIGH); // Slave'ı serbest bırak

  Serial.print("Sent Data: ");
  Serial.println(dataToSend, HEX);
  Serial.print("Received Data: ");
  Serial.println(receivedData, HEX);

  delay(1000); // Bir saniye bekle
}
