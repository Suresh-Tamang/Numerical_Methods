#include<stdio.h>
#include<conio.h>
#include<math.h>
# define f(x) 4*exp(-x)*sin(x)-1

void main(){
	float x0,x1,x2,f0,f1,f2,e;
	int iteration = 1;
	up:
		printf(" \nEnter two initial guesses : \n");
		scanf("%f%f",&x0,&x1);
		printf("\n Enter tolerable error : \n");
		scanf("%f",&e);
		f0 = f(x0);
		f1 = f(x1);
		
		if(f0 * f1 >0.0){
			printf("Incorrct initial guesses, \n");
			goto up;
		}
		printf("\nIteration \t\t x0 \t\t x1 \t\t x2=(x0+x1)/2 \t\t f(x2)\n");
		do{
			x2 = (x0+x1)/2;
			f2 = f(x2);
			printf("%d\t\t %f \t\t %f \t\t %f \t\t %f \t\t\n",iteration,x0,x1,x2,f2);
			if(f0 * f2 <0){
				x1 = x2;
				f1 = f2;
			}
			else{
				x0 = x2;
				f0 = f2;
			}
			iteration = iteration + 1;		
			}while(fabs(f2)>e);
		printf("\nRequired root of the equation is : %f ",x2);
		getch();
	}