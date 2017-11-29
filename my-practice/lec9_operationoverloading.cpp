#include <iostream>
using namespace std;

class Point
{
    private:
        int xpos, ypos;
        
    public:
        Point(int x=0, int y=0) : xpos(x) , ypos(y)
        {}
        
        void ShowPosition() const{
            cout << '[' <<xpos<< "," <<ypos << ']' <<endl;
        }
        
        Point operator+(const Point &ref)
        {
            Point pos(xpos+ref.xpos, ypos+ref.ypos);
            return pos;
        }
        
};