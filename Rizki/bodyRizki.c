#include "..\Mahira\headerMahira.h"

/* =====================================================================*/
/* ------------------------- Modul Pemrosesan --------------------------*/
/* =====================================================================*/
void prosesBabakGugur(){
	/* Inisiasi isi file yang akan terpakai di program untuk dikosongi */
	formatFile();
	
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
	inputTim(root, countingTeams());
	
	/* Pertandingan dimulai */
	babakGugur(root, countingTeams());
	
	/* Hasil dari pertandingan */
	system("cls");
	printf("\n\n\n\n\n\t==================================================\n");
	printf("           |\t\t   CHAMPION: %s\t\t |", root->value);
	printf("\n\t==================================================\n");
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

void formatFile(){
	FILE *file;
	
	file = fopen("pemenangFaseGrup(after).txt", "w");
	fclose(file);
}

void sortTeamFromGroup(){
	FILE *file1, *file2;
	int i, j = 0, cursorFile2;
	infotype buffer1, buffer2, buffer3, buffer4;
	
	file1 = fopen("pemenangFaseGrup(before).txt", "r");
	if(file1 == NULL){
		printf("File tidak bisa dibuka");
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
				printf("File tidak bisa dibuka");
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
	
	file = fopen("pemenangFaseGrup(before).txt", "r");
	if(file == NULL){
		printf("File tidak bisa dibuka");
	}else{
		buffer = (infotype) malloc (3 * sizeof(char));
		fseek(file, 0, SEEK_SET);
		while(!feof(file)){
			fscanf(file, "%s", buffer);
			quantity++;
		}
	}
	
	fclose(file);
	
	return (quantity * 2) - 1;
}

void inputTim(addressNode root, int maxNode){
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
				printf("\n\t\t=========================\n");
				printf("     \t\t|   Pertandingan Final  |");
				printf("\n\t\t=========================\n");
			}else{
				system("cls");
				printf("\n\t\t=========================\n");
				printf("     \t\t|   Pertandingan ke-%d\t|", l++);
				printf("\n\t\t=========================\n");
			}
			nodeSearch = searchNode(root, k);
			pointerPertandingan.leftTeam = nodeSearch->left;
			pointerPertandingan.rightTeam = nodeSearch->right;
			printf("\t \t|\t%s vs %s\t|", pointerPertandingan.leftTeam->value, pointerPertandingan.rightTeam->value);
			printf("\n\t\t-------------------------\n");
			
			pointerPertandingan.leftTeam->gol = randomGol();
			pointerPertandingan.rightTeam->gol = randomGol();
			
			printf("\t\t| Gol tim %s: %d\t|\n", pointerPertandingan.leftTeam->value, pointerPertandingan.leftTeam->gol);
			printf("\t\t| Gol tim %s: %d\t|\n", pointerPertandingan.rightTeam->value, pointerPertandingan.rightTeam->gol);
			printf("\t\t=========================");
			
			if(pointerPertandingan.leftTeam->gol == pointerPertandingan.rightTeam->gol){
				// masuk ke sesi penalty
				babakPenalty(root, pointerPertandingan);
//				printf("\t\t=========================");
				if(pointerPertandingan.leftTeam->golPenalty > pointerPertandingan.rightTeam->golPenalty){
					printf("\n\t\t     Tim %s menang!\n", pointerPertandingan.leftTeam->value);
					upgradeLeftTeam(pointerPertandingan, nodeSearch);
				}else{
					printf("\n\t\t     Tim %s menang!\n", pointerPertandingan.rightTeam->value);
					upgradeRightTeam(pointerPertandingan, nodeSearch);
				}
			}else if(pointerPertandingan.leftTeam->gol > pointerPertandingan.rightTeam->gol){
				printf("\n\t\t     Tim %s menang!\n", pointerPertandingan.leftTeam->value);
				upgradeLeftTeam(pointerPertandingan, nodeSearch);
				// pertandingan berhenti
			}else{
				printf("\n\t\t     Tim %s menang!\n", pointerPertandingan.rightTeam->value);
				upgradeRightTeam(pointerPertandingan, nodeSearch);
			}
			printf("\n\n\n");
			system("pause");
		}
	}
}

void babakPenalty(addressNode root, Referee pointerPertandingan){
	int leftTeamPenaltyChance = 5, rightTeamPenaltyChance = 5, golPenaltyKiri = 0, golPenaltyKanan = 0, i = 0;
	
	printf("\n\t\t|     Babak Penalty\t|\n");
	printf("\t\t=========================");
	while(leftTeamPenaltyChance != 0 && rightTeamPenaltyChance != 0){
		i++;
		pointerPertandingan.leftTeam->golPenalty += randomPenalty();
		pointerPertandingan.rightTeam->golPenalty += randomPenalty();
		leftTeamPenaltyChance--;
		rightTeamPenaltyChance--;
		if((pointerPertandingan.leftTeam->golPenalty + leftTeamPenaltyChance) < pointerPertandingan.rightTeam->golPenalty || (pointerPertandingan.rightTeam->golPenalty + rightTeamPenaltyChance) < pointerPertandingan.leftTeam->golPenalty){
			printf("\n\t\t|     Tendangan ke-%d    |\n", i);
			printf("\t\t-------------------------");
			printf("\n\t\t| Tim %s = %d\t\t|\n", pointerPertandingan.leftTeam->value, pointerPertandingan.leftTeam->golPenalty);
			printf("\t\t| Tim %s = %d\t\t|\n", pointerPertandingan.rightTeam->value, pointerPertandingan.rightTeam->golPenalty);
			printf("\t\t-------------------------");
			break;
		}
		printf("\n\t\t|     Tendangan ke-%d    |\n", i);
		printf("\t\t-------------------------");
		printf("\n\t\t| Tim %s = %d\t\t|\n", pointerPertandingan.leftTeam->value, pointerPertandingan.leftTeam->golPenalty);
		printf("\t\t| Tim %s = %d\t\t|\n", pointerPertandingan.rightTeam->value, pointerPertandingan.rightTeam->golPenalty);
		printf("\t\t-------------------------");
	}
	
	while(pointerPertandingan.leftTeam->golPenalty == pointerPertandingan.rightTeam->golPenalty){
		i++;
		pointerPertandingan.leftTeam->golPenalty += randomPenalty();
		pointerPertandingan.rightTeam->golPenalty += randomPenalty();
		printf("\n\t\t|     Sudden Death\t|\n");
		printf("\t\t=========================");
		printf("\n\t\t|     Tendangan ke-%d    |\n", i);
		printf("\t\t-------------------------");
		printf("\n\t\t| Tim %s = %d\t\t|\n", pointerPertandingan.leftTeam->value, pointerPertandingan.leftTeam->golPenalty);
		printf("\t\t| Tim %s = %d\t\t|\n", pointerPertandingan.rightTeam->value, pointerPertandingan.rightTeam->golPenalty);
		printf("\t\t-------------------------");
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
