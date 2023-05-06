#ifndef headerRizki_h
#define headerRizki_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef char* infotype;
typedef struct tNode *addressNode;
typedef struct tNode {
    addressNode left;
    infotype value;
    int gol; // nilai default
    addressNode right;
}Node;

typedef struct tReferee{
	addressNode leftTeam;
	addressNode rightTeam;
}Referee;

int tree_height(int n);

addressNode create_node(int value);

addressNode build_tree(int arr[], int start, int end);

void preorder_traversal(addressNode root);

void inorder_traversal(addressNode root);

void postorder_traversal(addressNode root);

addressNode refereeSearchTeam(addressNode referee);

int jumlahDaun(int maxNode);

//void groupToTree()

#endif
