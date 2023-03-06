#!/bin/sh

# Exit if any command fails
set -ex

# OpenSSL setting
mkdir openssl

openssl req -x509 -newkey rsa:4096 -nodes \
	-out /openssl/sokim.42.fr.crt \
	-keyout /openssl/sokim.42.fr.key \
	-subj "/C=KR/ST=Seoul/L=Gaepo/O=InnovationAcademy/OU=42Seoul/CN=sokim.42.fr"

# NGINX configuration validation
nginx -t

# Run nginx server as foreground process
exec "$@"
