#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define maxn 10

using namespace std;

int n;
int total,cnt;
int square[maxn][maxn];
int location[maxn*maxn][2];
struct sq{
    int num;
    double score;
    bool operator < (const sq &a)const{
        if (score<a.score) return 1;
            else return 0;
    }
}   s[900];
FILE *finfo = fopen("data/info.txt","r");
FILE *fin;
FILE *fout = fopen("rank.txt","w");

double ReadData(){
    char temp[20];
    double ret=0;
    memset(temp,0,sizeof(temp));
    sprintf(temp,"data/%d.txt",cnt);
    fin = fopen(temp,"r");
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++){
            fscanf(fin,"%d",&square[i][j]);
            location[square[i][j]][0] = i;
            location[square[i][j]][1] = j;
        }
    fclose(fin);
    for (int i=1;i<n*n;i++) ret += sqrt((location[i][0]-location[i+1][0])*(location[i][0]-location[i+1][0])+(location[i][1]-location[i+1][1])*(location[i][1]-location[i+1][1]));
    return ret;
}

int main(int argc, char *argv[]){
    fscanf(finfo,"%d%d",&n,&total);
    printf("%d\n",total);
    for (cnt=1;cnt<=total;cnt++){
        s[cnt].num = cnt;
        s[cnt].score = ReadData();
    }
    sort(s+1,s+total+1);
    for (int i=1;i<=total;i++) fprintf(fout,"%d %.2f\n",s[i].num,s[i].score);
    fclose(fout);
    return 0;
}
