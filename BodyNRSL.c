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

void CreateListTeam (ListTeam * L)
/* IS : L sembarang */
/* FS : Terbentuk ListTeam Kosong */
{
	First(*L) = Nil;
}

boolean isEmptyGroup(ListGroup L){
	if(First(L) == Nil){
		return true;
	}
	
	return false;
}

addressGroup AlokasiGroup (infotype X)
/* Mengirimkan addressGroup hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressGroup != Nil, 	   */
/*	dan misalnya menghasilkan P, maka Info(P) = X, nextGroup(P) = Nil, nextGroupToTeam(P) = Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
	/* Kamus Lokal */
	addressGroup P;
	/* Algoritma */
	P = (addressGroup) malloc (sizeof (DataGroup));
	if (P != Nil)		/* Alokasi berhasil */
	{
		InfoGroup(P) = X;
		nextGroup(P) = Nil;
		nextGroupToTeam(P) = Nil;
	}
	return (P);
}

addressTeam AlokasiTeam (infotype X)
/* Mengirimkan addressTeam hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressTeam != Nil, 	   */
/*	dan misalnya menghasilkan P, maka Info(P) = X, Next(P) = Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
	/* Kamus Lokal */
	addressTeam P;
	/* Algoritma */
	P = (addressTeam) malloc (sizeof (DataTeam));
	if (P != Nil)		/* Alokasi berhasil */
	{
		InfoTeam(P) = X;
		Gol(P) = 0;
		Selisih(P) = 0;
		Skor(P) = 0;
		Next(P) = Nil;
	}
	return (P);
}

void InsertLastGroup (ListGroup * L, addressGroup P)
/* IS : L sembarang, P sudah dialokasi */
/* FS : P ditambahkan sebagai elemen terakhir yang baru */
{
	 /* Kamus Lokal */
	addressGroup Last;
	 /* Algoritma */
	if (First(*L) != Nil){
		Last = First(*L);
		while (nextGroup(Last) != Nil){
			Last = nextGroup(Last); 
		}
		nextGroup(Last) = P;
	}
	else{
		First(*L) = P;
	}
}

void InsertLastTeam (ListTeam * L, addressTeam P)
/* IS : L sembarang, P sudah dialokasi */
/* FS : P ditambahkan sebagai elemen terakhir yang baru */
{
	 /* Kamus Lokal */
	addressTeam Last;
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
	addressGroup P;
	 /* Algoritma */
	P = AlokasiGroup (X);
	if (P != Nil){
		InsertLastGroup (&(*L), P);
	}
}

void InsVLastTeam (ListTeam * L, infotype X)
/* IS : L mungkin Kosong */
/* FS : melakukan alokasi sebuah elemen dan */
/* menambahkan elemen ListTeam di akhir (elemen terakhir adalah yang baru) */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal IS = FS */
{
	 /* Kamus Lokal */
	addressTeam P;
	 /* Algoritma */
	P = AlokasiTeam (X);
	if (P != Nil){
		InsertLastTeam (&(*L), P);
	}
}

void PrintInfo (ListGroup L)
/* IS : L mungkin kosong */
/* FS : Jika ListGroup tidak kosong, semua info yang disimpan pada elemen ListGroup */
/*	diprint. Jika ListGroup kosong, hanya menuliskan "ListGroup Kosong" */
{
	 /* Kamus Lokal */
	addressGroup P;
	addressTeam Q;
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
				printf ("%d. %s\n  ",++i, InfoGroup(P));
				Q = nextGroupToTeam(P);
				for (;;){
					if (Q == Nil){
						printf("\n");
						break;
					}
					else {
						printf (" %s", InfoTeam(Q));
						printf (" Gol : %d", Gol(Q));
						printf (" Skor : %d", Skor(Q));
						printf (" Selisih : %d\n  ", Selisih(Q));
						Q = Next(Q);
					}	
				}
				P = nextGroup(P);
			}
		}
	}
}

void DeAlokasiGroup (addressGroup P)
/* IS : P terdefinisi */
/* FS : P dikembalikan ke sistem */
/* Melakukan dealokasi / pengembalian addressGroup P ke system */
{
	if (P != Nil){
		free (P);
	}
}

void DeAlokasiTeam (addressTeam P)
/* IS : P terdefinisi */
/* FS : P dikembalikan ke sistem */
/* Melakukan dealokasi / pengembalian addressTeam P ke system */
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
	addressGroup P, Prec;
	boolean found = false;
	/* Algoritma */
	Prec = Nil;
	P = First(*L);
	while ((P != Nil) && (!found)){
		if (strcmp(InfoGroup(P), X) == 0){
			found = true;
		}		
		else {
			Prec = P;
			P = nextGroup(P);
		}
	} /* P = Nil Atau Ketemu */

	if (found){
		if (Prec == Nil && nextGroup(P) == Nil){	/* Hanya 1 elemen */
			First(*L) = Nil;	
		}
		else if (Prec == Nil){	/* Ketemu di elemen 1*/
			First(*L) = nextGroup(P);
		}
		else {	/* Ketemu di elemen list yang ditengah/akhir */
			nextGroup(Prec) = nextGroup(P);
		}
		nextGroup(P) = Nil;
		DeAlokasiGroup (P);
	}
}

void DelPTeam (ListTeam * L, infotype X)
/* IS : L sembarang */
/* FS : Jika ada elemen list beraddress P, dengan Info(P) = X */
/* 	Maka P dihapus dari list dan di dealokasi */
/* Jika tidak ada elemen list dengan Info(P) = X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
	/* Kamus Lokal */
	addressTeam P, Prec;
	boolean found = false;
	/* Algoritma */
	Prec = Nil;
	P = First(*L);
	while ((P != Nil) && (!found)){
		if (strcmp(InfoTeam(P), X) == 0){
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
		DeAlokasiTeam (P);
	}
}
