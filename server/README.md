# Server

The files in this directory are used to set up instances of
the applications needed for home automation.

## Architecture

The server consists of an MQTT server, Home Assistant
server, and Rhasspy server.

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

