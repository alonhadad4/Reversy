//
// Created by alon on 24/01/18.
//

#include "gameLoopTask.h"



gameLoopTask::gameLoopTask(void * (*func)(void *arg), void* arg) : Task (func , arg){

}

/*void gameLoopTask::execute(){}*/

gameLoopTask::~gameLoopTask() {

}