//Author: Caitlyn Aurand, Loghan Flanders, Ava Jones
//Date: 12/3/24
//Purpose: create a madlibs game 

#include <stdio.h>
#define INPUT_FILE "madlib3.txt"
#define ROW 100
#define COL 1000

void char_count(FILE *input,char saved[ROW][COL],int* rows);
void scrubber(char saved[ROW][COL],int rows);
void promptUser(char saved[ROW][COL], int rows);
int getWord(char buffer[], char type);
void addTrailingSpace(char buffer[]);
void addLeadingSpace(char buffer[]);
void replaceNewlines(char saved[ROW][COL], int rows);
int main(){
	char saved[ROW][COL];
	int letters=0,debug=0;
	FILE *fp1;
 	fp1=fopen(INPUT_FILE,"r");
   	if(fp1==NULL){
    	printf("failed to find file");
    	return 1;
   }
   char_count(fp1,saved,&letters);
    // while(debug<20){
	// 	printf("%s\n",saved[debug]);
	// 	debug++;
	// }
   fclose(fp1);
   //printf("%d\n",letters);
   promptUser(saved, letters);
   replaceNewlines(saved, letters);
   scrubber(saved,letters);
	return 0;
}
void char_count(FILE *input,char saved[ROW][COL],int* rows){
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
            scanf(" %s", buffer);
            addTrailingSpace(buffer);
            addLeadingSpace(buffer);
        break;
        case 'N': 
            printf("Please enter a noun:\n");
            scanf(" %s", buffer);
            addTrailingSpace(buffer);
            addLeadingSpace(buffer);
        break;
        case 'V': 
            printf("Please enter a verb:\n");
            scanf(" %s ", buffer);
            addTrailingSpace(buffer);
            addLeadingSpace(buffer);
        break;
    }
    return done;
}
void replaceNewlines(char saved[ROW][COL], int rows){
    for(int i=0;i<rows;i++){
		for(int j=0;j<COL;j++){
            if(saved[i][j] == '\n'){
                saved[i][j] = '\0';
            }
        }
    }
}
void scrubber(char saved[ROW][COL],int rows){
	for(int i=0;i<rows;i++){
	    printf("%s",saved[i]);
	}
}
void addTrailingSpace(char buffer[]){
    int i;
    for(i = 0; buffer[i] != '\0'; i++){}
    buffer[i] = ' ';
    buffer[i+1] = '\0';
}
void addLeadingSpace(char buffer[]){
    int i = 0;
    while(buffer[i] != '\0'){
        i++;
    }
    while(i >= 0){
        buffer[i + 1] = buffer[i];
        i--;
    }
    buffer[0] = ' ';
}