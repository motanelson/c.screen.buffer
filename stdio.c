#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define true 1
#define false 0
int file_input=false;
int file_output=false;
int file_error=false;
void file_open(int i){
    if(i==0)file_input=true;
    if(i==1)file_output=true;
    if(i==2)file_error=true;

}
void init(){
    file_open(2);
    file_open(1);
    file_open(2);

}
void file_write(int f1,char *c){
    if(f1==1 && file_output)printf("stdout:>%s\n",c);
    if(f1==2 && file_output)printf("stderr:>%s\n",c);
}
void file_close(int i){
    if(i==0)file_input=false;
    if(i==1)file_output=false;
    if(i==2)file_error=false;


}
int main(){
   printf("\033c\033[43;30m\n");
   init();
   file_write(1,"hello world...");
   file_write(2,"error message....");
   file_close(1);
   file_write(1,"hello world...");
  
   return 0;
}
