
# Matrix Hal Raspberry Pi Integration

For the first attempt we are using the Matrix Voice directly with the Raspberry Pi. This allows for the raspberry pi to directly interface with the matrix voice by using the matrix hal library.

## Raspberry Pi Install Instructions
Flash an SD card with the legacy version of raspberry pi OS using the raspberry pi imager application on another computer.

Run the install shell script on the new raspberry pi image.

## Installation Issues
It took a while to be able to install Matrix HAL on the raspberry pi as it is primarily supported for an older version of Raspbian. May be possible to build from scratch using the source code in the Git repo but trying this failed on a new version of raspbian as cmake fails with a pthread dependency error.

Thus to make progress I installed the legacy version of raspbian and after some minor issues was able to install HAL properly and compile the demo scripts.
Update: Matrix HAL is only currently supported in Raspbian Buster version not Bullseye.


