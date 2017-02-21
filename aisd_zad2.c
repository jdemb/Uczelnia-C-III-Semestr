#include <time.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define MLDD 1000000000.0 


void MakeItRandom(int arr[], int liczbaTestow) //creates array of random integers and print them to input.txt
{
	int range = 900;
	srand(time(NULL));
    
    int i;
    for(i=0;i<liczbaTestow;i++)
    {
    arr[i]=rand() % range + 1;
   // printf("%d ", arr[i]);
}
    
}
void MakeItDrop(int arr[], int liczbaTestow) //creates array of decreasing integers and print them to input.txt
{
	
    int i,j=2500;
    for(i=0; i<liczbaTestow; i++)
    {
	
    arr[i]=j;
    j--;
    //printf("%d ", arr[i]);
}
}

void Swap (int tab[], int a, int b)
{
    int x;
    x=tab[a];
    tab[a]=tab[b];
    tab[b]=x;
}

void Quicksort(int arr[], int l, int r)
{
	int i;
	if(l<r)
	{
		i=Partition(arr,l,r);
		Quicksort(arr,l,i);
		Quicksort(arr,i+1,r);
	}
}

int Partition(int arr[], int l, int r)
{
	int indeksPodzialu = arr[r]; 
	int wartoscPodzialu = l-1;
	int j;
	for(j=l; j<=r; j++)
	{
		if(arr[j]<=indeksPodzialu)
		{
			wartoscPodzialu++;
			Swap(arr, wartoscPodzialu, j);
		}
	}
	if(wartoscPodzialu<r) return wartoscPodzialu;
	else return wartoscPodzialu-1;
}

double TimeMeasure(int arr[],int l, int r, bool random, int liczbaTestow)
{
	  struct timespec tp0, tp1;
      double Tn,Fn,x;
      long int n;
      if(!random)
      {
      	
      MakeItDrop(arr,2500); 
      clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&tp0);
	  Quicksort(arr,l,r);
	  clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&tp1);
	  Fn=n*n/450000;
	  Tn=(tp1.tv_sec+tp1.tv_nsec/MLDD)-(tp0.tv_sec+tp0.tv_nsec/MLDD);
	  return Tn;
      }
      else
      {
      	for(n=0;n<liczbaTestow;n++)
      	{
      		
      		MakeItRandom(arr,2500);
      		
      		clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&tp0);
	        Quicksort(arr,l,r);
	        clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&tp1);
	        Fn=n*n/450000;
	        Tn+=(tp1.tv_sec+tp1.tv_nsec/MLDD)-(tp0.tv_sec+tp0.tv_nsec/MLDD);
	        
		}
		return Tn/liczbaTestow;
	  }
}

int main()
{
	printf("rozmiar tablicy N | czas - dane losowe | czas - dane niekorzystne\n");
	double Tn;
    int arr[2500];
    // test jeden
    int liczbaTestow=100;
	printf("%17d |", liczbaTestow);
    Tn = TimeMeasure(arr,0, liczbaTestow-1,1,liczbaTestow);
    printf("%19lf |",Tn);
    Tn = TimeMeasure(arr,0, liczbaTestow-1,0,liczbaTestow);
    printf("%19lf |",Tn);
    printf("\n");
    // test dwa
    liczbaTestow=500;
	printf("%17d |", liczbaTestow);
    Tn = TimeMeasure(arr, 0, liczbaTestow-1,1,liczbaTestow);
    printf("%19lf |",Tn);
    Tn = TimeMeasure(arr,0, liczbaTestow-1,1,liczbaTestow);
    printf("%19lf |",Tn);
    printf("\n");
    // test trzy
    liczbaTestow=1000;
	printf("%17d |", liczbaTestow);
    Tn = TimeMeasure(arr,0, liczbaTestow-1,1,liczbaTestow);
    printf("%19lf |",Tn);
    Tn = TimeMeasure(arr,0, liczbaTestow-1,0,liczbaTestow);
    printf("%19lf |",Tn);
    printf("\n");
    // test cztery
    liczbaTestow=2500;
	printf("%17d |", liczbaTestow);
    Tn = TimeMeasure(arr,0, liczbaTestow-1,1,liczbaTestow);
    printf("%19lf |",Tn);
    Tn = TimeMeasure(arr,0, liczbaTestow-1,0,liczbaTestow);
    printf("%19lf |",Tn);
    printf("\n");
  
    
    
  
    
	
	
	

return 0;
}
