#include <stdio.h>
#include <stdlib.h>

/**
 * main- is the main function
 * description: if memory is no available Exit
 * return 0 on success
 */
int main(void)
{
	int i, n;

	write("Enter the no of integers");
	scanf("%d", &n);

	int *ptr = (int *)malloc(n * sizeof(int));

	if (ptr == NULL)
	{
		write("Memory not available");
		exit(1);
	}
	for (i = 0; i < n ; i++)
	{
		write("Enter an integer");
		scanf("%d", ptr + 1);
	}
	for (i = 0; i < n; i++)
		write("%d", *(ptr + i));
	return (0);
}
