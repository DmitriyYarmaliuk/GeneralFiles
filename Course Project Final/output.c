#include <stdio.h>
#include <string.h>
#include "database.h"/*Using the quotes makes the compiler look for the header file in the same directory 
 as the C file being compiled*/
//THUS USE "" when including self constructed header files!!!!!!!!!!!!!!! 
//When using #include <> the compiler begins to look in certain predefined directories




//Fucntion that prints out the CD details one CD at a time. It had one CD as an input to the fucntion!!!!
void print_cd(cd_t *cd)
{
	
	
	puts("=======================");
	printf("Title: %s\n",cd->title);
#ifdef NO_ARTIST 
	printf("Artist: %s\n",cd->artist);
#endif	
	printf("Number of tracks: %d\n", cd->tracks);
	printf(is_on(cd->flags,CD_ALBUM) ? "Album\n"  : "Single\n");
	printf(is_on(cd->flags,CD_COMEDY) ? "Comedy\n"  : "Not a comedy\n");
	printf("Price: $%.2f\n",cd->price);
	puts("=======================");	
	
}
