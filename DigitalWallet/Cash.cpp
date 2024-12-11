#include "DigitalWallet.h"

Cash::Cash(string currency, double amount) : currency(currency), amount(amount) {}

Cash::Cash(string currency) : currency(currency), amount(0){} // Ÿ�Ը� �ް� ������ 0

void Cash::print() const {
    cout << currency << ": " << amount << endl;
}

string Cash::getCurrency() const {
    return currency;
}

double Cash::getAmount() const {
    return amount;
}

//������ �ߺ�
Cash& Cash::operator-=(double value) {
    if (amount >= value) {
        this->amount -= value;
    }

    else {
        cout << "�ܾ��� �����մϴ�. ���� ���� ����!" << endl;
    }
    return *this;
}
