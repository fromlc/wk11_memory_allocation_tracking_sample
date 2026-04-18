//------------------------------------------------------------------------------
// wk11_memory_allocation_tracking_sample.cpp
//------------------------------------------------------------------------------
#include <iostream>

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

    // allocate heap memory for one int (4 bytes), initialize with value 10
    pI = new int(25);
    // the previously allocated int with value 10 is now unreachable garbage!
    // we just created a memory leak

    std::cout << "\nGoodbye!\n";
}
