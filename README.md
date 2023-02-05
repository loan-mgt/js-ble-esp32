# [js-ble-esp32](https://qypol342.github.io/js-ble-esp32/index2.html)

js-ble-esp32

<img sr="src/illustration.png">

## Objectif
L’objectif de ce projet est d’avoir le code minimum pour communiquer avec esp32 avec du Bluetooth BLE depuis son navigateur. Parce que le projet se repose sur le navigateur cela fonctionne aussi sur mobile.

## Attention
L’api Bluetooth n’est pas encore supporté par  beaucoup de navigateurs. Pour l’instant seuls les navigateurs avec le moteur Chromium sont compatibles.

<img src="ble_support.PNG">

## Prérequis
Vous avez besoin d’un Esp32 évidemment, de l’IDE Arduino pour téléverser le code et finalement d’un serveur web (dans mon cas j’ai utiliser npm avec la commande `npx serve`)

## Installation
Cloner le projet sur votre machine </br>
Téléverser le `.ino` sur votre Esp32 </br>
Assurez vous que le chemin du serveur web correspond bien à la racine de ce projet
Lancer votre serveur web ( exemple `npx serve` )

## Bluetooth BLE structure
Le protocole fonctionne avec des services et des caractéristiques. Cette structure est très similaire à celle d’une bibliothèque, les services sont des étagères, on y range donc les livres des mêmes auteurs et du même genre. Les caractéristiques sont comme des livres on les ranges dans les mêmes services si il propose le même type de donnée ou que les données ont le même objectif.

Voici la structure créée dans ce projet:

<img src="schema.png">

Dans cette exemple `characteristicRandNb` est un seul octet, alors que `characteristicLed` est un table de 2 octets.

## Utilisation
Un fois la page web chargée et l'Esp 32 alimenté, cliquez sur `connect`, si votre navigateur est compatible un petit page va soucrir où vous allez pouvoir choisir l'appareil.
Une fois l'appareil choisi et la connexion réussit les autres boutons sont activés. Avec le bouton `Read` vous pouvez lire `characteristicLed` qui est un tableau de 2 octets. Avec le bouton `Write` vous pouvez écrire sur `characteristicLed`. Le code envoyé lorsque vous cliquez sur `Write` change entre ces deux tableaux: Une fois [42, 35] un fois [42,2]. </br>
Dans le code de l’arduino si le deuxième élément du tableau est un 2 alors la LED s’allume. Pour confirmer cet événement, il change la première valeur du tableau, il la met à 23. L'Esp 32 va a chaque révolution modifier la valeur de `characteristicRandNb` avec un nombre aléatoire compris entre 0 et 11. </br>
Avec le bouton `Notify` sur la page web vous pouvez vous abonner au changement de valeur. A chaque changement, la nouvelle valeur sera affichée dans la console.</br>
Finalement le bouton `Disconnect` qui parle de lui-même permet de déconnecter l'appareil. Dans cette configuration l'Esp 32 peut être connecté à un seul appareil à la fois.

<img src="demo.PNG">

## Documentation

Librairie arduino BLE

Google BLE Guide














## Info
There are a few ways to send a date-time value using only 20 bytes of data over Bluetooth Low Energy (BLE). Here are a few examples:

    Sending the date-time value as a Unix timestamp: A Unix timestamp is a number that represents the number of seconds since January 1, 1970. Since a timestamp is a numeric value, it can be easily represented using a 32-bit integer, which would take up 4 bytes of data.

    Sending the date-time value as a string: You can send the date-time value as a string in a specific format, such as "YYYY-MM-DD HH:MM:SS" which would take up 19 bytes of data.

    Sending the date-time value as a packed binary data: You can use some libraries to pack the date-time value into a 20 bytes of binary data, for example a library like https://github.com/JChristensen/Time can pack the date time in a 12 bytes of binary data.

It's important to note that the above examples are just a few possibilities and the best option will depend on the specific requirements and constraints of your application.

## Data needed

- datetime
- door status 1 byte
- winter time 1 byte
- light sensor value (more than 4 (254))


## guide Fr
- dans cette demo on aura un seul service avec 2 char
- un qui premt de génré la led de esp32 avec qui peut recevoi 2 octec
- un qui sera en lecture seul mais pour le quel on mettre un lsitenser qui observe si la valeur change commé d'un seul octer
- crée le fichier html
- ajouter la structure de base d'un fichier html
- ajouter 5 button
- pour se co pour lire pour ecrit pour etre notifier et se deco
- definir les bouton dans le js
- definir les uuid des service
- ajouter de vaiable
- ajouter les liseneter quand onc lcike sur les boutotn
- desactiver les bouton tant qu'uaun apparail est connecter
- fonction se connecter
- verfiifer si le navigateur est compatible
- fonction pour la demande d'appapreil
- fonction connecter se conncter
- demande le service
- aperis du service demander la charcherteroistique que l'on soug=haite
- activer les bouton
- fonction read pour la char led
- fonction écritre pour le char led
- fonction notify echoute chengemenat
- deconneciton

- code arduino

