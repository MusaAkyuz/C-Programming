/*
	Musa Akyüz
	9:36 04.06.2022
	
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char * argv[])
{
	//if argument didnt enter or more from 1
	if(argc != 2)
	{
		char *s = "Common dude you are already know how to execute this!";
		int i = 0;
		while(s[i] != 0)
		{
			printf("%c", s[i++]);
			fflush(stdout);
			usleep(99999);
		}
		exit(-1);
	}
	
	//open argument file path
	FILE *infile = fopen(argv[1], "r");
	if(infile < 0)
	{
		printf("Dosya açılamadı");
		exit(-2);
	}
	int c;
	while((c = getc(infile)) != EOF)
	{
		if(c == '\n')
		{
			usleep(1090009);
		}
		printf("%c", c);
		fflush(stdout);
		usleep(99999);
	}
	fclose(infile);
	return 0;
}
