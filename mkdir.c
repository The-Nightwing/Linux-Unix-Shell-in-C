#include <sys/types.h> 
#include <sys/stat.h>
#include <unistd.h> 
#include <stdio.h> 
# include <string.h>
#include <stdlib.h> 
  
int main(int argc, char* argv[])
{ 
    int check; 
   
    if(strcmp(argv[1],"--help") == 0){
        FILE *f1 = fopen("mkdir_help.txt","r");
        char buf[100];
    while(fgets(buf,sizeof(buf),f1)){
        printf("%s",buf);
    }
    printf("\n");
    }

    else if(strcmp(argv[1],"-v")==0){
         for(int i=2;i<argc;i++){
            check = mkdir(argv[i],0777); 
            if(check) { 
                printf("mkdir: cannot create directory ‘hello’: File exists\n"); 
            } 
            else{
                printf("mkdir: created directory '%s'",argv[i]);
            }
        }
    }
    else{
        for(int i=1;i<argc;i++){
            check = mkdir(argv[i],0777); 
            
            if(check) { 
                printf("mkdir: cannot create directory ‘hello’: File exists\n"); 
            } 
        }
    }
} 