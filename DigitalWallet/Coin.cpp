#include "DigitalWallet.h"

Coin::Coin(string type, double amount) : type(type), amount(amount) {}

Coin::Coin(string type) : type(type), amount(0){} // Ÿ�Ը� �ް�, ������ 0

void Coin::print() const {
    cout << type << ": " << amount << endl;
}

string Coin::getType() const {
    return type;
}

double Coin::getAmount() const {
    return amount;
}


//������ �ߺ�
Coin& Coin::operator-=(double value) {
    if (amount >= value) {
        this->amount -= value;
    }

    else {
        cout << "�ܾ��� �����մϴ�. ���� ���� ����!" << endl;
    }
    return *this;
}
