If anyone ever wanted to make projects with 7 segment displays, I made an library for that.
Use this tool to print your desired numbers: index.html file.
## Notes
-If you downloaded library before November 12, download it again.
<br>
<br>
-Do not make variables "dataPin", "clockPin" and "latchPin" cause they are used by library, but you can set it to their corresponding pins (initReg will have to be specified).
## Installation
Download .ZIP file. Then go to Arduino IDE, and add ZIP library.
## Functions
In this library, there are 3 main functions:
### displayShowNumbers("0000", "////");
This functios print numbers. Here are parameters: You obviously need numbers to show (In this case they are 0000) and dots(In function ////). This is how to add dots after numbers. If  you want dots after number you type ".", and if you don't "/". TThat should repeat 4 times.
<br>
### displayShowCharacter(0B11001100);
This function prints specified character in binary (e.g. 0B00000010). Note that it print character on ONE segment display, starting from last segment display.
<br>
### initReg(2, 3, 4);
Defines pins that are latch, clock and data pins in this order.
