# 7-Segment Display Library for Arduino

This library simplifies working with 7-segment displays, allowing you to easily display numbers and characters across multiple displays. Use the included `index.html` tool to test your desired numbers.

## Notes
- **Update**: If you downloaded the library before November 12, please download it again for the latest features and bug fixes.
- **Reserved Variables**: Avoid naming variables `dataPin`, `clockPin`, or `latchPin`, as these are used by the library. Set these using the `initReg()` function.
- **Delay Between Functions**: Add a delay between function calls for correct number display.
- **Hardware support**: This library is made for <a href="https://github.com/MidnightPavlaka635920/74HC595-PCB-project">my PCB project</a> specific! Avoid using on wrong hardware!
- **Status**: Libary is working totaly fine!
## Installation

1. Download the `.ZIP` file of this library.
2. Open the Arduino IDE, then go to **Sketch > Include Library > Add .ZIP Library...** and select the downloaded `.ZIP` file.

## Functions

The library includes the following main functions:

### `displayShowNumbers("0000", "////");`

This function displays numbers across 4 segments. It takes two parameters:
- **Numbers to show**: A string representing the numbers to display (e.g., `"1234"`).
- **Dots**: A string to indicate where to add dots after each number. Use `"."` for a dot and `"/"` for no dot, repeated four times (e.g., `"././"` would add dots after the first and third numbers).

**Example:**
<textarea readonly>
displayShowNumbers("1234", "././");
</textarea>

### `displayShowCharacter(0B11001100);`

This function displays a character on a single 7-segment display by specifying its binary pattern (e.g., `0B00000010`). The character will display on one segment, starting from the last segment display in the chain.

**Example:**
<textarea readonly>
displayShowCharacter(0B11001100);
</textarea>

### `initReg(int latchPin, int clockPin, int dataPin);`

Initializes the **latch**, **clock**, and **data** pins in that order. Call this function before displaying numbers or characters.

**Example:**
<textarea readonly>
initReg(2, 3, 4);
</textarea>

### `clearDisplay();`

Clears all segments on the display, turning off all lights.

**Example:**
<textarea readonly>
clearDisplay();
</textarea>

## Example Usage

Here’s a quick example of how to use this library:

`
#include "74HC595LED.h"  // Include the library

void setup() {
    initReg(2, 3, 4); // Initialize pins (latch, clock, data)
    clearDisplay();   // Clear the display
    delay(500);       // Short delay
}

void loop() {
    displayShowNumbers("1234", "././");  // Display the number 1234 with dots after 1 and 3
    delay(1000);                         // Delay to allow the display to hold
    clearDisplay();                      // Clear display between numbers
    delay(500);
    displayShowCharacter(0B11001100);    // Show a custom character pattern on the display
    delay(1000);
}
`
