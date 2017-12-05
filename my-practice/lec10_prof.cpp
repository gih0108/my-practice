#include <iostream>
class Agent
{
    public:
    Agent()
    {
        
    }
    virtual void Move() = 0;
};
class Monster : public Agent
{
    public:
    Monster()
    {
        x = 0;
        y = 0;
    }
    Monster(int _x, int _y)
    :x(_x), y(_y)
    {
        x= _x;
        y= _y;
    }
    void Move()
    {
        x++;
        y++;
        std::cout << "Monster: (" << x << ", " << y << ")"<< std::endl;
    }
    private:
    int x, y;
};

class Player : public Agent
{
    public:
    Monster(int _x, int _y)
    :x(_x), y(_y)
    {
        x= _x;
        y= _y;
    }
    void Move()
    {
        x--;
        y--;
        std::cout << "Player: (" << x << ", " << y << ")"<< std::endl;
    }
    private:
    int x, y;
};
int main(){
    /*
//몬스터    Monster mon(10,10);
    Player player(0,0);
  //몬스터 10개 만들기 
  Monster* mon_list = new Monster[10];
  for(int i = 0 ; i< 10 ; i++)
    mon_list[i].Move;
    
    mon.Move();
    player.Move();
*/
Agent* mon_list = new Monster[10];
for(int i = 0 ; i< 10 ; i++)
    mon_list[i].Move;
}