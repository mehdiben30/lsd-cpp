#include "../include/read_lines.h"


char *readline(int fd)
{
//declaration of the buffer
    char *buffer = (char *)malloc(BUFFER_SIZE); 
                                                   
//test all problems
    if(read(fd,buffer,0) == -1 || BUFFER_SIZE <=0 || fd < 0  ) //all problems
    {
        return NULL; 
    }

//declaration of the important variables    
    static liste leftovers = NULL;
    char *line;

//filling leftovers with buffer  
    
    while(testBSN(leftovers) == -1)
    {
        int readvalue =(int)read(fd,buffer,BUFFER_SIZE);
        if(readvalue<=0)
            break;
        for(int j=0;j<readvalue;j++)
            {
                ajoutFin(buffer[j],&leftovers);
            }
    }

//so that readline stops if we are at the end of the file before doing useless actions
    if(leftovers == NULL)
        return NULL;

//filling line with the elements of leftovers before '\n' and cleaning leftovers of the elements before \n
//if its de last line it will empty leftovers
    int n=testBSN(leftovers)+1; 
    if(n ==0 ) // case where there's not a \n in leftovers
        n=longueur(leftovers);   
    line = malloc(sizeof(char)*(n+1));
    for(int i=0;i<n;i++)
    {
        line[i] = leftovers->element;
        suppressionDebut(&leftovers);
    }

    line[n]='\0';
    return line;
}


