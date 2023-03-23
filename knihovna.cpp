#include <string>;
#include <vector>;
class Book{
    public: 
    std::string zanr;
    std::string nazev;
    std::string autor;
    Person *p_pujc;
    Library *knihovna;
    bool volna=1;
    void vypujc(Person *person){
        volna=0; 
        p_pujc=person;
    };
    std::string vypujcene_preson(Person *person){
        std::string seznam="";
        for(int i=0;i<knihovna->books.size();i++){
            if(knihovna->books[i]->volna==0 && knihovna->books[i]->p_pujc->karticka==person->karticka){
                seznam+=knihovna->books[i]->nazev+"\n";
            }
        }
    };
};

class Ebook:Book{
    std::string obsah;
    std::string otevri(){
        return obsah;
    };
    void zavri(){
        return;
    };
};

class Library{
    public: 
    std::vector<Book*>books;
    
};

class Person{
    public: 
    std::string jmeno;
    std::string prijmeni;
    int karticka;
}; 