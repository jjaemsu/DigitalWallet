#include "DigitalWallet.h"

Cash::Cash(string currency, double amount) : currency(currency), amount(amount) {}

Cash::Cash(string currency) : currency(currency), amount(0){} // 타입만 받고 개수는 0

void Cash::print() const {
    cout << currency << ": " << amount << endl;
}

string Cash::getCurrency() const {
    return currency;
}

double Cash::getAmount() const {
    return amount;
}

//연산자 중복
Cash& Cash::operator-=(double value) {
    if (amount >= value) {
        this->amount -= value;
    }

    else {
        cout << "잔액이 부족합니다. 현금 차감 실패!" << endl;
    }
    return *this;
}
