#include <iostream>
using namespace std;

int main(){
    int sisi[3];
    int j;
    int sisi_terpanjang;
    int sisi_lainnya[2];
    bool cek_bil_asli;
    bool cek_segitiga;
    int total_kuadrat;

    cout << "== PROGRAM MENENTUKAN JENIS SEGITIGA ==" << endl << endl;
    for (int i = 0; i < 3; i++){
        cout << "Masukkan sisi ke-" << i + 1 << ": ";
        cin >> sisi[i];
    }

    j = 0;
    sisi_terpanjang = sisi[0];
    for (int i = 1; i < 3; i++){
        if (sisi[i] >= sisi_terpanjang){
            sisi_lainnya[j] = sisi_terpanjang;
            sisi_terpanjang = sisi[i];
            j++;
        } else {
            sisi_lainnya[j] = sisi[i];
            j++;
        }    
    }

    cek_bil_asli = (sisi[0] > 0) && (sisi[1] > 0) && (sisi[2] > 0);
    cek_segitiga = sisi_lainnya[0] + sisi_lainnya[1] > sisi_terpanjang;
    
    if (cek_segitiga == true && cek_bil_asli == true){
        // cout << "Sisi terpanjang adalah: " << sisi_terpanjang << endl;
        // cout << "Sisi lainnya adalah: " << sisi_lainnya[0] << " dan " << sisi_lainnya[1] << endl;
        total_kuadrat = (sisi_lainnya[0] * sisi_lainnya[0]) + (sisi_lainnya[1] * sisi_lainnya[1]);
        
        if (total_kuadrat == sisi_terpanjang*sisi_terpanjang){
            cout << "\nIni adalah segitiga siku-siku" << endl;

        } else if (sisi_lainnya[0] == sisi_lainnya[1]){

            if (sisi_lainnya[0] == sisi_terpanjang){
                cout << "\nIni adalah segitiga sama sisi" << endl;
            } else {
                cout << "\nIni adalah segitiga sama kaki" << endl;
            }
        
        } else {
            cout << "\nIni adalah segitiga sembarang" << endl;
        }
        
    } else if (cek_bil_asli == false){
        cout << "\nInput harus berupa bilangan asli" << endl;
    
    } else {
        cout << "\nIni tidak bisa membentuk segitiga" << endl;
    }

    return 0;
}