#include<iostream>
using namespace std;
int check( int a)
{
    if(a % 2 == 0)
    {
        cout<<" Number is EVEN ";
    }
    else
    {
        cout<<"Number is ODD ";
    }
}
int check2(int b)
{
    if(b >= 0)
    {
        cout<<" Number is POSITIVE ";
    }
    else
    {
        cout<<" Number is NEGATIVE ";
    }   
}
int main()
{
    int num;
    cout<<"enter a number to check if it is EVEN or ODD: ";
    cin>>num;
    check(num);
    int number;
    cout<<"\n enter a number to check if it is POSITIVE or NEGATIVE: ";
    cin>>number;
    check2(number);
    return 0;
}