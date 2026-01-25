#include <stdio.h>
#include <stdlib.h>
#include "permutation.h"

void FonctionPermut(int dimension,int tour,int permut, int T[],int t[])
{
	int i,n,p;
	int Compt = 0;
	i = n = dimension - 1;
      //printf("\n\nPERMUTATION:\n");

     if(tour > permut)
	 {
	 	printf("\n tour est strictement superieur a permut\n");
	 	printf("\n permut = %d", permut);
	 	printf("\ndimension = %d", dimension);
	 	printf("\nTour = %d", tour);
	 	exit(0);
	 }
	 else if(tour > dimension)
	 {
	 	printf("\n tour est strictement sup�rieur a dimension\n");
	 	printf("\n permut = %d", permut);
	 	printf("\ndimension = %d", dimension);
	 	printf("\nTour = %d", tour);
	 	exit(0);
	 }
	 else if(permut > dimension)
	 {
	 	printf("\npermut > dimension");
	 	printf("\n permut = %d", permut);
	 	printf("\ndimension = %d", dimension);
	 	printf("\nTour = %d", tour);
	 	exit(0);
	 }
	 else
	 {
	 	//printf("\npermut <= dimension");
	 	//printf("\n permut = %d", permut);
	 	//printf("\nTour = %d", tour);
	 	//printf("\ndimension = %d", dimension);
    do
	{
		//printf("\ni = %d",i);
		p = i + tour;
		                    if(p<dimension)
							 {
							 	T[i] = t[(i + tour)];
							 	//printf("\nT[%d] = t[%d] = %d",i,(i + tour),T[i]);
							 }
		                    else if(p>= dimension)
			                 {
							   T[i] = t[((i+tour)- permut)];
							 //printf("\n ((%d+%d) moins %d)= %d\n", i,tour,permut,((i+tour)- permut));
							 //printf("\nT[%d] = t[%d] = %d",i,((i + tour)- permut),T[i]);
		                     }
							 else if(p==0)
		                     {
			                   T[i]=t[permut];
			                   //printf("\nT[%d] = t[%d] = %d",i,permut,T[i]);
		                     }
		i--;
		Compt++;
	}while(Compt != permut);
	 printf("\n");


	 if(i<0)
	 {
	 	printf("\t");
	 	//printf("i = %d\n", i);
		//printf("Compt = %d", Compt);
	 	//printf("\n\nTableau permutee:\n");
        //for(j = 0; j<dimension ; j++)
	    //{
		//printf("T[%d] = %d\n",j,T[j]);
	    //}
	 }
	 else if(i>=0)
	 {
	 	  //printf("i = %d\n", i);
		  //printf("Compt = %d", Compt);
	     do
	     {
		    T[i] = t[i];
		    //printf("\nT[%d] = %d",i,T[i]);
		    i--;
		    Compt++;
		 }while(Compt != dimension);

	        //printf("\n\nTableau permutee:\n");
            //for(j = 0; j<dimension ; j++)
	        //{
		      // printf("T[%d] = %d\n",j,T[j]);
	        //}
	}
	else
	{
		printf("\nc'est un tout autre probleme\n");
		printf("i = %d\n", i);
		printf("Compt = %d", Compt);

		exit(0);
	}
	}

}

void DefinirTableaut(int t[],int TailleTableau)
{
	int d;
	int i = 0;
	d = TailleTableau;
	for(i=0;i<d;i++)
	{
		t[i] = ((i+d)%d)+1;
	}
}