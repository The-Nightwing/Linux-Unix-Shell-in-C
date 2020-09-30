#include<stdio.h> 
#include<string.h> 
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>


int main(int argc,char *argv[])
{
    FILE *f1;



    if(strcmp(argv[1],"-n")==0){
        int j=0;
        for(int i=2;i<argc;i++){
        f1 = fopen(argv[i],"r");
        if(f1==NULL){
            printf("cat: %s: No such file or directory\n",argv[i]);
        }
        else{
        char line[200];
        while(fgets(line,sizeof(line),f1)){
            printf("%d %s",++j,line);
        }
        fclose(f1);
        }
    }
    }

    else if(strcmp(argv[1],"-E")==0){
    for(int i=2;i<argc;i++){
        f1 = fopen(argv[i],"r");
        if(f1==NULL){
            printf("cat: %s: No such file or directory\n",argv[i]);
        }
        else{
        char line[200];
        while(fgets(line,sizeof(line),f1)){
            line[strlen(line)-1] = '\0';
            printf("%s%c\n",line,'$');
        }
        fclose(f1);
        }
    }
    }
    else{
         for(int i=1;i<argc;i++){
        f1 = fopen(argv[i],"r");
        if(f1==NULL){
            printf("cat: %s: No such file or directory\n",argv[i]);
        }
        else{
        char line[200];
        while(fgets(line,sizeof(line),f1)){
            printf("%s",line);
        }
        fclose(f1);
        printf("\n");
        }
    }
    }

return 0;
}