#include <stdio.h>
#define max 6

void merge(int a[], int low, int mid, int high)
{
	int b[1000];
	int i = low;
	int j = mid+1;
	int k = 0;
	
	while(i <= mid && j <= high)
	{
		if(a[i] <= a[j])
		{
			b[k] = a[i];
			k++;
			i++;
		}
		else
		{
			b[k] = a[j];
			j++;
			k++;
		}
	}
	
	while(i <= mid)
	{
		b[k] = a[i];
		k++;
		i++;
	}
	
	while(j <= high)
	{
		b[k] = a[j];
		j++;	
		k++;
	}
	k--;
	
	while(k >= 0)
	{
		a[low+k] = b[k];
		k--;
	}
}

void mergesort(int a[], int low, int high)
{
	if(low < high)
	{
		int m = (low+high)/2;
		
		mergesort(a, low, m);
		
		mergesort(a, m+1, high);
		
		merge(a, low, m, high);
	}
	else
	{
		return ;
	}
}

int main()
{
	int a[max]={20, 10, 70, 80, 40, 90};
	int i = 0;
	
	printf("\nbefore merge ");
	
	for(i = 0; i < max; i++)
	{
		printf("%d", a[i]);
	}
	
	mergesort(a, 0, max-1);
	
	printf("\nafter merge ");
	
	for(i = 0; i < max; i++)
	{
		printf("%d", a[i]);
	}
}
