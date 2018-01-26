#ifndef COUTILSOPENSSL
#define COUTILSOPENSSL

#include <string>

#include "openssl/ssl.h"

using namespace std;

/**
Classe comprenant divers utilitaires pour des sc�narios de TLS utilisant OpenSSL.
*/
class COutilsOpenSsl
{
public:
    /**
    Initialisation de la librairie. Cette m�thode peut �tre appel�e plusieurs
    fois, mais l'initialisation ne se fera qu'une fois.
    @return true lorsque la librairie est initialis�e.
    */
    static bool InitOpenSsl();

    /**
    Lie le fichier contenant un certificat X.509 en format DER et le convertit en une structure interne � OpenSSL.
    @param chemin le chemin du fichier
    @return la structure interne du certificat, ou NULL si la conversion a �chou�
    */
    static X509* ouvrirCertificat(string chemin);

    /**
    M�thode servant � tracer les messages TLS envoy�es et re�ues par la librairie.
    */
    static void opensslMsg(int direction, int version, int type, const void* message, size_t len, SSL* connexion, void* arg);
protected:
    /**
    Constructeur par d�faut.
    */
    COutilsOpenSsl();

    /**
    Destructeur
    */
    virtual ~COutilsOpenSsl();

    /**
    Indicateur servant � savoir si la librairie a �t� initialis�e.
    */
    static bool m_bInit;
};

#endif // COUTILSOPENSSL
