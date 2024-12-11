#ifndef DIGITALWALLET_H
#define DIGITALWALLET_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream> // ���� ������� ���� ���̺귯��
using namespace std;

// Payment Ŭ���� (�߻� Ŭ����)
class Payment {
public: // ���� �Լ�
    virtual void pay(string type, double amount) = 0;
    virtual ~Payment() {}
};

// CoinPayment Ŭ���� (���)
class CoinPayment : public Payment {
public:
    void pay(string type, double amount) override; // �������̵�(������)
};

// CashPayment Ŭ���� (���)
class CashPayment : public Payment {
public:
    void pay(string type, double amount) override; // �������̵�(������)   
};

// Coin Ŭ����
class Coin {
private:
    string type;
    double amount;

public:
    Coin(string type, double amount);
    Coin(string type); // ������ �Լ� �ߺ�
    void print() const;
    string getType() const;
    double getAmount() const;
    Coin& operator-=(double value);
};

// Cash Ŭ����
class Cash {
private:
    string currency;
    double amount;

public:
    Cash(string currency, double amount);
    Cash(string currency); // ������ �Լ� �ߺ� 
    void print() const;
    string getCurrency() const;
    double getAmount() const;
    Cash& operator-=(double value);
};

// Wallet Ŭ����
class Wallet {
private:
    vector<Coin> coins;
    vector<Cash> cashes;
    const string transactionFile = "transactions.txt"; // �ŷ� ��� ���ϸ�
public:
    void addCoin(const Coin& coin);
    void addCash(const Cash& cash);
    void printBalance();


    void saveTransactionToFile(const string& log);   // ���Ͽ� �ŷ� ����
    void loadTransactionFromFile();                  // ���Ͽ��� �ŷ� ��� �ҷ�����
    void makePayment();


    void payWithCoin();
    void payWithCash();


    // ���ø� �Լ� ����(���׸� Ŭ����)
    template <typename T>
    T* getByProperty(vector<T>& items, const string& property);
    Coin* getCoinByType(const string& type); //��ü ������ �̿�
    Cash* getCashByCurrency(const string& currency); //��ü ������ �̿�


};



#endif // DIGITALWALLET_H
