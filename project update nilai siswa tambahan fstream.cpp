#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void tampilkanNilai(vector<int> nilai){
    cout << "\nDaftar Nilai\n";

    for(int i = 0; i < nilai.size(); i++){
        cout << "Nilai ke-" << i + 1
             << " : " << nilai[i] << endl;
    }
}

int tampilkanTotal(vector<int> nilai){
    int total = 0;

    for(int i = 0; i < nilai.size(); i++){
        total += nilai[i];
    }

    return total;
}

int tampilkanTinggi(vector<int> nilai){
    int max = nilai[0];

    for(int i = 1; i < nilai.size(); i++){
        if(nilai[i] > max){
            max = nilai[i];
        }
    }

    return max;
}

int tampilkanRendah(vector<int> nilai){
    int min = nilai[0];

    for(int i = 1; i < nilai.size(); i++){
        if(nilai[i] < min){
            min = nilai[i];
        }
    }

    return min;
}

int main(){

    string nama;
    int jumlah;

    vector<int> nilai;

    cout << "===== SISTEM NILAI =====\n\n";

    cout << "Nama : ";
    cin >> nama;

    cout << "Jumlah Nilai : ";
    cin >> jumlah;

    for(int i = 0; i < jumlah; i++){

        int n;

        cout << "Nilai ke-" << i + 1 << " : ";
        cin >> n;

        nilai.push_back(n);
    }

    tampilkanNilai(nilai);

    int total = tampilkanTotal(nilai);
    double rata = (double)total / nilai.size();

    cout << "\n===== HASIL =====\n";

    cout << "Nama : " << nama << endl;
    cout << "Total : " << total << endl;
    cout << "Rata-rata : " << rata << endl;
    cout << "Nilai Tertinggi : "
         << tampilkanTinggi(nilai) << endl;

    cout << "Nilai Terendah : "
         << tampilkanRendah(nilai) << endl;

    ofstream file("nilai_siswa.txt", ios::app);

    file << "====================\n";
    file << "Nama : " << nama << endl;
    file << "Total : " << total << endl;
    file << "Rata-rata : " << rata << endl;
    file << "Nilai Tertinggi : "
         << tampilkanTinggi(nilai) << endl;

    file << "Nilai Terendah : "
         << tampilkanRendah(nilai) << endl;

    file.close();

    cout << "\n===== ISI FILE =====\n";

    ifstream baca("nilai_siswa.txt");

    string text;

    while(getline(baca, text)){
        cout << text << endl;
    }

    baca.close();

    return 0;
}