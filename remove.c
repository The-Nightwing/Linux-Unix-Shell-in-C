#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>


int main(int argc,char *argv[]){
    if(argc==1 || (*argv[1])*(-1)==123){
    printf("%s\n","rm: missing operand");
    printf("%s \n","Try 'rm --help' for more information.");
    }
    else{
    if(strcmp(argv[1],"-f")==0){
        for(int i=2;i<argc;i++){
            unlink(argv[i]);
        }
    }

    else if(strcmp(argv[1],"-r")==0){
         if(argv[2][strlen(argv[2])-1]=='\\'){
            argv[2][strlen(argv[2])-1]='\0';
            char *make = argv[2];
            char *space=" ";
            for(int i=3;i<argc;i++){
                strcat(make," ");
                strcat(make,argv[i]);
            }
            int del = remove(make); 
            if(del==-1) { 
               perror(make); 
            }    
        }
        else{
        for(int i=2;i<argc;i++){
            int del = remove(argv[i]);
            if(del==-1){
                perror(argv[i]);
            }
        }
        }
    }
    else{
        char names[10][20];
        for(int i=1;i<argc;i++){
        int del = unlink(argv[i]);
        if(del==-1){
            perror(argv[i]);
        }
    }
    }
    }
return 0;
}