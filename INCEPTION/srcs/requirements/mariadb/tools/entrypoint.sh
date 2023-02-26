#!/bin/sh

# Exit if any command fails
set -ex

# Check whether system table is already setup or not
if [ ! -d $DB_PATH/$DB_NAME ];
then
	# Install mariadb according to my.cnf
	echo "Install MariaDB."
	mariadb-install-db

	# Execute mariaDB server as background process
	echo "Run MariaDB server."
	"$@" &

	# Wait until mariaDB server is ready
	mariadb-admin ping --wait=1 --connect_timeout=30

	# Create database and user
	echo "Create MariaDB database and user."
	mariadb -u root -e "CREATE DATABASE IF NOT EXISTS $DB_NAME; \
	CREATE USER IF NOT EXISTS 'root'@'localhost' IDENTIFIED BY '$MARIADB_ADMIN_PWD'; \
	GRANT ALL ON *.* TO 'root'@'localhost' IDENTIFIED BY '$MARIADB_ADMIN_PWD' WITH GRANT OPTION; \
	CREATE USER IF NOT EXISTS '$MARIADB_USER'@'localhost' IDENTIFIED BY '$MARIADB_PWD'; \
	GRANT ALL ON $DB_NAME.* TO '$MARIADB_USER'@'localhost' IDENTIFIED BY '$MARIADB_PWD';"

	# Stop mariaDB server
	mariadb-admin -uroot -p$MARIADB_ADMIN_PWD shutdown
	echo "MariaDB initialization has done!"
else
	echo "Target database already exists.";
fi

# Run mariaDB server as PID 1
# To receive any signals sent to the container
exec "$@";
