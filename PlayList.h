/*
File Name: PlayList.h
Name:James Zhao
Date: September 24, 2018
Assignment: CSCI 235, Fall 2018, Project 2

Utilizes the ArrayBag created by Set to organize each song
*/

#ifndef PLAYLIST_H_
#define PLAYLIST_H_
#include "Set.h"
#include "Song.h"
using namespace std;


class PlayList {

public:

	PlayList();

	PlayList(const Song& new_song);

	int getNumberOfSongs() const;

	bool isEmpty() const;

	bool addSong(const Song& new_song);

	bool removeSong(const Song& new_song);

	void clearPlayList();

	void displayPlayList() const;

private:
	//pre: communicates with the set template and the song class

	//post: creates a playlist with objects using an arraybag implementation
	Set<Song> playlist_;
};
#endif