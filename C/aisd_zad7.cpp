#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;


int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}


int find_kth(int *v, int n, int k) {

    if (n == 1 && k == 0) return v[0];
    if(n<=10)
    {
        qsort(v,n,sizeof(int),compare);
        return v[k];
    }

    int m = (n + 4)/5;
    int *medians = new int[m];
    for (int i=0; i<m; i++) {
        if (5*i + 4 < n) {
            int *w = v + 5*i;
            for (int j0=0; j0<3; j0++) {
                int jmin = j0;
                for (int j=j0+1; j<5; j++) {
                    if (w[j] < w[jmin]) jmin = j;
                }
                swap(w[j0], w[jmin]);
            }
            medians[i] = w[2];
        } else {
            medians[i] = v[5*i];
        }
    }

    int pivot = find_kth(medians, m, m/2);
    delete [] medians;

    for (int i=0; i<n; i++) {
        if (v[i] == pivot) {
            swap(v[i], v[n-1]);
            break;
        }
    }

    int store = 0;
    for (int i=0; i<n-1; i++) {
        if (v[i] < pivot) {
            swap(v[i], v[store++]);
        }
    }
    swap(v[store], v[n-1]);

    if (store == k) {
        return pivot;
    } else if (store > k) {
        return find_kth(v, store, k);
    } else {
        return find_kth(v+store+1, n-store-1, k-store-1);
    }
}


int main()
{
    int arr[] = {3,50,60,63,11,4,5,85,70,99,61,101,62,19,22,10,30,1,100,9,82,21,40,71,20,80,81,79};
    int k = 17;
    //qsort(arr,28,sizeof(int),compare);
    //int value = arr[k];
    int value = find_kth(arr,28,17);
    printf(" k(%d) = %d  \n", k, value);
    return 0;
}
