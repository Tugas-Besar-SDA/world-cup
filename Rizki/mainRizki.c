#include "headerRizki.h"

/* jumlah team yang bertanding sementara harus kelipatan 2 biar gak error*/
/* 	
	pola penempatan angka di tree nya:
	1. tree paling ujung kiri bawah nilainya 1	
	2. pola penempatan angka node di kanannya bakal ngeliat nilai integer di node paling kiri,
	   terus nilai tersebut jadi 2*n (n adalah nilai paling kiri node di tree), hasil dari 2*n itu jadi patokan buat pola "alamat" node nya
	   misal: paling kirinya bernilai 1, berarti ke kanan nya terus sampai ujung bakal berpola 1, 3, 5, 7, dst.
	   kalau paling kiri node bernilai 2, berarti ke kanan nya terus sampai ujung bakal berpola 2, 6, 10, 14, dst.
	   kalau paling kiri node bernilai 4, berarti ke kanan nya terus sampai ujung bakal berpola 4, 12, 20, 28, dst.
	   kalau paling kiri node bernilai 8, berarti ke kanan nya terus sampai ujung bakal berpola 8, 24.
	   yang terakhir "alamatnya itu 16"
	   itu semua berlaku untuk jumlah node 31, kalau 15 gimana? Yah berarti pakai pola itu, anggap node paling kiri bawah nilainya 1,
	   nanti polanya ngikutin yang atas
	3. ohh iya nilai paling kiri node itu 1, parent nya 2, parentnya lagi 4, terus pokoknya dikali 2 terus sampai ke root
*/

int main(){
    int maxNode, i;
    printf("Masukkan jumlah maksimum node: "); // harus kelipatan 2
    scanf("%d", &maxNode);

    int height = tree_height(maxNode); // kalau 31 node (16 tim) berarti height = 4
    printf("\nHeight dari tree adalah: %d\n", height);
    int maxNodeFullTree = pow(2, height+1) - 1;
    printf("\nMax node dari tree adalah: %d\n", maxNodeFullTree);
    int arr[maxNodeFullTree];

    for (i = 0; i < maxNodeFullTree; i++) {
        if (i < maxNode) {
            arr[i] = i+1;
        } else {
            arr[i] = 0;
        }
    }

    addressNode root = build_tree(arr, 0, maxNodeFullTree-1);
    printf("Preorder traversal: ");
    preorder_traversal(root);
    printf("\nInorder traversal: ");
    inorder_traversal(root);
    printf("\nPostorder traversal: ");
    postorder_traversal(root);
    
    infotype input;
    input = (infotype) malloc (3 * sizeof(char));
    scanf("%s", input);
    root->value = input;
    printf("Root = %s", root->value);

    return 0;
}
