bool isEmpty() {
  Serial.println(digitval.length() == 0);
  return (digitval.length() == 0);
}

float getValue() {
  Serial.println(digitval.toFloat());
  return digitval.toFloat();
}

void addNumber(char digit) {
  digitval.concat(digit);
}

void trimValue() {
  digitval = digitval.substring(0, digitval.length()-1);
}
