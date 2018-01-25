//
// Created by alon on 24/01/18.
//

#ifndef UNTITLED5_TASK_H
#define UNTITLED5_TASK_H

class Task{
    public:
        Task(void * (*func)(void *arg), void* arg) :
                func(func), arg(arg) {}
            void execute() {
                func(arg);
            }
        virtual ~Task() {}

protected:
        void * (*func)(void *arg);
        void *arg;
};


#endif //UNTITLED5_TASK_H
