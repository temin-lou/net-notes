# 用ssh公网建立通道方法
# 需求
    1. 最好是公网服务器
    2. 引用Nginx代理服务功能
# 配置
    Nginx 配置：
    ```
    upstream tunnel {
        server 127.0.0.1:8558;
    }

    server {
        listen 80;
        server_name test.mycom.org;

        location / {
            proxy_set_header X-Real-IP $remote_addr;
            proxy_set_header X-Forwarded-For $proxy_add_x_forwarded_for;
            proxy_set_header Host $http_host;
            proxy_redirect off;

            proxy_pass http://tunnel;
        }
    }
    ```
# 通道
    本地局网与公网服务器，使用ssh开通通道，命令:
    ```
    ssh -vnNT -R 服务器端口:localhost:本地端口 服务器用户名@服务器 IP 地址
    ```
    例子
    ```
    ssh -vnNT -R 8558:localhost:3000 root@202.106.40.68
    ```
