#!/bin/sh

# Exit if any command fails
set -ex

# Check whether system table is already setup or not
if [ ! -d $DB_PATH/$DB_NAME ]
then
	# Install Mariadb according to my.cnf
	echo "Install MariaDB."
	mariadb-install-db

	# Execute MariaDB server as background process
	echo "Run MariaDB server."
	"$@" &

	# Wait until MariaDB server is ready
	mariadb-admin ping --wait=1 --connect_timeout=30

	# Create database and user
	echo "Create MariaDB database and user."
	mariadb -u root -e "CREATE DATABASE IF NOT EXISTS $DB_NAME; \
	CREATE USER IF NOT EXISTS 'root'@'localhost' IDENTIFIED BY '$MARIADB_ADMIN_PWD'; \
	GRANT ALL ON *.* TO 'root'@'localhost' IDENTIFIED BY '$MARIADB_ADMIN_PWD' WITH GRANT OPTION; \
	CREATE USER IF NOT EXISTS '$MARIADB_USER'@'localhost' IDENTIFIED BY '$MARIADB_PWD'; \
	GRANT ALL ON $DB_NAME.* TO '$MARIADB_USER'@'localhost' IDENTIFIED BY '$MARIADB_PWD';"

	# Stop MariaDB server
	mariadb-admin -uroot -p$MARIADB_ADMIN_PWD shutdown
	echo "MariaDB initialization has done!"
else
	echo "Target database already exists.";
fi

# Run MariaDB server as foreground process
exec "$@";
