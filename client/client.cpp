// Classe du client TLS.
#include "CTlsClient.h"

/**
    Point d'entr�e pour le processus du client.
    @param argc: le nombre d'arguments sur la ligne de commande, incluant le programme.
    @param argv: la liste des arguments.
    @return troujours 0.
*/
int main (int argc, char* argv[])
{
    // Initialisation de la librairie winsock.

    // D�marrage du client.
    CTlsClient client;
    client.connecter("127.0.0.1", 0, "127.0.0.1", 8081);

    // �change de donn�es.
    client.echanger();

    // Arr�t du client.
    client.arreter();

    return 0;
}

