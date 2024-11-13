#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;

// Объявление функции debug
void debug(int n, float arg, float sum, float tsum, float eps) {
    cout << "N = " << n << endl;
    cout << "Sum = " << sum << " + " << arg << " = " << sum + arg << endl;
    cout << "Diff = " << tsum << " - " << sum << " = " << tsum - sum << endl; 
    cout << "Diff >= " << eps << " = " << bool((tsum - sum) >= eps) << endl;
    cout << "\n";
}

int main() {
    setlocale(LC_ALL, "RUSSIAN");

    // Инициализация переменных
    float sum = 0; // Сумма, насчитанная на данный момент 
    float diff = 1; // Разность между точной и насчитанной суммой 
    float eps = 0; // Требуемая точность(эпсилон)
    float tsum = pow(M_PI, 2) / 8; // Точная сумма 
    int n = 0; // Количество пройденных шагов
    float arg = 0;

    // Ввод исходных данных eps
    cout << "Введите eps: "; // Эхо-печать
    cin >> eps;

    // Проверка на правильность ввода (входной контроль)
    if (eps <= 0) {
        cout << "Ошибка, eps меньше или равен 0\n"; // Сообщение об ошибке 
        return 0;
    }
    // Данные корректны, продолжаем работу

    // Цикл while с основным алгоритмом действий (расчёт суммы ряда)
    while (diff >= eps) {
        n += 1; // Увеличить n на 1
        arg = 1 / ((2 * n - 1.0) * (2 * n - 1.0)); // Рассчитать текущее слагаемое
        
        // Вызов debug с передачей eps
        debug(n, arg, sum, tsum, eps);

        sum += arg; // Добавить текущее слагаемое к сумме 
        diff = abs(tsum - sum); // Вычислить разность между насчитанной и точной суммой 
    }

    // Вывод запрашиваемых данных (печать результата)
    cout << "Кол-во просуммированных элементов: " << n << "\n";
    cout << "Сумма: " << sum << "\n";
    cout << "Разность суммы и точного значения: " << diff << "\n";
    cout << "Точная сумма: " << tsum << "\n";
    return 0;
}
