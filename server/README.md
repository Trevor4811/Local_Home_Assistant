# Server

The files in this directory are used to set up instances of
the applications needed for home automation. The idea is
that a Matrix Voice (or any other device which is capable
of recording audio) may connect to the services that run on
a server to pass audio and perform the automations which
are configured on the server.

## Architecture

The server consists of an MQTT server, Home Assistant
server, and Rhasspy server. Voice audio is sent from the
Matrix Voice to an MQTT server using the Hermes protocol.
Rhasspy listens for those messages and performs a speech-
to-text conversion and looks for a configured intent. The
intent is passed to Home Assistant to perform an
automation.

## Usage

### Prerequisites

It is necessary to have [Docker](https://www.docker.com/)
already set-up before proceeding.

### Running the server

The instances of the applications packaged into the server
can be run by executing the following commands:

``` shell
cd server/
docker compose up

...

docker compose down
```

### Home Assistant Credentials

The Home Assistant administrator account can be used to set
up automations. The credentials are:

Username: `johnny`
Password: `password`

## Supported Automations

The current automations which are supported are:

1. Turning on and off a WLED strip
    1. "turn on/off the master lights"
2. Turning on and off individual LEDs on the LED strip
    1. The individual LEDs are represented as segments which
    must be set up on the WLED side
    2. "turn on/off the garage/living room/kitchen/dining room/bedroom/porch lights"
3. Turning on the master lights with a delay
    1. "turn on the lights in x hours/minutes/seconds"
    2. Only supports multiples of 10 - e.g. in 45 minutes is not supported while 40 minutes is
4. Turning on the master lights for a duration of time
    1. "turn on the lights for x hours/minutes/seconds"
    2. Only supports multiples of 10 - e.g. in 45 minutes is not supported while 40 minutes is
5. Retrieving the temperatures
    1. "what is the temperature?"
6. Retrieving the time
    1. "what is the time?"
7. Starting and stopping Spotify
    1. "start/pause music"
8. Searching Spotify for music
    1. Requires [Open transcription mode to be enabled in Rhasspy](https://github.com/neu-ece-4534-sp23/sp23-prj-voice-home-automation/blob/main/server/rhasspy-data/profiles/en/profile.json#L38)
    2. "play 'song name'"

## Setting up Spotify

The current version of the project is linked specifically to my (Iris's) Spotify account. In order to link it to your personal account, it is necessary to fix credentials in three places.

1. Remove the Spotify integration from Home Assistant and re-add it following the instructions [here](https://www.home-assistant.io/integrations/spotify/). This will involve creating an app in the Spotify Developer portal.

2. After following the steps above, the Client ID and Client secret (which the above tutorial will show you how to find) will need to be added to the docker-compose.yml file in lines 19 and 20. Then, the callback URI from line 21 (http://localhost:5173/callback) will need to be added to the app's list of redirect URIs in the Spotify Developer portal.

3. It will be necessary to run the hass-data/search_and_play.py script one time with `python search_and_play.py "play example"` from the hass-data directory in order to authenticate, but after this, the credentials should be cached so that no more authentication is needed. Overall these steps should update the files hass-data/config/.cache and hass-data/config/.storage/application_credentials and hass-data/config/.storage/core.entity_registry.

