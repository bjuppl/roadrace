#include "utils.h"

vector<string> split( string& str, char delim ) {

    vector<string> ret;

    string curChunk = "";

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
