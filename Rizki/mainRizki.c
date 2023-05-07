#include "headerRizki.h"

int main(){
	// Inisialisasi seed dengan waktu saat ini
    srand(time(NULL));
	
	/* Kamus data */
    int maxNode, i, levelTree;
    
    /* Proses membuat tree yang full balanced */
    printf("Masukkan jumlah maksimum node (7, 15, atau 31): ");
    scanf("%d", &maxNode);

    int height = tree_height(maxNode); // kalau 31 node (16 tim) berarti height = 4
    int maxNodeFullTree = pow(2, height+1) - 1;
    int arr[maxNodeFullTree];

    for (i = 0; i < maxNodeFullTree; i++) {
        if (i < maxNode) {
            arr[i] = i+1;
        } else {
            arr[i] = 0;
        }
    }

    addressNode root = build_tree(arr, 0, maxNodeFullTree-1);
	
	/* Memasukkan tim ke tree */
	infotype X = malloc (3 * sizeof(char));
	inputTim(root, X, maxNode);
	
	/* Pertandingan dimulai */
	babakGugur(root, maxNode);
	
	/* Hasil dari pertandingan */
	printf("\n==================================================\n");
	printf("                CHAMPION: %s", root->value);
	printf("\n==================================================\n");
	
    return 0;
}
