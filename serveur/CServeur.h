#ifndef CSERVEUR_H
#define CSERVEUR_H

#include <sys/types.h>
#include <sys/socket.h>
#include <string>
#include <netinet/in.h>
#include <arpa/inet.h>

using std::string;

/**
Abstraction d'une connexion TCP, du côté client. Il se connecte à un serveur
paramétrisé et permet de prendre des données sur la ligne de commande et les
envoyer au serveur.
*/
class CServeur
{
public:
    /**
    Constructeur par défaut.
    */
    CServeur();

    /**
    Destructeur.
    */
    virtual ~CServeur();

    /**
    Écoute pour des connexions du client.
    @param addrServeur l'adresse à laquelle se connecter
    @param portServeur le port auquel se connecter
    */
    virtual int attendre(string addrServeur, unsigned int portServeur);

    /**
    Arrêt du serveur, initiant la fermeture de la connexion.
    */
    virtual void arreter();

protected:
    /**
    Attente de réception de données du client et les imprime au stdout.
    */
    virtual void recevoir();

    /**
    Socket descriptor du socket serveur.
    */
    int m_sdServeur;

    /**
    Socket descriptor du socket créé lors de l'appel à accept()
    */
    int m_sdClient;
};

inline
void CServeur::arreter()
{
    shutdown(m_sdClient, SHUT_RDWR);
    shutdown(m_sdServeur, SHUT_RDWR);
}

#endif // CSERVEUR_H
