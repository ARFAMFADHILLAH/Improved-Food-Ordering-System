#include <iostream>
#include <vector>
#include <map>
#include <iomanip>

using namespace std;

struct MenuItem {
    int id;
    string name;
    int price;
};

size_t findIndexById(const vector<MenuItem> &menu, int id) {
    for (size_t i = 0; i < menu.size(); i++) {
        if (menu[i].id == id) return i;
    }
    return menu.size(); // Return size if not found
}

void printOrder(const map<int, int> &orders, const vector<MenuItem> &menu, const string &type) {
    int total = 0;
    int index = 1;

    if (orders.empty()) {
        cout << "Tidak ada pesanan " << type << '\n';
        return;
    }

    cout << "Daftar " << type << " yang dipesan:\n";
    for (const auto &order : orders) {
        size_t idx = findIndexById(menu, order.first);
        if (idx != menu.size()) { // Check if found
            int quantity = order.second;
            int subtotal = menu[idx].price * quantity;
            total += subtotal;
            cout << index++ << ". " << menu[idx].name << " sebanyak " << quantity
                 << " dengan total harga Rp." << subtotal << '\n';
        }
    }
    cout << "Total harga untuk pesanan " << type << ": Rp." << total << '\n';
}

int main() {
    vector<MenuItem> makanan = {
        {1, "Ayam Goreng", 12000},
        {2, "Ayam Bakar", 13000},
        {3, "Ayam Geprek", 10000},
        {4, "Ayam Suwir", 11000},
        {5, "Ayam Pop", 10000},
        {6, "Ayam Krispi", 15000},
        {7, "Ayam Kecap", 14000}
    };

    vector<MenuItem> minuman = {
        {1, "Air Mineral", 4000},
        {2, "Es Teh Manis", 5000},
        {3, "Es Jeruk", 6000},
        {4, "Soda Gembira", 10000},
        {5, "Es Kopi", 8000}
    };

    map<int, int> pesananMakanan;
    map<int, int> pesananMinuman;

    // Input pesanan makanan
    cout << "Masukkan pesanan makanan (masukkan -1 untuk selesai):\n";
    int nomor, kuantitas;
    while (true) {
        cin >> nomor;
        if (nomor == -1) break;
        cin >> kuantitas;

        if (kuantitas <= 0) {
            cout << "Kuantitas harus lebih dari 0!" << '\n';
            continue;
        }

        if (findIndexById(makanan, nomor) != makanan.size()) {
            pesananMakanan[nomor] += kuantitas;
        } else {
            cout << "Nomor makanan tidak valid!" << '\n';
        }
    }

    // Input pesanan minuman
    cout << "Masukkan pesanan minuman (masukkan -1 untuk selesai):\n";
    while (true) {
        cin >> nomor;
        if (nomor == -1) break;
        cin >> kuantitas;

        if (kuantitas <= 0) {
            cout << "Kuantitas harus lebih dari 0!" << '\n';
            continue;
        }

        if (findIndexById(minuman, nomor) != minuman.size()) {
            pesananMinuman[nomor] += kuantitas;
        } else {
            cout << "Nomor minuman tidak valid!" << '\n';
        }
    }

    // Cetak pesanan
    printOrder(pesananMakanan, makanan, "makanan");
    cout << '\n';
    printOrder(pesananMinuman, minuman, "minuman");
    cout << '\n';

    // Hitung total harga
    int totalHarga = 0;

    for (const auto &order : pesananMakanan) {
        size_t idx = findIndexById(makanan, order.first);
        if (idx != makanan.size()) {
            totalHarga += makanan[idx].price * order.second;
        }
    }

    for (const auto &order : pesananMinuman) {
        size_t idx = findIndexById(minuman, order.first);
        if (idx != minuman.size()) {
            totalHarga += minuman[idx].price * order.second;
        }
    }

    cout << "Total harga untuk seluruh pesanan: Rp." << totalHarga << '\n';

    return 0;
}