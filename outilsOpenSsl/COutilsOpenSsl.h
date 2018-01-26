#ifndef COUTILSOPENSSL
#define COUTILSOPENSSL

#include <string>

#include <openssl/ssl.h>

using namespace std;

/**
Classe comprenant divers utilitaires pour des scénarios de TLS utilisant OpenSSL.
*/
class COutilsOpenSsl
{
public:
    /**
    Initialisation de la librairie. Cette méthode peut être appelée plusieurs
    fois, mais l'initialisation ne se fera qu'une fois.
    @return true lorsque la librairie est initialisée.
    */
    static bool InitOpenSsl();

    /**
    Lie le fichier contenant un certificat X.509 en format DER et le convertit en une structure interne à OpenSSL.
    @param chemin le chemin du fichier
    @return la structure interne du certificat, ou NULL si la conversion a Échoué
    */
    static X509* ouvrirCertificat(string chemin);

    /**
    Méthode servant à tracer les messages TLS envoyées et reçues par la librairie.
    */
    static void opensslMsg(int direction, int version, int type, const void* message, size_t len, SSL* connexion, void* arg);
protected:
    /**
    Constructeur par défaut.
    */
    COutilsOpenSsl();

    /**
    Destructeur
    */
    virtual ~COutilsOpenSsl();

    /**
    Indicateur servant à savoir si la librairie a été initialisée.
    */
    static bool m_bInit;
};

#endif // COUTILSOPENSSL
