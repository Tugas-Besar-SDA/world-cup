#ifndef headerAdi_H
#define headerAdi_H

#include "..\Mahira\headerMahira.h"
#include "..\Rizki\headerRizki.h"
#include "..\boolean.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define Nil NULL
#define InfoGroup(P) (P)->infoGroup
#define InfoTeam(P) (P)->infoTeam
#define nextGroup(P) (P)->nextGroup
#define nextGroupToTeam(P) (P)->nextGroupToTeam
#define Skor(Q) (Q)->skor
#define Gol(Q) (Q)->gol
#define Selisih(Q) (Q)->selisih
#define NextTeam(Q) (Q)->nextTeam
#define First(L) (L).First

typedef char *infotype;
typedef struct tDataGroup *addressGroup;
typedef struct tDataTeam *addressTeam;
typedef struct tDataGroup {
	infotype infoGroup;
	addressGroup nextGroup;
	addressTeam nextGroupToTeam;
}DataGroup;

typedef struct tDataTeam {
	infotype infoTeam;
	int skor;
	int gol;
	int selisih;
	addressTeam nextTeam;
}DataTeam;

typedef struct {
	addressGroup First;
} ListGroup;

typedef struct {
	addressTeam First;
} ListTeam;

void CreateListGroup (ListGroup * L);
/* IS : L sembarang */
/* FS : Terbentuk ListGroup Kosong */

void CreateListTeam (ListTeam * L);
/* IS : L sembarang */
/* FS : Terbentuk ListTeam Kosong */

boolean isEmptyGroup(ListGroup L);
/* IS : L mungkin Nil */
/* FS : Mengembalikan true jika ListGroup masih Nil, */
/*      sedangkan mengembalikan nilai false jika ListGroup sudah menunjuk ke node */

addressGroup AlokasiGroup (infotype X);
/* Mengirimkan addressGroup hasil alokasiGroup sebuah elemen */
/* Jika alokasiGroup berhasil, maka addressGroup != Nil, 	   */
/*	dan misalnya menghasilkan P, maka Info(P) = X, nextGroup(P) = Nil, nextGroupToTeam(P) = Nil */
/* Jika alokasiGroup gagal, mengirimkan Nil */

addressTeam AlokasiTeam (infotype X);
/* Mengirimkan addressTeam hasil AlokasiTeam sebuah elemen */
/* Jika AlokasiTeam berhasil, maka addressTeam != Nil, 	   */
/*	dan misalnya menghasilkan P, maka Info(P) = X, Next(P) = Nil */
/* Jika AlokasiTeam gagal, mengirimkan Nil */

void InsertLastGroup (ListGroup * L, addressGroup P);

void InsertLastTeam (ListTeam * L, addressTeam P);

void InsVLastGroup (ListGroup * L, infotype X);
/* IS : L mungkin Kosong */
/* FS : melakukan alokasiGroup sebuah elemen dan */
/* menambahkan elemen listGroup di akhir (elemen terakhir adalah yang baru) */
/* bernilai X jika alokasiGroup berhasil. Jika alokasiGroup gagal IS = FS */

void InsVLastTeam (ListTeam * L, infotype X);
/* IS : L mungkin Kosong */
/* FS : melakukan AlokasiTeam sebuah elemen dan */
/* menambahkan elemen ListTeam di akhir (elemen terakhir adalah yang baru) */
/* bernilai X jika AlokasiTeam berhasil. Jika AlokasiTeam gagal IS = FS */

void PrintInfo (ListGroup L);
/* IS : L mungkin kosong */
/* FS : Jika List tidak kosong, semua info yang disimpan pada elemen list */
/*	diprint. Jika list kosong, hanya menuliskan "List Kosong" */

void DeAlokasiGroup (addressGroup P);
/* IS : P terdefinisi */
/* FS : P dikembalikan ke sistem */
/* Melakukan dealokasi / pengembalian addressGroup P ke system */

void DeAlokasiTeam (addressTeam P);
/* IS : P terdefinisi */
/* FS : P dikembalikan ke sistem */
/* Melakukan dealokasi / pengembalian addressTeam P ke system */

void DelPGroup (ListGroup * L, infotype X);
/* IS : L sembarang */
/* FS : Jika ada elemen listGroup beraddress P, dengan Info(P) = X */
/* 	Maka P dihapus dari listGroup dan di dealokasi */
/* Jika tidak ada elemen listGroup dengan Info(P) = X, maka listGroup tetap */
/* listGroup mungkin menjadi kosong karena penghapusan */

void DelPTeam (ListTeam * L, infotype X);
/* IS : L sembarang */
/* FS : Jika ada elemen ListTeam beraddressMhs P, dengan Info(P) = X */
/* 	Maka P dihapus dari ListTeam dan di dealokasi */
/* Jika tidak ada elemen ListTeam dengan Info(P) = X, maka ListTeam tetap */
/* ListTeam mungkin menjadi kosong karena penghapusan */


void addGroup(ListGroup *L, addressGroup *HeadGroup);

void addTeam (ListGroup *L, ListTeam *Q, addressGroup *HeadGroup);

void DelGroup(ListGroup *L, addressGroup *HeadGroup);

void DelTeam(ListGroup *L, ListTeam *Q, addressGroup *HeadGroup);

#endif
