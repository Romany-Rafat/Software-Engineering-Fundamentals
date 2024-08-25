#include <iostream>

using namespace std;
///(powerOn(), makeCall(), browseInternet()).
class device
{
public:
    void powerOn()
    {
        cout<<"power on\n";
    }
};
class phone:public device
{
public:
    void makeCall()
    {
        cout<<"makeCall\n";
    }
};
class smartPhone:public phone
{
public:
    void browseInternet()
    {
        cout<<"browse Internet\n";
    }
};
int main()
{

    smartPhone p1;
    p1.browseInternet();
    p1.makeCall();
    p1.powerOn();

    return 0;
}
