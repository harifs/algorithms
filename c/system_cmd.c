#include <stdio.h>
void main(int argc, char *argv[])
{
	int i=0;
	char cmd[1024];
	printf("Number of arguments is : %d\n",argc);
	while (i<argc)
	{
		printf("argv[%d]: [%s]\n",i,argv[i]);
		sprintf(cmd,"ls -l %s \n",argv[i]);
		system(cmd);
		i++;
	}
}

