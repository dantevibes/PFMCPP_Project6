/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert all of the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference.
 
 2) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */


#include <iostream>
#include <string>
struct T
{
    T(char v, const char* vName);   //1
    char value;   //2
    std::string name; //3
};

T::T(char v, const char* vName) :
    value(v),
    name (vName)
{}

struct CompareTValues         //4
{
    T* compare( T& a, T& b)     //5
    {
        if( a.value < b.value ) return &a;
        if( a.value > b.value ) return &b;
        return nullptr;
    }
};

struct U
{
    float uVal1 { 0 }, uVal2 { 0 };
    float reduceGap(const float& target)      //12
    {
        
        std::cout << "U's uVal1 value: " << uVal1 << std::endl;
        uVal1 = target;
        std::cout << "U's uVal1 updated value: " << uVal1 << std::endl;

        while( std::abs(uVal2 - uVal1) > 0.001f )
        {
            if(uVal2 > uVal1)
                uVal2 -= std::abs(uVal2 - uVal1)*.5f;
            else if (uVal2 < uVal1)
                uVal2 += std::abs(uVal2 - uVal1)*.5f;
        }
        std::cout << "U's uVal2 updated value: " << uVal2 << std::endl;
        return uVal1 * uVal2;
    }
};

struct Updator
{
            
    static float reduceGap(U& that, float&  uValTarget)   //10
    {
        
        std::cout << "U's uVal1 value: " << that.uVal1 << std::endl;
        that.uVal1 = uValTarget;
        std::cout << "U's uVal1 updated value: " << that.uVal1 << std::endl;
        while( std::abs(that.uVal2 - that.uVal1) > 0.001f )
        {
            /*
             something that makes the distance between that-><#name2#> and that-><#name1#> get smaller
             */
            if(that.uVal2 > that.uVal1)
                that.uVal2 -= std::abs(that.uVal2 - that.uVal1)*.5f;
            else if (that.uVal2 < that.uVal1)
                that.uVal2 += std::abs(that.uVal2 - that.uVal1)*.5f;
        }
        std::cout << "U's uVal2 updated value: " << that.uVal2 << std::endl;
        return that.uVal2 * that.uVal1;
    }
};
        
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    T ampersand('&', "&" );                                         //6
    T percent('%', "%" );                                           //6

    CompareTValues f;       //7
    auto* smaller = f.compare( ampersand , percent );  //8                                                   
    if( smaller != nullptr )
    {
        std::cout << "the smaller one is << " << smaller->name << std::endl; //9
    }  
    
    U staticTest;
    float updatedValue = 5.f;
    std::cout << "[static func] staticTest's multiplied values: " << Updator::reduceGap(staticTest, updatedValue) << std::endl;                  //11
    
    U memberTest;
    std::cout << "[member func] memberTest's multiplied values: " << memberTest.reduceGap( updatedValue ) << std::endl;
}

        
        
        
        
        
        
        
