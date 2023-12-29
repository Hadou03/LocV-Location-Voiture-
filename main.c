#include <stdio.h>
#include <stdlib.h>
struct date{
           int jour;
           int mois;
           }date;
struct historique{
            int id_client;
            int NumCar;
            int periode;
            struct date dateb;
            struct date datef;
             }histo;
//histo

int Numc() {
    int num;
    printf("entrer le num de la voiture desiree \n");
    scanf("%d", &num);
    return num;
}
struct date Date(){
    struct date date;
    printf("entrer date jour/mois \n");
    scanf("%d/%d",&date.jour,&date.mois);
    return date;
      }

int rech3(int NumCar) {
    FILE *f;
    f = fopen("histo.txt", "r");
    if (f == NULL) {
        printf("Erreur lors de l'ouverture du fichier histo.txt.\n");
        return -1;
    }

    struct historique histo;
    while (fscanf(f, "%d,%d,%d,%d/%d,%d/%d\n", &histo.id_client, &histo.NumCar, &histo.periode,
                   &histo.dateb.jour, &histo.dateb.mois, &histo.datef.jour, &histo.datef.mois) == 7) {
        if (histo.NumCar == NumCar) {
            fclose(f);
            return 1;
        }
    }

    fclose(f);
    return -1;
}

void Ajouterhis() {
    struct historique histo;
    FILE *f = fopen("histo1.txt", "a");
    if (f == NULL) {
        printf("Erreur lors de l'ouverture du fichier histo.txt.\n");
        return;
    }

    printf("\n Entrer le numero du car:");
    scanf("%d", &histo.NumCar);

    printf("donner l'id du client:\n");
    scanf("%d", &histo.id_client);

    printf("donner la periode:\n");
    scanf("%d", &histo.periode);

    printf("donner la date deb jour");
    scanf("%d", &histo.dateb.jour);
    printf("donner la date deb mois");
    scanf("%d", &histo.dateb.mois);
    printf("donner la date fin jour");
    scanf("%d", &histo.datef.jour);
    printf("donner la date deb mois");
    scanf("%d", &histo.datef.mois);



    fprintf(f, "%d,%d,%d,%d/%d,%d/%d\n",
            histo.id_client, histo.NumCar, histo.periode,
            histo.dateb.jour, histo.dateb.mois,
            histo.datef.jour, histo.datef.mois);
        printf("enregistrement avec succes \n");
        fclose(f);
}

void affichhisto() {
    int NumR;
    printf("entrer le numero de voiture: ");
    scanf("%d", &NumR);

    FILE *f = fopen("histo1.txt", "r");
    if (f == NULL) {
        printf("Erreur lors de l'ouverture du fichier histo.txt.\n");
        return;
    }

    struct historique histo;
    int found = 0;
    while (fscanf(f, "%d,%d,%d,%d/%d,%d/%d\n", &histo.id_client, &histo.NumCar, &histo.periode,
                   &histo.dateb.jour, &histo.dateb.mois, &histo.datef.jour, &histo.datef.mois) == 7) {
        if (NumR == histo.NumCar) {
            found = 1;
            printf("---AFFICHAGE De historique---\n");
            printf("id:\t%d\n", histo.id_client);
            printf("numcar:\t%d\n", histo.NumCar);
            printf("periode:\t%d\n", histo.periode);
            printf("date debut:\t%d/%d\n", histo.dateb.jour, histo.dateb.mois);
            printf("date fin:\t%d/%d\n", histo.datef.jour, histo.datef.mois);
        }
    }

    if (!found) {
        printf("Il n'existe pas d'historique pour ce numero de voiture.\n");
    }

    fclose(f);
}

void affichhistT() {
    FILE *f = fopen("histo1.txt", "r");
    if (f == NULL) {
        printf("Erreur lors de l'ouverture du fichier histo.txt.\n");
        return;
    }

    struct historique histo;
    while (fscanf(f, "%d,%d,%d,%d/%d,%d/%d\n", &histo.id_client, &histo.NumCar, &histo.periode,
                   &histo.dateb.jour, &histo.dateb.mois, &histo.datef.jour, &histo.datef.mois) == 7) {
        printf("---AFFICHAGE De historique---\n");
        printf("id:\t%d\n", histo.id_client);
        printf("numcar:\t%d\n", histo.NumCar);
        printf("periode:\t%d\n", histo.periode);
        printf("date debut:\t%d/%d\n", histo.dateb.jour, histo.dateb.mois);
        printf("date fin:\t%d/%d\n", histo.datef.jour, histo.datef.mois);
    }

    fclose(f);
}


//cars
struct car{
            char Nom[20],Matricule[20];

            int Num,tarif;
            struct car *Next;
          }car;
struct description{
            char Marque[20],energie[20],couleur[20],etat[20],classe[20];
            float compteur;
            int Num,puissance;
            struct car *Next;
          }des;





int rech(int NumCar) {
    FILE *f = fopen("cars1.txt", "r");
    if (f == NULL) {
        printf("Error opening file.\n");
        return -1;
    }

    while (fscanf(f, "%d;%[^;];%[^;];%d\n", &car.Num, car.Matricule, car.Nom, &car.tarif) != EOF) {
        if (car.Num == NumCar) {
            fclose(f);
            return 1;
        }
    }

    fclose(f);
    return -1;
}

void Ajouter() {
    struct car newCar;
    FILE *f = fopen("cars1.txt", "a");
    if (f == NULL) {
        printf("Error opening file.\n");
        return;
    }

    printf("\nEntrer le num de la voiture: ");
    int NumCar;
    scanf("%d", &NumCar);
    fflush(stdin);

    while (rech(NumCar) == 1) {
        printf("\nCe numero existe deja. Entrer un autre: ");
        scanf("%d", &NumCar);
        fflush(stdin);
    }
    newCar.Num = NumCar;

    printf("Entrer le nom de la voiture: \n");
    scanf("%s", newCar.Nom);

    printf("Entrer le tarif: \n ");
    scanf("%d", &newCar.tarif);

    printf("Entrer la matricule: \n ");
    scanf("%s", newCar.Matricule);

    printf("Registration successful.\n");

    fprintf(f, "%d;%s;%s;%d\n", newCar.Num, newCar.Matricule, newCar.Nom, newCar.tarif);
    fclose(f);
}

void Afficher() {
    FILE *f = fopen("cars1.txt", "r");
    if (f == NULL) {
        printf("Error opening file.\n");
        return;
    }

    while (fscanf(f, "%d;%[^;];%[^;];%d\n", &car.Num, car.Matricule, car.Nom, &car.tarif) != EOF) {
        printf("---DISPLAYING ALL CARS---\n");
        printf("NUMBER:\t%d\t", car.Num);
        printf("MATRICULE:\t%s\t", car.Matricule);
        printf("NAME:\t%s\t", car.Nom);
        printf("TARIFF:\t%d\n", car.tarif);
    }

    fclose(f);
}











/*void supprimerCar() {
    char rep;
    int NumRech;
    printf("Enter the car number: ");
    scanf("%d", &NumRech);
    fflush(stdin);

    if (rech(NumRech) == 1) {
        printf("\n Do you really want to delete this car? (O/n): ");
        scanf(" %c", &rep);

        if (rep == 'o' || rep == 'O') {
            FILE *f = fopen("cars1.txt", "r");
            FILE *fich = fopen("texte6.txt", "a");
            if (f == NULL || fich == NULL) {
                printf("Error opening file.\n");
                return;
            }

            while (fscanf(f, "%d;%[^;];%d\n", &car.Num, car.Matricule, &car.tarif) == 3) {
                if (NumRech != car.Num) {
                    fprintf(fich, "%d;%s;%d\n", car.Num, car.Matricule, car.tarif);
                }
            }

            fclose(f);
            fclose(fich);
            remove("cars1.txt");
            rename("texte6.txt", "cars1.txt");
            printf("Deletion successful.\n");
        }
    }
}*/

int rech2(int NumCar) {
    FILE *f = fopen("description1.txt", "r");
    if (f == NULL) {
        printf("Error opening file.\n");
        return -1;
    }

    while (fscanf(f, "%d;%[^;];%[^;];%[^;];%[^;];%[^;];%d;%f\n",
                  &des.Num, des.Marque, des.energie, des.couleur,
                  des.etat, des.classe, &des.puissance, &des.compteur) != EOF) {
        if (des.Num == NumCar) {
            fclose(f);
            return 1;
        }
    }

    fclose(f);
    return -1;
}

void Ajouterdes() {
    int NumCar;
    FILE *f = fopen("description1.txt", "a+");
    if (f == NULL) {
        printf("Error opening file.\n");
        return;
    }

    printf("\nEntrer le numero de la nouvelle voiture: ");
    scanf("%d", &NumCar);
    fflush(stdin);

    while (rech2(NumCar) == 1) {
        printf("\nCe numero existe deja.Entrer un autre: ");
        scanf("%d", &NumCar);
        fflush(stdin);
    }
    des.Num = NumCar;

    printf("Entrer La Marque: ");
    gets(des.Marque);

    printf("Entrer L'energie: ");
    gets(des.energie);

    printf("Entrer La couleur: ");
    gets(des.couleur);

    printf("Entrer l'etat de la voiture: ");
    gets(des.etat);

    printf("Entrer Classe de la voiture: ");
    gets(des.classe);

    printf("Entrer la puissance de la voiture: ");
    scanf("%d", &des.puissance);

    printf("Entrer le compteur de la voiture: ");
    scanf("%f", &des.compteur);

    printf("Registration successful.\n");

    fprintf(f, "%d;%s;%s;%s;%s;%s;%d;%f\n", des.Num, des.Marque, des.energie,
            des.couleur, des.etat, des.classe, des.puissance, des.compteur);
    fclose(f);
}

void Affich_des() {
    int NumR;
    printf("Enter the car number: ");
    scanf("%d", &NumR);

    FILE *f = fopen("description1.txt", "r");
    if (f == NULL) {
        printf("Error opening file.\n");
        return;
    }

    if (rech2(NumR) != 1) {
        printf("It does not exist.\n");
    } else {
        while (fscanf(f, "%d;%[^;];%[^;];%[^;];%[^;];%[^;];%d;%f\n",
                      &des.Num, des.Marque, des.energie, des.couleur,
                      des.etat, des.classe, &des.puissance, &des.compteur) != EOF) {
            if (NumR == des.Num) {
                printf("---DISPLAYING Description---\n");
                printf("Num:\t%d\t", des.Num);
                printf("Marque:\t%s\t", des.Marque);
                printf("Energie:\t%s\t", des.energie);
                printf("Coleur:\t%s\t", des.couleur);
                printf("Etat:\t%s\t", des.etat);
                printf("Class:\t%s\t", des.classe);
                printf("Puissance:\t%d\t", des.puissance);
                printf("Compteur:\t%f\n", des.compteur);
            }
        }
    }
    fclose(f);
}



void Modifierdes() {
    int num;
    char rep = 'n';
    printf("\nEntrer le numero de la voiture: ");
    scanf("%d", &num);
    fflush(stdin);

    if (rech2(num) == 1) {
        printf("\nVoulez Vous vraiment Modifier ces description? (o/n): ");
        scanf("%c", &rep);
        fflush(stdin);

        if (rep == 'o' || rep == 'O') {
            FILE *f = fopen("description1.txt", "r");
            FILE *fich = fopen("texte2.txt", "a");
            if (f == NULL || fich == NULL) {
                printf("Error opening file.\n");
                return;
            }

            while (fscanf(f, "%d;%[^;];%[^;];%[^;];%[^;];%[^;];%d;%f\n",
                          &des.Num, des.Marque, des.energie, des.couleur,
                          des.etat, des.classe, &des.puissance, &des.compteur) != EOF) {
                if (num == des.Num) {
                    des.Num = num;
                    printf("Entrer New Marque: ");
                    gets(des.Marque);

                    printf("Entrer new Energie: ");
                    gets(des.energie);

                    printf("Entrer new Coleur: ");
                    gets(des.couleur);

                    printf("Entrer new etat: ");
                    gets(des.etat);

                    printf("Entrer new Class: ");
                    gets(des.classe);

                    printf("Entrer new Puissance: ");
                    scanf("%d", &des.puissance);

                    printf("Entrer new compteur: ");
                    scanf("%f", &des.compteur);

                    printf("\nModification successful.\n");
                }
                fprintf(fich, "%d;%s;%s;%s;%s;%s;%d;%f\n", des.Num, des.Marque,
                        des.energie, des.couleur, des.etat, des.classe,
                        des.puissance, des.compteur);
            }

            fclose(f);
            fclose(fich);
            remove("description1.txt");
            rename("texte2.txt", "description1.txt");
            printf("Modification successful.\n");
        }

    }else printf("la description de cette voiture n'existe pas");
}
//valable
int voitureValable(int NumCar, struct date datedebut, struct date datefin) {
    FILE *f;
    f = fopen("histo1.txt", "r");

    if (f == NULL) {
        printf("Erreur lors de l'ouverture du fichier histo.txt.\n");
        return 0;
    }


    while (fscanf(f, "%d,%d,%d,%d/%d,%d/%d", &histo.id_client, &histo.NumCar, &histo.periode,
                  &histo.dateb.jour, &histo.dateb.mois, &histo.datef.jour, &histo.datef.mois) != EOF) {
        if (histo.NumCar == NumCar) {

            if ((datefin.jour < histo.dateb.jour || datedebut.jour > histo.datef.jour) &&
                (datefin.mois < histo.dateb.mois || datedebut.mois > histo.datef.mois)) {
                fclose(f);
                return 1; // La voiture est disponible entre les deux dates.
            } else {
                fclose(f);
                return 0; // La voiture est déjà louée pendant cette période.
            }
        }
    }

    fclose(f);
    return 1; // La voiture n'a pas d'historique, elle est donc disponible.
}

//louer
void louer(){
                 int num;
                 num=Numc();
                 if (rech(num)==1){
                 struct date debut,fin;
                 debut=Date();
                 fin=Date();
                 if (voitureValable(num, debut, fin)) {
                        Ajouterhis();

                        }
                else {
                      printf("La voiture est déjà louée pendant cette période.\n");
                     }
                 }
                 else printf("la voiture n'existe pas\n");
    }










int main() {
    int choix;
    char rep;
    do {
        system("cls");
        printf("*************MENU************* \n");
        printf("1-Ajouter Une Voiture \n");
        printf("2-Recherche la description d'une voiture \n");
        printf("3-supprimer Une voiture en panne \n");
        printf("4-Modifier la description d'une voiture \n");
        printf("5-Afficher tous les voitures \n");
        printf("6-Afficher tout l'historique \n");
        printf("7-Afficher l'historique d'une voitures \n");
        printf("8-Afficher si une voiture est valabe \n");
        printf("9-Louer une voiture \n");
        printf("10-Ajouter une description \n");
        printf("11-Quitter \n \n");
        do {
            printf("\n Entrer votre choix: ");
            scanf("%d", &choix);
        } while (choix < 1 || choix > 11);

        switch (choix) {
            case 1:
                Ajouter();
                break;
            case 2:
                Affich_des();
                break;
            /*case 3:
                supprimerCar();
                break;*/
            case 4:
                Modifierdes();
                break;
            case 5:
                Afficher();
                break;
            case 6:
                affichhistT();
                break;
            case 7:
                affichhisto();
                break;
            case 8: {
                int num;
                num = Numc();
                struct date debut, fin;
                debut = Date();
                fin = Date();
                if (voitureValable(num, debut, fin)) {
                    printf("La voiture est disponible entre les deux dates.\n");
                } else {
                    printf("La voiture est déjà louée pendant cette période.\n");
                }
                break;
            }
            case 9:
                louer();
                break;
            case 10:
                Ajouterdes();
                break;
            case 11:
                break;
        }
        printf("\n Voulez vous continuer O/N:");
        scanf(" %c", &rep);
        fflush(stdin);
    } while (rep == 'o' || rep == 'O');
    return 0;
}
