# Base image (The penultimate stable version)
FROM alpine:3.16

# Port number
EXPOSE 3306

# Package installation
RUN set -eux && \
	apk update && \
	apk add mariadb mariadb-client vim && \
	# Allow running the mysql daemon
	rm -rf /var/lib/mysql && \
	mkdir -p /run/mysqld /var/lib/mysql /var/log/mysql && \
	# Change the owner from root to mysql
	chown -R mysql:mysql /run/mysqld /var/lib/mysql /var/log/mysql && \
	chmod 777 /run/mysqld /var/lib/mysql /var/log/mysql;

# Copy entrypoint script
COPY ./tools/entrypoint.sh .

RUN chmod +x entrypoint.sh

# Command to be executed
ENTRYPOINT ["./entrypoint.sh"]

# Health check
HEALTHCHECK --start-period=3s --interval=10s --timeout=30s --retries=5 CMD ps | grep docker-init && mariadb-admin ping

# Command to be executed (added to entrypoint)
CMD ["mysqld"]
