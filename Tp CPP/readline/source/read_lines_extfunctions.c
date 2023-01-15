#include "../include/read_lines.h"


// add an element in the beginning of a list
void ajoutDebut(int x,liste *L)
{
    cellule * C=(cellule *)malloc(sizeof(cellule));
    C->element=x;
    C->suivant=*L;
    *L=C;
}

// add an element in the end of a list
void ajoutFin(int x,liste *L)
{
    cellule * C=(cellule *)malloc(sizeof(cellule));
    C->element=x;
    C->suivant=NULL;
    if(*L==NULL)
        *L=C;
        else
    {
        liste temp=*L;
        while(temp->suivant!=NULL)
        {
            temp=temp->suivant;
        }
        temp->suivant=C;
        return;
}
}

// remove the first element of a list
void suppressionDebut(liste * L)
{
    if(L!=NULL)
    {
        liste temp=*L;
        *L=(*L)->suivant;
        free(temp);
    }
    return;
}

// display the elements of a list
void affichageListe(liste L)
{
    if(L==NULL)
        printf("[ ]");
    else
    {
        printf("[");
        liste temp=L;
        while(temp->suivant!=NULL)
        {
            printf("%c ",temp->element);
            temp=temp->suivant;
        }
        if(temp!=NULL)
            printf("%c",temp->element);
        printf("]\n");
    }
}

// useless : return the len of a char *
int lenCharP(char *buffer)
{
    int k=0;
    while(buffer[k]!='\0') //\0 end of char *
    {
        k++;
    }
    return k;
}


//return -1 if \n is not in the buffer, else it returns the index of \n
int testBSN(liste leftovers)
    {
        liste temp= leftovers;
        int a=-1;
        int i=0;
        while(temp!=NULL)
        {
            if(temp->element == '\n')
              {
                 a=i;
                 break;
              } 

            i++;
            temp=temp->suivant;
        }
    return a;
    }
// A supprimer ?


// useless : return the position of an element in a list
int recherche(char x,liste L)
{
    liste temp=L;
    int k=0;
    while(temp!=NULL)
    {
        if(temp->element==x)
            return k;
        else
            temp=temp->suivant;
            k++;
    }
    return 0;
}

unsigned longueur(liste L)
{
    unsigned l=0;
    if(L!=NULL)
    {
        liste temp=L;
        while(temp!=NULL)
        {
            l+=1;
            temp=temp->suivant;
        }
    }
    return l;
}
