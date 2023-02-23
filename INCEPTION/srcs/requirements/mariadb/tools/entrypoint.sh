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

	# Stop mariadb server
	mariadb-admin shutdown
else
	echo "Target database already exists.";
fi
