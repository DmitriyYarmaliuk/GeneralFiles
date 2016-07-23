/*Header file for the music data base project */

#define NO_ARTIST 

#define Max 200

#define TITLE_LENGTH 60
#define ARTIST_LENGTH 60

#define CD_ALBUM  (1<<0)
#define CD_COMEDY (1<<1)

//f is the flag and b is the bit
// c is the condition, f is the 32 bit flag, and b is the actual bit being used as a boolen
#define on_off(c,f,b) ((c) ? ((f)|=(b)) : ((f) &= ~(b)))

//f is the 32 bit boolean that can be used to declare 32 individual booelan values 
//and b is the single bit that is used as a boolean  
#define is_on(f,b) (((f)&(b)) ? 1:0)

// Definition of one CD
struct cd_type 
{
	char title[TITLE_LENGTH+1]; 
#ifdef	NO_ARTIST //if the flag NO_ARTIST is not defined the code in between is not ommited
	char artist[ARTIST_LENGTH+1];// 100 artists that can each be 61 characters long
#endif //if the flag NO_ARTIST is defined the code in between is ommited 
	int tracks;
	int flags;//32 bit flag  
	float price;
	
};
typedef struct cd_type cd_t; 


static void reset_everything();
static void goodbye();
static void general_open(char *new_fname);
static void general_save(int append, int save_as);
static int are_you_sure();
static void file_new();
static void file_open();
static void file_save();
static void file_save_as();
static void file_append();
static void edit_add();
static void view_display_one();
static void view_display_all();
static void quit();
static void display_menu();
cd_t* increase_array(cd_t *oldarr,int oldcount,int increase);
int file_exists(char *fname);
int save_file(char *fname, cd_t **cds, int count,int append);
int open_file(cd_t **new_cds, char *fname, int *num);

int compare_func(const void *e1,const void *e2);

cd_t *allocate_one_cd ();
//Function prototypes

int trim_newline (char string[]);
int enter (char prompt[]);
int yesno (char prompt[]);
int read_int(char prompt[]);
float read_float (char prompts[]);
int read_string(char prompt[], char answer[], int MAX) ;
int output(char title[], char artist[], int tracks, int album, float price );
//char *read_dyn_string(char prompt[]);
int read_cd(cd_t *cd);
void print_cd(cd_t *cd);
