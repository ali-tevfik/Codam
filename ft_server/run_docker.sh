docker build -t abc .
docker run -p 80:80 -p 443:443 -it --rm abc
