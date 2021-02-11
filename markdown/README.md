![image](https://img.shields.io/badge/-Markdown-red) ![image](https://img.shields.io/badge/-HowToUse-yellow) ![image](https://img.shields.io/badge/-beginner-brightgreen)

# :point_right: #0 제목(Header)<a name="TOP"></a>
``` C
# 제목1
## 제목2
### 제목3
#### 제목4
##### 제목5
###### 제목6
```
# 제목1
## 제목2
### 제목3
#### 제목4
##### 제목5
###### 제목6


# :point_right: #1 강조(Emphasis)
``` java
*기울게*
_기울게_
**두껍게**
__두껍게__
~~취소선~~
***기울게 두껍게***
```
*기울게*
_기울게_
**두껍게**
__두껍게__
~~취소선~~
***기울게 두껍게***
- 마크다운은 기본적으로 밑줄을 인식하지 않는다. `<u>밑줄</u>`

# :point_right: #2 테이블
```zsh
| Tables   |      Are      |  Cool |
|:---------|:-------------:|------:|
| col 1 is | left-aligned  | $1600 |
| col 2 is |    centered   |   $12 |
| col 3 is | right-aligned |    $1 |
```
| Tables   |      Are      |  Cool |
|:---------|:-------------:|------:|
| colum1   | left-aligned  | $1600 |
| colu2    |    centered   |   $12 |
| col3     | right-aligned |    $1 |
- ':'에 따라서 정렬방식이 바뀐다.

# :point_right: #3 개행(New line)
```python
띄어(엔터)(엔터)
쓰기
```
띄어

쓰기
- 마크다운은 기본적으로 강제개행을 인식하지 않는다. 강제개행을 인식하는 방법은 있지만 가독성 문제로 권장되지 않는다고 한다. `<br>`
# :point_right: #4 수평선(horizental line)
```perl
---
```
---

# :point_right: #5 목록(List)
```ruby
1. 푹 자기
2. 맛있는 거 먹기
3. 재밌는 거 하기

- 오늘 해야 하는 일
  - 아침 먹고 할 것
    - 양치하기
    + 운동하기
    * 프로그래밍 공부하기
    
- 아침 먹고 해야 하는 일
  1. 양치하기 
  2. 운동하기
  3. 프로그래밍 공부하기
```
1. 푹 자기
2. 맛있는 거 먹기
3. 재밌는 거 하기

- 오늘 해야 하는 일
  - 아침 먹고 할 것
    - 양치하기
    + 운동하기
    * 프로그래밍 공부하기
    
- 아침 먹고 해야 하는 일
  1. 양치하기 
  2. 운동하기
  3. 프로그래밍 공부하기

# :point_right: #6 코드(Code)
```awk
코드 한 줄 
`system.out.println("Hello");`

코드 여러 줄
```c
#include <unistd.h>
void putchar(char character)
{
  write(1, &character, 1);
}
.```  //.무시
```
코드 한 줄

`system.out.println("Hello");`


코드 여러 줄
```c
#include <unistd.h>
void putchar(char character)
{
  write(1, &character, 1);
}
```
# :point_right: #7 To do list(check)
```swift
### - 오늘 해야 할 일
- [x] 아침에 일어나기
- [x] 아침 밥 맛있게 먹기
- [ ] 운동 하기
  -[ ] 이두 운동 하기
  -[ ] 500m 달리기
```
### - 오늘 해야 할 일
- [x] 아침에 일어나기
- [x] 아침 밥 맛있게 먹기
- [ ] 운동 하기
  - [ ] 이두 운동 하기
  - [ ] 500m 달리기

# :point_right: #8 인용문(Quote)
```scala
> 초밥 한 입 
>> 존맛탱 ㅠㅠ...
```

> 초밥 한 입 
>> 존맛탱 ㅠㅠ... 
  
# :point_right: #9 링크(New line)
``` javascript
[google](http://www.google.com)
[google](http://www.google.com "Don't touch this!!")
www.google.com
[ :point_right: 제목(Header)](#1제목(Header) "Move #1 제목(Header)")
[Go To TOP](#TOP)
```
[google](http://www.google.com)

[google](http://www.google.com "Don't touch this!!")

www.google.com

[ :point_right: 제목(Header)](# :point_right: #0 제목(Header)<a name="TOP"></a> "Move #1 제목(Header)")
[heading-1](#heading-1 "Goto heading-1")

[Go To TOP](#TOP)

# :point_right: #10 이미지(New line)
```bash
![pixabay](https://cdn.pixabay.com/photo/2021/02/01/13/37/cars-5970663_960_720.png "제목은 선택사항")
<img src="https://cdn.pixabay.com/photo/2021/02/01/13/37/cars-5970663_960_720.png" width="40%" height="30%" title="제목은 선택사항" alt="pixabay"></img>
```
![pixabay](https://cdn.pixabay.com/photo/2021/02/01/13/37/cars-5970663_960_720.png "제목은 선택사항")
<img src="https://cdn.pixabay.com/photo/2021/02/01/13/37/cars-5970663_960_720.png" width="40%" height="30%" title="제목은 선택사항" alt="pixabay"></img>

# :sushi: 마크 다운 작성 시 유용한 프로그램
- 마크다운 이모찌: https://www.webfx.com/tools/emoji-cheat-sheet/
- table 작성표: https://www.tablesgenerator.com/markdown_tables
- 깃허브 아이콘 만들기: https://img.shields.io/badge/-beginner-brightgreen
- 간단한 이미지 그리기: https://www.autodraw.com/
- 도식화 하기: https://app.diagrams.net/

# :memo: 참고자료
- https://github.com/tchapi/markdown-cheatsheet#TOP
- https://namu.wiki/w/%EB%A7%88%ED%81%AC%EB%8B%A4%EC%9A%B4
- https://gist.github.com/ihoneymon/652be052a0727ad59601
