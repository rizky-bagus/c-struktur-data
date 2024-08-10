#include <stdio.h>
#include <string.h>

#define MAX_MAHASISWA 100

// Definisi struktur mahasiswa
typedef struct {
    char npm[15];
    char nama[50];
    char tempat_lahir[30];
    char tanggal_lahir[15];
    char prodi[30];
} Mahasiswa;

// Deklarasi array dan variabel untuk menyimpan jumlah mahasiswa
Mahasiswa mahasiswa[MAX_MAHASISWA];
int jumlah_mahasiswa = 0;

// Deklarasi fungsi-fungsi sebelum digunakan
void tampilkanMenu();
void tambahMahasiswa();
void tampilkanMahasiswa();
void ubahMahasiswa();
void hapusMahasiswa();

// Fungsi untuk menambahkan mahasiswa
void tambahMahasiswa() {
    if (jumlah_mahasiswa < MAX_MAHASISWA) {
        Mahasiswa m;
        printf("Masukkan NPM: ");
        scanf("%s", m.npm);
        printf("Masukkan Nama: ");
        scanf(" %[^\n]s", m.nama);
        printf("Masukkan Tempat Lahir: ");
        scanf(" %[^\n]s", m.tempat_lahir);
        printf("Masukkan Tanggal Lahir (YYYY-MM-DD): ");
        scanf("%s", m.tanggal_lahir);
        printf("Masukkan Program Studi: ");
        scanf(" %[^\n]s", m.prodi);

        mahasiswa[jumlah_mahasiswa] = m;
        jumlah_mahasiswa++;
    } else {
        printf("Data mahasiswa penuh!\n");
    }
}

// Fungsi untuk menampilkan data mahasiswa
void tampilkanMahasiswa() {
    if (jumlah_mahasiswa == 0) {
        printf("Tidak ada data mahasiswa.\n");
    } else {
        for (int i = 0; i < jumlah_mahasiswa; i++) {
            printf("Mahasiswa %d\n", i+1);
            printf("NPM           : %s\n", mahasiswa[i].npm);
            printf("Nama          : %s\n", mahasiswa[i].nama);
            printf("Tempat Lahir  : %s\n", mahasiswa[i].tempat_lahir);
            printf("Tanggal Lahir : %s\n", mahasiswa[i].tanggal_lahir);
            printf("Prodi         : %s\n\n", mahasiswa[i].prodi);
        }
    }
}

// Fungsi untuk mengubah data mahasiswa
void ubahMahasiswa() {
    char npm[15];
    printf("Masukkan NPM mahasiswa yang akan diubah: ");
    scanf("%s", npm);

    for (int i = 0; i < jumlah_mahasiswa; i++) {
        if (strcmp(mahasiswa[i].npm, npm) == 0) {
            printf("Masukkan Nama baru: ");
            scanf(" %[^\n]s", mahasiswa[i].nama);
            printf("Masukkan Tempat Lahir baru: ");
            scanf(" %[^\n]s", mahasiswa[i].tempat_lahir);
            printf("Masukkan Tanggal Lahir baru (YYYY-MM-DD): ");
            scanf("%s", mahasiswa[i].tanggal_lahir);
            printf("Masukkan Program Studi baru: ");
            scanf(" %[^\n]s", mahasiswa[i].prodi);
            printf("Data mahasiswa berhasil diubah.\n");
            return;
        }
    }
    printf("Mahasiswa dengan NPM %s tidak ditemukan.\n", npm);
}

// Fungsi untuk menghapus data mahasiswa
void hapusMahasiswa() {
    char npm[15];
    printf("Masukkan NPM mahasiswa yang akan dihapus: ");
    scanf("%s", npm);

    for (int i = 0; i < jumlah_mahasiswa; i++) {
        if (strcmp(mahasiswa[i].npm, npm) == 0) {
            for (int j = i; j < jumlah_mahasiswa - 1; j++) {
                mahasiswa[j] = mahasiswa[j + 1];
            }
            jumlah_mahasiswa--;
            printf("Data mahasiswa berhasil dihapus.\n");
            return;
        }
    }
    printf("Mahasiswa dengan NPM %s tidak ditemukan.\n", npm);
}

// Fungsi untuk menampilkan menu
void tampilkanMenu() {
    int pilihan;
    do {
        printf("\nMenu CRUD Mahasiswa:\n");
        printf("1. Tambah Mahasiswa\n");
        printf("2. Tampilkan Mahasiswa\n");
        printf("3. Ubah Mahasiswa\n");
        printf("4. Hapus Mahasiswa\n");
        printf("5. Keluar\n");
        printf("Pilih (1-5): ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                tambahMahasiswa();
                break;
            case 2:
                tampilkanMahasiswa();
                break;
            case 3:
                ubahMahasiswa();
                break;
            case 4:
                hapusMahasiswa();
                break;
            case 5:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
        }
    } while (pilihan != 5);
}

// Fungsi utama (main)
int main() {
    tampilkanMenu();
    return 0;
}
