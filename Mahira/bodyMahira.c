#include "headerMahira.h"
#include "..\Adi\headerAdi.h"
#include "..\Rizki\headerRizki.h"

void Pertandingan(addressTeam *M, addressTeam *N)
{
	Gol(*M) = rand()%15;
	Gol(*N) = rand()%15;
	
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

void KalkulasiPoin(addressTeam *V, addressTeam *M)
{
	Skor(*V) = Skor(*V) + Skor(*M);
	Gol(*V) = Gol(*V) + Gol(*M);
	Selisih(*V) = Selisih(*V) + Selisih(*M);
}

void GroupStage(addressGroup A)
{
	addressTeam M, N, B, C;
	int i = 1;
	B = nextGroupToTeam(A);
	C = NextTeam(B);
	while(C != Nil)
	{
		Pertandingan(&M, &N);
		KalkulasiPoin(&B, &M);
		KalkulasiPoin(&C, &N);
		printf("Pertandingan %d\n", i);
		printf("Team = %s, Skor = %d, Gol = %d, Selisih = %d\n", InfoTeam(B), Skor(M), Gol(M), Selisih(M));
		printf("Team = %s, Skor = %d, Gol = %d, Selisih = %d\n", InfoTeam(C), Skor(N), Gol(N), Selisih(N));
		C = NextTeam(C);
		N = C;
		i++;
	}
}

void GroupWinner(addressGroup A, addressTeam *M, addressTeam *N)
{
	addressTeam B, C;
	int undi;
	
	*M = (addressTeam) malloc (sizeof (DataTeam));
	*N = (addressTeam) malloc (sizeof (DataTeam));
	B = nextGroupToTeam(A);
	C = NextTeam(B);
	while(C != Nil)
	{
	if(Skor(B) > Skor(C))
	{
//		*N = C;
		C = NextTeam(C);
	}
	else if(Skor(B) < Skor(C))
	{
		*N = B;
		B = C;
		C = NextTeam(C);
	}
	else 
//	if(Skor(B) == Skor(C))
	{
		if(Selisih(B) > Selisih(C))
		{
			C = NextTeam(C);
		}
		else if(Selisih(B) < Selisih(C))
		{
			*N = B;
			B = C;
			C = NextTeam(C);
		}
		else 
//		if(Selisih(B) == Selisih(C))
		{
			if(Gol(B) > Gol(C))
			{
				C = NextTeam(C);
			}
			else if(Gol(B) < Gol(C))
			{
				*N = B;
				B = C;
				C = NextTeam(C);
			}
			else 
//			if(Gol(B) == Gol(C))
			{
				while(undi == 0)
				{
					undi = rand()%2;
					if(undi == 1)
					{
						*N = B;
					}
					else if(undi == 2)
					{
						*N = C;
					}
				}
				
			}
		}
	}
	*M = B;
//	*N = C;
	}
//	*M = *N;
//	*M = B;
}
