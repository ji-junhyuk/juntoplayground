# Ch1. Vim의 방식(Tip 1 ~ 6)
- >G : 들여쓰기
- 반값할인
|||
|---|---|
|C|c$|
|s|cl|
|S|^C|
|I|^i|
|A|$a|
|o|A<CR>
|O|kO|
- 되돌리기
|||||
|---|---|---|---|
|기능|동작|반복|되돌리기|
|내용 변경|{편집}|.|u|
|다음 문자 찾기|f{문자} / t{문자}|;|,|
|행에서 이전 문자 찾기|F / T|;|,|
|다음 일치 찾기|/패턴<CR>|n|N|
|이전 일치 찾기|?패턴<CR>|n|N|
|치환 동작하기|:s/대상/치환|&|u|
|연속 변경 실행하기|qx{변경}q|@x|u|
- :set hls // 강조 기능 활성화

# Ch2. 일반 모드(Tip 7 ~ 12)
- "지금 끼워넣기 모드를 벗어나야 하나?" 질문에 답변하기가 약간이라도 머뭇거려진다면 그 순간에 벗어나는 것을 원칙으로 하자.
- 약방향 제거: db, 정방향 제거:dw, 단어 전체 제거:daw
- <C-a> <C-x> 숫자 증가, 감소
- d2w : 두 단어 삭제, 2dw : 단어를 두 번 삭제 
- 실행 취소 히스토리를 깔끔하게 관리하는 편이 나은지, 아니면 숫자를 직접 세서 한번에 지우는 작업을 더 편하게 느끼는지는 개인의 취향이다.
- Vim의 오퍼레이터 명령
|트리거|효과|
|---|---|
|c|변경|
|d|삭제|
|y|레지스터리로 복사|
|g~|대소문자 변환|
|gu|소문자로 변환|
|gU|대문자로 변환|
|>|우측으로 탭 이동|
|<|좌측으로 탭 이동|
|=|자동 들여 쓰기|
|!|{모션}에 해당하는 행을 외부 프로그램을 사용해 여과(필터)|
- aw: 현재 단어, ap: 현재 문단, ap: 문단 전체
	- daw: 단어삭제
	- gUaw: 현재 단어 모두 대문자
	- dap: 문단 삭제
	- gUap: 문단 전체 대문자
- 팀 포프의 commentary: gc{모션}으로 주석 변환 명령 실행 가능
- gg로 파일 상단 이동, =G를 이용하면 현재 커서 위치부터 파일 끝가지 모든 내용을 들여쓰기 할 수 있다.
	- textobj-entire 플러그인 있다면 =ae로 가능
- 오퍼레이터 대기 모드 (dw명령을 실행하면 d를 누르고 w를 누르기 전 사이의 시간을 말한다)

# Ch3. 끼워넣기 모드(Tip 13 ~ 20)
- 자동완성은 끼워넣기 모드에서 사용할 수 있는 가장 고급스러운 기능이다.
- 끼워넣기 모드에서 사용 가능(Bash 쉘에서도)
	- <C-h> 앞에 잇는 글자 하나 제거하기 (=backspace)
	- <C-w> 앞에 있는 단어 하나 제거하기
	- <C-u> 행의 시작 부분까지 제거하기
- 일반 모드로 돌아가기
	- <ESC>
	- <C-[>
	- <C-o> : 끼워넣기 일반모드로 전환하기	
- CapsLock키 CTRL키와 바꾸었음
- <C-r>{레지스터} ex) yt, <C-r>0
- 즉석에서 계산하기 <C-r>=6 * 35 
- 문자 코드 이용하기 <C-V>065 (A), 문서 내에서 어떤 문자의 숫자 코드를 찾고 싶다면 ga
- 문자 뒤집기 <C-k>?I, 이중자 사용 <C-k>>>, :h disgraph-table ex)☞ = <C-k>>H
- 선택 치환 모드 = gR, 커서가 탭 공간에 있떠라도 8개의 공간이 각각의 영역으로 존재하는 것처럼 동작(실제 파일에 문자를 바로 대체하지 않고 화면에 표시되는 기준에 따라 문자 덮어씀. 바꾸기 모드에서 동작시키면 다르게 변경되는 일이 이 모드에선 그렇지 않음. 선택치환모드 권장)
- vim은 일회성으로 사용할 수 있는 바꾸기모드와 선택치환모드 제공, r{문자}, gr{문자}

# Ch4. 비주얼 모드
- viw : 단어 영엉 선택
- 고르기 모드를 자주 사용하게 되면 Vim의 고유한 기능과는 멀어지게 됨. 사용하지 말자.
- 비주얼 모드 활성화 하기
	- v: 문자 단위 비주얼 모드 활성화하기
	- V: 행 단위 비주얼 모드 활성화하기
	- <C-v>: 블록 단위 비주얼 모드 활성화하기
	- gv: 비주얼 모드에서 마지막으로 선택했던 영역 다시 선택하기
	- o : 선택 영역 중 반대쪽 끝으로 이동하기
- :set shiftwidth=4 softtabstop=4 expandtab
- vit 명령을 사용하면 태그 안에 있는 내용을 선택할 수 있다(visually select inside the tag, 의 약어라고 생각하자). it 명령은 택스트 객체(text objct)라는 특별한 모션을 의미한다.
- vit, U -> gUit 전자는 vit는 선택, U는 조작. 후자는 gu명령과 모션(it)로 나눌 수 있다.
- 문서를 열 기준으로 조작하려면 특별한 도구가 필요하다. Vim은 이런 작업을 지원하기 위해 비주얼 블록 모드를 제공하고 있다.

# Ch5. 명령행 모드
- 버퍼 문서 작업에 사용할 수 있는 Ex명령
	- :[범위]delete [x]
	- :[범위]yank [x]
	- :[행]put [x]
	- :[범위]copy {주소}
	- :[범위]move {주소}
	- :[범위]join
	- :[범위]normal {명령}
	- :[범위]substitute/{패턴}/{문자열}/{플래그}
	- :[범위]global/{패턴}/[명령]
	- :h ex-cmd-index 참고
- ex명령에서 주소와 범위를 지정할 때 사용할 수 있는 기호 목록
	- 1: 파일의 첫 행
	- $: 파일의 마지막 행
	- 0: 파일의 첫 행 위의 가상 행
	- .: 커서가 위치한 행
	- 'm: 위치 표시 m이 포함된 행
	- '<: 비주얼 모드에서 선택된 영역의 첫 행
	- '>: 비주얼 모드에서 선택된 영역의 마지막 행
	- %: 파일 전체(1,$의 축약형)
- 약식 표기
- :copy 명령은 :co로 줄여쓸 수 있다. :t로도 가능하다.
	- :6t. : 6번행을 복사해서 현재 행 밑에 붙여넣기
	- :t6 : 현재 행을 복사해서 6번 행 밑에 붙여넣기
	- :t. : 현재 행을 복사해서 붙여넣기(yyp와 유사, 그러나 레지스터 사용하지 않음)
	- :t$ : 현재 행을 파일의 마지막에 붙여넣기
	- :'<,'>t0 : 비주얼 모드에서 선택한 행을 파일의 시작에 붙여넣기
- 가장 마지막에 사용한 Ex 명령을 반복하려면 간단하게 @:를 사용하면 된다.
- set wildmode=longest, list // 자동완성 기능이 배시 셸에서 제공하는 자동완성과 동일하게 동작한다
- set wildemode=full // 배시 셸보다 zsh가 제공하는 자동완성 기능이 더 편할 때 사용한다
- * * 와 <C-r><C-w>를 이용해 %s// 명령 효율적으로 이용한다
- set history=200 // 히스토리 기본 값은 20개, 메모리 성능 좋아졌으므로 늘리도록 하자.
- 명령행 창 불러오기
	- q/ : 검색 히스토리 명령행  창
	- q: : Ex명령 히스토리 명령행 창
	- <C-f> : 명령행 모드에서 명령행 창 전환
- :shell 쉘로 돌아가기, exit로 다시 vi로 돌아가기
- 현재 구동 중인 Vim 프로세스 중단하고 배시 셸로 돌아가기. <Ctrl-z>와 fg명령
- read !{명령} 을 사용하면 표준 출력이 버퍼에 바로 입력된다. :write는 반대로 작동한다. 이를 사용하면 버퍼에 있는 내용을 표준 입력으로 사용해서 {명령}에 전달할 수 있다.
- 느낌표는 명령행에서 어디에 위치하느냐에 따라 의미가 달라진다
	- :write !sh // 표준 입력으로 외부 sh 명령을 실행한다.
	- :write ! sh // 표준 입력으로 외부 sh 명령을 실행한다.
	- :write! sh // 버퍼의 내용을 sh라는 파일에 작성하는 명령이다. (덮어쓰라는 의미)
- :2,$!sort -t',' -k2 
	- 쉼표로 분리된 필드 알려주기 위해 -t',' 
	- 정렬하려는 필드가 두 번째 열이기 때문에 -k2
	- 2행에 커서 놓고 !G를 하면 :,.$! 가 입력된다.
- 셸 외부명령 호출 시 유용하게 사용할 수 있는 명령어
	- :shell : 셸을 시작함(exit를 입력하면 다시 vim으로)
	- :!{명령} : 셸에서 {명령}을 시작함
	- read !{명령} : 셸에서 {명령}을 실행한 후, 표준 출력을 커서 아래로 추가함
	- [범위]write !{명령} : 셸에서 [범위]의 내용을 표준 입력으로 사용해 {명령}을 실행함
	- [범위]!{필터} : 지정한 [범위]를 외부 프로그램 {필터}를 통해 걸러냄

# Ch6. 여러 파일 관리하기
- 파일을 편집한다고 표현하기는 했지만 실제로 파일을 편집하는 것이 아니다. 사실은 메모리 공간에 파일을 복사해서 편집을 하는 것이다. 이 메모리에 존재하는 파일의 사본을 Vim에서 사용하는 용어로 버퍼(buffer)라고 한다.
- :bprev, :bnext, :bfirst, :blast, <C-^> 단축키 이용하면 현재 버퍼와 이전 버퍼를 빠르게 전환할 수 있다.
- 팀 포프의 unimpaired 플러그인
	- nnoremap <silent> [b :bprevious<CR>
	- nnoremap <silent> ]b :bnext<CR>
	- nnoremap <silent> [B :bfirst<CR>
	- nnoremap <silent> ]B :blast<CR>
- 버퍼 제거 :bdelete 명령을 사용한다. 버퍼를 제거해도 버퍼와 연관된 실제 파일에는 영향을 미치지 않는다는 점을 알아두자. 단순히 메모리 내 사본을 제거하는 기능을 한다. 버퍼 목록을 관리하는 Vim 내장 기능은 유연성이 부족한 편이다. 
- 인자 목록 확인 :args, :args {인자목록}, 인자목록은 파일명이나 와일드카드, 셸 명령의 출력을 포함할 수 있다.
- 요청한 경로와 일치하는 파일 목록을 불러오기 위해 와일드카드 조합을 사용할 수 있는데 이 방법을 글롭(glob)이라 한다.
- Vim은 역따옴표 내에 있는 문자를 셸 명령으로 처리하고 그 결과를 args 명령의 인자로 사용한다
```vim
:args `cat . chapters`
```
- 종료할 때 숨김 버퍼 처리하기
	- 변경내용 유지 :w[rite]
	- 변경 취소 :e[dit]!
	- 모든 창 닫음 :qa[ll]!
	- 변경 모든 버퍼 디스크에 저장 :wa[ll]
- :argdo {명령} 은 이렇게 동작한다
	- :first :{명령} :next {명령} ...(목록 마지막까지)
	- hidden 설정을 활성화하면 "마지막 변경후에 저장하지 않았습니다."라는 에러를 !없이 작업할 수 있다.
	- :wn 현재 버퍼를 저장하고, 다음 버퍼로 이동하는 기능 제공
- <C-w>s : 화면 상하 - :sp[lit] {파일명}, <C-w>v : 화면 좌우 - :vsp[lit] {파일명}
- 이동: <C-w> w, h, l, k, j 닫기 :clo[se], <C-w>c 활성화 창 닫기, :on[ly], <C-w>o 활성화 창 유지, 나머지 닫기
- 창은 버퍼와 일대일 관계를 해당하지만 탭은 그렇지 않다.
- :lcd 명령을 사용하면 작업 경로를 다른 디렉터리로 변경할 수 있다.

# Ch7. 파일 열기와 저장하기
- 상대 경로로 파일 열기 
	- :edit %<Tab> - %기호는 현재 활성 버퍼의 파일 경로 의미
	- :edit %:h<tab> - :h변경자는 파일 경로에서 파일명을 제거
- 활성 파일 디렉토리를 위한 확장
	- vimrc에 cnoremap <expr> %% getcmdtype() == ':' ? expand('%:h').'\' : '%%'
	- %%를 입력하면 %:h<tab>을 입력한 것과 같이 현재 활성 버퍼 경로 확장하는 것 확인할 수 있다.
- find 명령을 사용하려면 'path'를 설정해야 한다.
	- :set path+=app/ * *
	- * * 와일드 카드는 app 아래 있는 모든 디렉터리를 찾는다.
	- 팀 포프의 rails.vim을 사용하면 프로젝트의 모든 디렉터리를 자동으로 설정한다. (path설정을 따로 하지 않아도 find 명령 사용 가능)
- netrw 플러그인 사용하기 위해서 설정 해야 할 것
	- set nocompatible
	- filetype plugin on
	- vim . 으로 실행 (- 는 부모디렉토리 이동)
- :edit . [:e.] : 파일 탐색기로 현재 작업 디렉터리 열기
- :Explore [:E] : 파일 탐색기로 현재 활성 버퍼의 디렉터리 열기
- <C-g> 명령은 현재 파일의 파일명과 상태를 출력한다
- 존재하지 않는 디렉터리에 파일 저장했을 때 오류 해결
	- ex) :edit madeup/dir/doesnotexist.yet
	- :!mkdir -p %:h
	- :write
- 관리자 권한으로 파일 저장하기(파일 root 소유, 일반 사용자 권한 접근)
	- :w !sudo tee % > /dev/null (후에 패스워드 입력)
	- % 기호는 현재 버퍼에 열려 있는 파일 경로를 의미한다. 
	- tee /etc/hosts > /dev/null 명령을 실행한다. 이 명령은 버퍼의 내용을 표준 입력으로 받아서 그 결과를 파일의 내용으로 덮어쓴다.

# Ch8. 모션으로 파일 내부 탐색하기
- 모션은 단순히 문서를 이동하는 데에만 쓰이지 않으며, 여러 기능과 함께 활용할 수 있다. 
- 매주마다 작업에서 사용하는 기능 중에 새로운 모션을 하나씩 늘리는 것을 목표로 삼고 이 문서를 자주 읽도록 하자.(:h motion.txt) 
- h, j, k, l에 익숙해지기
	- 방향키 습관을 없애자.
	- noremap <Up> <Nop>
	- noremap <Down> <Nop>
	- noremap <Left> <Nop>
	- noremap <Right> <Nop>
- 실제 행과 표시 행 명령어
	- j 하나아래로 실제행
	- gj 하나 아래로 표시행
	- j, k, 0, ^, $ 모두 앞에 g를 붙이면 표시행 기준으로 이동한다.
- 단어 단위로 이동하기
	- w, b, e, ge
	- w, b 는 단어 첫 번째로 이동하고, e와 ge는 단어 마지막으로 이동한다.
	- w,b 명령 (for)word와 backword를 생각하면서 익숙해지자
	- e, ge는 처음에는 유용성을 느끼기 어렵다. ea : 현재 단어 끝에 덧붙여라. gea : 이전 단어 끝에 덧붙여라
- 단어와 WORD 구분하기
	- 사실 단어와 WORD의 세밀한 차이는 Vim을 구현하는 사람 영역이다.
	- WORD는 단어보다 크다.
- 역방향 문자 검색 명령을 없애지 말자
	- vim은 사용자 정의 명령의 네임스페이스로 사용할 수 있는 리더 키를 제공한다.
	- 기본 리더키는 \이다. 일반적으로 쉼표 키를 사용한다. (쉼표에는 역방향 문자 검색 명령이 배정되어 있다)
	- 쉼표를 기본 리더키로 사용한다면 이 기능을 다른 키에 배정하도록 한다.
- f F t T ; , (f는 다음 위치, t는 다음 위치 앞으로)
	- 문장의 마지막 까지 삭제하고 싶다면, .은 제외하고 dt.
- /검색에선 n, N
	- v/ge<CR> 로 /ge단어까지 선택 후 h 후 d 눌러서 삭제 가능
	- d/ge<CR>
- 커서의 위치가 괄호 안이라면 i} 입력해서 어디에 있든 텍스트 객체를 사용할 수 있다.
- a"를 입력하면 겹따옴표로 감싼 범위로 선택 영역을 확장한다.
- i>는 꺾쇠 괄호 안에 있는 모든 문자를 영역으로 지정한다.
- 일반적으로 i는 구분자 내에 있는 본문 영역 지정, a는 구분자를 포함해서 선택영역 지정(i = inside, a = around를 선택한다고 생각하자).
- a) a} a] a> a' a" a` at(xml 태그 범위)
- ci" 명령은 겹따옴표 내 본문을 치환한다. (cit 명령은 태그내 본문 치환, 왜 안되지?)
- 주변 삭제, 내부 변경
	- iw : word, aw : word와 공백
	- iW : WORD, aW : WORD와 공백
	- is : 문장, as : 문장과 공백
	- ip : 문단, ap : 문단과 빈행
	- daw와 diw차이, caw와 ciw차이 이해하기(d -> aw as ap, c는 iw 일반적)
- '{마크}는 마크로 표시한 행으로 이동해서 처음으로 공백이 아닌 문자가 나오는 곳에 커서를 놓는다.
- \`{마크}는 위치를 표시한 행과 열을 정확하게 찾아 그 위치로 커서를 이동한다.

- 자동 마크 생성
	- \`\` : 현재 파일에서 마지막으로 이동하기 전 위치
	- \`. : 마지막으로 변경 위치
	- \`^ : 마지막 삽입 위치
	- \`[ : 마지막 변경 또는 복사의 시작 위치
	- \`] : 마지막 변경 또는 복사의 끝 위치
	- \`< : 마지막 선택 영역의 시작 위치
	- \`> : 마지막 선텩 영역의 끝 위치
- %명령을 이용해 열고 닫는  괄호로 이동할 수 있다.
	- match.vim 플러그인을 활성화하면 이 모션을 XML 태그에서도 사용할 수 있다.
	- <surround.vim> 플러그인은 이런 작업 쉽게 할 수 있는 명령 제공한다.
	- vim에는 % 명령의 기능을 향상하는 matchit 플러그인이 포함
	- vimrc에 다음을 추가하고 실행하면 플러그인 자동으로 실행
```vim
set nocompatible
filetype plugin on
runtime macros/matchit.vim
```

# Ch9. 점프 명령으로 파일 사이 이동하기
- <C-o> 명령을 누르면 뒤로 가기 버튼과 같은 동작을 하며 <C-i> 명령을 누르면 앞으로 가기 버튼과 같이 동작한다. 이 두가지 명령을 사용하면 vim에서 점프했던 모든 위치로 이동할 수 있다.
- 모션은 파일을 이동할 때 사용하는 명령을 뜻하고, 점프는 파일 사이를 돌아 다닐 때 사용하는 명령을 의미한다 (일부 모션 중에도 점프로 구분되는 모션이 있다).
- [숫자]G 명령을 사용해서 특정 행으로 바로 이동하는 동작은 첨프로 처리되지만 한 행씩 이동하는 동작은 점프로 처리되지 않는다.
- 점프로 처리되는 명령
	- [숫자]G : 행번호로 점프
	- /패턴<CR> / ?패턴<CR> / n / N : 전후에서 해당 패턴이 나타나는 곳으로 점프
	- % : 일치하는 괄호로 점프
	- ( / ), { / } : 이전/다음 문단의 시작으로 점프하기
	- H / M / L : 현재 화면의 상단/중단/하단으로 점프하기
	- gf : 커서가 놓여 있는 파일명을 열기
	- <C-]> : 커서가 놓여 있는 키워드의 정의로 점프
	- `{마크} / '{마크} : 마크로 이동하기
- vim 창을 여러개 띄었다면 그 각각의 화면에 대한 점프 목록이 별개로 존재한다.
- 탭 키를 매핑할 때 주의할 점
	- <C-i> 눌러보면 TAB키 처럼 작동한다. <TAB>키의 매핑을 변경하면 <C-i>를 누를 때도 변경된 매핑으로 실행된다.
	- u<C-r>을 누르면 마지막 변경 위치로 커서를 손쉽게 이동할 수 있다.
	- g; g, 목록의 전후를 살펴볼 수 있다.
	- 마지막으로 수정했던 위치에서 바로 끼워넣기 모드로 시작하고 싶다면 gi 명령을 사용하면 된다.
	- 내용 입력을 다 하고 커서의 위치를 다시 끼워넣기 모드를 시작했던 위치고 이동하고 싶다면 `^ 마크 사용.
- 파일 확장자 정하기
	- :set suffixesadd+=.rb
	- gf명령으로 파일 이동, <C-o>명령으로 이전 파일로 돌아가기
- gf 명령으로 찾는 파일이 존재할 만한 모든 경로를 추가해두면 gf 명령을 사용했을 때 해당 파일을 문제없이 찾을 수 있다.
	- 현재 path에 어떤 경로가 설정되어 있는지 알아보기 :set path?
	- 설졍 변경 문제를 자동화로 해결한 팀포프의 bundler.vim 플러그인
- m{영문자} 명령은 현재 커서가 놓인 곳에  마크를 생성한다. (소문자는 현재 버퍼, 대문자는 전역에서 접근할 수 있다)
	- `{영문자} 명령으로 해당 위치로 바로 이동할 수 있다.
- vimgrep /fooBar/ ** 
	- <C-o>명령을 이용해서 vimgrep을 가장 먼저 실행했던 위치로 돌아갈 수 있다.
	- 사용하기 전에 mM으로 위치를 마크해두면 `M으로 한번에 이동 가능하다.
	- 퀵픽스 목록을 생성하는 명령 즉, :grep, :vimgrep, :make 등을 사용하는 경우  전역 마크를 설정하는 습관을 갖자. 

# Ch10. 복사하기와 붙여넣기
- \_d{모션}명령을 사용하면 진정한 의미의 제거 기능을 사용할 수 있다. (블랙홀 레지스터)
- 명령에서 어떤 레지스터를 사용할지 지정하지 않으면 기본 레지스터인 무명레지스터("")를 사용해서 명령을 수행한다.
	- x, s, d, c, y 명령은 모두 무명 레지스터를 사용한다.
	- y 모션을 사용하면 무명 레지스터에만 저장하는 게 아니라 복사하기 레지스터(0)에도 내용을 저장한다. 
	- 레지스터에 저장된 내용은 :reg "0 으로 확인가능하다.
- 읽기 전용 레지스터
	- "% : 현재 파일명
	- "# : 직전에 편집한 파일명
	- ". : 마지막 삽입 본문
	- ": : 마지막 ex명령
	- "/ : 마지막 검색 패턴 (:let명령 사용해서 검색 패턴 저장할 수 있다)
- ciw<C-r>0<Esc> 끼워넣기 모드를 벗어나지 않고 레지스터 붙여넣기.
- :set pastetoggle=<f5> <f5>를 눌러 붙여넣기 설정을 쉽게 전환할 수 있다.
- "+p 명령을 입력하면 더하기 레지스터에 있는 내용을 붙여넣음. (이 레지스터가 바로 시스템 클립보드 레지스터) (설정 고민할 필요X)

# Ch11. 매크로
- Vim 매크로를 배우는 것은 바둑과 같다. 몇 분 투자해서 큐칙을 배울 수 있지만 정통하기 위해서는 시간을 평생 투자해야 한다. 하지만 매크로는 작업을 쉽게 자동화해주기 때문에 다소 어렵게 느껴지더라도 배워둘 가치가 있다.
- qa를 입력하면 레지스터 a에 매크로를 기록, q를 누르면 매크로 기록 저장. @a 매크로 a 사용, @@ 가장 최근 실행했던 매크로 사용
- 매크로를 기록하면서 모든 명령을 반복 가능한 형태로 작성할 것, 이것이 바로 매크로의 황금률이다.
- 매크로는 모션 이동이 실패하면 중지한다. 22@q
- ~대문자로 만들기
- 직렬과 병렬매크로 (병렬은 강력하다, 직렬은 어느 부분에서 문제가 생겼는지 알 수 있다)
- 매크로 끝에 명령더하기 (q에 저장했다면 qq(덮어쓰기)아닌 qQ(이어 붙이기))
- 매크로를 문서 안에 붙여 넣기 put: a
	- 매크로 수정 후 다시 저장하기 ("add (개행문자 포함), 0"ay$dd)

# Ch12. 패턴과 문자열 일치
- Vim의 검색 패턴에서 대소문자를 판별하는 기능을 끄려면 'ignorecase'설정을 활성화 한다. :set ignorecase
- 검색 시 대소문자 판별 지정하기 \c : 대소문자 구분 x, \C : 대소문자 구분 o
- 지능형 대소문자 판별 활성화하기 'smartcase'라는 설정화 활성화하면 사용가능, 패턴 검색 시 대문자 포함한 경우 'ignorecase'를 비활성화하고 검색한다.
- ignorecase, smartcase 둘다 on 일경우 foo -> foo Foo FOO, Foo -> Foo
- 대괄호는  기본적으로 특별한 의미가 부여되어 있음. 중괄호는 이스케이프 문자를 붙여야 특별한 의미가 있음. 닫는 중괄호는 생략해도 됨. 괄호또한 이스케이프 문자를 붙여야 특별한 의미가 있음.
- 배리 매직 검색을 활성화하려면 검색 패턴에 \v 패턴을 추가하자. 활성화되면 _ , 영소문자, 숫자0~9를 제외한 모든 문자를 특별한 의미로 취급
- 이스케이프 문자인 역슬래시 없이 작성할 수 있다. 패턴이 더 읽기 쉽다.
- # 문자에는 특별한 의미가 없다. 언제나 일반 문자로 인식한다. (예외, 추가될 수 있음)
- 어휘 착시를 찾아내는 정규표현식 /\v<(\w+)\_s+\1>
- \zs 항목은 일치의 시작을 표시하고 반대로 \ze 항목은 일치의 끝 부분을 표시한다.
- 정규표현식 "[^"]+"는 기초적인 패턴에 해당하는데 자주 사용하는 관용구 중 하나다. 
- "uyi[ 레지스터 u에 저장, /\V<C-r>u<CR>
- 검색이 어떤 방향으로 진행되는지 신경 쓰지 않고 u 레지스터에 저장된 내용을 탈출 기호로 처리하고 싶다면 escape함수를 사용하면서 {문자}인자에 getmcdtype().'\'를 넣으면 된다.

# Ch13. 검색하기
- 현재 커서에서 마지막까지 검색을 다 한 다음에 문서의 첫 부분으로 되돌아가서 검색을 다시 시작하는 동작을 방지하려면 'wrapscan'설정을 끄면 된다.
- 검색을 반복하는 경우 사용할 수 있는 명령
	- n : 이전 검색과 오프셋을 기준으로 다음 일치 위치 이동
	- N : '' 이전 일치 위치 이동
	- /<CR> : 이전에 사용한 검색 패턴으로 정방향 검색
	- ?<CR> : '' 역방향 검색
	- gn : 문자 단위 비주얼 모드 활성하고 다음 일치하는 문장 선택
	- gN : '' 이전 일치하는 문장 선택
- hlsearch : 이 설정을 켜면 현재 활성화되어 있는 모든 창에서 검색한 내용과 일치하는 위치 모두 강조 표시
- set nohlsearch 대신 nohlsearch 명령을 입력하면 강조가 일시적으로 꺼진다(이번 검색에서만 기능을 끄고 다시 검색했을 때 활성화)
	- nnoremap <silent> <C-I> :<C-u>nohlsearch<CR><C-I> // 일반적으로 <C-I>은 화면을 모두 지우고 다시 출력하는 기능.
- incsearch를 활성화하면 검색 칸에 입력하는 매 순간마다 첫 번째로 일치하는 위치를 강조해서 표시한다.
- 검색창에서 <C-r><C-w> 자동완성 기능
- 현재 커서가 위치한 단어 끝에 입력을 추가하는 일은 ea 명령
- /lang/e<CR>로 검색하면 일치하는 내용의 끝에 커서가 놓이게 된다.
- /\vX(ht)?ml\C<CR> 
	- /\C 스위치를 추가하면 강제로 대소문자를 구분하는 방식으로 동작한다.
	- gUgn 명령을 사용하면 검색 패턴과 일치하는 본문을 대문자로 전환한다.
	- dgn cgn 으로 제거하나 치환
- :%s//"\1"/g 마지막으로 사용한 검색 명령을 재사용한다.
- :%s///gn 일치 횟수 세기 :vimgrep //g %
- 현재 선택 영역으로 검색하기
```vim
xnoremap * :<C-u>call <SID>VSetSearch('/')<CR>/<C-R>=@/<CR><CR>
xnoremap # :<C-u>call <SID>VSetSearch('?')<CR>/<C-R>=@/<CR><CR>

function! s:VSetSearch(cmdtype)
	let temp = @s
	norm! gv"sy
	let @/ = '\V' . substitute(escape(@s, a:cmdtype.'\'), '\n', '\\n', 'g')
	let @s = temp
endfunction
```

# Ch14. 치환하기
- :[범위]s[ubstitute]/{패턴}/{문자열}/[플래그]
- g플래그 : 치환 명령을 전역 범위를 대상으로 수행(현재 행에서 전역적으로). c플래그 : 매 치환마다 변경 여부 확인. n플래그 : 치환 명령을 사용해도 치환을 수행하지 않고 몇번이나 치환을 반복하게 될지 그 횟수 알려줌. e: 오류를 출력하지 않음
- 대체 문자열에서의 특수문자
	- \r : 개행 문자 캐리지 리턴 삽입
	- \t : 탭문자 삽입
	- \\ : 역슬래시 삽입
	- \1 : 첫번째 하위 일치하는 항목 삽입
	- \2 : 두번째 하위 일치하는 항목 삽입
	- \0 : 일치하는 전체 패턴 삽입
	- & : 일치하는 전체 패턴 삽입
	- ~ : 이전 :substitute에서 사용했던 {문자열} 사용
	- /={Vim 스크립트} : {Vim 스크립트} 표현식 연산 후에 그 결과를 치환 {문자열}로 사용
- 치한 명령에서 g 플래그는 수평 축을, %범위는 수직 축을 확장하는 역활을 한다.
- \= 항목은 vim스크립트 표현식이다. @{레지스터}를 사용해서 내용을 ㄹ참조 할 수 있다. @0은 복사하기 레지스터 내용 반환, @" 기본 레지스터인 무명 레지스터에 저장한 내용을 반환
- 마지막 치환 명령을 파일 전체 대상으로 실행 :%s//~/&
- gv 명령은 비주얼 모드로 전환한 후 선택 범위를 마짐가으로 선택했던 영역으로 다시 설정한다.
- 아래 설정은 일반모드의 &를 고치면서 동시에 비주얼 모드에 동일한 기능을 추가하는 내용이다.
	- nnoremap & :&&<CR>
	- xnoremap & :&&<CR>
- h/zs/d 패턴은 h 문자 뒤에 붙는 어떤 숫자든 일치하게 된다는 것이다.
- 표현식에서 필요한 값에 접근하려면 submatch(0)함수를 사용할 수 있는데 이 함수는 현재 검색 패턴과 일치하는 값을 반환한다. 
- 팀포프가 작성한 Abolish. :Subvert라는 명령 :substitute의 확장판 처럼 동작한다.
	- :%S/{man,dog}/{dog,mag}/g // /\v(<man>|<dog>) + :%s//\={"dog":"man", "man":"dog"}[submatch(1)]/g
- vimgrep으로 프로젝트 범위 검색 실행하기 
	- /Pragatic\ze Vim
	- :vimgrep // * * / * . txt
- :set hidden 저장하지 않고도 다른 파일로 이동할 수 있다.
	- :cfdo %s//Practical/gc 
	- :cfo update // 변경사항 저장

# Ch15. 전역 명령
- :[범위] global[!] / {패턴} / [명령]
	- 기본적으로 파일 전체(%)에 해당한다. :delete, :substitute, :normal 등 대부분의 Ex명령이 현재 행(.)을 기본 범위로 동작하는 것과 대조적이다.
	- global을 반전해서 실행하려면 :global! 또는 :vglobal을 사용한다. 이는 각 행에서 [명령]을 실행하는 데 정의한 패턴과 일치하지 않는 행을 대상으로 한다는 뜻이다.
	- :v/href/d : 이 명령은 href가 포함되지 않은 가각의 행을 제거하기로 읽을 수 있다.
- :global 명령에서 [명령]을 입력하지 않으면 기본적으로 :print 출력 명령을 사용한다.
	- :g/TODO // TODO 항목을 한 위치에 모두 모아서 보기
	- :g/TODO/yank A // TODO 항목을 레지스터 A에 저장하기
- g/{시작}/ .,{끝} [명령] // 시작 위치부터 끝 위치까지의 범위를 대상으로 명령을 실행한다.

# Ch16. ctags로 소스코드 색인 및 탐색하기
- Vim 태그 탐색 기능을 사용하려면 ctags를 먼저 설치해야 한다.
	- $sudo apt-get install exuberant-ctags
- 색인을 항상 최신 파일로 유지하기 위해서 ctags를 자주 실행하면 버전 관리 도구를 사용할 때 마다 tags 파일을 변경했다고 나올 것이다. 커밋 히스토리를 깔끔하게 유지하기 위해서 tag 파일을 무시하도록 설정하자.
- :nnoremap <f5> :!ctags -R<CR> 간편하게 <F5>를 누르면 색인을 다시 생성할 수 있다. 자동화도 가능하다.
	- :autocmd BufWritePost * call system("ctags -R")
- 코드가 작다면 거의 눈치채지 못할 정도로 짧은 시간에 색인을 생성하겠지만 프로젝트가 커질수록 색인 생성 속도가 느려지고 작업 흐름을 방해할 수 있다.
- 편집기 외부에서 파일을 수정한 경우 VIm 내부에서 변경이 이뤄진 것이 아니기에 코드의 변화를 인식하지 못하고 색인을 새로 생성하지 못한다.
- <C-]>와 g<C-l> 명령을 사용해서 이동할 수 있다. <C-t>는 뒤로가기 버튼이다.
- tags 색인 파일을 사용해서 코드 사이를 이동할 때 쓸 수 있는 명령
	- <C-]>: 커서 밑에 있는 키워드와 일치하는 첫 번째 태그로 이동
	- g<C-]>: 커서 밑에 있는 키워드가 다중 일치하는 경우에 사용자가 선택할 수 있는 프롬프트 출력, 하나만 존재하는 경우 프롬포트 없이 이동
	- :tag {키워드}: 키워드에 일치하는 첫 번째 태그로 이동
	- :tjump {키워드}: {키워드}가 다중 일치하는 경우 사용자가 선택할 수 있는 프롬프트 출력, 하나만 존재하는 경우 프롬프트 없이 이동
	- :pop or <C-t>: 태그 히스토리 뒤로 가기
	- :tag: 태그 히스토리에서 앞으로 가기
	- :tnext, tprev, tfirst, flast, tselect

# Ch17. 코드컴파일과 퀵픽스 목록에서 오류 확인하기
- Vim의 퀵픽스 목록은 Vim으로 작업하면서 외부 프로그램과 통합이 필요할 때 활용할 수 있는 핵심 기능이다.
- :make 명령을 실행했을 경우 오류가 발생한 위치로 커서가 자동으로 이동한다. 이를 방지하려면 :make! 또는 <C-o>명령으로 커서 위치 되돌리기
- 퀵픽스 명령 목록
	- :cnext, cprev, cfirst, clast
	- :cnfile, cpfile 다음 파일 첫번째 항목으로 이동, 이전 파일 마지막 항목으로 이동
	- :cc N N번쨰 항목으로 이동
	- :copen, cclose 퀵픽스 창 열기, 닫기
	- :cdo {명령} {명령}을 퀵픽스 목록에 있는 각각의 행에서 실행하기
	- :cfdo {명령} {명령}을 퀵픽스 목록에 있는 각각의 파일에서 실행하기
- Vim에서 :make를 호출하면 JSLint의 명령행 인터페이스인 nodelint를 호출하도록 설정해야 한다.
	- npm install nodelint -g
- Vim에서 컴파일러는 현재 작업하는 파일로 어떤 외부 프로그램을 사용한다는 의미이며 그 프로그램이 오류 또는 경고를 반환하면 목록으로 그 내용을 확인하는 기능을 제공한다는 정도로 이해할 수 있다. :make 명령은 외부 컴파일러를 실행한 후에 퀵픽스 목록에서 그 결과를 탐색할 수 있도록 해석하는 기능이라 할 수 있다.

# Ch18. 프로젝트에서 grep, vimgrep 그 외 기능으로 검색하기
- 외부 프로그램을 사용하는 경우 Vim 검색에서 사용할 수 있는 정교표현식 문법이 대부분 호환되지 않는 단점이 있다. vimgrep은 편리하게 사용할 수 있지만 외부 프로그램을 사용하는 것보다 느린편이다.
- sudo apt-get install ack-grep
- grep 대신 ack 사용하기 위해 'grepprg'를 다음 처럼 변경
	- :set grepprg=ack\ --nogroup\ $ *
- grep은 POSIX의 정규표현식을 사용하는 반면 ack는 펄의 정규표현식을 사용한다. Ack.vim 플러그인을 화용하자.
- :vim[grep][!] /{패턴}/[g][j] {파일}
	- 인자 목록에 있는 파일을 모두 열기 위해서는 ## 기호를 사용한다.
- vim //g ##
	- 다시 사용하더라도 검색 패턴이 명령 히스토리에 같이 포함되어 있기에 더 유용하게 쓸 수 있다.
	- vim /<C-r>//g ##
	
# Ch19. 자동완성, 다이얼 X를 돌려라
- Vim의 자동완성 기능을 더 강력하게 사용하기 위해서는 가장 연관성 높은 추천 단어를 띄우는 방법과 목록에서 옳은 단어를 선택하는 방법, 이 두가지를 이해해야 한다.
- Vim의 자동완성은 끼워넣기 모드에서 <C-p>와 <C-n>을 눌러 실행할 수 있다. 
- 자동완성의 여러 형태
	- <C-n> : 일반 키워드 완성
	- <C-x><C-n> : 현재 버퍼 키워드
	- <C-X><C-i> : 현재 파일에 포함된 키워드
	- <C-x><C-]> : 태그 파일 키워드
	- <C-x><C-k> : 사전 목록 //set spell 을 활성화해서 vim내 맞춤법 검사 활성화
	- <C-x><C-l> : 전체 행 완성
	- <C-x><C-f> : 파일명 완성
	- <C-x><C-o> : 전체 완성
- 자동완성 상용할 수 있는 팝업메뉴
	- <C-n> : 다음 목록에서 다음 일치 항목 사용하기
	- <C-p> : 단어 목록에서 이전 일치 항목 사용하기
	- <Down> <Up>
	- <C-y> : 현재 선택한 항목 검사하기
	- <C-e> : 원래 입력한 단어로 되돌리기
	- <C-h> : 현재 일치에서 문자 하나 제거하기
	- <C-l> : 현재 일치에서 단어 하나 추가하기
	- {문자} : 완성을 중단하고 {문자}추가하기
- 전체완성은 <C-x><C-o>명령으로 실행할 수 있다. 이 기능은 파일 타입 플러그인으로 구현되어 있기 때문에 다음 내용을 vimrc에 추가해야 한다.
	- set nocompatible
	- filetype plugin on

# Ch20. Vim에서 맞춤법 검사하기
- :set spell : 잘못 입력한 단어를 강조 표시할 수 있다.
- 잘못 입력했다고 표시한 단어 위에 현재 커서가 놓여있다면 추천 정정 목록을 열 수 있다.
	- z=	
- 문서를 다 작성하고 맞춤법을 검사하자.
- 맞춤법 검사를 수행할 때 쓰는 명령어
	- ]s : 다음 철자 오류로 이동하기
	- [s : 이전 철자 오류로 이동하기
	- z= : 현재 단어 교정 추천 단어 열기
	- zg : 현재 단어를 철자 파일에 추가하기
	- zw : 현재 단어를 철자 파일에서 제거하기
	- zug : 현재 단어에서 사용한 zg 또는 zw 명령 취소하기
- 미국식 철자법만 사용하려면 다음처럼 지정하면 된다
	- :set spell
	- :set spelllang=en_us
- 다른 언어 파일을 다운로드 할 수 있다.
- 이 기능을 사용하기 위해 vimrc에 해당 내용 추가한다.
	- set nocompatible
	- filetype plugin on
- 일반적인 철자 오류 고치기	
	- [s, 1z=
- 빠르게 철자 자동완성 사용하기
	- <C-x>s 사용하기

# Ch21. 이제부터 해야 할 일
- Vim을 어떻게 사용해야 하는지 생각하지 않고도 자연스럽게 사용하는 것을 목표로 삼자. 그 경지에 도달하면 생각하는 속도만큼 빠르게 문서를 편집할 수 있을 것이다.
- 이 책을 다 읽은 후에도 다시 읽다 보면 새로운 사실을 또 배울 수 있을 것이다.
- Vim을 자기만의 도구로 사용하자.
	- Vim의 기본 설정이 좋은 설정인 경우는 그렇게 많지 않다. 왜 이런방식으로 작동하지? Vi가 그렇게 동작했기 때문이다.
- 톱 쓰는 법을 배우고, 날을 갈아라
	- 저자 github에 가서 많은 설정파일 참고하고 vimrc파일을 보자. (nelstrom/dotfiles)

### 부록: vim을 자신의 취향에 맞게 수정하기
- set ignorecase : 대소문자 판별 지정하기
	- set noignorecase : 대소문자 판별 기능 끄기
	- set ignorecase! : 현재 설정과 반대 설정으로 전환하기
	- set ignorecase? : 현재 설정된 값 확인하기
- set tabstop=2 : 탭 문자를 2칸 쓰기
- set ts=2 sts=2 sw=2 et // softtabpstop, shiftwidth, expandtab 설정은 vim 들여쓰기에 영향주니 vimcasts 확인
- :bufdo setlocal tabstop=4 // 동일한 설정을 모든 버퍼에 적용하기
- :windo setlocal number // 모든 창에서 행 번호를 표시하고 싶다면

- "Use two spaces for indentation
set tabstop=2
set softtabstop=2
set shiftwidth=2
set expandtab
- 이 설정을 현재 버퍼에 적용하고 싶다면 다음 명령을 사용하자
	- :source two-space-indent.vim
	- source 명령으로 실행하는 파일은 파일 각 행을 이미 Ex명령으로 가정하고 실행한다.
- 언어마다 들여쓰기 다르게하기
```vim
if has("autocmd")
	filetype on
	autocmd FileType ruby setlocal ts=2 sts=2 sw=2 et
	autocmd FileType javascript setlocal ts=4 sts=4 sw=4 et
endif
```
