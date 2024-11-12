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
#define _USE_MATH_DEFINES  // �������� �������������� ���������
#include <iostream>    // ����������� ���������� ��� ������ � ������ � �������
#include <iomanip>     // ����������� ���������� ��� ���������� ������� (��������� ��������)
#include <cmath>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");		//����������� �������� �����

    // ������������� ����������
    int N = 1;         // ��������� �������� ��� ������ ����� ����
    double sum = 0.0;  // ���������� ��� �������� ������� ����� ����
    double exact_value = M_PI * M_PI / 8; // ������ �������� ����� ���� ?^2/8
    double eps;  // ���������� ��� �������� �������� ��������
    double term;       // ���������� ��� �������� �������� ����� ����

    // ������ � ������������ ����������� ��������
    cout << "������� ��������: ";
    cin >> eps;

    // �������� �� ������������ ����� (������� ��������)
    if (eps <= 0)
    {
        cout << "������, eps ������ ��� ����� 0\n"; // ��������� �� ������ 
        return 0;
    }
    // ������ ���������, ���������� ������


    // �������� ���� ��� ������������ ������ ����, ���� ������� �� ������ ������ �������� ��������
    do {
        term = 1.0 / ((2 * N - 1) * (2 * N - 1)); // ��������� ������� ���� ����
        sum += term;   // ��������� ������� ���� � �����
        N++;           // ��������� � ���������� ����� ����
    } while (term > eps); // ��������: ����������, ���� ������� ���� ������ �������� ��������

    // ����� ���������� ���������������� ���������
    cout << "���������� ���������������� ���������: " << N - 1 << endl;
    // ����� �������� �����
    cout << "�����: " << setprecision(15) << sum << endl;
    // ����� �������� ����� ����������� ������ � ������ ���������
    cout << "�������� � ������ ���������: " << setprecision(15) << exact_value - sum << endl;
    // ����� ������� �������� ����� ����
    cout << "������ ��������: " << setprecision(15) << exact_value << endl;

    system("pause"); // �� ���� ������� ���������
    return 0;  // ��������� ���������
}