#include "Cryption.hpp"
#include "../processes/Task.hpp"
#include "../filehandling/ReadEnv.cpp"

int executeCryption(const std::string &taskData){
    Task task = Task::parse(taskData);
    ReadEnv readEnv;
    
    std::string env = readEnv.getenv();
    int key =  std::stoi(envKey);   

    if(task.action == Action::ENCRYPT){
        char ch;
        while(task.f_stream.get(ch)){
           ch = (ch = ch + key)%256;
              task.f_stream.seekp(-1, std::ios::cur);
              task.f_stream.put(ch);   
        }
        task.f_stream.close();
        }else{
            char ch;
            while(task.f_stream.get(ch)){
              ch = (ch = ch - key)%256;
              task.f_stream.seekp(-1, std::ios::cur);
              task.f_stream.put(ch);   
            }
            task.f_stream.close();
        }
        return 0;
    }


}