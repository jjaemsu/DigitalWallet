#include "DigitalWallet.h"
#include "exchangeRate.cpp"


/*
* 컴퓨터 프로그래밍 및 실습 평과과제
* 학과 : 컴퓨터공학부
* 학번 : 202301469
* 이름 : 이찬수
* 과제 주제 : 미래의 전자지갑
*/




int main() {
    Wallet wallet;
    cout << "오늘의 환율" << endl;
    /////////////////////////객체 배열 생성/////////////////////
    Exchangerate<double> exchanges[3] = { // 여기서는 double을 사용
        Exchangerate<double>("USD", "EUR", 0.85),
        Exchangerate<double>("USD", "JPY", 150.0),
        Exchangerate<double>("USD", "KRW", 1400.0)
    };
    // 배열의 각 환율 정보를 출력
    for (int i = 0; i < 3; ++i) {
        exchanges[i].print();
        cout << "------------------------------------------------" << endl;
    }
    ////////////////////////////////////////////////////////////
 
    /////////////////////////초기값선언/////////////////////////
    wallet.addCoin(Coin("BTC", 1));
    wallet.addCoin(Coin("ETH", 1));
    wallet.addCash(Cash("KRW", 18000));
    wallet.addCash(Cash("USD", 120));
    
    ////////////////////////////////////////////////////////////

    cout << "------------------지갑------------------" << endl;

    while (1) {
        cout << "1.결제\n2.잔액 확인\n3.거래 기록 확인\n4.종료" << endl;
        // 예외 처리
        try {
            int menu;
            if (!(cin >> menu) || menu < 1 || menu > 4) { // 정수가 아니거나, 1~4사이가 아닐경우
                cin.clear();                // 입력 스트림 초기화
                cin.ignore(1000, '\n');     // 잘못된 입력 무시
                throw invalid_argument("1에서 4 사이의 정수를 입력하세요.");
            }
            if (menu == 1) {
                wallet.makePayment();
            }
            else if (menu == 2) {
                wallet.printBalance();
            }
            else if (menu == 3) {
                wallet.loadTransactionFromFile(); // 파일에서 거래 기록 불러오기
            }
            else if (menu == 4) {
                cout << "종료하겠습니다." << endl;
                break;
            }
        }
        catch (const invalid_argument& e) {
            cout << "오류: " << e.what() << endl;
        }
    }
    return 0;
}
