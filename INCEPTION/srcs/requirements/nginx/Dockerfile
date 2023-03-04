# Base image (The penultimate stable version)
FROM alpine:3.16

# Port number
EXPOSE 443

# Package installation
RUN set -eux && \
	apk update && \
	apk add nginx openssl

# Make directory for wordpress
RUN mkdir -p /var/www/html/wordpress

# OpenSSL setting
RUN mkdir openssl

RUN openssl req -x509 -newkey rsa:4096 -nodes \
	-out /openssl/sokim.42.fr.crt \
	-keyout /openssl/sokim.42.fr.key \
	-subj "/C=KR/ST=Seoul/L=Gaepo/O=InnovationAcademy/OU=42Seoul/CN=sokim.42.fr"

# Command to be executed
CMD ["nginx", "-g", "daemon off;"]
