const String CHAR = "\""; 
const String PAGE = "page ";
const String FIELDS[] = {"QRCode.txt=", "Symbol.txt=", "Digits.txt="};

void changePage(int index) {
  Serial.print(PAGE + index);
  writeEndBits();
}

void changeData(int block, String data) {
  Serial.print(FIELDS[block] + CHAR + data + CHAR);
  writeEndBits();
}

void writeEndBits() {
  Serial.print("\xFF\xFF\xFF");
}
