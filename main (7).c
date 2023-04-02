#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

int* creatTab(unsigned long long n){
    int i;

    int *t =(int *)malloc(n * sizeof(int));

    for(i=0; i<n; i++)
    {
        t[i]=rand();

    }
    return t;

}
//void fusion(int* t, unsigned long long n, unsigned long long d, unsigned long long f){
//  int r[f-d+1];
//  unsigned long long cmp=0;
//  int m=(d+f)/2;
//  int i1=d, i2=m+1, k=0;
//  while (i1<=m && i2 <=f){
//    cmp++;
//    if (t[i1] < t[i2]){
//        r[k] = t[i1];
//        i1++;}
//    else {
//
//       r[k] = t[i2];
//       i2++;
//      }
//     k++;
//    }
//   while (i1 <=m){
//       r[k] = t[i1];
//       i1++;
//         k++;
//  }
//   while (i2 <=f){
//      r[k] = t[i2];
//      i2++;
//      k++;
//    }
//    for(k=0; k<=f-d; k++)
//      t[d+k]=r[k];
//
// printf("compteur d fusion : %llu\n",cmp);
//}
//void triFusion (int *t,unsigned long long n, unsigned long long d,
//unsigned long long f){
//if (d<f){
//int m=(d+f)/2;
//triFusion(t,n,d,m);
//triFusion(t,n,m+1,f);
//fusion(t,n,d,f);
//
//} }
void triFusion(int i, int j, int tab[], int tmp[]) {
    if(j <= i){ return;}
   unsigned long long cmp=0;
    int m = (i + j) / 2;

    triFusion(i, m, tab, tmp);     //trier la moitié gauche récursivement
    triFusion(m + 1, j, tab, tmp); //trier la moitié droite récursivement
    int pg = i;     //pg pointe au début du sous-tableau de gauche
    int pd = m + 1; //pd pointe au début du sous-tableau de droite
    int c;          //compteur
// on boucle de i à j pour remplir chaque élément du tableau final fusionné
    for(c = i; c <= j; c++) {
            cmp++;
        if(pg == m + 1) { //le pointeur du sous-tableau de gauche a atteint la limite
            tmp[c] = tab[pd];
            pd++;
        }else {cmp++;  if (pd == j + 1) { //le pointeur du sous-tableau de droite a atteint la limite
            tmp[c] = tab[pg];
            pg++;
        }else{ cmp++; if (tab[pg] < tab[pd]) { //le pointeur du sous-tableau de gauche pointe vers un élément plus petit
            tmp[c] = tab[pg];
            pg++;
        }else {  //le pointeur du sous-tableau de droite pointe vers un élément plus petit
            tmp[c] = tab[pd];
            pd++;
        }}}
    }
    for(c = i; c <= j; c++) {  //copier les éléments de tmp[] à tab[]
        tab[c] = tmp[c];
    }
    printf("compteur d fusion : %llu\n",cmp);


}
int* tri_selec(int *t,unsigned long long n){
    int i,j,min,temp,cmpt=0 ;
   for(i=0;i<n;i++){
        min=i;
        for(j=i+1;j<=n-1;j++){
            cmpt++;
            if(t[j]<t[min]){
                min=j;
            }
        }
        temp=t[i];
        t[i]=t[min];
        t[min]=temp;

    }
    printf("compteur de tri_selec : %d\n",cmpt);

    return t;
}

int* triParInsertion(int tab[],unsigned long long n){
    int i,j,tmp;
    int cmpt=0;

    for (i=1 ; i <= n-1; i++) {
    j = i;
   cmpt=1;

    while (j > 0 && tab[j-1] > tab[j]) {
      tmp = tab[j];
      tab[j] = tab[j-1];
      tab[j-1] = tmp;
     cmpt++;
      j--;
    }
    cmpt++;
  }
 printf("compteur triParInsertion : %d\n",cmpt);
  return tab;
}
int* triABulle(int *tab,unsigned long long n){
    int i,j,tmp;
unsigned long long cmpt=0;

       for (i=0 ; i < n-1; i++)
  {
    for (j=0 ; j < n-i-1; j++)
    {
    cmpt++;
      if (tab[j] > tab[j+1])
      {
        tmp = tab[j];
        tab[j] = tab[j+1];
        tab[j+1] = tmp;

      }
    }
  }
 printf("compteur triABulle : %llu\n",cmpt);

      return tab;
}
/* fonction de tri RECURSIF
 */
int  permuter(int *a, int *b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
//void triRapid(int* tab, int first, int last) {
//    int pivot, i, j;
//
//    if(first < last) {
//        pivot = first;
//        i = first;
//        j = last;
//        while (i < j) {
//            while(tab[i] <= tab[pivot] && i < last)
//                i++;
//            while(tab[j] > tab[pivot])
//                j--;
//            if(i < j) {
//                permuter(&tab[i], &tab[j]);
//            }
//        }
//        permuter(&tab[pivot], &tab[j]);
//        triRapid(tab, first, j - 1);
//        triRapid(tab, j + 1, last);
//    }
//}
//void triRapid (int* tab, unsigned long long first , unsigned long long last )
//{
//    int temp;
//int i = first -1;
//int j = last +1;
//const int pivot = tab [ first ];
//if( first >= last )
//return ;
//while (1)
//{
//do j --; while ( tab [ j ] > pivot );
//do i ++; while ( tab [ i ] < pivot );
//if( i < j ){
//temp = tab [i];
//tab [i] = tab [j];
//tab [j] = temp ;}
//else break ;
//}
//triRapid ( tab , first , j );
//triRapid ( tab , j +1, last);
//}



void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int Partition(int* data, int left, int right)
{

   int cmpt=0,j;
   //-----------TROIS METHODES DE PIVOTS---------------
   //int x = data[right];              //PIVOT FIN
   //int x = data[left + 1000 ];   //pivot aleaoitoire
	int x = data[right];
	int i = (left - 1);

	for ( j = left; j <= right - 1; ++j)
	{    cmpt++;
		if (data[j] <= x)
		{
			++i;
			permuter(&data[i], &data[j]);

		}
	}

	permuter(&data[i + 1], &data[right]);


	return (i + 1);
}

void QuickSortIterative(int* data, int count) {
	int startIndex = 0;
	int endIndex = count - 1;
	int top = -1;
	int* stack = (int*)malloc(sizeof(int) * count);
int cmpt=0;
	stack[++top] = startIndex;
	stack[++top] = endIndex;

	while (top >= 0)
	{
		endIndex = stack[top--];
		startIndex = stack[top--];

		int p = Partition(data, startIndex, endIndex);
cmpt++;
		if (p - 1 > startIndex)
		{
			stack[++top] = startIndex;
			stack[++top] = p - 1;
		}
cmpt++;
		if (p + 1 < endIndex)
		{
			stack[++top] = p + 1;
			stack[++top] = endIndex;
		}
	}

printf("compteur de trirapide : %d\n",cmpt);
	free(stack);
}

void heapify(int* arr, unsigned long long N, int i)
{
    // Find largest among root, left child and right child

    // Initialize largest as root
    int largest = i;

    // left = 2*i + 1
    int left = 2 * i + 1;

    // right = 2*i + 2
    int right = 2 * i + 2;


    // If left child is larger than root
    if (left < N && arr[left] > arr[largest])

        largest = left;

    // If right child is larger than largest
    // so far


    if (right < N && arr[right] > arr[largest])

        largest = right;

    // Swap and continue heapifying if root is not largest
    // If largest is not root
    if (largest != i) {

        permuter(&arr[i], &arr[largest]);
        // Recursively heapify the affected
        // sub-tree
        heapify(arr, N, largest,cmp);
    }


}

// Main function to do heap sort
void heapSort(int* arr, unsigned long long N)
{int i;

    // Build max heap

    for ( i = N / 2 - 1; i >= 0; i--)

        heapify(arr, N, i);

    // Heap sort
    for (i = N - 1; i >= 0; i--) {

        permuter(&arr[0], &arr[i]);

        // Heapify root element to get highest element at
        // root again
        heapify(arr, i, 0);
    }



}
int* ordre_inv(int *t,unsigned long long n){
     int i, temp;
       for(i = 0; i<n/2; i++){
        temp = t[i];
        t[i] = t[n-i-1];
        t[n-i-1] = temp;
    }
       return t;
}



int main()
{
    unsigned long long n;
    int i, rnum,*t,*tmp,*v,cmp=0;
	clock_t t1,t2;
    double delta;




     n=10000;
     tmp =(int *)malloc(n * sizeof(int));
       t=creatTab(n);
  heapSort(t, n,&cmp);
//     n=5*10000;
//       t=creatTab(n);
// triFusion(t,n,0,n-1);
//     n=100000;
//       t=creatTab(n);
//   triFusion(t,n,0,n-1);
//     n=5*100000;
//       t=creatTab(n);
//    triFusion(t,n,0,n-1);
//     n=1000000;
//       t=creatTab(n);
//  triFusion(t,n,0,n-1);
//     n=5*100000;
//       t=creatTab(n);
//  triFusion(t,n,0,n-1);
//     n=10000000;
//       t=creatTab(n);
//   triFusion(t,n,0,n-1);
//    n=5*10000000;
//      t=creatTab(n);
//  triFusion(t,n,0,n-1);
//    n=10000000;
//      t=creatTab(n);
//    triFusion(t,n,0,n-1);
//    for(i=0;i<n;i++)
// {
// printf("%d ",t[i]);
// }
 putchar('\n'); //aleatoire

//    t=tri_selec(t,n);
//heapSort(t, n);


//    heapSort(t, n);

//    triFusion(0, n-1, t, tmp);
//    t=triParInsertion(t,n);
//    t=triABulle(t,n);



//*******************************TRI RAPIDE**************************************//
//    t1 = clock();
//   tri_selec(t,n);
//  	t2 = clock();
//    for(i=0;i<n;i++)
// {
// printf("%d ",t[i]);
// }
// putchar('\n');
//	delta = (double) (t2-t1)/CLOCKS_PER_SEC ;
//    printf("Le temps d'execution  alea est (trirapideALEA) : %lf\n",delta);
//	t1 = clock();
//   tri_selec(t,n); //tri�
//	t2 = clock();


//    for(i=0;i<n;i++)
// {
// printf("%d ",t[i]);
// }
// putchar('\n');

//	delta = (double) (t2-t1)/CLOCKS_PER_SEC ;
//    printf("Le temps d'execution  trie est (trirapideORDONNEE) : %lf\n",delta);
//    t=ordre_inv(t,n); //inverse
//	t1 = clock();
//   tri_selec(t,n); //tri�
//	t2 = clock();
//	delta = (double) (t2-t1)/CLOCKS_PER_SEC ;
//    printf("Le temps d'execution  inv est (trirapideINVERSE) : %lf\n",delta);

//**************************************TRI PAR TAS******************************************
//t1 = clock();
//   heapSort(t, n);
//  	t2 = clock();
//	delta = (double) (t2-t1)/CLOCKS_PER_SEC ;
//    printf("Le temps d'execution  alea est (triParTasALEA) : %lf\n",delta);
//	t1 = clock();
//  heapSort(t, n); //tri�
//	t2 = clock();
//	delta = (double) (t2-t1)/CLOCKS_PER_SEC ;
//    printf("Le temps d'execution  trie est (triParTasORDONNEE) : %lf\n",delta);
//    t=ordre_inv(t,n); //inverse
//	t1 = clock();
//    heapSort(t, n); //tri�
//	t2 = clock();
//	delta = (double) (t2-t1)/CLOCKS_PER_SEC ;
//    printf("Le temps d'execution  inv est (triParTasINVERSE) : %lf\n",delta);









    return 0;

}

