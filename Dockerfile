# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yura <yura@student.42tokyo.jp>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/11 20:15:38 by yura              #+#    #+#              #
#    Updated: 2020/10/11 20:31:55 by yura             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM		debian:buster

EXPOSE		80
EXPOSE		443

RUN			apt-get update && \
			apt-get install -y --no-install-recommends \
				mariadb-server \
				nginx \
				php7.3-fpm \
				php-mysql \
				wget \
				openssl

WORKDIR		/tmp


# getting WordPress from the internet
RUN			wget --no-check-certificate https://wordpress.org/latest.tar.gz \
			&& tar xfv latest.tar.gz \
			&& mv wordpress /var/www/html/

# copying WordPress config
COPY		./srcs/wp-config.php /var/www/html/wordpress/wp-config.php

# getting phpMyAdmin
RUN			wget --no-check-certificate https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz \
			&& tar xfv phpMyAdmin-5.0.2-all-languages.tar.gz \
			&& mv phpMyAdmin-5.0.2-all-languages phpmyadmin \
			&& mv phpmyadmin /var/www/html/

# clean tar file
RUN			rm -f latest.tar.gz phpMyAdmin-5.0.2-all-languages.tar.gz

# setting mysql user and database
RUN			service mysql start \
			&& mysql -e "create user 'wp'@'localhost' identified by 'wp';" \
			&& mysql -e "create database wp;" \
			&& mysql -e "grant all on wp.* to 'wp'@'localhost';" \
			&& mysql -e "exit"

# setting ssl
RUN			mkdir /etc/nginx/ssl
WORKDIR		/etc/nginx/ssl
			# create private key
RUN			openssl genrsa -out private.key 2048 \
			# create certificate signing request
			&& openssl req -new -key private.key -out server.csr \
			-subj "/C=JP/ST=Tokyo/L=Roppongi/O=42tokyo/OU=/CN=localhost" \
			# create server certificate(CRT) file
			&& openssl x509 -days 3650 -req -signkey private.key -in server.csr -out server.crt

# setting entrykit (rendering config file)
RUN			wget --no-check-certificate https://github.com/progrium/entrykit/releases/download/v0.4.0/entrykit_0.4.0_Linux_x86_64.tgz \
			&& tar xfv entrykit_0.4.0_Linux_x86_64.tgz \
			&& mv entrykit /bin/entrykit \
			&& entrykit --symlink \
			&& rm -f entrykit_0.4.0_Linux_x86_64.tgz

# copying nginx default config file containing ssh, redirect config
COPY		./srcs/default.tmpl /etc/nginx/sites-available/default.tmpl

# setting shell script which start services like nginx, sql, php
COPY		./srcs/start_services.sh /tmp/start_services.sh
WORKDIR		/tmp
RUN			chmod a+x start_services.sh

ENTRYPOINT	["render", "/etc/nginx/sites-available/default", "--", "bash", "/tmp/start_services.sh"]
