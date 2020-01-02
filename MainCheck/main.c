#include <stdio.h>
#include <stdlib.h>


typedef struct artikal
{
    char naziv[24];
    double cijena;
    char id[8];

}ARTIKAL;

void ispisiArtikle(char *nazivDatoteke)
{
    FILE *fp;
    if((fp = fopen(nazivDatoteke,"r")) != NULL)
        {
            ARTIKAL tmp1;
            int errorCheck;
            while((errorCheck = fscanf(fp,"%s\n%s\n%lf\n\n",tmp1.id,tmp1.naziv,&tmp1.cijena)) != EOF)
            {
                printf("%-8s\n%-24s\n%.2lf\n\n",tmp1.id,tmp1.naziv,tmp1.cijena);
            }
            fclose(fp);

        }
        else
            printf("Greska prilikom otvaranja '%s' !",nazivDatoteke);
}

int brojArtikala(char *nazivDatoteke)
{
    FILE *fp;
    if((fp = fopen(nazivDatoteke,"r")) != NULL)
    {
        ARTIKAL tmp1;
        int brArt = 0, errorCheck;
        while((errorCheck = fscanf(fp,"%s\n%s\n%lf\n\n",tmp1.id,tmp1.naziv,&tmp1.cijena)) != EOF)
            brArt++;
        return brArt;
        fclose(fp);
    }
    else
    {
         printf("Greska prilikom otvaranja '%s' !",nazivDatoteke);
         return 0;
    }

}



void ispisiArtikleBrisanje(char *nazivDatoteke)
{
    FILE *fp;
    if((fp = fopen(nazivDatoteke,"r")) != NULL)
        {
            ARTIKAL tmp1;
            int errorCheck, brojac = 1;
            while((errorCheck = fscanf(fp,"%s\n%s\n%lf\n\n",tmp1.id,tmp1.naziv,&tmp1.cijena)) != EOF)
            {
                printf("%d:\n", brojac);
                printf("%-8s\n%-24s\n%.2lf\n\n",tmp1.id,tmp1.naziv,tmp1.cijena);
                brojac++;
            }
            fclose(fp);
        }
        else
            printf("Greska prilikom otvaranja '%s' !",nazivDatoteke);
}

void upisiArtikal(char *nazivDatoteke, ARTIKAL tmp2)
{
    FILE *fp;
    if((fp = fopen(nazivDatoteke,"a")) != NULL)
        {
            if((fp = fopen("Artikli.txt","a")) != NULL)
            {
                fprintf(fp,"%-8s\n%-24s\n%.2lf\n\n",tmp2.id,tmp2.naziv,tmp2.cijena);
                fclose(fp);
            }
        }
        else
            printf("Greska prilikom otvaranja '%s' !",nazivDatoteke);
}

void brisiArtikal(int brArt, int rb, char* nazivDatoteke)
{
    if(rb > 0 && rb < brArt + 1)
    {
        FILE *fp;
        ARTIKAL nizArt[brArt - 1];
        if((fp = fopen(nazivDatoteke,"r")) != NULL)
        {
            ARTIKAL tmp1;
            int indeks = 0;
            int errorCheck;
            while((errorCheck = fscanf(fp,"%s\n%s\n%lf\n\n",tmp1.id,tmp1.naziv,&tmp1.cijena)) != EOF)
            {
                if(indeks + 1 != rb)
                    nizArt[indeks++] = tmp1;
            }
            fclose(fp);
        }
        else
            printf("Greska prilikom otvaranja '%s' !",nazivDatoteke);

        if((fp = fopen(nazivDatoteke,"w")) != NULL)
            fclose(fp);
            for(int index = 0; index < brArt - 1; index++)
                upisiArtikal(nazivDatoteke, nizArt[index]);
            printf("\nArtikal je uspjesno obrisan ! \n");


//        else
//            printf("Greska prilikom pokusavanja brisanja '%s' datoteke", nazivDatoteke);
    }

}


ARTIKAL ucitajArtikal()
{
    ARTIKAL tmp2;
    printf("Naziv:  ");scanf("%s",tmp2.naziv);
    printf("ID:     ");scanf("%s",tmp2.id);
    printf("Cijena: ");scanf("%lf",&tmp2.cijena);
    return tmp2;
}





//optimizacija enum za vrijednosti opcija
//optimizacija pomocu funkcije za provjeru opcije
//optimizacija za ID da se sam dodaje

int main()
{

    char opcija = 1;//setovano na 1 zbog petlje za opciju

    printf("===================\n");
    printf("|                 |\n");
    printf("|  DOBRODOSLI!    |\n");
    printf("|  VAS MERKATOR   |\n");
    printf("|                 |\n");
    printf("===================\n");

    printf("Izaberite jednu od opcija:\n");
    printf("1.ISPISI SVE ARTIKLE\n");
    printf("2.DODAJTE NOVI ARTIKAL\n");
    printf("3.OBRISITE POSTOJECI ARTIKAL\n");
    printf("4.IZMIJENITE POSTOJECI\n");
    do
    {
        if(opcija < 1 || opcija > 4)
            printf("Nije validna opcija!!!\n");
        printf("Vasa opcija[1,2,3,4]: ");
        scanf("%d",&opcija);
    }
    while(opcija < 1 || opcija > 4);


    if(opcija == 1)
    {
        ispisiArtikle("Artikli.txt");
    }
    else if(opcija == 2)
    {
        ARTIKAL temp2 = ucitajArtikal();
        upisiArtikal("Artikli.txt",temp2);
    }
    else if(opcija == 3)
    {
        int rb, potvrda = 1;
        int brArt = brojArtikala("Artikli.txt");
        if(brArt > 0)
        {
            ispisiArtikleBrisanje("Artikli.txt");
            printf("\nIzaberite redni broj artikla koji zelite obrisati: ");
            scanf("%d",&rb);
            do
            {
                if(potvrda < 1 || potvrda > 2)
                    printf("\n\nPOGRESNA OPCIJA!\n");
                printf("Da li ste sigurni da zelite obrisati?\n");
                printf("            1. DA -> (ukucaj 1)      \n");
                printf("            2. NE -> (ukucaj 2)      \n");
                printf("Vas odgovor: "); scanf("%d", &potvrda);
            }
            while(potvrda < 1 || potvrda > 2);
            if(potvrda == 1)
                brisiArtikal(brArt, rb, "Artikli.txt");
        }
        else
            printf("Nema artikala za obrisati!\n");
    }
    else if(opcija == 4)
    {

    }


}
