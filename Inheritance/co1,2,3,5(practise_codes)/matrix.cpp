#include<iostream>
using namespace std;
int main()
{
    int matrix1[2][2];
    int matrix2[2][2];
    int multiplication[2][2];

    cout<<"enter elements for first matrix: "<<endl;
    cout<<"FIRST MATRIX: "<<endl;
    for(int i = 0; i <= 2; i++)
    {
        for(int j = 0; j <= 2; j++)
        {
            cin>>matrix1[i][j];
        }
        cout<<"\n";
    }
    cout<<"enter elements for second matrix: "<<endl;
    cout<<"SECOND MATRIX: "<<endl;
    for(int i = 0; i<=2; i++)
    {
        for(int j = 0; j<=2; j++)
        {
             cin>>matrix2[i][j];
        }
        cout<<"\n";
    }
    for(int i=0; i<= 2; i++)
    {
        for(int j=0; j<=2; j++)
        {
            multiplication[i][j] = 0;
            for(int k=0; k<=2; k++)
            {
                multiplication[i][j]+=matrix1[i][k] * matrix2[k][j];
            }
        }
        
    }
    cout<<"MULTIPLICATION OF TWO MATRICES: "<<endl;
    for(int i=0; i<=2; i++)
    {
        for(int j=0; j<=2; j++)
        {
            cout<<multiplication[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}