#include "liste.h"
#include <stdlib.h>
#include <stdio.h>


liste_t consVide(){
	//Rôle: constitue une liste vide

	return NULL;
}

int estVide( liste_t L){
	//Rôle: Vérifie si une liste Liste L estVide return Vrai si c'est le cas sinon Faux
	if (L == NULL)
	{
		return True;
	}
	else
	{
		return False;
	}

}

liste_t cons (liste_t  L,elm V){
	//Rôle: ajoute un élement en tête d'une liste puis retourne la liste ainsi formé

	liste_t tete=(liste_t)malloc(sizeof(elem_list_t));
	tete->val=V;
	tete->suc=L;
	return tete;
}

elm Tete(liste_t Liste){
	//Rôle: permet d'accéder à la première valeur d'une liste(celle en tête)
	return Liste->val;
}

liste_t Reste(  liste_t Liste){
	//Rôle: return le reste de la liste


	return Liste->suc;


}

liste_t Inserer(liste_t* L, elm ins, int pos){
	//Insere un élément dans une liste à la position pos
	//On suposse que pos est valide

	if(pos!=1){

		liste_t L1 = Reste(*L);
		elm elm1 = Tete(*L);
		liste_t L2 = Inserer(&L1, ins, pos - 1);
		return cons(&L2, elm1);

	}
	else
	{
		return cons(&(*L), ins);
	}

}

void ModifTete(liste_t* L, elm valeur)
{
    (*L)->val=valeur;
}


void ModifReste(liste_t *L,liste_t NL){

(*L)->suc=NL;

}

void Liberer(liste_t L)
{
    if(estVide(L)!=True)
    {
        liste_t Next=Reste(L);
        free(L);
        Liberer(Next);
    }

}


liste_t SupprimerNoeud(liste_t L,int pos){


if(pos!=1){
    liste_t LI2;
    LI2=SupprimerNoeud(Reste(L),pos-1);
    ModifReste(&L,LI2);
    return L;
}
else{
    liste_t LI;
    LI=Reste(L);
    ModifReste(&L,consVide());
    free(L);
    return LI;
}






}






/*
void SupprimerNoeud(liste_t *L,int pos)
{
    liste_t LI=Reste(L);
    if(pos==2)
    {
        if(estVide(Reste(Reste(*L)))==False)
        {

                (*L)->suc=Reste(Reste(*L));
        }
        else
        {
            (*L)=consVide();
        }

    }

    if(pos!=1)
    {
        SupprimerNoeud(LI,pos-1);
    }
    else if(pos==1)
    {
        (*L)->suc=consVide();
        free(L);
    }
}
*/
