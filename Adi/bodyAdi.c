//#include "headerAdi.h"
#include "..\Mahira\headerMahira.h"

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
/* IS : L mungkin Nil */
/* FS : mengembalikan nilai true jika grup belum terbentuk. Selain itu, mengembalikan nilai false*/
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
		NextTeam(P) = Nil;
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
		while (NextTeam(Last) != Nil){
			Last = NextTeam(Last); 
		}
		NextTeam(Last) = P;
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
				printf ("%s\n  ", InfoGroup(P));
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
						Q = NextTeam(Q);
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
			P = NextTeam(P);	
		}
	} /* P = Nil Atau Ketemu */

	if (found){
		if (Prec == Nil && NextTeam(P) == Nil){	/* Hanya 1 elemen */
			First(*L) = Nil;	
		}
		else if (Prec == Nil){	/* Ketemu di elemen 1*/
			First(*L) = NextTeam(P);
		}
		else {	/* Ketemu di elemen list yang ditengah/akhir */
			NextTeam(Prec) = NextTeam(P);
		}
		NextTeam(P) = Nil;
		DeAlokasiTeam (P);
	}
}


void addGroup(ListGroup * L, addressGroup * HeadGroup){
	infotype groupName;
	groupName = (char*) malloc (20 * sizeof (char));
	printf("Silahkan masukan nama grup : ");
	scanf("%s",groupName);
	//validasi jika nama groupName sudah tersedia, jika belum akan di tambahkan ke MyListGroup
	for(;;){
		if(isEmptyGroup(*L)){
			InsVLastGroup(&(*L), groupName);
			//JumlahGroup++;
			break;
		}else if (strcmp(groupName, InfoGroup(*HeadGroup)) == 0){
			printf("Nama grup %s sudah tersedia \n", groupName);
			system("pause");
			break;
		}
		else {
			if (nextGroup(*HeadGroup) == Nil){
				InsVLastGroup(&(*L), groupName);
				//JumlahGroup++;
				printf("Nama grup %s sudah tersedia \n", groupName);
				break;
			}
			*HeadGroup = nextGroup(*HeadGroup);
		}
	}
	*HeadGroup = First(*L);
}

void addTeam (ListGroup * L, ListTeam * Q, addressGroup * HeadGroup){
	infotype groupName, teamName;
	if(isEmptyGroup(*L)){
		printf("\nList kosong!\n\n");
		system("pause");
	}else{
		groupName = (char*) malloc (20 * sizeof (char));
		printf("Silahkan pilih nama grup : ");
		scanf("%s", groupName);
		//validasi apakah nama groupName sudah tersedia atau tidak
		for(;;){
			//jika groupName ada maka akan disuruh input teamName Kemudian di simpan di MyListTim 
			if (strcmp(groupName, InfoGroup(*HeadGroup)) == 0){
				teamName = (char*) malloc (20 * sizeof (char));
				printf("Silahkan masukan nama tim : ");
				scanf("%s", teamName);
				//jika MyListGroup belum tersambung sama sekali
				if (nextGroupToTeam(*HeadGroup) == Nil){
					CreateListTeam(&(*Q));
					InsVLastTeam(&(*Q), teamName);
					nextGroupToTeam(*HeadGroup) = First(*Q); //menyambungkan MyListGroup dengan MylistMhs
					break;
				}
				//jika MyListGroup sudah tersambung (melanjutkan MyListTim)
				else {
					First(*Q) = nextGroupToTeam(*HeadGroup); //agar MyListTim nya sesuai diinput di groupName yang di inginkan
					InsVLastTeam(&(*Q),teamName);
					break;
				}
			}
			else {
				if (nextGroup(*HeadGroup) == Nil){ //jika next groupName == Nil (tidak ketemu)
					printf("Nama grup %s tidak tersedia\n", groupName);
					system("pause");
					break;
				}
				//looping next groupName
				*HeadGroup = nextGroup(*HeadGroup);
			}
		}
	}
	//mengubah HeadGroup menjadi menujuk lagi ke list groupName yang pertama
	*HeadGroup = First(*L);	
}


void DelGroup(ListGroup * L, addressGroup * HeadGroup){
	infotype groupName;
	if(isEmptyGroup(*L)){
		printf("\nList kosong!\n\n");
		system("pause");
	}else{
		groupName = (char*) malloc (20 * sizeof (char));
		printf("\nSilahkan ketikan nama grup yang akan di delete : ");
		scanf("%s", groupName);
		//validasi jika yang di hapus list pertama
		if (strcmp(InfoGroup(*HeadGroup), groupName) == 0){
			*HeadGroup = nextGroup(*HeadGroup); //HeadGroup di isi list groupName yang kedua
			First(*L) = *HeadGroup; //HeadGroup (groupName ke 2) dijadikan first
		}
		DelPGroup(&(*L),groupName); //dealloc
//		JumlahGroup--;
	}
}

void DelTeam(ListGroup * L, ListTeam * Q, addressGroup * HeadGroup){
	infotype groupName, teamName;
	if(isEmptyGroup(*L)){
		printf("\nList kosong!\n\n");
		system("pause");
	}else{
		groupName = (char*) malloc (20 * sizeof (char));
		printf("Silahkan pilih nama grup : ");
		scanf("%s", groupName);
		//validasi apakah nama groupName sudah tersedia atau tidak
		for(;;){
			//jika groupName ada maka akan disuruh input teamName
			if (strcmp(InfoGroup(*HeadGroup), groupName) == 0){
				//cek apakah terdapat list team atau tidak
				if (nextGroupToTeam(*HeadGroup) == Nil){
					printf("\nList kosong!\n\n");
					system("pause");
					break;
				}
				teamName = (char*) malloc (20 * sizeof (char));
				printf("\nSilahkan ketikan nama tim yang akan di delete : ");
				scanf("%s",teamName);
				First(*Q) = nextGroupToTeam(*HeadGroup); //agar MyListTim nya sesuai diinput di groupName yang di inginkan
				//validasi jika yang di hapus list pertama
        		if(strcmp(InfoTeam(First(*Q)), teamName) == 0){
        			First(*Q) = NextTeam(First(*Q)); //list kedua menjadi first
        			nextGroupToTeam(*HeadGroup) = First(*Q); //di kaitkan First yang baru ke list groupName
        			break;
				}
				DelPTeam(&(*Q),teamName); //dealloc
				break;
			}else{
				if (nextGroup(*HeadGroup) == Nil){ //jika next groupName == Nil (tidak ketemu)
					printf("Nama grup %s tidak tersedia\n",groupName);
					system("pause");
					break;
				}
				//looping next groupName
				*HeadGroup = nextGroup(*HeadGroup);
			}
		}
		//mengubah HeadGroup menjadi menujuk lagi ke list groupName yang pertama
		*HeadGroup = First(*L);
	}
}
