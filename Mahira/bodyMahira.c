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
