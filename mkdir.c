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
        printf("Usage: mkdir [OPTION]... DIRECTORY...\nCreate the DIRECTORY(ies), if they do not already exist.\n");
    }

    else if(strcmp(argv[1],"-v")==0){
         if(argv[2][strlen(argv[2])-1]=='\\'){
            argv[2][strlen(argv[2])-1]='\0';
            char *make = argv[2];
            char *space=" ";
            for(int i=3;i<argc;i++){
                strcat(make," ");
                strcat(make,argv[i]);
            }
            check = mkdir(make,0777); 
            if(check) { 
               perror(make); 
            }    
            else{
                printf("mkdir: created directory '%s' \n",make);
            }
        }
        else{
         for(int i=2;i<argc;i++){
            check = mkdir(argv[i],0777); 
            if(check) { 
                perror(argv[i]); 
            } 
            else{
                printf("mkdir: created directory '%s' \n",argv[i]);
            }
        }
    }
    }
    else{
        
        if(argv[1][strlen(argv[1])-1]=='\\'){
            argv[1][strlen(argv[1])-1]='\0';
            char *make = argv[1];
            char *space=" ";
            for(int i=2;i<argc;i++){
                strcat(make," ");
                strcat(make,argv[i]);
            }
            check = mkdir(make,0777); 
            if(check) { 
               perror(make); 
            }    
        }
        else{
        for(int i=1;i<argc;i++){
            check = mkdir(argv[i],0777); 
            if(check) { 
               perror(argv[i]); 
            } 
        }
        }
    }

    return 0;
} 