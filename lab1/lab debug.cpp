/****************************************************************
*                     ������� � 304 1 ����                      *
*---------------------------------------------------------------*
* Project Type  : Win32 Console Application                     *
* Project Name  : First project                                 *
* File Name     : First.cpp                                     *
* Language      : C/C++                                         *
* Programmer(s) : �������� �.�., ������������ �.�.              *
* Modifyed By   :                                               *
* Lit source    :                                               *
* Created       : 30/10/24                                      *
* Last Revision : 31/10/24                                      *
* Comment(s)    : ����� ����.                                   *
****************************************************************/
#define _USE_MATH_DEFINES // ��������� ������������� �������������� �������� �� <cmath>
#include <iostream> // ����������� ���������� ��� �����-������
#include <cmath> // ����������� ���������� ��� �������������� ��������
using namespace std; // ������������� ������������ ���� std

// debug (�� ������ � ��������� ��������� ������ ��� ��������)
void debug(int n, float arg, float sum, float tsum, float eps) {
    cout << "N = " << n << endl;
    cout << "Sum = " << sum << " + " << arg << " = " << sum + arg << endl;
    cout << "Diff = " << tsum << " - " << sum << " = " << tsum - sum << endl; 
    cout << "Diff >= " << eps << " = " << bool((tsum - sum) >= eps) << endl;
    cout << "\n";
}

int main() {
    setlocale(LC_ALL, "RUSSIAN");// ��������� ����������� ��� ����������� ������ �� ������� �����

    float sum = 0; // ���������� ��� ������� �����
    float diff = 1; // ���������� ��� �������� ����� ������ � ����������� ������
    float eps = 0; // ���������� ��� �������� (�������)
    float tsum = pow(M_PI, 2) / 8; // ���������� ������ ����� ��� ���������
    int n = 0; // ������� ����� ��������� � �����
    float arg = 0; // ���������� ��� �������� ����������

    cout << "������� eps: "; // ������ ����� �������� �� ������������
    cin >> eps; // ���� �������� ��������

    if (eps <= 0) { // ��������, ��� �������� ������ 0
        cout << "������, eps ������ ��� ����� 0\n";     // ����� ������, ���� eps �����������
        return 0;                                       // ���������� ��������� ��� ������������ �����
    }

    while (diff >= eps) {                               // ���� ��� ���������� �����, ���� �������� ��������� eps
        n += 1;                                         // ���������� �������� ��������� �� 1
        arg = 1 / ((2 * n - 1.0) * (2 * n - 1.0));      // ���������� �������� ���������� ����
        
        debug(n, arg, sum, tsum, eps);                  // ����� ������� debug ��� ������ ������� ��������

        sum += arg;                                     // ���������� �������� ���������� � ����� �����
        diff = abs(tsum - sum);                         // ���������� �������� ����� ������ � ����������� ������
    }

    // ����� ����������� ����� ���������� �����
    cout << "���-�� ���������������� ���������: " << n << "\n"; // ����� ���������� ���������
    cout << "�����: " << sum << "\n";                            // ����� �������� �����
    cout << "�������� ����� � ������� ��������: " << diff << "\n"; // ����� �������� ��������
    cout << "������ �����: " << tsum << "\n";                    // ����� ������� �������� �����
    return 0;                                                    // ���������� ���������
}