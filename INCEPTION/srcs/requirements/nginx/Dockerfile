# Base image (The penultimate stable version)
FROM alpine:3.16

# Port number
EXPOSE 443

# Package installation
RUN set -eux && \
	apk update && \
	apk add nginx openssl

# OpenSSL setting
RUN mkdir openssl

RUN openssl req -x509 -newkey rsa:4096 -nodes \
	-key /openssl/sokim.42.fr.key \
	-out /openssl/sokim.42.fr.crt \
	-subj "/C=KR/ST=Seoul/L=Gaepo/O=InnovationAcademy/OU=42Seoul/CN=sokim.42.fr"

# Command to be executed (added to entrypoint)
CMD ["nginx", "-g", "daemon off;"]
