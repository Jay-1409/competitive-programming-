#include<stdio.h>
#include<string.h>
int wordCount(char txt[]);
int lineCount(char txt[]);
int charCount(char txt[]);
void mostFreq(char txt[]);
int avgWordlen(char txt[]);

int main(){
	char txt[100000];
	fgets(txt,100000,stdin);
	printf("NUMBER OF WORDS: %d \n",wordCount(txt));
	printf("NUMBER OF LINES: %d (THE NUMBER OF LINES DEPENDS ON THE SIZE OF WINDOW) \n",lineCount(txt));
	printf("NUMBER OF CHARACTERS: %d \n",charCount(txt));
	printf("AVERAGE LENGTH OF WORDS: %d \n",avgWordlen(txt));
//	printf("COULD NOT SOLVE: HOW TO FIND THE MOST FREQUENT WORD");
	mostFreq(txt);
}
void mostFreq(char txt[]){
	int buff[500];
	int j,i;
	for(i=0;i<charCount(txt);i=j+2){
		int sum=0;
		for(j=i;txt[j]!=' ';j++){
			sum=sum+txt[j];
		}
		printf("%d\n",sum);
	}

	
}
//void mostFreq(char txt[]){
//	int j,i;
//	int buff[500][500];
//	int size= charCount(txt);
//	for(i=0;i<size;i++){
//		for(j=0;txt[i+j]!=' ';j++){
//			buff[i][j]=(int)txt[i+j];
//			printf("%d\n",buff[i][j]);
//			i++;
//		}
//	}
//	
//}
int avgWordlen(char txt[]){
	int totalw = wordCount(txt);
	int totalc = charCount(txt);
	return totalc/totalw;
}
int charCount(char txt[]){
	int count=0;
	for(int i=0;txt[i]!='\0';i++){
		count++;
	}
	return count-1;
}
int wordCount(char txt[]){
	int count=0	; int isWord=0;
    for (int i =0; txt[i] != '\0'; i++) {
        if (txt[i] == ' ' || txt[i] == '\n' || txt[i] == '\t') {
            isWord = 0;
        } else if (isWord== 0) {
            isWord = 1;
            count++;
        }
    }
	return count;	
}
int lineCount(char txt[]){
	int count=1;
	for(int i=0;txt[i]!='\0';i++){
	if(txt[i]=='.'){
		count++;
	}	
	}
	return count;
} 
