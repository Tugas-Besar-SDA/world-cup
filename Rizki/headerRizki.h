#ifndef headerRizki_h
#define headerRizki_h

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

/* ================================================*/
/* ---------------- Modul Pemroses ----------------*/
/* ================================================*/
void prosesBabakGugur();

/* ================================================*/
/* ---------------- Pembuatan Tree ----------------*/
/* ================================================*/
addressNode create_node(int number);

addressNode buildTree(int arr[], int start, int end);

int treeHeight(int n);

int calculateLevelTree(addressNode root);

/* ================================================*/
/* ----------------- Operasi File -----------------*/
/* ================================================*/
void formatFile();

void sortTeamFromGroup();

int countingTeams();

void inputTim(addressNode root, int maxNode);

/* =======================================================*/
/* ----------------- Proses Pertandingan -----------------*/
/* =======================================================*/
void babakGugur(addressNode root, int maxNode);

void babakPenalty(addressNode root, Referee pointerPertandingan);

void upgradeLeftTeam(Referee pointerPertandingan, addressNode nodeSearch);

void upgradeRightTeam(Referee pointerPertandingan, addressNode nodeSearch);

/* =================================================*/
/* ----------------- Modul Support -----------------*/
/* =================================================*/
addressNode searchNode(addressNode root, int key);

int randomGol();

int randomPenalty();

#endif
