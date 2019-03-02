#include "PlayList.h"
#include "iostream"
using namespace std;

PlayList::PlayList()// default constructor
{
}

PlayList::PlayList(const Song & a_song):tail_ptr_(nullptr)
{
	//tail_ptr_(NULL);//constructor needs to initialize private data member, tail_ptr_
}
PlayList::PlayList(const PlayList & a_play_list)
{
	/*
	MyClass one;
	MyClass two = one;

	MyClass two(one);
	*/
	//deep copy of the chain
	//uses getPointerToLast Node to point tailptr to the last member in the chain
}

bool PlayList::add(const Song & new_song)
{
	//with access to first node via headptr, add song to the end of the playlist
	//same song must not play multiple times

	Node<Song>* cur_ptr = head_ptr_;
	Node<Song>* new_song_ptr = nullptr;
	if (!contains(new_song))// if the song is not already in the playlist, prevent repetition
	{
		while (int x = 0)// traversing node chain using while loop
		{
			cur_ptr = cur_ptr->getNext();

			if (cur_ptr = nullptr) {//if you reach the last node in the chain, have the last node point to the new song node and have the new song node point to null
				cur_ptr = new_song_ptr;
				cur_ptr->setItem(new_song);
				cur_ptr->setNext(nullptr);
				x++;//kill the while loop
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}


bool PlayList::remove(const Song & a_song)
{
	Node<Song>* a_song_ptr = nullptr;
	Node<Song>* prev_ptr = nullptr;
	if (contains(a_song))
	{
		prev_ptr = getPointerTo(a_song, prev_ptr);
		delete[] getPointerTo(a_song, prev_ptr);
		//getPointerTo(a_song, prev_ptr) = nullptr;

		return true;
		//will use getPointerTo to have the song pointing to null and deleted, have the previous pointer point to what the original pointer was pointing too
	}
	else
	{
		return false;
	}
	//will preserve order of songs when you remove one
}

void PlayList::loop()
{
	Node<Song>* cur_ptr = head_ptr_;
	if (cur_ptr->getNext() == nullptr)
	{
		cur_ptr = head_ptr_;
	}
	//once you hit end of playlist, go back to the beginning
}

void PlayList::unloop()
{
	Node<Song>* cur_ptr = head_ptr_;
	if (cur_ptr->getNext() == head_ptr_)
	{
		cur_ptr = nullptr;
	}
	//stop the playlist from going back to the beginning
}

void PlayList::displayPlayList()
{
	for (int i = 0; i < playlist_.getCurrentSize(); i++) {
		cout << "* Title: " << playlist_.toVector()[i].getTitle() <<
			"* Author: " << playlist_.toVector()[i].getAuthor() <<
			"* Album: " << playlist_.toVector()[i].getAlbum() << " *" << endl;

	}
	cout << "End of playlist" << endl;
}

PlayList::~PlayList()
{
	Node<Song>* cur_ptr = head_ptr_;
	if (cur_ptr->getNext() == head_ptr_)
	{
		cur_ptr = nullptr;
	}
	//destructor need to unloop, same thing as unloop function
	//Node<Song>* cur_ptr = head_ptr_;
	//if pointer -> dangling, then delete pointer and pointer = nullptr
}

Node<Song>* PlayList::getPointerToLastNode() const
{
	Node<Song>* cur_ptr = head_ptr_;
	Node<Song>* tail_ptr_ = nullptr;

	while (cur_ptr != nullptr)// traversing node chain using while loop
	{
		cur_ptr = cur_ptr->getNext();

			if (cur_ptr->getNext() == nullptr)
			{
				tail_ptr_ = cur_ptr;
			}
	}
	return tail_ptr_;
	//traverse pointer chain
	//travel until the pointer points to null
	//return the pointer that points to null

	/*return nullptr;*/
}

Node<Song>* PlayList::getPointerTo(const Song & target, Node<Song>*& previous_ptr) const
{
/* 
	post: previous_ptr is null if target is not in PlayList or if target is the
	first node, otherwise it points to the node preceding target
	return: either a pointer to the node containing target
	or the null pointer if the target is not in the PlayList.
*/
	Node<Song>* cur_ptr = head_ptr_;
	Node<Song>* target_ptr = nullptr;
	Node<Song>* prev_ptr = head_ptr_;

	cur_ptr = cur_ptr->getNext(); // current pointer will be one step ahead of previous pointer

	while (cur_ptr != nullptr)// while traversing pointer chain
	{
		if (cur_ptr -> getItem() == target)// if the current pointer points at the next pointer and gets the data from that pointer, I can get the previous pointer and the target pointer at the same time
		{
			target_ptr = cur_ptr;
			previous_ptr = prev_ptr;
		}
		cur_ptr = cur_ptr->getNext();
		prev_ptr = prev_ptr->getNext();
	}
	//traverse pointer chain until you find the pointer pointer pointing to what you want.
	//return that pointer
	return target_ptr;
}
