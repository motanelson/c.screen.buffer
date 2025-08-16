#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 #include <unistd.h>
int main(){
    char *s="\033c\033[43;30m\nhello world...\n";
    FILE *f1=fopen("/dev/stdout","w");
    int i=strlen(s);
    fputs(s,f1);
    fclose(f1);

}
