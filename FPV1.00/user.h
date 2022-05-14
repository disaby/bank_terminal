#ifndef USER_H
#define USER_H
#include <iostream>

using namespace std;

class user
{
private:
    string id;
    string name;
    string card_number;
    string pin;
    string balance;
    string last_transaction;
public:
    user();
//getters
    string get_id();
    string get_name();
    string get_card_number();
    string get_pin();
    string get_balance();
    string get_last_transaction();
//setters
    void set_id(string id);
    void set_name(string name);
    void set_card_number(string card_number);
    void set_pin(string pin);
    void set_balance(string balance);
    void set_last_transaction(string last_transaction);

};

#endif // USER_H
