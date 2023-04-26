# Alexa 2.0

## Description

The Alexa 2.0 system is a voice assistant solution which uses an open-source software
stack to perform voice processing. It integrates the Matrix Voice for audio capture
along with a server software package which performs the voice processing and automation
processing entirely locally. The goal of this system is to provide users seeking an
alternative to commerical voice assistants with a software ecosystem that they are in
control of. This allow Alexa 2.0 to be inspectable and extendable. It protects the
privacy of the user by performing processing locally and can function without an
Internet connection.

## System Diagram

![System Diagram](./docs/system_diagram.png)

## Setup

It is recommended to set up the system in the following manner:

1. Set up the WLED module
    1. Assign the WLED module a static IP
        1. Connect the WLED to the network
        2. Open the web UI
        3. Navigate to the Settings and Wi-Fi Setup
        4. Assign the IP to `192.168.15.101`
        5. Assign the subnet mask as `255.255.255.0`
        6. Assign the gateway to 192.168.15.2
        7. Save settings and reboot the WLED module
2. Set up the server
    1. See the [server README](https://github.com/neu-ece-4534-sp23/sp23-prj-voice-home-automation/blob/main/server/README.md#usage)
    for details
    2. Download the Rhasspy files
        1. Navigate to the web UI at `localhost:12101`
        2. Click on the "Download external files" button
        3. Wait for the download to finish
3. Set up the Matrix Voice
    1. Connect the Matrix Voice to the network
        1. See the [Rhasspy Satellite README](https://github.com/Romkabouter/ESP32-Rhasspy-Satellite/blob/master/matrixvoice.md)
        for details
    2. Configure the Matrix Voice
        1. Open the web UI
        2. Configure the address/port of the MQTT server to that of the server computer
        3. Save settings

## Team Members/Work Breakdown

Trevor McDonald: For sprint 1 I will complete the bring-up of the matrix voice array and helping to integrate this with the raspberry pi running Rhasspy. Initially we will start by using the on-board hot word detection and transferring the wav file over serial, and I will also look into options of programming the on-board ESP32 to convert the audio to text and transfer over the internet to a server. 

Brett Sullivan: For sprint 1, I will install [Rhasspy](https://rhasspy.readthedocs.io/en/latest/) locally on the Raspberry Pi to start processing audio from the MATRIX Voice. We will explore integrating Rhasspy with Home Assistant. Initially, Rhasspy will be run locally on the Raspberry Pi, but as we transition to using the ESP32, if the ESP32 is unable to handle the load locally, we may transmit the audio over MQTT and run Rhasspy remotely using an existing open source project, [ESP32 Rhasspy Satelite](https://github.com/Romkabouter/ESP32-Rhasspy-Satellite). I will explore Rhasspy's scripting possibilities and the events they generate, and implement a simple script to verify functionality.

Johnny Cao: For sprint 1, I will install [Home Assistant](https://www.home-assistant.io/) locally on my laptop and attempt to link up with Brett to get Home Assistant communicating with the Rhasspy instance that he will be working on getting set up. Rhasspy will be sending events to Home Assistant over a common MQTT broker. I will be responsible for also writing the automations needed to control the downstream devices from the events received through Rhasspy.

Iris Wang: For sprint 1 I will explore running FreeRTOS on the Matrix Voice ESP32. From my very initial research it looks like ESP-IDF is built on FreeRTOS and is the officially supported method of ESP32 development, but I will need to look into it if this is the correct path to go down or if some other FreeRTOS solution is needed for the project. Regardless of the outcome, initial steps include setting up an initial main function and spawning one task to ensure that it's working, then eventually integrating this with the actual software used to capture and send voice commands.

