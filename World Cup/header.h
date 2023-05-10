#ifndef header_h
#define header_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

#define Nil NULL
#define boolean bool
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

typedef char* infotype;
typedef struct tNode *addressNode;
typedef struct tNode {
    addressNode left;
    int alamat, gol, golPenalty;
    infotype value;
    addressNode right;
}Node;

typedef struct tReferee{
	addressNode leftTeam;
	addressNode rightTeam;
}Referee;

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
/*	dan misalnya menghasilkan P, maka InfoGroup(P) = X, nextGroup(P) = Nil, nextGroupToTeam(P) = Nil */
/* Jika alokasiGroup gagal, mengirimkan Nil */

addressTeam AlokasiTeam (infotype X);
/* Mengirimkan addressTeam hasil AlokasiTeam sebuah elemen */
/* Jika AlokasiTeam berhasil, maka addressTeam != Nil, 	   */
/*	dan misalnya menghasilkan P, maka InfoTeam(P) = X, NextTeam(P) = Nil, Gol(P) = 0, Skor(P) = 0, Selisih(P) = 0 */
/* Jika AlokasiTeam gagal, mengirimkan Nil */

void InsertLastGroup (ListGroup * L, addressGroup P);
/* IS : L sembarang, P sudah dialokasi */
/* FS : P ditambahkan sebagai elemen terakhir yang baru */

void InsertLastTeam (ListTeam * L, addressTeam P);
/* IS : L sembarang, P sudah dialokasi */
/* FS : P ditambahkan sebagai elemen terakhir yang baru */

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
/*	diprint. Jika list kosong, hanya menuliskan "List Kosong.." */

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
/* FS : Jika ada elemen ListGroup beraddress P, dengan InfoGroup(P) = X */
/* 	Maka P dihapus dari ListGroup dan di dealokasi */
/* Jika tidak ada elemen ListGroup dengan InfoGroup(P) = X, maka ListGroup tetap */
/* listGroup mungkin menjadi kosong karena penghapusan */

void DelPTeam (ListTeam * L, infotype X);
/* IS : L sembarang */
/* FS : Jika ada elemen ListTeam beraddress P, dengan InfoTeam(P) = X */
/* 	Maka P dihapus dari ListTeam dan di dealokasi */
/* Jika tidak ada elemen ListTeam dengan InfoTeam(P) = X, maka ListTeam tetap */
/* ListTeam mungkin menjadi kosong karena penghapusan */

void MenuAddGroup(ListGroup * L);
/* IS : L Sembarang*/
/* FS : Menambah group pada ListGroup, yang di inputkan langsung oleh user */

void MenuAddTeam(ListGroup * L);
/* IS : L Sembarang*/
/* FS : Menambah team di sebuah group yang akan dipilih user dari ListGroup yang tersedia*/
/* group dan team akan di inputkan langsung oleh user*/

void MenuDelGroup(ListGroup * L);
/* IS : L Sembarang*/
/* FS : Menghapus group pada ListGroup, yang di inputkan langsung oleh user group mana yang akan di hapus */

void MenuDelTeam(ListGroup * L);
/* IS : L Sembarang*/
/* FS : Menghapus team di sebuah group yang akan dipilih user dari ListGroup yang tersedia */
/* group dan team akan di inputkan langsung oleh user */

void ReadTeam(ListGroup * L);
/* IS : L Sembarang*/
/* FS : Menyimpan nama-nama group yang di baca dari file "DaftarTeam.txt" dan akan di simpan di listGroup */
/* dan juga menyimpan nama-nama team ke listTeam, kemudian list team akan di sambungkan dengan listGroup. */
/* Setiap group mempunyai listTeamnya masing-masing */

void AboutTeam();
/* IS : - */
/* FS : Menampilkan output mengenai tentang info kode alpha-3 zero yang digunakan setiap negara yang mengikuti world cup */

//mahira
void Match(addressTeam *M, addressTeam *N);
void PointCalculation(addressTeam *V, addressTeam *M);
void MatchInGroup(addressTeam *B, addressTeam *C);
void MatchButton(ListGroup A, addressGroup *B, addressTeam *C, addressTeam *D);
void GroupWinner(addressGroup A, addressTeam *M, addressTeam *N);
int CountTeam(addressGroup *A);
void WinnerList(addressTeam P, addressTeam Q);
void OpenListOfWinner();
void GroupStage(ListGroup MyListGroup);

/* Rizki Gunawan */
/* ================================================*/
/* ---------------- Modul Pemroses ----------------*/
/* ================================================*/
void prosesBabakGugur();

/* ================================================*/
/* ---------------- Pembuatan Tree ----------------*/
/* ================================================*/
addressNode create_node(int number);

addressNode buildTree(int arr[], int start, int end);

int treeHeight(int n);

int calculateLevelTree(addressNode root);

/* ================================================*/
/* ----------------- Operasi File -----------------*/
/* ================================================*/
void formatFileBefore();

void formatFileAfter();

void sortTeamFromGroup();

int countingTeams();

void inputTim(addressNode root, int maxNode);

/* =======================================================*/
/* ----------------- Proses Pertandingan -----------------*/
/* =======================================================*/
void babakGugur(addressNode root, int maxNode);

void babakPenalty(addressNode root, Referee pointerPertandingan);

void upgradeLeftTeam(Referee pointerPertandingan, addressNode nodeSearch);

void upgradeRightTeam(Referee pointerPertandingan, addressNode nodeSearch);

/* =================================================*/
/* ----------------- Modul Support -----------------*/
/* =================================================*/
void loadingScreen();

addressNode searchNode(addressNode root, int key);

int randomGol();

int randomPenalty();

#endif
