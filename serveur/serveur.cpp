// Classe du serveur TLS.
#include "CTlsServeur.h"

/**
    Point d'entr�e pour le processus du serveur.
    @param argc: le nombre d'arguments sur la ligne de commande, incluant le programme.
    @param argv: la liste des arguments.
    @return troujours 0.
*/
int main (int argc, char* argv[])
{
    // D�marrage du serveur.
    CTlsServeur serveur;
    serveur.attendre("127.0.0.1", 8081);
    serveur.recevoir();
    serveur.arreter();

    return 0;
}
