# Jeu de Révision Mathématiques – Niveau CM1 (Difficile)

------------------------------------------------------------------------------------------------

## Présentation du projet

Le projet consiste à développer un programme éducatif interactif destiné aux élèves de niveau CM1, ayant pour objectif de les accompagner dans la révision des notions fondamentales en mathématiques.  
L'application prend la forme d'une série de mini-jeux, chacun ciblant une compétence précise du programme scolaire. Le niveau de difficulté a été conçu pour être légèrement supérieur à la moyenne afin de proposer un véritable défi intellectuel adapté aux élèves les plus avancés ou en recherche de consolidation.  
Le contenu des exercices s’inspire des ressources disponibles sur le site (http://championmath.free.fr), tout en apportant une touche ludique et dynamique.

Chaque mini-jeu proposé dans le programme visera à renforcer des notions telles que les opérations de base (additions, soustractions, multiplications, etc). Le programme intégrera une interface claire et intuitive permettant à l'utilisateur de naviguer facilement entre les différentes sections.  
Un menu principal offrira un accès rapide aux jeux, à leurs règles et aux scores. Chaque activité sera accompagnée d'un système de points afin d'encourager la progression des joueurs.

-------------------------------------------------------------------------------------------------

## Prérequis et outils utilisés

- **Langage** : C

- **Éditeur** : (https://code.visualstudio.com) (ou tout éditeur de code de votre choix)

- **Compilateur** :
  - **GCC** pour Windows
  - **Clang** pour macOS

- **Terminal** :
  - **Windows** : `cmd`
  - **Mac** : Terminal (via Launchpad)

-------------------------------------------------------------------------------------------------

## Installation du compilateur C

### Windows – Installer GCC avec MinGW

1. Télécharger MinGW depuis :  
   (https://sourceforge.net/projects/mingw/)

2. Pendant l’installation, cocher :
   - `mingw32-gcc-g++`
   - `mingw32-gcc`

3. Une fois l’installation terminée :
   - Aller dans **Panneau de configuration > Système > Paramètres système avancés**
   - Cliquer sur **Variables d’environnement**
   - Ajouter à la variable `Path` :  
     `C:\MinGW\bin`

4. Vérifier l'installation dans le terminal (`cmd`) :
   `gcc --version`


### MacOs – Installer Clang

1. Ouver votre terminal

2. Taper la commande suivant : 
    `xcode-select --install`

3. Accepter l’installation des outils de développement

4. Verifier l'installation 
    `clang --version`

-------------------------------------------------------------------------------------------------

### Instructions d'installation et d'utilisation

1. Télécharger ou cloner le projet 

Place le fichier main.c dans un dossier de votre choix sur votre ordinateur.

2. Ouvrir le terminal

    - Windows : appuyer sur Windows + R, taper cmd puis appuyer sur Entrée
    - Mac : ouvrir Launchpad, taper "Terminal", puis l'ouvrir

3. Se déplacer dans le dossier contenant le fichier

    Dans le terminal, utiliser la commande cd pour naviguer vers le dossier contenant le fichier main.c :

    `cd chemin/vers/le/dossier`
    Remplacer chemin/vers/le/dossier par le chemin réel de votre fichier.

4. Compiler le programme

    - Sur Windows :
        `gcc main.c -o prog`
        
    - Sur Mac/Linux :
        `clang main.c -o prog`    

    Cela créera un exécutable nommé prog.

5. Lancer le programme

    Une fois l’exécutable généré, vous pouvez lancer le jeu en exécutant la commande suivante dans le terminal :
    `./prog`# ProjetC
