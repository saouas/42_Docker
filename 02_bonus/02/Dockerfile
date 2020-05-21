FROM 	debian:latest
MAINTAINER <saouas@student.42.fr>

RUN apt-get update -y \
	&& apt-get upgrade -y \
	&& apt-get install vim -y \
	&& apt-get install gcc -y \
	&& apt-get install valgrind -y 

ADD     ./leaks.c /leaks.c

RUN 	cat leaks.c

RUN 	["gcc", "-Wall", "-Wextra", "-Werror", "-g", "-o", "leaks", "leaks.c"]
CMD ["valgrind", "--leak-check=yes", "./leaks"]
