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

