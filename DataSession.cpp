#include "DataSession.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

DataSession::DataSession(const string& filePath) : filePath(filePath) {}

void DataSession::create(const string& userId, const string& userPw) {
    ifstream inputFile(filePath);
    ostringstream buffer;
    buffer << inputFile.rdbuf();
    inputFile.close();

    int lastToken = 0;
    istringstream stream(buffer.str());
    string line;
    while (getline(stream, line)) {
        if (line.find("token=") == 0) {
            lastToken = stoi(line.substr(6));
        }
    }

    ofstream outputFile(filePath, ios::app);
    outputFile << "\ntoken=" << (lastToken + 1) << "\n";
    outputFile << "userId=" << userId << "\n";
    outputFile << "userpw=" << userPw << "\n";
    outputFile << "job=default\nlevel=1\nexp=0\nmoney=0\n";
    for (int i = 1; i <= 5; i++) outputFile << "bag" << i << "=null\n";
    outputFile << "weapon=1\narmour=null\npresentstage=1\n";
    outputFile << "manapotioncount=0\nhealingpotioncount=0\n-\n";
    outputFile.close();
}

string DataSession::read(int token, const string& key) {
    string dataBlock = getData(token);
    if (dataBlock.empty()) return "Token not found";

    istringstream stream(dataBlock);
    string line;
    while (getline(stream, line)) {
        if (line.find(key + "=") == 0) {
            return line.substr(key.length() + 1);
        }
    }
    return "Key not found";
}

void DataSession::update(int token, const string& key, const string& value) {
    ifstream inputFile(filePath);
    ostringstream buffer;
    buffer << inputFile.rdbuf();
    string content = buffer.str();
    inputFile.close();

    string dataBlock = getData(token);
    if (dataBlock.empty()) {
        cerr << "Token not found\n";
        return;
    }

    string newDataBlock;
    istringstream stream(dataBlock);
    string line;
    while (getline(stream, line)) {
        if (line.find(key + "=") == 0) {
            newDataBlock += key + "=" + value + "\n";
        }
        else {
            newDataBlock += line + "\n";
        }
    }

    size_t pos = content.find(dataBlock);
    if (pos != string::npos) {
        content.replace(pos, dataBlock.length(), newDataBlock);
        saveFile(content);
    }
}

void DataSession::deleteData(int token) {
    ifstream inputFile(filePath);
    ostringstream buffer;
    buffer << inputFile.rdbuf();
    string content = buffer.str();
    inputFile.close();

    string dataBlock = getData(token);
    if (dataBlock.empty()) {
        cerr << "Token not found\n";
        return;
    }

    size_t pos = content.find(dataBlock);
    if (pos != string::npos) {
        content.erase(pos, dataBlock.length());
        saveFile(content);
    }
}

string DataSession::getData(int token) {
    ifstream inputFile(filePath);
    ostringstream buffer;
    buffer << inputFile.rdbuf();
    inputFile.close();

    istringstream stream(buffer.str());
    string line, dataBlock;
    bool found = false;

    while (getline(stream, line)) {
        if (line.find("token=") == 0 && stoi(line.substr(6)) == token) {
            found = true;
        }

        if (found) {
            dataBlock += line + "\n";
            if (line == "-") break;
        }
    }

    return dataBlock;
}

void DataSession::saveFile(const string& data) {
    ofstream outputFile(filePath, ios::trunc);
    outputFile << data;
    outputFile.close();
}
