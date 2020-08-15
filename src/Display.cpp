#include <Display.h>

const String TEXT = ".txt=";
const String CHAR = "\""; 
const String PAGE = "page ";
const String BLOCKS[] = {"QRCode", "Symbol", "Digits"};
const String FIELDS[] = {"Options.Option1", "Options.Option2" , "Options.Option3",
                        "Payment.ISOCode", "Payement.Symbol", "Payment.Back", "Payment.Next"
                        "Sucess.Text", "Refused.Text", "Warning.Text"};

HardwareSerial Screen(1);

Display::Display() {
    Screen.begin(9600, SERIAL_8N1, 26, 27);
}

void Display::changePage(Nextion page) {
    Screen.print(PAGE + (int)page);
    writeEndBits();
}

void Display::changeBlock(UIBlock block, String data) {
    Screen.print(BLOCKS[(int)block] + TEXT + CHAR + data + CHAR);
    writeEndBits();
}

void Display::changeField(int index, String data) {
    String output = FIELDS[index] + TEXT + CHAR + data + CHAR;
    Printer::toSerialNL(output);
    Screen.print(output);
    writeEndBits();
}

void Display::writeEndBits() {
    Screen.print("\xFF\xFF\xFF");
}