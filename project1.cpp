#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

class MusicSystem {
private:
    vector<string> songs;
    vector<string> playedSongs;
    vector<string> playlist;
    int lastIndex;

public:
    MusicSystem(vector<string>& songs) : songs(songs), lastIndex(-1) {}

    void playRandomSong() {
        if (playlist.size() < 10) {
            generateNewPlaylist();
        }

        if (!playlist.empty()) {
            string nextSong = playlist.back();
            playlist.pop_back();
            playedSongs.push_back(nextSong);
            cout << "Now playing: " << nextSong << endl;
        } else {
            cout << "Playlist is empty." << endl;
        }
    }

private:
    void generateNewPlaylist() {
        vector<string> availableSongs;
        for (const auto& song : songs) {
            if (find(playedSongs.begin(), playedSongs.end(), song) == playedSongs.end()) {
                availableSongs.push_back(song);
            }
        }

        unsigned seed = chrono::system_clock::now().time_since_epoch().count();
        shuffle(availableSongs.begin(), availableSongs.end(), default_random_engine(seed));

        int count = min(static_cast<int>(availableSongs.size()), 10);
        for (int i = 0; i < count; ++i) {
            playlist.push_back(availableSongs[i]);
        }
    }
};

int main() {
    vector<string> songs;
    for (int i = 1; i <= 100; ++i) {
        songs.push_back("Song " + to_string(i));
    }

    MusicSystem musicSystem(songs);

    // Simulate playing 20 songs
    for (int i = 0; i < 20; ++i) {
        musicSystem.playRandomSong();
    }

    return 0;
}
