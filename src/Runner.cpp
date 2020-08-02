#include <Runner.h>
// // Shared objects 
// #include <Project.h>
// #include <Display.h>
// #include <KeyScan.h>
// #include <Signals.h>
// #include <Blinker.h>


// // Shared objects (extern)

// Display display = Display();
// KeyScan scanner = KeyScan();
// Signals signal = Signals();
// Blinker blinker = Blinker();
// Printer printer = Printer();
// Payment payment = Payment();

Runner::Runner() {

}

void Runner::begin() {
    printer.toSerialNL("\nProgram Started\n");
    settings.begin();
    network.connect();
}

void Runner::check() {
    payment.begin();
    payment.start(PayCode::PURCHASE);
}

//   

//   progress = Status::CONFIG;

//   scanner.setDebounceTime(100);

//   blinker.begin(22, 500, 500);
//   blinker.setColor(ORANGE);
//   blinker.setLevel(125);
//   blinker.display();
//   blinker.turnLedOn();

//   settings.begin();
//   control.begin();