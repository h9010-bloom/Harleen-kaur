#include <iostream> 
using namespace std;
class ITEM
{
    public:
        string product_name;
        int price;
};
class Shopping_Cart
{
    public:
    ITEM item;
};
int main()
{
    Shopping_Cart mall;
    mall.item.product_name = "pens";
    mall.item.price = 50;

    cout<<"ITEM: "<< mall.item.product_name<<endl;
    cout<< "ITEM PRICE: "<< mall.item.price<<endl;
    return 0;
}