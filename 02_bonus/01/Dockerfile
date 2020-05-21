FROM debian
MAINTAINER <saouas@student.42.fr>

# depends
RUN apt-get update -y && apt-get upgrade -y
RUN apt-get install clang -y
RUN apt-get install binutils -y
RUN apt-get install git -y


# tools needed
RUN apt-get install vim -y
RUN apt-get install make -y

CMD /bin/bash
