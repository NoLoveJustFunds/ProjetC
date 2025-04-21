//Importation des bibliothèques nécessaires
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

    printf("Bienvenue dans le jeu d'addition !\n");
    printf("Vous avez 3 essais pour trouver le résultat d'une addition.\n");
    printf("\n");

    printf("Si vous trouvez en 1 seul coup, vous aurez 10 points.\n");
    printf("Si vous trouvez en 2 coups, vous aurez 5 points.\n");
    printf("Si vous trouvez en 3 coups, vous aurez 1 point.\n");
    printf("\n");

    printf("Bonne chance !\n");

    do {
        int nombre1 = rand() % 100 + 1; //Génère un nombre aléatoire entre 1 et 100
        int nombre2 = rand() % 100 + 1;
        resultat = nombre1 + nombre2;
        nbEssais = 0;

        printf("\n%d + %d = ?\n", nombre1, nombre2);

        while (nbEssais < 3) {
            printf("Entrez le résultat : ");
            scanf("%d", &reponseUser);
            printf("\n");
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

        // Demande au joueur s'il veut continuer seulement si le jeu n'est pas déjà terminé
        if (nbEssais == 3 && reponseUser != resultat) {
            printf("Nombre total de points : %d\n", pointUser);
            printf("\n");
            break; // Sort de la boucle do...while si le joueur a perdu
        }

        do {
            printf("Souhaitez-vous continuer ? (o/n) : ");
            scanf(" %c", &continuer);
        } while (continuer != 'o' && continuer != 'O' && continuer != 'n' && continuer != 'N');

    } while (continuer == 'o' || continuer == 'O');

    printf("\n");
    printf("Fin du jeu. Total des points gagnés : %d\n", pointUser);
    return pointUser;
        
}

//---------------------------------------------------------------------------------//

int FonctionMultiplication() {
    int resultat, ReponseUser,nbEssais, pointUser = 0;
    char continuer;

    srand(time(NULL));

    printf("Bienvenue dans le jeu de multiplication !\n");
    printf("Vous avez 3 essais pour trouver le résultat d'une multiplication.\n");
    printf("\n");

    printf("Si vous trouvez en 1 seul coup, vous aurez 10 points\n");
    printf("Si vous trouvez en 2 coups, vous aurez 5 points\n");
    printf("Si vous trouvez en 3 coups, vous aurez 1 point\n");
    printf("\n");

    printf("Bonne chance !\n");
    printf("\n");


    do {
        int nombre1 = rand() % 15 + 1; //Génère un nombre aléatoire entre 1 et 15
        int nombre2 = rand() % 15 + 1;
       
        resultat = nombre1 * nombre2; 
        nbEssais = 0;

        printf("%d * %d = ?\n", nombre1, nombre2);

        while (nbEssais < 3) {
            printf("Entrez le résultat : ");
            scanf("%d", &ReponseUser);
            printf("\n");
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

        // Demande au joueur s'il veut continuer seulement si le jeu n'est pas déjà terminé
        if (nbEssais == 3 && ReponseUser != resultat) {
            printf("Nombre total de points : %d\n", pointUser);
            printf("\n");
            break; // Sort de la boucle do...while si le joueur a perdu
        }

        do {
            printf("Souhaitez-vous continuer ? (o/n) : ");
            scanf(" %c", &continuer);
            printf("\n");
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

    printf("Bienvenue dans le jeu de soustraction !\n");
    printf("Vous avez 3 essais pour trouver le résultat d'une soustraction.\n");
    printf("\n");
    

    printf("Si vous trouvez en 1 seul coup, vous aurez 10 points\n");
    printf("Si vous trouvez en 2 coups, vous aurez 5 points\n");
    printf("Si vous trouvez en 3 coups, vous aurez 1 point\n");
    printf("\n");

    printf("Bonne chance !\n");
    printf("\n");


    do {
        int nombre1 = rand() % 101;//Génère un nombre aléatoire entre 0 et 100
        int nombre2 = rand() % 101;

        int permutation; //Permuation des éléments si le nombre 1 est plus petit que le nombre 2 (soustraction simple pour les CM1)
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
            printf("\n");
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

        // Demande au joueur s'il veut continuer seulement si le jeu n'est pas déjà terminé
        if (nbEssais == 3 && ReponseUser != resultat) {
            printf("Nombre total de points : %d\n", pointUser);
            printf("\n");
            break; // Sort de la boucle do...while si le joueur a perdu
        }

        do {
            printf("Souhaitez-vous continuer ? (o/n) : ");
            scanf(" %c", &continuer);
            printf("\n");
        } while (continuer != 'o' && continuer != 'O' && continuer != 'n' && continuer != 'N');

    } while (continuer == 'o' || continuer == 'O');

    printf("Fin du jeu | Total des points gagnés : %d\n", pointUser);

    return pointUser;
}

//---------------------------------------------------------------------------------//

int FonctionTableMultiplication(){

    printf("Bienvenue dans le jeu des tables de multiplications !\n");
    printf("Vous devez choisir une table de multiplication sur laquelle vous souhaitez vous entrainer.\n");
    printf("Vous avez 3 essais pour trouver le résultat d'une multiplication.\n");
    printf("\n");

    printf("Si vous trouvez en 1 seul coup, vous aurez 10 points.\n");
    printf("Si vous trouvez en 2 coups, vous aurez 5 points.\n");
    printf("Si vous trouvez en 3 coups, vous aurez 1 point.\n");
    printf("\n");

    printf("Bonne chance !\n");
    printf("\n");

    int resultat, ReponseUser,choixUser,nbEssais,pointUser = 0;
    char continuer;
    
        do {
            printf("Entrer la table (1 à 10) sur laquelle que vous voulez travailler :");
            scanf("%d",&choixUser);
            printf("\n");

            for(int i =1; i <=10 ; i++){
                printf("%d * %d\n",i,choixUser);
            }

            printf("\n");
            for(int i = 1 ; i<=10 ;i++){ //Boucle qui parcourt tous les nombres dans la table de multiplication choisie
                printf("\n");
                printf("%d * %d =?\n", i , choixUser);
                resultat = i * choixUser; 
                nbEssais = 0;
                while (nbEssais < 3) {
                    printf("Entrez le résultat : ");
                    scanf("%d", &ReponseUser);
                    printf("\n");
                    nbEssais++;
        
                    if (ReponseUser == resultat) {
                        if (nbEssais == 1) {
                            printf("Bravo ! Vous avez obtenu 10 points !\n");
                            pointUser += 10;
                        } else if (nbEssais == 2) {
                            printf("Bien joué ! Vous avez obtenu 5 points\n");
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
            
    
            // Demande au joueur s'il veut continuer seulement si le jeu n'est pas déjà terminé
            if (nbEssais == 3 && ReponseUser != resultat) {
                printf("Nombre total de points : %d\n", pointUser);
                printf("\n");
                break; // Sort de la boucle do...while si le joueur a perdu
            }
    
            do {
                printf("Souhaitez-vous continuer ? (o/n) : ");
                scanf(" %c", &continuer);
                printf("\n");
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
    
    printf("Bienvenue dans le jeu de division euclidienne !\n");
    printf("Vous avez 3 essais pour trouver le résultat d'une division.\n");
    printf("\n");

    printf("Si vous trouvez en 1 seul coup, vous aurez 10 points.\n");
    printf("Si vous trouvez en 2 coups, vous aurez 5 points.\n");
    printf("Si vous trouvez en 3 coups, vous aurez 1 point.\n");
    printf("\n");

    printf("Ce mini jeu de division est différent des autres.\n");
    printf("Vous devez trouver le modulo ( le reste ) de la divion de 2 nombres.\n");
    printf("Par exemple , 14 modulo 3 = 2 car 4 x 3 = 12 et le reste est 2.\n");
    printf("\n");


    printf("Bonne chance !\n");
    printf("\n");


    do {
        int nombre1 = rand() % 101; // Nombre aléatoire entre 0 et 100
        int nombre2 = rand() % 101;

        int permutation;//Permutation des éléements si le nombre 1 est plus petit que le nombre 2 (division simple pour les CM1)
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
            printf("\n");
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
                    printf("\n");
                }
            }
        }

        // Demande au joueur s'il veut continuer seulement si le jeu n'est pas déjà terminé
        if (nbEssais == 3 && ReponseUser != resultat) {
            printf("Nombre total de points : %d\n", pointUser);
            printf("\n");
            break; // Sorti de la boucle do...while si le joueur a perdu
        }

        do {
            printf("Souhaitez-vous continuer ? (o/n) : ");
            scanf(" %c", &continuer);
            printf("\n");
        } while (continuer != 'o' && continuer != 'O' && continuer != 'n' && continuer != 'N');

    } while (continuer == 'o' || continuer == 'O');

    printf("Fin du jeu | Total des points gagnés : %d\n", pointUser);

    return pointUser;

}

//---------------------------------------------------------------------------------//

int MiniProbleme(){

    printf("Bienvenue dans le jeu des mini problèmes !\n");
    printf("Vous avez 1 SEUL essai pour trouver la réponse d'un mini problème.\n");
    printf("Si vous trouver la réponse , un message vous indiquera le nombre de points gagnés.\n");
    printf("Si vous ne parvenez pas à trouver la réponse , la logique du problème s'affichera\n");
    printf("\n");

    printf("Bonne chance !\n");
    printf("\n");

    int resultat, ReponseUser,pointUser = 0;
    char continuer;

    srand(time(NULL));
    
    int nombreAlea = rand() % 5 + 1;
        
    if(nombreAlea == 1){
        printf("Wilfried avait 19 sacs de 40 bonbons . Il achète 18 bonbons .\n");
        resultat = 19*40 +18;
        printf("\n");
        printf("Combien a t'il de bonbons maintenant ?\n");
        printf("Entrez votre réponse : ");
        scanf("%d", &ReponseUser);
        printf("\n");

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

        printf("\n");
        printf("Combien a-t-il de timbres maintenant ?\n");
        printf("Entrez votre réponse : ");
        scanf("%d", &ReponseUser);
        printf("\n");

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

        printf("\n");
        printf("Combien a-t-il de petites voitures maintenant ?\n");
        printf("Entrez votre réponse : ");
        scanf("%d", &ReponseUser);
        printf("\n");

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
        printf("\n");
        printf("Combien a-t-il de balles rouges maintenant ?\n");
        printf("Entrez votre réponse : ");
        scanf("%d", &ReponseUser);
        printf("\n");

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
        printf("\n");
        printf("Combien a-t-il de cartes maintenant ?\n");
        printf("Entrez votre réponse : ");
        scanf("%d", &ReponseUser);
        printf("\n");


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
    printf("\n");
printf("Fin du jeu | Total des points gagnés : %d\n", pointUser);
return pointUser;
}

//---------------------------------------------------------------------------------//

int QuizGenerale() {


    printf("Bienvenue dans le Quiz generale !\n");
    printf("\n");

    printf("Vous avez 1 SEUL essai pour trouver le réponse à la question .\n");
    printf("Chaque bonne réponse , raportent 20 points.\n");
    printf("Votre total de points obtenus sera affiché à la fin.\n");
    printf("\n");
    

    printf("Si vous trouvez en 1 seul coup, vous aurez 10 points\n");
    printf("Si vous trouvez en 2 coups, vous aurez 5 points\n");
    printf("Si vous trouvez en 3 coups, vous aurez 1 point\n");
    printf("\n");

    printf("Bonne chance !\n");
    printf("\n");

    int score = 0;
    int reponse;
    char ReponseQuestion[30];

    printf("\n");

    // Question 1
    printf("Question 1: Qui a écrit 'Les Misérables' ?\n");
    printf("1. Victor Hugo\n2. Emile Zola\n3. Marcel Proust\n4. Honoré de Balzac\n");
    printf("Votre réponse (1-4): ");
    scanf("%d", &reponse);
    strcpy(ReponseQuestion ,"Victor Hugo");
    (reponse ==1) ? score+=20 , printf("Bonne réponse ! "): printf("La bonne réponse était : %s",ReponseQuestion);

    // Question 2
    printf("\n");
    printf("\nQuestion 2: Quelle est la capitale de l'Australie ?\n");
    printf("1. Sydney\n2. Melbourne\n3. Canberra\n4. Brisbane\n");
    printf("Votre réponse (1-4): ");
    scanf("%d", &reponse);
    strcpy(ReponseQuestion ,"Canberra");
    (reponse ==3) ? score+=20 , printf("Bonne réponse ! "): printf("La bonne réponse était : %s",ReponseQuestion);

    // Question 3
    printf("\n");
    printf("\nQuestion 3: Qui a peint la Joconde ?\n");
    printf("1. Michel-Ange\n2. Léonard de Vinci\n3. Raphael\n4. Claude Monet\n");
    printf("Votre réponse (1-4): ");
    scanf("%d", &reponse);
    strcpy(ReponseQuestion ,"Léonard de Vinci");
    (reponse ==2) ? score+=20 , printf("Bonne réponse ! "): printf("La bonne réponse était : %s",ReponseQuestion);

    // Question 4
    printf("\n");
    printf("\nQuestion 4: Quel est le plus grand océan du monde ?\n");
    printf("1. Atlantique\n2. Pacifique\n3. Indien\n4. Arctique\n");
    printf("Votre réponse (1-4): ");
    scanf("%d", &reponse);
    strcpy(ReponseQuestion ,"Pacifique");
    (reponse ==2) ? score+=20 , printf("Bonne réponse ! "): printf("La bonne réponse était : %s",ReponseQuestion);

    // Question 5
    printf("\n");
    printf("\nQuestion 5: Quelle est la durée d'une année sur Mars ?\n");
    printf("1. 365 jours\n2. 550 jours\n3. 720 jours\n4. 687 jours\n");
    printf("Votre réponse (1-4): ");
    scanf("%d", &reponse);
    strcpy(ReponseQuestion ,"687 jours");
    (reponse ==4) ? score+=20 , printf("Bonne réponse ! "): printf("La bonne réponse était : %s",ReponseQuestion);

    // Question 6
    printf("\n");
    printf("\nQuestion 6: Qui est le fondateur de la psychanalyse ?\n");
    printf("1. Carl Jung\n2. Sigmund Freud\n3. Alfred Adler\n4. William James\n");
    printf("Votre réponse (1-4): ");
    scanf("%d", &reponse);
    strcpy(ReponseQuestion ,"Sigmund Freud");
    (reponse ==2) ? score+=20 , printf("Bonne réponse ! "): printf("La bonne réponse était : %s",ReponseQuestion);

    // Question 7
    printf("\n");
    printf("\nQuestion 7: Quel est l'élément chimique dont le symbole est 'Au' ?\n");
    printf("1. Argent\n2. Or\n3. Aluminium\n4. Uranium\n");
    printf("Votre réponse (1-4): ");
    scanf("%d", &reponse);
    strcpy(ReponseQuestion ,"L'or");
    (reponse ==2) ? score+=20 , printf("Bonne réponse ! "): printf("La bonne réponse était : %s",ReponseQuestion);

    // Question 8
    printf("\n");
    printf("\nQuestion 8: Quel est le plus grand désert chaud du monde ?\n");
    printf("1. Sahara\n2. Désert de Gobi\n3. Kalahari\n4. Désert de Sonora\n");
    printf("Votre réponse (1-4): ");
    scanf("%d", &reponse);
    strcpy(ReponseQuestion ,"Sahara");
    (reponse ==1) ? score+=20 , printf("Bonne réponse ! "): printf("La bonne réponse était : %s",ReponseQuestion);

    // Question 9
    printf("\n");
    printf("\nQuestion 9: Qui a inventé l'ampoule électrique ?\n");
    printf("1. Nikola Tesla\n2. Thomas Edison\n3. Alexander Graham Bell\n4. Michael Faraday\n");
    printf("Votre réponse (1-4): ");
    scanf("%d", &reponse);
    strcpy(ReponseQuestion ,"Thomas Edison");
    (reponse ==2) ? score+=20 , printf("Bonne réponse ! "): printf("La bonne réponse était : %s",ReponseQuestion);

    // Question 10
    printf("\n");
    printf("\nQuestion 10: Quel est le plus long fleuve du monde ?\n");
    printf("1. Amazone\n2. Nil\n3. Yangzi\n4. Mississippi\n");
    printf("Votre réponse (1-4): ");
    scanf("%d", &reponse);
    strcpy(ReponseQuestion ,"Le Nil");
    (reponse ==2) ? score+=20 , printf("Bonne réponse ! "): printf("La bonne réponse était : %s",ReponseQuestion);
   
    // Afficher le score
    printf("\n");
    printf("\nNombre total de points gagnés: %d/200\n", score);

    return score;
}
    
//---------------------------------------------------------------------------------//

char* date_actu() {
    static char s_now[20]; // "JJ/MM/AAAA-HH:MM:SS" -> 19 caractères + '\0' ( le caractère fermant)
    time_t now = time(NULL); //Retourne l'heure actuelle avec la fonction time
    struct tm* tm_now = localtime(&now); //localtime(&now) convertit la valeur du temps now en seconde en une structure tm

    if (tm_now == NULL) {
        return NULL;
    }

    strftime(s_now, sizeof(s_now), "%d/%m/%Y-%H:%M:%S", tm_now); //On formate avec strftime dans le tableau s_now
    return s_now; //Sans static , le pointeur sur s_now sera invalide car varaible détruite a la fin de la fonctions ( un de mes problèmes rencontré)
    }
     
//---------------------------------------------------------------------------------//

void CreationJoueur(char* NomUser, char* PnomUser, char* date, int Nbpoint) {
    FILE* F = fopen("FichierPoints.txt", "a"); // Ouvre en mode ajout 
    if (F == NULL) {
        printf("Erreur lors de l'ouverture du fichier\n");
        return;
    }
    
    printf("Votre profil va etre ajouté ... \n");
    
    // Utilisation du délimiteur | entre les champs et ajout d'un retour à la ligne pour le joueur prochain
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
                if (strcmp(name, NomUser) == 0 && strcmp(prenom, PnomUser) == 0) { //Conparaison avec ceux de l'utilisateur choisis
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
        // Supprime le retour à la ligne s'il existe entre 2 joueurs
        ligne[strcspn(ligne, "\n")] = 0;
        
        char *name, *prenom, *date, *points, *copie;
        
        // Fait une copie car strtok modifie la chaîne originale
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
                        // On verifie si le nom et prenom du joueur correspond à celui cherché
                        if (strcmp(name, NomUser) == 0 && strcmp(prenom, PnomUser) == 0) {
                            *PointsUser = atoi(points);  //On convertit le nombre de points en entier car dans le fichier tout est en string 
                            joueurTrouve = true;
                            free(copie); //Liberation de la memoire
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
    FILE *F2 = fopen("FichierTemp.txt", "w"); //Création d'un fichier temporaire pour sauvegarder les nouveaux points
    if (F == NULL || F2 == NULL) {
        printf("Erreur lors de l'ouverture des fichiers\n");
        return;
    }

    char ligne[256];
    
    
    while (fgets(ligne, sizeof(ligne), F)) {
        
        ligne[strcspn(ligne, "\n")] = 0;  // Supprime le retour à la ligne s'il existe ( \n ) entre 2 joueurs si il existe
        
        char *name, *prenom, *date, *points_str; //Creation de pointeur sur les elements du fichier pour facilier la récupération
        int NbPoints;
        
        
        char *copie = strdup(ligne);// J'ai réaliser une copie de la ligne car strtok modifie la chaîne originale 
        if (copie == NULL) {
            fclose(F);
            fclose(F2);
            return;
        }
        
        //On Extrait les champs
        name = strtok(copie, "|");
        prenom = strtok(NULL, "|");
        date = strtok(NULL, "|");
        points_str = strtok(NULL, "|");
        
        if (name && prenom && date && points_str) {
            NbPoints = atoi(points_str); //On convertit le nombre de points en entier car dans le fichier tout est en string 
            
            if (strcmp(name, NomUser) == 0 && strcmp(prenom, PnomUser) == 0) {
                NbPoints += PointsUser;
                char date_nouvelle[30];
                strcpy(date_nouvelle, date_actu());
                
                // On ecrit  dans le fichier temporaire les nouvelles informations
                fprintf(F2, "%s|%s|%s|%d\n", name, prenom, date_nouvelle, NbPoints);
            } else {
                // On ecrit la ligne originale dans le fichier temporaire si le joueur n'est pas celui qu'on cherche
                fprintf(F2, "%s|%s|%s|%d\n", name, prenom, date, NbPoints);
            }
        }
        
        free(copie);
    }
    
    fclose(F); 
    fclose(F2);
    
    // Remplace l'ancien fichier par le fichier temporaire
    remove("FichierPoints.txt"); // Supprime l'ancien fichier
    rename("FichierTemp.txt", "FichierPoints.txt"); // Renomme le fichier temporaire et remplace l'ancien
    
    printf("Vos points ont été mis à jour avec succès !\n");
}
    
//---------------------------------------------------------------------------------//


int main(int argc, char *argv[]) {
    
    srand(time(NULL)); // Initialisation  du générateur de nombres aléatoires

    char NameUser[20];
    char RecupPoint;
    char SurnameUser[20];
    char reponse[5];
    int choix = -1; // Initialisation du choxi de départ pour pouvoir rentrer dans la boucle

    printf("Boom ! Bienvenue dans le jeu de calcul mental !\n");

    printf("Saisissez votre nom : ");
    scanf("%s", NameUser);
    printf("Saisissez votre prénom : ");
    scanf("%s",SurnameUser);

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

    printf("Souhaitez vous récuperer vos points (O/N) ? :");
    scanf(" %c", &RecupPoint); 

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
