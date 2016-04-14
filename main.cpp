#include <iostream>
#include <iomanip>

using namespace std;
//Defining the variables for the program, names self-explantory
char typeOfService;
double bill = 0;
double regularServiceFlatRate = 10.00;
double regularServiceCharge = 0.20;
double premiumDayServiceCharge = 0.10;
double premiumNightServiceCharge = 0.05;
double PremiumServiceFlatRate = 25.00;
double extraRegularRate = 0.0;
double extraDayRate = 0.0;
double extraNightRate = 0.0;
string regularService = "Regular";
string premiumService = "Premium";
double minutes;
double dayMinutes;
double nightMinutes;
int accountNumber;



int main()
{
    // Make sure theres a decimal point for units that need them such as money
    cout << showpoint << fixed;
    cout << "Enter your Account number: ";
    cin >> accountNumber;
    cout << "What type of service? Enter r for regular service or p for premium service: ";
    cin >> typeOfService;
    //asking user the type of service
    if(typeOfService == 'r' || typeOfService == 'R') {
        //regular service
        cout << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Type of Service: " + regularService << endl;
        cout << "The flat rate is $" << setprecision(2) << regularServiceFlatRate << endl;
        cout << "The first 50 minutes are free and you are charged $" << setprecision(2) << regularServiceCharge << " per minute after 50 minutes." << endl;
        //asking user to enter the minutes
        cout <<"Enter amount of minutes customer used: ";
        cin >> minutes;
        if(minutes <= 50) {
            //bill does not change from the flat rate
            bill = regularServiceFlatRate;
            cout << noshowpoint << setprecision(0) << fixed;
            cout << "Customer used " << minutes << " minutes" << endl;
            cout << showpoint << setprecision(2);
            cout << "Extra minute charge total charge: $" << extraRegularRate << endl;
            cout << "Amount Due: $" << bill << endl;
        }
        if(minutes > 50) {
            //bill will increase every extra minute used by $0.20
            extraRegularRate = (minutes - 50) * regularServiceCharge;
            bill = regularServiceFlatRate + extraRegularRate;
            cout << noshowpoint << setprecision(0) << fixed;
            cout << "Customer used " << minutes << " minutes" << endl;
            cout << showpoint << setprecision(2);
            cout << "Extra minute charge total charge: $" << extraRegularRate << endl;
            cout << "Amount Due: $" << bill << endl;
        }
    }
    // if p is entered go to premium service
    else if(typeOfService == 'p' || typeOfService == 'P') {
        cout << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Type of Service: " + premiumService << endl;
        cout << "The flat rate is $" << setprecision(2) << PremiumServiceFlatRate << endl;
        cout << "From 6:00am to 6:00pm, the first 75 minutes are free then you charged $" << setprecision(2) << premiumDayServiceCharge << " per minute after 75 minutes." << endl;
        cout << endl;
        cout << "From 6:00pm to 6:00am, the first 100 minutes are free then you charged $" << setprecision(2) << premiumNightServiceCharge << " per minute after 100 minutes." << endl;
    //enter amount of minutes for day
        cout << endl;
        cout <<"Enter amount of minutes customer used during the day: ";
        cin >> dayMinutes;
        //if the minutes is less than 75, same as the flat rate
        if(dayMinutes <= 75) {
            bill = PremiumServiceFlatRate;
            cout << noshowpoint << setprecision(0) << fixed;
            cout << "Customer used " << dayMinutes << " day minutes" << endl;

        }
        //calculate the bill for the day minutes
        if(dayMinutes > 75) {
            extraDayRate = (dayMinutes - 75) * premiumDayServiceCharge;
            bill = PremiumServiceFlatRate + extraDayRate;
            cout << noshowpoint << setprecision(0) << fixed;
            cout << "Customer used " << dayMinutes << " day minutes" << endl;



        }
        //taking in night minutes
        cout <<"Enter amount of minutes customer used during the night: ";
        cin >> nightMinutes;
        //bill will remain the same if minutes don't exceed the free minutes allowed
        if(nightMinutes <= 100) {
        bill = bill;
        cout << noshowpoint << setprecision(0) << fixed;
        cout << "Customer used " << nightMinutes << " night minutes" << endl;

        }
        //The extra minutes will be added on to the current bill from the day, no need to apply flat rate again
        if(nightMinutes > 100) {
            extraNightRate = (nightMinutes - 100) * premiumNightServiceCharge;
            bill = bill + extraNightRate;
            cout << noshowpoint << setprecision(0) << fixed;
            cout << "Customer used " << nightMinutes << " night minutes" << endl;



        }
        cout << endl;
        cout << "Total Minutes: " << dayMinutes + nightMinutes << endl;
        cout << showpoint << setprecision(2);
        cout << "Extra day minute charge total charge: $" << extraDayRate << endl;
        cout << "Extra night minute charge total charge: $" << extraNightRate << endl;
        cout << "Extra total minute charge total charge: $" << extraDayRate + extraNightRate << endl;
        cout << "Amount Due: $" << bill << endl;
    }
    //if user does not enter a valid service to being with, program will tell you to enter a valid one
    else {
        cout << "Enter a valid service please" << endl;
    }





    return 0;
}
