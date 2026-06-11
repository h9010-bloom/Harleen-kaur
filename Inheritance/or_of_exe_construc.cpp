#include <iostream>
using namespace std;
class A
{
    public:
    A()
    {
        cout<<"THIS IS CLASS A"<<endl;
    }
};
class B
{
    public:
    B()
    {
        cout<<"THIS IS CLASS B"<<endl;
    }
};
class C : public A, public B
{
    public:
    C()
    {
        cout<<"THIS IS CLASS C"<<endl;
    }
};
int main()
{
    C c;
    return 0;
}