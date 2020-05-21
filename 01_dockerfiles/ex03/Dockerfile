#Upgrade config of the machine to run as well gitlab_ce:
##VBoxManage modifyvm Char --cpus 2
####VBoxManage modifyvm Char --memory 4096

FROM ubuntu:18.04
MAINTAINER <saouas@student.42.fr>

#install depends
RUN apt-get update
RUN apt-get upgrade -y
RUN apt-get install -y curl openssh-server tzdata ca-certificates
RUN curl -s https://packages.gitlab.com/install/repositories/gitlab/gitlab-ce/script.deb.sh | bash
RUN apt-get install -y gitlab-ce

#config the gitlab.rb
RUN echo "letsencrypt['enable'] = false" > /etc/gitlab/gitlab.rb
RUN echo "nginx['ssl_certificate'] = \"/etc/gitlab/ssl/gitlab.example.com.crt\"" >> /etc/gitlab/gitlab.rb
RUN echo "nginx['ssl_certificate_key'] = \"/etc/gitlab/ssl/gitlab.example.com.key\"" >> /etc/gitlab/gitlab.rb
RUN echo "external_url 'https://gitlab.example.com'" >> /etc/gitlab/gitlab.rb

#Generating the ssl_certificate
RUN openssl req \
	   -subj "/C=FR/ST=PARIS/L=PARIS/O=Unknow/CN=www.example.com" \
       -newkey rsa:4096 -nodes -keyout gitlab.example.com.key \
       -x509 -days 365 -out gitlab.example.com.crt
RUN mkdir -p /etc/gitlab/ssl && chmod 700 /etc/gitlab/ssl && cp gitlab.example.com.key gitlab.example.com.crt /etc/gitlab/ssl/


#Launch on ENTRYPOINT  sshd daemon and gitlab-ctl + logs
ENTRYPOINT service ssh start && (/opt/gitlab/embedded/bin/runsvdir-start &) && gitlab-ctl reconfigure && gitlab-ctl tail

EXPOSE 80 443 22

# git config --global http.sslVerify false 
# If personnal Computer :Create you ssh key and past it into gitlab keys manager
#Then edit your sshd_config like this : 
###Hostname 192.168.99.100
###User git
###Port 2222
###IdentityFile ~/.ssh/id_rsa.pub
###PreferredAuthentications publickey
## local copy of pbcopy < ~/.ssh/id_rsa.pub
#######TO RUN : docker run --name gitlab-ce --rm -it -p 80:80 -p 2222:22 -p 443:443 gitlab
