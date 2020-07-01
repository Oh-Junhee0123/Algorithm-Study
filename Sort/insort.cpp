#include <stdio.h>

int main()
{
	int a[] = {50, 20, 30, 10, 40};
	int i, j,k;
	int temp;
	int n=5;
	
	for(int i = 0; i<n; i++)
	{
		printf("%d", a[i]);
	}
	printf("\n");
	
	for(i=1; i<n; i++)
	{
		j = i;
		
		while(j>0 && a[j]<a[j-1])
		{
			temp = a[j];
			a[j] = a[j-1];
			a[j-1] = temp;
			
			j--;
		}
	}
	for(k = 0; k<n; k++)
	{
		printf("%d", a[k]);
	}
	printf("\n");
	return 1;
}
