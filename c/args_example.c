#include <stdio.h>
void main(int argc, char *argv[])
{
	int i=0;
	printf("Number of arguments is : %d\n",argc);
	while (i<argc)
	{
		printf("argv[%d]: [%s]\n",i,argv[i++]);
	}
	if (argc==1)
		printf("Give Few Command line arguments to test!");
}

