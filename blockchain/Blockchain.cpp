#include "Blockchain.h"
#include <iostream>

Blockchain::Blockchain() {
    chain.emplace_back(0, "GENESIS");
}

void Blockchain::addTransaction(const std::string& from, const std::string& to, double amount) {
    pendingTransactions.emplace_back(from, to, amount);
}

void Blockchain::mineBlock() {
    int index = chain.size();
    std::string prevHash = chain.back().hash;
    Block newBlock(index, prevHash);

    for (const auto& tx : pendingTransactions)
        newBlock.addTransaction(tx);

    pendingTransactions.clear();
    chain.push_back(newBlock);

    std::cout << "Block mined!\n";
}

void Blockchain::print() const {
    for (const auto& block : chain)
        block.print();
}
