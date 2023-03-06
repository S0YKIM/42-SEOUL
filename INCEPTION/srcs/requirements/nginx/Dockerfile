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

# Copy entrypoint script
COPY ./tools/entrypoint.sh .

RUN chmod +x entrypoint.sh

# Command to be executed
ENTRYPOINT ["./entrypoint.sh"]

# Health check
HEALTHCHECK --start-period=3s --interval=10s --timeout=30s --retries=5 CMD ps | grep docker-init

# Command to be executed (added to entrypoint)
CMD ["nginx", "-g", "daemon off;"]
