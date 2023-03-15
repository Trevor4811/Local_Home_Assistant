#!/bin/bash

# Bootstrap script
# Creates a Docker image and then a Docker container that
# runs the instance of Home Assistant at localhost:8123

# Create the "hass" Docker image using ./Dockerfile
docker build -t hass ./Dockerfile

# Create the "hass" Docker container running the "hass"
# image.
# This creates the Home Assistant instance which can be
# accessed at localhost:8123.
# The configuration information is stored in a peristent
# volume called "hass-data"
docker run -d \
  --name hass \
  --privileged \
  --restart=unless-stopped \
  -p 8123:8123 \
  -v hass-data:/config \
  hass

