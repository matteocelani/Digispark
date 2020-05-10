# Digispark

The Digispark is an Attiny85 based microcontroller development board similar to the Arduino line, only cheaper, smaller, and a bit less powerful. With a whole host of shields to extend its functionality and the ability to use the familiar Arduino IDE the Digispark is a great way to jump into electronics, or perfect for when an Arduino is too big or too much.

Here are the specs:

- Support for the Arduino IDE 1.6.5+ (OSX/Win/Linux)
- Power via USB or External Source - 5v or 7-35v (12v or less recommended, automatic selection)
- On-board 500ma 5V Regulator
- Built-in USB
- 6 I/O Pins (2 are used for USB only if your program actively communicates over USB, otherwise you can use all 6 even if you are programming via USB)
- 8k Flash Memory (about 6k after bootloader)
- I2C and SPI (vis USI)
- PWM on 3 pins (more possible with Software PWM)
- ADC on 4 pins
- Power LED and Test/Status LED

___

## Connecting and Programming Your Digispark

The bootloader is the code that is pre-programmed on your Digispark and allows it to act as a USB device so that it can be programmed by the Arduino IDE.

The Digispark runs the “micronucleus tiny85” bootloader version 1.02, an open source project: https://github.com/micronucleus/micronucleus originally written by Bluebie: https://github.com/Bluebie.

## Software
The Digispark uses the Arduino IDE 1.6.5+ (Arduino 1.6.5r2 - NOT 1.6.6 or 1.6.7 strongly recommended)

## Installation Instructions
- First download the appropriate Arduino package at the Arduino.cc website: https://www.arduino.cc/en/Main/Software

>If using Arduino 1.6.6 or higher and windows - you will need to download and install the drivers manually. Download, unzip and run “Install Drivers” (on 32bit systems) or “DPInst64” (on 64bit systems). If you get stuck, try following the steps shown in this YouTube video. The driver files are located here: https://github.com/digistump/DigistumpArduino/releases/download/1.6.7/Digistump.Drivers.zip

- Install or Unzip the Arduino application.
- Run the Arduino application.
- In the Arduino application go to the “File” menu and select “Preferences”
- In the box labeled “Additional Boards Manager URLs” enter:
```
http://digistump.com/package_digistump_index.json
```
and click OK
- Go to the “Tools” menu and then the “Board” submenu - select “Boards Manager” and then from the type drop down select “Contributed”:
- Select the “Digistump AVR Boards” package and click the “Install” button.
- You'll see the download progress on the bottom bar of the “Boards Manager” window, when complete it will show “Installed” next to that item on the list.
- WINDOWS USERS: When complete the install with pop up a Driver Install Wizard window, please click “Next” on this Window to install the drivers for Digistump Boards (If you already have them installed, this installer will update them and install any that are missing)
- With the install complete, close the “Boards Manager” window and select the Digispark from the Tools→Boards menu. “Digispark (Default - 16.5mhz)” is the board that should be selected by all new users.
- The install is now complete!


### Linux Install

- If you haven't before - Install the udev rules found here: Troubleshooting section
- ATTENTION LINUX USERS: [PLEASE CHECKOUT THE LINUX TROUBLESHOOTING PAGE**](https://digistump.com/wiki/digispark/tutorials/linuxtroubleshooting)


## Using the Digispark with the Arduino IDE:

The Digispark works a bit differently than some Arduino compatible products. The Digispark programs with a different procedure.

From the Tools menu select Board→Digispark (Default - 16.5Mhz)

(The Tools→Programmer selection does not matter)

Write some code, open your code, or open a Digispark example.

**You do not need to plug in your Digispark before invoking upload**

Hit the upload button. The bottom status box will now ask you to plug in your Digispark - at this point you need to plug it in - or unplug and replug it.

You'll see the upload progress and then it will immediately run your code on the Digispark.

If you unplug the Digispark and plug it back in or attach it to another power source there will be a delay of 5 seconds before the code you programmed will run. This 5 second delay is the Digispark Pro checking to see if you are trying to program it.

___

## If the computer will not recognize the Digispark try the following:

- Try connecting it to another USB port or system.
- Try connecting it to the rear ports (if a desktop).
- Try connecting it to a USB hub.
- Try a powered USB hub.
- Try a different cable.
- Try a usb extension cable or hub.
- 2012 MacBook The USB ports on the 2012 MBPs (Retina and non) cause issues due to their USB3 controllers, currently the best work around is to use a cheap USB hub (non USB3) - we are working on future solutions. The hub on a Cinema display will work as well.

**If it won't upload (macOS Catalina only)**:

```
Arduino:1.8.12 (Mac OS X), Scheda:"Digispark (Default - 16.5mhz)"
fork/exec /Users/(username)/Library/Arduino15/packages/arduino/tools/avr-gcc/4.8.1-arduino5/bin/avr-g++:
bad CPU type in executable
Error compiling for board Digispark (Default - 16.5mhz).
```

The newest version (1.8.10+) has all the parts that are required inside.  One simply needs to trick the Digistump config to use what is included, instead of its own old, out of date, no longer supported snowflake of the AVR tools.

First, make sure your board includes are all setup properly. Next, shutdown the Arduino IDE completely.  Finally, from a shell prompt, you are gonna move the Digistump snowflake out of the way, and link in the current shipping version:

```
$ cd ~/Library/Arduino15/packages/arduino/tools/avr-gcc
$ mv 4.8.1-arduino5 orig.4.8.1
$ ln -s /Applications/Arduino.app/Contents/Java/hardware/tools/avr 4.8.1-arduino5
```
Restart the Arduino IDE.

___

# Sources

**Digispark Wiki**:
- https://digistump.com/wiki/digispark/tutorials/connecting
- https://digistump.com/wiki/digispark
- https://digistump.com/wiki/digispark/tutorials/linuxtroubleshooting

**Package Sources**:
- https://github.com/digistump
- https://github.com/digistump/DigistumpArduino
- https://github.com/digistump/DigistumpArduino/tree/master/digistump-avr/libraries
- https://github.com/micronucleus/micronucleus

**Digistump Forums**:
- http://digistump.com/board/

**Digistump Products**:
- http://digistump.com/products/1
