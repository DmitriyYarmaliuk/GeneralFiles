#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "database.h"


//This function removes the newline character which would be right before the terminating null character thus -1


trim_newline (char string[]) //passing in a string
//individual characters of that array will change and YOU DONT need a return

{
	if(string[strlen(string)-1]='\n')
	string[strlen(string)-1]='\0';
	/*For example if the string contained the word car than when using fgets the characet return would be read in
	thus streln would return a value of 4. However, you know that car is 3 characters long counting from 0 ...
	0 1 2 thus string[3] is the 4th charater and it is the character return or in other words 
	the new line character which needs to be removed */
}


/*increase_array()
gracefully increase the size of of a dynamically-alloated array
of CDs by the number in "increase"
if oldarr++NULL, then count is assumed to be 0 and v.v.
*/


cd_t *increase_array(cd_t *oldarr,int oldcount,int increase)
//                 null          0 they have to match if this is the particualr instance 
{
	cd_t *newarr;//new larger array used to store the filed read from the file in memory while the program is running 
	
	//Allocate memory for the next CD
	
	if(oldcount==0)
	{
			newarr=malloc(increase*sizeof(cd_t));
	}	
	else 
	{
			newarr=realloc(oldarr,(oldcount+increase)*sizeof(cd_t));	
	}
	if(newarr==NULL)
	{
		printf("This program is out of memory - Exiting\n");
		exit(1);
	}	
	return newarr;
	
	
}


/*
	allocate_one_cd()

Set aside space for one CD from the heap
This will need to be freed
If memory is not available, we exit the program*/
cd_t *allocate_one_cd () //returns a pointer to a new CD
	
{
		cd_t *ptr;
		
		if((ptr=malloc(sizeof *ptr))==NULL) //Getting the size of the content of the pointer which in this case is a cd structure
		
		{
			fprintf(stderr,"This program is out of memory-Exiting\n");
			exit(1);
		}
		
		return ptr;
}	



