//
// Created by Ryed Ahmed on 10/30/2018.
//

#include <cstdlib>
#include <iostream>
#include "song.h"
#include "UtPod.h"

UtPod:: UtPod(int size){
    if(size > MAX_MEMORY || size <= 0){
        memSize = MAX_MEMORY;
    }
    else
        memSize = size;
}