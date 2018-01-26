#include "CTlsClient.h"
#include "COutilsOpenSsl.h"

#include <iostream>
#include "openssl/err.h"

using std::string;

CTlsClient::CTlsClient()
:   CClient(),
    m_context(NULL),
    m_connexion(NULL)
{

}

CTlsClient::~CTlsClient()
{

}

int CTlsClient::connecter(string addrClient, unsigned int portClient,
                          string addrServeur, unsigned int portServeur)
{
    return CClient::connecter(addrClient, portClient, addrServeur, portServeur);
}

int CTlsClient::arreter()
{
    return CClient::arreter();
}

void CTlsClient::echanger()
{
    CClient::echanger();
}
