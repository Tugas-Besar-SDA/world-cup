#include "headerMahira.h"
#include "..\Adi\headerAdi.h"
#include "..\Rizki\headerRizki.h"

addressGroup AlokasiGroup (infotype X)
{
	addressGroup P;
	
	P = (addressGroup) malloc (sizeof (DataGroup));
	if (P != Nil)
	{
		InfoGroup(P) = X;
		nextGroup(P) = Nil;
		nextGroupToTeam(P) = Nil;
	}
	return (P);
}

addressTeam AlokasiTeam (infotype X)
{
	addressTeam P;
	
	P = (addressTeam) malloc (sizeof (DataTeam));
	if (P != Nil)
	{
		InfoTeam(P) = X;
		Gol(P) = 0;
		Selisih(P) = 0;
		Skor(P) = 0;
		NextTeam(P) = Nil;
	}
	return (P);
}

int main() 
{
	//kamus data
	addressTeam K, L, M, N, O, P, Q;
	addressGroup A;
	
	A = AlokasiGroup("A");
	
	K = AlokasiTeam("GER");
	L = AlokasiTeam("ARG");
	M = AlokasiTeam("NED");
	N = AlokasiTeam("CRO");
	O = AlokasiTeam("JPN");
	
	nextGroupToTeam(A) = K;
	NextTeam(K)	= L;
	NextTeam(L)	= M;
	NextTeam(M)	= N;
	NextTeam(N)	= O;
	GroupStage(A);
	
	printf("\n");
	printf("Team = %s, Skor = %d, Gol = %d, Selisih = %d\n", InfoTeam(K), Skor(K), Gol(K), Selisih(K));
	printf("Team = %s, Skor = %d, Gol = %d, Selisih = %d\n", InfoTeam(L), Skor(L), Gol(L), Selisih(L));
	printf("Team = %s, Skor = %d, Gol = %d, Selisih = %d\n", InfoTeam(M), Skor(M), Gol(M), Selisih(M));
	printf("Team = %s, Skor = %d, Gol = %d, Selisih = %d\n", InfoTeam(N), Skor(N), Gol(N), Selisih(N));
	printf("Team = %s, Skor = %d, Gol = %d, Selisih = %d\n", InfoTeam(O), Skor(O), Gol(O), Selisih(O));
	
	GroupWinner(A, &P, &Q);
	printf("\nJuara Grup\n");
	printf("Team = %s, Skor = %d, Gol = %d, Selisih = %d\n", InfoTeam(P), Skor(P), Gol(P), Selisih(P));
	printf("Team = %s, Skor = %d, Gol = %d, Selisih = %d\n", InfoTeam(Q), Skor(Q), Gol(Q), Selisih(Q));
	return 0;
}
