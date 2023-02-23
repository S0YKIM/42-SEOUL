# Base Image (The penultimate stable version)
FROM apline:3.16

# Port Number
EXPOSE 3306

# Package Installation
RUN apt-get update && apt-get install -y \
	mairadb-server \
	vim \
	procps

# Copy the Entrypoint Script
COPY ./tools/entrypoint.sh .

# Command To Be Executed
ENTRYPOINT ["./entrypoint.sh"]

# Health Check
HEALTHCHECK --start-period=3s --interval=10s --timeout=30s --retries=5 CMD pgrep tini && mariadb-admin ping

# Command To Be Executed (added to entrypoint)
CMD ["mysqld_safe"]
