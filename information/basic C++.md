# C++ 컴파일 과정

<img width="314" height="503" alt="화면 캡처 2025-07-17 181554" src="https://github.com/user-attachments/assets/3454d3ff-ee2d-4130-bc26-28a4568d4af1" />

1. 먼저 모든 소스 코드와 헤더 파일이 전처리기를 거친다.

(# include ~ # define)

이 과정에서 오류가 일어나면 멈춘다. (전처리 과정 오류)

2. 전처리기의 output(expnded source file)이 C++ 컴파일러를 거친다.

이 과정에서 syntax 오류가 있으면 멈춘다. (컴파일 과정 오류)

Object file이 생성된다.

3. Linker가 object file 들을 link 해준다.

이 과정에서 오류가 일어날 수 있다. (링크 과정 오류)

<img width="1922" height="1140" alt="IMG_0182" src="https://github.com/user-attachments/assets/a0e9c60d-5d2c-4349-9b3a-8900340c692b" />

# C++ 전처리기 기능

특정 전처리기 directives를 실행한다.

(# include <library> , # include "specificfile.h")

해당 파일의 전체 텍스트를 불러온다.

(# define LIMIT 100 // 매크로. # define AREA(L, W) (L * W) // 매크로 함수)

# cpp 파일과 헤더 파일의 분리

헤더 파일은 class와 함수의 선언을 담고 있다.

만약 모든 코드가 한 곳에 있다면, 컴파일러는 위에서 아래 방향으로 진행하기 때문에 정의를 위쪽에 해야 한다.

모두 같은 file에 define을 해놓는 건 매우 annoying 한 일이다.

## 헤더 파일의 이점

class의 기능을 한눈에 볼 수 있게 한다.

구현과 기능을 분리하는 디자인

헤더는 거의 변하지 않기에, recompilation을 줄여준다,

## 헤더 파일의 단점

더 많은 파일을 필요로 한다.

헤더와 cpp 파일을 왔다갔다 해야 한다.

# C++ 클래스 생성자 (constructor)

initializer는 default value를 주지 않고 바로 초기화한다.

만약 const를 주고 싶다면 initializer로 해야 한다.
