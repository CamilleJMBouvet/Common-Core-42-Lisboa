#!/bin/bash

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    setup.sh                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/22 15:11:34 by cbouvet           #+#    #+#              #
#    Updated: 2025/04/22 15:11:34 by cbouvet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Check if environment variables are set
if [ -z "$SSL_DIR" ] || [ -z "$CRT_PATH" ] || [ -z "$KEY_PATH" ]; then
	echo "❌ Error: SSL environment variables not set"
	exit 30
fi
##Checks if required SSL path are defined

# Sets default domain in case env var not found
DOMAIN=${DOMAIN:-"wordpress.local"}

# Create SSL dir if it doesn't exist
mkdir -p $SSL_DIR

# Generate cert if not exists
if [ -f "$CRT_PATH" ] && [ -f "$KEY_PATH" ]

then
	echo "✅ SSL certificate already exists."

else
	echo "Generating self-signed Certificate"
	openssl req \
	-x509 \
	-nodes \
	-newkey rsa:2048 \
	-days 365 \
	-keyout "$KEY_PATH" \
	-out "$CRT_PATH" \
	-subj "/C=PT/ST=Lisbon/L=Lisbon/O=42/OU=cbouvet/cbouvet.42.fr" || exit 31

fi

# Test nginx configuration
nginx -t || exit 32

# Launch nginx
exec nginx -g "daemon off;" || exit 33
