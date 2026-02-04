cmake_minimum_required(VERSION 3.16)

project(BankingSystem LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(BankingSystem main.cpp
    account.h account.cpp)

include(GNUInstallDirs)
install(TARGETS BankingSystem
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
