#include <iostream>
using namespace std;

struct Node
{
    int jam;
    int akhir;
    int hari;
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
void add_jadwal(int jam, int akhir, string kegiatan, int hari)
{
    Node *baru = new Node;
    baru->jam = jam;
    baru->akhir = akhir;
    baru->kegiatan = kegiatan;
    baru->hari = hari;
    if (isEmpty() == true)
    {
        head = tail = baru;
        tail->next = NULL;
        return;
    }
    else if (baru->akhir <= head->jam && baru->hari == head->hari)
    {
        baru->next = head;
        head = baru;
        return;
    }
    else if (baru->hari > tail->hari || baru->jam >= tail->akhir)
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
            if (baru->hari <= current->hari && baru->jam >= current->akhir && baru->akhir <= current->next->jam || current->next->hari == baru->hari && baru->akhir <= current->next->jam)
            {
                baru->next = current->next;
                current->next = baru;
                return;
            }
            current = current->next;
        }
    }
    cout << "Error";
}

void change_jadwal(int jam, int hari, int hariLama, int akhir, string kegiatan, string kegiatanLama)
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
            if (hariLama == current->hari && kegiatanLama == current->kegiatan)
            {
                current->jam = jam;
                current->akhir = akhir;
                current->kegiatan = kegiatan;
                current->hari = hari;
                return;
            }
            current = current->next;
        }
        cout << "Error";
    }
    cout << "Error";
}

void delete_jadwal(int hari, string kegiatan)
{
    Node *temp;
    Node *current = head;

    if (isEmpty() == true)
    {
        cout << "Jadwal Masih kosong";
        return;
    }
    else if (head->kegiatan == kegiatan && head->hari == hari)
    {
        temp = head;
        head = head->next;
        delete temp;
        return;
    }
    else if (tail->kegiatan == kegiatan && tail->hari == hari)
    {
        temp = tail;
        current = head;
        while (current->next != tail)
        {
            current = current->next;
        }
        tail = current;
        tail->next = NULL;
        delete temp;
        return;
    }
    else
    {
        while (current != NULL)
        {
            if (current->next->hari == hari && current->next->kegiatan == kegiatan)
            {
                temp = current->next;
                current->next = temp->next;
                delete temp;
                return;
            }
            current = current->next;
        }
        cout << "Error";
    }
    cout << "Error";
}
void clearList()
{
    Node *current, *hapus;
    current = head;
    while (current != NULL)
    {
        hapus = current;
        current = current->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}
void tampil()
{
    Node *current;
    current = head;
    if (isEmpty() == false)
    {
        cout << "==============================\n";
        cout << "kegiatan\t\tjam\n";
        cout << "==============================\n";
        while (current != NULL)
        {
            cout << current->kegiatan << "\t\t" << current->jam << " - " << current->akhir << "\n";
            current = current->next;
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
            int data, akhir, hari;
            string kegiatan;
            cout << "Masukkan nama kegiatan\t: ";
            cin >> kegiatan;
            cout << "Masukkan jam kegiatan dimulai\t: ";
            cin >> data;
            cout << "Masukkan jam kegiatan berakhir\t: ";
            cin >> akhir;
            cout << "Masukkan hari kegiatan \t: ";
            cin >> hari;
            add_jadwal(data, akhir, kegiatan, hari);
            cout << "Data " << kegiatan << " Berhasil diinput\n\n";
            break;
        }
        case 2:
        {
            cout << "--Tambah Belakang--\n";
            int data, akhir, hari, hariLama;
            string kegiatan, kegiatanLama;
            cout << "Masukkan kegiatan yang ingin diubah\t: ";
            cin >> kegiatanLama;
            cout << "Masukkan kegiatan yang ingin diubah\t: ";
            cin >> hariLama;
            cout << "Masukkan nama kegiatan baru\t: ";
            cin >> kegiatan;
            cout << "Masukkan jam kegiatan baru dimulai\t: ";
            cin >> data;
            cout << "Masukkan jam kegiatan baru berakhir\t: ";
            cin >> akhir;
            change_jadwal(data, hari, hariLama, akhir, kegiatan, kegiatanLama);
            cout << "Data " << kegiatanLama << " Berhasil diubah\n\n";
            break;
        }
        case 3:
        {
            cout << "--Tambah Tengah--\n";
            int data;
            string kegiatan;
            cout << "Masukkan nama kegiatan yang ingin dihapus";
            cin >> kegiatan;
            cout << "Masukkan hari dari kegiatan yang ingin dihapus";
            cin >> data;
            delete_jadwal(data, kegiatan);
            break;
        }
        case 4:
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
