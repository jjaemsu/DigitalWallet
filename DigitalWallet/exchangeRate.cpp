#include <string>
#include <iostream>

using namespace std;

template <class T>
class Exchangerate {
private:
    string currencyFrom;
    string currencyTo;
    T rate;

public:
    // 생성자
    Exchangerate(const string& from, const string& to, T r);

    // 환율 정보 출력 함수
    void print() const;
};

// 템플릿 클래스 함수 정의를 헤더 파일에 포함
template <class T>
Exchangerate<T>::Exchangerate(const string& from, const string& to, T r)
    : currencyFrom(from), currencyTo(to), rate(r) {}
 
template <class T>
void Exchangerate<T>::print() const {
    cout << "환전할 통화: " << currencyFrom << endl;
    cout << "목적 통화: " << currencyTo << endl;
    cout << "환율: " << rate << endl;
}

