#include "Block.h"
#include <sstream>
#include <iostream>

Block::Block(int idx, std::string prevHash)
    : index(idx), previousHash(std::move(prevHash)) {
    hash = calculateHash();
}

void Block::addTransaction(const Transaction& tx) {
    transactions.push_back(tx);
    hash = calculateHash();
}

std::string Block::calculateHash() const {
    std::stringstream ss;
    ss << index << previousHash;
    for (const auto& tx : transactions)
        ss << tx.fromAddress << tx.toAddress << tx.amount;
    return std::to_string(std::hash<std::string>{}(ss.str()));
}

void Block::print() const {
    std::cout << "Block #" << index << "\nHash: " << hash
              << "\nPrevious: " << previousHash << "\nTransactions:\n";
    for (const auto& tx : transactions)
        std::cout << "  " << tx.fromAddress << " -> " << tx.toAddress
                  << " : " << tx.amount << "\n";
    std::cout << std::endl;
}