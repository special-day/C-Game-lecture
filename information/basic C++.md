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

# C++ 클래스 소멸자 (destructor)

클래스 객체가 소멸될 때 clean-up 할 내용을 담는다.

# C++ memory

stack memory와 heap memory가 있다.

프로그램이 실행되면 OS는 메모리의 여러 공간에 접근할 수 있도록 한다.

우리가 조작할 수 있는 메모리는 stack과 heap memory이다.

둘 다 RAM에 저장되고, 차이는 OS가 실행 시점에 결정된다.

## Stack / Heap memory

둘 다 요청하면 메모리를 준다.

차이점은 다음과 같다.

- 사이즈 (heap이 더 크다)
- 메모리 할당 방법
- 메모리 할당 속도 (일반적으로 stack이 더 빠르다)
- 메모리 요청 방법 (문법 차이)
- 자동 deallocate 여부 (stack은 scope를 빠져나가면 자동으로 해제, heap은 사용자가 해제해 줘야 한다)

```
	Int val = 5;	// stack
	Int* hval = new int;	// heap
	*hval = 5;

	Int a[5];		// stack
	Int* ha = new int[5];	// heap
	Ha[3] = 10;

	MyClass c(args);		// stack
	// heap allocation with new
	MyClass * hc = new MyClass(args);
```

## Stack memory

미리 정해진 사이즈(few megabytes)를 가진다.

사이즈가 넘쳐서 오버플로우 되기 쉽다.

new가 없는 local variables는 default로 stack에 할당된다.

(program function calls / return addresses 도 stack에 할당된다)

static memory이다.

compile time에 사이즈를 알 수 있어야 한다.

}를 만나면 stack에 할당된 데이터들이 역순으로 deallocate 된다.

## Heap memory

stack보다 사용 가능한 메모리 크기가 크다.

New 키워드를 통해 할당된다. (내부적으로 C의 malloc 함수 호출)

연속적인 chunk of memory를 찾아서 그것의 포인터를 반환한다.

(해당 과정은 복잡하고 비용이 많이 든다)

memory를 포인터로 접근할 수 있다.

(포인터 그 자체는 stack에 저장된다. heap의 주소를 가리킬 뿐.)

}를 만나면 스택의 데이터는 deallocate 되지만, heap memory는 여전히 할당되어 있다.

따라서 사용자가 임의로 해제 해줘야 한다. (delete 키워드)

### speed 차이 이유

new의 기저에 있는 malloc의 로직과, delete의 기저에 있는 free의 로직은 매우 복잡하다.

그래서 stack과 heap 메모리 이용에 speed 차이가 난다.

Just remember

- Stack = Fast & Limited
- Heap = Slow & Larger

# C++ 포인터

메모리의 주소를 저장한다.

포인터 변수를 수정하면 가리킨 것의 '주소'가 수정된다.

가리키는 데이터를 변경하려면 dereference(역참조) 해야 한다.

'raw' 포인터는 매우 unsafe 하다.

- & = 'address of'
- \* = 'dereference'

# C++ 배열 / 포인터

배열의 이름은 주소이다.

따라서 포인터로 가리킬 수 있다.

```
// arr[n] = *(arr+n)
// n[arr] = *(n+arr)
// (arr+n) = &(arr[n])
```

# 포인터 사용 이유

1. 상속(inheritance) 사용을 위해서 필수
2. pass by value vs by reference
3. 크기가 큰 데이터를 가리킬 때 사용

# C++ 레퍼런스 변수

'안전한 포인터'

\* 대신 &를 사용한다.

레퍼런스는 반드시 존재하는 데이터를 가리켜야 한다.

## Pass by value / reference

C++은 default로 value를 반환한다.

하지만 PBV는 복사 비용이 발생한다.

또한 값을 수정하고 싶을 수 있다.

포인터 또는 레퍼런스로 PBR이 가능하고, 이를 통해 위 문제점을 해결 가능하다.

(포인터가 nullptr인 경우 역참조하면 오류 발생하니 주의가 필요하다. 또한 가리키는 자료형이 다르다면 포인터 변수의 자료형으로 강제 캐스팅해 버리므로 주의가 필요하다.)

## Pass by const reference

데이터를 수정하지 않겠다는 의미이다.

원본 데이터의 크기가 클 경우에도 8-byte 짜리 reference만 주면 된다.

(8바이트 보다 작으면 그냥 넘기는 게 낫다.)

# C++ / RAII (resource acquisition is initialization)

자동적으로 memory/resource를 관리하여 객체(의 생명주기)와 묶는다.

## RAII 구현

각각의 resource를 클래스로 묶는다.

클래스 생성자는 resource를 얻고, 초기화한다.

클래스 소멸자는 resource를 해제한다.

RAII 객체를 chain 할 수도 있다.

## C++ smart pointers

데이터 타입에 대해 own RAII 클래스를 생성해 준다.

C++은 여러 smart pointers를 가진다.

우리는 std::shared_ptr\<T>를 사용할 것이다.

### shared pointer

'reference counted pointer'

내부적으로 일어나는 일은 다음과 같다.
- internal counter가 생성자에서 1을 설정한다.
- shared_ptr이 복사될 때마다 counter가 1씩 증가한다.
- 소멸될 때마다 counter가 1씩 감소한다.
- count가 0이 되면, resouce가 deallocate 된다.


# How to allocate / pass data?

1. 가능하다면 stack을 이용한다.
   - small, local variables
   - pass variables by const reference if size > 8 bytes
2. 힙 메모리가 필요하다면, smart ptr를 사용한다.
   - std::shared_ptr\<T> myBigData;
   - std::shared_ptr\<Base> = std::make_shared\<Derived> ();
3. 정말 어쩔 수 없이 필요한 경우에만 raw pointers / new 를 사용한다. 
