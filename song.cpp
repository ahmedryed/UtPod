//
// Created by Ryed Ahmed on 10/30/2018.
//

#include "song.h"

Song::Song(string inTitle,string inArtist,int inSize){
    title = inTitle;
    artist = inArtist;
    size = inSize;
}

string Song::getTitle() {
    return title;
}

string Song::getArtist() {
    return artist;
}

int Song::getSize() {
    return size;
}