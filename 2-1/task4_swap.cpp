// 2-1 任务四：引用交换
#include <iostream>
#include <iomanip>
using namespace std;

void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

void swap(double &x, double &y) {
    double temp = x;
    x = y;
    y = temp;
}

int main() {
    double a, b;
    cin >> a >> b;

    if (a == static_cast<int>(a) && b == static_cast<int>(b)) {
        int x = static_cast<int>(a);
        int y = static_cast<int>(b);
        cout << "Before swap: x=" << x << ", y=" << y << endl;
        swap(x, y);
        cout << "After  swap: x=" << x << ", y=" << y << endl;
    } else {
        cout << fixed << setprecision(2);
        cout << "Before swap: x=" << a << ", y=" << b << endl;
        swap(a, b);
        cout << "After  swap: x=" << a << ", y=" << b << endl;
    }
    return 0;
}
