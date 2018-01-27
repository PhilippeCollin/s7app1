cmake_minimum_required(VERSION 3.9)
project(src)

set(CMAKE_CXX_STANDARD 11)

set(OPENSSL_ROOT_DIR openssl)
set(OPENSSL_USE_STATIC_LIBS TRUE)
find_package(OpenSSL REQUIRED)

message(AUTHOR_WARNING "OPENSSL libs: ${OPENSSL_VERSION}")
add_definitions(-DCERTIFICATS_PATH="${CMAKE_CURRENT_SOURCE_DIR}/certificats/")

include_directories(outilsOpenSsl)

add_subdirectory(serveur)
add_subdirectory(client)