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
        for(int i=2;i<argc;i++){
            int del = remove(argv[i]);
            if(del==-1){
                printf("rm: cannot remove '%s': No such file or directory \n",argv[i]);
            }
        }
    }
    else{
        char names[10][20];
        for(int i=1;i<argc;i++){
        int del = unlink(argv[i]);
        if(del==-1){
            printf("rm: cannot remove '%s': No such file or directory\n",argv[i]);
        }
    }
    }
    }
return 0;
}