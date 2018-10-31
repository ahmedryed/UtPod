//
// Created by Ryed Ahmed on 10/30/2018.
//

#include <cstdlib>
#include <iostream>
#include "song.h"
#include "UtPod.h"


UtPod::UtPod() {
    songs = NULL;
    memSize = MAX_MEMORY;
}

UtPod::UtPod(int size){
    songs = NULL;

    if(size > MAX_MEMORY || size <= 0){
        memSize = MAX_MEMORY;
    }
    else
        memSize = size;
}

int UtPod::addSong(Song const &s){
   if(s.getSize() > getRemainingMemory() ){//not enough memory to add song
        return -1;
    }
    else{
        SongNode *new_song = new SongNode;
        new_song->s = s;
        new_song->next = songs;
        songs = new_song;
        return 0;
    }
}

int UtPod::removeSong(Song const &s){

    SongNode *prev, *cur;
    Song searchSong = s;

    //For loop to search through linked list
    //Terminating conditions are getting to end of list or if song is found
    for(cur = songs, prev = NULL; cur != NULL && cmpSongs(cur->s,s) != 0; prev = cur, cur = cur->next);

    if(cur == NULL)
        return -2;
    if(prev == NULL)
        songs = songs->next;
    else{
        prev->next = cur->next;
        delete cur;
    }
    
    return 0;
}

int UtPod::cmpSongs(Song const &cur, Song const &s){
    //Returns 0 if song titles are the same
    return strcmp(cur.getTitle().c_str(),s.getTitle().c_str());
}

void UtPod::shuffle(){

}

void UtPod::showSongList(){
    SongNode *ptr = songs;

    std::cout << std::endl << "Song List: " << std::endl;

    if(ptr == NULL)
        std::cout << "No songs stored on UtPod" << std::endl<< std::endl;

    for(ptr = songs; ptr != NULL; ptr = ptr->next){
        std::cout << "Title: " << ptr->s.getTitle() << std::endl;
        std::cout << "Artist: " << ptr->s.getArtist() << std::endl;
        std::cout << std::endl;
    }
}

void UtPod::sortSongList(){

}

void UtPod::clearMemory(){

}

int UtPod::getRemainingMemory(){
    int usedMem = 0;
    SongNode *ptr;

    for(ptr = songs; ptr != NULL; ptr = ptr ->next){
        usedMem += ptr->s.getSize();
    }

    int remainingMem = getTotalMemory() - usedMem;
    return remainingMem;
}

UtPod::~UtPod(){}
