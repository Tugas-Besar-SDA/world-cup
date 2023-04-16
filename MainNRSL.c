#include "spnrsll.h"

int main(){
	//kamus data
	addressGroup HeadGroup, Group;
	addressTeam Team;
	ListGroup MyListGroup;
	ListTeam MyListTim;
//	int JumlahGroup = 1;
	int pilihMenu, pilihMenuDelete;
	CreateListGroup(&MyListGroup);
	
	//program
	for(;;){
		system("cls");
		if(!isEmptyGroup(MyListGroup)){
			PrintInfo (MyListGroup);
		}
		printf("Pilih opsi\n1. Tambah grup\n2. Tambah tim\n3. Delete grup\n4. Delete tim\n5. Pertandingan Group \n0. Exit\nMasukkan pilihan Anda: ");
	    	scanf("%d", &pilihMenu);
		switch(pilihMenu) {
	    	case 1:
	    		addGroup(&MyListGroup, &HeadGroup);
	    	break;
	    	case 2:
	    		addTeam(&MyListGroup, &MyListTim, &HeadGroup);
	    	break;
	    	case 3:
	    		DelGroup(&MyListGroup, &HeadGroup);
			break;
			case 4:
			    	DelTeam(&MyListGroup, &MyListTim, &HeadGroup);
			break;
//			case 5:
//			    	Group = First(MyListGroup);
//			    	GroupStage(Group);
//			    	Group = nextGroup(Group);
//			    	system("pause");
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
	Team = First(MyListTim);
	DeAlokasiTeam (Team);
	return 0;
}
