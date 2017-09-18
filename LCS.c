#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include "splittingLCS.h"

float Spaces(char s[])                 //Total number of spaces in the string are calculated//
{
	int i;
	float scount=0;
	for(i=0;i<strlen(s);i++)
	{
		if (s[i]==' ')
		{
			scount++;
		}
	}
	return scount;
}

int main()
{
	char arrfiles[100][30];             //2D array//
	DIR *d;                            //Accessing Directories on C//
	struct dirent *dir;                //Structure dir//
	d=opendir("TextFiles");                    //Opens directory system corresponding to dirname,returns a pointer to object of type DIR//
	int totalcount=0;                       
	if (d)
	{
		while((dir=readdir(d))!=NULL)          //Directory entry at correct position//
		{
			int m=strlen(dir->d_name);         //name of the entry//
			if (((int)dir->d_name[m-1])==116&&((int)dir->d_name[m-2])==120&&((int)dir->d_name[m-3])==116)
			{
				strcpy(arrfiles[totalcount],dir->d_name);     //copying file names into arrfiles array//
				totalcount++;
			}
		}
		// closedir(d);
	}
	printf("MATRIX   ");
	int i;
	for (i=0;i<totalcount;i++)
	{
		printf("%15s",arrfiles[i]);
	}
	FILE *fp;               //file pointer to access file//
	int j;
	int x;
	char c;
	for (i=0;i<totalcount;i++)
	{
		printf("\n%s",arrfiles[i]);
		char str1[100];
		char str2[100];
		for (j=0;j<totalcount;j++)
		{
			fp=fopen(arrfiles[i],"r");
			c=fgetc(fp);                 //gets the next character and moves the position indicator//
			int k=0;
			while (c!=EOF)
			{
				str1[k]=c;
				c=fgetc(fp);        //copying the data in the first file to str1//
				k++;
			}
			str1[k]='\0';
			k=0;
			fp=fopen(arrfiles[j],"r");
			c=fgetc(fp);
			while (c!=EOF)                  //copying the data in the second file to str2//
			{
				str2[k]=c;
				c=fgetc(fp);
				k++;
			}
			str2[k]='\0';
			k=0;
			float l1=strlen(str1)-Spaces(str1);
			float l2=strlen(str2)-Spaces(str2);
			int num=splittingLCS(str1,str2);    //returns length of all the longest substring//
			float percent=(num*2.0)/(l1+l2);   //LCS length in both strings / Total length //
			printf("%15f",percent*100);        //plagiarism percentage using LCS//
		}
	}printf("%s\n"," ");
}
