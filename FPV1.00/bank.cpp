//bank.cpp
#include "bank.h"
#include <list>
#include <string>

using namespace std;

//Global variables
string cardNumber, pincode;
string id, name, balance, last_transaction;

bank::bank() = default;

//
bool isNumber(const string& str)
{
    for (char const &c : str) {
        if (isdigit(c) == 0) return false;
    }
    return true;
}

void bank::Check() //checks weather input bankcard and PIN are match with database
{
    bool match = false;
    list<user>::iterator it;
    cout<<setw(50)<<"Welcome to the Bank of <DKA>" << endl<< endl;
    cout << "Card number (6 digits): ";
    cin>> cardNumber;
    cout << "PIN code (4 digits): ";
    cin>> pincode;
    for(it=database.begin();it!=database.end();++it)
    {
        if(cardNumber==(*it).get_card_number()&&pincode==(*it).get_pin())
        {
            match=true;
            id=(*it).get_id();
            name=(*it).get_name();
            balance=(*it).get_balance();
            last_transaction=(*it).get_last_transaction();
            break;
        }
    }
    if (match!=true)
    {
        do
        {
            system("cls");
            cout <<setw(50)<< "Welcome to the Bank of <DKA>" << endl<< endl;
            cout<<"The card number or PIN code is incorrect. Try again!"<<endl;
            cout << "Card number (6 digits): ";
            cin>> cardNumber;
            cout << "PIN code (4 digits): ";
            cin>> pincode;
            for(it=database.begin();it!=database.end();++it)
            {
                if(cardNumber==(*it).get_card_number()&&pincode==(*it).get_pin())
                {
                    match=true;
                    id=(*it).get_id();
                    name=(*it).get_name();
                    balance=(*it).get_balance();
                    last_transaction=(*it).get_last_transaction();
                }
            }
        } while(match!=true);
    }
    system("cls");
    cout<<name<<endl<<endl;
}

void bank:: Import()
{
    fstream MyFile;
    MyFile.open("database.csv");
    while(MyFile.good())
    {
        user person;
        string d_id;
        string d_name;
        string d_card_number;
        string d_pin;
        string d_balance;
        string d_last_transaction;
        getline(MyFile, d_id, ',');
        person.set_id(d_id);
        getline(MyFile, d_name, ',');
        person.set_name(d_name);
        getline(MyFile, d_card_number, ',');
        person.set_card_number(d_card_number);
        getline(MyFile, d_pin, ',');
        person.set_pin(d_pin);
        getline(MyFile, d_balance, ',');
        person.set_balance(d_balance);
        getline(MyFile, d_last_transaction, '\n');
        person.set_last_transaction(d_last_transaction);
        database.push_back(person);
    }
     database.pop_back();
}

void bank::Withdraw()
{
    if(isNumber(pincode))
    {
        int cb=stoi(balance),wd;
        string w;
        cout<<setw(50)<<"The bank of <DKA>"<<endl<<endl;
        cout<<"Current balance:\t\t"<<cb<<" KZT";
        cout<<"\n\nEnter amount to withdraw:\t";
        cin>>wd;
        while(wd>cb)
        {
            system("cls");
            cout<<setw(50)<<"The bank of <DKA>"<<endl<<endl;
            cout<<"Not enough money in your balance. \n\n";
            cout<<"Current balance:\t\t"<<cb<<" KZT";
            cout<<"\n\nEnter amount to withdraw:\t";
            cin>>wd;
        }
        cb=cb-wd;
        balance=to_string(cb);
        last_transaction="-"+to_string(wd);
        list<user>::iterator it;
        for(it=database.begin();it!=database.end();++it)
        {
            if(cardNumber==(*it).get_card_number())
            {
                (*it).set_balance(balance);
                (*it).set_last_transaction(last_transaction);
            }
        }
        system("cls");
        cout<<setw(50)<<"The bank of <DKA>"<<endl<<endl;
        cout<<"Cash withdrawn successfully!"<<endl;
        cout<<"Remaining balance: "<<cb<<" KZT\n\n";
    }
    else
    {
        cout<<"\nTo use transfer option you should activate your card. Modify your PIN!"<<endl;
    }
}

void bank::Deposit()
{
    if(isNumber(pincode))
    {
        int cb=stoi(balance),dp;
        cout<<setw(50)<<"The bank of <DKA>"<<endl<<endl;
        cout<<"Current balance:\t\t"<<cb<<" KZT";
        cout<<"\n\nEnter amount to withdraw:\t";
        cin>>dp;
        cb=cb+dp;
        balance=to_string(cb);
        last_transaction=to_string(dp);
        list<user>::iterator it;
        for(it=database.begin();it!=database.end();++it)
        {
            if((*it).get_card_number()==cardNumber)
            {
                (*it).set_balance(balance);
                (*it).set_last_transaction(last_transaction);
            }
        }
        system("cls");
        cout<<setw(50)<<"The bank of <DKA>"<<endl<<endl;
        cout<<"Cash deposited successfully!"<<endl;
        cout<<"Remaining balance: "<<cb<<" KZT\n\n";
    }
    else
    {
        cout<<"\nTo use transfer option you should activate your card. Modify your PIN!"<<endl;
    }
}

void bank::ModifyPin()
{
    system("cls");
    string new_pin;
    bool tr=false;
    do
    {
        system("cls");
        cout<<setw(50)<<"The bank of <DKA>"<<endl<<endl;
        if(tr) cout<<"Failed! "<<endl; //if it is not first try to put in new PIN
        cout<<"You should enter 4-digit PIN."<<endl;
        tr=true;
        cout<<"Enter new PIN: ";
        cin>>new_pin;
    }
    while(isNumber(new_pin)==false || new_pin.size()!=4);
    list<user>::iterator it;
    for(it=database.begin();it!=database.end();++it)
    {
        if((*it).get_card_number()==cardNumber)
        {
            (*it).set_pin(new_pin);
            pincode=new_pin;
            cout<<"\nNew PIN accepted!"<<endl;
        }
    }
}

void bank::Show()
{
    int usd=stoi(balance)/450;
    cout<<setw(50)<<"The bank of <DKA>"<<endl<<endl;
    cout<<"Card owner: "<<name<<endl;
    cout<<"Card number: "<<cardNumber<<endl;
    cout<<"Card balance in KZT: "<<balance<<endl;
    cout<<"Card balance in USD: "<<usd<<endl;
    cout<<"Last transaction: "<<last_transaction<<endl<<endl;
}

void bank::Transfer()
{
    string receiver, letter;
    int transfer_money, comission, sum, a;
    if(isNumber(pincode)==true)
    {
        cout<<setw(50)<<"The bank of <DKA>"<<endl<<endl;
        cout<<"**Comissions for fund transfers over 20,000 KZT is 500 KZT"<<endl<<endl;
        cout<<"Benefficiary's card number: ";
        cin>>receiver;
        list<user>::iterator it;
        for(it=database.begin();it!=database.end();++it)
            {
                if((*it).get_card_number()==receiver)
                    {
                        cout<<"Transfer amount (in KZT): ";
                        cin>>transfer_money;
                        if(transfer_money>stoi(balance))
                            {
                            do
                                {
                                cout<<"**Comissions for fund transfers over 20,000 KZT is 500 KZT\nNot enough balance. Try again!"<<endl<<endl;
                                cin>>transfer_money;
                                }while(transfer_money>stoi(balance));
                            }
                        if((*it).get_id()==id)
                        {
                            comission = 0;
                        }
                        else
                        {
                            comission = 200;
                        }
                        if(transfer_money>20000)
                        {
                            comission = comission + 500;
                        }
                        cout<<"Beneficiary`s name: "<<(*it).get_name()<<endl;
                        cout<<"Confirm transfer? (Y/N): ";
                        cin>>letter;
                        while(letter!="Y" && letter!="y" && letter!="N" && letter!="n")
                        {
                            cout<<"\rConfirm transfer? (Y/N): ";
                            cin>>letter;
                        }
                        if(letter=="Y"||letter=="y")
                        {
                            a = stoi((*it).get_balance())+transfer_money;
                            sum=-transfer_money-comission;
                            last_transaction=to_string(sum);
                            (*it).set_last_transaction(to_string(transfer_money));
                            (*it).set_balance(to_string(a));
                            cout<<"\nTransfer successful!"<<endl;
                        }
                        else
                        {
                        break;
                        }
                    }
            }
            for(it=database.begin();it!=database.end();++it)
                    {
                        if((*it).get_card_number()==cardNumber)
                            {
                                int int_balance=stoi(balance)+sum;
                                string s=to_string(int_balance);
                                (*it).set_balance(s);
                                balance=s;
                                s="-"+to_string(sum);
                                (*it).set_last_transaction(s);
                                break;
                            }
                    }
    }
    else
    {
        cout<<"\nTo use transfer option you should activate your card. Modify your PIN!"<<endl;
    }
}

void bank::Export()
{
    ofstream file_save;
    file_save.open("database.csv");
    list<user>::iterator it;
    for(it=database.begin();it!=database.end();it++)
    {
        file_save<<(*it).get_id()<<","<<(*it).get_name()<<","<<(*it).get_card_number()<<","<<(*it).get_pin()<<","<<(*it).get_balance()<<","<<(*it).get_last_transaction()<<"\n";
    }
}
