cmake_minimum_required(VERSION 3.10)
project(LuxuryBlockchain)

set(CMAKE_CXX_STANDARD 17)

include_directories(blockchain)

add_executable(LuxuryBlockchain
        main.cpp
        blockchain/Transaction.cpp
        blockchain/Block.cpp
        blockchain/Blockchain.cpp
)