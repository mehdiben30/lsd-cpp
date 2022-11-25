# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
# endif

struct cellule
{
char  element;
struct cellule * suivant;
};
typedef struct cellule cellule;
typedef struct cellule * liste;


char	*readline(int fd);
//void intoline(int fd, liste leftovers);
void ajoutDebut(int x,liste *L);
void ajoutFin(int x,liste *L);
void suppressionDebut(liste *L);
int recherche(char,liste);
void affichageListe(liste L);
int lenCharP(char *buffer); // return the len of a char *
int testBSN(liste leftovers); //return 1 if \n is in the buffer
unsigned longueur(liste L);