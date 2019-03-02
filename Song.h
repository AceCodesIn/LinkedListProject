/*
File Name: Song.h
Name:James Zhao
Date: September 24, 2018
Assignment: CSCI 235, Fall 2018, Project 2

Song.h will serve to give a song a title, author, and an album as well as overloading the == operator to compare to song objects(placeholders)
*/

#include "string"
#ifndef SONG_H_
#define SONG_H_

class Song {

public:
	//default constructor
	Song();

	//pre:when an object of song gets declared, they will be stored aas the param

	//post: param will be set equal to the private variables
	Song(const std::string& title, const std::string& author = "", const std::string& album = "");

	//pre: setTitle, setAuthor, and setAlbum take in a title, author, and album individually

	//post: set each parameter to their respective var
	void setTitle(std::string title);  //"set" in setTitle here means "give a value" and has nothing

									   // to do with the Set class. Similarly for setAuthor and setAlbum

	void setAuthor(std::string author);

	void setAlbum(std::string album);

	//return: outputs the private var when called

	std::string getTitle() const;

	std::string getAuthor() const;

	std::string getAlbum() const;

	//pre: takes in two parameters to be compared

	//post: compares two 2 parameters and returns true or false

	friend bool operator==(const Song& item1, const Song& item2);

private:

	std::string title_;

	std::string author_;

	std::string album_;
};
#endif