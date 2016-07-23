#include <stdio.h>
#include <string.h>
#include <stdlib.h>//includes prototypes for malloc and free
#include "database.h"/*Using the quotes makes the compiler look for the header file in the same directory 
 as the C file being compiled*/
//THUS USE "" when including self constructed header files!!!!!!!!!!!!!!! 
//When using #include <> the compiler begins to look in certain predefined directories
#define MAX_CDS 100 //how many cds we can stor
#define FNAME_SIZE 200 // max size of a file name
//!!!!! static variables are initialzed to NULL ---'\0'
static cd_t *cds[MAX_CDS];//an array of 100 pointers !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 
//each of which is implicitly initialized to NULL 
static int count;//how many CDs are in the cds array
static int changes;//boolean- have changes been made
static char fname[FNAME_SIZE];//current filename


/*Perform any necessary freeing and reset all the globals 
bac to a proper starting point*/ 
static void reset_everything()
{
	//Only free the array if we are sure that it is a valid pointer

		int i;
		
		for (i=0;i<count;i++)
			free(cds[i]); //each element of the cds array is a pointer thus it can be passed into the free function 
			
		
	count=0;	
	changes=0;
	fname[0]='\0'; //clear the current file name
}

static void goodbye()

{
	reset_everything();//not necessary but a good practice
	enter("\nPress ENTER to exit the program:");
}




//general_open()
//Perform all the kins of opens we do (from menusm from the command line
static void general_open(char *new_fname)

{
	cd_t *new_cds[MAX_CDS]; //temp array 
	int new_count;
	
	/* Read any records from a file intoa  temperary array
	Note that we don't pass &new_cds, because the address of an array is simply
	the array it self*/
	if(open_file(new_cds,new_fname,&new_count)==-1)
	{
		perror("Could not open the file");
		return;
	}
	
	
	//the temp array becomes the real array if the file was read properly
	//updating the globals accordingly
	
	reset_everything();//frees the existing list if there is one 
	count=new_count;
	memcpy(cds,new_cds,count * sizeof *cds);  //this copies only the pointers
	strcpy(fname,new_fname);
	
	printf("Successfully read file - %d new records\n",count);	
}

//general_save()
//Perform all the kinds of saves we do (regular save,save as,and append)
//Save_as and append are boolens and mutually exclusive

static void general_save(int append, int save_as)

{
	char new_fname[FNAME_SIZE];//the filename we will use
	
	//if we are appending or doing a save as then prompt for a filename
	
	if(append||save_as)
		read_string("Please enter the name of the file:", new_fname,sizeof(new_fname));
	else 
		strcpy(new_fname,fname);//using the existing file --saving to the existing file

	if (
	save_as
	&&//if save_as is false the other two conditions will not even be checked at all
	file_exists(new_fname)
	&&
	!yesno("The file exists. Are you sure you want to overwrite it:")
	)
	return;
	
	if(save_file(new_fname,cds,count,append)==-1)
	
	{
		perror("Could not save the list");
		return;
	}
	
	printf("List saved successfully - %d records\n",count);
	changes=0;    //Chanhes have been saved
	

	/*If they were doing a save as then
we have to make sure that the new filename(new_fname) is set to be the current file name (fname)*/

	if(save_as)
	{
		strcpy(fname,new_fname);
	}
}


/*are_you_sre()
If chanhes have been made, ask the user if they want to discard the,
returns 1 if it is okay or 0 otherwise*/
static int are_you_sure()
{
	if(!changes)
		return 1; //if there are no changes the question below does not have to b asked
	return yesno("Are you sure you want to discard all records:");	
}

//Menu option 1
//file_new()

static void file_new()
{
	if(are_you_sure())
		reset_everything();
}

//Menu option 2 
// file_open()
static void file_open()

{
	char new_fname[FNAME_SIZE];
	
	if(!are_you_sure())
		return;
	read_string("Please enter the name of the file to open:",new_fname,sizeof(new_fname));		

	general_open(new_fname);		
}


//Menu option 3
//file_save()

static void file_save()
{
	//if the current file name is empty we are really doing a save as
	general_save(0,strlen(fname)==0);
}
//Menu option 4
//file_save_as()

static void file_save_as()
{
	//if the current file name is empty we are really doing a save as
	general_save(0,1);
}


//Menu option 5
//file_append()

static void file_append()

{
	general_save(1,0);
}

//Menu option 6
//edit_add()
static void edit_add()
{
	cd_t cd;
	//Read in the CD
	
	printf("\nPlease enter the deatails od CD %d...\n\n",count+1);
	read_cd(&cd);
	
	/*Increase the size of the CD array*/
	/*The function increase-array dynamically reallocates memory for the static global cds array 
	if the user created a new cd stuc*/

	cds[count]=allocate_one_cd();
	*(cds[count])=cd;
	count++;
	
	changes=1; //clearly a change has been made 
	//are you sure question will be asked
	


}
//Menu option 7
//view_display_one()
static void view_display_one()

{
	int number;
	
	if(count==0)
	{
		puts("There are no CDs in the system");
		return;
	}
	//Asking for the CD number untill a valid one is supplied 
	for(;;)
	{
		number=read_int("Please enter the number of the CD that you wish to view:");
		if(number>=1 && number<=count)
		break;
		printf("Invalid number. There are %d CDs in the system\n",count);
	}
	
	printf("\nThe details of CD %d are: \n",number);
	print_cd(cds[number-1]);
}

//Menu option 8 
//view_display_all();
static void view_display_all()
{
	int i;
	
	if(count==0)
	
	{
		puts("There are no CDs in the system");
		return;
	}
	//OUTPUT CD details
	
	for (i=0;i<count;i++)
	
	{

	printf("\nINFO FOR CD:%d\n",i+1);	
	print_cd(cds[i]);
	
	if(i<count-1)// does this only if there are more CDs
		enter("\nPress ENTER to see the next set of details");

	}
}

/*0 if e1=e2
 <0 if e1<e2
 >0 if e1>e2 
 
This function will receive the addresses of two elements of out CDs array
where each element is in itself an address
"const" denotes that the function is not going to change the data pointed to 
by the pointer, and is included because of the prototype in stdlib.h 
 
 */
 
 
int compare_func(const void *e1,const void *e2)

{
		
	const cd_t *const*CD1=e1;
	const cd_t *const*CD2=e2;
	int rv;
	
	//First compare the artists
	
	rv=strcmp((*CD1)->artist,(*CD2)->artist);
	if(rv!=0)     //this means that the artists are different
		return rv; 
		
	//If we get to here, the artists were the same so now were gonna compare titles	
	
	return rv=strcmp((*CD1)->title,(*CD2)->title);
}



//Menu option 9
/*view_sort()
Sorts the records using qsort
*/
static void view_sort()

{
	if(count==0)
	{
		puts("There are no CDs in the system");
		return;
	}
	//cds is an array of pointers
	qsort(cds,count,sizeof cds[0],compare_func);
	puts("\nCDs sorted successfully");
	
}



//Menu option 10
//quit()

static void quit()

{
	if(are_you_sure())
	exit(0);   //note: some atexit processing will occur
}


	
//declaring a structure for the menu options
/*
static struct options

{
	char *string;
	void (*func)(void); //void in brackets means that the function to which this function pointer is pointing to does not take parameters
};

typedef struct options menu;

	menu menu_opts[]=
{
		 	 	
	{"1.   File: Create a new list\n", file_new},
	{"2.         Open an existing list\n",file_open},
	{"3.         Save the list\n", file_save},
	{"4.    	 Save the list with a new name\n",file_save_as},
	{"5.         Append list to another file\n", file_append},
	{"6.   Edit: Create a new record\n", edit_add},
	{"7.   View: Display a specific record\n",view_display_one},
	{"8.         Display all records\n",view_display_all},
	{"9.         Sort the records\n",view_sort},
	{"10.  Exit\n",quit}
	
};
*/	
static struct options

{
	char *string;
	void (*func)(void); //void in brackets means that the function to which this function pointer is pointing to does not take parameters
}    menu_opts[]=

{
		 	 	
	{"1.   File: Create a new list\n", file_new},
	{"2.         Open an existing list\n",file_open},
	{"3.         Save the list\n", file_save},
	{"4.    	 Save the list with a new name\n",file_save_as},
	{"5.         Append list to another file\n", file_append},
	{"6.   Edit: Create a new record\n", edit_add},
	{"7.   View: Display a specific record\n",view_display_one},
	{"8.         Display all records\n",view_display_all},
	{"9.         Sort the records\n",view_sort},
	{"10.  Exit\n",quit}
	
};
//display_menu()
/*Display the full menu screen Once, then promt the user for a 
choice and call the appropriate function*/
static void display_menu()

{
	int choice;
	int i;
	
	//Display the filename and record count 
	
	printf("\nThere are currently %d records in the system\n",count);
	if(strlen(fname)==0)
		puts("No current filename\n");
	else 
		printf("Current filename: %s\n\n",fname);
	//display the options 
	
	for (i=0;i<10;i++)
		printf("%s",menu_opts[i].string);
		
	for(;;)
	
	{
		choice=read_int("Please enter your choice:");
		if(choice>0 && choice<=10)	
			break;
		else 
			puts("Invalid Selection");
	}
	
	//Calling the function 
	menu_opts[choice-1].func();/*The brackets after func signify that I actually 
	want to run the function to which that particular function pointer is pointing to*/
	puts("\nPress ENTER to continue: ");		
}



main()
{
	atexit(goodbye);//ensure we say goodbye nicely
	
	/*If there are command-line arguments, interpret the first one as
	a filename to read CDs from */
	//if(argc>1) //1 is the name of the program
	//	general_open(argv[1]);//process the first parameter , the second string in the array of strings the first one being the name of the program
	
	puts("Welcome to the CD database");
	//just keep displaying the menu-the quit option will break the forever loop	
	
	for(;;)
	{
		display_menu();
	}

}










