#ifndef DIGITALWALLET_H
#define DIGITALWALLET_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream> // 파일 입출력을 위한 라이브러리
using namespace std;

// Payment 클래스 (추상 클래스)
class Payment {
public: // 가상 함수
    virtual void pay(string type, double amount) = 0;
    virtual ~Payment() {}
};

// CoinPayment 클래스 (상속)
class CoinPayment : public Payment {
public:
    void pay(string type, double amount) override; // 오버라이딩(다형성)
};

// CashPayment 클래스 (상속)
class CashPayment : public Payment {
public:
    void pay(string type, double amount) override; // 오버라이딩(다형성)   
};

// Coin 클래스
class Coin {
private:
    string type;
    double amount;

public:
    Coin(string type, double amount);
    Coin(string type); // 생성자 함수 중복
    void print() const;
    string getType() const;
    double getAmount() const;
    Coin& operator-=(double value);
};

// Cash 클래스
class Cash {
private:
    string currency;
    double amount;

public:
    Cash(string currency, double amount);
    Cash(string currency); // 생성자 함수 중복 
    void print() const;
    string getCurrency() const;
    double getAmount() const;
    Cash& operator-=(double value);
};

// Wallet 클래스
class Wallet {
private:
    vector<Coin> coins;
    vector<Cash> cashes;
    const string transactionFile = "transactions.txt"; // 거래 기록 파일명
public:
    void addCoin(const Coin& coin);
    void addCash(const Cash& cash);
    void printBalance();


    void saveTransactionToFile(const string& log);   // 파일에 거래 저장
    void loadTransactionFromFile();                  // 파일에서 거래 기록 불러오기
    void makePayment();


    void payWithCoin();
    void payWithCash();


    // 템플릿 함수 선언(제네릭 클래스)
    template <typename T>
    T* getByProperty(vector<T>& items, const string& property);
    Coin* getCoinByType(const string& type); //객체 포인터 이용
    Cash* getCashByCurrency(const string& currency); //객체 포인터 이용


};



#endif // DIGITALWALLET_H
