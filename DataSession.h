#pragma once
#include <string>

class DataSession {
public:
    DataSession(const std::string& filePath); // Constructor

    void create(const std::string& userId, const std::string& userPw); 
    std::string read(int token, const std::string& key);               
    void update(int token, const std::string& key, const std::string& value); 
    void deleteData(int token);                                            

private:
    std::string filePath; // Data file path

    std::string getData(int token); // get Data set
    void saveFile(const std::string& data); // save file to real
};
