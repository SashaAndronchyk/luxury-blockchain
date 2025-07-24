#include "blockchain/Blockchain.h"
#include <iostream>

int main() {
    Blockchain luxuryChain;

    luxuryChain.addTransaction("Alice", "Bob", 10.5);
    luxuryChain.addTransaction("Bob", "Charlie", 4.25);

    luxuryChain.mineBlock();
    luxuryChain.print();

    return 0;
}