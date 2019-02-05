#include <string>

using namespace std;


class person
{
    public :
    person ();
    person ( string , string , string );
    string getFirst () const ;
    string getLast () const ;
    string getId () const ;
    private :
    string first ;
    string last ;
    string id ;
};
class student
{
    public :
    static const int CREDITS_NEEDED = 15;
    student ();
    student ( string , string , string );
    person getPersonInfo () const ;
    unsigned int getCredits () const ;
    double getGpa () const ;
    void addCredits ( unsigned int , double );
    bool graduated () const ;
    private :
    person info ;
    unsigned int credits ;
    double gpa ;
};
class undergrad : student
{
    public :
    undergrad ();
    undergrad ( string , string , string );
    string getFirst () const ;
    string getLast () const ;
    unsigned int getCredits () const ;
    double getGpa () const ;
    
    bool searchById ( string ) const ;
    bool searchByName ( string ) const ;
    void completedClass ( double );
    bool graduated () const ;
};
class grad : student
{
    public :
    grad ();
    grad ( string , string , string , string );
    string getFirst () const ;
    string getLast () const ;
    unsigned int getCredits () const ;
    double getGpa () const ;
    bool searchById ( string ) const ;
    bool searchByName ( string ) const ;
    void completedClass ( double );
    bool graduated () const ;
    void completedThesis ();
    bool hasDefended () const ;
    private :
    string thesis ;
    bool defended ;
};
class phd : student
{
    public :
    phd ();
    phd ( string , string , string , string );
    string getFirst () const ;
    string getLast () const ;
    unsigned int getCredits () const ;
    double getGpa () const ;
    bool searchById ( string ) const ;
    bool searchByName ( string ) const ;
    void completedClass ( double );
    bool graduated () const ;
    void completedDissertation ();
    bool hasDefended () const ;
    private :
    string dissertation ;
    bool defended ;
};

