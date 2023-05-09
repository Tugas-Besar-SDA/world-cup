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
	printf("Team = %s, Skor = %d, Gol = %d, Selisih = %d\n", InfoTeam(*B), Skor(M), Gol(M), Selisih(M));
	printf("Team = %s, Skor = %d, Gol = %d, Selisih = %d\n", InfoTeam(*C), Skor(N), Gol(N), Selisih(N));
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
			if(*B == Nil)
			{
				printf("B = %s\n", *B);
				printf("Pertandingan fase grup telah berakhir\n");
				break;
			}
			else
			{
				*C = nextGroupToTeam(*B);
				*D = NextTeam(*C);
			}
			if(*D == Nil)
			{
				
			}
		}
		else if(*D == Nil && *C != Nil)
		{
			*C = NextTeam(*C);
			if(*C == Nil)
			{
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
	addressTeam B, C, O;
	int undi;
	
	*M = (addressTeam) malloc (sizeof (DataTeam));
	*N = (addressTeam) malloc (sizeof (DataTeam));
	O = (addressTeam) malloc (sizeof (DataTeam));
	B = nextGroupToTeam(A);
	C = NextTeam(B);
	while(C != Nil)
	{
		if(Skor(B) > Skor(C))
		{
			O = C;
			C = NextTeam(C);
//			*N = O;
		}
		else if(Skor(B) < Skor(C))
		{
			O = B;
			B = C;
			C = O;
			C = NextTeam(C);
		}
		else if(Skor(B) == Skor(C))
		{
			if(Selisih(B) > Selisih(C))
			{
				O = C;
				C = NextTeam(C);
			} 
			else if(Selisih(B) < Selisih(C))
			{
				O = B;
				B = C;
				C = O;
				C = NextTeam(C);
			}
			else if(Selisih(B) == Selisih(C))
			{
				if(Gol(B) > Gol(C))
				{
					O = C;
					C = NextTeam(C);
				}
				else if(Gol(B) < Gol(C))
				{
					O = B;
					B = C;
					C = O;
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
						C = O;
					}				
				}
			}
		}
		*M = B;
		*N = O;
	}
}

//void GroupStage(addressGroup A)
//{
//	addressTeam M, N, B, C;
//	int i = 1;
//	
//	M = (addressTeam) malloc (sizeof (DataTeam));
//	N = (addressTeam) malloc (sizeof (DataTeam));
//	B = nextGroupToTeam(A);
//	C = NextTeam(B);
//	while(C != Nil)
//	{
//		Match(&M, &N);
//		KalkulasiPoin(&B, &M);
//		KalkulasiPoin(&C, &N); 
//		printf("Pertandingan %d Group = %s\n", i, InfoGroup(A));
//		printf("Team = %s, Skor = %d, Gol = %d, Selisih = %d\n", InfoTeam(B), Skor(M), Gol(M), Selisih(M));
//		printf("Team = %s, Skor = %d, Gol = %d, Selisih = %d\n", InfoTeam(C), Skor(N), Gol(N), Selisih(N));
//		printf("\n");
//		C = NextTeam(C); //ned
//		if(C == Nil)
//		{
//			B = NextTeam(B);
//			C = NextTeam(B);
//		}
//		i++;
//	}
//}
