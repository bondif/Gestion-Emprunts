#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct
{
	char nom[60];
	char prenom[60];
}nomc;

typedef struct
{
	int jour;
	int mois;
	int annee;
}date;

typedef struct
{
	int no;
	nomc nom_complet;
	date datec;
	char titre[60];
}info_adherant;

info_adherant e;

void menu(void);
void creer(void);
int test(void);
void modif(void);
int rech(int);
void afficher(void);
void suppr(void);
void trier(void);
void quitter(void);

main ()
{
	int i=0,choix,noa;
	printf("Bonjour dans Gestion Emprunts\n\n\n");
	getch();
	for(;;)
	{	menu ();
		scanf("%d",&choix);
		if(choix==0){break;}
		switch(choix)
		{
			case 1:	creer();
					break;
			case 2:	modif();
			       	break;
			case 3:	printf("\nEntrer le No d'adherant a chercher : ");
					scanf("%d",&noa);
					rech(noa);
					break;
			case 4:	afficher();
			       	break;
			case 5:	suppr();
			       	break;
			case 6:	trier();
			       	break;
			default : printf("Erreur de choix !!!");
		}
	}
	printf("\n\n\nMerci d'avoir utiliser notre programme");
 	getch ();
}

void menu(void)
{
	printf("\n1. Ajouter un adherant");
	printf("\n2. Modifier les informations d'un adherant");
	printf("\n3. Rechercher un adherant");
	printf("\n4. Afficher tous les adherants");
	printf("\n5. Supprimer un adherant");
	printf("\n6. Trier les adherants");
	printf("\n0. Quitter !!");
	printf("\nVotre choix : ");
}

void creer(void)
{
	int n,i,tempno,trouve=0;
	FILE *f;
	if(f==NULL) f=fopen("liste.txt","w");
	else f=fopen("liste.txt","a");
	printf("\nEntrer le nombre d'adherant a ajouter : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{	
		printf("Entrer le numero : ");
		scanf("%d",&e.no);
		printf("Entrer le nom : ");
		fflush(stdin);
		gets(e.nom_complet.nom);
		printf("Entrer le prenom : ");
		fflush(stdin);
		gets(e.nom_complet.prenom);
		printf("Entrer le titre du livre : ");
		fflush(stdin);
		gets(e.titre);
		printf("Entrer la date (jj/mm/aaaa): ");
		scanf("%d/%d/%d",&e.datec.jour,&e.datec.mois,&e.datec.annee);
		fprintf(f,"%d\t%s\t\t%s\t\t%s\t\t%d/%d/%d\n",e.no,e.nom_complet.nom,e.nom_complet.prenom,e.titre,e.datec.jour,e.datec.mois,e.datec.annee);
	}
	fclose(f);
}

void modif(void)
{
	int i,no,n,temoin=0,choix;
	FILE *f,*g;
	f=fopen("liste.txt","r");
	g=fopen("temp.txt","w");
	printf("\nEntrer le no de l'adherant a modifier : ");
	scanf("%d",&no);
	if(rech(no)==1)
	{
		printf("Entrer numero de l'adherant a modifier : ");
		scanf("%d",&n);
		if(rech(n)==1)
		{
			printf("Voulez vous modifier :\n1. Le numero\n2. Le nom\n3. Le prenom\n4. Le livre\n5. La date\n");
			printf("Votre choix : ");
			scanf("%d",&choix);
			switch(choix) {
				case 1 :while(feof(f)==0)
						{
							fscanf(f,"%d\t%s\t\t%s\t\t%s\t\t%d/%d/%d\n",&e.no,e.nom_complet.nom,e.nom_complet.prenom,e.titre,&e.datec.jour,&e.datec.mois,&e.datec.annee);
							if(e.no==no)
							{
								printf("Entrer le nouveau numero : ");
								scanf("%d",e.no);
							}
							fprintf(g,"%d\t%s\t\t%s\t\t%s\t\t%d/%d/%d\n",e.no,e.nom_complet.nom,e.nom_complet.prenom,e.titre,e.datec.jour,e.datec.mois,e.datec.annee);
						}
						break;
				case 2 :while(feof(f)==0)
						{
							fscanf(f,"%d\t%s\t\t%s\t\t%s\t\t%d/%d/%d\n",&e.no,e.nom_complet.nom,e.nom_complet.prenom,e.titre,&e.datec.jour,&e.datec.mois,&e.datec.annee);
							if(e.no==no)
							{
								printf("Entrer le nouveau nom : ");
								fflush(stdin);
								gets(e.nom_complet.nom);
							}
							fprintf(g,"%d\t%s\t\t%s\t\t%s\t\t%d/%d/%d\n",e.no,e.nom_complet.nom,e.nom_complet.prenom,e.titre,e.datec.jour,e.datec.mois,e.datec.annee);
						}
						break;
				case 3 :while(feof(f)==0)
						{
							fscanf(f,"%d\t%s\t\t%s\t\t%s\t\t%d/%d/%d\n",&e.no,e.nom_complet.nom,e.nom_complet.prenom,e.titre,&e.datec.jour,&e.datec.mois,&e.datec.annee);
							if(e.no==no)
							{
								printf("Entrer le nouveau prenom : ");
								fflush(stdin);
								gets(e.nom_complet.prenom);
							}
							fprintf(g,"%d\t%s\t\t%s\t\t%s\t\t%d/%d/%d\n",e.no,e.nom_complet.nom,e.nom_complet.prenom,e.titre,e.datec.jour,e.datec.mois,e.datec.annee);
						}
						break;
				case 4 :while(feof(f)==0)
						{
							fscanf(f,"%d\t%s\t\t%s\t\t%s\t\t%d/%d/%d\n",&e.no,e.nom_complet.nom,e.nom_complet.prenom,e.titre,&e.datec.jour,&e.datec.mois,&e.datec.annee);
							if(e.no==no)
							{
								printf("Entrer le nouveau titre du livre : ");
								fflush(stdin);
								gets(e.titre);
							}
							fprintf(g,"%d\t%s\t\t%s\t\t%s\t\t%d/%d/%d\n",e.no,e.nom_complet.nom,e.nom_complet.prenom,e.titre,e.datec.jour,e.datec.mois,e.datec.annee);
						}
						break;
				case 5 :while(feof(f)==0)
						{
							fscanf(f,"%d\t%s\t\t%s\t\t%s\t\t%d/%d/%d\n",&e.no,e.nom_complet.nom,e.nom_complet.prenom,e.titre,&e.datec.jour,&e.datec.mois,&e.datec.annee);
							if(e.no==no)
							{
								printf("Entrer une nouvelle date : ");
								scanf("%d/%d/%d",&e.datec.jour,&e.datec.mois,&e.datec.annee);
							}
							fprintf(g,"%d\t%s\t\t%s\t\t%s\t\t%d/%d/%d\n",e.no,e.nom_complet.nom,e.nom_complet.prenom,e.titre,e.datec.jour,e.datec.mois,e.datec.annee);
						}
						break;
				default :printf("Erreur de choix !!");
			}
		}
		fclose(f);
		fclose(g);
		remove("liste.txt");
		rename("temp.txt","liste.txt");
	}
	else printf("L'adherant inexistant !!");
}

int rech(int noa)
{
	int trouve=0;
	FILE *f;
	f=fopen("liste.txt","r");
	while(feof(f)==0)
	{
		fscanf(f,"%d\t%s\t\t%s\t\t%s\t\t%d/%d/%d\n",&e.no,e.nom_complet.nom,e.nom_complet.prenom,e.titre,&e.datec.jour,&e.datec.mois,&e.datec.annee);
		if(e.no==noa)
		{
			trouve=1;
			printf("\nSes Informations :\nNo\tNom\t\tPrenom\t\tTitre du livre\t\tDate\n");
			fscanf(f,"%d\t%s\t\t%s\t\t%s\t\t%d/%d/%d\n",&e.no,e.nom_complet.nom,e.nom_complet.prenom,e.titre,&e.datec.jour,&e.datec.mois,&e.datec.annee);
			printf("%d\t%s\t\t%s\t\t%s\t\t%d/%d/%d\n",e.no,e.nom_complet.nom,e.nom_complet.prenom,e.titre,e.datec.jour,e.datec.mois,e.datec.annee);
			return 1;
		}
	}
	if(trouve==0)
	{
		printf("L'adherant Inexistant");
		return 0;
	}
	fclose(f);
}

void afficher(void)
{
	FILE *f;
	f=fopen("liste.txt","r");
	printf("\nNo\tNom\t\tPrenom\t\tTitre du livre\t\tDate\n");
	while(feof(f)==0)
	{
		fscanf(f,"%d\t%s\t\t%s\t\t%s\t\t%d/%d/%d\n",&e.no,e.nom_complet.nom,e.nom_complet.prenom,e.titre,&e.datec.jour,&e.datec.mois,&e.datec.annee);
		printf("%d\t%s\t\t%s\t\t%s\t\t%d/%d/%d\n",e.no,e.nom_complet.nom,e.nom_complet.prenom,e.titre,e.datec.jour,e.datec.mois,e.datec.annee);
	}
	fclose(f);
}
void suppr(void)
{
	int i,no,trouve=0;
	FILE *f,*g;
	f=fopen("liste.txt","r");
	g=fopen("temp.txt","w");
	printf("Entrer le no d'adherant a supprimer : ");
	scanf("%d",&no);
	while(feof(f)==0)
	{
		fscanf(f,"%d\t%s\t\t%s\t\t%s\t\t%d/%d/%d\n",&e.no,e.nom_complet.nom,e.nom_complet.prenom,e.titre,&e.datec.jour,&e.datec.mois,&e.datec.annee);
		if(e.no!=no)
		{
			fprintf(g,"%d\t%s\t\t%s\t\t%s\t\t%d/%d/%d\n",e.no,e.nom_complet.nom,e.nom_complet.prenom,e.titre,e.datec.jour,e.datec.mois,e.datec.annee);
		}
		else {trouve=0;}
	}
	if(trouve==0) printf("La suppression est effectuee avec succes !!");
	if(trouve==1) printf("L'adherant a supprimer est introuvable !!");
	fclose(f);
	fclose(g);
	remove("liste.txt");
	rename("temp.txt","liste.txt");
}

void trier(void)
{
	info_adherant p,h[200];
	int k=0,i=0,ordre=0,choix;
	FILE *f,*g;
	f=fopen("liste.txt","r");
	g=fopen("temp.txt","w");
	printf("Voulez vous trier par :\n1.\tNom\n2.\tNumero\nVotre Choix : ");
	scanf("%d",&choix);
	switch(choix)
	{
		
		case 1: while(feof(f)==0)
				{
					fscanf(f,"%d\t%s\t\t%s\t\t%s\t\t%d/%d/%d\n",&h[i].no,h[i].nom_complet.nom,h[i].nom_complet.prenom,h[i].titre,&h[i].datec.jour,&h[i].datec.mois,&h[i].datec.annee);
					k++;
					i++;
				}
				do
				{
					ordre=1;
				    for(i=0;i<k-1;i++)
					{
						if(strcmp(h[i].nom_complet.nom,h[i+1].nom_complet.nom)>0)
						{
							ordre=0;
							p=h[i];
							h[i]=h[i+1];
							h[i+1]=p;
						}
			    	}
				}while(ordre==0);
				fclose(f);
				for(i=0;i<k;i++)
				{
					fprintf(g,"%d\t%s\t\t%s\t\t%s\t\t%d/%d/%d\n",h[i].no,h[i].nom_complet.nom,h[i].nom_complet.prenom,h[i].titre,h[i].datec.jour,h[i].datec.mois,h[i].datec.annee);
				}
				break;
		case 2: while(feof(f)==0)
				{
					fscanf(f,"%d\t%s\t\t%s\t\t%s\t\t%d/%d/%d\n",&h[i].no,h[i].nom_complet.nom,h[i].nom_complet.prenom,h[i].titre,&h[i].datec.jour,&h[i].datec.mois,&h[i].datec.annee);
					k++;
					i++;
				}
				do
				{
					ordre=1;
				    for(i=0;i<k-1;i++)
					{
						if(h[i].no>h[i+1].no)
						{
							ordre=0;
							p=h[i];
							h[i]=h[i+1];
							h[i+1]=p;
						}
			    	}
				}while(ordre==0);
				fclose(f);
				for(i=0;i<k;i++)
				{
					fprintf(g,"%d\t%s\t\t%s\t\t%s\t\t%d/%d/%d\n",h[i].no,h[i].nom_complet.nom,h[i].nom_complet.prenom,h[i].titre,h[i].datec.jour,h[i].datec.mois,h[i].datec.annee);
				}
				break;
		default : printf("Erreur de choix");
	}
	
	
	fclose(g);
	fclose(f);
	remove("liste.txt");
	rename("temp.txt","liste.txt");
	printf("Le trie est effectue avec succes !!");
}
