//#include "headerAdi.h"
#include "..\Mahira\headerMahira.h"

int main(){
	//kamus data
	addressGroup HeadGroup, Group;
	addressTeam HeadTeam, Team;
	ListGroup MyListGroup;
	ListTeam MyListTeam;
	int pilihMenu;
	
	//program
	CreateListGroup(&MyListGroup);
	ReadTeam(&MyListGroup);
    	for(;;){
		system("cls");
		if(!isEmptyGroup(MyListGroup)){
			PrintInfo (MyListGroup);
		}
		
		printf("Pilih opsi\n1. Tambah grup\n2. Tambah tim\n3. Delete grup\n4. Delete tim\n5. Tentang tim\n0. Exit\nMasukkan pilihan Anda: ");
	    scanf("%d", &pilihMenu);
	    switch(pilihMenu) {
	    	case 1:
	    		MenuAddGroup(&MyListGroup);
			break;
	    	case 2:
	    		MenuAddTeam(&MyListGroup);
	    	break;
	    	case 3:
	    		MenuDelGroup(&MyListGroup);
		    break;
		    case 4:
		    	MenuDelTeam(&MyListGroup);
		    break;
		    case 5:
		    	AboutTeam();
		    break;
	    	case 0:
	    		exit(0);
	    	break;
	    	default:
	    		printf("Kesalahan input! Menu %d tidak tersedia \n", pilihMenu);
	    		system("pause");
	    	break;
		}
	}
	
	//finishing
	Group = First(MyListGroup);
	DeAlokasiGroup (Group);
	Team = First(MyListTeam);
	DeAlokasiTeam (Team);
	return 0;
}
