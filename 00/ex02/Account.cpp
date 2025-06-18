#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

Account::Account(int initial_deposit): _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0){
    Account::_nbAccounts++;
    Account::_totalAmount+=initial_deposit;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account(void){
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
    Account::_nbAccounts--;
    Account::_totalAmount-= _amount;
}

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void) {
    return Account::_nbAccounts;
}

int Account::getTotalAmount(void) {
    return Account::_totalAmount;
}

int Account::getNbDeposits(void) {
    return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals(void) {
    return Account::_totalNbWithdrawals;
}

void Account::_displayTimestamp(void) {
    std::time_t now = std::time(0);
    std::tm* timeinfo = std::localtime(&now);
    
    std::cout << "[" 
              << std::setfill('0') 
              << std::setw(4) << (timeinfo->tm_year + 1900)
              << std::setw(2) << (timeinfo->tm_mon + 1)
              << std::setw(2) << timeinfo->tm_mday
              << "_"
              << std::setw(2) << timeinfo->tm_hour
              << std::setw(2) << timeinfo->tm_min
              << std::setw(2) << timeinfo->tm_sec
              << "] ";
}

void Account::displayAccountsInfos(void) {
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts()
            << ";amount:" << getTotalAmount()
            << ";deposits:" << getNbDeposits()
            << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::displayStatus(void) const {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
            << ";amount:" << _amount
            << ";deposits:" << _nbDeposits
            << ";withdrawals:" << _nbWithdrawals << std::endl;
}

int Account::checkAmount(void) const {
    return _amount;
}

void Account::makeDeposit(int deposit) {
    int p_amount = _amount;
    _amount += deposit;
    _nbDeposits++;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
            << ";p_amount:" << p_amount
            << ";deposit:" << deposit
            << ";amount:" << _amount
            << "nb_deposits:" << _nbDeposits << std::endl;
    _totalNbDeposits++;
} 

bool Account::makeWithdrawal(int withdrawal) {
    if(checkAmount() < withdrawal) {
        _displayTimestamp();
            std::cout << "index:" << _accountIndex
            << ";p_amount:" << _amount
            << ";whithdrawal:refused" << std::endl;
        return false;
    } else {
        int p_amount = _amount;
        _amount -= withdrawal;
        _nbWithdrawals++;
        _totalNbWithdrawals++;
        _displayTimestamp();
            std::cout << "index:" << _accountIndex
            << ";p_amount:" << p_amount
            << ";whithdrawal:" << withdrawal
            << ";amount:" << _amount
            << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
        return true;
    }
}