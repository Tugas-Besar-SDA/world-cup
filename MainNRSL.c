#include "spnrsll.h"

int main(){
	//kamus data
	addressGroup HeadGroup, Group;
	addressTeam Team;
	infotype groupName, teamName;
	ListGroup MyListGroup;
	ListTeam MyListTim;
	int JumlahGroup = 0;
	int pilihMenu, pilihMenuDelete;
	
	//program
	CreateListGroup(&MyListGroup);
	for(;;){
		system("cls");
		if(!isEmptyGroup(MyListGroup)){
			PrintInfo (MyListGroup);
		}
		
		printf("Pilih opsi\n1. Tambah grup\n2. Tambah tim\n3. Delete grup\n4. Delete tim\n0. Exit\nMasukkan pilihan Anda: ");
	    scanf("%d", &pilihMenu);
	    switch(pilihMenu) {
	    	case 1:
	    		groupName = (char*) malloc (20 * sizeof (char));
				printf("Silahkan masukan nama grup ke-%d: ", JumlahGroup);
				scanf("%s",groupName);
				//validasi jika nama groupName sudah tersedia, jika belum akan di tambahkan ke MyListGroup
				for(;;){
					if(isEmptyGroup(MyListGroup)){
						InsVLastGroup(&MyListGroup, groupName);
						JumlahGroup++;
						break;
					}else if (strcmp(groupName, InfoGroup(HeadGroup)) == 0){
						printf("Nama grup %s sudah tersedia \n", groupName);
						system("pause");
						break;
					}
					else {
						if (nextGroup(HeadGroup) == Nil){
							InsVLastGroup(&MyListGroup, groupName);
							JumlahGroup++;
							break;
						}
						HeadGroup = nextGroup(HeadGroup);
					}
				}
				HeadGroup = First(MyListGroup);
				break;
	    	break;
	    	case 2:
	    		if(isEmptyGroup(MyListGroup)){
					printf("\nList kosong!\n\n");
					system("pause");
					break;
				}else{
					groupName = (char*) malloc (20 * sizeof (char));
					printf("Silahkan pilih nama grup : ");
					scanf("%s", groupName);
					//validasi apakah nama groupName sudah tersedia atau tidak
					for(;;){
						//jika groupName ada maka akan disuruh input teamName Kemudian di simpan di MyListTim
						if(isEmptyGroup(MyListGroup)){
							printf("\nList kosong!\n");
							system("pause");
							break;
						}else if (strcmp(groupName, InfoGroup(HeadGroup)) == 0){
							teamName = (char*) malloc (20 * sizeof (char));
							printf("Silahkan masukan nama tim : ");
							scanf("%s", teamName);
							//jika MyListGroup belum tersambung sama sekali
							if (nextGroupToTeam(HeadGroup) == Nil){
								CreateListTeam(&MyListTim);
								InsVLastTeam(&MyListTim, teamName);
								nextGroupToTeam(HeadGroup) = First(MyListTim); //menyambungkan MyListGroup dengan MylistMhs
								break;
							}
							//jika MyListGroup sudah tersambung (melanjutkan MyListTim)
							else {
								First(MyListTim) = nextGroupToTeam(HeadGroup); //agar MyListTim nya sesuai diinput di groupName yang di inginkan
								InsVLastTeam(&MyListTim,teamName);
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
				HeadGroup = First(MyListGroup);	
	    	break;
	    	case 3:
	    		if(isEmptyGroup(MyListGroup)){
					printf("\nList kosong!\n\n");
					system("pause");
					break;
				}else{
    				groupName = (char*) malloc (20 * sizeof (char));
    				printf("\nSilahkan ketikan nama grup yang akan di delete : ");
            		scanf("%s", groupName);
            		//validasi jika yang di hapus list pertama
            		if (strcmp(InfoGroup(HeadGroup), groupName) == 0){
            			HeadGroup = nextGroup(HeadGroup); //HeadGroup di isi list groupName yang kedua
            			First(MyListGroup) = HeadGroup; //HeadGroup (groupName ke 2) dijadikan first
					}
    				DelPGroup(&MyListGroup,groupName); //dealloc
    				JumlahGroup--;
				}
		    	break;
		    case 4:
		    	if(isEmptyGroup(MyListGroup)){
					printf("\nList kosong!\n\n");
					system("pause");
					break;
				}else if(JumlahGroup == 1 && nextGroupToTeam(First(MyListGroup)) == Nil){
					printf("\nList kosong!\n\n");
					system("pause");
					break;
				}else{
	    			groupName = (char*) malloc (20 * sizeof (char));
					printf("Silahkan pilih nama grup : ");
					scanf("%s", groupName);
					//validasi apakah nama groupName sudah tersedia atau tidak
    				for(;;){
    					//jika groupName ada maka akan disuruh input teamName
						if (strcmp(InfoGroup(HeadGroup), groupName) == 0){
							teamName = (char*) malloc (20 * sizeof (char));
							printf("\nSilahkan ketikan nama tim yang akan di delete : ");
							scanf("%s",teamName);
							First(MyListTim) = nextGroupToTeam(HeadGroup); //agar MyListTim nya sesuai diinput di groupName yang di inginkan
							//validasi jika yang di hapus list pertama
		            		if(strcmp(InfoTeam(First(MyListTim)), teamName) == 0){
		            			First(MyListTim) = NextTeam(First(MyListTim)); //list kedua menjadi first
		            			nextGroupToTeam(HeadGroup) = First(MyListTim); //di kaitkan First yang baru ke list groupName
		            			break;
							}
							DelPTeam(&MyListTim,teamName); //dealloc
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
					HeadGroup = First(MyListGroup);
				}
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
