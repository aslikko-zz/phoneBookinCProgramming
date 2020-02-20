#define ADMIN "-a"
#define USER  "-u"
#define UPDATE "update"
#define ADD "add"
#define DELETE "delete"
#define FILTER "filter"

typedef struct phonebook{
	
	char ID[100];
	char Name[100];
	char Phone[100];
	char Info[100];
	
}phonebook;

void allPersonList();
void searchLet(char letter); 
void searchNum();
void add();
void aDelete(char ID[]);
void update();
