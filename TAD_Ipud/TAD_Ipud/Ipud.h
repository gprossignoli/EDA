#ifndef Ipud_h
#define Ipud_h

#include <iostream>
#include <unordered_map>
#include <list>
#include <iterator>
#include <string>
#include <stdexcept>

class ipud {
	
	using title = std::string;
	using list = std::list<title>;
	using songInfo = struct {
		std::string artist;
		int duration;
		list::iterator itToPlayList;
		list::iterator itToRecentList;
	};
private:
	std::unordered_map<title, songInfo> songs;
	list playList;
	list recentList;
	int totalDurationOfPL;

public:
	ipud() : songs(), playList(), recentList(), totalDurationOfPL(0) {}

	void addSong(const std::string song, const std::string artist, const int duration) {
		auto itSong = songs.find(song);
		
		if (itSong != songs.end())
			throw std::domain_error("ERROR addSong");

		songInfo aux;
		aux.artist = artist;
		aux.duration = duration;
		aux.itToPlayList = playList.end();
		aux.itToRecentList = recentList.end();
		songs.insert({ song,aux });
	}

	void addToPlaylist(const std::string song) {
		auto itSong = songs.find(song);

		if (itSong == songs.end())
			throw std::domain_error("ERROR addToPlaylist");

		if (itSong->second.itToPlayList == playList.end()) {
			itSong->second.itToPlayList = playList.insert(playList.end(), itSong->first);
			totalDurationOfPL += itSong->second.duration;
		}
	}

	const std::string current() const {
		if (playList.empty())
			throw std::domain_error("ERROR current");

		return playList.front();
	}
	
	const std::string play() {
		if (!playList.empty()) {
			const title song = current();
			playList.pop_front();
			auto itSong = songs.find(song);
			itSong->second.itToPlayList = playList.end();
			totalDurationOfPL -= itSong->second.duration;
			if (itSong->second.itToRecentList == recentList.end()) {
				itSong->second.itToRecentList = recentList.insert(recentList.end(), song);
			}
			else {
				recentList.erase(itSong->second.itToRecentList);
				itSong->second.itToRecentList = recentList.insert(recentList.end(), song);
			}
			return song;
		}
		else
			throw std::domain_error("ERROR play");
	}

	const int totalTime() const{
		return totalDurationOfPL;
	}

	const std::list<std::string> recent(const int N) {
		std::list<title> recentSongs;
		auto it = recentList.end();
		--it;
		int i = 0;

		
		while (it != recentList.begin() && i < N) {
			recentSongs.push_back(*it);
			--it;
			++i;
		}
		if(it == recentList.begin())
			recentSongs.push_back(*it);

		return recentSongs;
	}

	void deleteSong(const std::string song) {
		auto itSong = songs.find(song);

		if (itSong != songs.end()) {
			if (itSong->second.itToPlayList != playList.end()) {
				playList.erase(itSong->second.itToPlayList);
				totalDurationOfPL -= itSong->second.duration;
				itSong->second.itToPlayList = playList.end();
			}
			if (itSong->second.itToRecentList != recentList.begin()) {
				recentList.erase(itSong->second.itToRecentList);
				itSong->second.itToRecentList = recentList.begin();
			}
			songs.erase(song);
		}
	}

};
#endif