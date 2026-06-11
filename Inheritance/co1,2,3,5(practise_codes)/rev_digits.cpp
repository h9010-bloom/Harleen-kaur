#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    string digit="1234";
    reverse(digit.begin(), digit.end());
    cout<<"reversed numbers: "<<digit;

    return 0;
}