#if !defined CTLSSERVEUR_H
#define CTLSSERVEUR_H
#include <iostream>
#include "CServeur.h"

#include "openssl/ssl.h"

/**
Coquille pour un serveur TLS.
*/
class CTlsServeur : protected CServeur
{
public:
    /**
    Constructeur par d�faut.
    */
    CTlsServeur();

    /**
    Destructeur.
    */
    virtual ~CTlsServeur();

    /**
    D�marre le serveur.
    @param addrServeur l'adresse � laquelle se connecter
    @param portServeur le port auquel se connecter
    */
    int attendre(string addrServeur, unsigned int portServeur);

    void recevoir();

    /**
    Arr�t du client, initiant la fermeture de la connexion.
    */
    void arreter();

protected:
    /**
    Le contexte TLS du serveur.
    */
    SSL_CTX* m_context;

    /**
    La connexion TLS associ�e au socket 'accept�'.
    */
    SSL* m_connexion;
};

#endif // CTLSSERVEUR_H
