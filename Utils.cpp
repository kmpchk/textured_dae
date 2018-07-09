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