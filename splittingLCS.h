int splittingLCS(char st1[],char st2[])
{
	char str1[100][50]={' '};
	int i=0,var1=0;
	char *tok1=strtok(st1," ");
	while (tok1!=NULL)
	{
		strcpy(str1[i],tok1);
		tok1=strtok(NULL," ");
		i++;
		var1++;
	}
	int var2=0;                          //Splitting the strings st1,st2 by space and putting the words in the array a//
	i=0;
	char str2[100][50]={' '};
	char *tok2=strtok(st2," ");
	while (tok2!=NULL)
	{
		strcpy(str2[i],tok2);
		tok2=strtok(NULL," ");
		i++;
		var2++;
	}
	int j,count=0,fcount=0,temp;
	for (i=0;i<var1;i++)
	{
		temp=i;
		for(j=0;j<var2;j++)
		{
			if (strcmp(str1[i],str2[j])==0) //compares the string pointed to, by str[i] to the string pointed to by str[j]//
			{
				count+=strlen(str1[i]);
				i++;
			}
			else
			{
				i=temp;                 //compares each word in first string with all the words//
		       	count=0;                //if matches continues to find the longer one//
			}
			if (fcount<count)
			{
				fcount=count;
			}
		}
		i=temp;
		count=0;
	}
	return fcount;                   //returns the longest sub string length//
}