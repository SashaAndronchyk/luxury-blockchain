#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

class Transaction {
public:
    std::string fromAddress;
    std::string toAddress;
    double amount;

    Transaction(std::string from, std::string to, double amt);
};

#endif