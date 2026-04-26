#include <iostream>
using namespace std;

class DateException{
    string message;

    public:
    DateException(string message){
        this->message = message;
    }
    string what(){
        return message;
    }
};

class Date{

    int day,month,year;
    public:
    Date():day(0),month(0),year(0){}
    void SetDate(){
        cout<< "Enter Day: ";
        cin>>day;
        if(day<1 || day>31){
            throw DateException("Invalid day");
        }
        
        cout<< "Enter Month: ";
        cin>>month;
        if(month<1 || month>12){
            throw DateException("Invalid month");
        }
        if (month == 2 && day > 29){
            throw DateException("Invalid day for February");
        }
        if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30){
            throw DateException("Invalid day for the given month");
        }

        cout<< "Enter Year: ";
        cin>>year;
        if(year<0){
            throw DateException("Invalid year");
        }

        if (month == 2 && day == 29){
            if ((year % 4 != 0) || (year % 100 == 0 && year % 400 != 0)){
                throw DateException("Invalid day for February in a non-leap year");
            }
        }
        cout<< "Date is: "<< day<<"/"<<month<<"/"<<year;
    }
};

    int
    main()
{
    Date date;
    try
    {
        date.SetDate();
    }
    catch (DateException e)
    {
        cout << e.what();
    }
    return 0;
}