#include <cstdio>

using namespace std;

FILE *fin = fopen("1-100.txt","r");
FILE *fout;

int main(){
    int i,j,k;
    for (i=1;i<=200;i++){
        char temp[20];
        fscanf(fin,"No.%d",&j);
        sprintf(temp,"%d.txt",j);
        fout = fopen(temp,"w");
        for (j=1;j<=16;j++){
            fscanf(fin,"%d",&k);
            if (j%4) fprintf(fout,"%d ",k);
                else fprintf(fout,"%d\n",k);
        }
        fclose(fout);
    }
    return 0;
}
