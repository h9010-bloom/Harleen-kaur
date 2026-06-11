#include<iostream>
using namespace std;
class Base
{
    public:
    void show()
    {
        cout<<"BASE CLASS"<<endl;
    }
};
class Derived:public Base
{
    public:
    virtual void show()
    {
        cout<<"DERIVED CLASS"<<endl;
    }
};
int main()
{
    Base *ptr;
    Derived d;
    ptr = &d;
    ptr->show();
    d.show();

    return 0;
}