#include<stdio.h> 
#include<string.h> 
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
    char command[20];
    char history[100][20];
    system("clear");
    printf("%s","-------------------------------------------");
    printf("\n");
    printf("%s \n","Welcome to this interactive Unix Shell");
    printf("%s","-------------------------------------------");
    printf("\n");
    int counter=0;
    while(1){
        FILE *f1;
        f1 = fopen("history_new.txt","a");
        char dir[1024];
        printf("\033[1;32m"); 
        printf("%s","shivi_020@DESKTOP-IAF8LGN:");
        printf("\033[0m"); 
        printf("\033[1;34m");
        printf("%s",getcwd(dir,1024));
        printf("\033[0m"); 
        printf("%s ","$");
        scanf("%[^\n]%*c", command); 
        fprintf(f1, "%s", command);
        fprintf(f1,"\n");
        fclose(f1);
        if(command[0]=='e' && command[1]=='x' && command[2]=='i' && command[3]=='t'){
            //printf("%s \n","##Exiting, Bye!##");
            exit(0);
        }

        else if(command[0]=='p' && command[1]=='w' && command[2]=='d'){
            if(command[4]=='-' && command[5]=='-' && command[6]=='h' && command[7]=='e'){
                FILE *f1 = fopen("pwd_help.txt","r");
                char buf[100];
                while(fgets(buf,sizeof(buf),f1)){
                    printf("%s",buf);
                }
                printf("\n");
            }
            else{
             printf("%s \n",getcwd(dir,1024));
            }
        }
        
        else if(command[0]=='h' && command[1]=='i' && command[2]=='s' && command[3]=='t' && command[4]=='o' && command[5]=='r' && command[6]=='y'){
           char data[200];
           if(command[8]=='-' && command[9]=='c'){
                f1 = fopen("history_new.txt","w");
                fclose(f1);
           }
           else{
               f1 = fopen("history_new.txt","r");
                    int i=0;
                    while(fgets(data,sizeof(data),f1)){
                        printf("%d) %s",i,data);
                        i++;
                }
                fclose(f1);
           }
        }
        else{
            char *token;
            char commands[10][100];
            int i = 0;
            int counter=0;
            token = strtok(command," ");
            while(token!=NULL)
            {
                strcpy(commands[i],token);
                i++;
                counter++;
                token = strtok(NULL," ");
            }
            if(strcmp(commands[0],"echo")==0)
            {
                int j = 1;
                if(strcmp(commands[1],"-n")==0){
                int k=2;
                    while(k<i)
                    {
                        
                        printf("%s ", commands[k]);
                        k++;
                    }    
                }
            
                else if(strcmp(commands[1],"-E")==0){
                    int k=2;
                    while(k<i)
                    {
                        printf("%s ", commands[k]);
                        k++;
                    }    
                    printf("\n");
                }
                
                else{
                    int j = 1;
                    while(j<i)
                    {
                        printf("%s ", commands[j]);
                        j++;
                    } 
                    printf("\n");
                }
            }   
            
            else if(strcmp(commands[0],"cd")==0)
            {
                if(strcmp(commands[1],"~")==0 || strcmp(commands[1],"-P")==0 || counter==1){
                    chdir(getenv("HOME"));
                }
                else if(strcmp(commands[1],"--help")==0){
                    FILE *f1 = fopen("cd_help.txt","r");
                    char buf[100];
                    while(fgets(buf,sizeof(buf),f1)){
                    printf("%s",buf);
                }
                printf("\n");
                }
                else{
                int res = chdir(commands[1]);
                if(res!=0)
                    printf("-bash: %s: No such file or directory \n",commands[1]);
                }
            }
            else if(strcmp(commands[0],"rm")==0){
                if(counter>2 && (strcmp(commands[1],"-r") > 0 || strcmp(commands[1],"-f") >0)){
                    printf("Invalid flag: %s\n",commands[1]);
                    continue;
                }
                pid_t pid = fork();
                char *argv[counter+1];
                if(pid==0){
                for(int i=0;i<counter;i++){
                    argv[i] = commands[i];
                }
                argv[counter]=NULL;

                execvp(strcat(getcwd(dir,1024),"/remove"),argv);
                }
                else{
                    wait(NULL);
                }
            }
            else if(strcmp(commands[0],"ls")==0){
                pid_t pid = fork();
                char *argv[counter];
                if(pid==0){
                for(int i=0;i<counter;i++){
                    argv[i] = commands[i];
                }
                //printf("%s",getcwd(dir,1024));
                execvp(strcat(getcwd(dir,1024),"/ls"),argv);
                }
                else{
                    wait(NULL);
                }
            }
            else if(strcmp(commands[0],"cat")==0){
                pid_t pid = fork();
                char *argv[counter];
                if(pid==0){
                for(int i=0;i<counter;i++){
                    argv[i] = commands[i];
                }
                argv[counter]= 0;
                execvp(strcat(getcwd(dir,1024),"/cat"),argv);
                }
                else{
                    wait(NULL);
                }
            }
            else if(strcmp(commands[0],"mkdir")==0){
                if(counter==1){
                    printf("%s\n","mkdir: missing operand");
                    printf("%s \n","Try 'mkdir --help' for more information.");
                    continue;
                }
                pid_t pid = fork();
                char *argv[counter];
                if(pid==0){
                for(int i=0;i<counter;i++){
                    argv[i] = commands[i];
                }
                argv[counter] = NULL;
            
                execvp(strcat(getcwd(dir,1024),"/mkdir"),argv);
                }
                else{
                    wait(NULL);
                }
            }
            else if(strcmp(commands[0],"date")==0){
                pid_t pid = fork();
                char *argv[counter];
                if(pid==0){
                for(int i=0;i<counter;i++){
                    argv[i] = commands[i];
                }
                argv[counter+1]=NULL;
                //printf("%s",getcwd(dir,1024));
                execvp(strcat(getcwd(dir,1024),"/date"),argv);
                }
                else{
                    wait(NULL);
                }

            }
            else{
                printf("%s \n","Command not Found");
            }
        }
    }
    return 0;
}