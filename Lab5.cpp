#include <iostream>
#include <vector>
#include <algorithm> // для std::sort

using namespace std;

// Функція для обчислення суми елементів кожного стовпця
vector<int> sumColumns(const vector<vector<int>>& matrix) {
    vector<int> columnSums(4, 0); // Ініціалізація масиву для сум стовпців
    for (int j = 0; j < 4; ++j) {
        for (int i = 0; i < 4; ++i) {
            columnSums[j] += matrix[i][j];
        }
    }
    return columnSums;
}

// Функція для сортування стовпців за їх сумами
void sortColumnsBySum(vector<vector<int>>& matrix, const vector<int>& columnSums) {
    vector<pair<int, int>> sumIndexPairs(4);
    for (int i = 0; i < 4; ++i) {
        sumIndexPairs[i] = {columnSums[i], i};
    }

    // Сортуємо пари за сумою стовпця
    sort(sumIndexPairs.begin(), sumIndexPairs.end());

    // Створюємо нову матрицю із відсортованими стовпцями
    vector<vector<int>> sortedMatrix(4, vector<int>(4));
    for (int j = 0; j < 4; ++j) {
        int colIndex = sumIndexPairs[j].second;
        for (int i = 0; i < 4; ++i) {
            sortedMatrix[i][j] = matrix[i][colIndex];
        }
    }

    // Копіюємо відсортовану матрицю назад у вихідну
    matrix = sortedMatrix;
}

int main() {
    vector<vector<int>> matrix(4, vector<int>(4));

    // Вводимо елементи матриці 4x4
    cout << "Введіть елементи матриці 4x4:" << endl;
    int input;
    int enteredElements = 0;
    bool matrixComplete = true;

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> input;
            if (cin.fail()) {  // Перевірка на коректність введення
                cout << "Матриця неповна. Введено неправильний елемент!" << endl;
                cout << "Введено на момент помилки: " << endl;
                for (int x = 0; x <= i; ++x) {
                    for (int y = 0; y <= (x == i ? j : 3); ++y) {
                        cout << matrix[x][y] << " ";
                    }
                    cout << endl;
                }
                return 1;  // Вихід з програми при некоректному введенні
            }
            matrix[i][j] = input;
            enteredElements++;
        }
    }

    // Перевірка, чи кількість введених елементів дорівнює 16
    if (enteredElements != 16) {
        cout << "Матриця неповна. Введено недостатньо елементів!" << endl;
        cout << "Введено на момент помилки: " << endl;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                if (matrix[i][j] != 0) { // Показуємо тільки введені елементи
                    cout << matrix[i][j] << " ";
                }
            }
            cout << endl;
        }
        return 1;
    }

    // Обчислюємо суми елементів кожного стовпця
    vector<int> columnSums = sumColumns(matrix);

    // Сортуємо стовпці матриці за сумою
    sortColumnsBySum(matrix, columnSums);

    // Виводимо відсортовану матрицю
    cout << "Відсортована матриця:" << endl;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
