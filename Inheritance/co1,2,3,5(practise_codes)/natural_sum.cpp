#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter natural numbers upto:"<<endl;
    cin>>n;
    int sum = 0;
    for(int i =1; i<=n; i++)
    {
        sum += i;
    }
    cout<<"Sum of natural numbers upto "<<n<<" is: "<<sum<<endl;
    return 0;
}
