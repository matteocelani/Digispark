# MacOS Keyboard Setup

**This guide is for macOS Catalina and Arduino 1.8.12**

Original files: https://github.com/digistump/DigistumpArduino/tree/master/digistump-avr/libraries/DigisparkKeyboard

# Installation
You must place the header files (usbconfig.h) into the DigisparkKeyboard library, inside your Arduino15 folder.


MacOS Catalina
```
/Users/(username)/Library/Arduino15/packages/digistump/hardware/avr/(version)/libraries/DigisparkKeyboard/
```

# Info
If we insert either HID tool into the macOS computer, we're greeted by our nemesis, the keyboard profiler, before the payload has a chance to execute.

![alt text](https://img.wonderhowto.com/img/original/18/15/63710450703420/0/637104507034201815.jpg "Keyboard Setup Assistant")

You can think of the Keyboard Setup Assistant like Clippy. It's supposed to help but actually makes things harder. Trying to navigate the tool is also awful because it doesn't always profile the keyboard correctly. For instance, it will sometimes make you re-press keys to profile the keyboard, which doesn't work with a device that can't react to feedback. Instead, it's better to go around it than deal with it at all.

To get rid of the Keyboard Setup Assistant profiler, we have to identify what it's complaining about. Deep in the configuration files of the Digispark library, the source of our problem comes from the configuration option shown below.

```
/* -------------------------- Device Description --------------------------- */

#define USB_CFG_VENDOR_ID 0xc0, 0x16
/* USB vendor ID for the device, low byte first. If you have registered your
 * own Vendor ID, define it here. Otherwise you may use one of obdev's free
 * shared VID/PID pairs. Be sure to read USB-IDs-for-free.txt for rules!
 * *** IMPORTANT NOTE ***
 * This template uses obdev's shared VID/PID pair for Vendor Class devices
 * with libusb: 0x16c0/0x5dc.  Use this VID/PID pair ONLY if you understand
 * the implications!
 */
```

The problem here is that the vendor ID of "0xc0, 0x16" is not Apple. Therefore, Apple does not trust it and springs the Keyboard Setup Assistant into action to try to identify the intruder. To fix the problem, we can go into the configuration options for the Digispark library and change the vendor ID to the value of an Apple device. It will still work with non-Apple devices just fine, and the Keyboard Setup Assistant will never be called into action because macOS will assume it's recognized a fellow Apple product.

```
/* -------------------------- Device Description --------------------------- */

#define USB_CFG_VENDOR_ID 0xac, 0x05
/* USB vendor ID for the device, low byte first. If you have registered your
 * own Vendor ID, define it here. Otherwise you may use one of obdev's free
 * shared VID/PID pairs. Be sure to read USB-IDs-for-free.txt for rules!
 * *** IMPORTANT NOTE ***
 * This template uses obdev's shared VID/PID pair for Vendor Class devices
 * with libusb: 0x16c0/0x5dc.  Use this VID/PID pair ONLY if you understand
 * the implications!
 */
```

___


# Error with macOs Catalina
**Error compiling for board Digispark (Default - 16.5mhz)**
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
