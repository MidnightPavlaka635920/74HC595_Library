# Shift7Segment - 7-Segment Display Library for Arduino

The Shift7Segment library simplifies working with 7-segment displays using shift registers (e.g., 74HC595). This library allows you to display numbers and characters, manage dots, and clear the display effortlessly.
## Features

   - Control up to 4 digits using shift registers.
   - Support for displaying numbers and characters.
   - Customizable dot placement for each digit.
   - Easy initialization and display control.

## Notes:

    - Hardware Compatibility: Designed specifically for this 74HC595 PCB project.
    - Reserved Variables: Avoid naming variables latchPin, clockPin, or dataPin, as these are managed by the library.
    - Status: Fully functional and tested.

## Installation

   - Download the .ZIP file of this library.
   - Open the Arduino IDE, then go to Sketch > Include Library > Add .ZIP Library... and select the downloaded .ZIP file.

## Functions
### Shift7Segment(latchPin, clockPin, dataPin)

Creates an instance of the Shift7Segment library. Specify the pin numbers for latch, clock, and data.

#### Example:

```Shift7Segment display(10, 11, 12); // Define latchPin, clockPin, dataPin```

init()

Initializes the pins and prepares the display for use. Call this function in setup().

Example:

display.init();

displayShowNumbers("0123", ".../");

Displays numbers across 4 digits.

    Numbers to show: A string representing the numbers to display (e.g., "0123").
    Dots: A string to indicate where to place dots. Use "." for a dot and "/" for no dot (e.g., "../." places dots on digits 1, 2, and 4).

Example:

display.displayShowNumbers("0123", ".../");

displayShowCharacter(characterCode);

Displays a custom character by specifying its binary or decimal code. For example, to display the hexadecimal character F, use 15.

Example:

display.displayShowCharacter(15); // Displays "F"

clearDisplay()

Clears all segments on the display, turning off all digits.

Example:

display.clearDisplay();

Example Usage

Here’s an example demonstrating the library's functionality:

#include <Shift7Segment.h>

// Define pins
const int latchPin = 10;
const int clockPin = 11;
const int dataPin = 12;

// Create an instance of Shift7Segment
Shift7Segment display(latchPin, clockPin, dataPin);

void setup() {
    display.init();
    display.displayShowNumbers("0123", ".../"); // Show "0123" with dots on first 3 digits
    delay(2000);

    display.clearDisplay(); // Clear the display
    delay(1000);

    display.displayShowCharacter(15); // Show "F"
}

void loop() {
    // Add further functionality here
}
