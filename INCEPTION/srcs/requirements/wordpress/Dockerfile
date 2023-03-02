# Base image (The penultimate stable version)
FROM alpine:3.16

# Port number
EXPOSE 9000

# Create directory
RUN mkdir -p /var/www/html/wordpress

WORKDIR /var/www

# Package installation
RUN set -eux && \
	apk update && \
	apk add --no-cache php8 php8-fpm php8-mysqli wget && \
	wget https://wordpress.org/latest.tar.gz | tar -xzvf latest.tar.gz;

# Copy entrypoint script
COPY ./tools/entrypoint.sh .

RUN chmod +x entrypoint.sh

# Command to be executed
ENTRYPOINT ["./entrypoint.sh"]

# Health check
HEALTHCHECK --start-period=3s --interval=10s --timeout=30s --retries=5 CMD ps | grep docker-init

# Command to be executed (added to entrypoint)
CMD ["php-fpm8.1", "-F"]
