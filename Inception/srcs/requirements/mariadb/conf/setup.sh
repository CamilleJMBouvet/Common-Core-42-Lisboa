#!/bin/bash

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    setup.sh                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/18 16:33:37 by cbouvet           #+#    #+#              #
#    Updated: 2025/04/21 17:22:44 by cbouvet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Gets passwords from secrets
if [ ! -f "/run/secrets/db_secrets" ]
then
	echo "❌ Error: MariaDB secrets not found"
	exit 10
fi
source /run/secrets/db_secrets || exit 11

# Checks if database exists - if not, sets it up
if [ -d "/var/lib/mysql/$DB_NAME" ]

then
	echo ✅ MariaDB image already existing

else
	echo 🆕 Configuring MariaDB
	service mariadb start || exit 12
	sleep 5

	mysql_install_db
	mysqld_safe --skip-grant-tables --skip-networking &
	sleep 5

	#Sets root password for all local connections
	mysql -u root << EOF
	FLUSH PRIVILEGES;
	ALTER USER 'root'@'localhost' IDENTIFIED BY '$DB_ROOTPASS';
	ALTER USER 'root'@'127.0.0.1' IDENTIFIED BY '$DB_ROOTPASS';
	ALTER USER 'root'@'::1' IDENTIFIED BY '$DB_ROOTPASS';
	FLUSH PRIVILEGES;
EOF

	killall mysqld
	sleep 5
	service mariadb start
	sleep 5

	#Now use root with password for remaining operations
	mysql -u root -p"$DB_ROOTPASS" << EOF
	DELETE FROM mysql.user WHERE User='';
	DELETE FROM mysql.user WHERE User='root' AND Host NOT IN ('localhost', '127.0.0.1', '::1');
	CREATE DATABASE IF NOT EXISTS \`$DB_NAME\`;
	CREATE USER IF NOT EXISTS '$DB_USER'@'%' IDENTIFIED BY '$DB_PASSW';
	CREATE USER IF NOT EXISTS '$DB_USER2'@'%' IDENTIFIED BY '$DB_PASS2';
	GRANT ALL PRIVILEGES ON \`$DB_NAME\`.* TO '$DB_USER'@'%';
	GRANT ALL PRIVILEGES ON \`$DB_NAME\`.* TO '$DB_USER2'@'%';
	FLUSH PRIVILEGES;
EOF
fi

# Stop service before final launch | Graceful shutdown, proper cleanup
service mariadb stop || exit 19

# Launches MariaDB with network access
exec mysqld_safe --bind-address=0.0.0.0
