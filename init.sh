#! /bin/bash
VERSION='1.1.0g'

rm -rf openssl
wget https://github.com/openssl/openssl/archive/OpenSSL_${VERSION//./_}.tar.gz -O - | tar -xz && mv openssl-OpenSSL_${VERSION//./_} openssl
cd openssl
./Configure darwin64-x86_64-cc shared enable-ec_nistp_64_gcc_128 no-ssl2 no-ssl3 no-comp --prefix=$(pwd) --libdir=/
make depend
make
