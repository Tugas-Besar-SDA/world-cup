#include "headerRizki.h"
#include "..\Mahira\headerMahira.h"

/* Pembuatan tree */
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

addressNode build_tree(int arr[], int start, int end) {
    if (start > end)
        return NULL;
    int mid = (start + end) / 2;
    addressNode root = create_node(arr[mid]);
    root->left = build_tree(arr, start, mid - 1);
    root->right = build_tree(arr, mid + 1, end);
    return root;
}

int tree_height(int n) {
    return (int)(log2(n+1)-1);
}

void inputTim(addressNode root, infotype X, int maxNode){
	FILE *file;
	infotype buffer;
	int i = 1;
	addressNode Psearch;
	
	file = fopen("nyobaDaftarTim.txt", "r");
	
	if(file == NULL){
		printf("\nFile tidak bisa terbuka!\n");
	}else{
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

int calculateLevelTree(addressNode root){
	int level = -1;
	addressNode pointer = root;
	
	while(pointer != NULL){
		pointer = pointer->right;
		level++;
	}
	return level;
}

/* Proses pertandingan */
void babakGugur(addressNode root, int maxNode){
	addressNode nodeSearch;
	int golKiri, golKanan;
	int tLevelTree = calculateLevelTree(root);
	int j, k, l = 1;
	
	for(j = 1; j <= tLevelTree; j++){
		for(k = pow(2, j); k <= maxNode; k += pow(2, (j+1))){
			Referee pointerPertandingan;
			
			if(k == pow(2, tLevelTree)){
				printf("\n=========================\n");
				printf("     Pertandingan Final");
				printf("\n=========================\n");
			}else{
				printf("\n=========================\n");
				printf("     Pertandingan ke-%d", l++);
				printf("\n=========================\n");
			}
			nodeSearch = searchNode(root, k);
			pointerPertandingan.leftTeam = nodeSearch->left;
			pointerPertandingan.rightTeam = nodeSearch->right;
			printf("\t %s vs %s", pointerPertandingan.leftTeam->value, pointerPertandingan.rightTeam->value);
			printf("\n-------------------------\n");
			
			pointerPertandingan.leftTeam->gol = randomGol();
			pointerPertandingan.rightTeam->gol = randomGol();
			
			printf("Gol tim %s: %d\n", pointerPertandingan.leftTeam->value, pointerPertandingan.leftTeam->gol);
			printf("Gol tim %s: %d\n", pointerPertandingan.rightTeam->value, pointerPertandingan.rightTeam->gol);
			
			if(pointerPertandingan.leftTeam->gol == pointerPertandingan.rightTeam->gol){
				// masuk ke sesi penalty
				babakPenalty(root, pointerPertandingan);
				
				if(pointerPertandingan.leftTeam->golPenalty > pointerPertandingan.rightTeam->golPenalty){
					printf("Tim Kiri naik di penalty\n");
					upgradeLeftTeam(pointerPertandingan, nodeSearch);
				}else{
					printf("Tim Kanan naik di penalty\n");
					upgradeRightTeam(pointerPertandingan, nodeSearch);
				}
			}else if(pointerPertandingan.leftTeam->gol > pointerPertandingan.rightTeam->gol){
				printf("\nTim Kiri naik!\n");
				upgradeLeftTeam(pointerPertandingan, nodeSearch);
				// pertandingan berhenti
			}else{
				printf("\nTim Kanan naik!\n");
				upgradeRightTeam(pointerPertandingan, nodeSearch);
			}
			system("pause");
		}
	}
}

void babakPenalty(addressNode root, Referee pointerPertandingan){
	int leftTeamPenaltyChance = 5, rightTeamPenaltyChance = 5, golPenaltyKiri = 0, golPenaltyKanan = 0;
	
	while(leftTeamPenaltyChance != 0 && rightTeamPenaltyChance != 0){
		pointerPertandingan.leftTeam->golPenalty += randomPenalty();
		pointerPertandingan.rightTeam->golPenalty += randomPenalty();
		leftTeamPenaltyChance--;
		rightTeamPenaltyChance--;
		printf("\nGol Penalty Kiri = %d\n", pointerPertandingan.leftTeam->golPenalty);
		printf("Gol Penalty Kanan = %d\n", pointerPertandingan.rightTeam->golPenalty);
	}
	
	while(pointerPertandingan.leftTeam->golPenalty == pointerPertandingan.rightTeam->golPenalty){
		pointerPertandingan.leftTeam->golPenalty += randomPenalty();
		pointerPertandingan.rightTeam->golPenalty += randomPenalty();
		printf("\nGol Penalty Kiri kedua = %d\n", pointerPertandingan.leftTeam->golPenalty);
		printf("Gol Penalty Kanan kedua = %d\n", pointerPertandingan.rightTeam->golPenalty);
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

/* Modul Support */
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
	return rand() % 10 + 1;
}

int randomPenalty(){
	int a = randomGol(), b = randomGol();
	
	if(a < b){
		return 1;
	}else{
		return 0;
	}
}

/* Modul Traversal */
void preorder_traversal(addressNode root) {
    if (root != NULL) {
        printf("%d ", root->alamat);
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}

void inorder_traversal(addressNode root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        printf("%d ", root->alamat);
        inorder_traversal(root->right);
    }
}

void postorder_traversal(addressNode root) {
    if (root != NULL) {
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        printf("%d ", root->alamat);
    }
}
