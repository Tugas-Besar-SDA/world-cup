#include "header.h"

/*=======================================================================================================*/
/* 											Muhammad Adi Saputera 										 */
/*=======================================================================================================*/
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
				printf("\t\t\t\t\t\t\t-----------------------------------------------\n");
				printf ("\t\t\t\t\t\t\t|\t\t    Group %s\t\t      |\n", InfoGroup(P));
				//printf("\t\t-----------\n");
				Q = nextGroupToTeam(P);
				for (;;){
					if (Q == Nil){
						printf("\t\t\t\t\t\t\t-----------------------------------------------\n");
						printf("\n");
						break;
					}
					else {
						printf("\t\t\t\t\t\t\t-----------------------------------------------\n");
						printf ("\t\t\t\t\t\t\t| Team %s |", InfoTeam(Q));
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
	else{
		printf("group %s tidak ada di dalam list\n\n",X);
		system("pause");
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
	else{
		printf("Tim %s tidak ada di dalam grup\n\n",X);
		system("pause");
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
		if (HeadGroup == First(*L)){ // Grup berada di urutan pertama
			HeadGroup = nextGroup(HeadGroup); //HeadGroup di isi list groupName yang kedua
			First(*L) = HeadGroup; //HeadGroup (groupName ke 2) dijadikan first
		}
		DelPGroup(&(*L),groupName); //dealloc
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
}

/*=======================================================================================================*/
/* 											Mahira Nurhaliza 											 */
/*=======================================================================================================*/

void Match(addressTeam *M, addressTeam *N)
{
	Gol(*M) = rand()%10;
	Gol(*N) = rand()%10;
	
	if(Gol(*M) == Gol(*N))
	{
		Skor(*M) = 1;
		Skor(*N) = 1;
	}
	else if(Gol(*M) > Gol(*N))
	{
		Skor(*M) = 3;
		Skor(*N) = 0;
	}
	else if(Gol(*M) < Gol(*N))
	{
		Skor(*M) = 0;
		Skor(*N) = 3;
	}
	Selisih(*M) = Gol(*M) - Gol(*N);
	Selisih(*N) = Gol(*N) - Gol(*M);
}

void PointCalculation(addressTeam *V, addressTeam *M)
{
	Skor(*V) = Skor(*V) + Skor(*M);
	Gol(*V) = Gol(*V) + Gol(*M);
	Selisih(*V) = Selisih(*V) + Selisih(*M);
}

void MatchInGroup(addressTeam *B, addressTeam *C)
{
	addressTeam M, N;
	
	M = (addressTeam) malloc (sizeof (DataTeam));
	N = (addressTeam) malloc (sizeof (DataTeam));
	
	Match(&M, &N);
	PointCalculation(&(*B), &M);
	PointCalculation(&(*C), &N); 
	printf("\t\t\t  Team = %s, Skor = %d, Gol = %d, Selisih = %d\n", InfoTeam(*B), Skor(M), Gol(M), Selisih(M));
	printf("\t\t\t  Team = %s, Skor = %d, Gol = %d, Selisih = %d\n", InfoTeam(*C), Skor(N), Gol(N), Selisih(N));
	printf("\n");
//	system("pause");
}

void MatchButton(ListGroup A, addressGroup *B, addressTeam *C, addressTeam *D)
{
	if(*C == Nil && *D == Nil)
	{
		*B = First(A);
		*C = nextGroupToTeam(*B);
		*D = NextTeam(*C);
	}
	
	do
	{
		if(*C == Nil)
		{	
			*B = nextGroup(*B);
			*C = nextGroupToTeam(*B);
			*D = NextTeam(*C);
		}
		else if(*D == Nil && *C != Nil)
		{
			*C = NextTeam(*C);
			if(NextTeam(*C) == Nil)
			{
				*C = Nil;
				*D = Nil;
			}
			else
			{
				*D = NextTeam(*C);
			}
		}
		else if(*D != Nil) 
		{
			MatchInGroup(&(*C), &(*D));
			*D = NextTeam(*D);
		}
//		printf("D = %s\n", InfoTeam(*D));
	}while(*C == Nil || *D == NextTeam(*C));
}

void GroupWinner(addressGroup A, addressTeam *M, addressTeam *N)
{
	//kamus data lokal
	addressTeam B, C, O;
	int undi;
	
	//inisialisasi
	*M = (addressTeam) malloc (sizeof (DataTeam));
	*N = (addressTeam) malloc (sizeof (DataTeam));
	O = (addressTeam) malloc (sizeof (DataTeam));
	Skor(O) = -1;
	Selisih(O) = -1;
	Gol(O) = -1;
	
	B = nextGroupToTeam(A);
	C = NextTeam(B);
	
	while(C != Nil)
	{
		if(Skor(B) > Skor(C))
		{
			if(Skor(O) < Skor(C))
			{
				O = C;	
			}
			C = NextTeam(C);
		}
		else if(Skor(B) < Skor(C))
		{
			O = B;
			B = C;
			C = NextTeam(C);
		}
		else if(Skor(B) == Skor(C))
		{
			if(Selisih(B) > Selisih(C))
			{
				if(Selisih(O) < Selisih(C))
				{
					O = C;	
				}
				C = NextTeam(C);
			} 
			else if(Selisih(B) < Selisih(C))
			{
				O = B;
				B = C;
				C = NextTeam(C);
			}
			else if(Selisih(B) == Selisih(C))
			{
				if(Gol(B) > Gol(C))
				{
					if(Gol(O) < Gol(C))
					{
						O = C;	
					}
					C = NextTeam(C);
				}
				else if(Gol(B) < Gol(C))
				{
					O = B;
					B = C;
					C = NextTeam(C);
				}
				else if(Gol(B) == Gol(C))
				{
					undi = rand()%1;
					if(undi == 1)
					{
						O = C;
					}
					else if(undi == 0)
					{
						O = B;
						B = C;
					}				
				}
			}
		}
		*M = B;
		*N = O;
	}
}

int CountTeam(addressGroup *A)
{
//	addressGroup B;
	addressTeam C;
	int sum = 0;
	
	C = nextGroupToTeam(*A);
	while(C != Nil)
	{
		sum++;
		C = NextTeam(C);
	}
	return sum;
}

void WinnerList(addressTeam P, addressTeam Q)
{
	FILE *fileP;
	infotype tim, tim1;
	
	//buka dan/atau buat file
	fileP = fopen("pemenangFaseGrup(before).txt", "a");
	
	//jika file tidak dapat dibuka
	if(fileP == NULL)
	{
		printf("\nFile tidak bisa terbuka!\n");
	}
	else
	{
		//alokasi
		tim = (infotype) malloc (3 * sizeof(char));
		
		//menyimpan di file
		tim = InfoTeam(P);
		fprintf(fileP, "%s\n", tim);
		tim = InfoTeam(Q);
		fprintf(fileP, "%s\n", tim);
	}
	fclose(fileP);
}

void OpenListOfWinner()
{
	//kamus data lokal
	FILE *fileP;
	infotype tim;
	int i = 0, j, k;
	char group;
	
	fileP = fopen("pemenangFaseGrup(before).txt","r");
	tim = (infotype) malloc (3 * sizeof(char));
	if(fileP == NULL)
	{
		printf("\n\t\t     File tidak bisa terbuka!\n");
	}
	else
	{
		fileP = fopen("pemenangFaseGrup(before).txt","r");
		while(!feof(fileP))
		{
			fscanf(fileP, "%s\n", tim);
			i++;
		}
		fclose(fileP);
		i = i/2;
		fileP = fopen("pemenangFaseGrup(before).txt","r");
		printf("\n\n");
		for(j = 65; j < 64+i; j++)
		{
			group = (char)j;
			printf("\t\t---------------------------------------------");
			printf("\n\t\t|\t\t   Group %c \t\t    |\n", group);
			printf("\t\t---------------------------------------------\n");
			k = 0;
			while(!feof(fileP) && k < 2)
			{
				fscanf(fileP, "%s\n", tim);
				printf("\t\t|\t\t     %s\t\t    |\n", tim);
				k++;	
			}	
			printf("\t\t---------------------------------------------\n\n");
		}
		fclose(fileP);
	}
	fclose(fileP);
}

void GroupStage(ListGroup MyListGroup)
//pertandingan dalam grup
{
	addressGroup H, I;
	addressTeam B, C;
	int SumOfTeam, SumOfMatch, i;
	
	B = (addressTeam) malloc (sizeof (DataTeam));
	C = (addressTeam) malloc (sizeof (DataTeam));
	B = Nil;
	C = Nil;
	H = First(MyListGroup);
	do
	{
		SumOfTeam = CountTeam(&H);
		printf("Team = %d\n", SumOfTeam);
		SumOfMatch = (SumOfTeam*(SumOfTeam-1))/2;
		printf("Match = %d\n", SumOfMatch);
		
		for(i = 1; i <= SumOfMatch; i++)
		{
			printf("Pertandingan %d Group = %s\n", i, InfoGroup(H));
			MatchButton(MyListGroup, &I, &B, &C);
//			system("pause");
		}
		H = nextGroup(H);
	}while(H != Nil);
}

/*=======================================================================================================*/
/* 											Rizki Gunawan 												 */
/*=======================================================================================================*/

/* =====================================================================*/
/* ------------------------- Modul Pemrosesan --------------------------*/
/* =====================================================================*/
void prosesBabakGugur(){
	loadingScreen();
	/* Inisiasi isi file yang akan terpakai di program untuk dikosongi */
	formatFileAfter();
	
	/* Kamus data */
    int maxNode, i, levelTree; // nanti harus ada modul buat ngitung jumlah tim yang akan bertanding di babak gugur
    
    /* Proses membuat tree yang full balanced */
    int height = treeHeight(countingTeams());
    int maxNodeFullTree = pow(2, height+1) - 1;
    int arr[maxNodeFullTree];

    for (i = 0; i < maxNodeFullTree; i++) {
        if (i < maxNode) {
            arr[i] = i+1;
        } else {
            arr[i] = 0;
        }
    }

    addressNode root = buildTree(arr, 0, maxNodeFullTree-1);
    /* Sorting tim */
    sortTeamFromGroup();
	/* Memasukkan tim ke tree */
	printf("Proses sebelum input tim\n");
	inputTeamToTree(root, countingTeams());
	/* Pertandingan dimulai */
	printf("Proses sebelum sebelum babak gugur\n");
	babakGugur(root, countingTeams());
	
	/* Hasil dari pertandingan */
	system("cls");
	printf("\n\n\n\n\n\t\t\t\t\t\t\t\t==================================================\n");
	printf("        \t\t\t\t\t\t\t|>>>>>>>>>>>>>>>>  CHAMPION: %s <<<<<<<<<<<<<<<<|", root->value);
	printf("\n\t\t\t\t\t\t\t\t==================================================\n\n\n\n");
}

/* =====================================================================*/
/* -------------------------- Pembuatan Tree ---------------------------*/
/* =====================================================================*/
addressNode create_node(int number) {
    addressNode newNode = (addressNode) malloc(sizeof(Node));
    newNode->left = NULL;
    newNode->alamat = number;
    newNode->value = ".";
    newNode->gol = 0;
    newNode->golPenalty = 0;
    newNode->right = NULL;
    return newNode;
}

addressNode buildTree(int arr[], int start, int end) {
    if (start > end)
        return NULL;
    int mid = (start + end) / 2;
    addressNode root = create_node(arr[mid]);
    root->left = buildTree(arr, start, mid - 1);
    root->right = buildTree(arr, mid + 1, end);
    return root;
}

int treeHeight(int n) {
    return (int)(log2(n+1)-1);
}

int calculateLevelTree(addressNode root){
	int level = -1;
	addressNode pointer = root;
	
	while(pointer != NULL){
		pointer = pointer->right;
		level++;
	}
	return level;
}

/* ======================================================================*/
/* ---------------------------- Operasi File ----------------------------*/
/* ======================================================================*/

void formatFileBefore(){
	FILE *file;
	
	file = fopen("pemenangFaseGrup(before).txt", "w");
	if(file == NULL){
		printf("File tidak bisa dibuka\n");
	}
	fclose(file);
}

void formatFileAfter(){
	FILE *file;
	
	file = fopen("pemenangFaseGrup(after).txt", "w");
	if(file == NULL){
		printf("File tidak bisa dibuka\n");
	}
	fclose(file);
}

void sortTeamFromGroup(){
	FILE *file1, *file2;
	int i, j = 0, cursorFile2;
	infotype buffer1, buffer2, buffer3, buffer4;
	file1 = fopen("pemenangFaseGrup(before).txt", "r");
	if(file1 == NULL){
		printf("File tidak bisa dibuka\n");
	}else{
		buffer1 = (infotype) malloc (3 * sizeof(char));
		buffer2 = (infotype) malloc (3 * sizeof(char));
		buffer3 = (infotype) malloc (3 * sizeof(char));
		buffer4 = (infotype) malloc (3 * sizeof(char));
		fseek(file1, 0, SEEK_SET);
		
		for(i = 1, cursorFile2 = 0; i <= 4; i++, cursorFile2 += 20){
			fseek(file1, j, SEEK_SET);
			fscanf(file1, "%s", buffer1);
			j += 15;
			fseek(file1, j, SEEK_SET);
			fscanf(file1, "%s", buffer2);
			fseek(file1, j - 10, SEEK_SET);
			fscanf(file1, "%s", buffer3);
			fseek(file1, j - 5, SEEK_SET);
			fscanf(file1, "%s", buffer4);
			file2 = fopen("pemenangFaseGrup(after).txt", "a");
			if(file2 == NULL){
				printf("File tidak bisa dibuka\n");
			}else{
				fseek(file2, cursorFile2, SEEK_SET);
				fprintf(file2, "%s\n", buffer2);
				fseek(file2, cursorFile2+5, SEEK_SET);
				fprintf(file2, "%s\n", buffer3);
				fseek(file2, cursorFile2+10, SEEK_SET);
				fprintf(file2, "%s\n", buffer4);
				fseek(file2, cursorFile2+15, SEEK_SET);
				fprintf(file2, "%s\n", buffer1);
			}
			fclose(file2);
			j += 5;
		}
	}
	fclose(file1);
}

int countingTeams(){
	int quantity = 0;
	
	FILE *file;
	infotype buffer;
	printf("Masuk counting teams\n");
	file = fopen("pemenangFaseGrup(before).txt", "r");
	if(file == NULL){
		printf("File tidak bisa dibuka\n");
	}else{
		buffer = (infotype) malloc (3 * sizeof(char));
		while (fgets(buffer, 100, file)) {
			quantity++;
    	}
	}
	
	fclose(file);
	return (quantity * 2) - 1;
}

void inputTeamToTree(addressNode root, int maxNode){
    FILE *file;
    infotype buffer;
    int i = 1;
    addressNode Psearch;
    file = fopen("pemenangFaseGrup(after).txt", "r");

    if(file == NULL){
        printf("\nFile tidak bisa terbuka!\n");
    }else{
    	fseek(file, 0, SEEK_SET);
        while(!feof(file)){
    		buffer = (infotype) malloc (3 * sizeof(char));
            fscanf(file, "%s", buffer);
            Psearch = searchNode(root, i);
            Psearch->value = buffer;
            i += 2;
            if(i > maxNode){
                break;
            }
        }
    }
    fclose(file);
}

/* ====================================================================*/
/*------------------------ Proses pertandingan ------------------------*/
/* ====================================================================*/
void babakGugur(addressNode root, int maxNode){
	addressNode nodeSearch;
	int golKiri, golKanan;
	int tLevelTree = calculateLevelTree(root);
	int j, k, l = 1;
	
	for(j = 1; j <= tLevelTree; j++){
		for(k = pow(2, j); k <= maxNode; k += pow(2, (j+1))){
			Referee pointerPertandingan;
			
			if(k == pow(2, tLevelTree)){
				system("cls");
				printf("\n\n\n\t\t\t\t\t\t\t\t\t\t=========================\n");
				printf("     \t\t\t\t\t\t\t\t\t\t|   Pertandingan Final  |");
				printf("\n\t\t\t\t\t\t\t\t\t\t=========================\n");
			}else{
				system("cls");
				printf("\n\n\n\t\t\t\t\t\t\t\t\t\t=========================\n");
				printf("     \t\t\t\t\t\t\t\t\t\t|   Pertandingan ke-%d\t|", l++);
				printf("\n\t\t\t\t\t\t\t\t\t\t=========================\n");
			}
			nodeSearch = searchNode(root, k);
			pointerPertandingan.leftTeam = nodeSearch->left;
			pointerPertandingan.rightTeam = nodeSearch->right;
			printf("\t \t\t\t\t\t\t\t\t\t|\t%s vs %s\t|", pointerPertandingan.leftTeam->value, pointerPertandingan.rightTeam->value);
			printf("\n\t\t\t\t\t\t\t\t\t\t-------------------------\n");
			
			pointerPertandingan.leftTeam->gol = randomGol();
			pointerPertandingan.rightTeam->gol = randomGol();
			
			printf("\t\t\t\t\t\t\t\t\t\t| Gol tim %s: %d\t|\n", pointerPertandingan.leftTeam->value, pointerPertandingan.leftTeam->gol);
			printf("\t\t\t\t\t\t\t\t\t\t| Gol tim %s: %d\t|\n", pointerPertandingan.rightTeam->value, pointerPertandingan.rightTeam->gol);
			printf("\t\t\t\t\t\t\t\t\t\t=========================");
			
			if(pointerPertandingan.leftTeam->gol == pointerPertandingan.rightTeam->gol){
				// masuk ke sesi penalty
				babakPenalty(root, pointerPertandingan);
				if(pointerPertandingan.leftTeam->golPenalty > pointerPertandingan.rightTeam->golPenalty){
					printf("\n\t\t\t\t\t\t\t\t\t\t>>>> Tim %s menang <<<<!\n", pointerPertandingan.leftTeam->value);
					upgradeLeftTeam(pointerPertandingan, nodeSearch);
				}else{
					printf("\n\t\t\t\t\t\t\t\t\t\t>>>> Tim %s menang <<<<!\n", pointerPertandingan.rightTeam->value);
					upgradeRightTeam(pointerPertandingan, nodeSearch);
				}
			}else if(pointerPertandingan.leftTeam->gol > pointerPertandingan.rightTeam->gol){
				printf("\n\t\t\t\t\t\t\t\t\t\t>>>> Tim %s menang! <<<<\n", pointerPertandingan.leftTeam->value);
				upgradeLeftTeam(pointerPertandingan, nodeSearch);
				// pertandingan berhenti
			}else{
				printf("\n\t\t\t\t\t\t\t\t\t\t>>>> Tim %s menang! <<<<\n", pointerPertandingan.rightTeam->value);
				upgradeRightTeam(pointerPertandingan, nodeSearch);
			}
			printf("\n\n\n");
			system("pause");
		}
	}
}

void babakPenalty(addressNode root, Referee pointerPertandingan){
	int leftTeamPenaltyChance = 5, rightTeamPenaltyChance = 5, golPenaltyKiri = 0, golPenaltyKanan = 0, i = 0;
	
	printf("\n\t\t\t\t\t\t\t\t\t\t|     Babak Penalty\t|\n");
	printf("\t\t\t\t\t\t\t\t\t\t=========================");
	while(leftTeamPenaltyChance != 0 && rightTeamPenaltyChance != 0){
		i++;
		pointerPertandingan.leftTeam->golPenalty += randomPenalty();
		pointerPertandingan.rightTeam->golPenalty += randomPenalty();
		leftTeamPenaltyChance--;
		rightTeamPenaltyChance--;
		if((pointerPertandingan.leftTeam->golPenalty + leftTeamPenaltyChance) < pointerPertandingan.rightTeam->golPenalty || (pointerPertandingan.rightTeam->golPenalty + rightTeamPenaltyChance) < pointerPertandingan.leftTeam->golPenalty){
			printf("\n\t\t\t\t\t\t\t\t\t\t|     Tendangan ke-%d    |\n", i);
			printf("\t\t\t\t\t\t\t\t\t\t-------------------------");
			printf("\n\t\t\t\t\t\t\t\t\t\t| Tim %s = %d\t\t|\n", pointerPertandingan.leftTeam->value, pointerPertandingan.leftTeam->golPenalty);
			printf("\t\t\t\t\t\t\t\t\t\t| Tim %s = %d\t\t|\n", pointerPertandingan.rightTeam->value, pointerPertandingan.rightTeam->golPenalty);
			printf("\t\t\t\t\t\t\t\t\t\t-------------------------");
			break;
		}
		printf("\n\t\t\t\t\t\t\t\t\t\t|     Tendangan ke-%d    |\n", i);
		printf("\t\t\t\t\t\t\t\t\t\t-------------------------");
		printf("\n\t\t\t\t\t\t\t\t\t\t| Tim %s = %d\t\t|\n", pointerPertandingan.leftTeam->value, pointerPertandingan.leftTeam->golPenalty);
		printf("\t\t\t\t\t\t\t\t\t\t| Tim %s = %d\t\t|\n", pointerPertandingan.rightTeam->value, pointerPertandingan.rightTeam->golPenalty);
		printf("\t\t\t\t\t\t\t\t\t\t-------------------------");
	}
	
	while(pointerPertandingan.leftTeam->golPenalty == pointerPertandingan.rightTeam->golPenalty){
		i++;
		pointerPertandingan.leftTeam->golPenalty += randomPenalty();
		pointerPertandingan.rightTeam->golPenalty += randomPenalty();
		printf("\n\t\t\t\t\t\t\t\t\t\t|     Sudden Death\t|\n");
		printf("\t\t\t\t\t\t\t\t\t\t=========================");
		printf("\n\t\t\t\t\t\t\t\t\t\t|     Tendangan ke-%d    |\n", i);
		printf("\t\t\t\t\t\t\t\t\t\t-------------------------");
		printf("\n\t\t\t\t\t\t\t\t\t\t| Tim %s = %d\t\t|\n", pointerPertandingan.leftTeam->value, pointerPertandingan.leftTeam->golPenalty);
		printf("\t\t\t\t\t\t\t\t\t\t| Tim %s = %d\t\t|\n", pointerPertandingan.rightTeam->value, pointerPertandingan.rightTeam->golPenalty);
		printf("\t\t\t\t\t\t\t\t\t\t-------------------------");
	}
}

void upgradeLeftTeam(Referee pointerPertandingan, addressNode nodeSearch){
	addressNode deleteLeft, deleteRight;

	nodeSearch->value = pointerPertandingan.leftTeam->value;
	deleteLeft = pointerPertandingan.leftTeam;
	deleteRight = pointerPertandingan.rightTeam;
	pointerPertandingan.leftTeam = NULL;
	pointerPertandingan.rightTeam = NULL;
	free(deleteLeft);
	free(deleteRight);
}

void upgradeRightTeam(Referee pointerPertandingan, addressNode nodeSearch){
	addressNode deleteLeft, deleteRight;

	nodeSearch->value = pointerPertandingan.rightTeam->value;
	deleteLeft = pointerPertandingan.leftTeam;
	deleteRight = pointerPertandingan.rightTeam;
	pointerPertandingan.leftTeam = NULL;
	pointerPertandingan.rightTeam = NULL;
	free(deleteLeft);
	free(deleteRight);
}

/* =====================================================================*/
/* --------------------------- Modul Support ---------------------------*/
/* =====================================================================*/
void loadingScreen(){
	int loading;
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t   Loading....\n");
	printf("\t\t\t\t\t\t\t\t\t");
	for(loading = 0; loading < 30; loading++){
		printf("%c", 223);
		Sleep(25);
	}
	system("cls");
}

addressNode searchNode(addressNode root, int key) {
    if (root == NULL || root->alamat == key) {
        return root;
    } else if (root->alamat < key) {
        return searchNode(root->right, key);
    } else {
        return searchNode(root->left, key);
    }
}

int randomGol(){
	return rand() % 10;
}

int randomPenalty(){
	int a = randomGol(), b = randomGol();
	
	if(a < b){
		return 1;
	}else{
		return 0;
	}
}
