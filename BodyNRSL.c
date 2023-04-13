#include <stdio.h>
#include <stdlib.h>
//#include <cstring>
#include "spnrsll.h"

//program

void CreateListGroup (ListGroup * L)
/* IS : L sembarang */
/* FS : Terbentuk ListGroup Kosong */
{
	First(*L) = Nil;
}

void CreateListTim (ListTim * L)
/* IS : L sembarang */
/* FS : Terbentuk ListTim Kosong */
{
	First(*L) = Nil;
}

address AlokasiGroup (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address != Nil, 	   */
/*	dan misalnya menghasilkan P, maka Info(P) = X, NextGroup(P) = Nil, NextTim(P) = Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
	/* Kamus Lokal */
	address P;
	/* Algoritma */
	P = (address) malloc (sizeof (ElmtList));
	if (P != Nil)		/* Alokasi berhasil */
	{
		Info(P) = X;
		NextGroup(P) = Nil;
		NextTim(P) = Nil;
	}
	return (P);
}

addressTim AlokasiTim (infotype X)
/* Mengirimkan addressTim hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressTim != Nil, 	   */
/*	dan misalnya menghasilkan P, maka Info(P) = X, Next(P) = Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
	/* Kamus Lokal */
	addressTim P;
	/* Algoritma */
	P = (addressTim) malloc (sizeof (dataTim));
	if (P != Nil)		/* Alokasi berhasil */
	{
		Info(P) = X;
		Gol(P) = 0;
		Selisih(P) = 0;
		Skor(P) = 0;
		Next(P) = Nil;
	}
	return (P);
}

void InsertLastGroup (ListGroup * L, address P)
/* IS : L sembarang, P sudah dialokasi */
/* FS : P ditambahkan sebagai elemen terakhir yang baru */
{
	 /* Kamus Lokal */
	address Last;
	 /* Algoritma */
	if (First(*L) != Nil){
		Last = First(*L);
		while (NextGroup(Last) != Nil){
			Last = NextGroup(Last); 
		}
		NextGroup(Last) = P;
	}
	else{
		First(*L) = P;
	}
}

void InsertLastTim (ListTim * L, addressTim P)
/* IS : L sembarang, P sudah dialokasi */
/* FS : P ditambahkan sebagai elemen terakhir yang baru */
{
	 /* Kamus Lokal */
	addressTim Last;
	 /* Algoritma */
	if (First(*L) != Nil){
		Last = First(*L);
		while (Next(Last) != Nil){
			Last = Next(Last); 
		}
		Next(Last) = P;
	}
	else{
		First(*L) = P;
	}
}

void InsVLastGroup (ListGroup * L, infotype X)
/* IS : L mungkin Kosong */
/* FS : melakukan alokasi sebuah elemen dan */
/* menambahkan elemen ListGroup di akhir (elemen terakhir adalah yang baru) */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal IS = FS */
{
	 /* Kamus Lokal */
	address P;
	 /* Algoritma */
	P = AlokasiGroup (X);
	if (P != Nil){
		InsertLastGroup (&(*L), P);
	}
}

void InsVLastTim (ListTim * L, infotype X)
/* IS : L mungkin Kosong */
/* FS : melakukan alokasi sebuah elemen dan */
/* menambahkan elemen ListTim di akhir (elemen terakhir adalah yang baru) */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal IS = FS */
{
	 /* Kamus Lokal */
	addressTim P;
	 /* Algoritma */
	P = AlokasiTim (X);
	if (P != Nil){
		InsertLastTim (&(*L), P);
	}
}

void PrintInfo (ListGroup L)
/* IS : L mungkin kosong */
/* FS : Jika ListGroup tidak kosong, semua info yang disimpan pada elemen ListGroup */
/*	diprint. Jika ListGroup kosong, hanya menuliskan "ListGroup Kosong" */
{
	 /* Kamus Lokal */
	address P;
	addressTim Q;
	int i = 0;
	 /* Algoritma */
	if (First(L) == Nil){
		printf ("ListGroup Kosong .... \a\n");
	}
	else {	/* ListGroup memiliki elemen */
		P = First(L);
		for (;;){
			if (P == Nil){
				printf("\n");
				break;
			}
			else {	/* Belum berada di akhir ListGroup */
				printf ("%d. %s",++i, Info(P));
				Q = NextTim(P);
				for (;;){
					if (Q == Nil){
						printf("\n");
						break;
					}
					else {
						printf (" %s", Info(Q));
						printf (" Gol : %d", Gol(Q));
						printf (" Skor : %d", Skor(Q));
						printf (" Selisih : %d", Selisih(Q));
						Q = Next(Q);
					}	
				}
				P = NextGroup(P);
			}
		}
	}
}

void DeAlokasiGroup (address P)
/* IS : P terdefinisi */
/* FS : P dikembalikan ke sistem */
/* Melakukan dealokasi / pengembalian address P ke system */
{
	if (P != Nil){
		free (P);
	}
}

void DeAlokasiTim (addressTim P)
/* IS : P terdefinisi */
/* FS : P dikembalikan ke sistem */
/* Melakukan dealokasi / pengembalian addressTim P ke system */
{
	if (P != Nil){
		free (P);
	}
}

void DelPGroup (ListGroup * L, infotype X)
/* IS : L sembarang */
/* FS : Jika ada elemen list beraddress P, dengan Info(P) = X */
/* 	Maka P dihapus dari list dan di dealokasi */
/* Jika tidak ada elemen list dengan Info(P) = X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
	/* Kamus Lokal */
	address P, Prec;
	boolean found = false;
	/* Algoritma */
	Prec = Nil;
	P = First(*L);
	while ((P != Nil) && (!found)){
		if (strcmp(Info(P), X) == 0){
			found = true;
		}		
		else {
			Prec = P;
			P = NextGroup(P);
		}
	} /* P = Nil Atau Ketemu */

	if (found){
		if (Prec == Nil && NextGroup(P) == Nil){	/* Hanya 1 elemen */
			First(*L) = Nil;	
		}
		else if (Prec == Nil){	/* Ketemu di elemen 1*/
			First(*L) = NextGroup(P);
		}
		else {	/* Ketemu di elemen list yang ditengah/akhir */
			NextGroup(Prec) = NextGroup(P);
		}
		NextGroup(P) = Nil;
		DeAlokasiGroup (P);
	}
}

void DelPTim (ListTim * L, infotype X)
/* IS : L sembarang */
/* FS : Jika ada elemen list beraddress P, dengan Info(P) = X */
/* 	Maka P dihapus dari list dan di dealokasi */
/* Jika tidak ada elemen list dengan Info(P) = X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
	/* Kamus Lokal */
	addressTim P, Prec;
	boolean found = false;
	/* Algoritma */
	Prec = Nil;
	P = First(*L);
	while ((P != Nil) && (!found)){
		if (strcmp(Info(P), X) == 0){
			found = true;
		}		
		else {
			Prec = P;
			P = Next(P);
		}
	} /* P = Nil Atau Ketemu */

	if (found){
		if (Prec == Nil && Next(P) == Nil){	/* Hanya 1 elemen */
			First(*L) = Nil;	
		}
		else if (Prec == Nil){	/* Ketemu di elemen 1*/
			First(*L) = Next(P);
		}
		else {	/* Ketemu di elemen list yang ditengah/akhir */
			Next(Prec) = Next(P);
		}
		Next(P) = Nil;
		DeAlokasiTim (P);
	}
}
