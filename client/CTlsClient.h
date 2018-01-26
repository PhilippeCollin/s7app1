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
    Constructeur par défaut.
    */
    CTlsClient();

    /**
    Destructeur.
    */
    virtual ~CTlsClient();

    /**
    Initie la connexion TLS auprès du serveur.
    @param addrClient l'adresse locale du client (pour l'appel à bind)
    @param portClient le port local (pour l'appel à bind)
    @param addrServeur l'adresse à laquelle se connecter
    @param portServeur le port auquel se connecter
    */
    int connecter(string addrClient, unsigned int portClient,
                  string addrServeur, unsigned int portServeur);

    /**
    Arrêt du client, initiant la fermeture de la connexion.
    */
    int arreter();

    /**
    Envoie les données captées sur la ligne de commande.
    */
    virtual void echanger();

protected:
    /**
    Le contexte OpenSSL relié à la connexion.
    */
    SSL_CTX* m_context;

    /**
    Le connexion OpenSSL.
    */
    SSL* m_connexion;
};

#endif
