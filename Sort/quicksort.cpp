#include <stdio.h>
#include <stdlib.h>
#define max 10

int Partition(int A[], int start, int end)
{
	int pivot = A[end];
	int i;
	int index = start;
	
	int temp;
	
	for(i = start; i < end; i++)
	{
		if(A[i] <= pivot)
		{
			temp = A[i];
			A[i] = A[index];
			A[index] = temp;
			index++;
		}
	}
	
	temp = A[index];
	A[index] = A[end];
	A[end] = temp;
	
	return index;
}

void QuickSort(int A[], int start, int end)
{
	int index;
	int i;
	
	if(start < end)
	{
		index = Partition(A, start, end);
		QuickSort(A, start, index-1);
		QuickSort(A, index+1, end);
	}
	else
	{
		return ;
	}
}

int main()
{
	int A[max] = {40, 30, 100, 60, 80, 70, 90, 10, 20, 50};
	int i;
	
	printf("\n before sorting ");
	
	for(i = 0; i < max; i++)
	{
		printf("%d", A[i]);
	}
	
	QuickSort(A, 0, max-1);
	
	printf("\n after sorting ");
	
	for(i = 0; i < max; i++)
	{
		printf("%d", A[i]);
	}
}
