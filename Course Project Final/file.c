//File input and output functions

#include <stdio.h>
#include <stdlib.h>//includes prototypes for malloc and free
#include "database.h"

/*file_exists()
Boolean-returns a 1 if the file exists (attempts to open it for reading)
If 0 is returned, errno will be set 
There is a better way of doing this -usually "stat()"*/

int file_exists(char *fname)

{
	FILE *fptr;
	fptr=fopen(fname,"rb");
	
	if (fptr==NULL)
		return 0;
	
	
	fclose(fptr);
	return 1;	
}

/*save_file()
Write "count" number of CDS to "fname" (appending tot he end of the file
if "append" is set to 1)
Returns -1 if any error (errno will be set), or 0 for suceess

*/

int save_file(char *fname, cd_t **cds, int count,int append)


{
	
	FILE *fptr;
	int i; 
	
	
	//first opend the text file for writing
	fptr=fopen(fname,append ? "ab" : "wb");
	if(fptr==NULL)
		return -1;
		
	///writing out all the records
	for (i=0;i<count;i++)
		if(fwrite(cds[i],sizeof *(cds[i]),1,fptr)!=1)
		{
			fclose(fptr);
			return -1;
		}
	fclose(fptr);
	return 0;
}

//open_file()
/*Read the CD records form the specified file.
Dynamically allocate memory enough to hold the records (must be freed).
Returns a pointer to the memory, and sets "num" to be how many were read.
Sets num to -1 and returns NULL if an error occured */

int open_file(cd_t  **new_cds,char *fname,int *num)

{
	FILE *fptr;
	cd_t cd; //buffer to hold each read
	

	fptr=fopen(fname,"rb");
	if(fptr==NULL)
	
	{
		
		return -1;
	}
	
	*num=0;
	/*While we can successfully read  from the file, increasing  the array 
	by one and copy the data from the file to the end of the array*/
	while(fread(&cd,sizeof(cd),1,fptr)==1)
	{
		//Allocate the next element of the array
		new_cds[*num]=allocate_one_cd(); /*a pointer is set to 
		a particualr address which is returned by the allocate_one_cd function which returns a pointer to a
		memory space large enough to store one cd structure */
		*(new_cds[*num])=cd;//the contents of that pointer (the 0th ) element of the pointer array is derefrenced and its contents are set to cd
		(*num)++; //note the need for brackets
	//++ has higher precedence than the * 
	}
	
	fclose(fptr);
	
	return 0;
	
}
	

