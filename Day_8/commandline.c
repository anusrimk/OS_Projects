#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	//argc and argv are stored in stack frame of the main argv stores the array of pointers to string
	
	int count = 0;
	printf("\nDemonstrate the process of command line argument");
	
	printf("\nThe Value of argc is %d",argc);

	while(count < argc)
	{
		printf("\n %dth string is %s",count, argv[count]);
		count++;
	}
	
	return 0;
}


