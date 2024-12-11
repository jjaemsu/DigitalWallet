#include "DigitalWallet.h"



// ���� �߰�
void Wallet::addCoin(const Coin& coin) {
    coins.push_back(coin);
}

// ���� �߰�
void Wallet::addCash(const Cash& cash) {
    cashes.push_back(cash);
}   

// �ܾ� ���
void Wallet::printBalance() {
    cout << "���� �ܰ�:" << endl;
    for (const auto& c : cashes) {
        c.print();
    }
    cout << "���� �ܰ�:" << endl;
    for (const auto& coin : coins) {
        coin.print();
    }
}


// �ŷ� ��� ��� �� ���� �����
void Wallet::saveTransactionToFile(const string& log) { 
    ofstream outFile(transactionFile, ios::app); // ������ append ���� ���� ������ �����θ����
    if (outFile.is_open()) {
        outFile << log << endl;
        outFile.close();
    }
    else {
        cout << "�ŷ� ������ ������ �� �����ϴ�." << endl;
    }
}
void Wallet::loadTransactionFromFile() {
    ifstream inFile(transactionFile); // ���� �б� ���� ����
    if (inFile.is_open()) {
        cout << "�ŷ� ����:" << endl;
        string line;
        while (getline(inFile, line)) {
            cout << line << endl;
        }
        inFile.close();
    }
    else {
        cout << "�ŷ� ��� ������ �� �� �����ϴ�." << endl;
    }
}


// ���� �˻�: Ÿ���� �������� �ش� ������ ��ȯ
Coin* Wallet::getCoinByType(const string& type) {
    for (auto& coin : coins) {
        if (coin.getType() == type) {
            return &coin; // ���ǿ� �´� ���� ��ȯ
        }
    }
    return nullptr; // ���ǿ� �´� ������ ���� ���
}

// ���� �˻�: ��ȭ�� �������� �ش� ������ ��ȯ
Cash* Wallet::getCashByCurrency(const string& currency) {
    for (auto& cash : cashes) {
        if (cash.getCurrency() == currency) {
            return &cash; // ���ǿ� �´� ���� ��ȯ
        }
    }
    return nullptr; // ���ǿ� �´� ������ ���� ���
}


// ���� ����
void Wallet::payWithCoin() {
    cout << "��� ������ ����:" << endl;
    for (const auto& coin : coins) {
        coin.print();
    }

    string coinType;
    cout << "���� ������ �Է��ϼ���: ";
    cin >> coinType;

    Coin* selectedCoin = getCoinByType(coinType);
    if (!selectedCoin) {
        cout << "�ش� ������ �����ϴ�." << endl;
        return;
    }

    double amount;
    cout << "���� �ݾ� �Է�: ";
    cin >> amount;

    if (amount > selectedCoin->getAmount()) {
        cout << "�ܾ��� �����մϴ�." << endl;
        return;
    }

    *selectedCoin -= amount;
    saveTransactionToFile(coinType + " ���� ����: " + to_string(amount));
    CoinPayment payment;
    payment.pay(coinType, amount);
}

// ���� ����
void Wallet::payWithCash() {
    cout << "��� ������ ����:" << endl;
    for (const auto& cash : cashes) {
        cash.print();
    }

    string currency;
    cout << "ȭ�� ������ �Է��ϼ���: ";
    cin >> currency;

    Cash* selectedCash = getCashByCurrency(currency);
    if (!selectedCash) {
        cout << "�ش� ȭ�� �����ϴ�." << endl;
        return;
    }

    double amount;
    cout << "���� �ݾ� �Է�: ";
    cin >> amount;

    if (amount > selectedCash->getAmount()) {
        cout << "�ܾ��� �����մϴ�." << endl;
        return;
    }

    *selectedCash -= amount;
    saveTransactionToFile(currency + " ���� ����: " + to_string(amount));
    CashPayment payment;
    payment.pay(currency, amount);
}

// ���� ó�� �޼���
void Wallet::makePayment() {
    int type;
    cout << "���� ��� ����: 1.���� 2.����" << endl;
    cin >> type;

    if (type == 1) {
        payWithCoin();
    }
    else if (type == 2) {
        payWithCash();
    }
    else {
        cout << "�߸��� �����Դϴ�." << endl;
    }
}
