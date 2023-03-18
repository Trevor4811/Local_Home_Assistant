#!/bin/bash


# Update
sudo apt update
sudo apt upgrade

# Install hal 
# https://github.com/matrix-io/matrix-creator-hal
# Add repo and key
curl -L https://apt.matrix.one/doc/apt-key.gpg | sudo apt-key add -
echo "deb https://apt.matrix.one/raspbian $(lsb_release -sc) main" | sudo tee /etc/apt/sources.list.d/matrixlabs.list

# Install MATRIX HAL Packages
sudo apt-get install matrixio-creator-init libmatrixio-creator-hal libmatrixio-creator-hal-dev

# Clone repo and make example scripts
cd ~/
git clone https://github.com/matrix-io/matrix-creator-hal.git
cd matrix-creator-hal
mkdir build
cd build
cmake ..
make -j4 && sudo make install

echo "Demo scripts are in ~/matrix-creater-hal/build/demos/"
echo "Success!"

