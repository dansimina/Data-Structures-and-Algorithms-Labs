#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <graphics.h>

using namespace std;
char a[100][10];//in a vom avea atomii lexicali
int na,p=1; //na=nr. de atomi, p=pozitia unde am ajuns cu evaluatul
char semne[]="+-*/()";
int c1=1, c2=15, c3=3, dx=160, dy=40, rx=20, ry=10;
typedef struct nod
{
    char op;
    int x;
    nod *st,*dr;
} *pnod;
pnod cap;

// adauga un atom lexical in vector
void addatom(char *s)
{
    na++;
    strcpy(a[na],s);
}

// preia sirul si creeaza vectorul cu atomi lexicali
void atomizeaza(char *s)
{
    char x[10];
    int i,j;
    na=0;//nu avem atomi lexicali la inceput
    i=0;
    while(i<strlen(s))
    {
        if(strchr(semne,s[i])>0)
        {
            x[0]=s[i];
            x[1]=0;
            i++;
            addatom(x);
        }
        else
        {
            j=0;
            while(i<strlen(s)&&strchr(semne,s[i])==0)
                x[j++]=s[i++];
            x[j]=0;
            addatom(x);
        }
    }
}
pnod termen();
pnod factor();
pnod expresie()
{
    pnod b,c;
    char o;
    b=termen();
    while((a[p][0]=='+')||(a[p][0]=='-'))
    {
        o=a[p][0];
        p++;
        c=termen();
        b=new nod({o,0,b,c});
    }
    return b;
}
pnod termen()
{
    pnod b,c;
    char o;
    b=factor();
    while((a[p][0]=='*')||(a[p][0]=='/'))
    {
        o=a[p][0];
        p++;
        c=factor();
        b=new nod({o,0,b,c});
    }
    return b;
}
pnod factor()
{
    long x,y;
    pnod f;
    if(a[p][0]=='(')
    {
        p++;
        f=expresie();
        if(a[p][0]!=')')cout<<"lipsa";
        p++;
    }
    else
    {
        x=atof(a[p]);
        p++;
        f=new nod({' ',x,NULL,NULL});
    }
    return f;
}
float eval(pnod p)
{
    if(!p)return 0;
    else if((p->st==NULL)&&(p->dr==NULL))return p->x;
    else
    {
        if(p->op=='+')p->x=eval(p->st)+eval(p->dr);
        if(p->op=='-')p->x=eval(p->st)-eval(p->dr);
        if(p->op=='*')p->x=eval(p->st)*eval(p->dr);
        if(p->op=='/')p->x=eval(p->st)/eval(p->dr);
        return p->x;
    }
}
void kaput(pnod p)
{
    if(p)
    {
        kaput(p->st);
        kaput(p->dr);
        delete p;
    }
}
void afis(pnod p, int n, int x, int y)
{
    char s[12]= {0,0,0,0,0,0,0,0,0,0,0,0};
    if(p==NULL) return;
    setcolor(c1);
    setfillstyle(1,n);
    fillellipse(x,y,rx,ry);
    if(p->op==' ')itoa(p->x,s,10);
    else s[0]=p->op;
    setcolor(c2);
    outtextxy(x-4*strlen(s),y+8,s);
    if(p->st!=NULL)
    {
        setcolor(c1);
        line(x,y,x-dx/n,y+dy);
        setfillstyle(1,n);
        fillellipse(x,y,rx,ry);
        setcolor(c2);
        setbkcolor(n);
        outtextxy(x-4*strlen(s),y+8,s);
        afis(p->st,n+1,x-dx/n,y+dy);
    }
    if(p->dr!=NULL)
    {
        setcolor(c1);
        line(x,y,x+dx/n,y+dy);
        setfillstyle(1,n);
        fillellipse(x,y,rx,ry);
        setcolor(c2);
        setbkcolor(n);
        outtextxy(x-4*strlen(s),y+8,s);
        afis(p->dr,n+1,x+dx/n,y+dy);
    }
}
void afisare(pnod cap)
{
    int gd = DETECT, gm;
    initgraph (&gd, &gm, "");
    setbkcolor(15);
    cleardevice();
    settextjustify(0,0);
    setfillstyle(1,c1);
    afis(cap,1,320,20);
    getch();
    closegraph();
}
int main()
{
    int i;

    char sir[300];
    cout <<"Introdu expresia:";
    cin.getline(sir,300);
    atomizeaza(sir);
    cap=expresie();
    cout<<"\n";
    cout << eval(cap);
    afisare(cap);
    return 0;
}
