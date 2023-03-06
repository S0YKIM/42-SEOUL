#!/bin/sh

# Exit if any command fails
set -ex

# Check whether openssl is already setup or not
if [ ! -d /etc/nginx/openssl ]
then
	# OpenSSL setting
	mkdir /etc/nginx/openssl

	openssl req -x509 -newkey rsa:4096 -nodes \
		-out /etc/nginx/openssl/sokim.42.fr.crt \
		-keyout /etc/nginx/openssl/sokim.42.fr.key \
		-subj "/C=KR/ST=Seoul/L=Gaepo/O=InnovationAcademy/OU=42Seoul/CN=sokim.42.fr"

# NGINX configuration validation
	nginx -t
	echo "SSL setting has done!"
else
	echo "OpenSSL already exists."
fi

# Run nginx server as foreground process
exec "$@"
