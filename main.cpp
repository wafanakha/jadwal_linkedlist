#include <iostream>
using namespace std;

struct Node
{
    int nim;
    string name;
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
void insertDepan(int nilai, string name)
{
    Node *baru = new Node;
    baru->nim = nilai;
    baru->name = name;
    baru->next = NULL;
    if (isEmpty() == true)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        baru->next = head;
        head = baru;
    }
}
void insertBelakang(int nilai, string name)
{
    Node *baru = new Node;
    baru->nim = nilai;
    baru->name = name;
    baru->next = NULL;
    if (isEmpty() == true)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        tail->next = baru;
        tail = baru;
    }
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
void insertTengah(int nim, int posisi, string name)
{
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        Node *baru, *bantu;
        baru = new Node();
        baru->nim = nim;
        baru->name = name;
        bantu = head;
        int nomor = 1;
        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
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
void ubahDepan(int nim, string name)
{
    if (isEmpty() == 0)
    {
        head->nim = nim;
        head->name = name;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
void ubahTengah(int nim, int posisi, string name)
{
    Node *bantu;
    if (isEmpty() == 0)
    {
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
            bantu = head;
            int nomor = 1;
            while (nomor < posisi)
            {
                bantu = bantu->next;
                nomor++;
            }
            bantu->nim = nim;
            bantu->name = name;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
void ubahBelakang(int nim, string name)
{
    if (isEmpty() == 0)
    {
        tail->nim = nim;
        tail->name = name;
    }
    else
    {
        cout << "List masih kosong!" << endl;
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
        cout << "Nama\t\tNIM\n";
        cout << "==============================\n";
        while (bantu != NULL)
        {
            cout << bantu->name << "\t\t" << bantu->nim << "\n";
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
        cout << "5. Ubah Belakang" << endl;
        cout << "6. Ubah Tengah" << endl;
        cout << "7. Hapus Depan" << endl;
        cout << "8. Hapus Belakang" << endl;
        cout << "9. Hapus Tengah" << endl;
        cout << "10. Hapus List" << endl;
        cout << "11. Tampilkan" << endl;
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
            int data;
            string name;
            cout << "Masukkan nama\t: ";
            cin >> name;
            cout << "Masukkan NIM\t: ";
            cin >> data;
            insertDepan(data, name);
            cout << "Data " << name << " Berhasil diinput\n\n";
            break;
        }
        case 2:
        {
            cout << "--Tambah Belakang--\n";
            int data;
            string name;
            cout << "Masukkan nama\t: ";
            cin >> name;
            cout << "Masukkan NIM\t: ";
            cin >> data;
            insertBelakang(data, name);
            cout << "Data " << name << " Berhasil diinput\n\n";
            break;
        }
        case 3:
        {
            cout << "--Tambah Tengah--\n";
            int data, posisi;
            string name;
            cout << "Masukkan nama\t: ";
            cin >> name;
            cout << "Masukkan NIM\t: ";
            cin >> data;
            cout << "Masukkan Posisi\t:";
            cin >> posisi;
            insertTengah(data, posisi, name);
            cout << "Data " << name << " Berhasil diinput\n\n";

            break;
        }
        case 4:
        {
            cout << "--Ubah Depan--\n";
            int data;
            string name, oldName;
            cout << "Masukkan nama\t: ";
            cin >> name;
            cout << "Masukkan NIM\t: ";
            cin >> data;
            oldName = head->name;
            ubahDepan(data, name);
            cout << "Data " << oldName << " telah diganti dengan data " << name << " !\n\n";
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