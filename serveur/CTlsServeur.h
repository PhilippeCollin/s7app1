#if !defined CTLSSERVEUR_H
#define CTLSSERVEUR_H

#include "CServeur.h"

#include "openssl/ssl.h"

/**
Coquille pour un serveur TLS.
*/
class CTlsServeur : protected CServeur
{
public:
    /**
    Constructeur par défaut.
    */
    CTlsServeur();

    /**
    Destructeur.
    */
    virtual ~CTlsServeur();

    /**
    Démarre le serveur.
    @param addrServeur l'adresse à laquelle se connecter
    @param portServeur le port auquel se connecter
    */
    int attendre(string addrServeur, unsigned int portServeur);

    void recevoir();

    /**
    Arrêt du client, initiant la fermeture de la connexion.
    */
    void arreter();

protected:
    /**
    Le contexte TLS du serveur.
    */
    SSL_CTX* m_context;

    /**
    La connexion TLS associée au socket 'accepté'.
    */
    SSL* m_connexion;
};

#endif // CTLSSERVEUR_H
