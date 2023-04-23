import spotipy
import sys
from spotipy.oauth2 import SpotifyOAuth
import re

query = ' '

if len(sys.argv) > 1:
    query = query.join(sys.argv[1:])
else:
    exit()

query = re.sub("search ", "", query, count=1)
query = re.sub("spotify ", "", query, count=1)
query = re.sub("for ", "", query, count=1)

print(query)

sp = spotipy.Spotify(auth_manager=SpotifyOAuth())

res = sp.search(query)
song = "spotify:track:" + res['tracks']['items'][0]['id']
print(song)

uris = [song]

print(uris)

sp.start_playback(uris=uris)