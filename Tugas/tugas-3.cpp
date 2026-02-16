#include <iostream>

using namespace std;

int main() {

    int baris, kolom;
    double total = 0;

    // Input jumlah baris dan kolom dari user
    cout << "Masukkan jumlah baris: ";
    cin >> baris;
    cout << "Masukkan jumlah kolom: ";
    cin >> kolom;

    // Deklarasi array 2d dengan ukuran sesuai input
    int matriks[baris][kolom];

    cout << "\nMasukkan elemen matriks " << baris << "x" << kolom << " (bilangan bulat):" << endl;

    // Looping untuk Menginput Nilai ke dalam Array
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            cout << "Elemen [" << i << "][" << j << "]: ";
            cin >> matriks[i][j];
            total += matriks[i][j];
        }
    }

    cout << "\nTampilan matriks " << baris << "x" << kolom << " :" << endl;

    // Loop untuk Menampilkan Array
    for (int i = 0; i < baris; i++) {
        cout << "[ ";
        for (int j = 0; j < kolom; j++) {
            cout << matriks[i][j] << "\t";
        }
        cout << "]" << endl;
    }

    // Menghitung dan Menampilkan Rata-rata
    double rata_rata = total / (baris * kolom);

    cout << "\n======================" << endl;
    cout << "Total Elemen   : " << (baris * kolom) << endl;
    cout << "Total Nilai    : " << total << endl;
    cout << "Nilai Rata-rata: " << rata_rata << endl;
    cout << "======================" << endl;

    return 0;
}