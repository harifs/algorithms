#include <stdio.h>
#include<stdlib.h>
#include<string.h>

void main() 
{ 
	char query[1024];
	FILE *fopen(), *fp; 
	int c ; 

	printf("The Query before extracting frm file is: [%s]\n", query);

	fp = fopen( "tmp.txt","r" ); 
	c = getc( fp ) ; 		
	while (  c != EOF ) 
	{
		fread(query,sizeof(c),1,fp);
		putchar( c );
		c = getc ( fp ); 	 
	}
	fclose( fp ); 

	printf("The Final Query is:\n");
	printf("%s\n",query);
}
