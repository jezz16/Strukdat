#include<iostream>
#include<math.h>

using namespace std;

struct tiang1 {
    int data1;
    tiang1 *next1;
}*top1 = NULL, *t1 = NULL, *nt1 = NULL;

struct tiang2 {
    int data2;
    tiang2 *next2;
}*top2 = NULL, *t2 = NULL, *nt2 = NULL;

struct tiang3 {
    int data3;
    tiang3 *next3;
}*top3 = NULL, *p3 = NULL, *np3 = NULL;

void push1(int data) {
    nt1 = new tiang1;
    nt1->data1 = data;
    nt1->next1 = NULL;
    if (top1 == NULL)
    {
        top1 = nt1;
    }
    else
    {
        nt1->next1 = top1;
        top1 = nt1;
    }
}

int pop1() {
    int b = 999;
    if (top1 == NULL)
    {
        return b;
    }
    else
    {
        t1 = top1;
        top1 = top1->next1;
        return(t1->data1);
        delete(t1);
    }
}

void push2(int data) {
    nt2 = new tiang2;
    nt2->data2 = data;
    nt2->next2 = NULL;
    if (top2 == NULL)
    {
        top2 = nt2;
    }
    else
    {
        nt2->next2 = top2;
        top2 = nt2;
    }
}

int pop2() {
    int b = 999;
    if (top2 == NULL) {
        return b;
    }
    else {
        t2 = top2;
        top2 = top2->next2;
        return(t2->data2);
        delete(t2);
    }
}
void push3(int data) {
    np3 = new tiang3;
    np3->data3 = data;
    np3->next3 = NULL;
    if (top3 == NULL) {
        top3 = np3;
    }
    else {
        np3->next3 = top3;
        top3 = np3;
    }
}

int pop3() {
    int b = 999;
    if (top3 == NULL) {
        return b;
    }
    else {
        p3 = top3;
        top3 = top3->next3;
        return(p3->data3);
        delete(p3);
    }
}

int top_of_stack() {
    if(top1 != NULL && top1->data1 == 1) {
        return 1;
    }
    else if(top2 != NULL && top2->data2 == 1) {
        return 2;
    }
    else if(top3 != NULL && top3->data3 == 1) {
        return 3;
    }
    return 0;
}
void printTiang1()
{
    cout<<endl;
    tiang1 *t1;
    t1 = top1;
    cout<<"Tower1-> "<<"\t";
    while(t1 != NULL)
    {
        cout<<t1->data1<<"\t";
        t1 = t1->next1;
    }
    cout<<endl;
}

void printTiang2() {
    tiang2 *t2;
    t2 = top2;
    cout<<"Tower2-> "<<"\t";
    while(t2 != NULL) {
        cout<<t2->data2<<"\t";
        t2 = t2->next2;
    }
    cout<<endl;
}

void printTiang3() {
    tiang3 *p3;
    p3 = top3;
    cout<<"Tower3-> "<<"\t";
    while(p3 != NULL) {
        cout<<p3->data3<<"\t";
        p3 = p3->next3;
    }
    cout<<endl;
    cout<<endl;
}

void pemindahan(int n) {
    int i,x,a,b;
    for(i=0; i<(pow(2,n)); i++) {
        printTiang1();
        printTiang2();
        printTiang3();
        x = top_of_stack();
        
        if(i % 2 == 0) {
            if (x == 1) {
                push3(pop1());
            }
            else if (x == 2) {
                push1(pop2());
            }
            else if (x == 3) {
                push2(pop3());
            }
        }
        else {
            if(x == 1) {
                a = pop2();
                b = pop3();
                if(a < b && b != 999) {
                    push3(b);
                    push3(a);
                }
                else if(a > b && a != 999) {
                    push2(a);
                    push2(b);
                }
                else if(b == 999) {
                    push3(a);
                }
                else if(a == 999) {
                    push2(b);
                }
            }
            else if (x == 2) {
                a = pop1();
                b = pop3();
                if(a < b && b != 999) {
                    push3(b);
                    push3(a);
                }
                else if(a > b && a != 999) {
                    push1(a);
                    push1(b);
                }
                else if (b == 999) {
                    push3(a);
                }
                else if(a == 999) {
                    push1(b);
                }
            }
            else if(x == 3) {
                a = pop1();
                b = pop2();
                if(a < b && b != 999) {
                    push2(b);
                    push2(a);
                }
                else if(a > b && a != 999) {
                    push1(a);
                    push1(b);
                }
                else if(b == 999) {
                    push2(a);
                }
                else if (a == 999) {
                    push1(b);
                }
            }
        }
    }
}

int main()
{
    int n,i;
    cout<<"Tower Of Hanoi"<<endl;
    cout<<"Masukkan jumlah piringan : ";
    cin>>n;
    for(i=n; i>=1; i--)
    {
        push1(i);
    }
    pemindahan(n);
}