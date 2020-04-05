#include <stdio.h>
#include <string.h>
#define MAX_LENGHT 1024 /*Maximum line lenght defined*/
/*Decleration of the functions that will used in the program*/
void menu();
void encrypt_open_msg();
void decrypt_secret_msg();
int find_size_of_line(char line[]);
void reverse_line(char line[], int line_lenght);
/*Shows menu on the screen and calls the function to use in sub-programs*/
void menu(){
    int choise;
    do{       
        printf("\n-----------------------------------------------------\n");
        printf("1. Encrypt\n");
        printf("2. Decrypt\n");
        printf("0. Exit\n");
        printf("Choise:\n");
        scanf("%d",&choise);
        /*Switch-case structure used to call  functions according to choises*/
        switch(choise){
            case(1):
                encrypt_open_msg();
                break;
                
            case(2):
                decrypt_secret_msg();
                break;
                
            case(0):
                break;
                               
            default:
                break;
        }
    }
    while(choise!=0);
}
/*Finds the lenght of line and returns it*/
int find_size_of_line(char line[]){
    int i,size=0;
    for(i=0; line[i]!=0; i++){
        size++;   
    }
    return size;
}
/*Reverses the line*/
void reverse_line(char line[], int line_lenght){
    char temp;
    int i=0,j=0;
    j=line_lenght -1;
    /*This while statement reverses the string assings
     * last element to the first with using a temp char value*/
    while(i<j){
        temp=line[i];
        line[i]=line[j];
        line[j]=temp;
        
        i++;
        j--;
    }    
}
/*This function reads content of open_msg.txt file, encrypts it, shows encrypted
 *message on screen and then writes to secret_msg.txt file.*/
void encrypt_open_msg(){

    FILE *in;
    FILE *out;
    char open_msg[]="open_msg.txt";
    char secret_msg[]="secret_msg.txt";
    char encrypt_str[MAX_LENGHT];
    int i,key,size;
    printf("Please enter key between 1-26:\n"); /*The key taken from the user*/
    scanf("%d",&key);
    
    /*Opening files*/
    in=fopen("open_msg.txt","r");
    out=fopen("secret_msg.txt","w");
    
    /*Do-while structure used to take all lines from the file until the end of file comes*/
    do{
        fgets(encrypt_str,MAX_LENGHT,in); /*Gets one line from file*/
        size=find_size_of_line(encrypt_str);/*find_lenght function called and the value assigned to the size variable*/
        size-=1;
        reverse_line(encrypt_str,size); /*Reverse function called and reversed the line*/
       
        if(!feof(in) && in!=NULL)/*This condition controls if there are empty lines.It wont process if there are empty line.*/
        {
            for(i=0; i< size;i++){
            
                if(encrypt_str[i]<='z' && encrypt_str[i]>='a'){ /*If the letters are between 'a' and 'z' operations are performed.*/
                
                    if(encrypt_str[i]-key >= 'a'){
                        encrypt_str[i] -=key;
                    }
                    /*When adding a key,the number of the alphabet(26)is added 
                     *according to the size of the letters.*/
                    else if(encrypt_str[i]-key < 'a'){
                        encrypt_str[i] = encrypt_str[i] + 26 - key;
                    }
                }
                if(encrypt_str[i]== ' '){ /*If there is a space,it changes to '_'*/
                encrypt_str[i]='_';
                }
                if(encrypt_str[i]=='.'){ /*If there is '.',it changes to '*'*/
                encrypt_str[i]='*';
                }
            }            
        	printf("%s",encrypt_str); /*Prints on the screen*/
            fprintf(out,"%s",encrypt_str); /*Prints on the file*/             
        }            
    }
    while(!feof(in));
    
    fclose(out);
    fclose(in);
}
/*This function reads each line of the message contained in secret_msg.txt, decrypts
 *the secret line, shows the open line on screen and then writes the open line to
 * *open_msg.txt file.*/
void decrypt_secret_msg(){

    FILE *in;
    FILE *out;
    char open_msg[]="secret_msg.txt";
    char secret_msg[]="open_msg.txt";
    char decrypt_str[MAX_LENGHT];
    int i,key,size;
    printf("Please enter key between 1-26:\n"); /*The key taken from the user*/
    scanf("%d",&key);
    
    in=fopen("secret_msg.txt","r");
    out=fopen("open_msg.txt","w");
    /*Do-while structure used to take all lines from the file until the end of file comes*/
    do{
    	
    	fgets(decrypt_str,MAX_LENGHT,in); /*Gets one line from file*/
        size=find_size_of_line(decrypt_str);/*find_lenght function called and the value assigned to the size variable*/
    	size-=1;
        reverse_line(decrypt_str,size); /*Reverse function called and reversed the line*/
    	if(!feof(in) && in!=NULL){ 
    	/*This condition controls if there are empty lines.It wont process if there are empty line.*/
    	
        	for(i=0; i< size;i++){
        	
                if(decrypt_str[i]<='z' && decrypt_str[i]>='a'){ /*If the letters are between 'a' and 'z' operations are performed.*/
                
                    /*changes in order to be error when changing the character according to the key value.*/
				    if(decrypt_str[i]+key>'z'){
					    decrypt_str[i]=((decrypt_str[i]+key)-'z')+('a'-1);
				    }
				    else{
					    decrypt_str[i]=decrypt_str[i]+key;
				    }
			    }
                if(decrypt_str[i]== '_'){ /*If there is a '_',it changes to space*/
                    decrypt_str[i]=' ';
                }
                if(decrypt_str[i]=='*'){ /*If there is '*',it changes to '.'*/
                    decrypt_str[i]='.';
                }
            }                    
           	printf("%s",decrypt_str); /*Prints on the screen*/
           	fprintf(out,"%s",decrypt_str); /*Prints on the file*/    
    	}   
    }
    while(!feof(in));
    /*Files closed*/
    fclose(out);
    fclose(in);
}
/*Main function only calls the menu function*/
void main(){
    menu();
}

