
# ESP32 Rhasspy Satellite

## Overview
https://github.com/Romkabouter/ESP32-Rhasspy-Satellite\
Found a git repo to use the matrix voice onboard esp 32 to run as a Rhasspy Satellite streaming audio on MQTT. Rhasspy sessions may then subscribe to the rhasspy session and process it. This library includes some control of the matrix voice over MQTT and uses the built in LEDs as indicators

This allows for rahsspy to run without being connected to a raspberry pi.

## Install Instructions
On the Raspberry Pi connected to the Matrix voice:
1. Run the matrix voice software [install script](./matrix_install.sh)
1. After reboot run the [reset esp32 script](./reset_esp32.sh)

On the personal computer
1. Download the esp32 satellite repo with `git clone https://github.com/Romkabouter/ESP32-Rhasspy-Satellite.git`
1. Open Visual Studio Code
1. Install the [PlatformIO](https://platformio.org/) extension in VSCode
1. copy the [settings file](./settings.ini) into the PlatformIO folder of the esp32 satellite repo
1. Open the PlatformIO folder in the esp32 satellite repo in VSCode
1. In VSCode run compile and upload buttons to flash the matrix voice using the raspberry pi
1. Shutdown the raspberry pi, remove the Matrix Voice, and power the Matrix Voice with a usb cable. 
1. Lights should turn blue when connected and automatically start streaming auido

Light indicators of the Matrix Voice
- Blue - Connected to the MQTT Server
- Red - Not connected, check the IP addresses the Matrix Voice was flashed with

## Reflashing
- Connect the Matrix Voice to the Raspberry Pi 
- Run the [reset esp32 script](./reset_esp32.sh)
- Upload using VSCode with the PlatformIO extenstion

