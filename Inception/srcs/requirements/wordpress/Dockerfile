# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/19 11:48:59 by cbouvet           #+#    #+#              #
#    Updated: 2025/05/03 19:59:01 by cbouvet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Base image
FROM debian:bullseye

# Prepares environment
ENV DEBIAN_FRONTEND=noninteractive

# Installs WordPress + cleans up
RUN apt update && \
	apt upgrade -y && \
	apt install -y \
	php-fpm \
	php-mysql \
	curl \
	ca-certificates \
	mariadb-client && \
	apt clean && \
	rm -rf /var/lib/apt/lists/*

# Configure PHP-FPM to listen on port 9000
RUN sed -i 's|listen = /run/php/php7.4-fpm.sock|listen = 9000|g' /etc/php/7.4/fpm/pool.d/www.conf

# Sets directory to install WordPress
WORKDIR /var/www/wordpress
RUN ln -s /var/www/wordpress /var/www/html

# Downloads and installs WP-CLI
RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
	chmod +x wp-cli.phar && \
	mv wp-cli.phar /usr/local/bin/wp

# Downloads WordPress files
RUN wp core download --allow-root

# Prepares the setup script
COPY conf/setup.sh /usr/local/bin/setup.sh
RUN chmod +x /usr/local/bin/setup.sh

# Exposes php-fpm port for NGINX
EXPOSE 9000

# Container initialization
ENTRYPOINT ["/usr/local/bin/setup.sh"]
