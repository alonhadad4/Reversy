//
// Created by alon on 24/01/18.
//

#ifndef UNTITLED5_THREADPOOL_H
#define UNTITLED5_THREADPOOL_H

#include "Task.h"
#include <queue>
#include <pthread.h>
using namespace std;

class ThreadPool {
public:
    // creates new threads and initializes mutexes
    ThreadPool(int threadsNum);
    // adding a task to the tasks queue
    void addTask(Task * task);
    //destructor for threadpool
    virtual ~ThreadPool();
    //terminate the pool and all stops all threads
    void terminate();

private:
    queue<Task *> tasksQueue;
    pthread_t threads [5];
    // loop for all threads to execute tasks from queue
    void executeTasks();
    bool stopped;
    pthread_mutex_t lock;
    // static wrapper for executing tasks
    static void * execute(void * arg);
};


#endif //UNTITLED5_THREADPOOL_H
