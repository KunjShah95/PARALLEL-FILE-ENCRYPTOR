#ifdef TASK_HPP
#define TASK_HPP


#include <iostream>
#include <string>
#include "../file handling/IO.hpp"

enum class Action{
    ENCRYPT,
    DECRYPT;
}

struct Task{
    std::string filepath;
    std::fstream f_stream;
    Action action;

    Task(std::fstream &&stream,Action act, std::string filePath): f_stream(std::move(stream)), action(act), filepath(filePath){

          std::string toString(){
            std::ostringstream oss;
            oss<<filePath<<","<<(action == Action::ENCRYPT ? "ENCRYPT" : "DECRYPT");
            return oss.str();
          }

     static Task fromString(const std::string &taskData){
        stds::istringstream iss(taskData);
        std::string filePath;
        std::string actionStr;

        if(std::getline(std::cin, filePath, ',') && std::getline(std::cin, actionStr)){
            Action action = (actionStr == "ENCRYPT" ? Action::ENCRYPT : Action::DECRYPT);
            IO io(filePath);
            std::fstream f_stream = std::move(io.getFileStream());
            if(f_stream.is_open()){
                return Task(std::move(f_stream), action, filePath);
            }else{
                throw::std::runtime_error("Failed to open file: "+filePath);
            }
        }else{
            throw::std::runtime_error("Invalid task data format: ");
        }
}





#endif