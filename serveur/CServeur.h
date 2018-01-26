#ifndef CSERVEUR_H
#define CSERVEUR_H

#include <sys/types.h>
#include <sys/socket.h>
#include <string>
#include <netinet/in.h>
#include <arpa/inet.h>

using std::string;

/**
Abstraction d'une connexion TCP, du c�t� client. Il se connecte � un serveur
param�tris� et permet de prendre des donn�es sur la ligne de commande et les
envoyer au serveur.
*/
class CServeur
{
public:
    /**
    Constructeur par d�faut.
    */
    CServeur();

    /**
    Destructeur.
    */
    virtual ~CServeur();

    /**
    �coute pour des connexions du client.
    @param addrServeur l'adresse � laquelle se connecter
    @param portServeur le port auquel se connecter
    */
    virtual int attendre(string addrServeur, unsigned int portServeur);

    /**
    Arr�t du serveur, initiant la fermeture de la connexion.
    */
    virtual void arreter();

protected:
    /**
    Attente de r�ception de donn�es du client et les imprime au stdout.
    */
    virtual void recevoir();

    /**
    Socket descriptor du socket serveur.
    */
    int m_sdServeur;

    /**
    Socket descriptor du socket cr�� lors de l'appel � accept()
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