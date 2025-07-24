#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <chrono>
#include <thread>

// Simple transaction
struct Transaction {
    std::string from;
    std::string to;
    double ounces;
};

// Simple block
struct Block {
    int index;
    std::string previousHash;
    std::string hash;
    std::vector<Transaction> transactions;

    Block(int idx, const std::string& prevHash) : index(idx), previousHash(prevHash) {
        hash = calculateHash();
    }

    std::string calculateHash() const {
        std::stringstream ss;
        ss << index << previousHash;
        for (const auto& tx : transactions)
            ss << tx.from << tx.to << tx.ounces;
        return std::to_string(std::hash<std::string>{}(ss.str()));
    }

    void print() const {
        std::cout << "Block #" << index << "\nHash: " << hash
                  << "\nPrevious: " << previousHash << "\nTransactions:\n";
        for (const auto& tx : transactions)
            std::cout << "  " << tx.from << " -> " << tx.to << " : " << tx.ounces << " oz gold\n";
        std::cout << std::endl;
    }
};

// Simple blockchain
class Blockchain {
    std::vector<Block> chain;
public:
    Blockchain() {
        chain.emplace_back(0, "GENESIS");
    }

    void addTransaction(const std::string& from, const std::string& to, double ounces) {
        Block& last = chain.back();
        Block newBlock(chain.size(), last.hash);
        newBlock.transactions.push_back({from, to, ounces});
        chain.push_back(newBlock);
    }

    void print() const {
        for (const auto& block : chain)
            block.print();
    }
};

int main() {
    Blockchain goldChain;
    int counter = 1;

    while (true) {
        std::string to = "User" + std::to_string(counter++);
        goldChain.addTransaction("Mint", to, 1.0);
        goldChain.print();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}