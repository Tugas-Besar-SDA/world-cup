#include "spnrsll.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <cstring>

int main(){
	//kamus data
	address Head, P;
	addressTim Q;
	infotype Group, Tim;
	ListGroup MyListGroup;
	ListTim MyListTim;
	int JmlGroup = 1;
	int pilihMenu,pilihMenuDel;
	
	//program
	Group = (char*) malloc (20 * sizeof (char));
	printf("Silahkan masukan nama Group ke-%d: ",JmlGroup);
	scanf("%s",Group);
	CreateListGroup(&MyListGroup);
	InsVLastGroup(&MyListGroup,Group);
	Head = First(MyListGroup);
	JmlGroup++;
	for(;;){
		system("cls");
		PrintInfo (MyListGroup);
//		printf("%d", Gol(First(MyListGroup));
		printf("\nPilih opsi\n1. Tambah Group\n2. Tambah Tim\n3. Delete\n4. Exit\nMasukkan pilihan Anda: ");
	    scanf("%d", &pilihMenu);
	    switch(pilihMenu) {
	    	case 1:
	    		Group = (char*) malloc (20 * sizeof (char));
				printf("Silahkan masukan nama Group ke-%d: ",JmlGroup);
				scanf("%s",Group);
				//validasi jika nama Group sudah tersedia, jika belum akan di tambahkan ke MyListGroup
				for(;;){
					if (strcmp(Group, Info(Head)) == 0){
						printf("Nama Group %s sudah tersedia \n",Group);
						system("pause");
						break;
					}
					else {
						if (NextGroup(Head) == Nil){
							InsVLastGroup(&MyListGroup,Group);
							JmlGroup++;
							break;
						}
						Head = NextGroup(Head);
					}
				}
				Head = First(MyListGroup);
				break;
	    	break;
	    	case 2:
				Group = (char*) malloc (20 * sizeof (char));
				printf("Silahkan pilih nama Group : ");
				scanf("%s",Group);
				//validasi apakah nama Group sudah tersedia atau tidak
				for(;;){
					//jika Group ada maka akan disuruh input Tim Kemudian di simpan di MyListTim
					if (strcmp(Group, Info(Head)) == 0){
						Tim = (char*) malloc (20 * sizeof (char));
						printf("Silahkan masukan nama Tim : ");
						scanf("%s",Tim);
						//jika MyListGroup belum tersambung sama sekali
						if (NextTim(Head) == Nil){
							CreateListTim(&MyListTim);
							InsVLastTim(&MyListTim,Tim);
							NextTim(Head) = First(MyListTim); //menyambungkan MyListGroup dengan MylistMhs
							break;
						}
						//jika MyListGroup sudah tersambung (melanjutkan MyListTim)
						else {
							First(MyListTim) = NextTim(Head); //agar MyListTim nya sesuai diinput di Group yang di inginkan
							InsVLastTim(&MyListTim,Tim);
							break;
						}
					}
					else {
						if (NextGroup(Head) == Nil){ //jika next Group == Nil (tidak ketemu)
							printf("Nama Group %s tidak tersedia\n",Group);
							system("pause");
							break;
						}
						//looping next Group
						Head = NextGroup(Head);
					}
				}
				//mengubah head menjadi menujuk lagi ke list Group yang pertama
				Head = First(MyListGroup);	
	    	break;
	    	case 3:
	    		system("cls");
	    		PrintInfo (MyListGroup);
	    		printf("Opsi delete\n1. Group\n2. Tim\nSilahkan pilih opsi delete berdasarkan angka: ");
	    		scanf("%d",&pilihMenuDel);
	    		switch(pilihMenuDel){
	    			case 1:
	    				Group = (char*) malloc (20 * sizeof (char));
	    				printf("\nSilahkan ketikan nama Group yang akan di delete : ");
	            		scanf("%s", Group);
	            		//validasi jika yang di hapus list pertama
	            		if (strcmp(Info(Head), Group) == 0){
	            			Head = NextGroup(Head); //Head di isi list Group yang kedua
	            			First(MyListGroup) = Head; //head (Group ke 2) dijadikan first
						}
	    				DelPGroup(&MyListGroup,Group); //dealloc
	    				JmlGroup--;
	    			break;
	    			case 2:
	    				Group = (char*) malloc (20 * sizeof (char));
						printf("Silahkan pilih nama Group : ");
						scanf("%s",Group);
						//validasi apakah nama Group sudah tersedia atau tidak
	    				for(;;){
	    					//jika Group ada maka akan disuruh input Tim
							if (strcmp(Info(Head), Group) == 0){
								Tim = (char*) malloc (20 * sizeof (char));
								printf("\nSilahkan ketikan nama Tim yang akan di delete : ");
								scanf("%s",Tim);
								First(MyListTim) = NextTim(Head); //agar MyListTim nya sesuai diinput di Group yang di inginkan
								//validasi jika yang di hapus list pertama
			            		if (strcmp(Info(First(MyListTim)), Tim) == 0){
			            			First(MyListTim) = Next(First(MyListTim)); //list kedua menjadi first
			            			NextTim(Head) = First(MyListTim); //di kaitkan First yang baru ke list Group
			            			break;
								}
								DelPTim(&MyListTim,Tim); //dealloc
								break;
							}
							else {
								if (NextGroup(Head) == Nil){ //jika next Group == Nil (tidak ketemu)
									printf("Nama Group %s tidak tersedia\n",Group);
									system("pause");
									break;
								}
								//looping next Group
								Head = NextGroup(Head);
							}
						}
						//mengubah head menjadi menujuk lagi ke list Group yang pertama
						Head = First(MyListGroup);
	    			break;
	    			default:
	    				printf("Kesalahan input! Menu %d tidak tersedia \n",pilihMenuDel);
	    				system("pause");
	    			break;
				}
	    	break;
	    	case 4:
	    		exit(1);
	    	break;
	    	default:
	    		printf("Kesalahan input! Menu %d tidak tersedia \n",pilihMenu);
	    		system("pause");
	    	break;
		}
	}
	
	//finishing
	P = First(MyListGroup);
	DeAlokasiGroup (P);
	Q = First(MyListTim);
	DeAlokasiTim (Q);
	return 0;
}
