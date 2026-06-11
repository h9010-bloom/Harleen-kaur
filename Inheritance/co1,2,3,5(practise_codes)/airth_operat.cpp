#include<iostream>
using namespace std;
int main()
{
    int A;
    int B;
    char op;

    cout<<"enter the value of A "<<endl;
    cin>>A;
    cout<<"enter the value of B "<<endl;
    cin>>B;
    cout<<"enter any operator"<<endl;
    cin>>op;

    cout<<"VALUE OF A: "<<A<<endl;
    cout<<"VALUE OF B: "<<B<<endl;

    switch (op)
    {
        case '+':
        cout<<"Addition result: "<<A+B<<endl;
        break;
        
        case '-':
        cout<<"Subtraction result: "<<A-B<<endl;
        break;

        case '*':
        cout<<"Multiplication result: "<<A*B<<endl;
        break;

        case '/':
        if(B!= 0 )
        {
            cout<<"Division result: "<<A/B<<endl;
        }
        else{
            cout<<"ERROR! Division by Zero"<<endl;
        }
        break;

        default:
        cout<<"Invalid Operator"<<endl;
    }

    return 0;
}