# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/15 18:40:08 by cbouvet           #+#    #+#              #
#    Updated: 2025/05/03 19:10:38 by cbouvet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

YML = ./srcs/docker-compose.yml
ENV = ./srcs/.env
COMPOSE = docker compose -f $(YML) --env-file $(ENV)

up:
	@$(COMPOSE) up --build -d
	@echo "Starting containers"

stop:
	@$(COMPOSE) stop
	@echo "Stopping containers"

down:
	@$(COMPOSE) down
	@echo "Bringing containers down"

clean:
	@$(COMPOSE) down -v
	@echo "Removing containers and volumes"
#	@sudo rm -rf /home/cbouvet/data/mariadb/*
#	@sudo rm -rf /home/cbouvet/data/wordpress/*

fclean: clean
	@docker rmi -f $(docker images -aq) 2>/dev/null || true
	@docker system prune -af
	@echo "Removing all Docker images"

setup:
	@sudo mkdir -p /home/cbouvet/data/mariadb
	@sudo mkdir -p /home/cbouvet/data/wordpress
	@sudo chmod 777 /home/cbouvet/data/mariadb
	@sudo chmod 777 /home/cbouvet/data/wordpress

re: fclean up

logs:
	$(COMPOSE) logs -f

ps:
	@$(COMPOSE) ps
	@docker images

.PHONY: up stop down clean fclean setup re logs ps
