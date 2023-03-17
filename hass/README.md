# Home Assistant

This directory contains the files used to bootstrap Home
Assistant on a device running Docker.

Run the `bootstrap.sh` script to create a Docker image and
a Docker container at `localhost:8123`.

## API Key

In order for Rhasspy to send events to Home Assistant, it
needs to be linked with Home Assistant using the instance
URL and an API key. The API key which has been generated
for the container on my laptop can be found in the
`access-token` file.

