If anyone ever wanted to make projects with 7 segment displays, I made an library for that.
Download file from above and put it in the same folder as a filename, and that folder put into libraries folder of your Arduino folder. Else it won't work.
You use displayShowNumbers("0123", "////"); for that purpose. You can also show some special characters using displayShowCharacter(B01101100); You initialize registers using initReg(latch, clock, data);
Use this tool to print your desired numbers: index.html file.
