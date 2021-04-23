#include<stdio.h> 
#include<string.h> 
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
    char command[20];
    char history[100][20];
    char path1[1024];
    char *path = getcwd(path1,1024);
    system("clear");
    printf("%s","-------------------------------------------");
    printf("\n");
    printf("%s \n","Welcome to this interactive Unix Shell");
    printf("%s","-------------------------------------------");
    printf("\n");
    int counter=0;
    while(1){
        FILE *f1;
        f1 = fopen("/mnt/c/users/verma/desktop/shell/history_new.txt","a");
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
            exit(0);
        }

        else if(command[0]=='p' && command[1]=='w' && command[2]=='d'){
            if(command[4]=='-' && command[5]=='-' && command[6]=='h' && command[7]=='e' && command[8]=='l' && command[9]=='p'){
                printf("pwd: pwd [-LP]\nPrint the name of the current working directory.\nOptions:\n-L        print the value of $PWD if it names the current working\ndirectory\n-P        print the physical directory, without any symbolic links\n");
            }
            else{
             printf("%s \n",getcwd(dir,1024));
            }
        }
        
        else if(command[0]=='h' && command[1]=='i' && command[2]=='s' && command[3]=='t' && command[4]=='o' && command[5]=='r' && command[6]=='y'){
           if(command[8]=='-' && command[9]=='c'){
                f1 = fopen("/mnt/c/users/verma/desktop/shell/history_new.txt","w");
                fclose(f1);
           }
           else if(command[8]=='-' && command[9]=='a'){
               
           }
           else{
               printf("%s","hello");
               char data[200];
               f1 = fopen("/mnt/c/users/verma/desktop/shell/history_new.txt","r");
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
                    printf("cd: cd [-L|[-P [-e]] [-@]] [dir] \n Change the shell working directory. \n Change the current directory to DIR.  The default DIR is the value of the \n HOME shell variable.\n");
                }
                else{
                if(commands[1][strlen(commands[1])-1]=='\\'){
                    commands[1][strlen(commands[1])-1]='\0';
                    char *make = commands[1];
                    char *space=" ";
                    for(int i=2;i<counter;i++){
                        strcat(make," ");
                        strcat(make,commands[i]);
                    }
                    int res= chdir(make);
                    if(res!=0) { 
                    perror(""); 
                }    
            }
            else{
                int res = chdir(commands[1]);
                if(res!=0)
                    perror("");
                }
            }
            }
            else if(strcmp(commands[0],"rm")==0){
                pid_t pid = fork();
                char *argv[counter+1];
                if(pid==0){
                for(int i=0;i<counter;i++){
                    argv[i] = commands[i];
                }
                argv[counter]=NULL;

                execvp(strcat(path,"/remove"),argv);
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
                execvp(strcat(path,"/ls"),argv);
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
                execvp(strcat(path,"/cat"),argv);
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
            
                execvp(strcat(path,"/mkdir"),argv);
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
                execvp(strcat(path,"/date"),argv);
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