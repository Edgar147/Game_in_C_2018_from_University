typedef enum { True, False }Booll;

//typedef enum  {Petit,Moyen,Grand,Boss}TailleChar;


typedef struct{
	int posx;
	int vie;
}elm;

typedef struct ellst{
	elm val;
	struct ellst *suc;
}elem_list_t, *liste_t;

liste_t consVide();

liste_t cons( liste_t, elm);

int estVide( liste_t);

elm Tete( liste_t );

liste_t Reste( liste_t );

liste_t Inserer( liste_t*,  elm,  int);

void ModifReste(liste_t*,liste_t);

void Liberer(liste_t);

liste_t SupprimerNoeud(liste_t,int);

void ModifTete(liste_t*, elm);
