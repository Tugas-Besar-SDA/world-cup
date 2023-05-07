#ifndef headerRizki_h
#define headerRizki_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

typedef char* infotype;
typedef struct tNode *addressNode;
typedef struct tNode {
    addressNode left;
    int alamat, gol, golPenalty;
    infotype value;
    addressNode right;
}Node;

typedef struct tReferee{
	addressNode leftTeam;
	addressNode rightTeam;
}Referee;

/* Pembuatan tree */
addressNode create_node(int number);

addressNode build_tree(int arr[], int start, int end);

int tree_height(int n);

void inputTim(addressNode root, infotype X, int maxNode);

addressNode searchNode(addressNode root, int key);

bool isRoot(addressNode root);

void upgradeLeftTeam(Referee pointerPertandingan, addressNode nodeSearch);

void upgradeRightTeam(Referee pointerPertandingan, addressNode nodeSearch);

void babakPenalty(addressNode root, Referee pointerPertandingan);

void upgradeFinalTeam(addressNode root, Referee pointerPertandingan);

int calculateLevelTree(addressNode root);

/* Proses pertandingan */
void babakGugur(addressNode root, int maxNode);

void babakPenalty(addressNode root, Referee pointerPertandingan);

void upgradeLeftTeam(Referee pointerPertandingan, addressNode nodeSearch);

void upgradeRightTeam(Referee pointerPertandingan, addressNode nodeSearch);

/* Modul Support */
addressNode searchNode(addressNode root, int key);

int randomGol();

int randomPenalty();

/* Modul Traversal */
void preorder_traversal(addressNode root);

void inorder_traversal(addressNode root);

void postorder_traversal(addressNode root);

#endif
