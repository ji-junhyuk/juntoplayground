# Ch1.자바 시작하기
- 확인문제
	- Q1: JRE에는 컴파일러가 포함되어 있지 않다.
	- Q2: JVM은 운영체제에 독립적이지 않다. 
	- Q3: 자바 소스 파일을 작성한다 -> javac.exe로 바이트 코드 파일(~.class)를 생성한다. -> java.exe로 JVM을 구동시킨다. -> JVM은 main()메소드를 찾아 메소드 블록을 실행시킨다.
	- Q4: 주석은 문자열 안에도 작성할 수 없다.
	- Q5: <!-- ... --> 는 HTML, XML에 사용되는 주석
	- Q6: .metadata 이클립스의 실행과 관련된 선호 옵션들이 저장되는 디렉토리이다.

# Ch2.변수와 타입
- 변수(Variable)는 값을 저장할 수 있는 메모리의 공간을 의미한다. 하나의 값만 저장할 수 있다.
- 리터럴(Literal)이란 소스 코드 내에서 직접 입력된 값을 말한다.
- 이스케이프(escape)문자란 역슬래쉬(\)가 붙은 문자로 특수한 용도로 사용된다.
- 문자열 리터럴이란 큰 따옴표로 묶은 텍스트를 말한다. 문자열 리터럴을 저장할 수 있는 타입은 String 하나뿐이다.
- 변수는 선언된 블록 내에서만 사용이 가능하다.

- String은 기본타입이 아니다. String은 클래스 타입이고 String 변수는 참조 변수이다. 문자열을 String 변수에 대입하면 문자열이 변수에 직접 저장되는 것이 아니라 String 객체가 생성되고, String 변수는 String 객체의 번지를 참조하게 된다. 
- char 타입 변수에 어떤 문자를 대입하지 않고 단순히 초기화를 목적으로 빈 문자를 대입하면 '' 컴파일 에러가 발생한다. 그렇기에 공백 하나를 포함해서 초기화해야 한다. 하지만 String 변수는 큰 따옴표 두개를 연달아 붙인 빈 문자를 대입해도 괜찮다.
- 캐스팅(Casting, 강제타입변환)이란 강제적으로 큰 데이터 타입을 작은 데이터 타입으로 쪼개어서 저장하는 것을 말한다.
- 확인문제
	- Q1: 변수는 초기값이 저장되지 않은 상태에서 읽을 수 없다
	- Q2: 변수 이름으로 사용가능한 것(modelName, $value, _ age), (class int 불가)
	- Q3: byte, char, short, int, long, double, float, boolean
	- Q4: 타입(int, double), 변수 이름(age, price), 리터럴(10, 3.14)
	- Q5: char타입은 양수만 저장할 수 있고 short 타입은 음수, 양수 가능. 따라서 short shortValue = charValue 컴파일 에러 발생.
	- Q6: 문자열 변수(String)을 char 타입으로 변환할 수 없다.
	- Q7: char 타입의 경우 '' 초기화할 수 없다. 단 문자열의  경우 "" 초기화할 수 있음.
	- Q8: int 타입 이하의 정수를 산술연산 했을 경우 int가 된다. 따라서 byte로 받을 수 없다.
	
# Ch3.연산자
- String 타입의 문자열을 비교할 때에는 대소 연산자(<, <=, >, >=)를 사용할 수 없고, 동등 비교 연산자(==, !=)는 사용할 수 있으나 문자열이 같은지, 다른지를 비교하는 용도로는 사용되지 않는다.
- 자바는 문자열 리터럴이 동일하다면 동일한 String 객체를 참조하도록 되어있다. new로 생성했다면 새로운 String은 주소값을 가지고 있다.
- 객체의 문자열만을 비교하고 싶다면 == 연산자 대신 equals() 메소드를 사용해야 한다.
- 확인문제
	- Q1: 연산식은 반드시 하나의 값을 산출한다. 연산자 수가 많아도 두 개 이상의 값을 산출하는 연산식은 없다.
	- Q2: z == 31;
	- Q3: 가 !(False)는 True
	- Q4: pencils / student, pencils % student
	- Q5: value - (value % 300)
	- Q6: ((Double)lengthTop + area) * height / 2
	- Q7: True, False
	- Q8: Double.isNaN(z) // 메소드 이용

# Ch4.조건문과 반복문
- 확인문제
	- Q1: (if), (switch), (for), (while), (do-while)
	- Q2: switch문에서 사용할 수 있는 변수의 타입에 string도 가능하다.
	- Q3: int sum = 0; i = 0; while (i <= 100) if (i % 3 == 0) sum += i;
	- Q4: int a = 0; int b = 0; while (a + b != 5) { a = (int)(Math.random() * 6) + 1; ... System.out.println("(" + num1 + ", " + num 2 + ")");
	- Q5: while (x <= 10) while (y <= 10) if ((4 * x) + (5 * y) == 60) System.out.println("(" + x + ", " + y + ")");
	- Q6: for (int i = 1; i <= 5; i++) for (int j = 1; j <= i; j++) System.out.println(" * ");
	- Q7: int number = scanner.nextInt(); int money = 0;
	switch (number) {
		case 1:
			System.out.print("예금액> ");
			money = scanner.nextInt();
			balance += money;
			break;
		case 2:
			System.out.print("출금액> ");
			money = scanner.nextInt();
			balance -= money;
			break;
		case 3:
			System.out.println("잔고> " + balance);
			break;
		case 4:
			run = false;
			break;
	}

# Ch5.참조타입
- 기본 타입인 byte, char, short, int, long, float, double, boolean을 이용해서 선언된 별수는 실제 값을 변수 안에 저장하지만, 참조 타입인 배열, 열거, 클래스, 인터페이스를 이용해서 선언된 변수는 메모리의 번지를 값으로 갖는다. 번지를 통해 객체를 참조한다는 뜻에서 참조타입이라고 부른다.
- 변수는 스택 영역에서 생성되고 객체는 힙 영역에서 생성된다.
- 메모리 사용 영역
	- 메소드 영역은 JVM이 시작할 때 생성되고 모든 스레드가 공유하는 영역이다.
	- 힙 영역은 객체와 배열이 생성되는 영역이다.
	- JVM 스택 영역은 각 스레드마다 하나씩 존재하며 스레드가 시작될 때 할당된다.
	- 배열 변수는 스택 영역에 생성되지만 실제 값을 갖는 배열은 힙 영역에 생성된다.
	- 배열 변수에는 배열의 힙 영역의 주소가 저장된다. (자바에서는 배열을 객체로 취급)
- null값도 초기값으로 사용할 수 있기 때문에 null로 초기화된 참조 변수는 스택 영역에 생성된다.
- NullPointerException, 참조 타입 변수가 null을 가지고 있을 경우, 참조 타입 변수는 사용할 수 없다. 참조 타입 변수를 사용하는 것은 곧 개체를 사용하는 것을 의미하는데, 참조할 객체가 없으므로 사용할 수가 없는 것이다.
- 문자열이 직접 변수에 저장되는 것이 아니라, 문자열은 String 객체로 생성되고 변수는 String 객체를 참조한다. 자바는 문자열 리터럴이 동일하다면 String 객체를 공유하도록 되어 있다.
- new 연산자는 힙 영역에 새로운 객체를 만들 때 사용하는 연산자로 객체 생성 연산자라고 한다.
- 배열 변수는 참조 변수에 속한다. 배열도 객체이므로 힙 영역에 생성되고, 배열 변수는 힙 영역의 배열 객체를 참조하게 된다. 참조할 배열 객체가 없다면 배열 변수는 null값으로 초기화될 수 있다.
- 배열 변수를 미리 선언한 후, 값 목록들이 나중에 결정되는 상황이라면 다음과 같이 new 연산자를 사용해서 값 목록을 지정해주면 된다. 
- new 연산자로 배열을 처음 생성할 경우, 배열은 자동적으로 기본값으로 초기화된다.
- 배열 length 필드를 읽기 위해서는 배열 변수에 .연산자를 붙이고 length를 적어주면 된다. 단, 읽기 전용이기에 값을 바꿀 수는 없다.
- 문자열은 산술연산을 할 수 없기에 Interger.parseInt() 메소드를 사용한다.
- 기본타입 배열은 각 항목에 직접 값을 갖고 있지만, 참조 타입배열은 각 항목의 객체의 번지를 가지고 있다.
- 배열은 한 번 생성하면 크기를 변경할 수 없기 때문에 더 많은 저장공간이 필요하다면 보다 큰 배열을 새로 만들고 이전 배열로부터 항목 값들을 복사해야 한다.

- 한정된 값만을 갖는 데이터 타입이 열거 타입이다.

- 확인문제
	- Q1: 참조타입은 null값으로도 초기화할 수 있다
	- Q2: 참조하는 변수나 필드가 없다면 의미 없는 개체가 되기에 이것을 쓰레기로 취급하고 JVM은 쓰레기 수집기를 실행시켜 쓰레기 객체를 힙 영역에서 자동으로 제거한다.
	- Q3: String 타입의 문자열 비교는 equals() 메소드를 이용해야 한다.
	- Q4: 2
	- Q5: boolean 타입 배열의 초기값은 false이다.
	- Q6: 3, 5
	- Q7:
	for (int i = 0; i < array.length; i++)
		if (array[i] > max)
			max = array[i];
	- Q8:
	int cnt = 0;
	for (int i = 0; i < array.length; i++)
		for (int j = 0; j < array.length; j++)
		{
			sum += array[i][j];
			cnt++;
		}
	avg = (dumble) sum / cnt;

	- Q9:
	if (selectNo == 1) {
		System.out.print("학생수> ");
		studentNum = scanner.nextInt();
		scores = new int[studentNum];
	} else if (selectNo == 2) {
		for (int i = 0; i < studentNum; i++) {
			System.out.print("socres[" + i + "] ");
			scores[i] = scanner.nextInt();
		}
	} else if (selectNo == 3) {
		for (int i = 0; i < studentNum; i++) 
			System.out.println("scores[" + i + "]: " + scores[i]);
	}
	} else if (selectNo == 4) {
		int max = 0;
		int sum = 0;
		for (int score : scores) {
			if (max < score) 
				max = score;
			sum += score;
		}
		System.out.println("최고 점수: " + max);
		System.out.println("평균 점수: " + (double)sum/scores.length);
	} else if (selectNo == 5)
		run = false;

# Ch6.클래스
- 객체란 물맂거으로 존재하거나 추상적으로 생각할 수 있는 것 중에서 자신의 속성을 가지고 있고 다른 것과 식별 가능한 것을 말한다.
- 자바는 이런 속성과 동작들을 각각 필드와 메소드라고 부른다.
- 클래스 내부의 생성자나 메소드에서 사용할 경우 단순히 필드 이름으로 읽고 변경하면 되지만, 클래스 외부에서 사용할 경우 우선적으로 클래스로부터 객체를 생성한 뒤 필드를 사용해야 한다. 그 이유는 필드는 객체에 소속된 데이터이므로 객체가 존재하지 않으면 필드도 존재하지 않기 때문이다.
- 다른 클래스에 생성자 선언이 있다면 기본 생성자를 호출해서 객체를 생성할 수 없고 Car(stirng color, int cc)를 호출해서 객체를 생성해야 한다.

# Ch7.상속
# Ch8.인터페이스
# Ch9.중첩 클래스와 중첩 인터페이스
# Ch10.예외 처리
# Ch11.기본 API 클래스
# Ch12.멀티 스레드
# Ch13.제네릭
# Ch14.람다식
# Ch15.컬렉션 프레임워크
# Ch16.스트림과 병렬처리
# Ch17.JavaFX
# Ch18.IO 기반 입출력 및 네트워킹
# Ch19.NIO 기반 입출력 및 네트워킹

