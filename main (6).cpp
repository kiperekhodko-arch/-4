#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

// ================= ОГОЛОШЕННЯ ФУНКЦІЙ ДО MAIN() =================

// --- Завдання 1: Proc21 ---
// Процедура обчислення часу вільного падіння t з висоти h (h - вхідний, t - вихідний)
void FreeFallTime(double h, double &t);
// Допоміжна функція введення та перевірки висоти h на діапазон [0, 100]
bool inputHeight(double &h, int index);
// Процедура виконання задачі Proc21 цілком
void task_Proc21();

// --- Завдання 1: Proc36 ---
// Функція перевірки, чи є ціле число K (0 < K < 3000) степенем числа 5 (без циклів)
bool IsPower5(int K);
// Допоміжна функція введення та перевірки цілого числа K на діапазон (0, 3000)
bool inputNumberK(int &K, int index);
// Процедура виконання задачі Proc36 цілком
void task_Proc36();

// --- Завдання 2: Integer4 ---
// 1) Функція введення вхідних значень A і B з перевіркою на коректність
bool in_AB(int &pA, int &pB);
// 2) Функція підрахунку кількості відрізків B на відрізку A
int calc_segments(int pA, int pB);
// 3) Функція виведення результату в консоль
void out_res_Int4(int res);
// Процедура виконання задачі Integer4 цілком
void task_Int4();

// ================= ГОЛОВНА ФУНКЦІЯ MAIN() =================

int main() {
    int choice; // змінна для вибору пункту меню

    do {
        cout << "\n================ МЕНЮ ЛАБОРАТОРНОЇ РОБОТИ №4 ================" << endl;
        cout << "1. Завдання 1.1 (Proc21 - час вільного падіння для 3 висот)" << endl;
        cout << "2. Завдання 1.2 (Proc36 - кількість степенів 5 серед 10 чисел)" << endl;
        cout << "3. Завдання 2   (Integer4 - кількість відрізків B на відрізку A)" << endl;
        cout << "0. Вихід з програми" << endl;
        cout << "Оберіть пункт меню: ";
        cin >> choice;

        // Перевірка коректності введення пункту меню
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Помилка! Введіть ціле число від 0 до 3." << endl;
            choice = -1;
            continue;
        }

        // Інструкція вибору для запуску відповідної процедури
        switch (choice) {
            case 1:
                task_Proc21();
                break;
            case 2:
                task_Proc36();
                break;
            case 3:
                task_Int4();
                break;
            case 0:
                cout << "Роботу програми завершено." << endl;
                break;
            default:
                cout << "Невірний вибір! Спробуйте ще раз." << endl;
        }
    } while (choice != 0);

    return 0;
}

// ================= ВИЗНАЧЕННЯ ФУНКЦІЙ ПІСЛЯ MAIN() =================

// --- Реалізація Завдання 1.1 (Proc21) ---

void FreeFallTime(double h, double &t) {
    const double g = 9.81; // прискорення вільного падіння (м/с^2)
    t = sqrt((2.0 * h) / g); // обчислення часу падіння
}

bool inputHeight(double &h, int index) {
    cout << "Введіть висоту h" << index << " (від 0 до 100 м): ";
    cin >> h;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    // Перевірка на невід'ємність та загальне обмеження [-100, 100] -> [0, 100]
    if (h < 0.0 || h > 100.0) {
        return false;
    }
    return true;
}

void task_Proc21() {
    cout << "\n--- Proc21: Час вільного падіння тіла ---" << endl;
    double h1, h2, h3; // три висоти
    double t1, t2, t3; // три результати часу

    // Послідовне введення та перевірка трьох значень без використання циклів
    if (!inputHeight(h1, 1) || !inputHeight(h2, 2) || !inputHeight(h3, 3)) {
        cout << "Помилка введення! Висота має бути числом у межах [0, 100]." << endl;
        return;
    }

    // Виклик процедури FreeFallTime для кожної висоти (без циклів)
    FreeFallTime(h1, t1);
    FreeFallTime(h2, t2);
    FreeFallTime(h3, t3);

    // Виведення результатів
    cout << "Результати розрахунків:" << endl;
    cout << "Для h1 = " << h1 << " м -> час t1 = " << t1 << " с" << endl;
    cout << "Для h2 = " << h2 << " м -> час t2 = " << t2 << " с" << endl;
    cout << "Для h3 = " << h3 << " м -> час t3 = " << t3 << " с" << endl;
}

// --- Реалізація Завдання 1.2 (Proc36) ---

bool IsPower5(int K) {
    // У діапазоні 0 < K < 3000 існують лише 5 цілих степенів числа 5:
    // 5^0 = 1, 5^1 = 5, 5^2 = 25, 5^3 = 125, 5^4 = 625 (5^5 = 3125 > 3000).
    // Перевірка виконується без циклів за умовою завдання.
    return (K == 1 || K == 5 || K == 25 || K == 125 || K == 625);
}

bool inputNumberK(int &K, int index) {
    cout << "Введіть ціле число K" << index << " (0 < K < 3000): ";
    cin >> K;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    // Перевірка обмеження з умови задачі: 0 < K < 3000
    if (K <= 0 || K >= 3000) {
        return false;
    }
    return true;
}

void task_Proc36() {
    cout << "\n--- Proc36: Перевірка степенів числа 5 ---" << endl;
    int k1, k2, k3, k4, k5, k6, k7, k8, k9, k10; // 10 цілих чисел

    // Введення 10 чисел без використання циклів
    if (!inputNumberK(k1, 1) || !inputNumberK(k2, 2) || !inputNumberK(k3, 3) ||
        !inputNumberK(k4, 4) || !inputNumberK(k5, 5) || !inputNumberK(k6, 6) ||
        !inputNumberK(k7, 7) || !inputNumberK(k8, 8) || !inputNumberK(k9, 9) ||
        !inputNumberK(k10, 10)) {
        cout << "Помилка введення! Усі числа повинні бути цілими в межах (0, 3000)." << endl;
        return;
    }

    // Підрахунок кількості степенів 5 через виклик функції IsPower5 без циклів
    int count = 0;
    if (IsPower5(k1)) count++;
    if (IsPower5(k2)) count++;
    if (IsPower5(k3)) count++;
    if (IsPower5(k4)) count++;
    if (IsPower5(k5)) count++;
    if (IsPower5(k6)) count++;
    if (IsPower5(k7)) count++;
    if (IsPower5(k8)) count++;
    if (IsPower5(k9)) count++;
    if (IsPower5(k10)) count++;

    cout << "Кількість чисел, що є степенями числа 5: " << count << endl;
}

// --- Реалізація Завдання 2 (Integer4) ---

bool in_AB(int &pA, int &pB) {
    cout << "Введіть цілі додатні числа A та B (A > B, у межах [1, 100]):" << endl;
    cout << "A = ";
    cin >> pA;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return true; // повертаємо true як ознаку помилки (за зразком методички)
    }

    cout << "B = ";
    cin >> pB;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return true;
    }

    // Перевірка на діапазон [-100, 100], додатність та умову A > B
    if (pA <= 0 || pA > 100 || pB <= 0 || pB > 100 || pA <= pB) {
        return true; // некоректні дані
    }

    return false; // дані коректні
}

int calc_segments(int pA, int pB) {
    return pA / pB; // цілочисельне ділення для знаходження кількості відрізків
}

void out_res_Int4(int res) {
    cout << "Максимальна кількість відрізків B на відрізку A: " << res << endl;
}

void task_Int4() {
    cout << "\n--- Integer4: Розміщення відрізків ---" << endl;
    int A, B; // вхідні змінні

    // 1) Виклик функції введення з перевіркою
    if (in_AB(A, B)) {
        cout << "Помилка! A і B мають бути цілими додатними числами в межах, причому A > B." << endl;
    } else {
        // 2) Підрахунок та 3) виведення результату
        int result = calc_segments(A, B);
        out_res_Int4(result);
    }
}
