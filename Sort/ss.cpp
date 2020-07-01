//구현은 쉽지만, 느림
 
#include <stdio.h>

int main()
{
	int a[]={10, 20, 50, 30, 40};
	int n=5;
	int temp;
	int min;
	
	for(int i=0; i<n; i++) 
	{
		printf("%d", a[i]);
	}
	printf("\n");
	
	for(int i = 0; i<n-1; i++)
	{
		min = i;
		
		for(int j = i+1; j<n; j++)
		{
			if(a[min] > a[j])
			{
				min = j;
			}
		}
		
		temp = a[i];
		a[i] = a[min];
		a[min] = temp;
	}
	
	for(int i = 0; i<n; i++)
	{
		printf("%d", a[i]);
	}
	
	return 1; 
}
