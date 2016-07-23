#include <stdio.h>
#include <string.h>
//#undef__STRICT_ANSI__
#include <stdlib.h>
#include "database.h"





enter (char prompt[]) 
{

	fputs(prompt,stdout); //Whatever text is in the prompt variable will be printed no changes to it are made
	fflush(stdin);
	getchar();
	
}
//If y or Y the function returns a 1 and n or N gives 0
int yesno (char prompt[])

{	
	fflush(stdin);
	char answer;
	
	for (;;)
	{
	fflush(stdin);
	fputs(prompt,stdout);
	fputs(" (Y/N)? ",stdout);
	scanf("%c",&answer);
	
	//Process the answer making it Upper case
	answer=toupper(answer); 
	
	if (answer=='Y') //Thus is not an array so there is no need in using the strcmp fucntion 
	return 1;//the return will break the loop
	
	//don't need a break
	
	else if (answer=='N')
	return 0;
	
	//don't need an else;	
	else
	printf("Error--only y/Y or n/N are allowed\n");
	fflush(stdin);
	}
}

//Ask the user a question and prompt for a string answer
//The string is dynamically allocated (and so should be freed)
//The absolute maximum size that the string can ever be is given by #define MAX 200

/*char *read_dyn_string(char prompt[])
function retruns a pointer to the dynamically allocated memory which contains a character string

{
	fputs(prompt,stdout);
	char buffer[Max];takes in the string that represents the title of the artist
	
	fflush(stdin);
	fgets(buffer,sizeof buffer,stdin);
	
	trim_newline(buffer);
	
	return strdup(buffer);the function strdup dynamically allocates enough memory for the entered string
	then the function returns a pointer to this piece of dynamically allocated memory
	
} */

//Function that reads in the CD information by using seveeral of the previoulsy written fucntions that read in strings and integers

read_cd(cd_t *cd)

{
	

	read_string ("Title: ",cd->title, sizeof cd->title);	
	
#ifdef NO_ARTIST
	read_string("Artist: ",cd->artist, sizeof cd->artist);	
#endif
	cd->tracks=read_int("Number of tracks:");
	on_off(yesno("Is the CD an Album:"),cd->flags,CD_ALBUM);
	on_off(yesno("Is it a comedy CD:"),cd->flags,CD_COMEDY);
	cd->price=read_float("Retail price (e.g. 4.65):");
	
}


int read_int(char prompt[])

{

	int answer;
	fputs(prompt, stdout);
	fflush(stdin);
	scanf("%d",&answer);
	
	
	return answer;
}

float read_float (char prompt[])
{
	float answer;
	fputs(prompt, stdout);
	fflush(stdin);
	scanf("%f",&answer);
	
	
	return answer;
}

/*read_string()
Ask the user a question and prompt for a string answer
MAZ size of the "answer" including the NULL terminating character
Note: The answer is MODIFIED by the function*/

read_string(char prompt[], char answer[], int MAX) 
/*creating another parameter char answer for the fucntion to output something essentially 
char answer will be modified and thus it will reflect the output of the function in a way*/
{
	fputs(prompt,stdout);
	fflush(stdin);
	
	fgets(answer,MAX,stdin);
	trim_newline(answer); 
	
}

