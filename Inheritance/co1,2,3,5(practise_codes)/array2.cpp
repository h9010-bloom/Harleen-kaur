#include<iostream>
using namespace std;
int main()
{
    int arr[10];
    cout<<"enter the 10 elements of an array: ";
    for(int i=0; i<=10;i++)
    {
        cin>>arr[i];
    }

    int evencount = 0;
    int oddcount = 0;

    for(int i=0; i<=10; i++)
    {
        if(arr[i] % 2 == 0)
        {
            evencount++;
        }
        else
        {
            oddcount++;
        }
    }

    cout<<"Totsl number of even nunber is: "<<evencount<<endl;
    cout<<"Total number of odd number is: "<<oddcount<<endl;
    return 0; 
}