/*Esra Nur Arıcan*/
/*161044028*/

#include <stdio.h>
#include<stdlib.h>
#include<time.h>
/*type definition t_type to use in the struct as "type"*/
typedef enum{
    P=200, //penalty
    S=201 ,//snake
    M=203,//stair
    B=204 ,//boost
    T=205 ,//trap        
} t_type;

/*struct definition for game board*/    
typedef struct{
    char text[50];
    int data;
    t_type type;
    int pos_x;
    int pos_y;
    int jump_x;
    int jump_y;
} block;

/*Function decleration */    
block init_board( block board[][10]);
block print_board(block board[][10]);
int dice_roll();
int play_single_player(block board[][10],int data,int counter);


int main(){

    block board[10][10];
    init_board(board);
    print_board(board);
    dice_roll();
    play_single_player(board,1,1);
   
}

/*Function that initializes the board*/
block init_board(block board[10][10]){
    
    
    int i,j,k=0; // i:row, j:column
    
    for(i=0; i<10;i++){
        /*For odd rows numbers start from 11,21,31 etc.*
         *I generated a formula to reach those numbers*/
        if(i%2==0){
            for(j=0; j<=9; j++){
                board[i][j].data = 10*(9-i) +(j+1);
            }
        }
        /*For odd rows numbers start from 10,30,50 etc.*
         *I used different equation to reach those numbers*/
        if(i%2!=0){
            for(j=0; j<=9; j++){
                board[i][j].data = 10*(10-i)-j;
            }
        }           
    }
    
    /*For types and texts i initialized one by one on the board*/
    board[0][2].type= T;
    sprintf(board[0][2].text,"T");
    board[0][7].type=S;
    sprintf(board[0][7].text,"S{72}");
    board[0][8].type=S;
    sprintf(board[0][8].text,"S{56}");
    board[i][j].type=M;
    sprintf(board[1][1].text,"M{94}");
    board[1][5].type = P;
    sprintf(board[1][5].text,"P");
    board[1][8].type = B;
    sprintf(board[1][8].text,"B");
    board[2][2].type=S;
    sprintf(board[2][2].text,"S{68}");
    board[2][5].type=M;
    sprintf(board[2][5].text,"M{83}");
    board[2][8].type = T;
    sprintf(board[2][8].text,"T");
    board[3][1].type=M;
    sprintf(board[3][1].text,"M{77}");
    board[3][4].type = B;
    sprintf(board[3][4].text,"B");
    board[3][7].type=S;
    sprintf(board[3][7].text,"S{52}");
    board[4][3].type = T;
    sprintf(board[4][3].text,"T");
    board[4][6].type=M;
    sprintf(board[4][6].text,"M{77}");
    board[4][9].type=S;
    sprintf(board[4][9].text,"S{44}");
    board[5][0].type = B;
    sprintf(board[5][0].text,"B");
    board[5][2].type = P;
    sprintf(board[5][2].text,"P");
    board[5][5].type=S;
    sprintf(board[5][5].text,"S{22}");
    board[6][1].type=M;
    sprintf(board[6][1].text,"M{52}");
    board[6][5].type = B;
    sprintf(board[6][5].text,"B");
    board[6][9].type = T;
    sprintf(board[6][9].text,"T");
    board[7][1].type = B;
    sprintf(board[7][1].text,"B");
    board[7][5].type=S;
    sprintf(board[7][5].text,"S{12}");
    board[8][2].type = P;
    sprintf(board[8][2].text,"P");
    board[8][6].type=M;
    sprintf(board[8][6].text,"M{28}");
    board[9][3].type=M;
    sprintf(board[9][3].text,"M{11}");
    board[9][4].type=S;
    sprintf(board[9][4].text,"S{1}");
          
}
/*Function that prints the game board on the screen*/
block print_board(block board[10][10]){
    int i,j;
    for(i=0; i<10; i++){
        for(j=0; j<10; j++){
            
            if(board[i][j].type==S || board[i][j].type== P||board[i][j].type==M||board[i][j].type==B||board[i][j].type==T)
                printf("%s\t",board[i][j].text);
            
            else if(board[i][j].type!=S || board[i][j].type!= P||board[i][j].type!=M||board[i][j].type!=B||board[i][j].type!=T)
                printf("%d\t",board[i][j].data);
            
            else if(board[i][j].text==NULL)
                printf("%d\t",board[i][j].data); 
        }
        printf("\n\n");
    }
   
}
/*Function that generates randomly numbers as a dice rolling*/
int dice_roll(){
    int dice;
    srand(time(NULL));
    dice=(rand()%6)+1;
    
    return dice;
}
/*Function that plays game for one player*/
int play_single_player(block board[][10],int data,int counter){
    int dice=0,i=0,j=0;
    if(data!=100){
        /*To find new position dice number added to data value*/
        dice=dice_roll();
        data=data+dice;
        
        printf("%d\n",data);
        for(i=0;i<10;i++){
            for(j=0;j<10;j++){
                if(board[i][j].data=data){
                    board[i][j].pos_x=i;
                    board[i][j].pos_y=j;
                    break;
                }
            }
        }
        /*If there is a boost,players goes five block further*/
        if(board[i][j].type==B){
            data=data+5;   
        }
        /*If there is a trap,players goes back five block */
        if(board[i][j].type==T){
            data=data-5;   
        }
        /*If there is a penalty,player stops,and rolls the dice again*/
        if(board[i][j].type==P){
            play_single_player(board,data,counter);
        }
       
    }
    return 0;
}






