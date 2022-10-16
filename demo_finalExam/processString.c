#include<stdio.h>
#include<string.h>


#define max 256

void clearBreak(char a[])
{
    if(strlen(a) > 0 && a[strlen(a) - 1] == '\n')
    {
       a[strlen(a) - 1] = '\0';
    }
}

void replaceSubstring(char* sub, char* new, char* String){
    int flag, start, end;
    int stringLen = strlen(String), subSize = strlen(sub), newSize = strlen(new);
    for(int i = 0; i < stringLen; i++){
        flag = 0, start = i;
        for (int j = 0; String[i] == sub[j]; i++, j++){
            if( j == (subSize - 1)){
                flag = 1, end = i;
            }

            if(flag ==  0){
                i -= j;
            }
            else{
                for( j = start; j < end; j++){
                    for(int k =  start; k < stringLen; k++){
                        String[k] = String[k+1];
                        stringLen --;
                        i--;
                    }
                }
                for(j = start; j < start+newSize; j++){
                    for(int k = stringLen; k >= j; k--)
                    String[k+1]=String[k];
                    String[j] = new[j-start];
                    stringLen++;
                    i++;
                }
            }
        }
     }
}


int main(){
    char P1[max], P2[max], T[max];
    fgets(P1, sizeof P1, stdin);
    clearBreak(P1);
    fgets(P2, sizeof P2, stdin);
    clearBreak(P2);
    fgets(T, sizeof T, stdin);
    clearBreak(T);

    replaceSubstring(P1, P2, T);
    printf("%s", T);

    return 0;
}