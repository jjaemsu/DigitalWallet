#include "DigitalWallet.h"

// 새로운 결제 수단이 생기면 여기서 추가 가능

// CoinPayment 구현
void CoinPayment::pay(string type, double amount) {
    cout << amount << type << " 결제 완료!" << endl;
}

// CashPayment 구현
void CashPayment::pay(string type, double amount) {
    cout << amount << type << " 결제 완료!" << endl;
}
