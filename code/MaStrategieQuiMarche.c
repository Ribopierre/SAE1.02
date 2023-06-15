#include <stdio.h>
#include <stdlib.h>

#define LIGNE 6
#define COLONNE 7

typedef int t_grille[LIGNE][COLONNE];

int main(int argc, char** argv);
void chargerGrille(char** argv, t_grille Grille);

const int VIDE = 0;
const int JOUEUR = 1;
const int ADVERSAIRE = 2;

    int strategie1 (t_grille laGrille);
    int focus(t_grille laGrille);
    int startegie2 (t_grille laGrille);
    int premiercoup(t_grille laGrille);
    int deuxtrou(t_grille laGrille);
    int strat5(t_grille laGrille);
    int strat6(t_grille laGrille);
    int deuxpions(t_grille laGrille);
    int fullstrat(t_grille laGrille);

/*
* VOTRE STRATEGIE
*/
int maStrategie(t_grille Grille)
{
    // TODO: Votre strategie de victoire. La seule fonction que vous aurez à modifier.
    // libre à vous d'en créer d'autres pour aérer votre code. 
    // La variable Grille est un tableau à deux dimensions d'entiers, c'est la Grille du tour. 
    // Un VIDE représente une case vide, 1 représente vos jetons et 2 représente les jetons adverses.
    // A vous de choisir le meilleur prochain coup !
    int sol;
        sol=deuxpions(Grille);
        if(sol=-1)
        {
            sol=strat6(Grille);
        }
        if (sol=-1)
        {
            sol=strat5(Grille);
        }
        if (sol=-1)
        {
            sol=deuxtrou(Grille);
        }
        if (sol=-1)
        {
            sol=premiercoup(Grille);
        }
        if (sol=-1)
        {
            sol=focus(Grille);
        }
        if (sol=1)
        {
            sol=startegie2 (Grille);
        }
        if (sol=-1)
        {
        sol=strategie1 (Grille);
        }
        return sol;
    
}

// La fonction principale reçoit la Grille du tour et retourne le coup choisi
// Vous n'avez pas à modifier cette fonction
int main(int argc, char** argv) 
{
    t_grille Grille;

    chargerGrille(argv, Grille);

    return maStrategie(Grille);
}

// Charge la Grille du tour actuel
// Vous n'avez pas à modifier cette fonction
void chargerGrille(char** argv, t_grille Grille) 
{
    for(int i = 0; i < LIGNE; i++)
        for(int j = 0; j < COLONNE; j++)
            Grille[i][j] = atoi(argv[i * COLONNE + j + 1]);
}

    int remplissage(t_grille Grille){
        int j, i, nombre;
        i=0;
        nombre=0;
        for ( j = 0; j < LIGNE; j++)
        {
            if (t_grille[i][j]==VIDE)
            {
                nombre=nombre+1;
            }
            
        }
        return nombre;
    }

    int strategie1 (t_grille Grille){                      //Sert trouver ligne max
        int i, maxn, maxt, res;
        maxt=0;
        for ( i = 0; i < COLONNE; i++)
        {
            maxn=remplissage(Grille);
            if (maxn>maxt)
            {
                maxt=maxn;
                res=i;
            }
            
        }
        return res;
    }

    int startegie2 (t_grille Grille){                       //Sert a bloqué 
        int i, j, res;
        for ( i = 0; i < COLONNE; i++)
        {
            if (Grille[i]==Grille[i+1]==Grille[i+2]&&(Grille[i+3]==VIDE))  {
                res=i+3;  
            }
            if (Grille[i]==Grille[i+1]==(Grille[i+3])&&Grille[i+2]==VIDE){
                res=i+2;
            }
            if (Grille[i]==(Grille[i+3])==Grille[i+2]&&(Grille[i+1]==VIDE)){
                res=i+1;
            }
            if ((Grille[i]==VIDE)&&(Grille[i+1]==Grille[i+2]==(Grille[i+3]))){
                res=i;
            }
            if (Grille[j]==Grille[j+1]==Grille[j+2]&&(Grille[j+3]==VIDE)){
                res=i;
            }
            if (Grille[j]==Grille[j+1]==(Grille[j+3])&&(Grille[j+2])==VIDE){
                res=i;
            }
            for ( j = 0; j < LIGNE; j++)
            {        
                if ((Grille[j]==(Grille[j+3]))==Grille[j+2]&&(Grille[j+1]==VIDE)){
                    res=i;
                }
                if ((Grille[j]==VIDE)&&(Grille[j+1]==Grille[j+2]==(Grille[j+3]))){
                    res=i;
                }
                if (Grille[i][j]=Grille[i-1][j+1]=Grille[i-2][j+2]&&(Grille[i-3][j+3]==VIDE)){
                    res=i;
                }
                if (Grille[i][j]=Grille[i-1][j+1]=(Grille[i-2][j+3])&&(Grille[i-3][j+2])==VIDE){
                    res=i;
                }
                if (Grille[i][j]=(Grille[i-1][j+3])=Grille[i-2][j+2]&&Grille[i-3][j+1]==VIDE){
                    res=i;
                }
                if ((Grille[i][j]=VIDE)&&(Grille[i-1][j+1]=Grille[i-2][j+2]=(Grille[i-3][j+3]))){
                    res=i;
                }
                if (Grille[i][j]=Grille[i-1][j+1]=Grille[i-2][j+2]&&(Grille[i-3][j+3]==VIDE)){
                    res=i;
                }
                if (Grille[i][j]=Grille[i-1][j-1]=(Grille[i-2][j-3])&&(Grille[i-3][j-2])==VIDE){
                    res=i;
                }
                if (Grille[i][j]=(Grille[i-1][j-3])=Grille[i-2][j-2]&&(Grille[i-3][j-1])==VIDE){
                    res=i;
                }
                if ((Grille[i][j]=VIDE)&&(Grille[i-1][j-1]=Grille[i-2][j-2]=(Grille[i-3][j-3]))){
                    res=i;
                }
            }  
        }
        return res;
    }

    int focus(t_grille Grille){
            int res, colrenv, i; //colrenv correspond à la
            i=res;
            while (i!=0)      //colonne ou va se placer le 
            {                 //pions
                if (res==5)
                {
                    i=i-3;
                }
                else if (res==3)
                {
                    i=i+2;
                }
                else if (res==6)
                {
                    i=i-5;
                }
                else if (res==2)
                {
                    i=i+4;
                }
                else if (res==7)
                {
                    i=i-7;
                }
                else if (res==1)
                {
                    i=i-2;
                }
                colrenv=i;
                i++;
            }
            return colrenv;
    }

    int premiercoup(t_grille Grille){
        int res, i, j, ici;
        ici=1;
        if (ici<=4 && ici>0)
        {
            while (Grille[i][j]==VIDE)
            {
                i++;
                j++;
            }
            if (i==3)
            {
                res = i;
            }
            if (i==2)
            {
                res = 4;
            }
            if (i==1)
            {
                res = 5;
            }
            if (i==0)
            {
                res = 6;
            }
            if (i==4)
            {
                res = 2;
            }
            if (i==5)
            {
                res = 1;
            }
            if (i==6)
            {
                res = 0;
            }
            ici++;
        }
        if (ici==0)
        {
            res=3;
        }
                    
    }

    int deuxtrou(t_grille Grille){
        int i, j, res;
        for ( i = 0; i < COLONNE; i++)
        {
            for ( j = 0; j < LIGNE; i++)
            {
                if (Grille[i]==Grille[i+2])
                {
                    res=Grille[i+1];
                }
                
            }
            
        }
        return res;
    }

    //Si il y a 5 colonne vide à la même ligne, l’algo place deux pions séparé par un vide 
    //(comme cela |X|’  ‘|X|) avec une colonne vide de chaque côté, il joue le deuxième pions 
    //donc a 2 case du premier
    int strat5(t_grille Grille){
        int i, res;
        for ( i = 0; i < 3; i++)
        {   
            if (Grille[i]==VIDE&&Grille[i+1]==VIDE&&Grille[i+2]==VIDE&&Grille[i+3]==VIDE&&Grille[i+4]==VIDE)
            {
                res=i+1;
            }
            else if (Grille[i]==VIDE&&Grille[i+1]!=VIDE&&Grille[i+2]==VIDE&&Grille[i+3]==VIDE&&Grille[i+4]==VIDE)
            {
                res=1+3;
            }
            
        }
        return res;
    }

    //Si l’adversaire a un pions collé a un pion de l'algorithme, 
    //l’algo place un pions sur celui de l’adversaire ayant pour but de faire une diagonale.

    int strat6(t_grille Grille){
        int i, res;
        i=1;
        while (Grille[i]!=Grille[i+1]&&Grille[i]!=VIDE&&Grille[i+1]==VIDE&&i<=COLONNE)
        {
            
            i++;
        }
        res=i;
        if (res==8)
        {
            res=-1;
        }
        
    }

    //Si le joueur place deux pions l’un à côté de l'autre 
    //l’algorithme place un pion sur le haut du second

    int deuxpions(t_grille Grille){
        int i, j, res;
        i=0;
        j=0;
        while (Grille[i]!=Grille[i+1]&&Grille[i]!=VIDE&&i<=6) //Ici je met 6 en max car
        {                                           //Il y a 2 pions à analyser
            while (Grille[i][j]!=Grille[i+1][j]&&Grille[i][j]!=VIDE)
            {
                j++;
            }
            i++;
        }
        res=i;
        if (res==7)
        {
            res=-1;
        }
        
    }