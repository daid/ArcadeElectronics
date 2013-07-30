ArcadeElectronics
=================

V-USB based Electronics board for Arcade controls

Features
========
* V-USB based USB Interface emulating a mouse, keyboard and gamepad with full configuration of button mapping (no drivers required)
* 4 way digital joystick + 7 button connections. 4 way joystick inputs can also be used for analogue joystick.
* 16 LED output pins (max current total 200mA) which can also be used as inputs. And 8 are also mapped wired to 1A higher power outputs with external power supply (optional hardware)
* RFM12 wireless transiever (optional hardware) allows communication with other controllers and building of wireless controllers with 2 boards.
* Full open-source hardware & open-source software - Build with Free-Open-Source tools (KiCAD & AVR-GCC)
* ISP header to program the AVR (reset line can be cut and re-wired to have the board function as an programmer on the same header)
* USB-micro or USB-B connector depending on your taste
* Different small board designs, depending on your requirements:
	* 100x50mm: Fully featured, has option for 16 LED outputs, of which 8 can be configured for high power. Has wireless RFM12 option. 4 direction inputs, 7 button inputs
	* 50x50mm: Only base features with screw connectors. 4 direction inputs, 7 button inputs.
	* 50x25mm: Only base features with pin connectors. 4 direction inputs, 7 button inputs 
	* 25x25mm: Only base features with pin connectors, components on both sides. 4 direction inputs, 7 button inputs 

Organization
============
The following directories are in this project:
* Electronics - Contain the KiCAD design files
* Software/firmware/bootloader - Modified HIDBoot
* Software/firmware/arcade - Main firmware for the Arcade controller
* Software/computer/commandline - Commandline application to change the controller configuration, and control the LEDs
* Software/computer/lib - Library shared between different applications for custom commands to the ArcadeController
* Software/computer/gui_test - SDL based application to verify the Keyboard/Joystick/Mouse inputs
