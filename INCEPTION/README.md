<div align="center">
  <img src="https://github.com/S0YKIM/42-SEOUL/blob/main/INCEPTION/images/docker%20logo.webp" height="128px" alt="inception" >
  <h1>Inception</h1>
  <p> Build your own Docker images </p>
</div>
</br>

## 🎬 Preview
![](https://github.com/S0YKIM/42-SEOUL/blob/main/INCEPTION/images/%EC%8A%A4%ED%81%AC%EB%A6%B0%EC%83%B7%202023-03-31%20%EC%98%A4%ED%9B%84%2012.47.21.png)
</br></br></br>

- This project aims to broaden your knowledge of `system administration` by using Docker.
- You will virtualize several Docker images, creating them in your new personal virtual machine.

</br>

## 🚀 Notes

[🔗 노션 정리](https://www.notion.so/Inception-7f84d764bf764bfa8f9fce660f4bf58d?pvs=4)

</br>

## 🚧 Structure
```
./
├── setup/					        # shell scripts to setup virtual machine
├── srcs/		                # docker compose file and dockerfiles
│   └── requirements/				# dockerfiles for each container
└── Makefile                # build docker images and run containers
```

</br>

## ❓ Usage

### 🖐️ Build Docker Images
```
$ make build
```

### 🖐️ Run containers
```
$ make
```

### 🖐️ Execute
```
$ ./inception
```

### 🖐️ Manipulate container
```
$ docker exec [-it] [CONTAINER NAME] /bin/sh
$ docker exec [-it] [CONTAINER NAME] /bin/bash
```

### 🖐️ Connect to WordPress website
```
https://localhost:443
```
</br>

## 👀 References
[Docker docs](https://docs.docker.com/get-started/overview/)
</br></br></br>
