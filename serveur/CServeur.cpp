#include "CServeur.h"

#include <sys/socket.h>
#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

CServeur::CServeur()
:   m_sdServeur(0),
    m_sdClient(0)
{

}

CServeur::~CServeur()
{

}

int CServeur::attendre(string addrServeur, unsigned int portServeur)
{
    m_sdServeur = (int)socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in localAddr;
    localAddr.sin_family = AF_INET;
    localAddr.sin_addr.s_addr = inet_addr(addrServeur.c_str());
    localAddr.sin_port = htons(portServeur);

    bool bReuse = true;
    int ret = setsockopt(m_sdServeur, SOL_SOCKET, SO_REUSEADDR, reinterpret_cast<char*>(&bReuse), sizeof(bReuse));
    ret = bind(m_sdServeur, (sockaddr*)&localAddr, (socklen_t)sizeof(localAddr));

    if (!ret)
    {
        ret = listen(m_sdServeur, 5);
    }

    cout << "serveur> en attente de connexion" << endl;

    sockaddr peerAddr;
    socklen_t uPeerAddrSize = sizeof(sockaddr);
    m_sdClient = (int)accept(m_sdServeur, &peerAddr, &uPeerAddrSize);

    if (m_sdClient > 0)
    {
        cout << "serveur> client connecte" << endl;
    }

    return ret;
}

void CServeur::recevoir()
{
    cout << "serveur> en attente de donnees" << endl;
    char data[1024];
    int recvLen = 0;
    bool bQuit = false;
    do 
    {
        do 
        {
            memset(data, 0, 1024);
            recvLen = recv(m_sdClient, data, 1024 , 0);
            cout << "serveur> " << data << endl;
        } while (recvLen > 0);

        bQuit = recvLen <= 0;
    } while (!bQuit);
}

