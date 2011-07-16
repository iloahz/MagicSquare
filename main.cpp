#include <cstdio>
#include <cstring>

#define maxn 10

using namespace std;

int n;
int total;
int sum;
int square[maxn*maxn];
int h[maxn*maxn];
FILE *finfo = fopen("data/info.txt","w");
FILE *fout;

void dfs(int x){
    if (x%n==1 && x>n){
        int i,s=0;
        for (i=x-1;i>=x-n;i--) s+=square[i];
        if (s!=sum) return;
    }
    if (x>n*(n-1)+1){
        int i,s=0;
        for (i=x-1;i>=1;i-=n) s+=square[i];
        if (s!=sum) return;
    }
    if (x==n*n+1){
        int i,s=0;
        for (i=1;i<=n*n;i+=n+1) s+=square[i];
        if (s!=sum) return;
        s=0;
        for (i=n;i<=n*(n-1)+1;i+=n-1) s+=square[i];
        if (s!=sum) return;
        total++;
        printf("%d\n",total);
        char temp[20];
        sprintf(temp,"data/%d.txt",total);
        fout = fopen(temp,"w");
        for (int i=1;i<=n*n;i++)
            if (i%n) fprintf(fout,"%d ",square[i]);
                else fprintf(fout,"%d\n",square[i]);
        fclose(fout);
    }
    for (int i=1;i<=n*n;i++)
        if (h[i]==0){
            square[x]=i;
            h[i]=1;
            dfs(x+1);
            h[i]=0;
        }
}

int main(int argc, char *argv[]){
    n = 3;
    sum = n*(n*n+1)/2;
    total = 0;
    memset(h,0,sizeof(h));
    dfs(1);
    fprintf(finfo,"%d\n%d\n",n,total);
    return 0;
}
