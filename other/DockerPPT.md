# Docker Workshop
## what is docker
- a containerization runtime
- create, deploy and run applications

## containers
- lightweight alternative to a virtual machine
- shares the kernel w/ host
- advantages:
	- consistent
	- portable
	- __single-process oriented__
	- packaged dependencies
	- efficient

## workflow
- dockers can be deployed to other compute services

## anatomy of docker deployment
- consider runtime
- build the container
- run the container
- inter-process communication
- orchestration


## runtime containers:
- python
- redit / postgres
- node

## Dockerfile
- commands: from, arg, run, workdir, copy, cmd
- from: base image you're using
- progressive caching system
- dockerfiles are cached
- if you change something near the end of the dockerfile, it will only run that line and below

## `docker build [options] PATH | URL | -`
- `-t` tag of container
- `-f` location of dockerfile
- `--cache-from` specifies the image to use as a cache while building
- this can be used to accelerate the building process
- `PATH` specifies the context ot build the container form

## `docker run [OPTIONS] IMAGE [COMMAND] [ARG]`
- `-d` runs the container as a daemon (in the background)
- `-e` allows setting environment variables for container runtime
- `-it` allows connecting to container w/ a tty instance
- `--rm` removes container after process has exited
- `--gpus` passes GPUs to a container (w/ appropriate runtime installed)
	- `all, int(0-inf)`
- `IMAGE` name specifed w/ -t
- `COMMAND` you can pass an optional command to the container


## EX:
```
FROM ubuntuu
ARG DEBIAN_FRONTEND=noninteractive
RUN sudo apt update && sudo apt install screenfetch
```

## Communicationt technologies
- usually you have multiple containers talking to each other
- messages queues:
	- network equivalent of data structures
	- containers can put data in the queue or take it out. 
	- FIFO
- traditional HTTP/TCP/UDP
- databases
- shared filesystem

## Orchestration
- Podman/Portainer: UIs for management
- kubernetes/k8s: cluster scale orchestration
- docker compose: single machine cli orchestration

## Docker Compose
### layout:
- services
	- containers
		- build
			- context
			- dockerfile
		- image
		- volumes
		- ports
		- env_file

## takeaways
- everybody uses docker
- docker is great for horizontal scaling, very fast
- allows teams to do their best work

		
