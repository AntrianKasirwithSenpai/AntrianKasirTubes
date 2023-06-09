/*
Kelompok : 3A
Anggota :
        * Hasna Fitriyani Khairunissa  221524011
        * Muhammad Azharuddin Hamid  221524018
*/

#ifndef header_h
#define header_h
#define Nil NULL
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>
#include <windows.h>
#define MAX_BARANG 10

typedef const char * infochar;
typedef struct Pembeli *address_P;
typedef struct List_BarangBelian *address_BB;
typedef struct Antrian *address_A;

typedef struct Pembeli
{
    infochar namaPembeli;
    address_BB barangBelian;
    int uangPembeli;
    int hargaTotal;
    int noKasir;
    address_P next;
} Pembeli;

typedef struct DataBarang
{
    infochar nama;
    int stok;
    int harga;
} DataBarang;

typedef struct List_BarangBelian
{
    infochar namaBarang;
    int jumlahBarang;
    address_BB next;
} List_BarangBelian;

typedef struct Antrian
{
    address_P Pembeli;
    address_A next;
} Antrian;

typedef struct Kasir
{
    int Nomor;
    address_A next;
    infochar namaKasir;
} DataKasir;

void createNodePembeli(address_P *headPembeli, address_P *newPembeli, infochar namaPembeli, int noKasir);
void alokasiNodePembeli(address_P *tempPembeli);
void datangPembeli(address_P *headPembeli, DataBarang (*dataBarang)[MAX_BARANG], DataKasir (*kasir)[3]);
void beliBarang(DataBarang (*dataBarang)[MAX_BARANG], address_P *newPembeli);
void persediaanBarang(DataBarang (*dataBarang)[MAX_BARANG]);
void alokasiNodeBarangBelian(address_BB *tempBarangBelian);
void createNodeBarangBelian(address_BB *headBarangBelian, infochar namaBarang, int jumlahBarang);
void delAwalBarangBelian(address_BB *barangBelian);
void alokasiAntrian(address_A *tempAntrian);
void masukAntrian(DataKasir *kasir, address_P Pembeli);
void initKasir(DataKasir (*kasir)[3]);
void prosesAntrian(DataKasir (*kasir)[3]);
int searchBarang(DataBarang dataBarang[MAX_BARANG], infochar namaBarang);

// Tampilan
void banner();
void displayMenu();
void displayListBarang(DataBarang dataBarang[MAX_BARANG], int flagListBarang);
void tampilListAntrian(DataKasir kasir[3], int flagAntrian);
void kotakPersediaanBarang(int flagKotak);

// Teknis
void koor(int x, int y);
void setColor(unsigned short color);

#endif