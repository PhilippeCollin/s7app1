#ifndef CTLSCLIENT_H
#define CTLSCLIENT_H

#include "openssl/ssl.h"

#include "CClient.h"

/**
Coquille pour un client TLS.
*/
class CTlsClient : protected CClient
{
public:
    /**
    Constructeur par d�faut.
    */
    CTlsClient();

    /**
    Destructeur.
    */
    virtual ~CTlsClient();

    /**
    Initie la connexion TLS aupr�s du serveur.
    @param addrClient l'adresse locale du client (pour l'appel � bind)
    @param portClient le port local (pour l'appel � bind)
    @param addrServeur l'adresse � laquelle se connecter
    @param portServeur le port auquel se connecter
    */
    int connecter(string addrClient, unsigned int portClient,
                  string addrServeur, unsigned int portServeur);

    /**
    Arr�t du client, initiant la fermeture de la connexion.
    */
    int arreter();

    /**
    Envoie les donn�es capt�es sur la ligne de commande.
    */
    virtual void echanger();

protected:
    /**
    Le contexte OpenSSL reli� � la connexion.
    */
    SSL_CTX* m_context;

    /**
    Le connexion OpenSSL.
    */
    SSL* m_connexion;
};

#endif
