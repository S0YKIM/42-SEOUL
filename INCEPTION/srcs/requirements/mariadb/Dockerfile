# Base Image (The penultimate stable version)
FROM debian:buster

# Port Number
EXPOSE 3306

# Package Installation
RUN apt-get update && apt-get upgrade && \
	apt-get install -y mariadb-server && \
	apt-get install -y vim && \
	apt-get install -y procps
RUN ls

# Copy the Entrypoint Script
COPY ./tools/entrypoint.sh .

RUN chmod +x /entrypoint.sh

# Command To Be Executed
ENTRYPOINT ["./entrypoint.sh"]

# Health Check
HEALTHCHECK --start-period=3s --interval=10s --timeout=30s --retries=5 CMD pgrep tini && mariadb-admin ping

# Command To Be Executed (added to entrypoint)
CMD ["mysqld_safe"]
