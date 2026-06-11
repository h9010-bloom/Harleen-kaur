#include<iostream>
using namespace std;
class rectangle
{
    int length;
    int breadth;
    public:
    void setdata(int l, int b)
    {
        length=l;
        breadth=b;
    }
    friend void getdata();
    
    void getdata()
    {
        int area=length*breadth;
        cout<<"area is:"<<area<<endl;
    }
};
int main()
{
    rectangle r;
    r.setdata(12,14);
    r.getdata();
    return 0;
}