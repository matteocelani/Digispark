# Italian keyboard layout for Digispark DigiKeyboard.h

Original files: https://github.com/digistump/DigistumpArduino/tree/master/digistump-avr/libraries/DigisparkKeyboard

# Installation
You must place the two header files (DigiKeyboard.h and scancode-ascii-table.h) into the DigisparkKeyboard library, inside your Arduino15 folder.


MacOS Catalina
```
/Users/(username)/Library/Arduino15/packages/digistump/hardware/avr/(version)/libraries/DigisparkKeyboard
```
Linux:
```
/home/(username)/.arduino15/packages/digistump/hardware/avr/(version)/libraries/DigisparkKeyboard/
```

Windows (Arduino IDE 1.6.5 and previous):
```
c:\Users\(username)\AppData\Roaming\Arduino15\packages\digistump\hardware\avr\(version)\libraries\DigisparkKeyboard\
```
Windows (Arduino IDE 1.6.6 and later):
```
c:\Users\(username)\AppData\Local\Arduino15\packages\digistump\hardware\avr\(version)\libraries\DigisparkKeyboard\
```

# Info
For sending special characters like \[]{}@# I modified the write function in DigiKeyboard.h, starting at line 203, so to send the corresponding keystroke combination.

Updated scancode-ascii-table.h so to map the correct keycodes to ASCII codes for the italian keyboard layout.

# References

- https://en.wikipedia.org/wiki/Keyboard_layout
- https://github.com/PaulStoffregen/cores/blob/master/teensy/keylayouts.h
- http://www.asciitable.com/
