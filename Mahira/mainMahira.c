#include "headerMahira.h"

int main() 
{
	//kamus data
	ListGroup MyListGroup, F;
	ListTeam MyListTim;
	addressTeam K, L, M, N, O, P, Q, B, C;
	addressGroup A, G, H, HeadGroup;
	addressNode root;
	char pilih;
	int i = 1, menu, height, maxNode, maxNodeFullTree, arr[maxNodeFullTree];
	
	CreateListGroup(&MyListGroup);
	A = AlokasiGroup("A");
	G = AlokasiGroup("B");
	
	K = AlokasiTeam("GER");
	L = AlokasiTeam("ARG");
	M = AlokasiTeam("NED");
	N = AlokasiTeam("CRO");
	O = AlokasiTeam("JPN");
	
	First(F) = A;
//	nextGroup(A) = G;
	nextGroupToTeam(A) = K;
	NextTeam(K)	= L;
	NextTeam(L)	= M;
	
//	NextTeam(M)	= N;
	NextTeam(N)	= O;
	MatchInGroup(&K, &L);
	B = (addressTeam) malloc (sizeof (DataTeam));
	C = (addressTeam) malloc (sizeof (DataTeam));
	B = Nil;
	C = Nil;
	H = (addressGroup) malloc (sizeof (DataGroup));
	
	//program
	do
	{
		system("cls");
		printf("\n");
		printf("1. List Group\n");
		printf("2. Group Stage\n");
		printf("3. Knockout Stage\n");
		printf("4. Add and Delete Group Team\n");
		printf("0. Exit\n");
		scanf("%d", &menu);
		switch(menu)
		{
			case 1:
			{
				if(!isEmptyGroup(MyListGroup))
				{
					PrintInfo(MyListGroup);
				}
				system("pause");
				break;
			}
			case 2:
			{
				do
				{
					system("cls");
					printf("\n");
					printf("1. Match Button\n");
					printf("2. Next Match\n");
					printf("99. Back to menu\n");
					scanf("%d", &menu);
					switch(menu)
					{
						case 1:
						{
							do
							{
								if(H != Nil)
								{
									printf("Pertandingan di luar %d Group = %s\n", i, InfoGroup(A));
								}
									MatchButton(F, &H, &B, &C);
									printf("Menonton pertandingan? [y/t]\n");
									scanf(" %c", &pilih);
								i++;
							}while(pilih == 'y');
//							MatchButton(F, &H, &B, &C);
//							MyListGroup
							system("pause");
							break;
						}
						case 2:
						{
//							next match pokonya
							break;
						}
					}
				}while(menu != 99);
			}
			case 3:
			{
				height = tree_height(maxNode); // kalau 31 node (16 tim) berarti height = 4
			    maxNodeFullTree = pow(2, height+1) - 1;
			    arr[maxNodeFullTree];
			
			    for (i = 0; i < maxNodeFullTree; i++) {
			        if (i < maxNode) {
			            arr[i] = i+1;
			        } else {
			            arr[i] = 0;
			        }
			    }
			
			    root = build_tree(arr, 0, maxNodeFullTree-1);
			    
			    babakGugur(root, maxNode);
				break;
			}
			case 4:
			{
				do
				{
					system("cls");
					if(!isEmptyGroup(MyListGroup))
					{
						PrintInfo(MyListGroup);
					}
					printf("\n");
					printf("1. Add Group\n");
					printf("2. Add Team\n");
					printf("3. Delete Group\n");
					printf("4. Delete Team\n");
					printf("99. Back to menu\n");
					scanf("%d", &menu);
					switch(menu)
					{
						case 1:
						{
							addGroup(&MyListGroup, &HeadGroup);
							break;
						}
						case 2:
						{
							addTeam(&MyListGroup, &MyListTim, &HeadGroup);
							break;
						}
						case 3:
						{
							DelGroup(&MyListGroup, &HeadGroup);
							break;
						}
						case 4:
						{
							DelTeam(&MyListGroup, &MyListTim, &HeadGroup);
							break;
						}
					}
				}while(menu != 99);
			}
		}
	}while(menu != 0);
	
//	First(F) = A;
////	nextGroup(A) = G;
//	nextGroupToTeam(A) = K;
//	NextTeam(K)	= L;
//	NextTeam(L)	= M;
//	
//	NextTeam(M)	= N;
//	NextTeam(N)	= O;
//	MatchInGroup(&K, &L);
//	B = (addressTeam) malloc (sizeof (DataTeam));
//	C = (addressTeam) malloc (sizeof (DataTeam));
//	B = Nil;
//	C = Nil;
//	H = (addressGroup) malloc (sizeof (DataGroup));
//	do
//	{
//		if(H != Nil)
//		{
////			printf("H = %s\n", H);
//			printf("Pertandingan di luar %d Group = %s\n", i, InfoGroup(A));
//		}
//			MatchButton(F, &H, &B, &C);
////			printf("Pertandingan selanjutnya\n %s VS %s\n", InfoTeam(B), InfoTeam(C));
//			printf("Menonton pertandingan? [y/t]\n");
//			scanf(" %c", &pilih);
//		i++;
//	}while(pilih == 'y');
////	GroupStage(A);
//	
//	printf("\n");
//	printf("Team = %s, Skor = %d, Gol = %d, Selisih = %d\n", InfoTeam(K), Skor(K), Gol(K), Selisih(K));
//	printf("Team = %s, Skor = %d, Gol = %d, Selisih = %d\n", InfoTeam(L), Skor(L), Gol(L), Selisih(L));
//	printf("Team = %s, Skor = %d, Gol = %d, Selisih = %d\n", InfoTeam(M), Skor(M), Gol(M), Selisih(M));
//	printf("Team = %s, Skor = %d, Gol = %d, Selisih = %d\n", InfoTeam(N), Skor(N), Gol(N), Selisih(N));
//	printf("Team = %s, Skor = %d, Gol = %d, Selisih = %d\n", InfoTeam(O), Skor(O), Gol(O), Selisih(O));
//	
//	GroupWinner(A, &P, &Q);
//	printf("\nJuara Grup\n");
//	printf("Team = %s, Skor = %d, Gol = %d, Selisih = %d\n", InfoTeam(P), Skor(P), Gol(P), Selisih(P));
//	printf("Team = %s, Skor = %d, Gol = %d, Selisih = %d\n", InfoTeam(Q), Skor(Q), Gol(Q), Selisih(Q));
	return 0;
}
