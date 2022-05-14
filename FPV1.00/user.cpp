#include "user.h"

user::user() = default;

string user:: get_id()
{
    return this->id;
}

string user:: get_name()
{
    return this->name;
}

string user:: get_card_number()
{
    return this->card_number;
}

string user:: get_pin()
{
    return this->pin;
}

string user:: get_balance()
{
    return this->balance;
}

string user:: get_last_transaction()
{
    return this->last_transaction;
}

void user::set_id(string id)
{
    this->id=id;
}

void user::set_name(string name)
{
    this->name=name;
}

void user::set_card_number(string card_number)
{
    this->card_number=card_number;
}

void user:: set_pin(string pin)
{
    this->pin=pin;
}

void user:: set_balance(string balance)
{
    this->balance=balance;
}

void user:: set_last_transaction(string last_transaction)
{
    this->last_transaction=last_transaction;
}

