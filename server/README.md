# Server

The files in this directory are used to set up instances of
the applications needed for home automation.

## Architecture

The server consists of an MQTT server and the Home Assistant
instance running in their own Docker containers. This allows
Rhasspy to pass on voice commands to Home Assistant, which
then communicates with a variety of devices.

## Usage

### Prerequisites

It is necessary to have [Docker](https://www.docker.com/)
already set-up before proceeding.

### Running the server

The server can be run by executing the following commands:

``` shell
cd server/
docker compose up

...

docker compose down
```

