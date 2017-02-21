#include<stdio.h>
#include<time.h>
void SaveToFile(int arr[]) // save results to file output.txt
{
	FILE *fp;

    if ((fp=fopen("output.txt", "w"))==NULL) {
      printf ("Nie mogê otworzyæ pliku input.txt do zapisu!\n");
      return;
      }
    int i;
    for(i=0;i<30;i++)
    fprintf (fp, "%d ", arr[i]);

    fclose (fp);
}

void ReadFromFile(int arr[]) // reads input from file input.txt
{
	FILE *fp;

    if ((fp=fopen("input.txt", "r"))==NULL) {
      printf ("Nie mogê otworzyæ pliku output.txt do zapisu!\n");
      return;
      }
    int i;
    for(i=0; i<30; i++)
    fscanf (fp, "%d", &arr[i]);
    fclose (fp);
}

void MakeItRandom() //creates array of random integers and print them to input.txt
{
	int range = (200 - 1) + 1;
	srand(time(NULL));
    FILE *fp;
    if ((fp=fopen("input.txt", "w"))==NULL) {
      printf ("Nie mogê otworzyæ pliku input.txt do zapisu!\n");
      return;
      }
    int i;
    for(i=0;i<30;i++)
    fprintf (fp, "%d ", rand() % range + 1);
    fclose (fp);
}

void Heapify(int arr[], int i, int n) // iteration, i - father, n - size of array
{
    while (i <= n)
        {
        int largest;
        int l = left(i); //  functions below, for i=0 l=1 otherwise l=2*i
        int r = right(i);//  for i=0 r =2 otherwise 2*i+1

        if (l<n && arr[l] > arr[i])
           largest = l;
        else
           largest = i;

        if (r< n && arr[r] > arr[largest])
           largest = r;

        if (largest != i){
           Swap(arr,i,largest);
           i=largest;
        }
        else
           break;
        }
}

void BuildHeap(int arr[], int size)
{
    int i;
    for (i=size/2; i>=0; --i)
       Heapify(arr,i,size);
}

void HeapSort(int arr[],int size)
{
    BuildHeap(arr,size);
    int n=size,i;
    for (i=size-1; i>=1; --i)
        {
        Swap(arr,i,0); // swap last element with the first one
        --n;
        Heapify(arr,0,n);
        }
}

int left(int i)
{
    if(i==0)return 1;
    else return 2*i;
};
int right(int i)
{
    if(i==0)return 2;
    else return 2*i+1;
};

void Swap (int tab[], int a, int b)
{
    int x;
    x=tab[a];
    tab[a]=tab[b];
    tab[b]=x;
}

int main()
{
	int arr[30];
    MakeItRandom();
    ReadFromFile(arr);
    HeapSort(arr,30);
	SaveToFile(arr);

return 0;
}
