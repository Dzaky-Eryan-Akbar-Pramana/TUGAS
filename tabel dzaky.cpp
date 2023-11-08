#include <iostream>
using namespace std;

int main() {
    string nim, nama;
    cout<<"Nama\t: Dzaky Eryan Akbar Pramana"<<endl;
    cout<<"Kelas\t: A"<<endl;
	cout<<"NIM\t: 2300018036 "<<endl<<endl;
	cout<<"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl<<endl;
	cout <<"_________________TUGAS TABEL_________________"<<endl<<endl;
	cout<<"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl<<endl;
    


    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << "+-----"; // Output garis vertikal
        }
        std::cout << "+\n"; // Output ujung garis horizontal
        for (int j = 0; j < 3; j++) {
            std::cout << "|     "; // Output spasi kosong
        }
        std::cout << "|\n"; // Output baris kosong
    }

    // Output garis horizontal di bagian bawah tabel
    for (int j = 0; j < 3; j++) {
        std::cout << "+-----"; // Output garis vertikal
    }
    std::cout << "+\n"; // Output ujung garis horizontal

    return 0;
}
