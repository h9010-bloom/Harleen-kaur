#include<iostream>
using namespace std;
class complex
{
    int real;
    int imag;
    public:
    complex(int r,int i)
    {
        real=r;
        imag=i;
    }
    complex operator + (complex d)
    {
        complex temp(0,0);
        temp.real=real+d.real;
        temp.imag=imag+d.imag;
        return temp;

    }
    void display()
    {
        cout<<"the value with the use of binary operator is: "<<real<<" + "<<"i"<<imag<<endl;
    }
};
int main()
{
    complex c(10,20),d(30,40),result(0,0);
    result=c+d;
    result.display();
    return 0;
}