#include "utils.h"

std::vector<std::string> split( std::string& str, char delim ) {

    std::vector<std::string> ret;

    std::string curChunk = "";

    auto size = str.size();

    for ( auto i = 0; i < size; i++ ) {

        if ( str[i] != delim) {
            curChunk += str.at(i);
        }
        if ( str[i] == delim || i == size-1 ) {

            ret.push_back(curChunk);
            curChunk = "";

        }
    }

    return ret;

}
