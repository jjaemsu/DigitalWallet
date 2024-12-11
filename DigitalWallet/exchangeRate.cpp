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
    // ������
    Exchangerate(const string& from, const string& to, T r);

    // ȯ�� ���� ��� �Լ�
    void print() const;
};

// ���ø� Ŭ���� �Լ� ���Ǹ� ��� ���Ͽ� ����
template <class T>
Exchangerate<T>::Exchangerate(const string& from, const string& to, T r)
    : currencyFrom(from), currencyTo(to), rate(r) {}
 
template <class T>
void Exchangerate<T>::print() const {
    cout << "ȯ���� ��ȭ: " << currencyFrom << endl;
    cout << "���� ��ȭ: " << currencyTo << endl;
    cout << "ȯ��: " << rate << endl;
}

