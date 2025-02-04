#include <string>
#include <iostream>
#include<sys/wait.h>
#include "ProcessManagement.hpp"
// #include "../encryptDecrypt/Cryption.hpp"

ProcessManagement::ProcessManagement(){
    // std::cout<<"ProcessManagement constructor called"<<std::endl;
bool ProcessManagement::submitToQueue(std::unique_ptr<Task> task){
    taskQueue.push(std::move(task));
    return true;
}

void ProcessManagement::executeTasks(){
    while(!taskQueue.empty()){
        std::unique_ptr<Task> task = std::move(taskQueue.front());
        taskQueue.pop();
        pid_t pid = fork();
       std::cout<<"Executing task "<<taskToExecute->toString(
        executeCryption(tasktoExecute->toString());
       )<<std::endl;











































































}
