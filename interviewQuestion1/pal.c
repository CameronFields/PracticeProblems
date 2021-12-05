#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


int getSize(char *pal){
	int i=0;
	while(pal[i]!='\0'){
		printf("%d\n", i);
		i++;
	}
	return i;
}

/*
bool palCheck(char *pal){


}*/




int main(){
	char *s1;
	scanf("%s", s1);
	printf("%c", &s1[0]);
	//printf("%d\n", getSize(s1));


}
