struct frequency
{
	char *words;
	int count;
};

int splitting(char *str1, struct frequency f1[])
{	
	char *arr[100];
	char *str=strtok(str1," ");
	int var=0,count=1;
	while (str!=NULL)           //Splitting the string s1 by space and putting the words in the array a//
	{
	arr[var]=str;
	var++;
	str=strtok(NULL," ");	
	}
	int z=0;
	int z1=0;
	int k=0;
	for(int i=0;i<var;i++)
	{
		count=1;
		for(int j=i+1;j<var;j++)
		{
			if(strcmp(arr[i],arr[j])==0 && arr[i]!="&") //compares the string pointed to, by arr[i] to the string pointed to by arr[j]//
			{
              arr[j]="&";      //if two words are equal second word is replaced by a special character//
              count=count+1;
          	  f1[i].words=arr[i];
    		  f1[i].count=count;
    		  k=k+1;
    		  // printf("%s : %d\n",f1[i].words,f1[i].count);
    		 
			}
		}
			if(count==1 && arr[i]!="&")
			{
			  f1[i].words=arr[i];
    		  f1[i].count=count;                  //unique words without any repitition are saved//
    		  k=k+1;
    		  // printf("%s : %d\n",f1[i].words,f1[i].count);
			}		
	}
	return(k);	//unique word count is returned//
}