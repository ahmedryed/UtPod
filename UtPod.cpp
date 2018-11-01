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
     if(strcmp(cur.getTitle().c_str(),s.getTitle().c_str()) == 0 && strcmp(cur.getArtist().c_str(),s.getArtist().c_str()) == 0 ){
        return 0;
    }
    else{
        return -1;
    }
}

void UtPod::shuffle(){
int size = 0;
    SongNode *ptr;
    int target;
    int dest;
    int count = 0;

    SongNode *targ1;
    SongNode *targ2;
    SongNode *prev1;
    SongNode *prev2;
    SongNode *temp;
    
    for(ptr = songs; ptr != NULL; ptr = ptr ->next)
    {
        size++;    
    }
    for(int i = 0; i < 20; i++)
    {
        target = rand() % size;
        dest = rand() % size;

        for(ptr = songs; ptr != NULL; ptr = ptr ->next)
        {
            if(count == target)
            {
                targ1 = ptr;
            }
            if(count == dest)
            {
                targ2 = ptr;
            }
            count ++;
        }

        count = 0;

        for(ptr = songs; ptr != NULL; ptr = ptr ->next)
        {
            if(target == 0)
            {
                prev1 = ptr;
            }
            if(dest == 0)
            {
                prev2 = ptr;
            }
            if(target != 0 && count == target - 1)
            {
                prev1 = ptr;
            }
            if(dest != 0 && count == dest - 1)
            {
                prev2 = ptr;
            }
            count++;
        }
        count = 0;

        if(target == 0 && dest != 0)
        {
            songs = targ2;
            prev2->next = targ1;

            temp = targ1->next;
            targ1->next = targ2->next;
            targ2->next = temp;
        }

        if(dest == 0 && target != 0)
        {
            songs =targ1;
            prev1->next = targ2;

            temp = targ1->next;
            targ1->next = targ2->next;
            targ2->next = temp;
        }


        if(target != 0 && dest != 0) 
        {
            temp = prev1->next;
            prev1->next = prev2->next;
            prev2->next = temp;

            temp = targ1->next;
            targ1->next = targ2->next;
            targ2->next = temp;
        }
    }
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
//Code adapted from Geeks for Geeks Selection Sort
    if(songs == NULL)
        return;

    songs = recurSelectionSort(songs);
}

UtPod::SongNode* UtPod::recurSelectionSort(SongNode* head) {
//Code adapted from Geeks for Geeks Selection Sort
    // if there is only a single node
    if (head->next == NULL)
        return head;

    // 'min' - pointer to store the node having
    // minimum data value
    SongNode *min = head;

    // 'beforeMin' - pointer to store node previous
    // to 'min' node
    SongNode *beforeMin = NULL;
    SongNode *ptr;

    // traverse the list till the last node
    for (ptr = head; ptr->next != NULL; ptr = ptr->next) {

        // if true, then update 'min' and 'beforeMin'
        if (strcmp(ptr->next->s.getTitle().c_str(),min->s.getTitle().c_str()) < 0) {
            min = ptr->next;
            beforeMin = ptr;
        }
    }

    // if 'min' and 'head' are not same,
    // swap the head node with the 'min' node
    if (min != head)
        swapNodes(&head, head, min, beforeMin);

    // recursively sort the remaining list
    head->next = recurSelectionSort(head->next);
    return head;
}

void UtPod::swapNodes(SongNode** head_ref, SongNode* currX, SongNode* currY, SongNode* prevY){
//Code adapted from Geeks for Geeks Selection Sort
    // make 'currY' as new head
    *head_ref = currY;

    // adjust links
    prevY->next = currX;

    // Swap next pointers
    SongNode* temp = currY->next;
    currY->next = currX->next;
    currX->next = temp;
}

void UtPod::clearMemory(){
    SongNode *nxt;

    for(nxt = songs; songs != NULL; songs = nxt){
        nxt = songs->next;
        delete songs;
    }

    songs = NULL;
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
