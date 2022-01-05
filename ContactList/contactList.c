// Yassine Berrachid
// Student ID: 1006848761
// Lab 9


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//#include "contactList.h"
#include <string.h>
#include <ctype.h>

#define PHONE_NUMBER_MAX_LENGTH 12
#define LISTCONTACTS 1
#define PRINTPHONES 2
#define FINDDUPLICATES 3
#define DELETECONTACT 4
#define EXIT 5
#define MAXNAME 256



typedef struct entry{ // Here we are defining a structure and a new type of data called entry
    char *name;
    char *phoneNumber[10]; // Each instance of the structure has two charachter pointers associated with it: the name of the contact and his/her phone number
} ContactInformation;

ContactInformation listOfContacts[30]; // Here we are defining an array pointer to an instance of the structure

void convertInputToDataStructure() // Here we are reading the strings contained in the contact list and assigning the names of the contact and the corresponding phone numbers to a structure
{
    

	
	int placeOfContact=0;
    int allContacts=sizeof(contactList)/sizeof(char *); 
    for(int i=0; i<allContacts; i++) 
	{
		if(isalpha(*contactList[i])!=0) // We check if the element is a name (starts with a letter -> isalpha
		{
         listOfContacts[placeOfContact].name=(char*) contactList[i]; // We assign the element of the list with index it to the name of the contact if isalpha returns true for the index i
		}
        else if(isdigit(*contactList[i])!=0 && i<allContacts) 
        {
            int placeOfPhone=0; 
            if(i<allContacts-1){
                while(isdigit(*contactList[i])!=0 && i<allContacts)
                {
                    listOfContacts[placeOfContact].phoneNumber[placeOfPhone]=(char*) contactList[i]; // We assign the element of the list with index i to the phone number if isdigit returns true
                    placeOfPhone++;
                    i++;
                }
                i--;
                placeOfContact++; 
            }
            else{
                listOfContacts[placeOfContact].phoneNumber[placeOfPhone]=(char*) contactList[i];
            }
        }

    }
}


void ListAllContacts() // This function lists all the contacts in the contact list in alphabetical order
{
   // First, we have to sort all the contacts in alphabetical order. We use insertion sort.
   int top; // item to insert
   for(top=1;top<30 && listOfContacts[top].name!=NULL ;top++){
       
       ContactInformation contactToCompare;
       contactToCompare=listOfContacts[top];
       int i=top;
       while (i>0 && strcmp(contactToCompare.name,listOfContacts[i-1].name)<0){ // This means we enter the while loop if the contact to compare is alphabetically before than the one we're comparing it to
           listOfContacts[i]=listOfContacts[i-1]; // Here, we're swapping both contacts if the one that we're testing is smaller alphabetically to the other (it will be placed before)
           i--; // This tests if the first contact that we swapped is smaller alphabetically to the one before again, until we find that the i-1 contact is smaller than this contact
       }
       listOfContacts[i]=contactToCompare; // We put the contact in its corresponding position after comparing it alphabetically to the others.
   }
   
   for(int listContacts=0;listContacts<30 && listOfContacts[listContacts].name!=NULL;listContacts++){
      printf("Name: %s\n", listOfContacts[listContacts].name);
      printf("Phone(s):");
      int numberOfNumbers;
      for (int i=0; i<30 && listOfContacts[listContacts].phoneNumber[i]!=NULL;i++){
            numberOfNumbers=i+1;
            bool contactPrinted=true;
      }
           
      for(int a=numberOfNumbers-1;a>=0;a--){
               printf(" %s", listOfContacts[listContacts].phoneNumber[a]);
               bool contactPrinted=true;
      }
      
      printf("\n");
           
      
  }
   
   
}





char* scanInput(char* input){ // This functions acts like a scanf statement, it reads and processes the string type input that is recieved from the user
    printf("%s",input);
    char buff[256];
    fgets(buff,256,stdin);
    size_t lengthCharUser=strlen(buff);
    char *pointerToInput= calloc(sizeof(char), lengthCharUser);
    strncpy(pointerToInput,buff,lengthCharUser-1);
    pointerToInput[lengthCharUser-1]='\0';
    return pointerToInput;
}


    




/*
 * printMenu - Prints out the user menu
 */
void printMenu() { // This function prints out the menu that is displayed to the user
   printf("\n\nEnter a command by number\n");
   printf("1. List all contacts in alphabetical order\n");
   printf("2. Print phone(s) for a contact\n");
   printf("3. Find duplicate entries\n");
   printf("4. Delete contact\n");
   printf("5. Exit the program\n");
   printf("Your input: ");
}





//eliminate trailing \n
char* rtrim(char* str)
{
   int i;
   for (i = strlen(str) - 1; i >= 0 && str[i] == '\n'; i--)
      str[i] = '\0';
   return str;
}

void PrintContact() { 
   
   char *nameSearched=scanInput("Enter name: ");
   bool contactFound=false;
   for (int count=1;count<30 && listOfContacts[count].name!=NULL; count++){
       if(strcmp(nameSearched,listOfContacts[count].name)==0){
           contactFound=true;
           int numberOfNumbers;
           printf("Name: %s\n", listOfContacts[count].name);
           printf("Phone(s):");
           for (int i=0; i<30 && listOfContacts[count].phoneNumber[i]!=NULL;i++){
               numberOfNumbers=i+1;
           }
           
           for(int a=numberOfNumbers-1;a>=0;a--){ // We print the numbers from the top to the bottom and print a new line at the end of each phone number 
               printf(" %s", listOfContacts[count].phoneNumber[a]);
           }
           
           printf("\n");
           return;
       }
   }
   printf("Contact not found"); // If we do not enter the loop, it means the contact was not found
   printf("\n");
    
       
}


void DeleteContact() // This function asks the user to enter the name of a contact and then deletes this contact from the contact list
{
   
   char *nameDeleted=scanInput("Enter name: ");
   bool contactDeleted=false;
   for (int i=0; i<30 && listOfContacts[i].name!=NULL; i++){
       if (strcmp(nameDeleted,listOfContacts[i].name)==0){
           for(int count=i; count<30 && listOfContacts[count].name!=NULL; count++){
               listOfContacts[count]=listOfContacts[count+1];
               contactDeleted=true;
           }
           return;
       }
   }
   printf("Contact not found");
   printf("\n");
}




void FindDuplicates(){ // This function is used to find dupplicate contacts, meaning contacts that appear twice (they have a phone number in common)
   for(int i=0; i<30 && listOfContacts[i].name!=NULL; i++) 
   {
      for(int j=0; j<10 && listOfContacts[i].phoneNumber[j]!=NULL; j++) 
      
      {
         bool found=false;
         for(int restContacts=i+1; restContacts<30 && listOfContacts[restContacts].name!=NULL && found==false; restContacts++)  // We go through the rest of the contacts as well
         {
            for(int numRestContacts=0; numRestContacts<10 && listOfContacts[restContacts].phoneNumber[numRestContacts]!=NULL && found==false; numRestContacts++) 
            {
               if(strcmp(listOfContacts[i].phoneNumber[j], listOfContacts[restContacts].phoneNumber[numRestContacts])==0)
               {
                  found=true;
                  printf("%s and %s", listOfContacts[i].name, listOfContacts[restContacts].name);
                  printf(" have a phone number in common\n");
               }
            }
         }
      }      
   }
}

int main()
{
   // first move data from contactList.h to a data structure
   convertInputToDataStructure();
   
   char notDone = 1;
   while (notDone) {
      printMenu();
      char userChoice[100];
      char* s = fgets(userChoice, sizeof(userChoice), stdin);
      if (!s)
      {
         printf("Wrong input\n");
         continue;
      }
      s = rtrim(s); /* eliminate trailing \n */
      //printf("selection = %s\n", s);
      int userSelection = atoi(s);

      switch (userSelection) {
         case 1: ListAllContacts(); break;
         case 2: PrintContact(); break;
         case 3: FindDuplicates(); break;
         case 4: DeleteContact(); break;
         case 5: notDone = 0; break;
         default: printf("Bad command...\n"); break;
         }
     
   }
   
   // PUT ANY POST_RUN CODE HERE

   return 0;
}

