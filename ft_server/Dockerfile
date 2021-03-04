#get image
FROM 	debian:buster

# install tools
RUN		set -ex \
		&& apt-get update && apt-get install -y --no-install-recommends wget curl vim openssl \
			nginx \
			mariadb-server mariadb-client \
			php-cgi php-common php-fpm php-pear php-mbstring php-zip php-net-socket php-gd php-xml-util php-gettext php-mysql php-bcmath; \
#apt -getのcache削除
		rm -rf /var/lib/apt/lists/*;
#mysql設定

RUN 	service mysql start \
		&& mysql -e "CREATE DATABASE wpdb;" \
		&& mysql -e "CREATE USER 'wpuser'@'localhost' identified by 'dbpassword';" \
		&& mysql -e "GRANT ALL ON wpdb.* TO 'wpuser'@'localhost';" \
		&& mysql -e "flush privileges;"

# wordpress 設定
WORKDIR /var/www/html
RUN 	wget --no-check-certificate https://wordpress.org/latest.tar.gz \
		&& tar -xvzf latest.tar.gz \
		&& rm latest.tar.gz;
WORKDIR /var/www/html/wordpress
COPY	./srcs/wp-config.php /var/www/html/wordpress/
COPY 	./srcs/php.ini /etc/php/7.3/fpm/
COPY 	./srcs/default.tmpl /etc/nginx/sites-available/
# ssl key設定
RUN 	mkdir /etc/nginx/ssl
WORKDIR /etc/nginx/ssl
RUN 	openssl req -newkey rsa:2048 \
		-x509 \
		-sha256 \
		-days 3650 \
		-nodes \
		-out /etc/nginx/ssl/wordpress.crt \
		-keyout /etc/nginx/ssl/wordpress.key \
		-subj "/C=JA/ST=Tokyo/L=Urayasu/O=/OU=/CN="; 

# phpmyadmin ダウンロード
WORKDIR /var/www/html
RUN		wget --no-check-certificate https://files.phpmyadmin.net/phpMyAdmin/5.0.4/phpMyAdmin-5.0.4-all-languages.tar.gz \
		&& tar -xvf phpMyAdmin-5.0.4-all-languages.tar.gz \
		&& rm phpMyAdmin-5.0.4-all-languages.tar.gz \
		&& mv phpMyAdmin-5.0.4-all-languages phpMyAdmin;

RUN		wget --no-check-certificate https://github.com/progrium/entrykit/releases/download/v0.4.0/entrykit_0.4.0_Linux_x86_64.tgz \
		&& tar -xvf entrykit_0.4.0_Linux_x86_64.tgz \
		&& rm entrykit_0.4.0_Linux_x86_64.tgz \
		&& mv entrykit /bin/entrykit \
		&& chmod +x /bin/entrykit \
		&& entrykit --symlink ;
		
WORKDIR /var/www/html/phpMyAdmin
RUN 	cp config.sample.inc.php config.inc.php;

RUN		chown -R www-data:www-data /var/www/html/; 
COPY	./srcs/service_start.sh /tmp/
RUN		chmod a+x /tmp/service_start.sh;
WORKDIR /

ENTRYPOINT [ "render", "/etc/nginx/sites-available/default", "--", "bash", "/tmp/service_start.sh" ]
# keep move
#CMD		tail -f /dev/null
