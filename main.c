#include <stdio.h>
#include <stdlib.h>
void FonctionPermut(int dimension,int tour,int permut, int T[],int t[]);///PROTOTYPE DE LA FONCTIONPERMUT

void DefinirTableaut(int t[],int TailleTableau);
void afficheTableau(int Tableau[],int TailleTableau);///LES PROTOTYPES DU CODE BOUCLE
void afficheTableauPermutee(int Tableau[], int TailleTableau);
void BouclePermut(int Tour[],int Permut[],int T[],int t[],int TailleTableau,int compteur);
void BouclePermutCarre(int matrice[10][10],int echange[10][10],int TailleCarre,int Tour[],int Permut[],int T[],int t[],int TailleTableau,int compteur);
int FactorielSur2(int a);/// Dans CODEBOUCLEPERMUT
int Factoriel(int a);
void Echange(int matrice[10][10],int echange[10][10],int TailleCarre);


int main()
{
	///VARIABLE FONCTIONPERMUT
    int *T = NULL;
    int *t = NULL;
    int dimension = 0;
    ///

    int *Tour = NULL;///VARIABLE BOUCLEPERMUT
	int l,n,m,k;
	int compteur = 0;///
	int *Permut = NULL;

    printf("\nEntrer la dimension :)(::");///CREEE LE FONCTION A PERMUTE ET LA FONCTION PERMUTEE
    scanf("%d", &dimension);
    T = malloc((dimension)*sizeof(int));
    t = malloc((dimension)*sizeof(int));

    //d = dimension;
    //for(i=0;i<d;i++)
	//{
		//t[i] = ((i+d)%d)+1;
	//}                          ///
	DefinirTableaut(t,dimension);
    afficheTableauPermutee(t,dimension);

	Tour = malloc((dimension)*sizeof(int));///CREATION FONCTION TOUR

	n = dimension;
	Tour[0] = n;
	for(l=1;l<(dimension-1);l++)
	{
		Tour[l] = n;
		n--;
	}
	Tour[dimension-1] = 1;///

	Permut = malloc((dimension)*sizeof(int));///CREATION TABLEAU PERMUT

	m = dimension;
	Permut[0] = m;
    for(k=1;k<=(dimension-1);k++)
	{
		Permut[k] = m;
		m--;
	}                  ///
     //printf("\nTableau permut\n");
     //afficheTableau(Permut,dimension);

	printf("\nOn doit obtenir %d permutaions possibles", Factoriel(dimension));
     printf("\n");

     BouclePermut(Tour,Permut,T,t,dimension,compteur);

     free(Tour);
     free(T);
    free(t);
    free(Permut);
    return 0;
}



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
	 	printf("\n tour est strictement supérieur a dimension\n");
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
void afficheTableau(int Tableau[],int TailleTableau)///FONCTION AFFICHAGE
{
    int i;
    for(i=0;i<TailleTableau;i++)
	{
		printf("Tour[%d] = %d\n", i,Tableau[i]);
	}
}
void afficheTableauPermutee(int Tableau[], int TailleTableau)
{
	int i;
	printf("\n");
	for(i=0;i<TailleTableau;i++)
	{
		printf("%d\t",Tableau[i]);
	}                                      ///
}


void BouclePermut(int Tour[],int Permut[],int T[],int t[],int TailleTableau,int compteur)
{
	int np = 0;
	int NombredePermutations = 0;
	int a = 0;
	int i,p,j,k,l,q;
	int cpt = 0;
	int fois = 0;

	///VARIABLE FONCTIONPERMUTCARRE
    int *TCP = NULL;
    int *tcp = NULL;
    ///

    int *TourC = NULL;///VARIABLE BOUCLEPERMUTCARRE
	int w,x,y,z;///
	int *PermutC = NULL;

	int Carre[10][10];
	int echange[10][10];
	 int Ligne,Colonne,s,L,C;
	p = TailleTableau;

	TCP = malloc((TailleTableau-1)*sizeof(int));
    tcp = malloc((TailleTableau-1)*sizeof(int));
    DefinirTableaut(tcp,TailleTableau-1);

    TourC = malloc((TailleTableau-1)*sizeof(int));///CREATION FONCTION TOUR

	x = TailleTableau-1;
	TourC[0] = x;
	for(w=1;w<(TailleTableau-2);w++)
	{
		TourC[w] = x;
		x--;
	}
	TourC[TailleTableau-2] = 1;///

	PermutC = malloc((TailleTableau-1)*sizeof(int));///CREATION TABLEAU PERMUT

	y = TailleTableau-1;
	PermutC[0] = y;
    for(z=1;z<=(TailleTableau-2);z++)
	{
		PermutC[z] = y;
		y--;
	}


	do{
            DefinirTableaut(t,TailleTableau);
            for(i=(p-2);i>=1;i--)
			{
               if(compteur == 0)
			   {
			   	 Tour[i] = Tour[i];
			   }
			   else
				{
				   if((compteur % FactorielSur2(p-i))==0)
				   {
				   	  Tour[i] = Tour[i]-1;
				   	  if(Tour[i]==0)
					  {
					  	Tour[i] = Tour[i] + ((p-i)+1);
					  }
				   }
				   else
					{Tour[i] = Tour[i];
					}
			    }
			 }
			          for(k=0;k<TailleTableau;k++)
					  {
                       FonctionPermut(TailleTableau,Tour[k],Permut[k],T,t);//A PARTIR DE CETTE LIGNE A INSERER DANS BOUCLEPERMUT
                       if(Permut[k]>3)
					   {
					   	 a = FactorielSur2(Permut[k]-1);
					   }
                       fois++;
                        for(l=0;l<p;l++)
						{
							if(T[l]==t[l])
							{
								cpt++;
							}
							else
							{
								cpt = cpt;
							}
						}
						if(cpt==TailleTableau && fois != 1)
						{
                             for(j=0;j<p;j++)
	                         {
		                       t[j] = T[j];
							 }
	                    }
	                    else if(Permut[k] > 3 && (compteur % a)!= 0)
						{
							for(j=0;j<p;j++)
	                         {
		                       t[j] = T[j];
							 }
						}
	                    else
							{
								for(q=0;q<p;q++)
	                            {
		                          t[q] = T[q];
							    }
	                            //printf("\n\nVoici le nouveau tableau t\n");///AFFICHAGE
                                  afficheTableauPermutee(t,TailleTableau);
                                 for(Ligne = 0;Ligne<TailleTableau;Ligne++)///CARRRE LATIN
								 {
								 	for(Colonne = 0;Colonne<TailleTableau;Colonne++)
									{
                                        s = Ligne + Colonne;
                                        Carre[Ligne][Colonne] = t[s%TailleTableau];
									}
								 }
								  printf("\nVoici le carre latin et ses permutations:\n");
								 for(L = 0;L<TailleTableau;L++)
								 {
								 	for(C = 0;C<TailleTableau;C++)
									{
										printf("%2d",Carre[L][C]);
									}
									printf("\n");
								 }
								 //printf("\nEchange\n");
								 Echange(Carre,echange,TailleTableau);///AFFICHAGE CARRE LATIN
                                 BouclePermutCarre(Carre,echange,TailleTableau,TourC,PermutC,TCP,tcp,TailleTableau-1,compteur);
	                            NombredePermutations++;
	                        }
	                        cpt = 0;
					  }
							   //JUSQU'ICI
			compteur++;
			np++;
			//printf("\nchemin numero %d\n", np);
         }while(np != FactorielSur2(p));
         printf("\nLe nombre de permutations de %d est %d\n.", TailleTableau,NombredePermutations);

         free(TourC);
     free(TCP);
    free(tcp);
    free(PermutC);
}

int FactorielSur2(int a)
{
  int F = 1;
  do{
	 F = F * a;
     a--;
    }while(a != 1);
    F = F/2;
  return F;
}
int Factoriel(int a)
{
  int F = 1;
  do{
	 F = F * a;
     a--;
    }while(a != 1);
  return F;
}

void BouclePermutCarre(int matrice[10][10],int echange[10][10],int TailleCarre,int Tour[],int Permut[],int T[],int t[],int TailleTableau,int compteur)
{
	int np = 0;
	int NombredePermutations = 0;
	int a = 0;
	int i,p,j,k,l,q;
	int cpt = 0;
	int fois = 0;
	p = TailleTableau;
    int ligne,colonne,L,C,Ligne,Colonne;

	do{
            DefinirTableaut(t,TailleTableau);
            for(i=(p-2);i>=1;i--)
			{
               if(compteur == 0)
			   {
			   	 Tour[i] = Tour[i];
			   }
			   else
				{
				   if((compteur % FactorielSur2(p-i))==0)
				   {
				   	  Tour[i] = Tour[i]-1;
				   	  if(Tour[i]==0)
					  {
					  	Tour[i] = Tour[i] + ((p-i)+1);
					  }
				   }
				   else
					{Tour[i] = Tour[i];
					}
			    }
			 }
			          for(k=0;k<TailleTableau;k++)
					  {
                       FonctionPermut(TailleTableau,Tour[k],Permut[k],T,t);//A PARTIR DE CETTE LIGNE A INSERER DANS BOUCLEPERMUT
                       if(Permut[k]>3)
					   {
					   	 a = FactorielSur2(Permut[k]-1);
					   }
                       fois++;
                        for(l=0;l<p;l++)
						{
							if(T[l]==t[l])
							{
								cpt++;
							}
							else
							{
								cpt = cpt;
							}
						}
						if(cpt==TailleTableau && fois != 1)
						{
                             for(j=0;j<p;j++)
	                         {
		                       t[j] = T[j];
							 }
	                    }
	                    else if(Permut[k] > 3 && (compteur % a)!= 0)
						{
							for(j=0;j<p;j++)
	                         {
		                       t[j] = T[j];
							 }
						}
	                    else
							{
								for(q=0;q<p;q++)
	                            {
		                          t[q] = T[q];
							    }
	                            //printf("\n\nVoici le nouveau tableau t\n");///AFFICHAGE

	                            //afficheTableauPermutee(t,TailleTableau);
							    for(ligne=1;ligne<TailleCarre;ligne++)
								{
									for(colonne=0;colonne<TailleCarre;colonne++)
									{
                                       matrice[ligne][colonne] = echange[t[ligne-1]][colonne];
									}
								}
								printf("\n");               ///AFFICHAGE
								for(L=0;L<TailleCarre;L++)
								{
									for(C=0;C<TailleCarre;C++)
									{
										printf("%2d", matrice[L][C]);
									}
									printf("\n");
								}                         ///AFFICHAGE
	                            NombredePermutations++;
	                        }
	                        cpt = 0;
	                        for(Ligne=0;Ligne<TailleCarre;Ligne++)
							{
								for(Colonne=0;Colonne<TailleCarre;Colonne++)
								{
									matrice[Ligne][Colonne] = echange[Ligne][Colonne];
								}
							}
							printf("\n%d\n", k);
					  }
							   //JUSQU'ICI
			compteur++;
			np++;
			//printf("\nchemin numero %d\n", np);
         }while(np != FactorielSur2(p));
         //printf("\nLe nombre de permutations de %d est %d\n.", TailleTableau,NombredePermutations);
}
void Echange(int matrice[10][10],int echange[10][10],int TailleCarre)
{
	int Ligne,Colonne;
    ///int L,C;

	for(Ligne=0;Ligne<TailleCarre;Ligne++)
	{
		for(Colonne=0;Colonne<TailleCarre;Colonne++)
		{
			echange[Ligne][Colonne] = matrice[Ligne][Colonne];
		}
	}
	//for(L=0;L<TailleCarre;L++)
	//{
		//for(C=0;C<TailleCarre;C++)
		//{
			//printf("%4d", echange[L][C]);
		//}
		//printf("\n");
	//}
}
