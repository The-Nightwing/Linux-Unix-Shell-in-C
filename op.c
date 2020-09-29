#include<stdio.h> 
#include<string.h> 
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>


int main(){
    
    char command[20];
    scanf("%[^\n]%*c", command); 
    printf("%s",command);

    if(strcmp(command,"cd")==0){
        printf("..");
    }

    return 0;
}