#include <stdio.h>
#include <iostream>

class Widget {
public:
    Widget(int i);
    ~Widget();
    void swap(Widget& other);
    Widget& operator=(const Widget& rhs);
    int getNum();
private:
    int* num;
};

Widget::Widget(int i): num(new int(i))
{
}

Widget::~Widget()
{
    delete num;
}

void Widget::swap(Widget& other)
{
    std::swap(num, other.num);
}

Widget& Widget::operator=(const Widget& rhs)
{
    *num = *(rhs.num);
    return *this;
}

int Widget::getNum()
{
    return *num;
}

namespace std {
    template<>
    void swap<Widget>(Widget& a, Widget& b)
    {
        a.swap(b);
    }
}

int main()
{
    Widget a(1);
    Widget b(2);
    std::swap(a, b);
    printf("a: %d, b: %d\n", a.getNum(), b.getNum());
}
