const String QRCode = "QRCode.txt=";

void changeCode(String message) {
  Serial.print(QRCode);
  Serial.print('"');
  Serial.print(message);
  Serial.print('"');
  writeEndBits();
}

void changePage(int page) {
  
}

void writeEndBits() {
  Serial.write(0xff);
  Serial.write(0xff);
  Serial.write(0xff);
}
