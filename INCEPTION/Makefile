NAME = inception

COMPOSE_SRC = ./srcs/docker-compose.yml

VOLUME_PATH = /home/sokim/data

.PHONY : all
all : build
	@ mkdir -p $(VOLUME_PATH)/db_volume;
	@ mkdir -p $(VOLUME_PATH)/wp_volume; 
	@ docker compose -f $(COMPOSE_SRC) up

.PHONY : build
build :
	@ docker compose -f $(COMPOSE_SRC) build --progress=plain

.PHONY : stop
stop :
	@ docker compose -f $(COMPOSE_SRC) stop

.PHONY : restart
restart :
	@ docker compose -f $(COMPOSE_SRC) restart

.PHONY : clean
clean :
	@ docker compose -f $(COMPOSE_SRC) down \
	--remove-orphans --rmi all -v

.PHONY : fclean
fclean : clean
	@ sudo rm -rf $(VOLUME_PATH)

.PHONY : re
re :
	make fclean
	make all
