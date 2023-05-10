#include "headerMahira.h"
//#include "..\Adi\headerAdi.h"
//#include "..\Rizki\headerRizki.h"

void Match(addressTeam *M, addressTeam *N)
{
	srand(time(Nil));
	Gol(*M) = rand()%10;
	Gol(*N) = rand()%10;
	
	if(Gol(*M) == Gol(*N))
	{
		Skor(*M) = 1;
		Skor(*N) = 1;
	}
	else if(Gol(*M) > Gol(*N))
	{
		Skor(*M) = 3;
		Skor(*N) = 0;
	}
	else if(Gol(*M) < Gol(*N))
	{
		Skor(*M) = 0;
		Skor(*N) = 3;
	}
	Selisih(*M) = Gol(*M) - Gol(*N);
	Selisih(*N) = Gol(*N) - Gol(*M);
}

void PointCalculation(addressTeam *V, addressTeam *M)
{
	Skor(*V) = Skor(*V) + Skor(*M);
	Gol(*V) = Gol(*V) + Gol(*M);
	Selisih(*V) = Selisih(*V) + Selisih(*M);
}

void MatchInGroup(addressTeam *B, addressTeam *C)
{
	addressTeam M, N;
	
	M = (addressTeam) malloc (sizeof (DataTeam));
	N = (addressTeam) malloc (sizeof (DataTeam));
	
	Match(&M, &N);
	PointCalculation(&(*B), &M);
	PointCalculation(&(*C), &N); 
	printf("\t\t\t  Team = %s, Skor = %d, Gol = %d, Selisih = %d\n", InfoTeam(*B), Skor(M), Gol(M), Selisih(M));
	printf("\t\t\t  Team = %s, Skor = %d, Gol = %d, Selisih = %d\n", InfoTeam(*C), Skor(N), Gol(N), Selisih(N));
	printf("\n");
}

void MatchButton(ListGroup A, addressGroup *B, addressTeam *C, addressTeam *D)
{
	
	if(*C == Nil && *D == Nil)
	{
		*B = First(A);
		*C = nextGroupToTeam(*B);
		*D = NextTeam(*C);
	}
	
	do
	{
		if(*C == Nil)
		{	
			*B = nextGroup(*B);
			*C = nextGroupToTeam(*B);
			*D = NextTeam(*C);
		}
		else if(*D == Nil && *C != Nil)
		{
			*C = NextTeam(*C);
			if(NextTeam(*C) == Nil)
			{
				*C = Nil;
				*D = Nil;
			}
			else
			{
				*D = NextTeam(*C);
			}
		}
		else if(*D != Nil) 
		{
			MatchInGroup(&(*C), &(*D));
			*D = NextTeam(*D);
		}
//		printf("D = %s\n", InfoTeam(*D));
	}while(*C == Nil || *D == NextTeam(*C));
}

void GroupWinner(addressGroup A, addressTeam *M, addressTeam *N)
{
	//kamus data lokal
	addressTeam B, C, O;
	int undi;
	
	//inisialisasi
	*M = (addressTeam) malloc (sizeof (DataTeam));
	*N = (addressTeam) malloc (sizeof (DataTeam));
	O = (addressTeam) malloc (sizeof (DataTeam));
	Skor(O) = -1;
	Selisih(O) = -1;
	Gol(O) = -1;
	
	B = nextGroupToTeam(A);
	C = NextTeam(B);
	
	while(C != Nil)
	{
		if(Skor(B) > Skor(C))
		{
			if(Skor(O) < Skor(C))
			{
				O = C;	
			}
			C = NextTeam(C);
		}
		else if(Skor(B) < Skor(C))
		{
			O = B;
			B = C;
			C = NextTeam(C);
		}
		else if(Skor(B) == Skor(C))
		{
			if(Selisih(B) > Selisih(C))
			{
				if(Selisih(O) < Selisih(C))
				{
					O = C;	
				}
				C = NextTeam(C);
			} 
			else if(Selisih(B) < Selisih(C))
			{
				O = B;
				B = C;
				C = NextTeam(C);
			}
			else if(Selisih(B) == Selisih(C))
			{
				if(Gol(B) > Gol(C))
				{
					if(Gol(O) < Gol(C))
					{
						O = C;	
					}
					C = NextTeam(C);
				}
				else if(Gol(B) < Gol(C))
				{
					O = B;
					B = C;
					C = NextTeam(C);
				}
				else if(Gol(B) == Gol(C))
				{
					undi = rand()%1;
					if(undi == 1)
					{
						O = C;
					}
					else if(undi == 0)
					{
						O = B;
						B = C;
					}				
				}
			}
		}
		*M = B;
		*N = O;
	}
}

int CountTeam(addressGroup *A)
{
//	addressGroup B;
	addressTeam C;
	int sum = 0;
	
	C = nextGroupToTeam(*A);
	while(C != Nil)
	{
		sum++;
		C = NextTeam(C);
	}
	return sum;
}

void WinnerList(addressTeam P, addressTeam Q)
{
	FILE *fileP;
	infotype tim, tim1;
	
	//buka dan/atau buat file
	fileP = fopen("..\\Rizki\\pemenangFaseGrup(before).txt", "a");
	
	//jika file tidak dapat dibuka
	if(fileP == NULL)
	{
		printf("\n2. File tidak bisa terbuka!\n");
	}
	else
	{
		//alokasi
		tim = (infotype) malloc (3 * sizeof(char));
		
		//menyimpan di file
		tim = InfoTeam(P);
		fprintf(fileP, "%s\n", tim);
		tim = InfoTeam(Q);
		fprintf(fileP, "%s\n", tim);
	}
	fclose(fileP);
}

void OpenListOfWinner()
{
	//kamus data lokal
	FILE *fileP;
	infotype tim;
	
	fileP = fopen("..\\Rizki\\pemenangFaseGrup(before).txt","r");
	tim = (infotype) malloc (3 * sizeof(char));
	if(fileP == NULL)
	{
		printf("\n1. File tidak bisa terbuka!\n");
	}
	else
	{
		while(!feof(fileP))
		{
			fscanf(fileP, "%s\n", tim);
			printf("%s\n", tim);	
		}
	}
	fclose(fileP);
}

void GroupStage(ListGroup MyListGroup)
//pertandingan dalam grup
{
	addressGroup H, I;
	addressTeam B, C;
	int SumOfTeam, SumOfMatch, i;
	
	B = (addressTeam) malloc (sizeof (DataTeam));
	C = (addressTeam) malloc (sizeof (DataTeam));
	B = Nil;
	C = Nil;
	H = First(MyListGroup);
	do
	{
		SumOfTeam = CountTeam(&H);
		printf("Team = %d\n", SumOfTeam);
		SumOfMatch = (SumOfTeam*(SumOfTeam-1))/2;
		printf("Match = %d\n", SumOfMatch);
		
		for(i = 1; i <= SumOfMatch; i++)
		{
			printf("Pertandingan %d Group = %s\n", i, InfoGroup(H));
			MatchButton(MyListGroup, &I, &B, &C);
			system("pause");
		}
		H = nextGroup(H);
	}while(H != Nil);
}
