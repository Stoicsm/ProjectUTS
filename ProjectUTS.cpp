#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Struct untuk menyimpan menu
struct TehMenu {
    int id;
    string namaTeh;
    float harga;
};

// Node untuk linked list pesanan
struct PesananNode {
    int idTeh;
    int jumlah;
    PesananNode* next; // Pointer
};
// Inisialisasi menu teh
TehMenu menuTeh[10] = {
    {1, "Original Tea", 5000},
    {2, "Matcha Tea", 8000},
    {3, "Manggo Tea", 8000},-
    {4, "Earl Grey Tea", 8000},
    {5, "Chamomile Tea", 9000},
    {6, "Spring Tea", 10000},
    {7, "Milky Choco", 10000},
    {8, "Milky Leci", 12000},
    {9, "Milkytea", 10000},
    {10, "Greentea", 9000}
};

// Fungsi untuk menambah pesanan ke linked list
bool tambahPesanan(PesananNode** kepala, int id, int jumlah) {
    if(id < 1 || id > 10) {
        cout << "Pesanan tidak valid. Silakan coba lagi.\n";
        return false;
    }
    
    PesananNode* pesananBaru = new PesananNode();
    pesananBaru->idTeh = id;
    pesananBaru->jumlah = jumlah;
    pesananBaru->next = (*kepala);
    (*kepala) = pesananBaru;
    cout << "Pesanan berhasil ditambahkan.\n";
    return true;
}

void tampilkanPesanan(PesananNode* n) {
    if (n == nullptr) {
        cout << "Tidak ada pesanan.\n";
        return;
    }
    cout << left << setw(5) << "ID" << setw(20) << "Nama Teh" << setw(10) << "Jumlah" << setw(15) << "Total Harga" << endl;
    cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl; // Garis pemisah
    while (n != nullptr) {
        cout << left << setw(5) << n->idTeh << setw(20) << menuTeh[n->idTeh - 1].namaTeh << setw(10) << n->jumlah << "Rp" << setw(14) << (menuTeh[n->idTeh - 1].harga * n->jumlah) << endl;
        n = n->next;
    }
}


// Fungsi untuk menghapus pesanan berdasarkan ID
void hapusPesanan(PesananNode** kepala, int id) {
    PesananNode* temp = *kepala, *prev = nullptr;
    
    // Jika kepala itu sendiri yang harus dihapus
    if (temp != nullptr && temp->idTeh == id) {
        *kepala = temp->next; // Pindahkan kepala
        delete temp; // Hapus node lama
        cout << "Pesanan berhasil dihapus.\n";
        return;
    }

    // Cari node yang harus dihapus, simpan node sebelumnya
    while (temp != nullptr && temp->idTeh != id) {
        prev = temp;
        temp = temp->next;
    }

    // Jika ID tidak ditemukan
    if (temp == nullptr) {
        cout << "Pesanan tidak ditemukan. Tidak dapat dihapus.\n";
        return;
    }

    // Unlink node dari linked list dan hapus
    prev->next = temp->next;
    delete temp;
    cout << "Pesanan berhasil dihapus.\n";
}

void tampilkanMenu() {
    cout << "Menu Teh:\n";
    cout << left << setw(5) << "ID" << setw(20) << "Nama Teh" << setw(15) << "Harga" << endl;
    cout << setfill('-') << setw(40) << "-" << setfill(' ') << endl; // Garis pemisah
    for (int i = 0; i < 10; i++) {
        cout << left << setw(5) << menuTeh[i].id << setw(20) << menuTeh[i].namaTeh << "Rp" << setw(14) << menuTeh[i].harga << endl;
    }
}


int main() {
    PesananNode* kepala = nullptr;
    int pilihan, id, jumlah;

    while (true) {
        cout << "\nSistem Pemesanan Royal Tea\n";
        cout << "1. Pilihan Menu\n";
        cout << "2. Tambah Pesanan\n";
        cout << "3. Tampilkan Pesanan\n";
        cout << "4. Hapus Pesanan\n";
        cout << "5. Keluar\n";
        cout << "Masukkan pilihan Anda: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tampilkanMenu();
                break;
           case 2: {
            cout << "Masukkan ID Teh: ";
            cin >> id;
            cout << "Masukkan jumlah: ";
            cin >> jumlah;
            bool berhasil = tambahPesanan(&kepala, id, jumlah);
            if (berhasil) {
            cout << "Daftar Pesanan:\n";
                 tampilkanPesanan(kepala);
                  }
                 break;
                  }
            case 3:
                tampilkanPesanan(kepala);
                break;
            case 4:
                cout << "Masukkan ID Teh yang akan dihapus: ";
                cin >> id;
                hapusPesanan(&kepala, id);
                break;
            case 5:
                cout << "Terima kasih bosku, mampir lagi yaa....\n";
                return 0;
            default:
                cout << "Pilihan tidak valid, silakan coba lagi.\n";
        }
    }

    return 0;
}

