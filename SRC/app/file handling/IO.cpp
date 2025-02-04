#include<iostream>
#include "IO.hpp"
#include<fstream>
using namespace std;
IO::IO(const std::string &file_path){
    file_stream.open(file_path, std::ios::in | std::ios::out | std::ios::binary);
    if(!file_stream.is_open()){
        std::cout << "Unable to open file: " << file_path << std::endl;
    }
}

IO::getFileStream(){
    return std::move(file_stream);
}

IO::~IO(){
    if (file_stream.is_open()){
       file_stream.close();
}
}