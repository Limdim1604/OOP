#include <bits/stdc++.h>
using namespace std;

class SinCalculator {
private:
    double x;          // Giá trị góc (đơn vị radian)
    double precision;  // Độ chính xác yêu cầu

public:
    // Constructor
    SinCalculator(double angle, double prec = 0.00001) : x(angle), precision(prec) {}

    // Phương thức tính sin(x) theo công thức chuỗi Taylor
    double calculate() {
        double term = x;        // Giá trị của từng hạng tử trong chuỗi
        double sum = term;      // Tổng các hạng tử
        int n = 0;              // Chỉ số hạng tử

        while (abs(term) >= precision) { 
        //vòng lặp tiếp tục cho đến khi trị tuyệt đối của hạng tử nhỏ hơn độ chính xác yêu cầu
            n++;
            int exponent = 2 * n + 1; // Số mũ của x trong hạng tử
            term = -term * x * x / ((exponent - 1) * exponent); 
            // Tính hạng tử tiếp theo dựa vào hạng tử trước đó 
            sum += term;
        }

        return sum;
    }
};

int main() {
    double angle;
    char unit;
    cout << "Nhap gia tri goc: ";
    cin >> angle;
    cout << "Don vi (r - radian, d - degree): ";
    cin >> unit;

    if (unit == 'd' || unit == 'D') {
        angle = angle * M_PI / 180.0; // Chuyển đổi độ sang radian
    }

    SinCalculator calculator(angle);

    double result = calculator.calculate();

    cout << fixed << setprecision(6);
    cout << "Gia tri sin cua goc da nhap la: " << result << endl;
    cout << "Gia tri sin tinh bang ham sin tich hop co san la: " << sin(angle) << endl;

    return 0;
}