#include<iostream>
using namespace std;
void inputdata(int &a, int &b)
{
    cout<<"enter a 1st number: ";
    cin>>a;
    cout<<"enter a 2nd number: ";
    cin>>b;
}
int calculatedata(int a, int b, int &sum)
{
    sum= a+b;
}
void displaydata(int sum)
{
    cout<<"Sum of Two numbers is: "<<sum;
}
int main()
{
    int num1, num2, addition;
    inputdata(num1, num2);
    calculatedata(num1, num2, addition);
    displaydata(addition);
    return 0;
}