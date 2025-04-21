//Commande pour compiler ce programme : gcc mainGTK.c -o programme `pkg-config --cflags --libs gtk+-3.0`

#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

GtkWidget *labelDateHeure;  // Pour afficher la date et l'heure
guint timer_id; 

// Structure pour stocker les informations du joueur
typedef struct {
    char nom[40];
    char prenom[40];
    int points;
    GtkWidget *window;
    GtkWidget *mainBox;
    GtkWidget *loginBox;
    GtkWidget *labelPoints;
    GtkWidget *labelDateHeure;  // Nouveau label pour la date/heure
    GtkWidget *entryNom;
    GtkWidget *entryPrenom;
} UserData;

// Prototypes des fonctions
char* date_actu();
bool VerificationJoueurExiste(char* NomUser, char* PnomUser);
void CreationJoueur(char* NomUser, char* PnomUser, char* date, int Nbpoint);
bool chercherJoueur(char* NomUser, char* PnomUser, int *PointsUser);
void MiseAjourPoints(char* NomUser, char* PnomUser, int PointsUser);
void afficher_menu_jeu(UserData *userData);
void demarrer_jeu_console(int jeuChoisi, UserData *userData);
void relancer_interface_gtk(UserData *userData);

// Fonction pour obtenir la date et l'heure actuelles
char* date_actu() {
    static char s_now[20]; // "JJ/MM/AAAA-HH:MM:SS" = 19 caractères + '\0'
    time_t now = time(NULL);
    struct tm* tm_now = localtime(&now);
    
    if (tm_now == NULL) {
        return NULL;
    }
    
    strftime(s_now, sizeof(s_now), "%d/%m/%Y-%H:%M:%S", tm_now);
    return s_now; // Sans static, le pointeur sur s_now sera invalide car variable détruite
}

static gboolean update_date_time(gpointer user_data) {
    UserData *userData = (UserData *)user_data;
    char *current_datetime = date_actu();
    
    if (current_datetime != NULL && userData->labelDateHeure != NULL) {
        char buffer[100];
        snprintf(buffer, sizeof(buffer), "Date et heure: %s", current_datetime);
        gtk_label_set_text(GTK_LABEL(userData->labelDateHeure), buffer);
    }
    
    // Retourner TRUE pour que le timer continue
    return TRUE;
}

// Fonction qui verifie si le joueur existe déjà
bool VerificationJoueurExiste(char* NomUser, char* PnomUser) {
    FILE *F = fopen("FichierPoints.txt", "r");
    if (F == NULL) {
        printf("Erreur lors de l'ouverture du fichier\n");
        return false;
    }

    char ligne[256];
    bool joueurExiste = false;
    
    while (fgets(ligne, sizeof(ligne), F)) {
        char *name, *prenom, *copie;
        
        // On fait une copie de la ligne car strtok modifie la chaîne
        copie = strdup(ligne);
        if (copie == NULL) {
            printf("Erreur d'allocation mémoire\n");
            fclose(F);
            return false;
        }
        
        // Extraction du nom (premier champ)
        name = strtok(copie, "|");
        if (name != NULL) {
            // Extraction du prénom (deuxième champ)
            prenom = strtok(NULL, "|");
            
            if (prenom != NULL) {
                // Comparaison avec les informations recherchées
                if (strcmp(name, NomUser) == 0 && strcmp(prenom, PnomUser) == 0) {
                    printf("Votre profil est deja enregistré dans le jeu ! \n");
                    joueurExiste = true;
                    free(copie);
                    break;
                }
            }
        }
        
        free(copie);
    }
    
    fclose(F);
    return joueurExiste;
}

// Fonction qui crée le profil du joueur
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

// Fonction qui cherche le joueur pour récupérer ses informations
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

// Fonction pour mettre à jour les points du joueur
void MiseAjourPoints(char *NomUser, char *PnomUser, int PointsUser) {
    FILE *F = fopen("FichierPoints.txt", "r");
    FILE *F2 = fopen("FichierTemp.txt", "w");
    if (F == NULL || F2 == NULL) {
        printf("Erreur lors de l'ouverture des fichiers\n");
        return;
    }

    char ligne[256];
    
    // Lire chaque ligne du fichier d'origine
    while (fgets(ligne, sizeof(ligne), F)) {
        // Supprimer le retour à la ligne s'il existe
        ligne[strcspn(ligne, "\n")] = 0;
        
        char *name, *prenom, *date, *points_str;
        int NbPoints;
        
        // Faire une copie de la ligne pour strtok
        char *copie = strdup(ligne);
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
            NbPoints = atoi(points_str);
            
            // Vérifier si c'est le joueur à mettre à jour
            if (strcmp(name, NomUser) == 0 && strcmp(prenom, PnomUser) == 0) {
                // Mettre à jour les points
                NbPoints += PointsUser;
                // Mettre à jour la date
                char date_nouvelle[30];
                strcpy(date_nouvelle, date_actu()); // Suppose que date_actu() existe
                
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

// Fonction appelée lorsque le bouton de connexion est cliqué
static void on_connexion_clicked(GtkButton *button, UserData *userData) {
    const gchar *nom = gtk_entry_get_text(GTK_ENTRY(userData->entryNom));
    const gchar *prenom = gtk_entry_get_text(GTK_ENTRY(userData->entryPrenom));
    int points = 0;
    
    if (strlen(nom) == 0 || strlen(prenom) == 0) {
        GtkWidget *dialog = gtk_message_dialog_new(GTK_WINDOW(userData->window),
                                                  GTK_DIALOG_DESTROY_WITH_PARENT,
                                                  GTK_MESSAGE_ERROR,
                                                  GTK_BUTTONS_CLOSE,
                                                  "Veuillez remplir tous les champs");
        gtk_dialog_run(GTK_DIALOG(dialog));
        gtk_widget_destroy(dialog);
        return;
    }
    
    // Copier les données du joueur dans la structure
    strncpy(userData->nom, nom, sizeof(userData->nom) - 1);
    strncpy(userData->prenom, prenom, sizeof(userData->prenom) - 1);
    
    // Vérifier si le joueur existe déjà
    if (!VerificationJoueurExiste(userData->nom, userData->prenom)) {
        CreationJoueur(userData->nom, userData->prenom, date_actu(), 0);
        userData->points = 0;
        
        GtkWidget *dialog = gtk_message_dialog_new(GTK_WINDOW(userData->window),
                                                GTK_DIALOG_DESTROY_WITH_PARENT,
                                                GTK_MESSAGE_INFO,
                                                GTK_BUTTONS_OK,
                                                "Bienvenue %s %s!\nVotre profil a été créé.",
                                                prenom, nom);
        gtk_dialog_run(GTK_DIALOG(dialog));
        gtk_widget_destroy(dialog);
    } else {
        // Récupérer les points du joueur
        if (chercherJoueur(userData->nom, userData->prenom, &points)) {
            userData->points = points;
            
            GtkWidget *dialog = gtk_message_dialog_new(GTK_WINDOW(userData->window),
                                                    GTK_DIALOG_DESTROY_WITH_PARENT,
                                                    GTK_MESSAGE_INFO,
                                                    GTK_BUTTONS_OK,
                                                    "Bienvenue %s %s!\nVous avez %d points.",
                                                    prenom, nom, points);
            gtk_dialog_run(GTK_DIALOG(dialog));
            gtk_widget_destroy(dialog);
        }
    }
    
    // Cacher l'écran de connexion et afficher le menu du jeu
    gtk_widget_hide(userData->loginBox);
    afficher_menu_jeu(userData);

    
}

// Fonction pour démarrer le jeu en console
void demarrer_jeu_console(int jeuChoisi, UserData *userData) {
    // Fermer la fenêtre GTK pour passer à la console
    
    
    // Variables pour le jeu en console
    int scoreActuel = 0;
    int nombre1, nombre2, resultat;
    char reponseStr[100];
    int reponseUser;
    int essais;
    int nombreEssaisMax = 3;
    const char *nomJeu;
    
    // Déterminer le nom du jeu
    switch (jeuChoisi) {
        case 1: 
            nomJeu = "Addition"; 
            break;
        case 2: 
            nomJeu = "Soustraction"; 
            break;
        case 3: 
            nomJeu = "Multiplication"; 
            break;
        case 4: 
            nomJeu = "Tables de multiplication"; 
            break;
        case 5: 
            nomJeu = "Division"; 
            break;
        case 6: 
            nomJeu = "Mini Problèmes"; 
            break;
        default: 
            nomJeu = "Inconnu"; 
            break;
    }
    
    printf("\n\n==== Jeu Mathématique: %s ====\n", nomJeu);
    printf("Joueur: %s %s\n", userData->prenom, userData->nom);
    printf("Points actuels: %d\n\n", userData->points);
    
    printf("Règles du jeu:\n");
    printf("• Trouvez la réponse en 1 essai = 10 points\n");
    printf("• Trouvez la réponse en 2 essais = 5 points\n");
    printf("• Trouvez la réponse en 3 essais = 1 point\n\n");
    
    // Boucle principale du jeu
    char continuer = 'o';
    while (continuer == 'o' || continuer == 'O') {
        // Générer une question selon le jeu choisi
        essais = 0;
        
        switch (jeuChoisi) {
            case 1: // Addition
                nombre1 = rand() % 100 + 1;
                nombre2 = rand() % 100 + 1;
                resultat = nombre1 + nombre2;
                printf("Question: %d + %d = ?\n", nombre1, nombre2);
                break;
                
            case 2: // Soustraction
                nombre1 = rand() % 101;
                nombre2 = rand() % 101;
                
                // S'assurer que le premier nombre est plus grand
                if (nombre1 < nombre2) {
                    int temp = nombre2;
                    nombre2 = nombre1;
                    nombre1 = temp;
                }
                
                resultat = nombre1 - nombre2;
                printf("Question: %d - %d = ?\n", nombre1, nombre2);
                break;
                
            case 3: // Multiplication
                nombre1 = rand() % 10 + 1;
                nombre2 = rand() % 10 + 1;
                resultat = nombre1 * nombre2;
                printf("Question: %d × %d = ?\n", nombre1, nombre2);
                break;
                
            case 4: // Tables de multiplication
                nombre1 = rand() % 10 + 1; // Choisir une table au hasard
                printf("Vous allez parcourir la table de multiplication de %d.\n", nombre1);
                for (int i = 1; i <= 10; i++) {
                    resultat = nombre1 * i;
                    printf("Question (Table de %d): %d × %d = ?\n", nombre1, nombre1, i);
                    
                    // Boucle pour les essais
                    essais = 0;
                    while (essais < nombreEssaisMax) {
                        essais++;
                        printf("Votre réponse (essai %d/%d): ", essais, nombreEssaisMax);
                        fgets(reponseStr, sizeof(reponseStr), stdin);
                        reponseUser = atoi(reponseStr);
                        
                        if (reponseUser == resultat) {
                            // Réponse correcte
                            int points = 0;
                            
                            if (essais == 1) {
                                points = 10;
                                printf("\nBravo ! Vous avez gagné 10 points !\n");
                            } else if (essais == 2) {
                                points = 5;
                                printf("\nBien joué ! Vous avez gagné 5 points.\n");
                            } else {
                                points = 1;
                                printf("\nCorrect. Vous gagnez 1 point.\n");
                            }
                            
                            scoreActuel += points;
                            printf("Score actuel: %d\n\n", scoreActuel);
                            break;
                        } else {
                            // Réponse incorrecte
                            if (essais < nombreEssaisMax) {
                                printf("Incorrect. Essayez encore...\n");
                            } else {
                                printf("\nDommage, la bonne réponse était : %d\n\n", resultat);
                                printf("Vous avez atteint le nombre maximum d'essais pour cette question.\n");
                                
                                // Mettre à jour les points avant de quitter
                                
                                
                                printf("Souhaitez-vous quitter ? (o/n): ");
                                fgets(reponseStr, sizeof(reponseStr), stdin);
                                if (reponseStr[0] == 'o' || reponseStr[0] == 'O') {
                                    MiseAjourPoints(userData->nom, userData->prenom, scoreActuel);
                                    printf("Vous avez choisi de quitter. Merci d'avoir joué !\n");
                                    return;
                                }
                            }
                        }
                    }
                }
                break;
                
            case 5: // Division (modulo)
                nombre1 = rand() % 101;
                nombre2 = rand() % 101;
                
                // S'assurer que le premier nombre est plus grand et le second nombre n'est pas zéro
                if (nombre1 < nombre2) {
                    int temp = nombre2;
                    nombre2 = nombre1;
                    nombre1 = temp;
                }
                if (nombre2 == 0) {
                    nombre2 = 1;
                }
                
                resultat = nombre1 % nombre2;
                printf("Question: %d modulo %d = ?\n", nombre1, nombre2);
                break;
                
            case 6: // Mini problèmes
                nombre1 = rand() % 10 + 5;
                nombre2 = rand() % 10 + 5;
                resultat = nombre1 * nombre2 + 5;
                printf("Question: Un enfant a %d sacs contenant chacun %d bonbons.\n", nombre1, nombre2);
                printf("Il reçoit ensuite 5 bonbons supplémentaires.\n");
                printf("Combien a-t-il de bonbons en tout?\n");
                break;
        }
        
        // Boucle des essais
        while (essais < nombreEssaisMax) {
            essais++;
            printf("Votre réponse (essai %d/%d): ", essais, nombreEssaisMax);
            fgets(reponseStr, sizeof(reponseStr), stdin);
            reponseUser = atoi(reponseStr);
            
            if (reponseUser == resultat) {
                // Réponse correcte
                int points = 0;
                
                if (essais == 1) {
                    points = 10;
                    printf("\nBravo ! Vous avez gagné 10 points !\n");
                } else if (essais == 2) {
                    points = 5;
                    printf("\nBien joué ! Vous avez gagné 5 points.\n");
                } else {
                    points = 1;
                    printf("\nCorrect. Vous gagnez 1 point.\n");
                }
                
                scoreActuel += points;
                printf("Score actuel: %d\n\n", scoreActuel);
                break;
            } else {
                // Réponse incorrecte
                if (essais < nombreEssaisMax) {
                    printf("Incorrect. Essayez encore...\n");
                } else {
                    printf("\nDommage, la bonne réponse était : %d\n\n", resultat);
                }
            }
        }
        
        printf("Voulez-vous continuer? (o/n): ");
        fgets(reponseStr, sizeof(reponseStr), stdin);
        continuer = reponseStr[0];
    }
    
    // Mettre à jour les points dans le fichier
    MiseAjourPoints(userData->nom, userData->prenom, scoreActuel);
    printf("\nJeu terminé! Vous avez gagné %d points.\n", scoreActuel);
    printf("Votre score total est maintenant de %d points.\n", userData->points + scoreActuel);
    printf("\nÀ bientôt!\n");

    // Mettre à jour les points dans la structure userData
    userData->points += scoreActuel;
    
    printf("\nRetour au menu principal...\n");
    
    // Recréer la fenêtre principale et relancer l'interface GTK
    relancer_interface_gtk(userData);
}

void relancer_interface_gtk(UserData *userData) {
    // Créer une nouvelle fenêtre
    userData->window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(userData->window), "Jeu Mathématique");
    gtk_window_set_default_size(GTK_WINDOW(userData->window), 500, 400);
    gtk_container_set_border_width(GTK_CONTAINER(userData->window), 10);
    g_signal_connect(userData->window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    
    // Réinitialiser les champs de la boîte principale
    userData->mainBox = NULL;

    userData->labelDateHeure = NULL;
    
    // Afficher le menu du jeu
    afficher_menu_jeu(userData);
    
    // Afficher la fenêtre et tous ses widgets
    gtk_widget_show_all(userData->window);
    
    // Démarrer une nouvelle boucle GTK
    gtk_main();
}


static void cleanup_resources(GtkWidget *widget, gpointer data) {
    if (timer_id > 0) {
        g_source_remove(timer_id);
        timer_id = 0;
    }
    gtk_main_quit();
}
// Fonction appelée quand un mode de jeu est sélectionné
// Fonction appelée quand un mode de jeu est sélectionné
// Structure pour passer des données à la fonction d'inactivité
typedef struct {
    UserData *userData;
    int jeuChoisi;
} GameLaunchData;

// Fonction qui sera appelée après que GTK a traité tous les événements en attente
static gboolean launch_game_when_idle(gpointer data) {
    GameLaunchData *launchData = (GameLaunchData *)data;
    
    // Fermer la fenêtre principale
    gtk_widget_destroy(launchData->userData->window);
    
    // Lancer le jeu console
    demarrer_jeu_console(launchData->jeuChoisi, launchData->userData);
    
    // Libérer la mémoire allouée
    g_free(launchData);
    
    // Retourner FALSE pour que cette fonction ne soit pas rappelée
    return FALSE;
}

// Fonction appelée quand un mode de jeu est sélectionné
static void on_mode_selected(GtkButton *button, UserData *userData) {
    const gchar *jeu = gtk_button_get_label(GTK_BUTTON(button));
    int jeuChoisi = 0;
    
    // Déterminer quel jeu a été sélectionné
    if (strcmp(jeu, "Addition") == 0) {
        jeuChoisi = 1;
    } else if (strcmp(jeu, "Soustraction") == 0) {
        jeuChoisi = 2;
    } else if (strcmp(jeu, "Multiplication") == 0) {
        jeuChoisi = 3;
    } else if (strcmp(jeu, "Tables de multiplication") == 0) {
        jeuChoisi = 4;
    } else if (strcmp(jeu, "Division") == 0) {
        jeuChoisi = 5;
    } else if (strcmp(jeu, "Mini Problèmes") == 0) {
        jeuChoisi = 6;
    } else if (strcmp(jeu, "QuizGenerale") == 0) {
        jeuChoisi = 7;
        
    }
    else {
        return; // Jeu non reconnu
    }
    
    // Afficher un message de confirmation
    GtkWidget *dialog = gtk_message_dialog_new(GTK_WINDOW(userData->window),
                                             GTK_DIALOG_DESTROY_WITH_PARENT,
                                             GTK_MESSAGE_INFO,
                                             GTK_BUTTONS_OK,
                                             "Vous avez choisi le mode: %s\nLe jeu va continuer dans la console.",
                                             jeu);
  
    gtk_dialog_run(GTK_DIALOG(dialog));
    
   
    gtk_widget_destroy(dialog);
    
    // Prépare les données pour le lancement du jeu
    gtk_widget_hide(userData->window);

    gtk_main_quit();
    
    demarrer_jeu_console(jeuChoisi, userData);
}


// Fonction pour afficher le menu du jeu
void afficher_menu_jeu(UserData *userData) {
    // Retirer d'abord tout widget existant de la fenêtre
    GtkWidget *current_child = gtk_bin_get_child(GTK_BIN(userData->window));
    if (current_child != NULL) {
        gtk_container_remove(GTK_CONTAINER(userData->window), current_child);
    }
    
    // Si le menu principal n'existe pas encore, le créer
    if (userData->mainBox == NULL) {
        userData->mainBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
        gtk_container_set_border_width(GTK_CONTAINER(userData->mainBox), 20);
        
        // Ajouter un titre
        GtkWidget *labelTitre = gtk_label_new("QuizzyMath");
        PangoAttrList *attrs = pango_attr_list_new();
        pango_attr_list_insert(attrs, pango_attr_weight_new(PANGO_WEIGHT_BOLD));
        pango_attr_list_insert(attrs, pango_attr_scale_new(2.0));
        gtk_label_set_attributes(GTK_LABEL(labelTitre), attrs);
        pango_attr_list_unref(attrs);
        gtk_box_pack_start(GTK_BOX(userData->mainBox), labelTitre, FALSE, FALSE, 10);
        
        // Ajouter un label pour afficher les informations du joueur
        GtkWidget *labelJoueur = gtk_label_new("");
        gchar *joueur_text = g_strdup_printf("Joueur: %s %s",userData->nom, userData->prenom);
        gtk_label_set_text(GTK_LABEL(labelJoueur), joueur_text);
        g_free(joueur_text);
        gtk_box_pack_start(GTK_BOX(userData->mainBox), labelJoueur, FALSE, FALSE, 5);
        
        // Ajouter un label pour afficher les points
        userData->labelPoints = gtk_label_new("");
        gchar *points_text = g_strdup_printf("Points totaux: %d", userData->points);
        gtk_label_set_text(GTK_LABEL(userData->labelPoints), points_text);
        g_free(points_text);
        gtk_box_pack_start(GTK_BOX(userData->mainBox), userData->labelPoints, FALSE, FALSE, 5);
        
        // Ajouter un label explicatif
        GtkWidget *labelExplication = gtk_label_new("Choisissez un mode de jeu.\nLe jeu continuera ensuite dans la console.");
        gtk_box_pack_start(GTK_BOX(userData->mainBox), labelExplication, FALSE, FALSE, 15);

      
        
        // Ajouter un séparateur
        GtkWidget *separator = gtk_separator_new(GTK_ORIENTATION_HORIZONTAL);
        gtk_box_pack_start(GTK_BOX(userData->mainBox), separator, FALSE, FALSE, 10);
        
        // Ajouter les boutons pour chaque jeu
        const gchar *jeux[] = {
            "Addition", "Soustraction", "Multiplication",
            "Tables de multiplication", "Division", "Mini Problèmes"
        };
        
        for (int i = 0; i < 6; i++) {
            GtkWidget *button = gtk_button_new_with_label(jeux[i]);
            g_signal_connect(button, "clicked", G_CALLBACK(on_mode_selected), userData);
            gtk_box_pack_start(GTK_BOX(userData->mainBox), button, FALSE, FALSE, 5);
        }
        
        // Ajouter un bouton pour quitter
        GtkWidget *buttonQuitter = gtk_button_new_with_label("Quitter");
        g_signal_connect(buttonQuitter, "clicked", G_CALLBACK(gtk_main_quit), NULL);
        gtk_box_pack_start(GTK_BOX(userData->mainBox), buttonQuitter, FALSE, FALSE, 10);
    }
    
    gchar *points_text = g_strdup_printf("Points totaux: %d", userData->points);
    gtk_label_set_text(GTK_LABEL(userData->labelPoints), points_text);
    g_free(points_text);

    if (userData->labelDateHeure == NULL) {
        userData->labelDateHeure = gtk_label_new("");
        char buffer[100];
        char *current_datetime = date_actu();
        snprintf(buffer, sizeof(buffer), "Date et heure: %s", current_datetime);
        gtk_label_set_text(GTK_LABEL(userData->labelDateHeure), buffer);
        gtk_box_pack_start(GTK_BOX(userData->mainBox), userData->labelDateHeure, FALSE, FALSE, 5);
        
        // Démarrer le timer pour mettre à jour toutes les secondes (1000 ms)
        timer_id = g_timeout_add(1000, update_date_time, userData);
    }

    // Ajouter le menu au conteneur principal
    gtk_container_add(GTK_CONTAINER(userData->window), userData->mainBox);
    
    // Afficher tous les widgets
    gtk_widget_show_all(userData->mainBox);

}

// Fonction principale
int main(int argc, char *argv[]) {
    // Initialiser GTK
    gtk_init(&argc, &argv);
    
    // Initialiser le générateur de nombres aléatoires
    srand(time(NULL));
    
    // Créer la structure de données utilisateur
    UserData *userData = g_new0(UserData, 1);
    userData->points = 0;
    userData->mainBox = NULL;
    userData->labelDateHeure = NULL;
    
    // Créer la fenêtre principale
    userData->window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(userData->window), "QuizzyMath");
    gtk_window_set_default_size(GTK_WINDOW(userData->window), 500, 400);
    gtk_container_set_border_width(GTK_CONTAINER(userData->window), 10);
    g_signal_connect(userData->window, "destroy", G_CALLBACK(cleanup_resources), NULL);
    
    // Créer l'interface de connexion
    userData->loginBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_container_set_border_width(GTK_CONTAINER(userData->loginBox), 20);
    
    // Ajouter un titre
    GtkWidget *labelTitre = gtk_label_new("QuizzyMath - Connexion");
    PangoAttrList *attrs = pango_attr_list_new();
    pango_attr_list_insert(attrs, pango_attr_weight_new(PANGO_WEIGHT_BOLD));
    pango_attr_list_insert(attrs, pango_attr_scale_new(1.5));
    gtk_label_set_attributes(GTK_LABEL(labelTitre), attrs);
    pango_attr_list_unref(attrs);
    gtk_box_pack_start(GTK_BOX(userData->loginBox), labelTitre, FALSE, FALSE, 10);
    
    // Ajouter les champs pour le nom et prénom
    GtkWidget *nomBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    GtkWidget *labelNom = gtk_label_new("Nom:");
    gtk_widget_set_size_request(labelNom, 100, -1);
    gtk_box_pack_start(GTK_BOX(nomBox), labelNom, FALSE, FALSE, 0);
    userData->entryNom = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(nomBox), userData->entryNom, TRUE, TRUE, 0);
    
    GtkWidget *prenomBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    GtkWidget *labelPrenom = gtk_label_new("Prénom:");
    gtk_widget_set_size_request(labelPrenom, 100, -1);
    gtk_box_pack_start(GTK_BOX(prenomBox), labelPrenom, FALSE, FALSE, 0);
    userData->entryPrenom = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(prenomBox), userData->entryPrenom, TRUE, TRUE, 0);
    
    gtk_box_pack_start(GTK_BOX(userData->loginBox), nomBox, FALSE, FALSE, 5);
    gtk_box_pack_start(GTK_BOX(userData->loginBox), prenomBox, FALSE, FALSE, 5);
    
    // Ajouter un bouton de connexion
    GtkWidget *buttonConnexion = gtk_button_new_with_label("Login/Sign up");
    g_signal_connect(buttonConnexion, "clicked", G_CALLBACK(on_connexion_clicked), userData);
    gtk_box_pack_start(GTK_BOX(userData->loginBox), buttonConnexion, FALSE, FALSE, 20);
    
    // Ajouter l'écran de connexion à la fenêtre principale
    gtk_container_add(GTK_CONTAINER(userData->window), userData->loginBox);
    
    // Afficher la fenêtre et tous ses widgets
    gtk_widget_show_all(userData->window);

    
    
    // Démarrer la boucle principale GTK
    gtk_main();
    
    // Libérer la mémoire
    g_free(userData);
    
    return 0;
}