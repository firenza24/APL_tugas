#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct MataKuliah {
    int no;
    string matkul;
    int sks;
    string namaDosen;
};

// mengubah string ke huruf kecil (Case-Insensitive)
string toLower(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

void bersihkan_terminal() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void tampilkanMatkul(MataKuliah *ptr, int jumlahData) {
    // header
    cout << "\n==========================================================\n";
    cout << "| " << left << setw(3) << "No"
         << "| " << setw(42) << "Nama Mata Kuliah"
         << "| " << setw(5) << "SKS" << " |\n";
    cout << "----------------------------------------------------------\n";
    
    // isi tabel
    for (int i = 0; i < jumlahData; i++) {
        cout << "| " << left << setw(3) << (ptr + i)->no
             << "| " << setw(42) << (ptr + i)->matkul
             << "| " << setw(5) << (ptr + i)->sks << " |\n";
    }
    cout << "==========================================================\n";
}

void cariDosen(MataKuliah *daftar, int size, string keyword) {
    int jumlahDosenTerdeteksi = 0;
    string keywordLower = toLower(keyword);
    bool headerSudahMuncul = false;

    cout << "\nHASIL PENCARIAN DOSEN (KATA KUNCI: \"" << keyword << "\"):" << endl;

    for (int i = 0; i < size; i++) {

        MataKuliah *item = (daftar + i);

        // Bandingkan mata kuliah dalam format huruf kecil
        if (toLower(item->matkul).find(keywordLower) != string::npos) { 
            if (!headerSudahMuncul) {
                cout << "======================================================================================================" << endl;
                cout << "| " << left << setw(4)  << "No"
                     << "| " << setw(50) << "Nama Dosen"
                     << "| " << setw(40) << "Mata Kuliah" << " |" << endl;
                cout << "------------------------------------------------------------------------------------------------------" << endl;
                headerSudahMuncul = true;
            }

            string strDosen = item->namaDosen;
            size_t start = 0;
            size_t end = strDosen.find(" / ");

            while (end != string::npos) {
                cout << "| " << left << setw(4)  << ++jumlahDosenTerdeteksi
                     << "| " << setw(50) << strDosen.substr(start, end - start)
                     << "| " << setw(40) << item->matkul << " |" << endl;
                
                start = end + 3;
                end = strDosen.find(" / ", start);
            }

            // Menampilkan dosen terakhir (atau dosen tunggal)
            cout << "| " << left << setw(4)  << ++jumlahDosenTerdeteksi
                 << "| " << setw(50) << strDosen.substr(start)
                 << "| " << setw(40) << item->matkul << " |" << endl;
        }
    }

    if (jumlahDosenTerdeteksi == 0) {
        cout << "Maaf, tidak ada dosen yang ditemukan untuk kata kunci tersebut." << endl;
    } else {
        cout << "======================================================================================================" << endl;
    }
}

int main() {

    const int jumlahData = 7;

    MataKuliah *daftarKuliah = new MataKuliah[jumlahData] {
        {1, "Aljabar Linear", 3, "Ir. Addy Suyatno, S.Kom., M.Kom. / Muhammad Labib Jundillah, S.Kom., M.Kom."},
        {2, "Algoritma dan Pemrograman Lanjut", 3, "Ir. Novianti Puspitasari, S.Kom., M.Eng / Awang Harsa Kridalaksana, S.Kom., M.Kom."},
        {3, "Basis Data", 3, "Ummul Hairah, S.Pd., M.T / Ramadiani, S.Pd., M.Si., M.Kom., Ph.D."},
        {4, "Pendidikan Bahasa Indonesia", 2, "Rasni Alex, S.E, M.M"},
        {5, "Pendidikan Karakter, Etika dan Profesi", 3, "Andi Tejawati, S.Sos., M.Si."},
        {6, "Statistika", 3, "Prof. Dr. Fahrul Agus, S.Si., M.T. / Wasono, S.Si., M.Si."},
        {7, "Struktur Data", 3, "Masna Wati, S.Si., M.T. / Rosmasari, S.Kom., M.T."}
    };

    string kunci;
    while (true) {

        bersihkan_terminal();

        cout << "========== DAFTAR MATA KULIAH ==========" << endl;
        tampilkanMatkul(daftarKuliah, jumlahData);

        cout << "\nMasukkan kata kunci mata kuliah (0 atau 'keluar' untuk berhenti): ";
        if (!getline(cin, kunci)) break;
        
        // Cek keluar dengan case-insensitive
        string kunciCek = toLower(kunci);
        if (kunciCek == "keluar" || kunciCek == "0") break;

        if (kunci.empty()) continue;

        bersihkan_terminal();

        // tampilan hasil pencarian
        cariDosen(daftarKuliah, jumlahData, kunci);

        cout << "\nTekan ENTER untuk mencari lagi...";
        cin.get();
    }
    delete[] daftarKuliah;
    daftarKuliah = nullptr;

    cout << "\nProgram selesai. Sampai jumpa!" << endl;
    return 0;
}