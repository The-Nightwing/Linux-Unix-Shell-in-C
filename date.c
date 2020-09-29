#include <time.h>
#include <stdio.h>
#include<string.h>

int main(int argc,char *argv[]){


struct tm* ptr; 
time_t lt;


if(strcmp(argv[1],"-u")==0){
     
    time(&lt); 
    ptr = gmtime(&lt); 
    char buf[100];
    strftime(buf,80,"%a %b %d %T UTC %Y", ptr);
    printf("%s\n",buf); 
}
else if(strcmp(argv[1],"-R")==0){
    time(&lt); 
    ptr = localtime(&lt); 
    char buf[100];
    strftime(buf,80,"%a, %d %b %Y %T %z", ptr);
    printf("%s\n",buf); 
}

else{
    time(&lt); 
    ptr = localtime(&lt); 
    char buf[100];
    strftime(buf,80,"%a %b %d %T %Z %Y", ptr);
    printf("%s\n",buf);  
}

    return 0;
}