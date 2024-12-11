#include "DigitalWallet.h"
#include "exchangeRate.cpp"


/*
* ��ǻ�� ���α׷��� �� �ǽ� �������
* �а� : ��ǻ�Ͱ��к�
* �й� : 202301469
* �̸� : ������
* ���� ���� : �̷��� ��������
*/




int main() {
    Wallet wallet;
    cout << "������ ȯ��" << endl;
    /////////////////////////��ü �迭 ����/////////////////////
    Exchangerate<double> exchanges[3] = { // ���⼭�� double�� ���
        Exchangerate<double>("USD", "EUR", 0.85),
        Exchangerate<double>("USD", "JPY", 150.0),
        Exchangerate<double>("USD", "KRW", 1400.0)
    };
    // �迭�� �� ȯ�� ������ ���
    for (int i = 0; i < 3; ++i) {
        exchanges[i].print();
        cout << "------------------------------------------------" << endl;
    }
    ////////////////////////////////////////////////////////////
 
    /////////////////////////�ʱⰪ����/////////////////////////
    wallet.addCoin(Coin("BTC", 1));
    wallet.addCoin(Coin("ETH", 1));
    wallet.addCash(Cash("KRW", 18000));
    wallet.addCash(Cash("USD", 120));
    
    ////////////////////////////////////////////////////////////

    cout << "------------------����------------------" << endl;

    while (1) {
        cout << "1.����\n2.�ܾ� Ȯ��\n3.�ŷ� ��� Ȯ��\n4.����" << endl;
        // ���� ó��
        try {
            int menu;
            if (!(cin >> menu) || menu < 1 || menu > 4) { // ������ �ƴϰų�, 1~4���̰� �ƴҰ��
                cin.clear();                // �Է� ��Ʈ�� �ʱ�ȭ
                cin.ignore(1000, '\n');     // �߸��� �Է� ����
                throw invalid_argument("1���� 4 ������ ������ �Է��ϼ���.");
            }
            if (menu == 1) {
                wallet.makePayment();
            }
            else if (menu == 2) {
                wallet.printBalance();
            }
            else if (menu == 3) {
                wallet.loadTransactionFromFile(); // ���Ͽ��� �ŷ� ��� �ҷ�����
            }
            else if (menu == 4) {
                cout << "�����ϰڽ��ϴ�." << endl;
                break;
            }
        }
        catch (const invalid_argument& e) {
            cout << "����: " << e.what() << endl;
        }
    }
    return 0;
}
