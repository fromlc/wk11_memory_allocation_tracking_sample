//------------------------------------------------------------------------------
// wk11_memory_allocation_tracking_sample.cpp
//------------------------------------------------------------------------------
#include <iostream>
#include <malloc.h>

//------------------------------------------------------------------------------
// override new operator to track memory allocations
//      - malloc() is the memory allocation function in C, also works in C++
//      - only use malloc() in C++ development code, not release code!
//      - void* is generic memory pointer, you can cast to any pointer type
//------------------------------------------------------------------------------
void* operator new(size_t nBytes)
{
    std::cout << "Allocated " << nBytes << " bytes\n";

    return malloc(nBytes);
}

//------------------------------------------------------------------------------
// override delete operator to track memory deallocations
//      - free() is the memory deallocation function in C, also works in C++
//      - only use free() in C++ development code, not release code!
//------------------------------------------------------------------------------
void operator delete(void* pDelete, size_t nBytes)
{
    std::cout << "Deallocated " << nBytes << " bytes\n";

    free(pDelete);
}

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main()
{
    // pointer variable naming convention: small p then descriptive name
    //      here pI is a short name for pointer to int

    // allocate heap memory for one int (4 bytes), initialize with value 10
    int* pI = new int(10);

    std::cout << "The allocated int has value " << *pI << "\n";

    // fix memory leak
    delete(pI);
    // pointer is now invalid - it contains an address that is unreachable

    // best practice: set invalid pointers to 0 with nullptr or NULL
    pI = nullptr;

    std::cout << "\nGoodbye!\n";
}
