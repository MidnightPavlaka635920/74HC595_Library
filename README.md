If anyone ever wanted to make projects with 7 segment displays, I made an library for that.
Download file from above and put it in the same folder as a filename, and that folder put into libraries folder of your Arduino folder. Else it won't work.
Use this tool to print your desired numbers: index.html file.
# Project Title

Here is one example how to show numbers with my library:

## Code Example

```arduino
// Pin definitions for your 74HC595 shift registers
const int dataPina = 4;
const int clockPina = 3;
const int latchPina = 2;
#include "74HC595LED.h"
// Initialize the display by setting up pins
void setup() {
  initReg(latchPina, clockPina, dataPina);  // Initialize shift register pins
  clearDisplay();  // Clear the display initially
  delay(2000);
  displayShowNumbers("8888", "...."); // Print "8.8.8.8." on display: 8888: numbers to show; ....: add dots after all segments
}

// Main loop to display numbers on the 4-digit 7-segment display
void loop() {
}

