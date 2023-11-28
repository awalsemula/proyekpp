#include <iostream>
#include <string>
using namespace std;

struct Karyawan {
    string nama;
    string nik;
    string tanggalLahir;
    string status;
    string jabatan;
    string level;
    string divisi;
    double gaji;
    int masaKerja;
    char jenisKelamin;
};

const int max_karyawan = 2;
Karyawan dataKaryawan[max_karyawan];
int jumlahKaryawan = 0;

void tampilkanDataKaryawan() {
    cout << "							\n"; 
    cout << "===== Data Karyawan =====\n";
    for (int i = 0; i < jumlahKaryawan; ++i) {
        cout << "Nama: " << dataKaryawan[i].nama << endl;
        cout << "NIK: " << dataKaryawan[i].nik << endl;
        cout << "Tanggal Lahir: " << dataKaryawan[i].tanggalLahir << endl;
        cout << "Status: " << dataKaryawan[i].status << endl;
        cout << "Jabatan: " << dataKaryawan[i].jabatan << endl;
        cout << "Level: " << dataKaryawan[i].level << endl;
        cout << "Divisi: " << dataKaryawan[i].divisi << endl;
        cout << "Gaji: " << dataKaryawan[i].gaji << endl;
        cout << "Masa Kerja: " << dataKaryawan[i].masaKerja << " tahun\n";
        cout << "Jenis Kelamin: " << (dataKaryawan[i].jenisKelamin == 'L' ? "Laki-laki" : "Perempuan") << endl;
        cout << "------------------------\n";
    }
}

void tambahDataKaryawan() {
    if (jumlahKaryawan < max_karyawan) {
        Karyawan karyawan;

        cout << "Masukkan Nama: ";
        getline(cin, karyawan.nama);
        cout << "Masukkan NIK: ";
        getline(cin, karyawan.nik);
        cout << "Masukkan Tanggal Lahir: ";
        getline(cin, karyawan.tanggalLahir);
        cout << "Masukkan Status: ";
        getline(cin, karyawan.status);
        cout << "Masukkan Jabatan: ";
        getline(cin, karyawan.jabatan);
        cout << "Masukkan Level: ";
        getline(cin, karyawan.level);
        cout << "Masukkan Divisi: ";
        getline(cin, karyawan.divisi);
        cout << "Masukkan Gaji: ";
        cin >> karyawan.gaji;
        cout << "Masukkan Masa Kerja (tahun): ";
        cin >> karyawan.masaKerja;
        cout << "Masukkan Jenis Kelamin (L/P): ";
        cin >> karyawan.jenisKelamin;

        dataKaryawan[jumlahKaryawan] = karyawan;
        jumlahKaryawan++;
		
		cout << "							\n"; 
        cout << "Data Karyawan berhasil ditambahkan.\n";
    } else {
    	cout << "							\n"; 
        cout << "Data Karyawan sudah penuh.\n";
    }
}

void updateDataKaryawan() {
    string nikUpdate;
    cout << "Masukkan NIK Karyawan yang akan diupdate: ";
    cin >> nikUpdate;

    bool found = false;
    for (int i = 0; i < jumlahKaryawan; ++i) {
        if (dataKaryawan[i].nik == nikUpdate) {
            found = true;

            cout << "Masukkan Nama Baru: ";
            getline(cin, dataKaryawan[i].nama);
            cout << "Masukkan Tanggal Lahir Baru: ";
            getline(cin, dataKaryawan[i].tanggalLahir);
            cout << "Masukkan Status Baru: ";
            getline(cin, dataKaryawan[i].status);
            cout << "Masukkan Jabatan Baru: ";
            getline(cin, dataKaryawan[i].jabatan);
            cout << "Masukkan Level Baru: ";
            getline(cin, dataKaryawan[i].level);
            cout << "Masukkan Divisi Baru: ";
            getline(cin, dataKaryawan[i].divisi);
            cout << "Masukkan Gaji Baru: ";
            cin >> dataKaryawan[i].gaji;
            cout << "Masukkan Masa Kerja Baru (tahun): ";
            cin >> dataKaryawan[i].masaKerja;
            cout << "Masukkan Jenis Kelamin Baru (L/P): ";
            cin >> dataKaryawan[i].jenisKelamin;

            cout << "Data Karyawan berhasil diupdate.\n";
            break;
        }
    }

    if (!found) {
    	cout << "							\n"; 
        cout << "NIK Karyawan tidak ditemukan.\n";
    }
}

void hapusDataKaryawan() {
    string nikHapus;
    cout << "Masukkan NIK Karyawan yang akan dihapus: ";
    cin >> nikHapus;

    bool found = false;
    for (int i = 0; i < jumlahKaryawan; ++i) {
        if (dataKaryawan[i].nik == nikHapus) {
            found = true;

            // Memindahkan data pada posisi i ke posisi terakhir
            dataKaryawan[i] = dataKaryawan[jumlahKaryawan - 1];
            jumlahKaryawan--;

            cout << "Data Karyawan berhasil dihapus.\n";
            break;
        }
    }

    if (!found) {
        cout << "NIK Karyawan tidak ditemukan.\n";
    }
}

int main() {
    int pilihan;

    do {
    	 cout << "									\n";
        cout << "===== Aplikasi Data Karyawan =====\n";
        cout << "1. Tampilkan Data Karyawan\n";
        cout << "2. Tambah Data Karyawan\n";
        cout << "3. Update Data Karyawan\n";
        cout << "4. Hapus Data Karyawan\n";
        cout << "0. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> pilihan;
        cin.ignore(); // Membersihkan buffer keyboard

        switch (pilihan) {
            case 1:
                tampilkanDataKaryawan();
                break;
            case 2:
                tambahDataKaryawan();
                break;
            case 3:
                updateDataKaryawan();
                break;
            case 4:
                hapusDataKaryawan();
                break;
            case 0:
                cout << "Terima kasih telah menggunakan aplikasi.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (pilihan != 0);

    return 0;
}
