#include<iostream>
#include<string>
using namespace std;
class book
{
    public:
    void bookdata()
    {
        string title="The Flawless love";
        string author="Shinshinye";
        int ISBN=1234;

        cout<<"TITLE: "<<title<<endl;
        cout<<"Author: "<<author<<endl;
        cout<<"ISBN C code: "<<ISBN<<endl;
    }
};
class publisher
{
    public:
    void publisherdata()
    {
        string publishername="WEBTOON";
        string publisheraddress="NAVER WEBTOON LTD., NAVER Green Factory 6-10F, Buljeong-ro, Bundango,Seongnam-si, Gyeonggi-do,Republic of korea";

        cout<<"Publisher name: "<<publishername<<endl;
        cout<<"Publisher address: "<<publisheraddress<<endl;
    }
};
class librarybook:public book, public publisher
{
    public:
    void librarybookdata()
    {
        string shelfnumber="A12";
        string availabilitystatus="Available";

        cout<<"Shelf Number: "<<shelfnumber<<endl;
        cout<<"Availability status: "<<availabilitystatus<<endl;
    }
};
int main()
{
    librarybook lb;
    lb.bookdata();
    lb.publisherdata();
    lb.librarybookdata();
}