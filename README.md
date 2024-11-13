# 7-Segment Display Library for Arduino

This library simplifies working with 7-segment displays, allowing you to easily display numbers and characters across multiple displays. Use the included `index.html` tool to test your desired numbers.

## Notes
- **Update**: If you downloaded the library before November 12, please download it again for the latest features and bug fixes.
- **Reserved Variables**: Avoid naming variables `dataPin`, `clockPin`, or `latchPin`, as these are used by the library. Set these using the `initReg()` function.
- **Delay Between Functions**: Add a delay between function calls for correct number display.

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
```cpp
displayShowNumbers("1234", "././");
