FROM debian:buster


RUN apt-get update &&\
                    apt-get -y install\
                    wget\
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

# Copy necessary files to your image
COPY ./srcs/start.sh ./
COPY ./srcs/index.html ./tmp/index.html
COPY ./srcs/nginx-conf ./tmp/nginx-conf
COPY ./srcs/config.inc.php ./tmp/config.inc.php
COPY ./srcs/wordpress.sql /var/www/
COPY ./srcs/wp-config.php ./tmp/wp-config.php
EXPOSE 80 443


ENTRYPOINT ["sh","start.sh"]
