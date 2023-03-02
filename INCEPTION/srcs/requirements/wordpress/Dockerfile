# Base image (The penultimate stable version)
FROM alpine:3.16

# Port number
EXPOSE 9000

# Package installation
RUN set -eux && \
	apk update && \
	apk add --no-cache php8 php8-fpm php8-mysqli php8-common php8-iconv php8-tokenizer php8-gd php8-cli php8-phar mysql-client wget;

# Create user www-data
RUN adduser -u 82 -D -S -G www-data www-data

# Make directory and change owner to www-data
RUN set -eux && \
	mkdir -p /var/www/html/wordpress /run/php && \
	chown -R www-data:www-data /var/www/html/wordpress && \
	chmod 777 /var/www/html/wordpress;

RUN set -eux && \
	wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
	chmod +x wp-cli.phar && \
	mv wp-cli.phar /usr/local/bin/wp;

# Copy entrypoint script
COPY ./tools/entrypoint.sh .

RUN chmod +x entrypoint.sh

# Command to be executed
ENTRYPOINT ["./entrypoint.sh"]

# Health check
HEALTHCHECK --start-period=3s --interval=10s --timeout=30s --retries=5 CMD ps | grep docker-init

# Command to be executed (added to entrypoint)
CMD ["php-fpm8", "-F"]
