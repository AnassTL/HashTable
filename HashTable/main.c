#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 20


char name[MAX_NAME];


char * hash_table[TABLE_SIZE];

int hash(char name[]){
	int i,cle=0;
    for(i=0;name[i]!='\0';i++)
        cle=cle+name[i]*(i+1);
    return (cle%TABLE_SIZE);
}

//initialiser la table
void init_hash_table(){
	for(int i =0; i< TABLE_SIZE ; i++){
	    hash_table[i]= NULL;
	}

}


//afficher table
void print_table(){
	printf("START");
	for (int i=0; i<TABLE_SIZE ; i++){
		if (hash_table[i]==NULL){
			printf("\t%i\t---\n",i);

		}else{
			printf("\t%i\t%s\n",i,hash_table[i]);
		}
	}
	printf("FINISH\n");
}


//inserer element
void hash_table_insert(char  name[]){

	    int index = hash(name);

		if (hash_table[index] == NULL){
			hash_table[index]= malloc(strlen(name));
            strcpy(hash_table[index] , name);

		}

		else{
			do{
               index ++;
        }while (hash_table[index]!= NULL);

		hash_table[index]= malloc(strlen(name));
        strcpy(hash_table[index%TABLE_SIZE] , name);
		}
}



//trouver element
void hash_table_lookup (char name[])
{
   int index = hash(name);
   if(hash_table[index] == NULL)
   {
	   printf("lexeme n'existe pas\n");

   }

   if(strncmp(hash_table[index], name, TABLE_SIZE)==0){
	   printf("lexeme trouve\n");
	   printf("%d \t%s\n",index,hash_table[index]);
       }
   else {

		   do{
               index ++;
			   printf("%d",index);
        }while (strncmp(hash_table[index], name, TABLE_SIZE)!=0 && index<TABLE_SIZE);

		if(strncmp(hash_table[index], name, TABLE_SIZE)==0)
		    {
			  printf("lexeme trouve\n");
	          printf("%d \t%s\n",index,hash_table[index]);
		    }

		  else{
			  printf("lexeme  n est pas dans la table \n");

		  }
	   }

}



int main()
{
	int choice, value, n, c;
	char name[100];
	//char  search[100];

	init_hash_table();

	do {
		printf("\n Mise en Oeuvre de la table de hachage en C \n\n");
		printf("MENU -: \n\n1.Insertion d’un element dans la table de hachage"
		                 " \n2.Element de recherche dans la table de hachage"
                        " \n3.Afficher une table de hachage"
		       " \n \n Veuillez saisir votre choix -:");

		scanf("%d", &choice);

		switch(choice)
                {

		case 1:

		      printf("Insertion d element dans la table de hachage\n");
		      printf("Enter element -:\t");
		      scanf("%s", name);
		      hash_table_insert(name);
              break;



		case 3:

		      print_table();

		      break;

		case 2:

		      printf("Rechercher un element dans Hash Table\n");
		      printf("Entrer l'element -:\t");
		      scanf("%s", name);
		      hash_table_lookup(name);

	          //if (tmp == NULL){
		      //printf("Not Found!\n");

	          //}else{
		      //printf("Found %s\n", tmp);
	          //}
			  break;


		default:

		       printf("Wrong Input\n");

}

		printf("\n Voulez vous continuez -:(entrer 1 pour oui)\t");
		scanf("%d", &c);

	}while(c == 1);



}
