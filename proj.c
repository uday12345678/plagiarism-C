#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <dirent.h>
#include "splitting.h"


int main(int argc, char *argv[])
{	
    char filestr[100][30];         //2D array//
	DIR *d;                        //Accessing Directories on C//
	struct dirent *dir;            //Structure dir//
	d=opendir(".");               //Opens directory system corresponding to dirname,returns a pointer to object of type DIR//
	int totalfiles=0;
	if (d)
	{
		while((dir=readdir(d))!=NULL)       //Directory entry at correct position//
		{
			int m=strlen(dir->d_name);     //name of the entry//
			if (((int)dir->d_name[m-1])==116&&((int)dir->d_name[m-2])==120&&((int)dir->d_name[m-3])==116)
			{
				strcpy(filestr[totalfiles],dir->d_name); //copying file names into filestr array//
				totalfiles++;
			}
		} 
		// closedir(d);
	}
	printf("MATRIX   ");
	int i;
	for (i=0;i<totalfiles;i++)
	{
		printf("%15s",filestr[i]);
	}		
	FILE *fp;     //file pointers to access files//
	FILE *fp1;
	
	char a;
	char b;
	for(int i=0;i<totalfiles;i++)
	{
	    printf("\n%s",filestr[i]);
		char str1[1000];
		char str2[1000];
	
		for(int j=0;j<totalfiles;j++)
		{
	
		fp=fopen(filestr[i],"r");
		int k1=0;
		a=fgetc(fp);       //gets the next character and moves the position indicator//
        while (a!=EOF)
         {
         	if(a!='\n')
         	{
         	str1[k1]=a;
         	k1++;
         	a=fgetc(fp);
            }
            else                        //copying the data in the first file to str1//
            {
            	a=' ';
            }
          
         }
         // printf("%s",str1);
         str1[k1]='\0';
         fclose(fp);
    fp1=fopen(filestr[j],"r");
	int k=0;
	b=fgetc(fp1);
      while (b!=EOF)
         {
         	if(b!='\n')
         	{
         	str2[k]=b;                       //copying the data in the second file to str2//
         	k++;
         	b=fgetc(fp1);            
         	}
         	else
         	{
         		b=' ';
         	}        
         }
         // printf("%s",str2);
         str2[k]='\0';
         fclose(fp1);
     struct frequency f1[100];
     struct frequency f2[100];
	
	int d=splitting(str1,f1);                 //length or the number of unique words are returned//
	int e=splitting(str2,f2);                 // frequencies of the words in the strings are found//
	int z=0;
	int z1=0;
	
	for(int x=0;x<d;x++)
	{
		
		z=z+pow((f1[x].count),2);              //sum of squares of frequencies of words in first file//
	}
	//printf("%d",z);
	for(int y=0;y<e;y++)
	{
		
		z1=z1+pow((f2[y].count),2);           //sum of squares of frequencies of words in second file//
	}
	//printf("%d",z1);
	float denom=sqrt(z)*sqrt(z1);             //product of square root of sum of squares of both the files//
	//printf("%.2f",f);
	int numer=0;
	for(int x=0;x<d;x++)
	{
		for(int y=0;y<e;y++)
		{
			if(strcmp(f1[x].words,f2[y].words)==0)     //Dot product of frequencies//
			{
				numer=numer+((f1[x].count)*(f2[y].count));
			}

		}
	}
	//printf("%d",w);
	printf("\t\t %.2f",(numer/denom)*100);         //Plagiarism percentage calculation//
  }
  printf("%d\n","");  

 }

}