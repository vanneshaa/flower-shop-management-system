
#include <iostream>
#include <string>
#include <stack>
using namespace std;

// Struct untuk data bunga
struct Bunga {
    string nama;
    string jenis;
    int stok;
    double harga;
};

// Fungsi untuk menampilkan semua bunga
void tampilkanBunga(Bunga* b, int jumlah) { 
    if (jumlah == 0) { 
        cout << "Tidak ada bunga dalam stok.\n"; 
        return;
    }
    cout << "\n=== Daftar Bunga ===\n";
    for (int i = 0; i < jumlah; i++) {
        cout << i + 1 << ". Nama: " << b[i].nama 
             << ", Jenis: " << b[i].jenis 
             << ", Stok: " << b[i].stok 
             << ", Harga: Rp" << b[i].harga << endl;
    }
}

// Fungsi untuk mencari bunga berdasarkan nama
void cariBunga(Bunga* b, int jumlah, string nama) { // sequental search/Linear search
    for (int i = 0; i < jumlah; i++) {
        if (b[i].nama == nama) { 
            cout << "\nBunga ditemukan:\n"; 
            cout << "Nama: " << b[i].nama 
                 << ", Jenis: " << b[i].jenis 
                 << ", Stok: " << b[i].stok 
                 << ", Harga: Rp" << b[i].harga << endl;
            return;
        }
    }
    cout << "Bunga dengan nama " << nama << " tidak ditemukan.\n";
}

// Fungsi untuk mengurutkan bunga berdasarkan harga
void urutkanBunga(Bunga* b, int jumlah) { // sorting (bublle sort )
    for (int i = 0; i < jumlah - 1; i++) { 
        for (int j = 0; j < jumlah - i - 1; j++) {
            if (b[j].harga > b[j + 1].harga) {
                swap(b[j], b[j + 1]); 
            }
        }
    }
    cout << "Data bunga telah diurutkan berdasarkan harga.\n";
}

// Fungsi utama
int main() {
    Bunga bunga[100]; //array menyimpan data [100]
    int jumlah = 0;
    stack<Bunga> undoStack; // stack digunakan untuk menyimpan data bunga yang baru ditambahkan
    int pilihan;

    do {
        cout << "\n=== Sistem Manajemen Toko Bunga ===\n";
        cout << "1. Tambah Bunga\n";
        cout << "2. Tampilkan Semua Bunga\n";
        cout << "3. Cari Bunga berdasarkan Nama\n";
        cout << "4. Urutkan Bunga berdasarkan Harga\n";
        cout << "5. Undo Bunga\n";
        cout << "6. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;
// percabangan 
        if (pilihan == 1) {
            if (jumlah >= 100) {
                cout << "Kapasitas maksimum tercapai.\n";
            } else {
                Bunga b;
                cout << "Masukkan nama bunga: ";
                cin.ignore();
                getline(cin, b.nama);
                cout << "Masukkan jenis bunga: ";
                getline(cin, b.jenis);
                cout << "Masukkan stok bunga: ";
                cin >> b.stok;
                cout << "Masukkan harga bunga: ";
                cin >> b.harga;

                bunga[jumlah] = b;
                undoStack.push(b);
                jumlah++;
                cout << "Bunga berhasil ditambahkan.\n";
            }
        } else if (pilihan == 2) {
            tampilkanBunga(bunga, jumlah);
        } else if (pilihan == 3) {
            string nama;
            cout << "Masukkan nama bunga yang ingin dicari: ";
            cin.ignore(); 
            getline(cin, nama);
            cariBunga(bunga, jumlah, nama);
        } else if (pilihan == 4) {
            urutkanBunga(bunga, jumlah);
        } else if (pilihan == 5) {
            if (!undoStack.empty()) {
                undoStack.pop();
                jumlah--;
                cout << "Undo berhasil. Bunga terakhir dihapus.\n";
            } else {
                cout << "Tidak ada data untuk di-undo.\n";
            }
        } else if (pilihan == 6) {
            cout << "Keluar dari program.\n";
        } else {
            cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 6);

    return 0;
}
