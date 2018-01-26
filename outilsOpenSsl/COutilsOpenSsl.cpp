#include "COutilsOpenSsl.h"

#include <fstream>
#include <iostream>

#include "openssl/ssl.h"
#include "openssl/err.h"
#include "openssl/rand.h"

using namespace std;

bool COutilsOpenSsl::m_bInit = false;

COutilsOpenSsl::COutilsOpenSsl()
{

}

COutilsOpenSsl::~COutilsOpenSsl()
{

}

bool COutilsOpenSsl::InitOpenSsl()
{
    if (!m_bInit)
    {
        m_bInit = true;

        cout << "Version: " << OPENSSL_VERSION_TEXT << endl;
        SSL_load_error_strings();
        SSL_library_init();
        RAND_screen();
    }
    return m_bInit;
}

X509* COutilsOpenSsl::ouvrirCertificat(string chemin)
{
    ifstream cert (chemin.c_str(), ios::in | ios::binary);
    cert.seekg (0,ios::end);
    int certSize = static_cast<int>(cert.tellg());
    char* certBuffer = new char [certSize];
    memset (certBuffer, 0, certSize);
    cert.seekg(0, ios::beg);
    cert.read(certBuffer, certSize);
    cert.close();

    const unsigned char* p = (unsigned char*)certBuffer;
    X509* x509cert = d2i_X509(NULL, &p, certSize);

    delete [] certBuffer;

    return x509cert;
}

void COutilsOpenSsl::opensslMsg (int direction, int version, int type, const void* message, size_t len, SSL* connexion, void* arg)
{
    const char* pMessage = reinterpret_cast<const char*>(message);

    cout << (char*)arg << " - ";

    (direction) ? cout << "envoi " : cout << "reception";

    switch(version)
    {
        case SSL2_VERSION: cout << "SSLv2 "; break;
        case SSL3_VERSION: cout << "SSLv3 "; break;
        case TLS1_VERSION: cout << "TLSv1 "; break;
    }

    switch(type)
    {
        case 20: cout << " ChangeCipherSpec"; break;
        case 21:
        {
            cout << "Alert: ";
            switch (pMessage[0])
            {
                case SSL3_AL_WARNING: cout << "warning"; break;
                case SSL3_AL_FATAL:  cout << "fatal"; break;
            }
        }
        break;
        case 22:
        {
            cout << "Handshake: ";
            switch (pMessage[0])
            {
                case SSL3_MT_HELLO_REQUEST: cout << "Hello Request"; break;
                case SSL3_MT_CLIENT_HELLO: cout << "Client Hello"; break;
                case SSL3_MT_SERVER_HELLO: cout << "Server Hello"; break;
                case SSL3_MT_CERTIFICATE: cout << "Certificate"; break;
                case SSL3_MT_SERVER_KEY_EXCHANGE: cout << "ServerKeyExchange"; break;
                case SSL3_MT_CERTIFICATE_REQUEST: cout << "CertificateRequest"; break;
                case SSL3_MT_SERVER_DONE: cout << "ServerHelloDone"; break;
                case SSL3_MT_CERTIFICATE_VERIFY: cout << "CertificateVerify"; break;
                case SSL3_MT_CLIENT_KEY_EXCHANGE: cout << "CertificateKeyExchange"; break;
                case SSL3_MT_FINISHED: cout << "Finished"; break;
            }
        }
        break;
    }

    cout << endl;
}
