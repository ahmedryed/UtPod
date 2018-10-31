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

}

void UtPod::shuffle(){

}

void UtPod::showSongList(){

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
