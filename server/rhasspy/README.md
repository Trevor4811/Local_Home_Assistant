# Rhasspy

This directory contains the files used to bootstrap Rhasspy
on a device running Docker.

# Installation 

`docker run -d -p 12101:12101 \
      --name rhasspy \
      --restart unless-stopped \
      -v "$HOME/.config/rhasspy/profiles:/profiles" \
      -v "/etc/localtime:/etc/localtime:ro" \
      --device /dev/snd:/dev/snd \
      rhasspy/rhasspy \
      --user-profiles /profiles \
      --profile en`

# Usage

To start Rhasspy:
`docker start rhasspy`

To stop Rhasspy:
`docker stop rhasspy`

# Configurations

Once Rhasspy is running, you can access it at `localhost:12101` by default.

To configure Rhasspy to work with Home Assistant, set MQTT Broker to external, and set the IP and port to the MQTT broker started by Home Assistant ([see Home Assistant README](../hass/README.md)). Intent handling must also be enabled to transmit to Home Assistant.
