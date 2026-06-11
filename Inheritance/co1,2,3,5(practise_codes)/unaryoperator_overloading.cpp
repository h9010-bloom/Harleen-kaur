#include<iostream>
using namespace std;
class demo
{
    int real;
    public:
    demo(int r)
    {
        real=r;
    }
    int operator ++()
    {
        real=++real;
        return real;
    }
    void show()
    {
        cout<<"result is: "<<real<<endl;
    }
};
int main()
{
    demo d(40),result(0);
    result=++d;
    d.show();
    return 0;
}