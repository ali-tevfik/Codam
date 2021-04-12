FROM debian:buster

RUN apt-get update && apt-get upgrade -y

RUN apt-get -y install wget\
                        unzip\
                        nginx\
                        mariadb-server\
                        php-fpm\
                        php-mysql\
                        php-mbstring\
                        php-dev\
                        php-gd\
                        php-pear\
                        php-zip\
                        php-xml\
                        php-curl -y

COPY srcs/start.sh ./
COPY srcs/index.html ./tmp.index.html
COPY srcs/nginx-conf ./tmp/nginx-conf
COPY srcs/config.inc.php ./tmp/config.inc.php
COPY srcs/start.sh /bin/
COPY srcs/wordpress.sql ./var/www/

EXPOSE 80 443
CMD ["sh", "srcs/start.sh"]