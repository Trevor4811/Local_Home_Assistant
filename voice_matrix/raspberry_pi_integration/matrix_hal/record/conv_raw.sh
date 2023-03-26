#!/bin/bash

# Convert the raw recordings to wav files
sox -r 16000 -c 1 -e signed -c 1 -e signed -b 16 mic_16000_raw_s16le_channel_0.raw channel_0.wav
sox -r 16000 -c 1 -e signed -c 1 -e signed -b 16 mic_16000_raw_s16le_channel_1.raw channel_1.wav
sox -r 16000 -c 1 -e signed -c 1 -e signed -b 16 mic_16000_raw_s16le_channel_2.raw channel_2.wav
sox -r 16000 -c 1 -e signed -c 1 -e signed -b 16 mic_16000_raw_s16le_channel_3.raw channel_3.wav
sox -r 16000 -c 1 -e signed -c 1 -e signed -b 16 mic_16000_raw_s16le_channel_4.raw channel_4.wav
sox -r 16000 -c 1 -e signed -c 1 -e signed -b 16 mic_16000_raw_s16le_channel_5.raw channel_5.wav
sox -r 16000 -c 1 -e signed -c 1 -e signed -b 16 mic_16000_raw_s16le_channel_6.raw channel_6.wav
sox -r 16000 -c 1 -e signed -c 1 -e signed -b 16 mic_16000_raw_s16le_channel_7.raw channel_7.wav


