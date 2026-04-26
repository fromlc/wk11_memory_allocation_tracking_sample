//------------------------------------------------------------------------------
// wk11_memory_allocation_tracking_sample.cpp
//
// Geeks for Geeks example:
// C++ program to illustrate malloc()
// and new operator in C++
// https://www.geeksforgeeks.org/cpp/new-vs-malloc-and-free-vs-delete-in-c/
//------------------------------------------------------------------------------
#include <iostream>
#include <malloc.h>

static int count = 0;

void* operator new(size_t size)
{

    std::cout << ++count << " ??allocated " << size << " bytes\n";
    return malloc(size);
}

void operator delete(void* pMemory, size_t size)
{
    std::cout << --count << " ??deallocated " << size << " bytes\n";
    free(pMemory);
}

//------------------------------------------------------------------------------
// Class A
//------------------------------------------------------------------------------
class A
{
    int a;

public:
    int* ptr;

    // Constructor of class A
    A() : a(0), ptr(nullptr)
    {
        std::cout << "\nClass A constructor was called!\n";
    }
};

//------------------------------------------------------------------------------
// Struct B
//------------------------------------------------------------------------------
struct B
{
    int b;

public:
    int* ptr;

    // Constructor of struct B
    B() : b(0), ptr(nullptr)
    {
        std::cout << "\nStruct B constructor was called!\n";
    }
};

//------------------------------------------------------------------------------
// driver code entry point
//------------------------------------------------------------------------------
int main()
{
    // Allocate an instance of class A with new operator
    A* pA = new A;
    std::cout << "Allocated class A instance with new operator\n";
    delete pA;
    std::cout << "Deallocated class A instance with delete operator\n";

   // Allocate an instance of class A with malloc()
    pA = (A*)malloc(sizeof(A));
    std::cout << "Allocated class A instance with malloc()\n";
    free(pA);
    std::cout << "Deallocated class A instance with delete operator\n";

    // Allocate an instance of struct B new operator
    B* pB = new B;
    std::cout << "Allocated struct B instance with new operator\n";
    delete pB;
    std::cout << "Deallocated struct B instance with delete operator\n";

    return 0;
}
