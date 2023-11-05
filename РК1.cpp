#include <iostream>
#include <cstring>
using namespace std;
int main() {
    system("chcp 1251 > nul");
    int size;
    cout << "Введите количество заказов: ";
    cin >> size;

    char** bludo = new char* [size];
    int* porcii = new int[size];
    double* cena = new double[size];

    cin.ignore();

    for (int i = 0; i < size; ++i) {
        cout << "Введите название блюда " << i + 1 << ": ";
        char buffer[100];
        cin.getline(buffer, 100);
        bludo[i] = new char[strlen(buffer) + 1];
        strcpy_s(bludo[i], strlen(buffer) + 1 , buffer);

        cout << "Введите количество порций " << i + 1 << ": ";
        cin >> porcii[i];
        cin.ignore();
        cout << "Введите цену " << i + 1 << ": ";
        cin >> cena[i];
        cin.ignore();
    }
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (strcmp(bludo[j], bludo[j + 1]) > 0) {
                swap(bludo[j], bludo[j + 1]);
                swap(porcii[j], porcii[j + 1]);
            }
        }
    }
    cout << "\nОтсортированный список заказов:\n";
    for (int i = 0; i < size; ++i) {
        cout << "Название блюда: " << bludo[i] << ", Количество порций: " << porcii[i] << ", Стоимость: " << cena[i] << endl;
    }
    for (int i = 0; i < size; ++i) {
        delete[] bludo[i];
    }
    delete[] bludo;
    delete[] porcii;
    delete[] cena;
    return 0;
}