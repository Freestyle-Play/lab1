#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;

// ���������� ������� debug
void debug(int n, float arg, float sum, float tsum, float eps) {
    cout << "N = " << n << endl;
    cout << "Sum = " << sum << " + " << arg << " = " << sum + arg << endl;
    cout << "Diff = " << tsum << " - " << sum << " = " << tsum - sum << endl; 
    cout << "Diff >= " << eps << " = " << bool((tsum - sum) >= eps) << endl;
    cout << "\n";
}

int main() {
    setlocale(LC_ALL, "RUSSIAN");

    // ������������� ����������
    float sum = 0; // �����, ����������� �� ������ ������ 
    float diff = 1; // �������� ����� ������ � ����������� ������ 
    float eps = 0; // ��������� ��������(�������)
    float tsum = pow(M_PI, 2) / 8; // ������ ����� 
    int n = 0; // ���������� ���������� �����
    float arg = 0;

    // ���� �������� ������ eps
    cout << "������� eps: "; // ���-������
    cin >> eps;

    // �������� �� ������������ ����� (������� ��������)
    if (eps <= 0) {
        cout << "������, eps ������ ��� ����� 0\n"; // ��������� �� ������ 
        return 0;
    }
    // ������ ���������, ���������� ������

    // ���� while � �������� ���������� �������� (������ ����� ����)
    while (diff >= eps) {
        n += 1; // ��������� n �� 1
        arg = 1 / ((2 * n - 1.0) * (2 * n - 1.0)); // ���������� ������� ���������
        
        // ����� debug � ��������� eps
        debug(n, arg, sum, tsum, eps);

        sum += arg; // �������� ������� ��������� � ����� 
        diff = abs(tsum - sum); // ��������� �������� ����� ����������� � ������ ������ 
    }

    // ����� ������������� ������ (������ ����������)
    cout << "���-�� ���������������� ���������: " << n << "\n";
    cout << "�����: " << sum << "\n";
    cout << "�������� ����� � ������� ��������: " << diff << "\n";
    cout << "������ �����: " << tsum << "\n";
    return 0;
}
