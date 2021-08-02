#include<iostream>
using namespace std;
class tool//abstract class.
{
    int strength;
    char type;
public:
    tool(char s,int a=1)//Parameterised constructor with default arguments for a.
    {
        strength=a;
        type=s;
    }
    void set_type(char s){type=s;}//function which sets type.
    void set_strength(int s){strength=s;}//function which sets strength.
    int get_strength(){return this->strength;}//function which returns the strength value.
    char get_type(){return this->type;}//function which returns the type of tool.
    virtual int fight(tool*e)=0;//virtual function whose function is defined as per a specific tool.
};
class rock:public tool//class rock which is inherited from tool.
{
public:
    rock():tool('r',1){};//constructor which sets type to 'r' and default strength to 1.
    int fight(tool *e)//which returns 1/2/3 depending on who wins.
    {
        int d;
        char s;
        s=e->get_type();//"s" stores the return type of the tool choosed by the computer.
        if(s=='s'){d=1;}//when rock fights against scissors human wins.
        else if(s=='r'){d=3;}//when rock fights against rock its a tie.
        else {d=2;}//when rock fights against paper computer wins.
        return d;
    }
};
class paper:public tool
{
public:
    paper():tool('p',1){};//constructor which sets type to 'p' and default strength to 1.
    int fight(tool *e)
    {
        int d;//default of 3 indicates that paper is playing with paper.
        char x;
        x=e->get_type();//x stores the return type of the tool choosed by the computer.
        if(x=='s'){d=2;}//when paper fights with scissor computer wins.
        else if(x=='r'){d=1;}//when paper fights with rock human wins.
        else{d=3;}//when paper fights against paper its a tie.
        return d;
    }
};
class scissor:public tool
{
public:
    scissor():tool('s',1){};//constructor which sets type to 's' and default strength to 1.
    int fight(tool*e)
    {
        int d;//default of 1 indicates that scissor is playing with paper.
        char s;
        s=e->get_type();
        if(s=='s'){d=3;}//if scissor plays against scissor its a tie.
        else if(s=='r'){d=2;}//if scissor plays against rock computer wins.
        else {d=1;}//if scissor plays against paper human wins.
        return d;
    }
};
int i=0;//global value i for creating random tools for computer.
tool* randi()
{
    rock a;
    paper b;
    scissor c;
    tool *d;
    if(i%3==0)
        {
            i++;
            cout<<"Computer choose rock"<<endl;
            a.set_strength(1);
            a.set_type('r');
            d=&a;
        }//if i%3 is 0 random function will generate rock.
    else if(i%3==1)
        {
            i++;
            cout<<"Computer choose paper"<<endl;
            b.set_strength(1);
            b.set_type('p');
            d=&b;
        }  //if i%3 is 1 random function will generate paper.
    else if(i%3==2)
        {
            i++;
            cout<<"Computer choose scissor"<<endl;
            c.set_strength(1);
            c.set_type('s');
            d=&c;
        }//if i%3 is 2 random function will generate scissor.
    return d;
}
class RPSgame
{
    tool *a;//Human choice
    tool *b;//Computer choice
    int human_wins,comp_wins,tie;
public:
    RPSgame(){human_wins=comp_wins=tie=0;}//default constructor set human_wins,comp_wins,tie to 0.
    void set_tool(tool *c,tool *d){a=c;b=d;}//setter which sets a and b to c and d.
    void fightgame()//function for playing rock paper and scissor.
    {
        int c;
        c=a->fight(b);//c stores the int value which indicates the winning status.
        if(c==1){cout<<"You win!!! :-)"<<endl;human_wins++;}
        else if(c==2){cout<<"Computer wins! :-("<<endl;comp_wins++;}
        if(c==3){cout<<"Its a tie!!! "<<endl;tie++;}//
        cout<<endl;
        disp();//displays the result.
    }
    void disp()//display function which displays the overall summary of the match.
    {
        cout<<"Result "<<endl;
        cout<<"Human wins : "<<human_wins<<endl;
        cout<<"Comp wins : "<<comp_wins<<endl;
        cout<<"Tie : "<<tie<<endl;
    }
};
int main()
{
    char s,b;
    rock a;
    paper c;
    scissor d;
    RPSgame g;
    tool *z;
    int v;
    cout<<"Welcome to Rock,Paper,Scissors!"<<endl;
    cout<<"Do you want to choose different strengths for the tools?(y-yes,n-no)";
    cin>>s;
    if(s=='n')
    {
        do
        {
            cout<<"Choose your tool(r-rock,p-paper,s-scissor,e-exit):";
            cin>>b;
            if(b=='r')
            {
                z=randi();
                g.set_tool(&a,z);
                g.fightgame();
            }
            if(b=='p')
            {
                z=randi();
                g.set_tool(&c,z);
                g.fightgame();
            }
            if(b=='s')
            {
                z=randi();
                g.set_tool(&d,z);
                g.fightgame();
            }
        }while(b!='e');
    }
     else if(s=='y')
        {
            do
            {
                cout<<"Choose your tool(r-rock,p-paper,s-scissor,e-exit):";
                cin>>b;
                if(b=='r')
                {
                    cout<<"Enter the strength of your tool(1-5)"<<endl;
                    cin>>v;
                    a.set_strength(v);
                    z=randi();
                    g.set_tool(&a,z);
                    g.fightgame();

                }
                else if(b=='p')
                {
                    cout<<"Enter the strength of your tool(1-5)"<<endl;
                    cin>>v;
                    c.set_strength(v);
                    z=randi();
                    g.set_tool(&c,z);
                    g.fightgame();
                }
                else if(b=='s')
                {
                    cout<<"Enter the strength of your tool(1-5)"<<endl;
                    cin>>v;
                    d.set_strength(v);
                    z=randi();
                    g.set_tool(&d,z);
                    g.fightgame();
                }
            }while(b!='e');
        }
    return 0;
}
