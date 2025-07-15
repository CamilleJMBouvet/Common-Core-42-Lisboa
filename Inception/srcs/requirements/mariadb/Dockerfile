# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/18 14:43:32 by cbouvet           #+#    #+#              #
#    Updated: 2025/05/03 19:34:29 by cbouvet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Base image
FROM debian:bullseye

# Prepares environment
ENV DEBIAN_FRONTEND=noninteractive

# Installs MariaDB + cleans up
RUN apt update && \
	apt upgrade -y && \
	apt install -y mariadb-server && \
	apt clean && \
	rm -rf /var/lib/apt/lists/*

# Prepares the setup script from host to container
COPY conf/setup.sh /usr/local/bin/setup.sh
RUN chmod +x /usr/local/bin/setup.sh

# Container initialization
ENTRYPOINT ["/usr/local/bin/setup.sh"]
