#include "../ch01/stdafx.h"

class CShape
{
	public:
		CShape() { }
		virtual ~CShape() { }
		virtual void draw() { cout << "CShape::draw()" << '\n'; }
};

class CRectangle : public CShape
{
	public:
		virtual void draw() { cout << "CRectangle::draw()" << '\n'; }
};

class CCircle : public CShape
{
	public:
		virtual void draw() { cout << "CCircle::draw()" << '\n'; }
};

int _tmain(int argc, _TCHAR *argv[])
{
	cout << "도형 번호를 입력하세요 1. 사각형 2. 원 " << '\n';
	int i_input = 0;
	cin >> i_input;

	CShape *p_shape = nullptr;
	if (i_input == 1)
		p_shape = new CRectangle;
	else if (i_input == 2)
		p_shape = new CCircle;
	else
		p_shape = new CShape;
	p_shape->draw(); // 좋은 예

	// 가상함수를 작성한다면 이런 식으로 코드를 작성할 필요가 없다.
	CRectangle *p_rect = dynamic_cast<CRectangle*>(p_shape);
	if (p_rect != NULL)
		cout << "CRectangle::draw()" << '\n';
	else
	{
		CCircle *p_circle = dynamic_cast<CCircle*>(p_shape);
		if (p_circle != NULL)
			cout << "CCircle::draw()" << '\n';
		else
			cout << "CShape::draw()" << '\n';
	}
	return 0;
}
