#ifndef BLOCK_H
#define BLOCK_H

#include "Transaction.h"
#include <vector>
#include <string>

class Block {
public:
    int index;
    std::string previousHash;
    std::string hash;
    std::vector<Transaction> transactions;

    Block(int idx, std::string prevHash);

    void addTransaction(const Transaction& tx);
    std::string calculateHash() const;
    void print() const;
};

#endif