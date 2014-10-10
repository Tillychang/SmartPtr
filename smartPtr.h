#ifndef START_PTR_H
#define START_PTR_H

#include <iostream>
using namespace std;

class Animal 
{
    public:
        Animal() { cout << "Animal" << endl ;}
        ~Animal() { cout << "~Animal" << endl; }

        void run() { cout << "Animal is running....." << endl; }

}; 




class SmartPtr
{
    public:
        SmartPtr(Animal * ptr = NULL)  //采用缺省函数
            :ptr_(ptr) 
        {
             
        }

        ~SmartPtr()
        {
            delete ptr_ ;
        }

        Animal &operator*()   //需要重载一个const 版本，否则const SmartPtr 无法解引用
        {
            return *ptr_ ;
        }
        const Animal &operator*() const
        {
            return *ptr_ ;
        }

        Animal *operator->()
        {
            return ptr_ ;
        }
        const Animal *operator->() const
        {
            return ptr_ ;
        }
    private:
        SmartPtr(const SmartPtr &other)
            :ptr_(other.ptr_)
        {
            
        }
        SmartPtr &operator=(const SmartPtr &other) 
        {
            if(this != &other)
            {
                ptr_ = other.ptr_ ;
            }
            return *this ;
        }

        Animal *ptr_ ;
} ;

#endif  /*START_PTR_H*/
