
#include <string.h>
 #include <unistd.h>
int pfread(char *s,int i,int f1){
    
    return (int)read(f1,s,i);
}
void pfgets(char *s,int i,int f1){
    s[pfread(s,i-1,f1)-1]=0;
}
char pfgetc(int f1){
    char cc[4096]="\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
    pfread(cc,4095,f1);
    return (char)cc[0];
}
void pgets(char *s,int i){
    pfgets(s,i-1,0);
}
char pgetc(int f1){
    char cc[4096]="\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
    pfread(cc,4095,0);
    return (char)cc[0];
}

int main(){
    char ss[4096];
    char *s="\033c\033[43;30m\nget me a string\n";
    int i=strlen(s);
    write(1,s,i);
    pgets(ss,4095);
    i=strlen(ss);
    write(1,ss,i);
    //pgetc(0);
    return 0;
    
}
