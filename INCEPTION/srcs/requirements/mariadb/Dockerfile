# Base Image (The penultimate stable version)
FROM alpine:3.16

# Port Number
EXPOSE 3306

# Package Installation
RUN set -eux && \
	apk update && \
	apk add mariadb mariadb-client vim && \
	# Allow running the mysql daemon
	rm -rf /var/lib/mysql && \
	mkdir -p /run/mysqld /var/lib/mysql && \
	# Change the owner from root to mysql
	chown -R mysql:mysql /run/mysqld /var/lib/mysql && \
	chmod 777 /run/mysqld /var/lib/mysql;
RUN ls /var/lib;

# Copy the Entrypoint Script
COPY ./tools/entrypoint.sh .

RUN chmod +x entrypoint.sh

# Command To Be Executed
ENTRYPOINT ["./entrypoint.sh"]

# Health Check
HEALTHCHECK --start-period=3s --interval=10s --timeout=30s --retries=5 CMD pgrep tini && mariadb-admin ping

# Command To Be Executed (added to entrypoint)
CMD ["mysqld_safe"]
