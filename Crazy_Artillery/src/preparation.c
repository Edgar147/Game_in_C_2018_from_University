#include "preparation.h"
#include <stdlib.h>
#include <stdio.h>


void nbChar(int niveau, int *nbpetit, int *nbmoyen, int *nbgrand, int *nbboss)
{
	//Le nombre de char pour chaque taille est d�fini al�atoirement
	// et le nombre max de char possible augmente � chaque niveau


	int Nbchar = 5+5*niveau;
	int min = 7 + 2 * (niveau - 1);

	if ((niveau % 5) == 0)
	{
		(*nbboss) = (niveau / 5);
	}
	else
	{
		(*nbboss) = 0;
	}


	(*nbpetit) = nbAlea(min, Nbchar - 2 * niveau-(*nbboss));
	if ((*nbpetit) != Nbchar)
	{
		(*nbmoyen) = nbAlea(2 * niveau - (*nbboss), Nbchar - (*nbpetit));
	}
	(*nbgrand) = Nbchar - ((*nbpetit) + (*nbmoyen));


}

int nbAlea(int min, int max)
{
	srand(time(NULL));
	return (min + (rand() % (max - min + 1)));

}

