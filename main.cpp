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
    T(float v, const char* vName) :
    value(v),
    name(vName)
    {}   //1
    float value; //2
    std::string name;//3
};

struct CompareStruct                                //4
{
    T* compare(T& a, T& b) //5
    {
            if( a.value < b.value ) return &a;
            if( a.value > b.value ) return &b;
        return nullptr;
    }
};

struct U
{
    float u1 { 3.2f }, u2 { 1.4f };
    float memFunc(const float& updatedValue)      //12
    {
            std::cout << "U's u1 value: " << u1 << std::endl;
            u1 = updatedValue;
            std::cout << "U's u2 updated value: " << u1 << std::endl;
            while( std::abs(u2 - u1) > 0.001f )
            {
                /*
                write something that makes the distance between that->u2 and that->u1 get smaller
                */
                u2 += 0.1f;
            }
            std::cout << "U's u2 updated value: " << u2 << std::endl;
            return u2 * u1;   
    }
};

struct valPrintStruct
{
    static float valPrint(U& that, const float& updatedValue )        //10
    {
            std::cout << "U's u1 value: " << that.u1 << std::endl;
            that.u1 = updatedValue;
            std::cout << "U's u2 updated value: " << that.u1 << std::endl;
            while( std::abs(that.u2 - that.u1) > 0.001f )
            {
                /*
                write something that makes the distance between that->u2 and that->u1 get smaller
                */
                that.u2 += 0.1f;
            }
            std::cout << "U's u2 updated value: " << that.u2 << std::endl;
            return that.u2 * that.u1;
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
    T t1( 4.1f,"t1Name" );                                             //6
    T t2( 7.2f,"t2Name" );                                             //6
    
    CompareStruct f;                                            //7
    auto* smaller = f.compare(t1 ,t2 );                              //8
    if(smaller != nullptr)
    {
        std::cout << "the smaller one is << " << smaller->name << std::endl; //9
    }

    U u3;
    float updatedValue = 2.5f;
    std::cout << "[static func] u3's multiplied values: " << valPrintStruct::valPrint( u3, updatedValue ) << std::endl;                  //11
    
    U u4;
    std::cout << "[member func] u4's multiplied values: " << u4.memFunc( updatedValue ) << std::endl;
}

        
        
        
        
        
        
        
