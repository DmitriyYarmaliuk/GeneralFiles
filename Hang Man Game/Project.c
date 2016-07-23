#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main ()

{
	printf("Welcome :) \nLets play Hang-Man\n<At any time enter quit to leave game>\nPREPARE TO BE AMAZED\n");
	
	char firstname [30];
	printf("Please enter your first name:");
	fgets(firstname, 30, stdin);
	//printf("Sorry %s you lost", firstname);
	
	srand(time(NULL));
	int randomIndex=rand() % 4;
	/*srand(x)  used to set the starting value (seed) for generating a sequence of pseudo-random integer values.  The srand(x) function sets the seed of the random number generator algorithm used by the function rand( ).  A seed value of 1 is the default setting yielding the same sequence of values as if srand(x) were not used.  Any other value for the seed produces a different sequence.

Using
srand(time(NULL));
makes use of the computer's internal clock to control the choice of the seed.  Since time is continually changing, the seed is forever changing.  Remember, if the seed number remains the same, the sequence of numbers will be repeated for each run of the program.
*/
//	printf("randonIndex:%d\n",randomIndex);


	 
	 
	 

	switch (randomIndex)
	
	{
	
		case 0:
			printf("A word has been selected from color theme\n");
			srand(time(NULL));
	
	char guessWords [][16]={
	
	
	"yellow",
	"purple",
	"violet",
	"brown",
	"green",
	"orange",
	
	
	};

                                   
	int randomIndex=rand() % 6;   //this fucntion comes from the stdlib library
	int numberofLives=5;
	int numberCorrect=0;
	int oldCorrect=0;
	
	int lengthofword= strlen(guessWords[randomIndex]);
	
	//                    0 1 2 3 4
	//                    g r e e n
	int letterGuessed[8]={0,0,0,0,0,0,0,0,};
	int quit=0;
	int loopIndex=0;
	char guess[16];
	char letterentered;
//	printf("guessWords:%s\nrandonIndex:%d\nlength of the word:%d\n",guessWords[randomIndex], randomIndex, lengthofword);
	
	//While the number of the letters guessed correct is less than the number of letters in the word the loop will proceed
	while (numberCorrect < lengthofword)
	{
		printf("\n\nNew turn...\nHangman word:");
	
		for(loopIndex=0; loopIndex<lengthofword; loopIndex++)
		{
            
		//this if statement prevents the program from accepting one particular correct letter more than once			
			if(letterGuessed[loopIndex]==1)
			{
				printf("%c",guessWords[randomIndex][loopIndex]);
			}
			
			else{
				printf("-");
			}
			
		}
		
		printf("\n");

	
	
	printf("Please enter a guess letter:\n");
	printf("number correct so far is:%d\n",numberCorrect);
	fgets(guess, 16, stdin);
	
	if (strncmp(guess,"quit", 4)==0){
	
		quit=1;
		break;
		}
		
		
		letterentered=guess[0];
		printf("Letter guessed:%c\n", letterentered);
		
	
		oldCorrect=numberCorrect;
		for(loopIndex=0; loopIndex<lengthofword; loopIndex++)
		{
            
		//this if statement prevents the program from accepting one particular correct letter more than once			
			if(letterGuessed[loopIndex]==1)
			{
				continue;
			}
			
			/*if the letter entered (character at this point) equals the guessword[randomindex(which is determined randomly 
			by the computer with the stdlib library)] at the loop index which is 
			the column of the guessWords character array*/
			if(letterentered==guessWords[randomIndex][loopIndex] )
			{
				letterGuessed[loopIndex]=1;
				numberCorrect++;
				
			}
		}

		
		 if(oldCorrect==numberCorrect){
			numberofLives--;
			printf("That letter is not in the word\n");
			
			if (numberofLives==0){
			break;
		}
	}
	else{
		printf("Good job that letter is in the word\n");
		
		
	}	
		
	} //end of while loop
	
	if(quit==1)
	{
	printf("The user quit early\n");
}
	else if (numberofLives==0)
	{
		printf("Sorry %s\nYou lost the word was:%s",firstname,guessWords[randomIndex] );
	}
	else{
		printf("Congradulations %s\nYou are a winner the word was:%s",firstname, guessWords[randomIndex] );
	}
	
	getchar();
	break;
	
	case 1:
			
	printf("A word has been selected from the school subjects theme\n");
	srand(time(NULL));
	
	char dguessWords [][16]={
	
	
	"calculus",
	"physics",
	"english",
	"writing",
	
	
	
	};

                                   
	int drandomIndex=rand() % 4;   //this fucntion comes from the stdlib library
	int dnumberofLives=5;
	int dnumberCorrect=0;
	int doldCorrect=0;
	
	int dlengthofword= strlen(dguessWords[drandomIndex]);
	
	//                    0 1 2 3 4
	//                    g r e e n
	int dletterGuessed[8]={0,0,0,0,0,0,0,0};
	int dquit=0;
	int dloopIndex=0;
	char dguess[16];
	char dletterentered;
//	printf("guessWords:%s\nrandonIndex:%d\nlength of the word:%d\n",dguessWords[drandomIndex], drandomIndex, dlengthofword);
	
	//While the number of the letters guessed correct is less than the number of letters in the word the loop will proceed
	while (dnumberCorrect < dlengthofword)
	{
		printf("\n\nNew turn...\nHangman word:");
	
		for(dloopIndex=0; dloopIndex<dlengthofword; dloopIndex++)
		{
            
		//this if statement prevents the program from accepting one particular correct letter more than once			
			if(dletterGuessed[dloopIndex]==1)
			{
				printf("%c",dguessWords[drandomIndex][dloopIndex]);
			}
			
			else{
				printf("-");
			}
			
		}
		
		printf("\n");

	
	
	printf("Please enter a guess letter:\n");
	printf("number correct so far is:%d\n",dnumberCorrect);
	fgets(dguess, 16, stdin);
	
	if (strncmp(dguess,"quit", 4)==0){
	
		dquit=1;
		break;
		}
		
		
		dletterentered=dguess[0];
		printf("Letter guessed:%c\n", dletterentered);
		
	
		doldCorrect=dnumberCorrect;
		for(dloopIndex=0; dloopIndex<dlengthofword; dloopIndex++)
		{
            
		//this if statement prevents the program from accepting one particular correct letter more than once			
			if(dletterGuessed[dloopIndex]==1)
			{
				continue;
			}
			
			/*if the letter entered (character at this point) equals the guessword[randomindex(which is determined randomly 
			by the computer with the stdlib library)] at the loop index which is 
			the column of the guessWords character array*/
			if(dletterentered==dguessWords[drandomIndex][dloopIndex] )
			{
				dletterGuessed[dloopIndex]=1;
				dnumberCorrect++;
				
			}
		}

		
		 if(doldCorrect==dnumberCorrect){
			dnumberofLives--;
			printf("That letter is not in the word\n");
			
			if (dnumberofLives==0){
			break;
		}
	}
	else{
		printf("Good job that letter is in the word\n");
		
		
	}	
		
	} //end of while loop
	
	if(dquit==1)
	{
	printf("The user quit early\n");
}
	else if (dnumberofLives==0)
	{
		printf("Sorry %s\nYou lost the word was:%s",firstname,dguessWords[drandomIndex] );
	}
	else{
		printf("Congradulations %s\nYou are a winner the word was:%s",firstname,dguessWords[drandomIndex] );
	}
	
	getchar();
	break;
	
	
	case 2:
	printf("A word has been selected from the animal theme\n");
		srand(time(NULL));
	
	char zguessWords [][16]={
	
	
	
	"baboon",
	"jaguar",
	"alligator",
	"iguana",
	"caterpillar",
	"cheetah",
	"alligator",
	"mosquito",
	
	
	
	
	};

                                   
	int zrandomIndex=rand() % 8;   //this fucntion comes from the stdlib library
	int znumberofLives=5;
	int znumberCorrect=0;
	int zoldCorrect=0;
	
	int zlengthofword= strlen(zguessWords[zrandomIndex]);
	
	//                    0 1 2 3 4
	//                    g r e e n
	int zletterGuessed[8]={0,0,0,0,0,0,0,0};
	int zquit=0;
	int zloopIndex=0;
	char zguess[16];
	char zletterentered;
//	printf("guessWords:%s\nrandonIndex:%d\nlength of the word:%d\n",zguessWords[zrandomIndex], zrandomIndex, zlengthofword);
	
	//While the number of the letters guessed correct is less than the number of letters in the word the loop will proceed
	while (znumberCorrect < zlengthofword)
	{
		printf("\n\nNew turn...\nHangman word:");
	
		for(zloopIndex=0; zloopIndex<zlengthofword; zloopIndex++)
		{
            
		//this if statement prevents the program from accepting one particular correct letter more than once			
			if(zletterGuessed[zloopIndex]==1)
			{
				printf("%c",zguessWords[zrandomIndex][zloopIndex]);
			}
			
			else{
				printf("-");
			}
			
		}
		
		printf("\n");

	
	
	printf("Please enter a guess letter:\n");
	printf("number correct so far is:%d\n",znumberCorrect);
	fgets(zguess, 16, stdin);
	
	if (strncmp(zguess,"quit", 4)==0){
	
		zquit=1;
		break;
		}
		
		
		zletterentered=zguess[0];
		printf("Letter guessed:%c\n", zletterentered);
		
	
		zoldCorrect=znumberCorrect;
		for(zloopIndex=0; zloopIndex<zlengthofword; zloopIndex++)
		{
            
		//this if statement prevents the program from accepting one particular correct letter more than once			
			if(zletterGuessed[zloopIndex]==1)
			{
				continue;
			}
			
			/*if the letter entered (character at this point) equals the guessword[randomindex(which is determined randomly 
			by the computer with the stdlib library)] at the loop index which is 
			the column of the guessWords character array*/
			if(zletterentered==zguessWords[zrandomIndex][zloopIndex] )
			{
				zletterGuessed[zloopIndex]=1;
				znumberCorrect++;
				
			}
		}

		
		 if(zoldCorrect==znumberCorrect){
			znumberofLives--;
			printf("That letter is not in the word\n");
			
			if (znumberofLives==0){
			break;
		}
	}
	else{
		printf("Good job that letter is in the word\n");
		
		
	}	
		
	} //end of while loop
	
	if(zquit==1)
	{
	printf("The user quit early\n");
}
	else if (znumberofLives==0)
	{
		printf("Sorry %s\nYou lost the word was:%s",firstname,zguessWords[zrandomIndex] );
	}
	else{
		printf("Congradulations %s\nYou are a winner the word was:%s",firstname,zguessWords[zrandomIndex] );
	}
	
	getchar();
	break;


case 3:
	printf("A word has been selected from the countries theme\nP.S. remeber your 2nd grade teacher and how countries start with a capital\n");
		srand(time(NULL));
	
	char dzguessWords [][16]={
	
	
	"Czechoslavakia",
	"China",
	"Russia",
	"Turkey",
	"Poland",
	"Belarus",
	"Albania",
	"Belgium",
	"Serbia",
	

	
	
	};

                                   
	int dzrandomIndex=rand() % 9;   //this fucntion comes from the stdlib library
	int dznumberofLives=5;
	int dznumberCorrect=0;
	int dzoldCorrect=0;
	
	int dzlengthofword= strlen(dzguessWords[dzrandomIndex]);
	
	//                    0 1 2 3 4
	//                    g r e e n
	int dzletterGuessed[15]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int dzquit=0;
	int dzloopIndex=0;
	char dzguess[16];
	char dzletterentered;
	//printf("guessWords:%s\nrandonIndex:%d\nlength of the word:%d\n",dzguessWords[dzrandomIndex], dzrandomIndex, dzlengthofword);
	
	//While the number of the letters guessed correct is less than the number of letters in the word the loop will proceed
	while (dznumberCorrect < dzlengthofword)
	{
		printf("\n\nNew turn...\nHangman word:");
	
		for(dzloopIndex=0; dzloopIndex<dzlengthofword; dzloopIndex++)
		{
            
		//this if statement prevents the program from accepting one particular correct letter more than once			
			if(dzletterGuessed[dzloopIndex]==1)
			{
				printf("%c",dzguessWords[dzrandomIndex][dzloopIndex]);
			}
			
			else{
				printf("-");
			}
			
		}
		
		printf("\n");

	
	
	printf("Please enter a guess letter:\n");
	printf("number correct so far is:%d\n",dznumberCorrect);
	fgets(dzguess, 16, stdin);
	
	if (strncmp(dzguess,"quit", 4)==0){
	
		dzquit=1;
		break;
		}
		
		
		dzletterentered=dzguess[0];
		printf("Letter guessed:%c\n", dzletterentered);
		
	
		dzoldCorrect=dznumberCorrect;
		for(dzloopIndex=0; dzloopIndex<dzlengthofword; dzloopIndex++)
		{
            
		//this if statement prevents the program from accepting one particular correct letter more than once			
			if(dzletterGuessed[dzloopIndex]==1)
			{
				continue;
			}
			
			/*if the letter entered (character at this point) equals the guessword[randomindex(which is determined randomly 
			by the computer with the stdlib library)] at the loop index which is 
			the column of the guessWords character array*/
			if(dzletterentered==dzguessWords[dzrandomIndex][dzloopIndex] )
			{
				dzletterGuessed[dzloopIndex]=1;
				dznumberCorrect++;
				
			}
		}

		
		 if(dzoldCorrect==dznumberCorrect){
			dznumberofLives--;
			printf("That letter is not in the word\n");
			
			if (dznumberofLives==0){
			break;
		}
	}
	else{
		printf("Good job that letter is in the word\n");
		
		
	}	
		
	} //end of while loop
	
	if(dzquit==1)
	{
	printf("The user quit early\n");
}
	else if (dznumberofLives==0)
	{
		printf("Sorry %s\nYou lost the word was:%s",firstname,dzguessWords[dzrandomIndex] );
	}
	else{
		printf("Congradulations %s\nYou are a winner the word was:%s",firstname,dzguessWords[dzrandomIndex] );
	}
	
	getchar();
	break;
	}
return 0;

}
