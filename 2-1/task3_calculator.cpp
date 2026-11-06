// 2-1 任务三：简易多功能计算器
#include <iostream>
#include <iomanip>
using namespace std;

inline double square(double x) {
    return x * x;
}

double power(double base, int exponent = 2) {
    double result = 1.0;
    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }
    return result;
}

double calc(double a, double b, char op) {
    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/':
        if (b == 0.0) {
            cout << "Error: divide by zero" << endl;
            return 0.0;
        }
        return a / b;
    default:
        cout << "Error: unknown operator" << endl;
        return 0.0;
    }
}

// 整数重载：演示同名函数按参数类型选择
double calc(int a, int b, char op) {
    return calc(static_cast<double>(a), static_cast<double>(b), op);
}

int main() {
    double a, b;
    char op;
    cin >> a >> b >> op;

    cout << "square(" << a << ") = " << fixed << setprecision(2)
         << square(a) << endl;
    cout << defaultfloat << "power(" << a << ",3) = " << fixed
         << setprecision(2) << power(a, 3) << endl;

    double result;
    if (a == static_cast<int>(a) && b == static_cast<int>(b)) {
        result = calc(static_cast<int>(a), static_cast<int>(b), op);
    } else {
        result = calc(a, b, op);
    }

    bool valid = (op == '+' || op == '-' || op == '*' || op == '/');
    bool divideByZero = (op == '/' && b == 0.0);
    if (valid && !divideByZero) {
        cout << defaultfloat << a << ' ' << op << ' ' << b << " = "
             << fixed << setprecision(2) << result << endl;
    }
    return 0;
}
