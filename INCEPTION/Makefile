NAME = inception

COMPOSE_SRC = ./srcs/docker-compose.yml

VOLUME_PATH = /home/sokim/data

.PHONY : all
all : build
	@ sudo docker compose -f $(COMPOSE_SRC) up

.PHONY : build
build :
	@ sudo docker compose -f $(COMPOSE_SRC) build --progress=plain

.PHONY : clean
clean :
	@ sudo docker compose -f $(COMPOSE_SRC) down \
	--remove-orphans --rmi all -v

.PHONY : fclean
fclean : clean
	@ sudo rm -rf $(VOLUME_PATH)

.PHONY : re
re :
	make fclean
	make all
