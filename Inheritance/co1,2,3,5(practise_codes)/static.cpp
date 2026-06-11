#include <iostream>
using namespace std;
class A
{
    static int a;//static data member
    static int b;//static data member

    public:
    static void show(int alpha,int beta)
    {
        a=alpha;
        b=beta;
    }
    static void getdata()//static member function
    {
        cout<<"value of a is: "<<a<<endl;
        cout<<"value of b is: "<<b<<endl;
    }
};
int A::a=0;
int A::b=0;
int main()
{
    A::show(10,30);
    A::getdata();
    return 0;

}