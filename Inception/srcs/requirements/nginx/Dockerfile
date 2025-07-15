# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/22 15:06:45 by cbouvet           #+#    #+#              #
#    Updated: 2025/05/03 20:21:16 by cbouvet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Base image
FROM debian:bullseye

# Prepares environment
ENV DEBIAN_FRONTEND=noninteractive

# Installs NGINX & OpenSSL + cleans up
RUN apt update && \
	apt upgrade -y && \
	apt install -y \
	nginx \
	openssl && \
	apt clean && \
	rm -rf /var/lib/apt/lists/* && \
	mkdir -p /etc/nginx/ssl

# Creates SSL certificate
RUN openssl req -x509 -nodes \
	-out /etc/nginx/ssl/inception.crt \
	-keyout /etc/nginx/ssl/inception.key \
	-subj "/C=PT/ST=Lisbon/L=Lisbon/O=42/OU=cbouvet/CN=cbouvet.42.fr"

# Prepares the setup script
COPY conf/nginx.conf /etc/nginx/nginx.conf
COPY conf/setup.sh /usr/local/bin/setup.sh
RUN chmod +x /usr/local/bin/setup.sh

# Expose HTTPS
EXPOSE 443

# Container initialization
ENTRYPOINT ["/usr/local/bin/setup.sh"]
