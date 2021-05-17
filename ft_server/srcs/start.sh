# Generate website folder & create index.php & move html file
mkdir /var/www/localhost && touch /var/www/localhost/index.php
echo "<?php phpinfo(); ?>" >> /var/www/localhost/index.php
mv ./tmp/index.html /var/www/localhost/index.html

# access permission
chown -R www-data /var/www/*
chmod -R 755 /var/www/*

# SSL protocol
mkdir /etc/nginx/ssl
openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes -out /etc/nginx/ssl/localhost.pem -keyout /etc/nginx/ssl/localhost.key -subj "/C=NL/ST=Netherlands/L=Amsterdam/O=Codam/OU=icikrikc/CN=localhost"
openssl rsa -noout -text -in /etc/nginx/ssl/localhost.key

# Configure nginx
mv ./tmp/nginx-conf /etc/nginx/sites-available/localhost
ln -s /etc/nginx/sites-available/localhost /etc/nginx/sites-enabled/localhost
rm -rf /etc/nginx/sites-enabled/default


# php myadminß
wget https://files.phpmyadmin.net/phpMyAdmin/4.9.4/phpMyAdmin-4.9.4-all-languages.zip
unzip phpMyAdmin-4.9.4-all-languages.zip -d /var/www/localhost/
mv /var/www/localhost/phpMyAdmin-4.9.4-all-languages /var/www/localhost/phpmyadmin
mv ./tmp/config.inc.php /var/www/localhost/phpmyadmin/config.inc.php

# wordpress
wget -c https://wordpress.org/latest.tar.gz
tar -xvzf latest.tar.gz
mv wordpress/ /var/www/localhost
mv ./tmp/wp-config.php /var/www/localhost/wordpress/


# mysql
service mysql start
mysql < /var/www/wordpress.sql
curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
chmod +x wp-cli.phar
mv wp-cli.phar /usr/local/bin/wp
cd /var/www/ 
mkdir wordpress
cd wordpress
wp core download --allow-root
wp config create --dbname=wordpress --dbuser=user --dbpass=password --dbhost=localhost --allow-root
wp core install --url=localhost/wordpress/ --title=BoringWebsite --admin_user=user --admin_password=password --admin_email=info@example.com --allow-root


# start php and nginx
service php7.3-fpm start
service nginx start

bash
