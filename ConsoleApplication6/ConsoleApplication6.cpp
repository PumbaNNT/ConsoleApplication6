
#include <iostream>
#include <cmath>
using namespace std;


bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}


int daysInMonth(int month, int year) {
    switch (month) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        return 31;
    case 4: case 6: case 9: case 11:
        return 30;
    case 2:
        return isLeapYear(year) ? 29 : 28;
    default:
        return 0;
    }
}


int daysFromStart(int day, int month, int year) {
    int days = day;
    for (int y = 1; y < year; y++) {
        days += isLeapYear(y) ? 366 : 365;
    }
    for (int m = 1; m < month; m++) {
        days += daysInMonth(m, year);
    }
    return days;
}


int daysBetweenDates(int d1, int m1, int y1, int d2, int m2, int y2) {
    int days1 = daysFromStart(d1, m1, y1);
    int days2 = daysFromStart(d2, m2, y2);
    return abs(days2 - days1);
}

int main() {
    int d1, m1, y1, d2, m2, y2;
    cout << "Введіть першу дату (день місяць рік): ";
    cin >> d1 >> m1 >> y1;
    cout << "Введіть другу дату (день місяць рік): ";
    cin >> d2 >> m2 >> y2;

    cout << "Різниця в днях: " << daysBetweenDates(d1, m1, y1, d2, m2, y2) << endl;
    return 0;
}





double average(const int arr[], int size) {
    if (size == 0) return 0;
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}

int main() {
    int n;
    cout << "Введіть кількість елементів: ";
    cin >> n;
    int arr[n];
    cout << "Введіть елементи масиву: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Середнє арифметичне: " << average(arr, n) << endl;
    return 0;
}







void countElements(const int arr[], int size, int& positive, int& negative, int& zero) {
    positive = negative = zero = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) positive++;
        else if (arr[i] < 0) negative++;
        else zero++;
    }
}

int main() {
    int n;
    cout << "Введіть кількість елементів: ";
    cin >> n;
    int arr[n];
    cout << "Введіть елементи масиву: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    int pos, neg, zer;
    countElements(arr, n, pos, neg, zer);

    cout << "Додатних: " << pos << ", Від'ємних: " << neg << ", Нульових: " << zer << endl;
    return 0;
}
