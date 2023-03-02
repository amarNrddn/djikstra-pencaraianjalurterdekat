// / Amar Nuruddin


#include <iostream>
#include <string>

//devinisi INFIniti/ takterhingga
#define INFI 999

using namespace std;


int p[31][31];

//rumus dijkstra
void jalur__terpendek(int a[31][31])
{
    int k, i, j;
    for (k = 0; k < 31; k++)
    {
        for (i = 0; i <31; i++)
        {
            for (j = 0; j <31; j++)
            {
                if (a[i][k] + a[k][j] < a[i][j])
                {
                    a[i][j] = a[i][k] + a[k][j];
                    p[i][j] = k;
                }
            }
        }
    }
}

 //Menelusuri jalur terpendek
 
void path(int i, int j, string arr[31])
{
    int k = p[i][j];
    if (k > 0)
    {
        path(i, k, arr);
        cout << "-->  " << arr[k] << " ";
        path(k, j, arr);
    }
}

 // Menampilkan jalur terpendek
 
void mencari__jalur(int a[31][31], int i, int j, string arr[31])
{
    cout << "Lintasan dari Kota " << arr[i] << " Ke " << arr[j] << ":";
    if (a[i][j] < INFI)
    {
        cout << " " << arr[i] << " ";
        path(i, j, arr);
        cout << "--> " << arr[j]<< " || Anad Telah sampai tujuan";
    }
}

 // Isi Menu kota Berserta bobotnya
int cari(string x, string arr[31])
{
    int i = 0;
    while (i <31)
    {
        if (arr[i] == x) {
            break;
        }
        i++;
    }
    
    return i;
}
 
int main() {
    string tabel__Kota[31] = {
        "Kediri",
        "Probolinggo",
        "Malang",
        "Lumajang",
        "Jember",
        "Sidoarjo",
        "Surabaya",
        "Bangkalan",
        "Bojonegoro",
        "Nganjuk",
        "Kertosono",
        "Madiun",
        "Ponorogo",
        "Magetan",
        "Ngawi",
        "Tulungagung",
        "Trenggalek",
        "Blitar",
        "Jombang",
        "Mojokerto",
        "Gresik",
        "Pasuruan",
        "Sampang",
        "Pamekasan",
        "Sitobondo",
        "Bondowoso",
        "Banyuwangi",
        "Sumenep",
        "Lamongan",
        "Tuban",
        "Pacitan"
    };
    
    int bobot[31][31] = 
            {{0, INFI, 119, INFI, INFI, INFI, INFI, INFI, INFI, 37, 80, INFI, INFI, INFI, INFI, 53, 
            INFI, 40, 54, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI},
            {INFI, 0, INFI, 47, 96, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, 46, INFI, INFI, 114, 97, INFI, INFI, INFI, INFI, INFI},
            {119, INFI, 0, 90, INFI, 71, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, 78, INFI, INFI, INFI, 75, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI},
            {INFI, 47, 90, 0, 75, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI},
            {INFI, 96, INFI, 74, 0, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, 34, 103, INFI, INFI, INFI, INFI},
            {INFI, INFI, 71, INFI, INFI, 0, 26, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, 51, INFI, 45, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI},
            {INFI, INFI, INFI, INFI, INFI, 26, 0, 32, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, 64, 63, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI},
            {INFI, INFI, INFI, INFI, INFI, INFI, 32, 0, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, 62, 94, INFI, INFI, INFI, INFI, INFI, INFI, INFI},
            {INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, 0, 43, 68, INFI, INFI, INFI, 63, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, 65, 43, INFI},
            {37, INFI, INFI, INFI, INFI, INFI, INFI, INFI, 43, 0, 23, 55, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI},
            {80, INFI, INFI, INFI, INFI, INFI, INFI, INFI, 68, 23, 0, INFI, INFI, INFI, INFI, INFI, INFI, INFI, 25, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI},
            {INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, 55, INFI, 0, 30, 23, 37, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI},
            {INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, 30, 0, 34, INFI, INFI, 64, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, 69},
            {INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, 23, 34, 0, 32, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI},
            {INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, 63, INFI, INFI, 37, INFI, 32, 0, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI},
            {53, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, 0, 52, 34, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI},
            {INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, 64, INFI, INFI, 52, 0, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, 96},
            {40, INFI, 78, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, 34, INFI, 0, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI},
            {54, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, 25, INFI, INFI, INFI, INFI, INFI, INFI, INFI, 0, 33, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI},
            {INFI, INFI, INFI, INFI, INFI, 51, 64, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, 33, 0, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI},
            {INFI, INFI, INFI, INFI, INFI, INFI, 63, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, 0, INFI, INFI, INFI, INFI, INFI, INFI, INFI, 31, INFI, INFI},
            {INFI, 45, 75, INFI, INFI, 45, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, 0, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI},
            {INFI, INFI, INFI, INFI, INFI, INFI, INFI, 62, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, 0, 46, INFI, INFI, INFI, 102, INFI, INFI, INFI},
            {INFI, INFI, INFI, INFI, INFI, INFI, INFI, 94, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, 46, 0, INFI, INFI, INFI, 67, INFI, INFI, INFI},
            {INFI, 114, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, 0, 35, 78, INFI, INFI, INFI, INFI},
            {INFI, 97, INFI, INFI, 34, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, 35, 0, INFI, INFI, INFI, INFI, INFI},
            {INFI, INFI, INFI, INFI, 103, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, 78, INFI, 0, INFI, INFI, INFI, INFI},
            {INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, 102, 67, INFI, INFI, INFI, 0, INFI, INFI, INFI},
            {INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, 65, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, 31, INFI, INFI, INFI, INFI, INFI, INFI, INFI, 0, 57, INFI},
            {INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, 43, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, 57, 0, INFI},
            {INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, 69, INFI, INFI, INFI, 96, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, INFI, 0}};

    jalur__terpendek(bobot);
    
    int i, j;
    string asal, tujuan;
    cout << "Masukan kota asal:";
    cin >> asal;
    i = cari(asal, tabel__Kota);
    if (i == 31) {
        cout<<"------------------------------------------------------------------------------------------"<<endl;;
        cout<<"\t\tWARNING !!"<<endl;
        cout << "Kota asal tidak ditemukan, Karena Diluar dari Provinsi Jawa Timur!!\n Input Kota Yang benar!!";
        return 1;
    }
    
    cout << "Masukan kota tujuan:";
    cin >> tujuan;
    j = cari(tujuan, tabel__Kota);
    if (j == 31) {
        cout<<"------------------------------------------------------------------------------------------"<<endl;
        cout<<"\t\tWARNING !!"<<endl;
        cout << "Kota tujuan tidak ditemukan Karena Diluar dari Provinsi Jawa Timur!!\n Input Kota Yang benar!!";
        return 1;
    }
    
    mencari__jalur(bobot, i, j, tabel__Kota);
    return 0;
}