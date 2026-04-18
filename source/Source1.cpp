#include <malloc.h>
#include <string>

//------------------------------------------------------------------------------
// overrides new operator
//------------------------------------------------------------------------------
void* operator new(size_t nBytes)
{
    return malloc(nBytes);
}

//------------------------------------------------------------------------------
struct Song
{
    std::string title;
    std::string artist;
    std::string genre;
    bool favorite;
};

