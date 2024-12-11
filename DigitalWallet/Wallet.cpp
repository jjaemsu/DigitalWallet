#include "DigitalWallet.h"



// 코인 추가
void Wallet::addCoin(const Coin& coin) {
    coins.push_back(coin);
}

// 현금 추가
void Wallet::addCash(const Cash& cash) {
    cashes.push_back(cash);
}   

// 잔액 출력
void Wallet::printBalance() {
    cout << "현금 잔고:" << endl;
    for (const auto& c : cashes) {
        c.print();
    }
    cout << "코인 잔고:" << endl;
    for (const auto& coin : coins) {
        coin.print();
    }
}


// 거래 기록 출력 및 파일 입출력
void Wallet::saveTransactionToFile(const string& log) { 
    ofstream outFile(transactionFile, ios::app); // 파일을 append 모드로 열기 포인터 끝으로만들기
    if (outFile.is_open()) {
        outFile << log << endl;
        outFile.close();
    }
    else {
        cout << "거래 내용을 저장할 수 없습니다." << endl;
    }
}
void Wallet::loadTransactionFromFile() {
    ifstream inFile(transactionFile); // 파일 읽기 모드로 열기
    if (inFile.is_open()) {
        cout << "거래 내역:" << endl;
        string line;
        while (getline(inFile, line)) {
            cout << line << endl;
        }
        inFile.close();
    }
    else {
        cout << "거래 기록 파일을 열 수 없습니다." << endl;
    }
}


// 코인 검색: 타입을 기준으로 해당 코인을 반환
Coin* Wallet::getCoinByType(const string& type) {
    for (auto& coin : coins) {
        if (coin.getType() == type) {
            return &coin; // 조건에 맞는 코인 반환
        }
    }
    return nullptr; // 조건에 맞는 코인이 없을 경우
}

// 현금 검색: 통화를 기준으로 해당 현금을 반환
Cash* Wallet::getCashByCurrency(const string& currency) {
    for (auto& cash : cashes) {
        if (cash.getCurrency() == currency) {
            return &cash; // 조건에 맞는 현금 반환
        }
    }
    return nullptr; // 조건에 맞는 현금이 없을 경우
}


// 코인 결제
void Wallet::payWithCoin() {
    cout << "사용 가능한 코인:" << endl;
    for (const auto& coin : coins) {
        coin.print();
    }

    string coinType;
    cout << "코인 종류를 입력하세요: ";
    cin >> coinType;

    Coin* selectedCoin = getCoinByType(coinType);
    if (!selectedCoin) {
        cout << "해당 코인이 없습니다." << endl;
        return;
    }

    double amount;
    cout << "결제 금액 입력: ";
    cin >> amount;

    if (amount > selectedCoin->getAmount()) {
        cout << "잔액이 부족합니다." << endl;
        return;
    }

    *selectedCoin -= amount;
    saveTransactionToFile(coinType + " 코인 결제: " + to_string(amount));
    CoinPayment payment;
    payment.pay(coinType, amount);
}

// 현금 결제
void Wallet::payWithCash() {
    cout << "사용 가능한 현금:" << endl;
    for (const auto& cash : cashes) {
        cash.print();
    }

    string currency;
    cout << "화폐 종류를 입력하세요: ";
    cin >> currency;

    Cash* selectedCash = getCashByCurrency(currency);
    if (!selectedCash) {
        cout << "해당 화폐가 없습니다." << endl;
        return;
    }

    double amount;
    cout << "결제 금액 입력: ";
    cin >> amount;

    if (amount > selectedCash->getAmount()) {
        cout << "잔액이 부족합니다." << endl;
        return;
    }

    *selectedCash -= amount;
    saveTransactionToFile(currency + " 현금 결제: " + to_string(amount));
    CashPayment payment;
    payment.pay(currency, amount);
}

// 결제 처리 메서드
void Wallet::makePayment() {
    int type;
    cout << "결제 방법 선택: 1.코인 2.현금" << endl;
    cin >> type;

    if (type == 1) {
        payWithCoin();
    }
    else if (type == 2) {
        payWithCash();
    }
    else {
        cout << "잘못된 선택입니다." << endl;
    }
}
