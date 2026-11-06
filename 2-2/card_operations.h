// 校园一卡通：公共头文件
#ifndef CARD_OPERATIONS_H
#define CARD_OPERATIONS_H

#include <string>

// 系统常量
const double FEE_RATE = 0.02;
const double WARNING_BALANCE = 10.0;

// 一卡通账户
struct Card {
    int id;
    std::string name;
    double balance;
    int transactions;
};

// 格式化输出
void printLine(char c = '-', int len = 60);
void title(const std::string &s);

// 动态内存
Card *createCards(int n);
void destroyCards(Card *p);

// 录入与业务
void inputCards(Card *arr, int n);
void deposit(Card &c, double amount, double fee = FEE_RATE);
bool spend(Card &c, double cost);
bool spend(Card &c, double cost, const std::string &item);

// 只读查询
void showBalance(const Card &c);
void viewStudentID(const Card *p);

// 金额换算与报表
int toCent(double amount);
void printReport(const Card *arr, int n);

#endif
