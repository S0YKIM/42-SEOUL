NAME = inception

COMPOSE_SRC = ./srcs/docker-compose.yml

VOLUME_PATH = /home/sokim/data

.PHONY : all
all : build
	mkdir -p $(VOLUME_PATH)
	docker compose -f $(COMPOSE_SRC) up

.PHONY : build
build :
	docker compose -f $(COMPOSE_SRC) build

.PHONY : clean
clean :
	docker compose -f $(COMPOSE_SRC) down \
	--remove-orphans --rmi all -v

.PHONY : fclean
fclean : clean
	rm -rf $(VOLUME_PATH)

.PHONY : re
re :
	make fclean
	make all
