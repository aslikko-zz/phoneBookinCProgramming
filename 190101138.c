#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "190101138.h"


int main(int argc, char *argv[]){
	
	if (argc >= 2){

	switch(argc)
	{	
		case 2: 
		if (strcmp(argv[1],USER) == 0){		
		allPersonList();	
		}
		if (strcmp(argv[1],ADMIN) == 0){		
			
		}
		break;

		case 4: /*./yalphone <usertype> <ID> <whatulookingfor>*/
		
		if (strcmp(argv[1],USER) == 0 && strcmp(argv[2], "filter") == 0){/* //checking if usertype is user*/
		searchLet(argv[3][0]);	          /*  //searching by name first letter*/
		searchNum(argv[3]);		           /* //searcing by number 4 digit*/
		}
		if (strcmp(argv[1],ADMIN) == 0 && strcmp(argv[2], "delete") == 0){/*//deleting entry*/
		aDelete(argv[3]);
		}	
		case 6:
		if (strcmp(argv[1], ADMIN) == 0 && strcmp(argv[2], "add") == 0){/*//adding entry to person.txt*/
		add(argv[3], argv[4], argv[5]);	
		}
		if (strcmp(argv[1],ADMIN) == 0 && strcmp(argv[2], "update") == 0){/*//updating entry*/
		update(argv[3], argv[4], argv[5]);
		}
		break;
		
	}
}
return 0;
}
void allPersonList(int argc, char *argv[]){ 
	FILE *person;
    FILE *allusers;
    char list;
    char ch;
    
    person=fopen("person.txt", "r");

       list=fgetc(person);
       while (list!=EOF)
       {
           printf("%c", list);
           list=fgetc(person);
       }   
        printf("\n");
    person=fopen("person.txt", "r");  
    allusers=fopen("allusers.txt", "w");
    while ((ch=fgetc(person))!=EOF) 
    {
        fputc(ch,allusers);                     
    }
   
        fclose(person);
        fclose(allusers);  
                        
}

void searchLet(char letter){ 
	
   FILE *person;	
   FILE *users;
	struct phonebook Phonebook;
	person = fopen ("person.txt", "r"); /*//for read*/
	users = fopen ("users.xml", "a"); /*//for write to new file*/
	
   while(!feof(person))
   {
        fscanf(person, "%[^,] , %[^,] , %[^,] , %[^\n] \n",Phonebook.ID,Phonebook.Name,Phonebook.Phone,Phonebook.Info);
               
	if(strstr(Phonebook.Name, "Ars. Gor.") != NULL && Phonebook.Name[10] == toupper(letter)){	
		printf("%s %s %s %s\n",Phonebook.ID,Phonebook.Name,Phonebook.Phone,Phonebook.Info);
		fprintf(users,"\n%s--%s %s %s",Phonebook.ID,Phonebook.Name, Phonebook.Phone, Phonebook.Info);
	}
	else if(strstr(Phonebook.Name, "Dr. Ogr. Uyesi") != NULL && Phonebook.Name[15] == toupper(letter)){
	
		printf("%s %s %s %s\n",Phonebook.ID,Phonebook.Name,Phonebook.Phone,Phonebook.Info);
		fprintf(users,"\n%s--%s %s %s",Phonebook.ID,Phonebook.Name, Phonebook.Phone, Phonebook.Info);
	}
	else if(strstr(Phonebook.Name, "Doc. Dr.") != NULL && Phonebook.Name[9] == toupper(letter)){
	
		printf("%s %s %s %s\n",Phonebook.ID,Phonebook.Name,Phonebook.Phone,Phonebook.Info);
		fprintf(users,"\n%s--%s %s %s",Phonebook.ID,Phonebook.Name, Phonebook.Phone, Phonebook.Info);
	}
	else if(strstr(Phonebook.Name, "Ogr. Gor.") != NULL && Phonebook.Name[10] == toupper(letter)){
	
		printf("%s %s %s %s\n",Phonebook.ID,Phonebook.Name,Phonebook.Phone,Phonebook.Info);
		fprintf(users,"\n%s--%s %s %s",Phonebook.ID,Phonebook.Name, Phonebook.Phone, Phonebook.Info);
	}
	else if(strstr(Phonebook.Name, "Prof. Dr.") != NULL && Phonebook.Name[10] == toupper(letter)){
	
		printf("%s %s %s %s\n",Phonebook.ID,Phonebook.Name,Phonebook.Phone,Phonebook.Info);
		fprintf(users,"\n%s--%s %s %s",Phonebook.ID,Phonebook.Name, Phonebook.Phone, Phonebook.Info);
	}
	else if (strstr(Phonebook.Name, "Prof. Dr.") == NULL &&
		 strstr(Phonebook.Name, "Ogr. Gor.") == NULL &&
		 strstr(Phonebook.Name, "Doc. Dr.") == NULL &&
		 strstr(Phonebook.Name, "Dr. Ogr. Uyesi") == NULL &&
		 strstr(Phonebook.Name, "Ars. Gor.") == NULL &&
		 Phonebook.Name[0] == toupper(letter)
		)

	{
		printf("%s %s %s %s\n",Phonebook.ID,Phonebook.Name,Phonebook.Phone,Phonebook.Info);
		fprintf(users,"\n%s--%s %s %s",Phonebook.ID,Phonebook.Name, Phonebook.Phone, Phonebook.Info);
	}
	
   }
	
}


void searchNum(char number[]){
	
	FILE *person;	
	struct phonebook Phonebook;
	if((person = fopen ("person.txt", "r")) == NULL){
	  	printf("Error! openning file");
		exit(1);
	}
	 while(!feof(person))
   	{
        fscanf(person, "%[^,] , %[^,] , %[^,] , %[^\n] \n",Phonebook.ID,Phonebook.Name,Phonebook.Phone,Phonebook.Info);
             
	if(strstr(Phonebook.Phone, number) != NULL){
	printf("%s %s %s %s\n",Phonebook.ID,Phonebook.Name,Phonebook.Phone,Phonebook.Info);
	}
		
	}	
	
	fclose(person);
}

void add(char name[], char phone[], char pos[]){
	
	FILE *person;
	struct phonebook Phonebook;
	
	if((person=fopen("person.txt","r"))==NULL){		
	}
	 while(!feof(person))
   	{
        fscanf(person, "%[^,] , %[^,] , %[^,] , %[^\n] \n",Phonebook.ID,Phonebook.Name,Phonebook.Phone,Phonebook.Info);
        }

	if((person=fopen("person.txt","a"))==NULL){		
	}
	strcpy(Phonebook.Name, name);
	strcpy(Phonebook.Phone, phone);
	strcpy(Phonebook.Info, pos);
	fprintf(person,"%d, %s, %s, %s\n",atoi(Phonebook.ID) + 1,Phonebook.Name, Phonebook.Phone, Phonebook.Info);

	fclose(person);
	fclose(person);
}

void update(char ID[], char type[], char newInfo[]){ 
	
	FILE *person, *person2;
	int count = 0;
	struct phonebook Phonebook;
	if((person = fopen ("person.txt", "r")) == NULL){
	  	printf("Error! openning file");
		exit(1);
	}
	person2 = fopen("phone.txt", "w");
	 while(!feof(person))
   	{
        fscanf(person, "%[^,] , %[^,] , %[^,] , %[^\n] \n",Phonebook.ID,Phonebook.Name,Phonebook.Phone,Phonebook.Info);		
	
	if(strcmp(Phonebook.ID, ID) != 0)
		{				
		fprintf(person2,"%s, %s, %s, %s\n",Phonebook.ID,Phonebook.Name,Phonebook.Phone,Phonebook.Info);		
		}
	else{
	if(strcmp(type, "name") == 0){ 
		fprintf(person2,"%s, %s, %s, %s\n",Phonebook.ID,newInfo,Phonebook.Phone,Phonebook.Info);
    }
	else if(strcmp(type, "phone") == 0){
		fprintf(person2,"%s, %s, %s, %s\n",Phonebook.ID,Phonebook.Name,newInfo,Phonebook.Info);
	}
	else if(strcmp(type, "info") == 0){
		fprintf(person2,"%s, %s, %s, %s\n",Phonebook.ID,Phonebook.Name,Phonebook.Phone,newInfo);
	}
	}
    }
	fclose(person);
	fclose(person2);
	

	person = fopen("phone.txt","r");
	person2 = fopen("person.txt", "w");
	while(!feof(person))
   	{

        fscanf(person, "%[^,] , %[^,] , %[^,] , %[^\n] \n",Phonebook.ID,Phonebook.Name,Phonebook.Phone,Phonebook.Info);	
	fprintf(person2,"%s, %s, %s, %s\n",Phonebook.ID,Phonebook.Name,Phonebook.Phone,Phonebook.Info);	
		
	}
	
	fclose(person);
	fclose(person2);    
	remove("phone.txt");
}
void aDelete(char ID[]){
	FILE *person, *person2, *deleted;
	int count = 1;
	struct phonebook Phonebook;
	if((person = fopen ("person.txt", "r")) == NULL){
	  	printf("Error! openning file");
		exit(1);
	}
	person2 = fopen("phone.txt", "w");  
	deleted = fopen("deleted.txt", "a");
	 while(!feof(person))
   	{
        fscanf(person, "%[^,] , %[^,] , %[^,] , %[^\n] \n",Phonebook.ID,Phonebook.Name,Phonebook.Phone,Phonebook.Info);		
	
	if(strcmp(Phonebook.ID, ID) != 0) 
		{				
		fprintf(person2,"%s, %s, %s, %s\n",Phonebook.ID,Phonebook.Name,Phonebook.Phone,Phonebook.Info);		
		}
	else{
		fprintf(deleted,"%s, %s, %s, %s\n",Phonebook.ID,Phonebook.Name,Phonebook.Phone,Phonebook.Info);
	}

	}
	fclose(person);
	fclose(person2);
	person = fopen("phone.txt","r");
	person2 = fopen("person.txt", "w");
	while(!feof(person))
   	{
        fscanf(person, "%[^,] , %[^,] , %[^,] , %[^\n] \n",Phonebook.ID,Phonebook.Name,Phonebook.Phone,Phonebook.Info);	
	fprintf(person2,"%s, %s, %s, %s\n",Phonebook.ID,Phonebook.Name,Phonebook.Phone,Phonebook.Info);	
		
	}
	
	    
	remove("phone.txt");
	fclose(person);
	fclose(person2);
	fclose(deleted);
	
	
        
}	



	







	
	
