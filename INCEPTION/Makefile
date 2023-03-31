NAME = inception

COMPOSE_SRC = ./srcs/docker-compose.yml

VOLUME_PATH = /Users/soyeon/desktop

.PHONY : all
all : build
	@ mkdir -p $(VOLUME_PATH)/db_volume;
	@ mkdir -p $(VOLUME_PATH)/wp_volume; 
	@ sudo docker compose -f $(COMPOSE_SRC) up

.PHONY : build
build :
	@ sudo docker compose -f $(COMPOSE_SRC) build --progress=plain

.PHONY : stop
stop :
	@ sudo docker compose -f $(COMPOSE_SRC) stop

.PHONY : restart
restart :
	@ sudo docker compose -f $(COMPOSE_SRC) restart

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
