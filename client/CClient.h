#ifndef CCLIENT_H
#define CCLIENT_H

#include <sys/types.h>
#include <sys/socket.h>
#include <string>
#include <iostream>
#include <netinet/in.h>
#include <arpa/inet.h>

using std::string;
using std::cout;
using std::cin;

/**
Abstraction d'une connexion TCP, du côté client. Il se connecte à un serveur
paramétrisé et permet de prendre des données sur la ligne de commande et les
echanger au serveur.
*/
class CClient
{
public:
    /**
    Constructeur par défaut.
    */
    CClient();

    /**
    Destructeur.
    */
    virtual ~CClient();

    /**
    Initie la connexion auprès du serveur.
    @param addrClient l'adresse locale du client (pour l'appel à bind)
    @param portClient le port local (pour l'appel à bind)
    @param addrServeur l'adresse à laquelle se connecter
    @param portServeur le port auquel se connecter
    */
    virtual int connecter(string addrClient, unsigned int portClient,
                          string addrServeur, unsigned int portServeur);

    /**
    Arrêt du client, initiant la fermeture de la connexion.
    */
    virtual int arreter();

    /**
    Envoie les données captées sur la ligne de commande.
    */
    virtual void echanger();

protected:
    /**
    Capte les données sur la ligne de commande.
    */
    virtual bool capter(string& msg);

    /**
    Eonvoie les données sur le socket.
    */
    virtual int envoyer(string& msg);

    /**
    Le socket descriptor de la connexion.
    */
    int m_sdClient;
};

inline
int CClient::arreter()
{
    return shutdown(m_sdClient, SHUT_RDWR);
}

inline
void CClient::echanger()
{
    string msg;
    while (!capter(msg) && envoyer(msg) >= 0)
        ;
}

inline
bool CClient::capter(string& msg)
{
    cout << "client> ";
    cin >> msg;
    return msg == "q";
}

inline
int CClient::envoyer(string& msg)
{
    return send(m_sdClient, msg.c_str(), static_cast<int>(msg.length()), 0);
}

#endif // CCLIENT_H