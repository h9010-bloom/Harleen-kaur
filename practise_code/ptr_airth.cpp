#include<iostream>
using namespace std;
int main()
{
    int arr[3]={20,30,10};
    int *p=arr;
    cout<< *p <<endl;

    p++;
    cout<<*p<<endl;

    p=p+1;
    cout<< *p <<endl;

    return 0;
}
