// example solution : TestScore & sort
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

class TestScore{
public:
    TestScore();
    TestScore(int id,std::string name,int score);
    int get_id() const;
    int get_score() const;
    std::string get_name() const;
    void set_id(int id);
    void set_score(int score);
    void set_name(std::string name);
    friend std::istream& operator >> (std::istream &strm, TestScore & ts);
    friend std::ostream& operator << (std::ostream &strm,const TestScore & ts);
private:
    int id;
    int score;
    std::string name;
};

TestScore::TestScore():id(-1),name("NA"),score(0){}
TestScore::TestScore(int id,std::string name,int score)
:id(id),name(name),score(score){}

int TestScore::get_id() const{
    return id;
}
int TestScore::get_score() const{
    return score;
}
std::string TestScore::get_name() const{
    return name;
}
void TestScore::set_id(int id){
    this->id = id;
}
void TestScore::set_score(int score){
    this->score = score;
}
void TestScore::set_name(std::string name){
    this->name = name;
}

std::istream& operator >> (std::istream &strm, TestScore & ts){
    strm >> ts.id >> ts.name >> ts.score;
    return strm;
}

std::ostream& operator << (std::ostream &strm,const TestScore & ts){
    strm << ts.id << " " << ts.name << " " << ts.score;
    return strm;
}

bool compareScore(const TestScore &st1,const TestScore &st2){
    return (st1.get_score() > st2.get_score());
}

int main(int argc, const char * argv[])
{
    // read !
    std::ifstream infile;
    infile.open("score2.dat");
    if (infile.fail()){
        std::cout << "File not found\n";
        return 0;
    }
    
    TestScore st1;
    std::vector<TestScore> list;
    while(infile >> st1){
        list.push_back(st1);
        //std::cout << st1 << std::endl;
    }
    infile.close();
    
    // sort!  : Google "lambda expressions C++"
    std::sort(list.begin(),list.end(),
              [](const TestScore &st1,const TestScore &st2)
              {
                  return (st1.get_score() > st2.get_score());
              });
    /*
     // see a function compareScore() above.
     std::sort(list.begin(),list.end(),compareScore);
     */
    
    // out!
    std::ofstream outfile;
    outfile.open("rank.dat");
    /*
     for (int i = 0 ; i < list.size() ; i++){
     outfile << list[i] << std::endl;
     }
     */
    /*
     for (auto it = list.begin() ; it != list.end() ; it++){
     outfile << *it << std::endl;
     }
     */
    for (auto st : list){
        outfile << st << std::endl;
    }
    outfile.close();
    return 0;
}

