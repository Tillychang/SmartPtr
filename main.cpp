#include "smartPtr.h"
#include <iostream>
using namespace std;

int main(int argc, const char *argv[])
{
    {
        SmartPtr ptr(new Animal) ;
        ptr->run() ;
    }
    return 0;
}
