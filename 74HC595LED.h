
const byte segmentPatterns[] = 
{
  B11111100, // 0 (0)
  B01100000, // 1 (1)
  B11011010, // 2 (2)
  B11110010, // 3 (3)
  B01100110, // 4 (4)
  B10110110, // 5 (5)
  B10111110, // 6 (6)
  B11100000, // 7 (7)
  B11111110, // 8 (8)
  B11110110, // 9 (9)
  B11101110, // A (10)
  B11111110, // B (11)
  B10011100, // C (12)
  B01111010, // D (13)
  B10011110, // E (14)
  B10001110, // F (15)
  B00000001,  // . (16) (Decimal point)
  B00000000
};
int dataPin;
int clockPin;
int latchPin;
void initReg(int latchPin, int clockPin, int dataPin) {
  // Initialize pins
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}




// Function to display hexadecimal characters from 0 to F


// Function to display a digit on the 7-segment display
void displayWrite(int digit1, int digit2, int digit3, int digit4)
{
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, segmentPatterns[digit4]); // Shift out the segment pattern for the digit
  digitalWrite(latchPin, HIGH);

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, segmentPatterns[digit3]); // Shift out the segment pattern for the digit
  digitalWrite(latchPin, HIGH);

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, segmentPatterns[digit2]); // Shift out the segment pattern for the digit
  digitalWrite(latchPin, HIGH);

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, segmentPatterns[digit1]); // Shift out the segment pattern for the digit
  digitalWrite(latchPin, HIGH);
}

// Function to clear the display (turn off all segments)
void clearDisplay() 
{
  for(int i; i < 5; i++){
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000000); // Invert all bits to turn off segments
  digitalWrite(latchPin, HIGH);
  }
}
                                          // ABCDEFG[DP]
void displayShowCharacter(int character){ //B00000000
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, character);
  digitalWrite(latchPin, HIGH);
}


void displayShowNumbers(String number) {
  int length = number.length(); // Get the length of the input string

  // Initialize digits and decimal points
  int digit1 = 17, digit2 = 17, digit3 = 17, digit4 = 17;
  bool decimal1 = false, decimal2 = false, decimal3 = false, decimal4 = false;

  // Check for decimal points
  int decimalIndex = number.indexOf('.');
  if (decimalIndex != -1) {
    number.remove(decimalIndex, 1); // Remove the decimal point from the string
    length--;
    switch (decimalIndex) {
      case 0: decimal4 = true; break;
      case 1: decimal3 = true; break;
      case 2: decimal2 = true; break;
      case 3: decimal1 = true; break;
    }
  }

  // Parse the number and assign digits
  int numbers = number.toInt();
  switch (length) {
    case 4:
      digit1 = numbers / 1000; // Extract thousands place digit
      digit2 = (numbers % 1000) / 100; // Extract hundreds place digit
      digit3 = (numbers % 100) / 10; // Extract tens place digit
      digit4 = numbers % 10; // Extract ones place digit
      break;
    case 3:
      digit1 = 17; // Blank
      digit2 = numbers / 100; // Extract hundreds place digit
      digit3 = (numbers % 100) / 10; // Extract tens place digit
      digit4 = numbers % 10; // Extract ones place digit
      break;
    case 2:
      digit1 = 17; // Blank
      digit2 = 17; // Blank
      digit3 = numbers / 10; // Extract tens place digit
      digit4 = numbers % 10; // Extract ones place digit
      break;
    case 1:
      digit1 = 17; // Blank
      digit2 = 17; // Blank
      digit3 = 17; // Blank
      digit4 = numbers % 10; // Extract ones place digit
      break;
  }

  // Shift out the segment patterns for each digit, including decimal points
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, segmentPatterns[digit4] | (decimal4 ? B00000001 : 0));
  digitalWrite(latchPin, HIGH);

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, segmentPatterns[digit3] | (decimal3 ? B00000001 : 0));
  digitalWrite(latchPin, HIGH);

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, segmentPatterns[digit2] | (decimal2 ? B00000001 : 0));
  digitalWrite(latchPin, HIGH);

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, segmentPatterns[digit1] | (decimal1 ? B00000001 : 0));
  digitalWrite(latchPin, HIGH);
}

