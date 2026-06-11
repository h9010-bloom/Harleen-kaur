#include<iostream>
using namespace std;
int swap(int temp, int x, int y )
{
    temp = x;
    x = y;
    y = temp;
    cout<<"inside swap function when a and b is x="<<x<<" or y= "<<y<<endl;
}
int main()
{
    int temp;
    int a=2;
    int b=3;
    cout<<"before swap a= "<<a<<" b= "<<b<<endl;
    swap(temp, a, b);
    cout<<"after swap a= " <<a<<" b= "<<b<<endl;
    return 0;
}