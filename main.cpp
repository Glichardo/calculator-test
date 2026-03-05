#include <iostream>
#include <vector>
#include "calculator.h"

using namespace std;

int main() {
    int option = 0;

    do {
        cout << "\nCalculadora:\n1. Dividir\n2. Media\n3. Salir\n";
        cout << "Elige una opción: ";
        cin >> option;

        if (option == 1) {
            double n1, n2;
            cout << "Introduce numero 1: ";
            cin >> n1;
            cout << "Introduce numero 2: ";
            cin >> n2;

            try {
                double result = divide(n1, n2);
                cout << "Resultado: " << result << endl;
            } catch (const char* e) {
                cout << e << endl;
            }

        } else if (option == 2) {
            int size;
            cout << "Cantidad de numeros: ";
            cin >> size;

            if (size == 0) {
                cout << "La lista no puede estar vacia\n";
                continue;
            }

            vector<double> nums(size);
            for (int i = 0; i < size; i++) {
                cout << "Numero " << i + 1 << ": ";
                cin >> nums[i];
            }

            double result = average(nums.data(), size);
            cout << "Resultado: " << result << endl;
        } else if (option < 1 || option > 3) {
            cout << "Opcion invalida, vuelve a intentarlo\n";
        }

    } while (option != 3);

    return 0;
}