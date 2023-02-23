# Base Image (The penultimate stable version Debian 10)
FROM debian:buster

# Port Number
EXPOSE 3306

# Package Installation
RUN apt-get update && apt-get install -y \
	mairadb-server \
	vim \
	procps

# Copy the Entrypoint Script
COPY ./tools/entrypoint.sh .

# TODO: CMD 뒤의 명령어
# Health Check
HEALTHCHECK --start-period=3s --interval=10s --timeout=30s --retries=5 CMD [명령어]

# Command to Be Executed
ENTRYPOINT ["./entrypoint.sh"]
