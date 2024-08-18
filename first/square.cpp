#include"TXLib.h"
#include<stdio.h>
#include<math.h>
const double EPS = 0.00001;
void solve(double a,double b, double c, double x_1[],double x_2[]);

void solve(double a,double b, double c, double x_1[],double x_2[]){
    double D = b*b-4*a*c;
    if(abs(a)<EPS){
        printf("Not square\n");
        return;
    }
    if(abs(D)<EPS){
        x_2[0] = (-b)/(2*a);
        x_1[0] = (-b)/(2*a);
        x_1[1] = 0;
        x_2[1] = 0;
    }
    else if(D>0){
        x_1[0] = (-b+sqrt(D))/(2*a);
        x_2[0] = (-b-sqrt(D))/(2*a);
        x_1[1] = 0;
        x_2[1] = 0;
    }
    else{
        x_1[0] = (-b)/(2*a);
        x_2[0] = (-b)/(2*a);
        x_1[1] =  (sqrt(-D))/(2*a);
        x_2[1] =  (sqrt(-D))/(2*a);
    }
    printf("first is %.2lf + %.2lf i and second %.2lf - %.2lf i",x_1[0],x_1[1],x_2[0],x_2[1]);
}
int main(){
    double a,b,c;
    printf("enter coef in square equation\n");
    scanf("%lf %lf %lf",&a,&b,&c);
    double x_1[2],x_2[2];
    solve(a,b,c,x_1,x_2);
    return 0;
}
