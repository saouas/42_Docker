FROM ruby:2.5.1

ENV APP_HOME /opt/app

MAINTAINER saouas <saouas@student.42.fr>

RUN apt-get -y update \
&& apt-get -y upgrade \
&& apt-get install -y build-essential \
&& apt-get install -y libpq-dev \
&& apt-get install -y sqlite3 \
&& apt-get install -y nodejs
RUN gem install rails
RUN gem install bundler
RUN gem update

ONBUILD RUN mkdir $APP_HOME
ONBUILD COPY app/ $APP_HOME
ONBUILD WORKDIR $APP_HOME

ONBUILD RUN bundle install 
ONBUILD RUN rake db:migrate
ONBUILD RUN rake db:seed
