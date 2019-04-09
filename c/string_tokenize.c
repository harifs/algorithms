#include <stdio.h>
#include <string.h>
void main()
{
char a[21]="CO:KA:CO:LA:NO";
char *b;

b=strtok(a,":");
	printf("%s",b);
if ( b )
{
	printf("%s",b);
	while (b=strtok(NULL,":"))
	printf("\n%s",b);
}
}
