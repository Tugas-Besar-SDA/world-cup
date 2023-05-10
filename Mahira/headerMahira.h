#ifndef headerMahira_h
#define headerMahira_h

#include "..\Adi\headerAdi.h"
#include "..\Rizki\headerRizki.h"
#include "..\boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

//mahira
void Match(addressTeam *M, addressTeam *N);
void PointCalculation(addressTeam *V, addressTeam *M);
void MatchInGroup(addressTeam *B, addressTeam *C);
void MatchButton(ListGroup A, addressGroup *B, addressTeam *C, addressTeam *D);
void GroupWinner(addressGroup A, addressTeam *M, addressTeam *N);
int CountTeam(addressGroup *A);
void WinnerList(addressTeam P, addressTeam Q);
void OpenListOfWinner();
void GroupStage(ListGroup MyListGroup);

#endif
