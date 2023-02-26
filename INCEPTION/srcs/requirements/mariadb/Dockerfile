# Base image (The penultimate stable version)
FROM alpine:3.16

# Port number
EXPOSE 3306

# Package installation
RUN set -eux && \
	apk update && \
	apk add --no-cache mariadb mariadb-client vim && \
	# Allow running the mysql daemon
	rm -rf /var/lib/mysql && \
	mkdir -p /run/mysqld /var/lib/mysql /var/log/mysql && \
	# Change the owner from root to mysql
	chown -R mysql:mysql /run/mysqld /var/lib/mysql /var/log/mysql && \
	chmod 777 /run/mysqld /var/lib/mysql /var/log/mysql;

# Copy the config file and entrypoint Script
COPY ./conf/my.cnf /etc/mysql/mariadb.conf.d/
COPY ./tools/entrypoint.sh .

RUN chmod +x entrypoint.sh

# Command To Be Executed
ENTRYPOINT ["./entrypoint.sh"]

# Health Check
HEALTHCHECK --start-period=3s --interval=10s --timeout=30s --retries=5 CMD pgrep tini && mariadb-admin ping

# Command To Be Executed (added to entrypoint)
CMD ["mysqld"]
