//
// Created by alon on 24/01/18.
//
#include "Task.h"

#ifndef UNTITLED5_GAMELOOPTASK_H
#define UNTITLED5_GAMELOOPTASK_H


class gameLoopTask : public Task {
public:
   // gameLoopTask();
    gameLoopTask(void * (*func)(void *arg), void* arg);
    ~gameLoopTask();

};


#endif //UNTITLED5_GAMELOOPTASK_H
