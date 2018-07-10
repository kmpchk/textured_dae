//
// Created by optio32 on 09.07.18.
//

#ifndef UNTITLED_UTILS_H
#define UNTITLED_UTILS_H

#include <cstring>
#include <string>

enum STATUS
{
    STATUS_SUCCESS = 1,
    STATUS_FAIL = -1
};

std::string getFileName(const std::string& s);
std::string getFileDirectory(const std::string& s);
STATUS readFile(char* fileName, void* buffer, size_t bufferSize);
#endif //UNTITLED_UTILS_H
