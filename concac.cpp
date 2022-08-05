#include <stdio.h>

void docTTmotSV(SV sv, FILE *f)
{
    fscanf(f,"%s",sv.ten);
    ...
    ...
    ..

}


void readFile(FILE *f, char *fname, LinkedList * list)
{
    f = fopen(fname,"r");
    if(f!=NULL)
    {
        while(!feof)
        {
            SV sv;
            docTTmotSV(sv,f);
            addTail(list,sv);
        }
    }
    fclose(f);
}
    