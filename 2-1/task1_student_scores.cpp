// 2-1 任务一：学生成绩统计
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

struct Student {
    string name;
    double chinese;
    double math;
    double english;
    double average;
};

int main() {
    int n;
    cin >> n;

    vector<Student> students(n);
    for (int i = 0; i < n; ++i) {
        cin >> students[i].name >> students[i].chinese
            >> students[i].math >> students[i].english;
        students[i].average =
            (students[i].chinese + students[i].math + students[i].english) / 3.0;
    }

    cout << fixed << setprecision(2);
    for (int i = 0; i < n; ++i) {
        cout << left << setw(10) << students[i].name
             << right << setw(8) << students[i].chinese
             << setw(8) << students[i].math
             << setw(8) << students[i].english
             << setw(8) << students[i].average;

        if (students[i].average >= 90.0) {
            cout << " Excellent";
        }
        cout << endl;
    }
    return 0;
}
