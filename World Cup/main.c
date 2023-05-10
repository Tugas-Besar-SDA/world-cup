#include "header.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() 
{
	srand(time(NULL));
	//kamus data
	ListGroup MyListGroup, F;
	ListTeam MyListTim;
	addressTeam K, L, M, N, O, P, Q, B, C, R, S, T;
	addressGroup A, G, H, HeadGroup;
	addressNode root;
	char pilih;
	int i = 1, menu, height, maxNode, maxNodeFullTree, arr[maxNodeFullTree], SumOfTeam, SumOfMatch;
	
	CreateListGroup(&MyListGroup);
	
	B = (addressTeam) malloc (sizeof (DataTeam));
	C = (addressTeam) malloc (sizeof (DataTeam));
	B = Nil;
	C = Nil;
	H = (addressGroup) malloc (sizeof (DataGroup));
	ReadTeam(&MyListGroup);
	
	//program
	do
	{
		system("cls");
		printf("\n");
		printf("\n\t\t=============================================\n");
		printf("\t\t\t\t  WORLD CUP");
		printf("\n\t\t=============================================\n");
		printf("\n\t\t\t   1. List Group\n");
		printf("\t\t\t   2. Group Stage\n");
		printf("\t\t\t   3. Knockout Stage\n");
		printf("\t\t\t   4. Add and Delete Group Team\n");
		printf("\t\t\t   0. Exit\n");
		printf("\n\t\t=============================================\n");
		printf("\n\t\t     Pilih menu: ");
		scanf("%d", &menu);
		switch(menu)
		{
			case 1:
			{
				if(!isEmptyGroup(MyListGroup))
				{
					system("cls");
					PrintInfo(MyListGroup);
				}
				printf("\t\t     ");
				system("pause");
				break;
			}
			case 2:
			{
				do
				{
					system("cls");
					printf("\n");
					printf("\n\t\t=============================================\n");
					printf("\t\t\t\t GROUP STAGE");
					printf("\n\t\t=============================================\n");
					printf("\n\t\t\t     1. Match Button\n");
					printf("\t\t\t     2. Group Winner\n");
					printf("\t\t\t     99. Back to menu\n");
					printf("\n\t\t=============================================\n");
					printf("\n\t\t     Pilih menu: ");
					scanf("%d", &menu);
					switch(menu)
					{
						case 1:
						{
							if(First(MyListGroup) == Nil)
							{
								printf("\t\t     Tidak ada tim untuk ditandingkan\n");
							}
							else
							{
								GroupStage(MyListGroup);
								A = First(MyListGroup);
								formatFileBefore();
								do
								{
									GroupWinner(A, &P, &Q);
									WinnerList(P, Q);
									A = nextGroup(A);
								}while(A != Nil);
							}
							printf("\t\t     ");
							system("pause");
							break;
						}
						case 2:
						{
							OpenListOfWinner();
							printf("\t\t     ");
							system("pause");
							break;
						}
						case 99:
						{
							menu = 99;
							break;
						}
					}
				}while(menu != 99);
				break;
			}
			case 3:
			{
				prosesBabakGugur();
				system("pause");
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
					printf("\n\t\t=============================================\n");
					printf("\t\t\t\t ADD AND DELETE");
					printf("\n\t\t=============================================\n");
					printf("\n\t\t\t\t1. Add Group\n");
					printf("\t\t\t\t2. Add Team\n");
					printf("\t\t\t\t3. Delete Group\n");
					printf("\t\t\t\t4. Delete Team\n");
					printf("\t\t\t\t99. Back to menu\n");
					printf("\n\t\t=============================================\n");
					printf("\n\t\t     Pilih menu: ");
					scanf("%d", &menu);
					switch(menu)
					{
						case 1:
						{
							MenuAddGroup(&MyListGroup);
							break;
						}
						case 2:
						{
							MenuAddTeam(&MyListGroup);
							break;
						}
						case 3:
						{
							MenuDelGroup(&MyListGroup);
							break;
						}
						case 4:
						{
							MenuDelTeam(&MyListGroup);
							break;
						}
						case 99:
						{
							menu = 99;
							break;
						}
						default:
						{
							printf("Kesalahan input! Menu %d tidak tersedia \n", menu);
							system("pause");
							break;
						}
					}
				}while(menu != 99);
				break;
			}
		}
	}while(menu != 0);
	return 0;
}
