#include "DigitalWallet.h"

Coin::Coin(string type, double amount) : type(type), amount(amount) {}

Coin::Coin(string type) : type(type), amount(0){} // 타입만 받고, 개수는 0

void Coin::print() const {
    cout << type << ": " << amount << endl;
}

string Coin::getType() const {
    return type;
}

double Coin::getAmount() const {
    return amount;
}


//연산자 중복
Coin& Coin::operator-=(double value) {
    if (amount >= value) {
        this->amount -= value;
    }

    else {
        cout << "잔액이 부족합니다. 코인 차감 실패!" << endl;
    }
    return *this;
}
