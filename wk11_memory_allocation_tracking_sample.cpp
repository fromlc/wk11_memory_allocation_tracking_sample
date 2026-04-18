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

// Class A
class A
{
    int a;

public:
    int* ptr;

    // Constructor of class A
    A() : a(0), ptr(nullptr)
    {
        std::cout << "Class A constructor was called!\n";
    }
};

// Struct B
class B
{
    int b;

public:
    int* ptr;

    // Constructor of struct B
    B() : b(0), ptr(nullptr)
    {
        std::cout << "Struct B constructor was called!\n";
    }
};

//------------------------------------------------------------------------------
// entry point: driver code
//------------------------------------------------------------------------------
int main()
{
    // Create an object of class A with new operator
    A* pA = new A;
    std::cout << "Instance of class A was created with new operator\n";
    delete pA;

   // Create an object of class A with malloc()
    pA = (A*)malloc(sizeof(A));
    std::cout << "Instance of class A was created with malloc()\n";
    delete pA;

    // Create an instance of struct B new operator
    B* pB = new B;
    std::cout << "Instance of struct B was created with new operator\n";
    delete pB;

    return 0;
}
