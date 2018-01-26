#include "CTlsServeur.h"


CTlsServeur::CTlsServeur()
: CServeur(),
  m_context(NULL),
  m_connexion(NULL)
{
}

CTlsServeur::~CTlsServeur()
{

}

int CTlsServeur::attendre(string addrServeur, unsigned int portServeur)
{
    // Receice <- Client Hello
    // Send -> Serveur Hello
    // Send -> Certificat
    // Send -> Server Hello Done
    // Receice <- Client key exchange
    // Receice <- Change cipher spec
    // Receice <- Finished
    // Send -> Change cipher spec
    // Send -> Finished
    return CServeur::attendre(addrServeur, portServeur);
}

void CTlsServeur::recevoir()
{
    CServeur::recevoir();
}

void CTlsServeur::arreter()
{
    CServeur::arreter();
}

