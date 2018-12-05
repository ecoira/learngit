#include <stdio.h>

void GetHzkCode(char *c,char buff[])
{
	unsigned char qh,wh;
	unsigned char location;
	FILE *HZK;

	if((HZK=fopen("hzk16","rb"))==NULL){
		printf("Can't open hzk16,Please add it?");
		getc();
		exit(0);
	}
	qh=*c-0xa0;
	wh=*(c+1)-0xa0;
	location=(94*(qh-1)+(wh-1))*32L;
	fseek(HZK,location,SEEK_SET);
	fread(buff,32,1,HZK);
	printf("qh:%d,wh:%d,location:%ld\n\r",qh,wh,location);
}

void printHzkChar(char *mat,char *c1,char *c2)
{
	int i,j,k;
	for(i=0;i<16;i++)
	{
		for(j=0;j<2;j++)
			for(k=0;k<8;k++)
				if(mat[i*2+j]&(0x80>>k))
					printf("%s",c1);
				else printf("%s",c2);
		printf("\n");
	}
}

void main()
{
	char *hzk;
	unsigned char *Hzkc1="*";
	unsigned char *Hzkc2=" ";
	char buffer[32];

	GetHzkCode("王",buffer);
	hzk=buffer;
	printHzkChar(hzk,Hzkc1,Hzkc2);
}
