#!/bin/sh

# Exit if any command fails
set -e

# Check whether system table is already setup or not
if [ ! -d /var/lib/mysql/mysql ];
then
	mariadb-install-db --user=mysql
