#include <string.h>
#include <unistd.h>
void pfwrite(char *s,int i,int f1){
    write(f1,s,i);
}
void pfputs(char *s,int f1){
    int i=strlen(s);
    pfwrite(s,i,f1);
}
void pputs(char *s){
    pfputs(s,1);
}

void pfputc(char c,int f1){
    char s[]=" \0\0\0";
    s[0]=(char)c;
    pfwrite(s,1,f1);
}

void pputc(char c){
    pfputc(c,1);
}
void pfprintf(char *s,int f1){
    int c=0;
    char *integers=" integer \0";
    while (s[c]!=0){
        if (s[c]!='%'){
            pfputc(s[c],f1);
        }else{
            pfputs(integers,f1);
        }
        
        c++;
    }

}
void pprintf(char *s){
    pfprintf(s,1);
}
void pperror(char *s){
    pfputs(s,2);
}
int main(){
    char *s="\033c\033[43;30m\nhello world...\n";
    pputs(s);
    pprintf("xx%xxxx%xx\n");
    pperror("err:>simulate a error\n");  
}
