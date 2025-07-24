#include "Transaction.h"

Transaction::Transaction(std::string from, std::string to, double amt)
    : fromAddress(std::move(from)), toAddress(std::move(to)), amount(amt) {}