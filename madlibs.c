//Author: Caitlyn Aurand, Loghan Flanders, Ava Jones
//Date: 12/10/24
//Purpose: create a madlibs game 

#include <stdio.h>
#define INPUT_FILE "madlib2.txt"
#define ROW 100
#define COL 1000

void readFile(FILE *input,char saved[ROW][COL],int* rows);
void promptUser(char saved[ROW][COL], int rows);
int getWord(char buffer[], char type);
void replaceNewlines(char saved[ROW][COL], int rows);
void finalize(char saved[ROW][COL], char final[], int rows);
void print(char final[]);
int main(){
   char saved[ROW][COL];
   char final[ROW*COL];
   int row_count=0,debug=0;
   FILE *fp1;
   fp1=fopen(INPUT_FILE,"r");
   if(fp1==NULL){
    	printf("failed to find file");
    	return 1;
   }
   readFile(fp1,saved,&row_count);
   fclose(fp1);
   promptUser(saved, row_count);
   replaceNewlines(saved, row_count);
   finalize(saved, final, row_count);
   print(final);
	return 0;
}
void readFile(FILE *input,char saved[ROW][COL],int* rows){
	int count_rows=0;
	while(fgets(saved[count_rows],COL,input) != NULL){
		count_rows++;
	}
	*rows=count_rows;
}
void promptUser(char saved[ROW][COL], int rows){
    for(int i=0;i<rows;i++){
        if(saved[i][1]=='\n'){
            getWord(saved[i], saved[i][0]);
        }
	}
}
int getWord(char buffer[], char type){
    int done = 0;
    switch(type){
        case 'A': 
            printf("Please enter an adjective:\n");
            scanf("%s", buffer);
        break;
        case 'N': 
            printf("Please enter a noun:\n");
            scanf("%s", buffer);
        break;
        case 'V': 
            printf("Please enter a verb:\n");
            scanf("%s", buffer);
        break;
    }
    return done;
}
void replaceNewlines(char saved[ROW][COL], int rows){
    for(int i=0;i<rows;i++){
		for(int j=0;j<COL;j++){
            //when fgets reads in a line it stores "\n" and then "\0"
            if(saved[i][j] == '\n'){
                saved[i][j] = '\0';
                break;
            }
        }
    }
}
void finalize(char saved[ROW][COL], char final[], int rows){
    int cursor = 0;
    for(int i=0;i<rows;i++){
        int j = 0;
        if(i != 0 && !(saved[i][j] == '.' || saved[i][j] == '!' || saved[i][j] == '?')){
            final[cursor++] = ' ';
        }
	    while(saved[i][j]!='\0'){
            final[cursor++] = saved[i][j];
            j++;
        }
    }
    final[cursor] = '\0';
}
void print(char final[]){
    int cursor = 0;
    while(final[cursor]!='\0'){
        printf("%c", final[cursor++]);
    }
    printf("\n");
}
