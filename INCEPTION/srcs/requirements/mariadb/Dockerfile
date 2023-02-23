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

# Command To Be Executed (added to entrypoint)
CMD ["mariadb"]
