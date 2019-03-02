/*
File Name: Song.cpp
Name:James Zhao
Date: September 24, 2018
Assignment: CSCI 235, Fall 2018, Project 2

Song.cpp will implement Song.h's functions similarly to how each customer was given a name, a defective object in project 1, Genius Bar.
*/
#include "Song.h"
#include "iostream"

Song::Song()
{
	//default contructor
}

//pre:communicates with the private var and the parameters

//post: object will contain the given parameters in the form of its private var

Song::Song(const std::string& title, const std::string& author, const std::string& album)
{
	
	title_ = title;
	author_ = author;
	album_ = album;
	
}
//pre:communicates with the private var and the parameters

//post: object will contain the given parameters in the form of its private var

void Song::setTitle(std::string title)
{
	title_ = title;
}
//pre:communicates with the private var and the parameters

//post: object will contain the given parameters in the form of its private var

void Song::setAuthor(std::string author)
{
	author_ = author;
}
//pre:communicates with the private var and the parameters

//post: object will contain the given parameters in the form of its private var

void Song::setAlbum(std::string album)
{
	album_ = album;
}

//return: when called, they retrieve the private member data 

std::string Song::getTitle() const
{
	return title_;
}

std::string Song::getAuthor() const
{
	return author_;
}

std::string Song::getAlbum() const
{
	return album_;
}

//pre: takes in 2 parameters as a objects of the class Song

//post: Compares the 2 objects in every parameter set by the constructor 

//return:true or false if the condition matches

bool operator==(const Song & item1, const Song & item2)// item1 and item2 are placeholders representing the 2 objects being compared in the operator, replaced lhs and rhs to avoid confusion
{
	if (item1.getTitle() == item2.getTitle())
		return true;
	else
		return false;
	if (item1.getAuthor() == item2.getAuthor())
		return true;
	else
		return false;
	if (item1.getAlbum() == item2.getAlbum())
		return true;
	else
		return false;
}
