#include <iostream>
using namespace std;

struct Node
{
    int jam;
    int akhir;
    string kegiatan;
    Node *next;
};
Node *head;
Node *tail;
void init()
{
    head = NULL;
    tail = NULL;
}
bool isEmpty()
{
    if (head == NULL)
        return true;
    else
        return false;
}
void add_jadwal(int jam, int akhir, string kegiatan)
{
    Node *baru = new Node;
    baru->jam = jam;
    baru->akhir = akhir;
    baru->kegiatan = kegiatan;
    if (isEmpty() == true)
    {
        head = tail = baru;
        tail->next = NULL;
        return;
    }
    else if (baru->akhir <= head->jam)
    {
        baru->next = head;
        head = baru;
        return;
    }
    else if (baru->jam >= tail->akhir)
    {
        tail->next = baru;
        tail = baru;
        return;
    }
    else
    {
        Node *current = head;
        while (current != NULL)
        {
            if (baru->jam >= current->akhir && baru->akhir <= current->next->jam)
            {
                baru->next = current->next;
                current->next = baru;
                return;
            }
            current = current->next;
        }
        cout << "Error";
    }
    cout << "Error";
}

void change_jadwal(int jam, int akhir, string kegiatan, string kegiatanLama)
{
    if (isEmpty() == true)
    {
        cout << "Jadwal Masih kosong";
        return;
    }
    else
    {
        Node *current = head;
        while (current != NULL)
        {
            if (kegiatanLama == current->kegiatan)
            {
                current->jam = jam;
                current->akhir = akhir;
                current->kegiatan = kegiatan;
                return;
            }
            current = current->next;
        }
        cout << "Error";
    }
    cout << "Error";
}
int hitungList()
{
    Node *hitung;
    hitung = head;
    int jumlah = 0;
    while (hitung != NULL)
    {
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}
void hapusDepan()
{
    Node *hapus;
    if (isEmpty() == false)
    {
        if (head->next != NULL)
        {
            hapus = head;
            head = head->next;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}
void hapusBelakang()
{
    Node *hapus;
    Node *bantu;
    if (isEmpty() == false)
    {
        if (head != tail)
        {
            hapus = tail;
            bantu = head;
            while (bantu->next != tail)
            {
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}
void hapusTengah(int posisi)
{
    Node *bantu, *hapus, *sebelum;
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi di luar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        int nomor = 1;
        bantu = head;
        while (nomor <= posisi)
        {
            if (nomor == posisi - 1)
            {
                sebelum = bantu;
            }
            if (nomor == posisi)
            {
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        sebelum->next = bantu;
        delete hapus;
    }
}
void clearList()
{
    Node *bantu, *hapus;
    bantu = head;
    while (bantu != NULL)
    {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}
void tampil()
{
    Node *bantu;
    bantu = head;
    if (isEmpty() == false)
    {
        cout << "==============================\n";
        cout << "kegiatan\t\tjam\n";
        cout << "==============================\n";
        while (bantu != NULL)
        {
            cout << bantu->kegiatan << "\t\t" << bantu->jam << " - " << bantu->akhir << "\n";
            bantu = bantu->next;
        }
        cout << endl;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
int main()
{
    init();

    while (true)
    {
        cout << "Program Single Linked List NON-Circular" << endl;
        cout << "++++++++=====+++++++++++" << endl;
        cout << "1. Tambah Depan" << endl;
        cout << "2. Tambah Belakang" << endl;
        cout << "3. Tambah Tengah" << endl;
        cout << "4. Ubah Depan" << endl;
        cout << "0. Exit" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 0:
        {
            return 0;
        }
        case 1:
        {
            cout << "--Tambah Depan--\n";
            int data, akhir;
            string kegiatan, hari;
            cout << "Masukkan nama kegiatan\t: ";
            cin >> kegiatan;
            cout << "Masukkan jam kegiatan dimulai\t: ";
            cin >> data;
            cout << "Masukkan jam kegiatan berakhir\t: ";
            cin >> akhir;

            add_jadwal(data, akhir, kegiatan);
            cout << "Data " << kegiatan << " Berhasil diinput\n\n";
            break;
        }
        case 2:
        {
            cout << "--Tambah Belakang--\n";
            int data, akhir;
            string kegiatan, kegiatanLama;
            cout << "Masukkan kegiatan yang ingin diubah\t: ";
            cin >> kegiatanLama;
            cout << "Masukkan nama kegiatan baru\t: ";
            cin >> kegiatan;
            cout << "Masukkan jam kegiatan baru dimulai\t: ";
            cin >> data;
            cout << "Masukkan jam kegiatan baru berakhir\t: ";
            cin >> akhir;
            change_jadwal(data, akhir, kegiatan, kegiatanLama);
            cout << "Data " << kegiatanLama << " Berhasil diubah\n\n";
            break;
        }
        case 3:
        {
            cout << "--Tambah Tengah--\n";
            int data, posisi;
            string kegiatan;
            cout << "Masukkan nama\t: ";
            cin >> kegiatan;
            cout << "Masukkan NIM\t: ";
            cin >> data;
            cout << "Masukkan Posisi\t:";
            cin >> posisi;
            cout << "Data " << kegiatan << " Berhasil diinput\n\n";

            break;
        }
        case 4:
        {
            cout << "--Ubah Depan--\n";
            int data;
            string kegiatan, oldkegiatan;
            cout << "Masukkan nama\t: ";
            cin >> kegiatan;
            cout << "Masukkan NIM\t: ";
            cin >> data;
            oldkegiatan = head->kegiatan;
            cout << "Data " << oldkegiatan << " telah diganti dengan data " << kegiatan << " !\n\n";
            break;
        }
        case 5:
        {
            tampil();
            break;
        }
        default:
        {
            cout << "Invalid choice" << endl;
            break;
        }
        }
    }
    return 0;
}
