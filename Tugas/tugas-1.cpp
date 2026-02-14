#include <iostream>

using namespace std;

// Fungsi untuk mencari nilai minimum
int cariMin(int matriks[2][3], int baris, int kolom) {
    int min = matriks[0][0];

    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            if (matriks[i][j] < min) {
                min = matriks[i][j];
            }
        }
    }
    
    return min;
}

// Fungsi untuk mencari nilai maksimum
int cariMax(int matriks[2][3], int baris, int kolom) {
    int max = matriks[0][0];

    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            if (matriks[i][j] > max) {
                max = matriks[i][j];
            }
        }
    }

    return max;
}

// Fungsi untuk menghitung rata-rata
double cariRataRata(int matriks[2][3], int baris, int kolom) {
    int jumlah = 0;
    int banyakElemen = baris * kolom;

    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            jumlah = jumlah + matriks[i][j];
        }
    }

    double rataRata = (double)jumlah / banyakElemen;
    return rataRata;
}

int main() {
    int matriks[2][3] = {
        {6, 7, 8},
        {1, 5, 3}
    };

    int baris = 2;
    int kolom = 3;

    int nilaiMin = cariMin(matriks, baris, kolom);
    int nilaiMax = cariMax(matriks, baris, kolom);
    double nilaiRataRata = cariRataRata(matriks, baris, kolom);

    cout << "Nilai minimum = " << nilaiMin << endl;
    cout << "Nilai maksimum = " << nilaiMax << endl;
    cout << "Nilai rata-rata = " << nilaiRataRata << endl;

    return 0;
}