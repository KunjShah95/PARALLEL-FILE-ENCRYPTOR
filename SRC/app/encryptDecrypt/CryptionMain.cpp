#include<iostream>
#include "Cryption.hpp"

int main(int arg, char* argv[])
if(argc!=2){
    std::cerr <<"Usage: ./cryption <task_data>" << std::endl; 
    return 1;
    }

    executeCryption(argv[1]);
    return 0;
    }