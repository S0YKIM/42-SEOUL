#!/bin/sh

# Exit if any command fails
set -e

# Check whether system table is already setup or not
if [ ! -d $DB_PATH/$DB_NAME ];
then
	# Install mariadb according to my.cnf
	mariadb-install-db

	# Execute mariaDB server as background process
	/usr/bin/mysqld_safe &

	# Create database and user
	mariadb -u root -e "CREATE DATABASE IF NOT EXISTS $DB_NAME; \
	CREATE USER IF NOT EXISTS 'root'@'localhost'; \
	GRANT ALL ON *.* TO 'root'@'localhost' IDENTIFIED BY '$MARIADB_ADMIN_PWD' WITH GRANT OPTION; \
	CREATE USER IF NOT EXISTS '$MARIADB_USER'@'localhost'; \
	GRANT ALL ON $DB_NAME.* TO '$MARIADB_USER'@'localhost' IDENTIFIED BY '$MARIADB_PWD';"

	# Stop mariaDB server
	mariadb-admin shutdown
	echo "MariaDB initialization has done!"
else
	echo "Target database already exists.";
fi

# Run mariaDB server by Dumb Init
exec $@;
