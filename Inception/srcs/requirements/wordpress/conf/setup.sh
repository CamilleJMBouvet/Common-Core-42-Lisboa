#!/bin/bash

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    setup.sh                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/19 11:48:34 by cbouvet           #+#    #+#              #
#    Updated: 2025/04/21 17:49:14 by cbouvet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# Gets passwords from secrets
if [ ! -f "/run/secrets/wp_secrets" ]
then
	echo ❌ "Error: WordPress file not found"
	exit 0
fi
source /run/secrets/wp_secrets || exit 1

# Waits for MariaDB to be ready
until mysqladmin ping -h"$DB_HOST" --silent
do
	echo "⏳ Waiting for MariaDB"
	sleep 2
done

# Ensures WordPress directory exists
WP_PATH="/var/www/html"
if [ ! -d "$WP_PATH" ]
then
	mkdir -p "$WP_PATH"
fi
cd "$WP_PATH"

# Checks if image exists - if not, sets it up
if [ -f "$WP_PATH/wp-config.php" ]

then
	echo "✅ WordPress already set up"

else
	echo "🆕 Configuring WordPress"

	#Downloads WordPRess if not present
	if [ ! -f "$WP_PATH/index.php" ]
	then
		wp core download --allow-root --path=$WP_PATH || exit 9
	fi

	#Creates wp-config.php with database settings
	wp config create \
		--allow-root \
		--path=$WP_PATH \
		--dbname=$DB_NAME \
		--dbuser=$DB_USER \
		--dbpass=$DB_PASS \
		--dbhost=$DB_HOST || exit 3

	#Installs WordPress core with admin user
	wp core install \
		--allow-root \
		--url="https://$DOMAIN" \
		--title=$WP_TITLE \
		--admin_user=$WP_ADMIN \
		--admin_password=$WP_ADMINPASS \
		--admin_email=$WP_ADMINEMAIL || exit 4

	#Creates additional user
	wp user create \
		--allow-root \
		$WP_USER \
		$WP_USEREMAIL \
		--user_pass=$WP_USERPASS || exit 5
fi

# Creates PHP-FPM runtime directory
mkdir -p /run/php || exit 6

# Starts PHP-FPM in foreground
exec /usr/sbin/php-fpm7.4 -F || exit 7
