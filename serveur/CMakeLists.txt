add_executable(server
        CServeur.cpp
        CServeur.h
        CTlsServeur.cpp
        CTlsServeur.h
        serveur.cpp
        ${CMAKE_SOURCE_DIR}/outilsOpenSsl/COutilsOpenSsl.h
        ${CMAKE_SOURCE_DIR}/outilsOpenSsl/COutilsOpenSsl.cpp)

target_link_libraries(server OpenSSL::SSL OpenSSL::Crypto)