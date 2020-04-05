/*my search function is incorrext thats way i call it in my main but it shows nothing.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*Struct definition of forest*/
typedef struct{
    char **map;
    int width;
    int height;
    int flower_x;
    int flower_y;
    
}Forest;

/*Struct definition of botanist*/
typedef struct{
    int coord_x;
    int coord_y;
    int water_bottle_size;
    
}Botanist;

/*Function decleration*/
void init_game(Forest *forest,Botanist *botanist);
void print_map (Forest *forest);
void search (Forest *forest,Botanist *botanist);

void main(){
    Forest forest,*fptr;
    Botanist botanist,*bptr;
    bptr=&botanist;
    fptr=&forest;
    init_game(fptr,bptr);
    print_map (&forest);
    search(fptr,bptr);

}//end of main function

void init_game(Forest *forest,Botanist *botanist){
    int i,j;
    char seperate;
    FILE *inp;
    inp=fopen("init.csv","r");
    
    fscanf(inp,"%d\n",&(botanist->water_bottle_size));
    printf("water bottle size:%d\n",botanist->water_bottle_size);
    fscanf(inp,"%d%c%d\n",&(forest->width),&(seperate),&(forest->height));
    printf("width height:%d,%d \n",forest->width,forest->height);
    
    forest->map=(char**) malloc(forest->width*sizeof(char*));
    for(i=0;i<forest->width;i++){
        forest->map[i]=(char*) malloc(forest->height*sizeof(char*));
    }
    i=0;
    j=0;

    for(i=0;i<forest->width;i++){
        for(j=0;j<forest->height;j++){
  
            if(j==9)
                fscanf(inp,"%c\n",&forest->map[i][j]);
            else
                fscanf(inp,"%c,",&forest->map[i][j]);    
        }
    }
            
    fclose(inp);
        
}
/*This function prints the map on screen*/
void print_map (Forest *forest){
    int i,j;
    for(i=0;i<forest->width;i++){
        for(j=0;j<forest->height;j++){
                printf("%c ",forest->map[i][j]);
        }
        printf("\n");
    }
}

/*Function that searches the flower recursively*/
void search (Forest *forest,Botanist *botanist){
    int random;
    int i,j;
    
    /*Finding random number to walk up, down, left and right*/
    srand(time(NULL));
    random=(rand()%4)+1;
    
    /*For loop to find coordinates where the botanist and flower are*/
    for(i=0;i<forest->width;i++){
        for(j=0;j<forest->height;j++){
            if(forest->map[i][j]=='B'){
                botanist->coord_x=i;
                botanist->coord_y=j;
            }
            else if(forest->map[i][j]=='F'){
                forest->flower_x=i;
                forest->flower_y=j;
            }
        }
    }
    
    /*If water bottle is empty botanist faints*/
    if(botanist->water_bottle_size==0){
        printf("Help! I am on (%d,%d)\n",botanist->coord_x,botanist->coord_y);
        print_map (forest);
    }
    else if(botanist->coord_x==forest->flower_x && botanist->coord_y==forest->flower_y){
        printf("I have found it on (%d,%d)!\n",botanist->coord_x,botanist->coord_y);
        print_map (forest);
    }
    else{
    
        if(random==1 && botanist->coord_x+1<forest->width && botanist->coord_x+1>=0){
            if(forest->map[botanist->coord_x+1][botanist->coord_y]==' ' || forest->map[botanist->coord_x+1][botanist->coord_y]=='F'
                ){
                
                forest->map[botanist->coord_x][botanist->coord_y]=' ';
                forest->map[botanist->coord_x+1][botanist->coord_y]='B';
                botanist->coord_x=botanist->coord_x+1;
                botanist->water_bottle_size--;
                //print_map(forest);
                  
            }
           
        }
        else if(random==2&&( botanist->coord_x-1 <forest->width && botanist->coord_x-1>=0)){ 
            if(forest->map[botanist->coord_x-1][botanist->coord_y]==' ' || forest->map[botanist->coord_x-1][botanist->coord_y]=='F'
               ){
               
                forest->map[botanist->coord_x][botanist->coord_y]=' ';
                forest->map[botanist->coord_x-1][botanist->coord_y]='B';
                botanist->coord_x=botanist->coord_x-1;
                botanist->water_bottle_size--;
                //print_map(forest);
                  
            }
           
        }
        else if(random==3&&botanist->coord_y-1 <forest->height &&botanist->coord_y-1>=0){
            if(forest->map[botanist->coord_x][botanist->coord_y-1]=' '|| forest->map[botanist->coord_x][botanist->coord_y-1]=='F'
          ){
          
                forest->map[botanist->coord_x][botanist->coord_y]=' ';
                forest->map[botanist->coord_x][botanist->coord_y-1]='B';
                botanist->coord_y=botanist->coord_y-1;
                botanist->water_bottle_size--;
                //print_map(forest);
                  
            }
            
        }
        else if(random==4 && (botanist->coord_y-1 <forest->height) &&(botanist->coord_y-1 >=0)){
            if(forest->map[botanist->coord_x][botanist->coord_y+1]==' ' || forest->map[botanist->coord_x][botanist->coord_y+1]=='F'
                 ){
             
                
               
                forest->map[botanist->coord_x][botanist->coord_y]=' ';
                forest->map[botanist->coord_x][botanist->coord_y+1]='B';
                botanist->coord_y=botanist->coord_y+1;
                botanist->water_bottle_size--;
                //print_map(forest);
                  
            
            
        }
        else
            search(forest,botanist);
        
        
    }


}

}
