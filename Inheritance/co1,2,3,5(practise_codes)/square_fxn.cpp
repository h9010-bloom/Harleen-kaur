#include<iostream>
using namespace std;
int square(int num)
{
    return num*num;
}
int main()
{
    int number;
    cout<<"enter a number: ";
    cin>>number;
    int result=square(number);
    cout<<"the square of "<<number<<" is: "<<result<<endl;
}