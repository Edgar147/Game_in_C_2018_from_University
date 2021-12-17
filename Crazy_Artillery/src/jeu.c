#include "jeu.h"
#include "preparation.h"
#include "liste.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h> //atan()
#define TEMPSP 10
#define TEMPSM 30
#define TEMPSG 50
#define TEMPSB 100
# define TEMPSAVION 50000
#define TEMPSBOMB 25000
#define posX 700
#define posY 384


void Commencement()
{
    //Initialisation des pointeurs SDL à NULL
    SDL_Surface *ecran = NULL, *imageDeFond = NULL,*Sol=NULL,*Base=NULL,*Canon=NULL,*rotation=NULL,*Ball=NULL,*Chare=NULL,*Drapeau=NULL,*Debut=NULL,*DefaiteIm=NULL,*Fin=NULL;

    SDL_Surface *Niv1=NULL,*Niv2=NULL,*Niv3=NULL,*Niv4=NULL,*NivBoss=NULL,*Dispo=NULL;

  SDL_Surface *AvioEnem=NULL,*AvioAide=NULL,*BombAvio=NULL,*BombAide=NULL;

    SDL_Surface *Moyen=NULL,*Grand=NULL,*Boss=NULL;
    SDL_Rect positionFond,positionSol,positionBase,positionCanon,positionBall,positionChare,positionDrapeau,positionDebut,positionDefaite,positionFin;


        SDL_Rect posAvioEnem,posAvioAide,posBombAvio,posBomb,posDispo;



    SDL_Rect posNiv1,posNiv2,posNiv3,posNiv4,posNivBoss;

    SDL_Rect chare;


    Booll a=False; //booléen qui permet de savoir si le tir est au milieu
    double angle = 30;// L'angle de positionnement du canon
    int continuer = True;
    int x1=0,y1=0;


    elm NE;

    int tempsPrecedentP = 0,tempsPrecedentM = 0,tempsPrecedentG = 0,tempsPrecedentB = 0, tempsActuel=0,tempsChare1=0,tempsChare2=0;
    int tempsAvion=0,tempBomb=0;

    positionDrapeau.y=posY;
     positionDrapeau.x=150;

    positionBall.x=83;
    positionBall.y=428;
    positionFond.x = 0;
    positionFond.y = 0;
    positionSol.x=0;
    positionSol.y=400;
    positionBase.x=10;
    positionBase.y=384;
    positionChare.y=350;

posDispo.x=0;
posDispo.y=0;

    positionDebut.x=0;
    positionDebut.y=0;
    positionDefaite.x=0;
    positionDefaite.y=0;
    positionFin.x=0;
    positionFin.y=0;




    posNiv1.x=425;
    posNiv1.y=5;
    posNiv2.x=425;
    posNiv2.y=5;
    posNiv3.x=425;
    posNiv3.y=5;
    posNiv4.x=425;
    posNiv4.y=5;
    posNivBoss.x=425;
    posNivBoss.y=5;


Niv1=IMG_Load("ImageNiveau1.png");
Niv2=IMG_Load("ImageNiveau2.png");
Niv3=IMG_Load("ImageNiveau3.png");
Niv4=IMG_Load("ImageNiveau4.png");
NivBoss=IMG_Load("ImageNiveauBoss.png");



    posAvioAide.x=0;
    posAvioAide.y=100;
    posAvioEnem.x=1000;
    posAvioEnem.y=100;
    posBombAvio.y=100;
    posBomb.x=750;
    posBomb.y=200;

AvioAide=IMG_Load("AvionAide.png");
AvioEnem=IMG_Load("AvionEnemie.png");
BombAvio=IMG_Load("BombAvion.png");
BombAide=IMG_Load("Bomb.png");


    //positionCanon.x=20;
    //positionCanon.y=300;
    SDL_Init(SDL_INIT_VIDEO);
    ecran = SDL_SetVideoMode(1000, 500, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("Jeu", NULL);
    Canon=IMG_Load("Howitzer_Canon3.png");
     Base=IMG_Load("HowitzerBase.png");
    imageDeFond = IMG_Load("Fond.jpg");
    Chare=IMG_Load("Chare.png");
    Moyen=IMG_Load("CharMoyen.png");
    Grand=IMG_Load("CharGrand.png");
    Boss=IMG_Load("CharBoss.png");

    Sol=IMG_Load("Sol.png");

    Drapeau=IMG_Load("ImageDrapeau.png");
    Ball=IMG_Load("Ball2.png");


      Debut=IMG_Load("ImageDebut.png");
      DefaiteIm=IMG_Load("ImageDefaite.png");
Dispo=IMG_Load("Dispo.png");


    SDL_Event event;

    chare.y=posY;
    int Rejouer=True;
    int commencer=False;

    while(commencer==False)
    {
        SDL_BlitSurface(Debut,NULL, ecran, &positionDebut);
        SDL_Flip(ecran);
                    SDL_PollEvent(&event);
                    switch(event.type)
                    {
                        case SDL_KEYDOWN:

                            switch(event.key.keysym.sym)
                            {
                            case SDLK_c:
                                commencer=True;
                                break;
                            case SDLK_x:
                                Rejouer=False;
                                commencer=True;
                                break;

                            default:
                                break;
                            }
                            break;
                        default:
                            break;
                    }
    }
    int Defaite=False;

    while(Rejouer!=False)
    {
        // INITIALISATION DE TOUT LES TEMPS PRéCéDENT PAR SDL GET TICKS
        int niveau=0;
        liste_t listePetit=consVide();
        liste_t listeMoyen=consVide();
        liste_t listeGrand=consVide();
        liste_t listeBoss=consVide();

    int Victoire=False;
    int appAV=False;
    posAvioEnem.x=1000;
    posBombAvio.y=100;
    posAvioAide.x=0;
    int Bomb=False;

    while((Defaite!=True)&&(Victoire==False))
    {
        int nbcharpet;
        int nbMoyen;
        int nbGrand;
        int nbBoss;
        continuer=True;

        SDL_Flip(ecran);
        niveau=niveau+1;





        if(niveau>5)
        {
            continuer=False;
            Victoire=True;
        }
        else
        {
            nbChar(niveau,  &nbcharpet,  &nbMoyen,  &nbGrand, &nbBoss);
        }
        int Av=False;
        int bombdisp=False;
        int lancerbomb=False;
        while (continuer==True)
        {

                tempsActuel = SDL_GetTicks();
                tempsChare1=SDL_GetTicks();

                if(tempsActuel-tempBomb>TEMPSBOMB)
                {
                    tempBomb=tempsActuel;
                    bombdisp=True;
                }

                if((tempsActuel-tempsAvion>TEMPSAVION)&&(Av==False)){

                    tempsAvion=tempsActuel;
                    Av=True;
                }







                liste_t LIP;
                elm NV;
                if ((tempsActuel - tempsPrecedentP > TEMPSP)&& (estVide(listePetit)==False)) // on deplace les char petits
                {
                    LIP=listePetit;
                    while (estVide(LIP)!=True)
                    {
                        NV=Tete(LIP);
                        NV.posx=NV.posx-1;
                        ModifTete(&LIP,NV);
                        LIP=Reste(LIP);
                        //positionChare.x=positionChare.x-1;

                    }
                     tempsPrecedentP = tempsActuel;
                }
                if ((tempsActuel - tempsPrecedentM > TEMPSM)&& (estVide(listeMoyen)==False)) // on deplace les char moyens
                {
                    LIP=listeMoyen;
                    while (estVide(LIP)!=True)
                    {

                        NV=Tete(LIP);
                        NV.posx=NV.posx-1;
                        ModifTete(&LIP,NV);
                        LIP=Reste(LIP);
                        //positionChare.x=positionChare.x-1;
                    }
                     tempsPrecedentM = tempsActuel;
                }

                if ((tempsActuel - tempsPrecedentG > TEMPSG)&& (estVide(listeGrand)==False)) // on deplace les char grand
                {
                    LIP=listeGrand;
                    while (estVide(LIP)!=True)
                    {

                        NV=Tete(LIP);
                        NV.posx=NV.posx-1;
                        ModifTete(&LIP,NV);
                        LIP=Reste(LIP);
                        //positionChare.x=positionChare.x-1;

                    }
                     tempsPrecedentG = tempsActuel;
                }

                 if ((tempsActuel - tempsPrecedentB > TEMPSB)&& (estVide(listeBoss)==False)) // on deplace les char Boss
                {
                    LIP=listeBoss;
                    while (estVide(LIP)!=True)
                    {

                        NV=Tete(LIP);
                        NV.posx=NV.posx-1;
                        ModifTete(&LIP,NV);
                        LIP=Reste(LIP);
                        //positionChare.x=positionChare.x-1;

                    }
                     tempsPrecedentB = tempsActuel;
                }




                if(tempsChare1-tempsChare2>4000){ // on fait apparaitre un char en plus
                    NE.posx=posX;
                    if(nbcharpet>0)// on fait appaitre un nouveau char petit s'il en reste
                    {
                        NE.vie=1;
                        listePetit =cons(listePetit,NE);
                        nbcharpet=nbcharpet-1;
                    }
                    else if (nbMoyen>0)// on fait appaitre un nouveau char moyen s'il en reste
                    {
                        NE.vie=2;
                        listeMoyen =cons(listeMoyen,NE);
                        nbMoyen=nbMoyen-1;
                    }
                    else if (nbGrand>0)// on fait appaitre un nouveau char grand s'il en reste
                    {
                        NE.vie=3;
                        listeGrand =cons(listeGrand,NE);
                        nbGrand=nbGrand-1;
                    }
                    else if(nbBoss>0) // on fait appaitre un nouveau char Boss s'il en reste
                    {
                        NE.vie=5;
                        listeBoss =cons(listeBoss,NE);
                        nbBoss=nbBoss-1;
                    }
                    tempsChare2=tempsChare1;
                    // nb de char restant voir dans preparation.c

                }



                SDL_PollEvent(&event);
                switch(event.type)
                {
                    case SDL_QUIT:
                        continuer = False;
                        break;



                    case SDL_KEYDOWN:

                        switch(event.key.keysym.sym)
                        {

                        case SDLK_p:

                            if(Av==True)
                            {
                                    appAV=True;
                            }
                            break;
                        case SDLK_b:
                            if(bombdisp==True)
                            {
                                lancerbomb=True;
                            }
                            break;





                            case SDLK_x:

                      continuer=False;
                      Defaite=True;
                                break;





                            case SDLK_r:

                               a=False;


                            x1=0,y1=0;
                                  positionBall.x=83;
                                positionBall.y=428;
                                break;

                            case SDLK_UP:
                               angle=angle+1;
                              if(angle>55)
                                angle=55;
                                break;

                            case SDLK_DOWN: //
                                angle=angle-1;
                                if(angle<25)
                                angle=25;
                                break;
                            default:
                                break;
                        }
                   break;
                   case SDL_KEYUP:

                        switch(event.key.keysym.sym)
                        {





                            case  SDLK_SPACE:
                            a=False;

                            continuer = True;
                            x1=0,y1=0;

                            x1=(angle-10)*25;//on doit pas arriver a la fin avec le tire;;;tricherie pour cela...873

                            if((positionBall.x<x1/2) && (a==False)){
                                positionBall.x=positionBall.x+15;
                                positionBall.y=positionBall.y-15;//=(int)(-(g/2)*(pow(positionBall.x-15,2)/(pow(v,2)*pow(cos(angle*3.14/180),2)))+tan(angle*3.14/180)*(positionBall.x-15)+450);
                            }
                            else{
                                a=True;
                                if(positionBall.y<500){
                                positionBall.x=positionBall.x+15;
                                positionBall.y=positionBall.y+15;
                                }


                            }
                            liste_t LIP3;
                            int pos;
                            if (estVide(listePetit)==False)
                            {
                                LIP3=listePetit;
                                pos=1;
                                while(estVide(LIP3)!=True)
                                {

                                    if((positionBall.x<Tete(LIP3).posx+150)&&(positionBall.x>Tete(LIP3).posx)&&(positionBall.y>posY)&&(positionBall.y<posY+69))
                                    {
                                        LIP3=consVide();
                                        listePetit=SupprimerNoeud(listePetit,pos);

                                    }
                                    else
                                    {
                                         LIP3=Reste(LIP3);
                                         pos=pos+1;
                                    }

                                }

                            }


                            elm NVE;
                            if (estVide(listeMoyen)==False)
                            {
                                LIP3=listeMoyen;
                                pos=1;
                                while(estVide(LIP3)!=True)
                                {

                                    if((positionBall.x<Tete(LIP3).posx+160)&&(positionBall.x>Tete(LIP3).posx)&&(positionBall.y>posY)&&(positionBall.y<posY+59))
                                    {
                                        NVE.vie=(Tete(LIP3).vie)-1;
                                        NVE.posx=Tete(LIP3).posx;
                                        ModifTete(&LIP3,NVE);
                                        if(Tete(LIP3).vie==0)
                                        {
                                            listeMoyen=SupprimerNoeud(listeMoyen,pos);
                                        }
                                        LIP3=consVide();
                                        positionBall.x=2000;
                                        positionBall.y=2000;

                                    }
                                    else
                                    {
                                         LIP3=Reste(LIP3);
                                         pos=pos+1;
                                    }

                                }

                            }




                            if (estVide(listeGrand)==False)
                            {
                                LIP3=listeGrand;
                                pos=1;
                                while(estVide(LIP3)!=True)
                                {

                                    if((positionBall.x<Tete(LIP3).posx+200)&&(positionBall.x>Tete(LIP3).posx)&&(positionBall.y>posY)&&(positionBall.y<posY+67))
                                    {
                                        NVE.vie=(Tete(LIP3).vie)-1;
                                        NVE.posx=Tete(LIP3).posx;
                                        ModifTete(&LIP3,NVE);
                                        if(Tete(LIP3).vie==0)
                                        {
                                            listeGrand=SupprimerNoeud(listeGrand,pos);
                                        }
                                        LIP3=consVide();
                                        positionBall.x=2000;
                                        positionBall.y=2000;

                                    }
                                    else
                                    {
                                         LIP3=Reste(LIP3);
                                         pos=pos+1;
                                    }

                                }

                            }


                            if (estVide(listeBoss)==False)
                            {
                                LIP3=listeBoss;
                                pos=1;
                                while(estVide(LIP3)!=True)
                                {

                                    if((positionBall.x<Tete(LIP3).posx+250)&&(positionBall.x>Tete(LIP3).posx)&&(positionBall.y>posY)&&(positionBall.y<posY+98))
                                    {
                                        NVE.vie=(Tete(LIP3).vie)-1;
                                        NVE.posx=Tete(LIP3).posx;
                                        ModifTete(&LIP3,NVE);
                                        if(Tete(LIP3).vie==0)
                                        {
                                            listeBoss=SupprimerNoeud(listeBoss,pos);
                                        }
                                        LIP3=consVide();
                                         positionBall.x=2000;
                                        positionBall.y=2000;

                                    }
                                    else
                                    {
                                         LIP3=Reste(LIP3);
                                         pos=pos+1;
                                    }

                                }

                            }



                            SDL_BlitSurface(Ball,NULL, ecran, &positionBall);
                            break;

                            default:
                                break;
                        }

                    default:
                        break;
                }



                rotation = rotozoomSurface(Canon, angle, 1.0, 1);
                positionCanon.x =  80-rotation->w/2;
                positionCanon.y = 420-rotation->h/2;

                SDL_BlitSurface(rotation , NULL, ecran, &positionCanon); //On affiche la rotation de la surface image.
                  SDL_BlitSurface(Base,NULL, ecran, &positionBase);
                SDL_FreeSurface(rotation); //On efface rotation car on va la redéfinir dans la prochaine boucle. Si on ne le fait pas, cela crée une fuite de mémoire.




                SDL_Flip(ecran);




                //
            SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
            SDL_BlitSurface(Sol, NULL, ecran, &positionSol);
        SDL_BlitSurface(Drapeau, NULL, ecran, &positionDrapeau);


            /*elm V1;
            V1.posx=posX-400;
            listeMoyen=cons(listeMoyen,V1);

            elm V2;
            V2.posx=posX;
            listeMoyen=cons(listeMoyen,V2);

            SDL_Rect chare;
            chare.x=Tete(listeMoyen).posx;
            chare.y=posY;
            SDL_BlitSurface(Chare, NULL, ecran, &chare);

            listeMoyen=Reste(listeMoyen);
            chare.x=Tete(listeMoyen).posx;
            chare.y=posY;
            SDL_BlitSurface(Chare, NULL, ecran, &chare);
        */

            liste_t LIP2;
            LIP2=listePetit;
            while (estVide(LIP2)!=True) // tant que la liste n'est pas vide(permet de faire apparaitre tout les chars de la liste)
            {

                chare.x=Tete(LIP2).posx;
                SDL_BlitSurface(Chare, NULL, ecran, &chare);
                LIP2=Reste(LIP2);
            }
            LIP2=listeMoyen;
            while (estVide(LIP2)!=True) // tant que la liste n'est pas vide(permet de faire apparaitre tout les chars de la liste)
            {

                chare.x=Tete(LIP2).posx;
                SDL_BlitSurface(Moyen, NULL, ecran, &chare);
                LIP2=Reste(LIP2);
            }
            LIP2=listeGrand;
            while (estVide(LIP2)!=True) // tant que la liste n'est pas vide(permet de faire apparaitre tout les chars de la liste)
            {

                chare.x=Tete(LIP2).posx;
                SDL_BlitSurface(Grand, NULL, ecran, &chare);
                LIP2=Reste(LIP2);
            }
            LIP2=listeBoss;
            while (estVide(LIP2)!=True) // tant que la liste n'est pas vide(permet de faire apparaitre tout les chars de la liste)
            {
                chare.x=Tete(LIP2).posx;
                SDL_BlitSurface(Boss, NULL, ecran, &chare);
                LIP2=Reste(LIP2);
            }
            if(Av==True)
            {
                SDL_BlitSurface(AvioEnem,NULL, ecran, &posAvioEnem);
                posAvioEnem.x=posAvioEnem.x-2;
                if(posAvioEnem.x<positionDrapeau.x+50)
                {

                    posBombAvio.x=posAvioEnem.x;
                    Bomb=True;
                }
            }
            if((appAV==True)&&(Bomb==False))
            {
                SDL_BlitSurface(AvioAide,NULL, ecran, &posAvioAide);
                posAvioAide.x=posAvioAide.x+2;
                if(posAvioAide.x>positionDrapeau.x)
                {
                    Av=False;
                    appAV=False;
                    posAvioEnem.x=1000;
                    posAvioAide.x=0;
                }
            }
            if(posAvioEnem.x<positionDrapeau.x+50)
            {
                SDL_BlitSurface(BombAvio,NULL, ecran, &posBombAvio);
                posBombAvio.y=posBombAvio.y+5;
                posBombAvio.x=posBombAvio.x+5;
            }
            if(posBombAvio.y>posY)
            {
                Defaite=True;
                continuer=False;
            }
            if(lancerbomb==True)
            {
                SDL_BlitSurface(BombAide,NULL, ecran, &posBomb);
                posBomb.y=posBomb.y+10;
            }
            if(posBomb.y>posY)
            {
                posBomb.y=200;
                lancerbomb=False;
                bombdisp=False;
                Liberer(listePetit);
                Liberer(listeMoyen);
                Liberer(listeGrand);
                Liberer(listeBoss);
                listePetit=consVide();
                listeMoyen=consVide();
                listeGrand=consVide();
                listeBoss=consVide();
            }
            if(bombdisp==True)
            {
               // SDL_Rect test;
                //test.x=0;
               // test.y=0;
                SDL_BlitSurface(Dispo,NULL, ecran, &posDispo);// A LA PLACE DE NIVEAU 2,MET L IMAGE QUI AFFICHE LA DISPO DE BOMB
            }

            switch(niveau){

        case 1:
            SDL_BlitSurface(Niv1,NULL, ecran, &posNiv1);

        break;

        case 2:
            SDL_BlitSurface(Niv2,NULL, ecran, &posNiv2);
        break;

        case 3:
            SDL_BlitSurface(Niv3,NULL, ecran, &posNiv3);
        break;

        case 4:
            SDL_BlitSurface(Niv4,NULL, ecran, &posNiv4);
        break;
        case 5:
            SDL_BlitSurface(NivBoss,NULL, ecran, &posNivBoss);
        break;

        default:
        break;

        }



             if(((nbcharpet==0)&&(nbMoyen==0) && (nbGrand==0)&&(nbBoss==0))
                &&((estVide(listePetit)==True)&& (estVide(listeMoyen)==True)
                   &&(estVide(listeGrand)==True)&& (estVide(listeBoss)==True)))
            {
                continuer=False;
            }
            else
            {
                LIP2=listePetit;
                while ((estVide(LIP2)!=True)&&(Defaite==False))
                {
                    if(Tete(LIP2).posx<positionDrapeau.x)
                    {
                        Defaite=True;

                        LIP2=consVide();
                        continuer=False;
                    }
                    else
                    {
                        LIP2=Reste(LIP2);
                    }
                }

                LIP2=listeMoyen;
                while ((estVide(LIP2)!=True) &&(Defaite==False))
                {
                    if(Tete(LIP2).posx<positionDrapeau.x)
                    {
                        Defaite=True;

                        LIP2=consVide();
                        continuer=False;
                    }
                    else
                    {
                        LIP2=Reste(LIP2);
                    }
                }

                LIP2=listeGrand;
                while ((estVide(LIP2)!=True)&&(Defaite==False))
                {
                    if(Tete(LIP2).posx<positionDrapeau.x)
                    {
                        Defaite=True;
                        LIP2=consVide();
                        continuer=False;
                    }
                    else
                    {
                        LIP2=Reste(LIP2);
                    }
                }

                LIP2=listeBoss;
                while ((estVide(LIP2)!=True)&&(Defaite==False))
                {
                    if(Tete(LIP2).posx<positionDrapeau.x)
                    {
                        Defaite=True;
                        LIP2=consVide();
                        continuer=False;
                    }
                    else
                    {
                        LIP2=Reste(LIP2);
                    }
                }
                if(Defaite==True)
                {
                    Liberer(listePetit);
                    Liberer(listeMoyen);
                    Liberer(listeGrand);
                    Liberer(listeBoss);
                }

            }




//SDL_BlitSurface(DefaiteIm, NULL, ecran, &positionDefaite);



    }

      // CA NE FONCTIONNE PAS
    }
    if(Defaite==True)
    {
        SDL_BlitSurface(DefaiteIm, NULL, ecran, &positionDefaite);
        SDL_Flip(ecran);
    }
    if(Victoire==True)
        {
            Fin=IMG_Load("ImageFin.png");
            SDL_BlitSurface(Fin, NULL, ecran, &positionFin); posBombAvio.y=100;
            SDL_Flip(ecran);
            Victoire=False;
        }
         int sortir=False;
                while(sortir!=True)
                {
                    SDL_PollEvent(&event);
                    switch(event.type)
                    {
                        case SDL_KEYDOWN:

                            switch(event.key.keysym.sym)
                            {
                            case SDLK_t:
                                Rejouer=True;
                                sortir=True;
                                continuer=True;
                                Defaite=False;
                                break;
                            case SDLK_x:
                                Rejouer=False;
                                sortir=True;
                                break;

                            default:
                                break;
                            }
                            break;
                        default:
                            break;
                    }


                }
    }




    SDL_FreeSurface(Niv1);
    SDL_FreeSurface(Niv2);
    SDL_FreeSurface(Niv3);
    SDL_FreeSurface(Niv4);
    SDL_FreeSurface(NivBoss);
    SDL_FreeSurface(Drapeau);
    SDL_FreeSurface(Debut);
    SDL_FreeSurface(DefaiteIm);
    SDL_FreeSurface(Fin);
    SDL_FreeSurface(AvioEnem);
    SDL_FreeSurface(AvioAide);
    SDL_FreeSurface(BombAvio);
    SDL_FreeSurface(BombAide);
    SDL_FreeSurface(Dispo);
    SDL_FreeSurface(Moyen);
    SDL_FreeSurface(Grand);
    SDL_FreeSurface(Boss);
    SDL_FreeSurface(Debut);
    SDL_FreeSurface(DefaiteIm);
    SDL_FreeSurface(Fin);
    SDL_FreeSurface(Chare);
    SDL_FreeSurface(Canon);
    SDL_FreeSurface(imageDeFond);
    SDL_FreeSurface(Sol);
    SDL_FreeSurface(Base);
    SDL_FreeSurface(Ball);
    SDL_Quit();
}

