#include <QtGui/QApplication>
#include <QtGui/QPainter>
#include <QtGui/QPixmap>
#include <QWidget>
#include <cstdio>
#include <cstring>
#include <iostream>

#define maxn 10
#define pixelx 400
#define pixely 400

using namespace std;

int n;
int total,count;
int square[maxn][maxn];
int location[maxn*maxn][2];
FILE *finfo = fopen("../data/info.txt","r");
FILE *fin;

void ReadData(){
    char temp[20];
    memset(temp,0,sizeof(temp));
    sprintf(temp,"../data/%d.txt",count);
    fin = fopen(temp,"r");
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++){
            fscanf(fin,"%d",&square[i][j]);
            location[square[i][j]][0] = i;
            location[square[i][j]][1] = j;
        }
    fclose(fin);
}

void Draw(){
    QPixmap *pixmap = new QPixmap(pixelx,pixely);
    QPainter *painter = new QPainter(pixmap);
    painter->begin(pixmap);
    painter->setViewport(0,0,pixelx,pixely);
    painter->setWindow(0,0,n+1,n+1);
    painter->setPen(Qt::NoPen);
    painter->setBrush(QBrush(Qt::white,Qt::SolidPattern));
    painter->drawRect(0,0,pixelx,pixely);
    painter->setPen(Qt::lightGray);
    for (int i=0;i<=n;i++) painter->drawLine(QPointF(0.5,i+0.5),QPointF(n+0.5,i+0.5));
    for (int i=0;i<=n;i++) painter->drawLine(QPointF(i+0.5,0.5),QPointF(i+0.5,n+0.5));
    painter->setPen(Qt::black);
    for (int i=1;i<n*n;i++){
        painter->drawLine(location[i][0],location[i][1],location[i+1][0],location[i+1][1]);
    }
    painter->end();
    char temp[20];
    sprintf(temp,"../picture/%d.jpg",count);
    pixmap->save(temp,0,100);
}

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    fscanf(finfo,"%d%d",&n,&total);
    for (count=1;count<=total;count++){
        ReadData();
        Draw();
    }
    return 0;
    return a.exec();
}
