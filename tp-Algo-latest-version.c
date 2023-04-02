#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include<math.h>

bool testPremA1 (  unsigned long long n ){
    int i,j;
    bool premier;
    clock_t t1,t2;
    double delta;
    premier=true;
float somme , moy; 
somme =0;
for (j=0;j< 20;j++){

    t1 = clock();
    i=2;
    while(i<n && premier){
        if(n % i == 0){
            premier=false;
        }else {
        i++;}
    }
    t2 = clock();
    delta = (double) (t2-t1)/CLOCKS_PER_SEC ;

   printf("  %lf\n",delta);
        somme=somme+delta;
}
moy = somme / 20;
printf("La moyenne est :%f\n",moy);
   return premier;


}
bool testPremA2 (  unsigned long long n){
    int i,j;
    double delta;
    bool premier;
    clock_t t1,t2;

float somme , moy; 
somme =0;
for (j=0;j< 20;j++){
    t1 = clock();
    premier=true;
    i=2;
    while(i<=n/2 && premier==true){
        if(n % i == 0){
            premier=false;
        }
        else {
        i++;}
    }
    t2 = clock();
    delta = (double) (t2-t1)/CLOCKS_PER_SEC ;

    printf("  %lf\n",delta);
         somme=somme+delta;
}
moy = somme / 20;
printf("La moyenne est :%f\n",moy);
    return premier;

}

bool testPremA3 (  unsigned long long n ){
    int i,j;
    bool premier;
    clock_t t1,t2;
    double delta;

float somme , moy; 
somme =0;
for (j=0;j< 20;j++){

    t1 = clock();
    premier=true;
    i=2;
    while(i<=sqrt(n) && premier==true){
        if(n % i == 0){
            premier=false;
        }else {
        i++;}
    }
    t2 = clock();
    delta = (double) (t2-t1)/CLOCKS_PER_SEC ;
    printf("  %lf\n",delta);
         somme=somme+delta;
}
moy = somme / 20;
printf("La moyenne est :%f\n",moy);
    return premier;
    


}

bool testPremA4 (  unsigned long long n){
    int i,j;
    double delta;
    bool premier;
    clock_t t1,t2;
    premier=true;
 
float somme , moy; 
somme =0;
for (j=0;j< 20;j++){
    t1 = clock();


    if(n!=2 && n%2==0){
         premier=false;
    }
    else{ if(n!=2) {
    i=3;
    while(i<=n-2 && premier){
        if( n % i ==0){
            premier=false;
        }
        else{
        i=i+2;}
    }}}
    t2 = clock();
    delta = (double) (t2-t1)/CLOCKS_PER_SEC ;
    printf("  %lf\n",delta);
     somme=somme+delta;
}
moy = somme / 20;
printf("La moyenne est :%f\n",moy);
    return premier;

}
bool testPremA5 (unsigned long long n )
{
 int j,i;
 bool premier;
 clock_t t1, t2 ;
 double delta ;
float somme , moy; 
somme =0;
for (j=0;j< 20;j++){
  t1 = clock();
  premier=true;

    if(n!=2 && n%2==0){
         premier=false;
    }
   else { if(n!=2) {
       i=3;
       while(i<=n/2 && premier){
        if(n%i==0){
            premier=false;
        }
        else {
            i=i+2;
        }
       }
    }}

   t2 = clock();
   delta = (double) (t2-t1)/CLOCKS_PER_SEC ;
   printf("  %lf\n",delta);
 somme=somme+delta;
}
moy = somme / 20;
printf("La moyenne est :%f\n",moy);
   return premier;

}
bool testPremA6 ( unsigned long long n )
{   int i,j ;
float somme , moy; 
somme =0;
    bool premier;
    clock_t t1, t2 ;
    double delta ;
for (j=0;j< 20;j++){
    	t1 = clock();
  premier=true;
    if (n != 2 && n % 2 == 0)
    { premier = false ;
	}
   else
   {
     if (n!=2){
     	i =3;
     	while (i<= sqrt(n) &&  premier == true){
     		if(n %i == 0 ){
			 premier =false ;
			 }
			 else {
			 premier = true ;
			 }
			 i =i+2;
		 }
	 }
   }
   t2 = clock();
   delta = (double) (t2-t1)/CLOCKS_PER_SEC ;
   printf("  %lf\n",delta);
   somme=somme+delta;
}
moy = somme / 20;printf("La moyenne est :%f\n",moy);

   return premier;

}



int main()
{
    unsigned long long n;
    int i;

    bool premier;


    printf("Donner un nombre :\n");
    scanf("%llu",&n);
    premier=testPremA1(n);
    premier=testPremA2(n);
    premier=testPremA3(n);
    premier=testPremA4(n);
    premier=testPremA5(n);
    premier=testPremA6(n);


    if(premier)

   {
      printf("\n%llu est un nombre premier \n",n);
   }
   else
   {
      printf("\n%llu n'est pas un nombre premier \n",n);
   }

    return 0;
}
