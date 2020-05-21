FROM debian
#
## Set de variable d'env necessaire pour TS
#
ENV TS_RELEASE=3.5.1
ENV TS_USER_HOME_DIRECTORY=/home/teamspeak
ENV TS_DIRECTORY=${TS_USER_HOME_DIRECTORY}/app
ENV TS_USER=teamspeak

#
## Installation des dependances necessaires
#
RUN apt-get update -qy \
&& apt-get upgrade -qy \
&& apt-get install -qy wget \
&& apt-get install -qy tar \
&& apt-get install -qy bzip2

#
## Creation enviromment Teamspeak , user , group , changements droits de repo
#
RUN groupadd -r ${TS_USER} \
&& useradd -rmg ${TS_USER} -d ${TS_USER_HOME_DIRECTORY} ${TS_USER} \
&& mkdir -p ${TS_DIRECTORY} \
&& chown -R ${TS_USER}: ${TS_DIRECTORY}

#
## Downloading TS serveur 
#

RUN wget --quiet http://dl.4players.de/ts/releases/${TS_RELEASE}/teamspeak3-server_linux_amd64-${TS_RELEASE}.tar.bz2 \
&& tar jxvf teamspeak3-server_linux_amd64-${TS_RELEASE}.tar.bz2 \
&& mv teamspeak3-server_linux_amd64/* ${TS_DIRECTORY} \
&& rm -rf /teamspeak.tar.bz2 /teamspeak3-server_linux_amd64/

#
## Ouverture du port 9987 communication vocale , 10011 serveur query , 30033 transport de fichiers
#
EXPOSE 9987/udp 10011 30033

#
## On se place dans le repo et on execute le script par defaut de ts
#

WORKDIR ${TS_DIRECTORY}

ENTRYPOINT ["bash", "ts3server_minimal_runscript.sh"]

USER teamspeak
