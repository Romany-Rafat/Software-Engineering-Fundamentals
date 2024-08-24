#include <iostream>

using namespace std;
class date
{
private:
    int Day,Year,Month;
public:
    date(int Day=0,int Month=0,int Year=0)
    {
        this->Day=Day;
        this->Month=Month;
        this->Year=Year;
    }
    void setDay(int Day)
    {
        this->Day=Day;
    }
    void setMonth(int Month)
    {
        this->Month=Month;
    }
    void setYear(int Year)
    {
        this->Year=Year;
    }
    int getDay()
    {
        return Day;
    }
    int getMonth()
    {
        return Month;
    }
    int getYear()
    {
        return Year;
    }
    int subDate(date d1)
    {
        int days=0;
        days+=abs(d1.getDay()-Day);
        days+=abs(d1.getMonth()-Month)*30;
        days+=abs(d1.getYear()-Year)*365;
        return days;
    }
    void print()
    {
        cout<<Month<<"/"<<Day<<"/"<<Year<<endl;
    }
};
int main()
{
    date d1(20,1,2004),d2(20,10,2006);
    d1.print();
    d2.print();
    cout<<d1.subDate(d2)<<endl;

    return 0;
}
