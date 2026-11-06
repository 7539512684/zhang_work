// 校园一卡通：主程序
#include "card_operations.h"

#include <iostream>
#include <new>
#include <stdexcept>
using namespace std;

int main() {
    Card *cards = nullptr;
    try {
        title("Campus Card System");

        int n;
        cout << "请输入学生数量：" << endl;
        cin >> n;
        if (!cin || n <= 0) {
            throw invalid_argument("学生数量必须为正整数");
        }

        cards = createCards(n);
        inputCards(cards, n);

        cout << "\n--- 账户操作演示 ---" << endl;
        deposit(cards[0], 100.0);
        cout << "已向 " << cards[0].name
             << " 充值 100.00 元（手续费率 2%）。" << endl;
        spend(cards[0], 8.5, "食堂午餐");

        cout << endl;
        showBalance(cards[0]);
        viewStudentID(&cards[0]);
        cout << "换算为分：" << toCent(cards[0].balance) << endl;

        cout << endl;
        printReport(cards, n);
    } catch (const bad_alloc &) {
        cout << "内存分配失败，程序退出。" << endl;
        destroyCards(cards);
        return 1;
    } catch (const exception &e) {
        cout << "程序异常：" << e.what() << endl;
        destroyCards(cards);
        return 1;
    }

    destroyCards(cards);
    return 0;
}
