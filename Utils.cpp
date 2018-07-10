//
// Created by optio32 on 09.07.18.
//

#include "Utils.h"

std::string getFileDirectory(const std::string& s)
{
    return s.substr(0, s.find_last_of("/"));
}

std::string getFileName(const std::string& s)
{
    char sep = '/';

#ifdef _WIN32
    sep = '\\';
#endif

    size_t i = s.rfind(sep, s.length());
    if (i != std::string::npos) {
        return (s.substr(i + 1, s.length() - i));
    }

    return ("");
}

STATUS readFile(char* fileName, void* buffer)
{
    FILE* file = fopen(fileName, "r");
    if(file == NULL) return STATUS_FAIL;
    fseek(file, 0, SEEK_END);
    size_t fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);
    buffer = new char[fileSize];
    size_t readedBytes = fread(buffer, fileSize, 1, file);
    if(readedBytes != 1)
    {
        fclose(file);
        return STATUS_FAIL;
    }
    return STATUS_SUCCESS;
}