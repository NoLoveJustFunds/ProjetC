//Importation des bibliothèques nécessaires
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include "header.h" //Importation du fichier header.h contenant les prototypes des fonctions qui seront utilisées dans le jeu


int main(int argc, char *argv[]) {
    
    srand(time(NULL)); // Initialisation  du générateur de nombres aléatoires

    char NameUser[20];
    char RecupPoint;
    char SurnameUser[20];
    char reponse[5];
    int choix = -1; // Initialisation du choxi de départ pour pouvoir rentrer dans la boucle

    printf("\n");

    printf("Boom ! Bienvenue dans le jeu de calcul mental !\n");
    printf("\n");

    printf("Saisissez votre nom : ");
    scanf("%s", NameUser);

    printf("\n");
    printf("Saisissez votre prénom : ");
    scanf("%s",SurnameUser);

    printf("\n");
    printf("Etes vous déjà inscrit ? (Oui/Non) : ");
    scanf("%s",reponse);
    if((strcmp(reponse , "Oui")==0) || strcmp(reponse , "oui")==0){
        if(VerificationJoueurExiste(NameUser , SurnameUser) == false){
            CreationJoueur(NameUser,SurnameUser,date_actu(),0);
            printf("Utilisateur introuvable , un profil vient d'etre crée ! \n");
        }else{
            printf("Votre profil a été récupéré avec succès ! \n");
        }
        
    }else{
        if(VerificationJoueurExiste(NameUser , SurnameUser) == false){
            printf("Votre profil a été créé avec succès ! \n");
            CreationJoueur(NameUser,SurnameUser,date_actu(),0);
        }else{
            printf("Votre profil existe déjà, il a été récupéré avec succès ! \n");
        }
    }
    printf("\n");
    printf("Souhaitez vous récuperer vos points (O/N) ? :");
    scanf(" %c", &RecupPoint); 
    printf("\n");

    if ((RecupPoint == 'O') || ( RecupPoint == 'o')) {
        AfficherPointsJoueur(NameUser,SurnameUser);
    }
        // Boucle du menu tant que l'utilisateur ne choisit pas 0 ( ne veut pas quitter)
        while (choix != 0) {
            printf("+-------------------------------+\n");
            printf("| 1: Addition                   |\n");
            printf("| 2: Soustraction               |\n");
            printf("| 3: Multiplication             |\n");
            printf("| 4: Tables des multiplications |\n");
            printf("| 5: Division                   |\n");
            printf("| 6: MiniProbleme               |\n");
            printf("| 7: QuizGenerale               |\n");
            printf("| 8: Mon score                  |\n");
            printf("| 0: Quitter                    |\n");
            printf("+-------------------------------+\n");

            printf("Saisissez votre choix :");
            scanf("%d", &choix);
            printf("\n");

            // Exécute l'action correspondante selon le choix de l'utilisateur
            switch (choix) {
                case 0:
                    printf("Merci de votre visite !\n");
                    break;
                case 1:
                    MiseAjourPoints(NameUser,SurnameUser,FonctionAddition());
                    printf("\n");
                    break;
                case 2:
                    MiseAjourPoints(NameUser,SurnameUser,FonctionSoustraction());
                    printf("\n");
                    break;
                case 3:
                    MiseAjourPoints(NameUser,SurnameUser,FonctionMultiplication());   
                    printf("\n");
                    break;
                case 4:
                    MiseAjourPoints(NameUser,SurnameUser,FonctionTableMultiplication());
                    printf("\n");
                    break;
                case 5:
                    MiseAjourPoints(NameUser,SurnameUser,FonctionDivision());
                    printf("\n");
                    break;
                case 6:
                    MiseAjourPoints(NameUser , SurnameUser,MiniProbleme());
                    printf("\n");
                    break;
                case 7:
                    MiseAjourPoints(NameUser , SurnameUser,QuizGenerale());
                    printf("\n");
                    break;
                case 8:
                    AfficherPointsJoueur(NameUser,SurnameUser);
                    printf("\n");
                    break;
                default:
                    printf("Erreur de saisie, veuillez réessayer.\n"); //Cas par défault si il n'entre pas un nombre entre 0 et 8
                    break;
        }
    }

    return 0;
}
