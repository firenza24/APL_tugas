#include <iostream>

using namespace std;

int main() {
    
    const int baris = 2;
    const int kolom = 2;

    int matriks[baris][kolom]; 
    double invers[baris][kolom];
    double det;

    // Input menggunakan Nested Loop
    cout << "Masukkan elemen matriks 2x2 (Bilangan Bulat):" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << "Elemen [" << i << "][" << j << "]: ";
            cin >> matriks[i][j];
        }
    }

    // Menghitung Determinan
    det = (matriks[0][0] * matriks[1][1]) - (matriks[0][1] * matriks[1][0]);

    cout << "\nDeterminan: " << det << endl;

    if (det == 0) {
        cout << "Matriks Singular (determinan = 0)! " << endl;
    } else {

        invers[0][0] = (double)matriks[1][1] / det;  
        invers[0][1] = (double)-matriks[0][1] / det; 
        invers[1][0] = (double)-matriks[1][0] / det; 
        invers[1][1] = (double)matriks[0][0] / det;  

        // Output menggunakan Nested Loop
        cout << "\nInvers Matriks adalah:" << endl;
        for (int i = 0; i < 2; i++) {
            cout << "[ ";
            for (int j = 0; j < 2; j++) {
                cout << invers[i][j] << "\t"; 
            }
            cout << "]" << endl;
        }
    }

    return 0;
}