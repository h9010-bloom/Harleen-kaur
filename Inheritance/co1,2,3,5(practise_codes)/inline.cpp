#include<iostream>
using namespace std;
inline int rec(int l, int b)
{
    return l * b;
}
int main()
{
    int length=45;
    int breadth=55;
    int area=rec(length,breadth);
    cout<<"Area of the rectangle is: "<<area<<endl;
    return 0;
}