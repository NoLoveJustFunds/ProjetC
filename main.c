#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

//---------------------------------------------------------------------------------//

int FonctionAddition() {
    int pointUser = 0;
    int resultat, reponseUser, nbEssais;
    char continuer;

    srand(time(NULL));

    printf("Si vous trouvez en 1 seul coup, vous aurez 10 points\n");
    printf("Si vous trouvez en 2 coups, vous aurez 5 points\n");
    printf("Si vous trouvez en 3 coups, vous aurez 1 point\n");

    do {
        int nombre1 = rand() % 100 + 1;
        int nombre2 = rand() % 100 + 1;
        resultat = nombre1 + nombre2;
        nbEssais = 0;

        printf("\n%d + %d = ?\n", nombre1, nombre2);

        while (nbEssais < 3) {
            printf("Entrez le résultat : ");
            scanf("%d", &reponseUser);
            nbEssais++;

            if (reponseUser == resultat) {
                if (nbEssais == 1) {
                    printf("Bravo ! Vous avez eu 10 points !\n");
                    pointUser += 10;
                } else if (nbEssais == 2) {
                    printf("Bien joué ! Vous obtenez 5 points\n");
                    pointUser += 5;
                } else {
                    printf("Vous obtenez quand même 1 point\n");
                    pointUser += 1;
                }
                break;
            } else {
                if (nbEssais < 3) {
                    printf("Faux ! Essayez encore...\n");
                } else {
                    printf("Dommage, la bonne réponse était : %d\n", resultat);
                    printf("Vous avez échoué 3 fois.\n");
                }
            }
        }

        // Demander au joueur s'il veut continuer seulement si le jeu n'est pas déjà terminé
        if (nbEssais == 3 && reponseUser != resultat) {
            printf("Nombre total de points : %d\n", pointUser);
            break; // Sortir de la boucle do...while si le joueur a perdu
        }

        do {
            printf("Voulez-vous continuer ? (o/n) : ");
            scanf(" %c", &continuer);
        } while (continuer != 'o' && continuer != 'O' && continuer != 'n' && continuer != 'N');

    } while (continuer == 'o' || continuer == 'O');

    printf("Fin du jeu. Score final : %d\n", pointUser);
    return pointUser;
        
}

//---------------------------------------------------------------------------------//

int FonctionMultiplication() {
    int resultat, ReponseUser,nbEssais, pointUser = 0;
    char continuer;

    srand(time(NULL));

    printf("Si vous trouvez en 1 seul coup, vous aurez 10 points\n");
    printf("Si vous trouvez en 2 coups, vous aurez 5 points\n");
    printf("Si vous trouvez en 3 coups, vous aurez 1 point\n");

   

    do {
        int nombre1 = rand() % 10 + 1;
        int nombre2 = rand() % 10 + 1;
       
        resultat = nombre1 * nombre2; 
        nbEssais = 0;

        printf("%d * %d = ?\n", nombre1, nombre2);

        while (nbEssais < 3) {
            printf("Entrez le résultat : ");
            scanf("%d", &ReponseUser);
            nbEssais++;

            if (ReponseUser == resultat) {
                if (nbEssais == 1) {
                    printf("Bravo ! Vous avez eu 10 points !\n");
                    pointUser += 10;
                } else if (nbEssais == 2) {
                    printf("Bien joué ! Vous obtenez 5 points\n");
                    pointUser += 5;
                } else {
                    printf("Vous obtenez quand même 1 point\n");
                    pointUser += 1;
                }
                break;
            } else {
                if (nbEssais < 3) {
                    printf("Faux ! Essayez encore...\n");
                } else {
                    printf("Dommage, la bonne réponse était : %d\n", resultat);
                    printf("Vous avez échoué 3 fois.\n");
                }
            }
        }

        // Demander au joueur s'il veut continuer seulement si le jeu n'est pas déjà terminé
        if (nbEssais == 3 && ReponseUser != resultat) {
            printf("Nombre total de points : %d\n", pointUser);
            break; // Sortir de la boucle do...while si le joueur a perdu
        }

        do {
            printf("Voulez-vous continuer ? (o/n) : ");
            scanf(" %c", &continuer);
        } while (continuer != 'o' && continuer != 'O' && continuer != 'n' && continuer != 'N');

    } while (continuer == 'o' || continuer == 'O');

    printf("Fin du jeu. Score final : %d\n", pointUser);
    return pointUser;
}

//---------------------------------------------------------------------------------//

int FonctionSoustraction() {
    int resultat, ReponseUser,nbEssais,pointUser = 0;
    char continuer;


    srand(time(NULL));
    

    printf("Si vous trouvez en 1 seul coup, vous aurez 10 points\n");
    printf("Si vous trouvez en 2 coups, vous aurez 5 points\n");
    printf("Si vous trouvez en 3 coups, vous aurez 1 point\n");


    do {
        int nombre1 = rand() % 101;
        int nombre2 = rand() % 101;

        int permutation;
        if (nombre1 < nombre2) {
            permutation = nombre2;
            nombre2 = nombre1;
            nombre1 = permutation;
        }

        resultat = nombre1 - nombre2;
        nbEssais = 0;

        printf("%d - %d = ?\n", nombre1, nombre2);

        while (nbEssais < 3) {
            printf("Entrez le résultat : ");
            scanf("%d", &ReponseUser);
            nbEssais++;

            if (ReponseUser == resultat) {
                if (nbEssais == 1) {
                    printf("Bravo ! Vous avez eu 10 points !\n");
                    pointUser += 10;
                } else if (nbEssais == 2) {
                    printf("Bien joué ! Vous obtenez 5 points\n");
                    pointUser += 5;
                } else {
                    printf("Vous obtenez quand même 1 point\n");
                    pointUser += 1;
                }
                break;
            } else {
                if (nbEssais < 3) {
                    printf("Faux ! Essayez encore...\n");
                } else {
                    printf("Dommage, la bonne réponse était : %d\n", resultat);
                    printf("Vous avez échoué 3 fois.\n");
                }
            }
        }

        // Demander au joueur s'il veut continuer seulement si le jeu n'est pas déjà terminé
        if (nbEssais == 3 && ReponseUser != resultat) {
            printf("Nombre total de points : %d\n", pointUser);
            break; // Sortir de la boucle do...while si le joueur a perdu
        }

        do {
            printf("Voulez-vous continuer ? (o/n) : ");
            scanf(" %c", &continuer);
        } while (continuer != 'o' && continuer != 'O' && continuer != 'n' && continuer != 'N');

    } while (continuer == 'o' || continuer == 'O');

    printf("Fin du jeu | Total des points gagnés : %d\n", pointUser);

    return pointUser;
}

//---------------------------------------------------------------------------------//

int FonctionTableMultiplication(){


    int resultat, ReponseUser,choixUser,nbEssais,pointUser = 0;
    char continuer;
    
        do {
            printf("Entrer la table (1 à 10) sur laquelle que vous voulez travailler :\n");
            scanf("%d",&choixUser);

            for(int i =1; i <=10 ; i++){
                printf("%d * %d\n",i,choixUser);
            }

            
            for(int i = 1 ; i<=10 ;i++){
                printf("%d * %d =?\n", i , choixUser);
                resultat = i * choixUser; 
                nbEssais = 0;
                while (nbEssais < 3) {
                    printf("Entrez le résultat : ");
                    scanf("%d", &ReponseUser);
                    nbEssais++;
        
                    if (ReponseUser == resultat) {
                        if (nbEssais == 1) {
                            printf("Bravo ! Vous avez eu 10 points !\n");
                            pointUser += 10;
                        } else if (nbEssais == 2) {
                            printf("Bien joué ! Vous obtenez 5 points\n");
                            pointUser += 5;
                        } else {
                            printf("Vous obtenez quand même 1 point\n");
                            pointUser += 1;
                        }
                        break;
                    } else {
                        if (nbEssais < 3) {
                            printf("Faux ! Essayez encore...\n");
                        } else {
                            printf("Dommage, la bonne réponse était : %d\n", resultat);
                            
                        }
                    }
                }
                
                
            }
            
    
            // Demander au joueur s'il veut continuer seulement si le jeu n'est pas déjà terminé
            if (nbEssais == 3 && ReponseUser != resultat) {
                printf("Nombre total de points : %d\n", pointUser);
                break; // Sortir de la boucle do...while si le joueur a perdu
            }
    
            do {
                printf("Voulez-vous continuer ? (o/n) : ");
                scanf(" %c", &continuer);
            } while (continuer != 'o' && continuer != 'O' && continuer != 'n' && continuer != 'N');
    
        } while (continuer == 'o' || continuer == 'O');
    
        printf("Fin du jeu | Total des points gagnés : %d\n", pointUser);
    
       return pointUser; 
    }

//---------------------------------------------------------------------------------//

int FonctionDivision(){

    int resultat, ReponseUser,nbEssais,pointUser = 0;
    char continuer;


    srand(time(NULL));
    

    printf("Si vous trouvez en 1 seul coup, vous aurez 10 points\n");
    printf("Si vous trouvez en 2 coups, vous aurez 5 points\n");
    printf("Si vous trouvez en 3 coups, vous aurez 1 point\n");

    printf("\n---------------------------\n");
    printf("Ce jeu de division est différent des autres.\n");
    printf("Vous devez trouver le moduloe ( le reste ) de la divion de 2 nombres\n");
    printf("Par exemple , 14 modulo 3 = 2 car 4 x 3 = 12 et le reste est 2\n");


    do {
        int nombre1 = rand() % 101;
        int nombre2 = rand() % 101;

        int permutation;
        if (nombre1 < nombre2) {
            permutation = nombre2;
            nombre2 = nombre1;
            nombre1 = permutation;
        }

        resultat = nombre1 % nombre2;
        nbEssais = 0;

        printf("%d modulo %d = ?\n", nombre1, nombre2);

        while (nbEssais < 3) {
            printf("Entrez le résultat : ");
            scanf("%d", &ReponseUser);
            nbEssais++;

            if (ReponseUser == resultat) {
                if (nbEssais == 1) {
                    printf("Bravo ! Vous avez eu 10 points !\n");
                    pointUser += 10;
                } else if (nbEssais == 2) {
                    printf("Bien joué ! Vous obtenez 5 points\n");
                    pointUser += 5;
                } else {
                    printf("Vous obtenez quand même 1 point\n");
                    pointUser += 1;
                }
                break;
            } else {
                if (nbEssais < 3) {
                    printf("Faux ! Essayez encore...\n");
                } else {
                    printf("Dommage, la bonne réponse était : %d\n", resultat);
                    printf("Vous avez échoué 3 fois.\n");
                }
            }
        }

        // Demander au joueur s'il veut continuer seulement si le jeu n'est pas déjà terminé
        if (nbEssais == 3 && ReponseUser != resultat) {
            printf("Nombre total de points : %d\n", pointUser);
            break; // Sortir de la boucle do...while si le joueur a perdu
        }

        do {
            printf("Voulez-vous continuer ? (o/n) : ");
            scanf(" %c", &continuer);
        } while (continuer != 'o' && continuer != 'O' && continuer != 'n' && continuer != 'N');

    } while (continuer == 'o' || continuer == 'O');

    printf("Fin du jeu | Total des points gagnés : %d\n", pointUser);

    return pointUser;

}

//---------------------------------------------------------------------------------//

int MiniProbleme(){

    int resultat, ReponseUser,nbEssais,pointUser = 0;
    char continuer;

    srand(time(NULL));
    
    int nombreAlea = rand() % 5 + 1;
        
    if(nombreAlea == 1){
        printf("Wilfried avait 19 sacs de 40 bonbons . Il achète 18 bonbons .\n");
        resultat = 19*40 +18;
        printf("Combien a t'il de bonbons maintenant\n");
        scanf("%d", &ReponseUser);

        if(ReponseUser == resultat){
            printf("Excellent !  , vous avez gagné 15 points.\n");
            pointUser+=15;
        }else{
            printf("Voici la réflexion qu'il fallait avoir : \n");

            printf("\n");
            printf("Wilfried avait 19 sacs de 40 bonbons .\n");
            printf("Il faut donc commencer par faire une multiplication.\n");
            printf("Il achète 18 bonbons .\n");
            printf("Il aura donc 18 bonbons en plus.\n");
            printf("Opération : (19x40)+18 = 778\n");
            printf("Wilfried a 778 bonbons maintenant.\n");
        }
    
    }else if (nombreAlea == 2){
        printf("Eric avait 17 pochettes de 30 timbres.\n");
        printf("Il donne ensuite 8 timbres à chacun de ses 4 amis.\n");
        printf("Mais il achète 2 nouvelles pochettes contenant chacune 25 timbres.\n");

        resultat = (17 * 30) - (8 * 4) + (2 * 25);

        printf("Combien a-t-il de timbres maintenant ?\n");
        scanf("%d", &ReponseUser);

        if (ReponseUser == resultat) {
            printf("Excellent ! Vous avez gagné 15 points.\n");
            pointUser += 15;
        } else {
            printf("Voici la réflexion qu'il fallait avoir : \n\n");
            printf("Eric avait 17 pochettes de 30 timbres.\n");
            printf("Il faut donc commencer par faire une multiplication.\n");
            printf("Il donne ensuite 8 timbres à chacun de ses 4 amis.\n");
            printf("Il faut donc faire une soustraction.\n");
            printf("Mais il achète 2 nouvelles pochettes contenant chacune 25 timbres.\n");
            printf("Il faut donc faire une addition.\n\n");
            printf("Opération : (17 x 30) - (8 x 4) + (2 x 25) = %d\n", resultat);
            printf("Eric a maintenant %d timbres.\n", resultat);
        }
    }else if(nombreAlea == 3){
        printf("Arthur avait 19 boîtes de 18 petites voitures.\n");
        printf("Il donne ensuite 3 voitures à chacun de ses 5 amis.\n");
        printf("Mais il trouve un lot de 12 voitures en cadeau.\n");

        resultat = (19 * 18) - (3 * 5) + 12;

        printf("Combien a-t-il de petites voitures maintenant ?\n");
        scanf("%d", &ReponseUser);

        if (ReponseUser == resultat) {
            printf("Excellent ! Vous avez gagné 15 points.\n");
            pointUser += 15;
        } else {
            printf("Voici la réflexion qu'il fallait avoir : \n\n");
            printf("Arthur avait 19 boîtes de 18 petites voitures.\n");
            printf("Il faut donc commencer par faire une multiplication.\n");
            printf("Il donne ensuite 3 voitures à chacun de ses 5 amis.\n");
            printf("Il faut donc faire une soustraction.\n");
            printf("Mais il trouve un lot de 12 voitures en cadeau.\n");
            printf("Il faut donc faire une addition.\n\n");
            printf("Opération : (19 x 18) - (3 x 5) + 12 = %d\n", resultat);
            printf("Arthur a maintenant %d petites voitures.\n", resultat);
        }
    }else if (nombreAlea ==4){

        printf("Bob avait 4 boîtes de 6 balles rouge . Il vend 1 boite mais il recoit 3 boites de 3 balles rouge .\n");
        resultat = ((4*6)-6) + 3*3;
        printf("Combien a-t-il de balles rouges maintenant ?\n");
        scanf("%d", &ReponseUser);

        if(ReponseUser == resultat){
            printf("Excellent !  , vous avez gagné 15 points.\n");
            pointUser+=15;
        }else{
            printf("Voici la réflexion qu'il fallait avoir : \n");

            printf("\n");
            printf("Bob avait 4 boîtes de 3 balles rouge .\n");
            printf("Il faut donc commencer par faire une multiplication.\n");
            printf("Il vend 1 boite de balles rouge .\n");
            printf("Il aura donc 6 balles rouge en moins.\n");
            printf("Il recoit 3 boites contenant chacune 3 balles rouge\n");
            printf("Il aura donc 9 balles rouges en plus\n");
            printf("\n");
            printf("Opération : ((4*6)-6) + 3*3 = %d\n",resultat);
            printf("Bob a %d balles rouge maintenant.\n",resultat);
        }
    }else{
        printf("Lucas collectionne des cartes. Il achète 6 paquets contenant chacun 15 cartes.\n");
        printf("Mais il donne ensuite 2 cartes à chacun de ses 4 amis.\n");
        printf("Il recoit ensuite un cadeau de 10 cartes.\n");
        resultat = (6 * 15) - (2 * 4) + 10 ;
        printf("Combien a-t-il de cartes maintenant ?\n");
        scanf("%d", &ReponseUser);


        if(ReponseUser == resultat){
            printf("Excellent !  , vous avez gagné 15 points.\n");
            pointUser+=15;
        }else{
            printf("Voici la réflexion qu'il fallait avoir : \n");

            printf("\n");
            printf("Lucas avait 6 paquets contenant chacun 15 cartes.\n");
            printf("Il faut donc commencer par faire une multiplication.\n");
            printf("Il donne ensuite 2 cartes à chacun de ses amis .\n");
            printf("Il aura donc 8 cartes en moins.\n");
            printf("Il recoit 10 cartes en cadeau .\n");
            printf("Il aura donc 2 cartes en plus par rapport à son paquet initial.\n");
            printf("\n");
            printf("Opération : (6 x 15) - (2 x 4) + 10 =  %d .\n",resultat);
            printf("Lucas a %d cartes maintenant.\n",resultat);
        }
    
    }     

printf("Fin du jeu | Total des points gagnés : %d\n", pointUser);
return pointUser;
}

//---------------------------------------------------------------------------------//

int QuizGenerale() {
    int score = 0;
    int reponse;
    char ReponseQuestion[30];

    printf("Votre score sera affiché a la fin , vous aurez 20 points par bonne réponse ! \n");

    // Question 1
    printf("Question 1: Qui a écrit 'Les Misérables' ?\n");
    printf("1. Victor Hugo\n2. Emile Zola\n3. Marcel Proust\n4. Honoré de Balzac\n");
    printf("Votre réponse (1-4): ");
    scanf("%d", &reponse);
    strcpy(ReponseQuestion ,"Victor Hugo");
    (reponse ==1) ? score+=20 : printf("La bonne réponse était : %s",ReponseQuestion);

    // Question 2
    printf("\nQuestion 2: Quelle est la capitale de l'Australie ?\n");
    printf("1. Sydney\n2. Melbourne\n3. Canberra\n4. Brisbane\n");
    printf("Votre réponse (1-4): ");
    scanf("%d", &reponse);
    strcpy(ReponseQuestion ,"Canberra");
    (reponse ==3) ? score+=20 : printf("La bonne réponse était : %s",ReponseQuestion);

    // Question 3
    printf("\nQuestion 3: Qui a peint la Joconde ?\n");
    printf("1. Michel-Ange\n2. Léonard de Vinci\n3. Raphael\n4. Claude Monet\n");
    printf("Votre réponse (1-4): ");
    scanf("%d", &reponse);
    strcpy(ReponseQuestion ,"Léonard de Vinci");
    (reponse ==2) ? score+=20 : printf("La bonne réponse était : %s",ReponseQuestion);

    // Question 4
    printf("\nQuestion 4: Quel est le plus grand océan du monde ?\n");
    printf("1. Atlantique\n2. Pacifique\n3. Indien\n4. Arctique\n");
    printf("Votre réponse (1-4): ");
    scanf("%d", &reponse);
    strcpy(ReponseQuestion ,"Pacifique");
    (reponse ==2) ? score+=20 : printf("La bonne réponse était : %s",ReponseQuestion);

    // Question 5
    printf("\nQuestion 5: Quelle est la durée d'une année sur Mars ?\n");
    printf("1. 365 jours\n2. 550 jours\n3. 720 jours\n4. 687 jours\n");
    printf("Votre réponse (1-4): ");
    scanf("%d", &reponse);
    strcpy(ReponseQuestion ,"687 jours");
    (reponse ==4) ? score+=20 : printf("La bonne réponse était : %s",ReponseQuestion);

    // Question 6
    printf("\nQuestion 6: Qui est le fondateur de la psychanalyse ?\n");
    printf("1. Carl Jung\n2. Sigmund Freud\n3. Alfred Adler\n4. William James\n");
    printf("Votre réponse (1-4): ");
    scanf("%d", &reponse);
    strcpy(ReponseQuestion ,"Sigmund Freud");
    (reponse ==2) ? score+=20 : printf("La bonne réponse était : %s",ReponseQuestion);

    // Question 7
    printf("\nQuestion 7: Quel est l'élément chimique dont le symbole est 'Au' ?\n");
    printf("1. Argent\n2. Or\n3. Aluminium\n4. Uranium\n");
    printf("Votre réponse (1-4): ");
    scanf("%d", &reponse);
    strcpy(ReponseQuestion ,"L'or");
    (reponse ==2) ? score+=20 : printf("La bonne réponse était : %s",ReponseQuestion);

    // Question 8
    printf("\nQuestion 8: Quel est le plus grand désert chaud du monde ?\n");
    printf("1. Sahara\n2. Désert de Gobi\n3. Kalahari\n4. Désert de Sonora\n");
    printf("Votre réponse (1-4): ");
    scanf("%d", &reponse);
    strcpy(ReponseQuestion ,"Sahara");
    (reponse ==1) ? score+=20 : printf("La bonne réponse était : %s",ReponseQuestion);

    // Question 9
    printf("\nQuestion 9: Qui a inventé l'ampoule électrique ?\n");
    printf("1. Nikola Tesla\n2. Thomas Edison\n3. Alexander Graham Bell\n4. Michael Faraday\n");
    printf("Votre réponse (1-4): ");
    scanf("%d", &reponse);
    strcpy(ReponseQuestion ,"Thomas Edison");
    (reponse ==2) ? score+=20 : printf("La bonne réponse était : %s",ReponseQuestion);

    // Question 10
    printf("\nQuestion 10: Quel est le plus long fleuve du monde ?\n");
    printf("1. Amazone\n2. Nil\n3. Yangzi\n4. Mississippi\n");
    printf("Votre réponse (1-4): ");
    scanf("%d", &reponse);
    strcpy(ReponseQuestion ,"Le Nil");
    (reponse ==2) ? score+=20 : printf("La bonne réponse était : %s",ReponseQuestion);

    // Afficher le score
    printf("\nVotre score final: %d/200\n", score);

    return score;
}
    
//---------------------------------------------------------------------------------//

char* date_actu() {
    static char s_now[20]; // "JJ/MM/AAAA-HH:MM:SS" = 19 caractères + '\0'
    time_t now = time(NULL); //Retourne l'heure actuelle
    struct tm* tm_now = localtime(&now); //localtime(&now) convertit la valeur du temps now en seconde en une structure tm

    if (tm_now == NULL) {
        return NULL;
    }

    strftime(s_now, sizeof(s_now), "%d/%m/%Y-%H:%M:%S", tm_now); //On formate avec strftime dans le tableau s_now
    return s_now; //Sans static , le pointeur sur s_now sera invalide car varaible détruite a la fin de la fonctions
    }
     
//---------------------------------------------------------------------------------//

void CreationJoueur(char* NomUser, char* PnomUser, char* date, int Nbpoint) {
    FILE* F = fopen("FichierPoints.txt", "a"); // Ouvre en mode ajout
    if (F == NULL) {
        printf("Erreur lors de l'ouverture du fichier\n");
        return;
    }
    
    printf("Votre profil va etre ajouté ... \n");
    
    // Utilisation du délimiteur | entre les champs et ajout d'un retour à la ligne
    fprintf(F, "%s|%s|%s|%d\n", NomUser, PnomUser, date, Nbpoint);
    
    printf("Votre profil a été crée ! \n");
    
    // Fermeture du fichier
    fclose(F);
}

//---------------------------------------------------------------------------------//  

bool VerificationJoueurExiste(char* NomUser, char* PnomUser) {
    FILE *F = fopen("FichierPoints.txt", "r");
    if (F == NULL) {
        printf("Erreur lors de l'ouverture du fichier\n");
        return false;
    }

    char ligne[256];
    bool joueurExiste = false;
    
    while (fgets(ligne, sizeof(ligne), F)) { //Lecture de la ligne
        char *name, *prenom, *copie;
        
        
        copie = strdup(ligne);// On fait une copie de la ligne car strtok modifie la chaîne
        if (copie == NULL) {
            printf("Erreur d'allocation mémoire\n");
            fclose(F);
            return false;
        }
        
        
        name = strtok(copie, "|");// Extraction du nom (premier champ)
        if (name != NULL) {
            prenom = strtok(NULL, "|"); //Extraction du second champs ( prenom)
            
            if (prenom != NULL) {
                if (strcmp(name, NomUser) == 0 && strcmp(prenom, PnomUser) == 0) {
                    printf("Votre profil est deja enregistré dans le jeu ! \n");
                    joueurExiste = true;
                    free(copie); //Libere la memoire
                    break;
                }
            }
        }
        
        free(copie);
    }
    
    fclose(F);
    return joueurExiste;
}

//---------------------------------------------------------------------------------//
 
bool chercherJoueur(char* NomUser, char* PnomUser, int *PointsUser) {
    FILE *F = fopen("FichierPoints.txt", "r");
    if (F == NULL) {
        printf("Erreur lors de l'ouverture du fichier\n");
        return false;
    }

    char ligne[256];
    bool joueurTrouve = false;
    
    while (fgets(ligne, sizeof(ligne), F)) {
        // Supprimer le retour à la ligne s'il existe
        ligne[strcspn(ligne, "\n")] = 0;
        
        char *name, *prenom, *date, *points, *copie;
        
        // Faire une copie car strtok modifie la chaîne originale
        copie = strdup(ligne);
        if (copie == NULL) {
            printf("Erreur d'allocation mémoire\n");
            fclose(F);
            return false;
        }
        
        // Extraction des données avec strtok
        name = strtok(copie, "|");
        if (name != NULL) {
            prenom = strtok(NULL, "|");
            if (prenom != NULL) {
                date = strtok(NULL, "|");
                if (date != NULL) {
                    points = strtok(NULL, "|");
                    if (points != NULL) {
                        // Vérifier si c'est le joueur recherché
                        if (strcmp(name, NomUser) == 0 && strcmp(prenom, PnomUser) == 0) {
                            *PointsUser = atoi(points);  // Convertir points en entier
                            joueurTrouve = true;
                            free(copie);
                            break;
                        }
                    }
                }
            }
        }
        
        free(copie);
    }
    
    fclose(F);
    return joueurTrouve;
}
    
//---------------------------------------------------------------------------------//

void AfficherPointsJoueur(char *NomUser, char *PnomUser) {
    int NbPoints;
    if (chercherJoueur(NomUser, PnomUser, &NbPoints)) {
        printf("Vous avez : %d points.\n", NbPoints);
    } else {
        printf("Vos points n'ont pas été trouvés par le système.\n");
    }
}

//---------------------------------------------------------------------------------//

void MiseAjourPoints(char *NomUser, char *PnomUser, int PointsUser) {
    FILE *F = fopen("FichierPoints.txt", "r");
    FILE *F2 = fopen("FichierTemp.txt", "w");
    if (F == NULL || F2 == NULL) {
        printf("Erreur lors de l'ouverture des fichiers\n");
        return;
    }

    char ligne[256];
    
    
    while (fgets(ligne, sizeof(ligne), F)) {
        
        ligne[strcspn(ligne, "\n")] = 0;  // Supprimer le retour à la ligne s'il existe ( \n )
        
        char *name, *prenom, *date, *points_str; //Creation de pointeur sur les elements du fichier
        int NbPoints;
        
        
        char *copie = strdup(ligne);// Faire une copie de la ligne pour strtok car modifie la chaine
        if (copie == NULL) {
            fclose(F);
            fclose(F2);
            return;
        }
        
        // Extraire les champs
        name = strtok(copie, "|");
        prenom = strtok(NULL, "|");
        date = strtok(NULL, "|");
        points_str = strtok(NULL, "|");
        
        if (name && prenom && date && points_str) {
            NbPoints = atoi(points_str); //On convertir la chaine en nombre de points
            
            if (strcmp(name, NomUser) == 0 && strcmp(prenom, PnomUser) == 0) {
                NbPoints += PointsUser;
                char date_nouvelle[30];
                strcpy(date_nouvelle, date_actu());
                
                // Écrire dans le fichier temporaire avec les nouvelles informations
                fprintf(F2, "%s|%s|%s|%d\n", name, prenom, date_nouvelle, NbPoints);
            } else {
                // Écrire la ligne originale dans le fichier temporaire
                fprintf(F2, "%s|%s|%s|%d\n", name, prenom, date, NbPoints);
            }
        }
        
        free(copie);
    }
    
    fclose(F);
    fclose(F2);
    
    // Remplacer l'ancien fichier par le fichier temporaire
    remove("FichierPoints.txt"); // Supprimer l'ancien fichier
    rename("FichierTemp.txt", "FichierPoints.txt"); // Renommer le fichier temporaire
    
    printf("Les points ont été mis à jour avec succès !\n");
}
    
//---------------------------------------------------------------------------------//


int main(int argc, char *argv[]) {
    
    srand(time(NULL)); // Initialisation unique du générateur de nombres aléatoires

    char NameUser[20];
    char RecupPoint;
    char SurnameUser[20];
    char reponse[5];
    int choix = -1; // Initialisation de choix

    printf("Bing ! Bienvenue dans le jeu de calcul mental !\n");

    printf("Entrez votre nom : ");
    scanf("%s", NameUser);
    printf("Entrez votre prénom : ");
    scanf("%s",SurnameUser);

    printf("Etes vous inscrit ? (Oui/Non) : ");
    scanf("%s",reponse);
    if(strcmp(reponse , "Oui")==0){
        if(VerificationJoueurExiste(NameUser , SurnameUser) == false){
            CreationJoueur(NameUser,SurnameUser,date_actu(),0);
        }else{
            printf("Heureux de vous revoir ! \n");
        }
        
    }else{
        if(VerificationJoueurExiste(NameUser , SurnameUser) == false){
            CreationJoueur(NameUser,SurnameUser,date_actu(),0);
        }
    }

    printf("Souhaitez vous récuperer vos points (O/N) ? :");
    scanf(" %c", &RecupPoint); 

    if (RecupPoint == 'O') {
        AfficherPointsJoueur(NameUser,SurnameUser);
    }
        // Boucle du menu tant que l'utilisateur ne choisit pas 0
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

            printf("Quel est votre choix ? \n");
            scanf("%d", &choix);

            // Exécuter l'action correspondante
            switch (choix) {
                case 0:
                    printf("Merci de votre visite !\n");
                    break;
                case 1:
                    MiseAjourPoints(NameUser,SurnameUser,FonctionAddition());
                    break;
                case 2:
                    MiseAjourPoints(NameUser,SurnameUser,FonctionSoustraction());
                    break;
                case 3:
                    MiseAjourPoints(NameUser,SurnameUser,FonctionMultiplication());   
                    break;
                case 4:
                    MiseAjourPoints(NameUser,SurnameUser,FonctionTableMultiplication());
                    break;
                case 5:
                    MiseAjourPoints(NameUser,SurnameUser,FonctionDivision());
                    break;
                case 6:
                    MiseAjourPoints(NameUser , SurnameUser,MiniProbleme());
                    break;
                case 7:
                    MiseAjourPoints(NameUser , SurnameUser,QuizGenerale());
                    break;
                case 8:
                    AfficherPointsJoueur(NameUser,SurnameUser);
                    break;
                default:
                    printf("Erreur de saisie, veuillez réessayer.\n");
                    break;
        }
    }

    return 0;
}
