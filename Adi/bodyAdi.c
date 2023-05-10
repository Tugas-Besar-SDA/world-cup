//#include "headerAdi.h"
#include "..\Mahira\headerMahira.h"

void CreateListGroup (ListGroup * L){
	First(*L) = Nil;
}

void CreateListTeam (ListTeam * L){
	First(*L) = Nil;
}

boolean isEmptyGroup(ListGroup L){
	if(First(L) == Nil){
		return true;
	}
	
	return false;
}

addressGroup AlokasiGroup (infotype X){
	//kamus data
	addressGroup P;
	
	//program
	P = (addressGroup) malloc (sizeof (DataGroup));
	if (P != Nil)		//Alokasi berhasil
	{
		InfoGroup(P) = X;
		nextGroup(P) = Nil;
		nextGroupToTeam(P) = Nil;
	}
	return (P);
}

addressTeam AlokasiTeam (infotype X){
	//kamus data
	addressTeam P;
	
	//program
	P = (addressTeam) malloc (sizeof (DataTeam));
	if (P != Nil)		//Alokasi berhasil
	{
		InfoTeam(P) = X;
		Gol(P) = 0;
		Selisih(P) = 0;
		Skor(P) = 0;
		NextTeam(P) = Nil;
	}
	return (P);
}

void InsertLastGroup (ListGroup * L, addressGroup P){
	//kamus data
	addressGroup Last;
	
	//program
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

void InsertLastTeam (ListTeam * L, addressTeam P){
	//kamus data
	addressTeam Last;
	
	//program
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
{
	//kamus data
	addressGroup P;
	
	//program
	P = AlokasiGroup (X);
	if (P != Nil){
		InsertLastGroup (&(*L), P);
	}
}

void InsVLastTeam (ListTeam * L, infotype X){
	//kamus data
	addressTeam P;
	
	//program
	P = AlokasiTeam (X);
	if (P != Nil){
		InsertLastTeam (&(*L), P);
	}
}

void PrintInfo (ListGroup L){
	//kamus data
	addressGroup P;
	addressTeam Q;
	int i = 0;
	
	//program
	if (First(L) == Nil){
		printf ("ListGroup Kosong .... \a\n");
	}
	else {	//ListGroup memiliki elemen
		P = First(L);
		for (;;){
			if (P == Nil){
				printf("\n");
				break;
			}
			else {	//Belum berada di akhir ListGroup
				printf("\t\t-----------\n");
				printf ("\t\t| Group %s |\n", InfoGroup(P));
				printf("\t\t-----------\n");
				Q = nextGroupToTeam(P);
				for (;;){
					if (Q == Nil){
						printf("-----------------------------------------------\n");
						printf("\n");
						break;
					}
					else {
						printf("-----------------------------------------------\n");
						printf ("| Team %s |", InfoTeam(Q));
						printf (" Gol : %d |", Gol(Q));
						printf (" Skor : %d |", Skor(Q));
						printf (" Selisih : %d |\n", Selisih(Q));
						Q = NextTeam(Q);
					}	
				}
				P = nextGroup(P);
			}
		}
	}
}

void DeAlokasiGroup (addressGroup P){
	if (P != Nil){
		free (P);
	}
}

void DeAlokasiTeam (addressTeam P){
	if (P != Nil){
		free (P);
	}
}

void DelPGroup (ListGroup * L, infotype X){
	//kamus data
	addressGroup P, Prec;
	boolean found = false;
	
	//program
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
	} //P = Nil Atau Ketemu

	if (found){
		if (Prec == Nil && nextGroup(P) == Nil){	//Hanya 1 elemen
			First(*L) = Nil;	
		}
		else if (Prec == Nil){	//Ketemu di elemen 1
			First(*L) = nextGroup(P);
		}
		else {	//Ketemu di elemen list yang ditengah/akhir
			nextGroup(Prec) = nextGroup(P);
		}
		nextGroup(P) = Nil;
		DeAlokasiGroup (P);
	}
}

void DelPTeam (ListTeam * L, infotype X){
	//kamus data
	addressTeam P, Prec;
	boolean found = false;
	
	//program
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
	} //P = Nil Atau Ketemu 

	if (found){
		if (Prec == Nil && NextTeam(P) == Nil){	//Hanya 1 elemen
			First(*L) = Nil;	
		}
		else if (Prec == Nil){	//Ketemu di elemen 1
			First(*L) = NextTeam(P);
		}
		else {	//Ketemu di elemen list yang ditengah/akhir
			NextTeam(Prec) = NextTeam(P);
		}
		NextTeam(P) = Nil;
		DeAlokasiTeam (P);
	}
}


void MenuAddGroup(ListGroup * L){
	//kamus data
	infotype groupName;
	groupName = (infotype) malloc (20 * sizeof (char));
	addressGroup HeadGroup = First(*L);
	
	//program
	printf("Silahkan masukan nama grup : ");
	scanf("%s",groupName);
	//validasi jika nama groupName sudah tersedia, jika belum akan di tambahkan ke MyListGroup
	for(;;){
		if(isEmptyGroup(*L)){
			InsVLastGroup(&(*L), groupName);
			break;
		}else if (strcmp(groupName, InfoGroup(HeadGroup)) == 0){
			printf("Nama grup %s sudah tersedia %s \n", groupName, InfoGroup(HeadGroup));
			system("pause");
			break;
		}
		else {
			
			if (nextGroup(HeadGroup) == Nil){
				InsVLastGroup(&(*L), groupName);
				break;
			}
			HeadGroup = nextGroup(HeadGroup);
		}
	}
	HeadGroup = First(*L);
}

void MenuAddTeam (ListGroup * L){
	//kamus data
	infotype groupName, teamName;
	addressGroup HeadGroup = First(*L);
	ListTeam MyListTeam;
	
	//program
	if(isEmptyGroup(*L)){
		printf("\nList kosong!\n\n");
		system("pause");
	}else{
		groupName = (infotype) malloc (20 * sizeof (char));
		printf("Silahkan pilih nama grup : ");
		scanf("%s", groupName);
		//validasi apakah nama groupName sudah tersedia atau tidak
		for(;;){
			//jika groupName ada maka akan disuruh input teamName Kemudian di simpan di MyListTim 
			if (strcmp(groupName, InfoGroup(HeadGroup)) == 0){
				teamName = (infotype) malloc (20 * sizeof (char));
				printf("Silahkan masukan nama tim : ");
				scanf("%s", teamName);                         
				//jika MyListGroup belum tersambung sama sekali
				if (nextGroupToTeam(HeadGroup) == Nil){
					CreateListTeam(&MyListTeam);
					InsVLastTeam(&MyListTeam, teamName);
					nextGroupToTeam(HeadGroup) = First(MyListTeam); //menyambungkan MyListGroup dengan MylistMhs
					break;
				}
				//jika MyListGroup sudah tersambung (melanjutkan MyListTim)
				else {
					First(MyListTeam) = nextGroupToTeam(HeadGroup); //agar MyListTim nya sesuai diinput di groupName yang di inginkan
					InsVLastTeam(&MyListTeam,teamName);
					break;
				}
			}
			else {
				if (nextGroup(HeadGroup) == Nil){ //jika next groupName == Nil (tidak ketemu)
					printf("Nama grup %s tidak tersedia\n", groupName);
					system("pause");
					break;
				}
				//looping next groupName
				HeadGroup = nextGroup(HeadGroup);
			}
		}
	}
	//mengubah HeadGroup menjadi menujuk lagi ke list groupName yang pertama
	HeadGroup = First(*L);	
}


void MenuDelGroup(ListGroup * L){
	//kamus data
	infotype groupName;
	addressGroup HeadGroup = First(*L);
	
	//program
	if(isEmptyGroup(*L)){
		printf("\nList kosong!\n\n");
		system("pause");
	}else{
		groupName = (infotype) malloc (20 * sizeof (char));
		printf("\nSilahkan ketikan nama grup yang akan di delete : ");
		scanf("%s", groupName);
		
		HeadGroup = First(*L); // HeadGroup diinisiasi untuk menunjuk Grup ke-1
		while(strcmp(InfoGroup(HeadGroup), groupName) != 0){
			HeadGroup = nextGroup(HeadGroup);
			if(HeadGroup == Nil){
				break;
			}
		}
		
		if(HeadGroup != Nil){
			if (HeadGroup == First(*L)){ // Grup berada di urutan pertama
				HeadGroup = nextGroup(HeadGroup); //HeadGroup di isi list groupName yang kedua
				First(*L) = HeadGroup; //HeadGroup (groupName ke 2) dijadikan first
			}
			DelPGroup(&(*L),groupName); //dealloc
		}else{
			printf("\nGrup tidak ada\n\n");
			system("pause");
		}
	}
}

void MenuDelTeam(ListGroup * L){
	//kamus data
	infotype groupName, teamName;
	addressGroup HeadGroup = First(*L);
	ListTeam MyListTeam;
	
	//program
	if(isEmptyGroup(*L)){
		printf("\nList kosong!\n\n");
		system("pause");
	}else{
		groupName = (infotype) malloc (20 * sizeof (char));
		printf("Silahkan pilih nama grup : ");
		scanf("%s", groupName);
		//validasi apakah nama groupName sudah tersedia atau tidak
		for(;;){
			//jika groupName ada maka akan disuruh input teamName
			if (strcmp(InfoGroup(HeadGroup), groupName) == 0){
				//cek apakah terdapat list team atau tidak
				if (nextGroupToTeam(HeadGroup) == Nil){
					printf("\nList kosong!\n\n");
					system("pause");
					break;
				}
				teamName = (infotype) malloc (20 * sizeof (char));
				printf("\nSilahkan ketikan nama tim yang akan di delete : ");
				scanf("%s",teamName);
				First(MyListTeam) = nextGroupToTeam(HeadGroup); //agar MyListTim nya sesuai diinput di groupName yang di inginkan
				//validasi jika yang di hapus list pertama
        		if(strcmp(InfoTeam(First(MyListTeam)), teamName) == 0){
        			First(MyListTeam) = NextTeam(First(MyListTeam)); //list kedua menjadi first
        			nextGroupToTeam(HeadGroup) = First(MyListTeam); //di kaitkan First yang baru ke list groupName
        			break;
				}
				DelPTeam(&MyListTeam,teamName); //dealloc
				break;
			}else{
				if (nextGroup(HeadGroup) == Nil){ //jika next groupName == Nil (tidak ketemu)
					printf("Nama grup %s tidak tersedia\n",groupName);
					system("pause");
					break;
				}
				//looping next groupName
				HeadGroup = nextGroup(HeadGroup);
			}
		}
		//mengubah HeadGroup menjadi menujuk lagi ke list groupName yang pertama
		HeadGroup = First(*L);
	}
}

void ReadTeam(ListGroup * L){
	//kamus data
    FILE *file;
    ListTeam MyListTeam;
    addressGroup HeadGroup;
    infotype groupName,teamName1,teamName2,teamName3,teamName4;
    int i,cursor = 0;
    
    //program
    file = fopen("DaftarTeam.txt", "r");
    if (file == NULL) {
        printf("File tidak dapat dibuka.\n");
        exit(EXIT_FAILURE);
    }
    else{
    	HeadGroup = Nil;
		for(i = 0;i < 8;i++){
			groupName = (infotype) malloc(1 * sizeof(char));
			fseek(file, cursor, SEEK_SET);
			fscanf(file, "%s", groupName);
			InsVLastGroup(&(*L), groupName);
			if(HeadGroup == Nil){
				HeadGroup = First(*L);	
			}
			cursor+= 19;
		}
		HeadGroup = First(*L);
		cursor = 0;
		for(i = 0;i < 8;i++){
			teamName1 = (infotype) malloc(3 * sizeof(char));
			teamName2 = (infotype) malloc(3 * sizeof(char));
			teamName3 = (infotype) malloc(3 * sizeof(char));
			teamName4 = (infotype) malloc(3 * sizeof(char));
			fseek(file, cursor, SEEK_SET);
			fseek(file, cursor+2, SEEK_SET);
			fscanf(file, "%s", teamName1);
			fseek(file, cursor+6, SEEK_SET);
			fscanf(file, "%s", teamName2);
			fseek(file, cursor+10, SEEK_SET);
			fscanf(file, "%s", teamName3);
			fseek(file, cursor+14, SEEK_SET);
			fscanf(file, "%s", teamName4);
			CreateListTeam(&MyListTeam);
			InsVLastTeam(&MyListTeam, teamName1);
			nextGroupToTeam(HeadGroup) = First(MyListTeam);
			InsVLastTeam(&MyListTeam, teamName2);
			InsVLastTeam(&MyListTeam, teamName3);
			InsVLastTeam(&MyListTeam, teamName4);
			HeadGroup = nextGroup(HeadGroup);
			cursor += 19;
		}
	}
    fclose(file);
}

void AboutTeam(){
	//kamus data
	FILE *file;
	char buffer[100];
	
	//program
	system("cls");
	file = fopen("AboutTeam.txt", "r");
	if (file == NULL) {
		printf("File tidak dapat dibuka.\n");
	}
	
	while (fgets(buffer, sizeof(buffer), file)) {
		printf("%s", buffer);
	}

	fclose(file);
	printf("\n");
	system("pause");
}
