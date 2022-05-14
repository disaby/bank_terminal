#ifndef BANK_H
#define BANK_H
#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <unistd.h>
#include "user.h"

class bank
{
private:
    list<user> database;
public:
    bank();
    void Check();
    void Import();
    void Withdraw();
    void Deposit();
    void ModifyPin();
    void Show();
    void Transfer();
    void Export();
};

#endif // BANK_H
