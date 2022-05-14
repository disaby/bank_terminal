//main.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <windows.h>
#include <stdlib.h>
#include "bank.h"

using namespace std;

bool again =false;
bank banking;


void Process()
{
    system("cls"); //clears console
    int choice=0;   //option chosen by User
  do
    {
    cout <<setw(50)<<"Welcome to the Bank of <DKA>" << endl<< endl;
    cout<<" Select one of the following options: \n";
    cout<< "  1. Withdraw Cash"<<setw(30)<<" 2. Deposit Cash"<<endl;
    cout<< "  3. Modify PIN Code"<<setw(28)<<"4. Show Balance"<<endl;
    cout<< "  5. Transfer Between Accounts"<<setw(17)<<"6. End Session"<<endl<<endl;
    cout<<"Enter option number: "<<endl;
    cin >> choice;
    switch(choice)
        {
        case 1:
        {
            system("cls");
            banking.Withdraw();
            string w;
            do
            {
            cout<<"Would you like to return to main menu? (Y/N) ";
            cin>>w;
            }
            while(w!="Y" && w!="y" && w!="N" && w!="n");
            if(w=="Y"||w=="y")
            {
                Process();
            }
            else
            {
                choice=6;
                break;
            }
        }
        case 2:
        {
            system("cls");
            banking.Deposit();
            cout<<"Would you like to return to main menu? (Y/N) ";
            string w;
            cin>>w;
            while(w!="Y" && w!="y" && w!="N" && w!="n")
            {
                cout<<"\rWould you like to return to main menu? (Y/N) ";
                cin>>w;
            }
            if(w=="Y"||w=="y")
            {
                Process();
            }
            else
            {
                choice=6;
                break;
            }
        }
        case 3:
        {
            system("cls");
            banking.ModifyPin();
            cout<<"Would you like to return to main menu? (Y/N) ";
            string w;
            cin>>w;
            while(w!="Y" && w!="y" && w!="N" && w!="n")
            {
                cout<<"\rWould you like to return to main menu? (Y/N) ";
                cin>>w;
            }
            if(w=="Y"||w=="y")
            {
                Process();
            }
            else
            {
                choice=6;
                break;
            }
        }

        case 4:
        {
            system("cls");
            banking.Show();
            string w;
            cout<<"Would you like to return to main menu? (Y/N) ";
            cin>>w;
            while(w!="Y" && w!="y" && w!="N" && w!="n")
            {
                cout<<"\rWould you like to return to main menu? (Y/N) ";
                cin>>w;
            }
            if(w=="Y"||w=="y")
            {
                Process();
            }
            else
            {
                choice=6;
                break;
            }
        }
        case 5:
            {
                system("cls");
                banking.Transfer();
                string w;
                cout<<"Would you like to return to main menu? (Y/N) ";
                cin>>w;
                while(w!="Y" && w!="y" && w!="N" && w!="n")
                {
                    cout<<"\rWould you like to return to main menu? (Y/N) ";
                    cin>>w;
                }
                if(w=="Y"||w=="y")
                {
                    system("cls");
                    Process();
                }
                else
                {
                    choice=6;
                    break;
                }
            }

        case 6:
            system("cls");
            break;
        default:
            system("cls");
            cout<<"No option"<<endl;
            break;
        }
        } while(choice!=6);
        system("cls");
        banking.Export();                 //export data to .csv file
        cout<<endl<<endl<<endl;
        cout<<setw(40)<<"Goodbye!"<<endl;
        sleep(3);                           //pause for 3 seconds
        system("cls");
        banking.Check();
        Process();
}


int main()
{
    HWND console = GetConsoleWindow();
    RECT ConsoleRect;
    GetWindowRect(console, &ConsoleRect);
    MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 600, 400, TRUE);     // input fixed width and height to console window
    if(again==false){banking.Import();} //import data only if it is first time of execution
    again=true;
    banking.Check();                    //to Log In
    Process();                          //main process
    return 0;
}
