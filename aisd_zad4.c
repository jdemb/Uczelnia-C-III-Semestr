#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct elem
{
    char value[5];
    struct elem *prev, *next;
} elem,kopia,scalona;

//////////////////////////////////////////////////////////////////

void wstaw(char *tab, elem **head, elem **tail){
    elem *tmp;	/*wskaznik na nowy element*/
    tmp=(void *)malloc(sizeof(elem));
    tmp->prev = NULL;
    tmp->next = (*head);
    int i;
    for(i=0; i<5; i++)
    tmp->value[i]=tab[i];	 /*przypisanie wartosci dla tmp*/
    if(!(*head))	 /*sprawdzenie czy kolejka byla pusta*/
    {
        (*head) = tmp;	/*przepiecie glowy i ogona na jedyny element*/
        (*tail) = tmp;
    }
    else{
        (*head)->prev=tmp; /*element poprzedni wskazuje na ostatni POPRZEDNI KOLEJNEGO WSKAZUJE NA NOWA WARTOSC */
        (*head) = tmp;	/*przepiecie glowy na element ostatni, */
    }
}

//////////////////////////////////////////////////////////////////

void kasuj(elem **tail, elem **head){
elem *tmp;	/*wskaznik na nowy element*/
*tail=NULL;
*head=NULL;
if(*tail){
    elem *tmp;
    tmp = (*tail);	/* przypisanie tmpowi wartosci tail*/
    (*tail) = tmp->prev;	/* przepiecie tail na element wczesniejszy*/
if((*tail))	/*sprawdza czy po przepieciu tail wskazuje na nulla*/
{
    (*tail)->next = NULL; /*przepiecie tail->next na null*/
}

free(tmp);
}

}

///////////////////////////////////////////////////////////////////

elem* szukaj(elem *tail, char *tab){
  if(!tail)
    {
        printf("kolejka pusta");
        return tail;
    }
    else	/*jesli nie jest pusta*/
    {
        while(tail) /*przechodzimy petla dopoki tail nie wskazuje na null*/
        {
            if(strcmp(tail->value, tab)==0){
            return tail;
            }
            tail = tail->prev; /*przepinamy tail na wczesniejsz element w klejce*/
        }
        return tail;
    }
}

///////////////////////////////////////////////////////////////////////

void usun(char *tab, elem **head){
    if(head == NULL)
    {
        printf("Ta lista jest pusta!\n");
        return;
    }
    elem* first = *head;
    elem* prev;
    elem* tmp = *head;
    while(tmp != NULL)
    {
        if(strcmp(tmp->value, tab)==0)
        {
            if(tmp == *head)
            {
                *head=tmp->next;
                return;
            }

            else
            {
                prev->next = tmp->next;
                free(tmp);
                return;
            }
        }
        else
        {
            prev=tmp;
            tmp = tmp->next;
        }
    }

}

/////////////////////////////////////////////////////////////////////////

void wypisz(elem *head)
{
    if(!head)
    {
        printf("kolejka pusta\n");
    }
    else	/*jesli nie jest pusta*/
    {
        while(head) /*przechodzimy petla dopoki head nie wskazuje na null*/
        {
            printf("%s / ",head->value); /*wypisujemy element*/
            head = head->next; /*przepinamy head na kolejny element w kolejce*/
        }
        printf("");
    }
}

//////////////////////////////////////////////////////////////////////////
void bezpowtorzen(elem *head, elem **head2, elem **tail2)
{
    elem *tmp;
    if(!head)
    {
        printf("kolejka pusta \n");
    }
    else
    {
        while(head) /*przechodzimy petla dopoki head nie wskazuje na null*/
        {
            bool znalazl = 0;
            tmp = head->next;
            while(tmp)
            {
                if(strcmp(head->value, tmp->value)==0)
                {
                    znalazl=1;
                    break;
                }
                tmp = tmp->next;
            }
            if(!znalazl)
            {
                kopia *tmp;	/*wskaznik na nowy element*/
                tmp=(void *)malloc(sizeof(kopia));
                tmp->prev = NULL;
                tmp->next = (*head2);
                int i;
                for(i=0; i<5; i++)
                    tmp->value[i]=head->value[i];	 /*przypisanie wartosci dla tmp*/
                if(!(*head2))	 /*sprawdzenie czy kolejka byla pusta*/
                {
                    (*head2) = tmp;	/*przepiecie glowy i ogona na jedyny element*/
                    (*tail2) = tmp;
                }
                else{
                    (*head2)->prev=tmp; /*element poprzedni wskazuje na ostatni POPRZEDNI KOLEJNEGO WSKAZUJE NA NOWA WARTOSC */
                    (*head2) = tmp;	/*przepiecie glowy na element ostatni, */
                }
            }
            head = head->next; /*przepinamy head na kolejny element w kolejce*/
        }

    }

}

///////////////////////////////////////////////////////////////////////////

void scal(elem *head, elem *head2, elem **head3, elem **tail3)
{
    while(head)
    {
        scalona *tmp;	/*wskaznik na nowy element*/
        tmp=(void *)malloc(sizeof(scalona));
        tmp->prev = NULL;
        tmp->next = (*head3);
        int i;
        for(i=0; i<5; i++)
            tmp->value[i]=head->value[i];	 /*przypisanie wartosci dla tmp*/
        if(!(*head3))	 /*sprawdzenie czy kolejka byla pusta*/
        {
            (*head3) = tmp;	/*przepiecie glowy i ogona na jedyny element*/
            (*tail3) = tmp;
        }
        else{
            (*head3)->prev=tmp; /*element poprzedni wskazuje na ostatni POPRZEDNI KOLEJNEGO WSKAZUJE NA NOWA WARTOSC */
            (*head3) = tmp;	/*przepiecie glowy na element ostatni, */
        }

        head = head->next; /*przepinamy head na kolejny element w kolejce*/
    }
    while(head2)
    {
        scalona *tmp;	/*wskaznik na nowy element*/
        tmp=(void *)malloc(sizeof(scalona));
        tmp->prev = NULL;
        tmp->next = (*head3);
        int i;
        for(i=0; i<5; i++)
            tmp->value[i]=head2->value[i];	 /*przypisanie wartosci dla tmp*/
        if(!(*head3))	 /*sprawdzenie czy kolejka byla pusta*/
        {
            (*head3) = tmp;	/*przepiecie glowy i ogona na jedyny element*/
            (*tail3) = tmp;
        }
        else{
            (*head3)->prev=tmp; /*element poprzedni wskazuje na ostatni POPRZEDNI KOLEJNEGO WSKAZUJE NA NOWA WARTOSC */
            (*head3) = tmp;	/*przepiecie glowy na element ostatni, */
        }

        head2 = head2->next; /*przepinamy head na kolejny element w kolejce*/
    }

}

///////////////////////////////////////////////////////////////////////////

int main()
{
elem *head=NULL;
elem *tail=NULL;

elem *head2=NULL; //do kopii
elem *tail2=NULL;

elem *head3=NULL; //do scalania
elem *tail3=NULL;

char slowo1[5] = "ala";
char slowo2[5] = "ma";
char slowo3[5] = "kota";
char slowo4[5] = "kota";

wstaw(slowo1,&head, &tail);
wstaw(slowo2,&head, &tail);
wstaw(slowo3,&head, &tail);
wstaw(slowo4,&head, &tail);

printf("Wypisuje liste:\n");
wypisz(head);
printf("\n");

printf("Szukam slowa 'ma' \n");
if(szukaj(tail, slowo2))
    printf("znalazlem\n");
else
    printf("nie ma\n");

char slowo5[5] = "kot";
printf("Szukam slowa 'kot' \n");
if(szukaj(tail, slowo5))
    printf("znalazlem\n");
else
    printf("nie ma\n");

printf("bez powtorzen\n");
bezpowtorzen(head,&head2,&tail2);
wypisz(head2);

printf("scalam liste\n");
scal(head,head2,&head3,&tail3);
wypisz(head3);


printf("\nusuwam 'ma'\n");
usun(slowo2,&head);
wypisz(head);
printf("\n");




printf("Kasuje liste:\n");
kasuj(&tail, &head);
wypisz(head);
printf("\n");
/*
printf("\nDodaje 11 i 34 do listy");
wstaw(11,&head, &tail);
wstaw(34,&head, &tail);
printf("\n");
wypisz(tail);
printf("\n\n");
printf("Podaj zmienna do poszukania: \n");
scanf("%d", &zk);
printf("\n");
szukaj(tail, zk);
printf("\n");
wypisz(tail);
kasuj(&tail, &head);
printf("\n");
printf("Wypisuje liste:\n");
wypisz(tail);*/
return 0;
}
