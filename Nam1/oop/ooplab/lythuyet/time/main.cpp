#include <iostream>
#include <string>
using namespace std;

class Time
{
private:
    int h;
    int m;
    int s;
public:
    Time(){};
    Time(int, int, int);
    void set(int, int, int);
    void printf();
    operator++(int);
};

Time::Time(int h, int m, int s)
{
    this->h = h;
    this->m = m;
    this->s = s;
}

void Time::set(int h, int m, int s)
{
    this->h = h;
    this->m = m;
    this->s = s;
}

void Time::printf()
{
    string h = to_string(this->h);
    string m = to_string(this->m);
    string s = to_string(this->s);
    if(h.length() == 1)
    {
        h = '0' + h;
    }
    if(m.length() == 1)
    {
        m = '0' + m;
    }
    if(s.length() == 1)
    {
        s = '0' + s;
    }
    cout << h << ":" << m << ":" << s << endl;
}

Time::operator++(int)
{
    if(this->h == 23 && this->m == 59 && this->s == 59)
    {
        this->h = 0;
        this->m = 0;
        this->s = 0;
        return 0;
    }
    else if(this->m == 59 && this->s == 59)
    {
        this->h += 1;
        this->m = 0;
        this->s = 0;
        return 0;
    }
    else if(this->s == 59)
    {
        this->m += 1;
        this->s = 0;
        return 0;
    }
    s+= 1;
    return 0;
}

int main()
{
    Time a(23, 59, 59);
    a.printf();
    a++;
    a.printf();
    a.set(4, 5, 6);
    a.printf();
    return 0;
}
