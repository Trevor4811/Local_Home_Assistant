#!/bin/bash
cd ~
wget https://apt.matrix.one/doc/apt-key.gpg
sudo apt-key add apt-key.gpg
echo "deb https://apt.matrix.one/raspbian $(lsb_release -sc) main" | sudo tee /etc/apt/sources.list.d/matrixlabs.list

sudo apt-get update
sudo apt-get upgrade

sudo apt install matrixio-creator-init

sudo reboot
