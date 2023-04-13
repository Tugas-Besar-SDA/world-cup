#ifndef spnrsll_H
#define spnrsll_H
#include "boolean.h"
#include <stdio.h>
#define Nil NULL
#define Info(P) (P)->info
#define NextGroup(P) (P)->nextgrup
#define NextTim(P) (P)->nexttim
//#define Info(Q) (Q)->info
#define Skor(Q) (Q)->skor
#define Gol(Q) (Q)->gol
#define Selisih(Q) (Q)->selisih
#define Next(Q) (Q)->next
#define First(L) (L).First
//#define Pertama(L) (L).Pertama

typedef char *infotype;
typedef struct tElmtList *address;
typedef struct tdatatim *addressTim;
typedef struct tElmtList {
	infotype info;
	address nextgrup;
	addressTim nexttim;
}ElmtList;

typedef struct tdatatim {
	infotype info;
	int skor;
	int gol;
	int selisih;
	addressTim next;
}dataTim;

typedef struct {
	address First;
} ListGroup;

typedef struct {
	addressTim First;
} ListTim;

void CreateListGroup (ListGroup * L);
/* IS : L sembarang */
/* FS : Terbentuk ListGroup Kosong */

void CreateListTim (ListTim * L);
/* IS : L sembarang */
/* FS : Terbentuk ListTim Kosong */

address AlokasiGroup (infotype X);
/* Mengirimkan addressGroup hasil alokasiGroup sebuah elemen */
/* Jika alokasiGroup berhasil, maka addressGroup != Nil, 	   */
/*	dan misalnya menghasilkan P, maka Info(P) = X, NextGroup(P) = Nil, NextTim(P) = Nil */
/* Jika alokasiGroup gagal, mengirimkan Nil */

addressTim AlokasiTim (infotype X);
/* Mengirimkan addressTim hasil alokasiTim sebuah elemen */
/* Jika alokasiTim berhasil, maka addressTim != Nil, 	   */
/*	dan misalnya menghasilkan P, maka Info(P) = X, Next(P) = Nil */
/* Jika alokasiTim gagal, mengirimkan Nil */

void InsertFirstGroup (ListGroup * L, address P);
/* IS : L sembarang, P sudah dialokasi */
/* FS : menambahkan elemen ber-addressGroup P sebagai elemen pertama */

void InsertFirstTim (ListTim * L, addressTim P);
/* IS : L sembarang, P sudah dialokasi */
/* FS : menambahkan elemen ber-addressGroup P sebagai elemen pertama */

void InsVLastGroup (ListGroup * L, infotype X);
/* IS : L mungkin Kosong */
/* FS : melakukan alokasiGroup sebuah elemen dan */
/* menambahkan elemen listGroup di akhir (elemen terakhir adalah yang baru) */
/* bernilai X jika alokasiGroup berhasil. Jika alokasiGroup gagal IS = FS */

void InsVLastTim (ListTim * L, infotype X);
/* IS : L mungkin Kosong */
/* FS : melakukan alokasiTim sebuah elemen dan */
/* menambahkan elemen listTim di akhir (elemen terakhir adalah yang baru) */
/* bernilai X jika alokasiTim berhasil. Jika alokasiTim gagal IS = FS */

void PrintInfo (ListGroup L);
/* IS : L mungkin kosong */
/* FS : Jika List tidak kosong, semua info yang disimpan pada elemen list */
/*	diprint. Jika list kosong, hanya menuliskan "List Kosong" */

void DeAlokasiGroup (address P);
/* IS : P terdefinisi */
/* FS : P dikembalikan ke sistem */
/* Melakukan dealokasi / pengembalian addressGroup P ke system */

void DeAlokasiTim (addressTim P);
/* IS : P terdefinisi */
/* FS : P dikembalikan ke sistem */
/* Melakukan dealokasi / pengembalian addressTim P ke system */

void DelPGroup (ListGroup * L, infotype X);
/* IS : L sembarang */
/* FS : Jika ada elemen listGroup beraddress P, dengan Info(P) = X */
/* 	Maka P dihapus dari listGroup dan di dealokasi */
/* Jika tidak ada elemen listGroup dengan Info(P) = X, maka listGroup tetap */
/* listGroup mungkin menjadi kosong karena penghapusan */

void DelPTim (ListTim * L, infotype X);
/* IS : L sembarang */
/* FS : Jika ada elemen listTim beraddressMhs P, dengan Info(P) = X */
/* 	Maka P dihapus dari listTim dan di dealokasi */
/* Jika tidak ada elemen listTim dengan Info(P) = X, maka listTim tetap */
/* listTim mungkin menjadi kosong karena penghapusan */

#endif
