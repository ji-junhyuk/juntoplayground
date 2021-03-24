/*
   첫 번째 배열은 전체 책 제목 목록을 포함하는 문자열 배열이다.
   추가적인 두개의 배열은 전체 책 목록에서 가장 잘 팔리는 책 목록과 영어책 목록을 관리하기 위한 목적으로 제공된다.
   
*/
char *titles[] = {"rabbit", "honey", "angel", "boy", "think"};

char **bestBooks[1];
char **englishBooks[2];
// 이 두 배열은 책 제목을 복사하여 가지는 것보다 titles 배열에서 해당 책 제목의 주소를 포함하려고 한다. 
// 이 두배열은 그렇다면 char 포인터에 대한 포인터로 선언되어야 하며 배열의 요소들은 titles 배열 요소들의 주소를 포함해야 한다.

bestBooks[0] = &titles[4];

englishbook[0] = &titles[0];
englishbook[1] = &titles[1];
