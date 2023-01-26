# 서브젝트 설명

*UNIX 신호를 이용해 데이터를 주고받는 작은 프로그램*을 만들어보는 과제였습니다.

프로세스간의 통신과 시그널, C언어 함수 구현에 대한 이해가 필요한 과제였습니다.

# 실행 방법

루트 경로에서 makefile을 실행해 주세요.

```jsx
make all
```

그 후, server 파일과 client 파일이 생성되면 server파일을 실행 시킨 후 화면에 표시된 프로세스 아이디를 확인 한 후, client 파일의 매개변수로 메시지와 함께 넘겨 실행시켜 주세요.

```jsx
./server
```

```jsx
./client [pid] [msg]
```

client 프로그램을 실행시켰을 때,

server에서 msg send!라는 메세지가, client에서 received!라는 메세지가 출력 됐다면 성공적으로 메세지가 전송된 것 입니다.

# 실행 예시
![Untitled](https://user-images.githubusercontent.com/48785968/214737337-5be27e94-e1ac-416b-bfcf-b9281aedf4e3.png)
