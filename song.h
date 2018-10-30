//
// Created by Ryed Ahmed on 10/30/2018.
//

#ifndef UTPOD_SONG_H
#define UTPOD_SONG_H



#include <string>

using namespace std;

class Song{
private:
    string title;
    string artist;
    int size;
public:
    //default constructor
    Song();

    Song(string inTitle,string inArtist,int inSize);

    string getTitle();

    string getArtist();

    int getSize();



};

#endif //UTPOD_SONG_H