#!/bin/bash
cd ~

sudo voice_esp32_enable

esptool.py --chip esp32 --port /dev/ttyS0 --baud 115200 --before default_reset --after hard_reset erase_flash
