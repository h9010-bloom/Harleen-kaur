#include<iostream>
using namespace std;
class Base
{
    public:
    void show()
    {
        cout<<"THIS IS A BASE CLASS FUNCTION"<<endl;
    }
};
class Derived:public Base
{
    public:
    void show()
    {
        cout<<"THIS IS A DERIVED CLASS FUNCTION"<<endl;
    }
};
int main()
{
    Derived d;
    d.Base::show();
    d.show();
    return 0;
}