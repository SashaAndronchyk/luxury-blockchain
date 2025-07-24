#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include "Block.h"
#include <vector>

class Blockchain {
private:
    std::vector<Block> chain;
    std::vector<Transaction> pendingTransactions;

public:
    Blockchain();

    void addTransaction(const std::string& from, const std::string& to, double amount);
    void mineBlock();
    void print() const;
};

#endif