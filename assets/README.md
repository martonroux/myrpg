## IMPORTANT: formatage images

Afin d'assurer le bon fonctionnement des fonctions d'animation de personnages, merci de respecter ce formatage:  

Chaque image doit au moins avoir 4 lignes de sprites:
- 1ere ligne: personnage avance vers le **haut**
- 2eme ligne: personnage avance vers la **gauche**
- 3eme ligne: personnage avance vers le **bas**
- 4eme ligne: personnage avance vers la **droite**

**La première image** de chaque ligne doit être la position **IDLE** du personnage (quand il ne bouge pas). A partir de la deuxième image, l'animation de déplacement commence. Le minimum d'image par ligne est donc de **2**, autrement le personnage ne sera pas affiché lorsqu'il est en mouvement.

Prenez exemple sur les images déjà présentes dans le dossier pour référence.  
Au delà de la 4ème ligne, les sprites seront utilisés pour les autres animations diverses, du style:  
- Attaques
- Mouvements spécifiques à un personnage
- Etc
