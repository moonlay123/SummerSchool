#include<stdio.h>
#include<math.h>
const double EPS = 0.00001;
void solve(double a,double b, double c, double x_1[],double x_2[]);

void solve(double a,double b, double c, double x_1[],double x_2[]){
    double D = b*b-4*a*c;
    double sqrtD = sqrt(abs(D));

    if (abs(a)<EPS) {
        x_1[0] = (-c/b);

        printf("Only one real root\n");
        printf("%.2lf",x_1[0],x_1[1]);

        return;
    }
    if (abs(D)<EPS) {
        x_1[0] = (-b)/(2*a);
        x_2[0] = (-b)/(2*a);

        printf("Two similar real roots\n");
    }
    else if (D>0){
        x_1[0] = (-b+sqrtD)/(2*a);
        x_2[0] = (-b-sqrtD)/(2*a);

        printf("two unique roots\n");
    }

    else {
        x_1[0] = (-b)/(2*a);
        x_1[1] =  (sqrtD)/(2*a);

        x_2[0] = (-b)/(2*a);
        x_2[1] =  (sqrtD)/(2*a);

        printf("two complex roots\n");
    }

    printf("first root  %.2lf + %.2lf i \nsecond root %.2lf - %.2lf i",x_1[0],x_1[1],x_2[0],x_2[1]);
}

int main(){
    double a=0,b=0,c=0;

    printf("enter coef in square equation\n");
    scanf("%lf %lf %lf",&a,&b,&c);

    double x_1[2]={0,0},x_2[2]={0,0};
    solve(a,b,c,x_1,x_2);

    return 0;
}
