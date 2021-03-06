/*
    Algorithm
    1) start
    2) create class Date
    3) create a function to get date as input from user
    4) create a function to check wether the year is leap or not
    5) create a function to check the validity of entered date
    6) print validity of date
    7) create a function to print next date
    8) make a object from class Date and call the functions to execute programme
    9) stop
*/
#include <iostream>
using namespace std;

class Date {
    private:
    int day, month, year;
    int maxdays[13] = {29,31,28,31,30,31,30,31,31,30,31,30,31};

    public:
    void enter()
    {
        cout << "Enter Day: ";
        cin >> day;

        cout << "Enter Month: ";
        cin >> month;

        cout << "Enter year: ";
        cin >> year;
    }
    bool leapTest()
    {
        return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    }

    bool Datecheck()
    {
        if(leapTest() && month==2 && day>0 && day<30 && year > 0 || day > 0 && day <= maxdays[month] && year > 0)
        {
            return true;
        }
        else
        {
            return false;
        }        
    }

    void Output(){
        if(Datecheck())
        {
            cout << "Valid \n";
        }
        else
        {
            cout << "Not valid \n";
        }
    }

    void nextDate()
    {
       if (Datecheck())
       {
            if(day != maxdays[month])
            {
                cout << "Next Date: " << day+1 << "/" << month << "/" << year << endl;
            }

            else if(day = maxdays[month])
            {
                
                if(month == 12)
                {
                    cout << "Next Date: " << "1" << "/" << "1" << "/" << year+1 << endl;
                }
                else if(month !=2 && month != 12)
                {
                    cout << "Next Date: " << day+1 << "/" << month << "/" << year << endl;
                }
            }  

            else if(leapTest() && month == 2 && day == 29)
                {
                    cout << "Next Date: " << "1" << "/" << "3" << "/" << year << endl;
                } 
       }
    }
};

int main()
{
    Date dateGet;
    dateGet.enter();
    dateGet.Datecheck();
    dateGet.Output();
    dateGet.nextDate();
    return 0;
}