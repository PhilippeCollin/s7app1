// Classe du serveur TLS.
#include "CTlsServeur.h"
#include "COutilsOpenSsl.h"

/**
    Point d'entrée pour le processus du serveur.
    @param argc: le nombre d'arguments sur la ligne de commande, incluant le programme.
    @param argv: la liste des arguments.
    @return troujours 0.
*/
int main ()
{
    // Démarrage du serveur.
    COutilsOpenSsl::InitOpenSsl();
    CTlsServeur serveur;
    serveur.attendre("127.0.0.1", 8081);
    serveur.recevoir();
    serveur.arreter();

    return 0;
}
