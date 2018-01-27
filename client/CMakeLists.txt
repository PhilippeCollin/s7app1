add_executable(client
        CClient.cpp
        CClient.h
        CTlsClient.cpp
        CTlsClient.h
        client.cpp
        ${CMAKE_SOURCE_DIR}/outilsOpenSsl/COutilsOpenSsl.h
        ${CMAKE_SOURCE_DIR}/outilsOpenSsl/COutilsOpenSsl.cpp)

target_link_libraries(client OpenSSL::SSL OpenSSL::Crypto)