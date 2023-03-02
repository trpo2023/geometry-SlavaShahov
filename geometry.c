#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    int SpaceCount=0;
    int Zcount;
    int Pcount;
    char Str[100]="circle(0 0, 1.5)";
    char BeginStr[8]="circle(";
    char OurStr[256];
    //printf("%s",Str+7);
    if(strncmp(Str,BeginStr,7)!=0){
        printf("Error column 1 expected: 'circle('");puts("\n");
        printf("%s\n", Str);
        for(int i=0; i<strlen(BeginStr); i++){
            if(Str[i]==BeginStr[i]){
                printf(" ");
            }else {printf("^"); break;}
        }
        return 0;
    }else{
       strncpy(OurStr,Str+7,strlen(Str)-7);
       int flagS=0;
       for(int i=0;i<strlen(OurStr);i++){
           if((OurStr[i]==')')&&(i!=strlen(OurStr)-1)){
               printf("Error column %d too many brackets or the characters are outside the parenthesis",i+8);puts("\n");
               printf("%s\n", Str);
               return 0;
           }
           if((OurStr[i]==' ')&&(flagS!=2)){
               flagS=1;
               
           }
           if(OurStr[i]==','){
               if(flagS!=1){
                   printf("Error column %d expected: 'circle(int int, float)' ",i+8);
                   
               }
                if(flagS==1){
                    flagS++;
                    if(OurStr[i+1]!=' '){
                        printf("Error column %d 'circle(int int, float)'",i+8);
                        return 0;
                        
                    }
                    
                }
               
           }
           if(OurStr[i]=='.'){
               if(flagS!=2){
                   printf("Error column %d 'circle(int int, float)'",i+8);
                   return 0;
                   
               }else{
                   flagS=3;
               }
               
           }
           
       }
   }   
   //int BracketsRevCount=0;
   for(int i=0;i<strlen(OurStr);i++){
       if(OurStr[i]==' '){
           SpaceCount++;
           if(SpaceCount>2)printf("Error column %d too many spaces",i+8);
           return 0;
           
       }
       if ((OurStr[i] >= 'a') && (OurStr[i] <='z')) {
           printf(" Error column %d expected: 'circle(int int, float)' ",i+8);
           return 0;
       }
       if(OurStr[i]==','){
           Zcount++;
           if(Zcount>1)printf("Error column %d too many commas",i+8);
           return 0;
       }
       if(OurStr[i]=='.'){
           Pcount++;
           if(Pcount>1)printf("Error column %d too many points",i+8);
           return 0;
       }
       if(OurStr[i]=='('){
           printf("Error column %d too many brackets",i+8);
           return 0;
       }
	}
}
