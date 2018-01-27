#! /bin/bash
DEFAULT_VERSION='1.0.0l'
VERSION=${1:-$DEFAULT_VERSION}

echo "------------------------------------------"
echo -n "Installing OpenSSL ${VERSION}... "
rm -rf openssl
curl --silent -L https://github.com/openssl/openssl/archive/OpenSSL_${VERSION//./_}.tar.gz | tar -xz
mv openssl-OpenSSL_${VERSION//./_} openssl
echo "✅"

cd openssl

echo "------------------------------------------"
echo -n "Configure OpenSSL... "
./Configure darwin64-x86_64-cc shared enable-ec_nistp_64_gcc_128 no-ssl2 no-ssl3 --prefix=$(pwd) --libdir=/ > /dev/null 2>&1
echo "✅"

echo "------------------------------------------"
echo -n "Build OpenSSL... "
if [ "$VERSION" != "$DEFAULT_VERSION" ]
then
  make depend
fi
make > /dev/null 2>&1
echo "✅"
echo "------------------------------------------"
echo "Done 💥"