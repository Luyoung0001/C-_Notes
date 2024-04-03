// 多态性的演示
#include "brassplus.h"


const int CLIENTS = 4;
int main() {
    using std::cin;
    using std::cout;
    using std::endl;

    AcctABC *p_clients[CLIENTS];
    std::string temp;
    long tempnum;
    double tempbal;
    char kind;

    for (int i = 0; i < CLIENTS; i++) {
        cout << "输入客户名称: ";
        getline(cin, temp);
        cout << "输入客户账户: ";
        cin >> tempnum;
        cout << "输入开户余额: ";
        cin >> tempbal;
        cout << "1 for brass, 2 for brassplus: ";

        while (cin >> kind && (kind != '1' && kind != '2')) {
            cout << "输入错误,请重新输入:";
        }
        if(kind == '1'){
            p_clients[i] = new Brass(temp,tempnum,tempbal);
        }else{
            double tmax,trate;
            cout << "请输入透支额度: ";
            cin >> tmax;
            cout << "输入利息: ";
            cin >> trate;

            p_clients[i] = new BrassPlus(temp,tempnum,tempbal,tmax,trate);
        }
        while(cin.get() != '\n'){
            // 刷掉错误输入
            continue;
        }
    }
    cout << endl;
    for(int i = 0; i < CLIENTS ; i++){
        p_clients[i]->ViewAcct(); // 多态
        cout << endl;
    }
    for(int i = 0; i < CLIENTS ; i++){
        delete p_clients[i];
    }
    cout << "Done!\n";

    return 0;
}