#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<dirent.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char *argv[]) 
{ 
    struct dirent *file; 
    DIR *dirc = opendir("."); 

   
    if (dirc == NULL)  
    { 
        printf("Could not open current directory" );  
    } 

    if(strcmp(argv[1],"-m")==0){
        file = readdir(dirc);
        file = readdir(dirc);
         while ((file = readdir(dirc)) != NULL) {
             printf("%s, ",file->d_name);
        }
        closedir(dirc);   
    }

    else if(strcmp(argv[1],"-1")==0){
        file = readdir(dirc);
        file = readdir(dirc);
         while ((file = readdir(dirc)) != NULL) {
             printf("%s\n",file->d_name);
        }
         closedir(dirc);   
    }

    else{
 
        file = readdir(dirc);
        file = readdir(dirc);
         while ((file = readdir(dirc)) != NULL) {
             printf("%s  ",file->d_name);
        }
         closedir(dirc);   
    }
    printf("\n");
 

return 0; 
} 