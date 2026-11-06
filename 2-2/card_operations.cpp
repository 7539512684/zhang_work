// 校园一卡通：功能实现
#include "card_operations.h"

#include <iostream>
#include <iomanip>
#include <stdexcept>
using namespace std;

void printLine(char c, int len) {
    cout << string(len, c) << endl;
}

void title(const string &s) {
    cout << s <<  endl;
}

Card *createCards(int n) {
    if (n <= 0) {
        throw invalid_argument("账户数量必须大于 0");
    }
    Card *cards = new Card[n];
    for (int i = 0; i < n; ++i) {
        cards[i].id = 0;
        cards[i].balance = 0.0;
        cards[i].transactions = 0;
    }
    return cards;
}

void destroyCards(Card *p) {
    delete[] p;
}

void inputCards(Card *arr, int n) {
    for (int i = 0; i < n; ++i) {
        while (true) {
            try {
                cout << "请输入第 " << i + 1
                     << " 个账户（学号 姓名 初始余额）：" << endl;
                cin >> arr[i].id >> arr[i].name >> arr[i].balance;

                if (!cin) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    throw invalid_argument("输入格式错误");
                }
                if (arr[i].id <= 0) {
                    throw invalid_argument("学号必须为正整数");
                }
                if (arr[i].balance < 0) {
                    throw invalid_argument("余额不能为负数");
                }

                arr[i].transactions = 0;
                break;
            } catch (const exception &e) {
                if (cin.eof()) {
                    throw;
                }
                cout << "输入错误：" << e.what() << "，请重新输入。" << endl;
            }
        }
    }
}

void deposit(Card &c, double amount, double fee) {
    if (amount <= 0) {
        throw invalid_argument("充值金额必须大于 0");
    }
    c.balance += amount * (1.0 - fee);
    ++c.transactions;
    if (c.balance < WARNING_BALANCE) {
        cout << "警告：" << c.name << " 的余额低于 10 元。" << endl;
    }
}

bool spend(Card &c, double cost) {
    if (cost <= 0) {
        throw invalid_argument("消费金额必须大于 0");
    }
    if (c.balance < cost) {
        return false;
    }
    c.balance -= cost;
    ++c.transactions;
    if (c.balance < WARNING_BALANCE) {
        cout << "警告：" << c.name << " 的余额低于 10 元。" << endl;
    }
    return true;
}

bool spend(Card &c, double cost, const string &item) {
    cout << "消费项目：" << item << endl;
    if (!spend(c, cost)) {
        throw runtime_error("余额不足，消费失败");
    }
    return true;
}

void showBalance(const Card &c) {
    cout << c.name << " 当前余额为：" << fixed << setprecision(2)
         << c.balance << endl;
}

void viewStudentID(const Card *p) {
    if (p != nullptr) {
        cout << "账户ID为：" << p->id << endl;
    }
}

int toCent(double amount) {
    return static_cast<int>(amount * 100.0 + 0.5);
}

void printReport(const Card *arr, int n) {
    printLine('=', 60);
    cout << left << setw(8) << "ID"
         << setw(15) << "Name"
         << right << setw(10) << "Balance"
         << setw(14) << "Transactions" << endl;
    printLine('-', 60);
    for (int i = 0; i < n; ++i) {
        cout << left << setw(8) << arr[i].id
             << setw(15) << arr[i].name
             << right << fixed << setprecision(2)
             << setw(10) << arr[i].balance
             << setw(14) << arr[i].transactions << endl;
    }
    printLine('=', 60);
}
