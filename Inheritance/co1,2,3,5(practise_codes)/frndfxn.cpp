#include<iostream>
using namespace std;
class Y;//forward decleration
class X
{
    int length;
    public:
    void setdata(int l)
    {
        length=l;
    }
    friend void show(X,Y);
};
class Y
{
    int breadth;
    public:
    void getdata(int b)
    {
        breadth = b;   
    }
    friend void show(X,Y);
};
void show(X a, Y b)
{
    int area;
    area = a.length * b. breadth;
    int perimeter;
    perimeter = 2* (a.length + b.breadth);

    cout<<"length is: "<<a.length<<endl;
    cout<<"breadth is: "<<b.breadth<<endl;
    cout<<"Area of the rectangle is : "<<area<<endl;
    cout<<"Perimeter of the rectangle is : "<<perimeter<<endl;
}
int main ()
{
    X x;
    x.setdata(5);
    Y y;
    y.getdata(8);
    show(x,y);

    return 0;
}