#include "CClient.h"

CClient::CClient()
:   m_sdClient(0)
{

}

CClient::~CClient()
{

}

int CClient::connecter(string addrClient, unsigned int portClient,
                       string addrServeur, unsigned int portServeur)
{
    int ret = 0;

    m_sdClient = (int)socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in localAddr;
    localAddr.sin_family = AF_INET;
    localAddr.sin_addr.s_addr = inet_addr(addrClient.c_str());
    localAddr.sin_port = htons(portClient);

    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr(addrServeur.c_str());
    serverAddr.sin_port = htons(portServeur);

    ret = bind(m_sdClient, (sockaddr*)&localAddr, (socklen_t)sizeof(localAddr));
    if (!ret)
    {
        ret = connect(m_sdClient, (sockaddr*)&serverAddr, sizeof(serverAddr));
    }

    return ret;
}
