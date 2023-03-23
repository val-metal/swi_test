#include <string>;
#include <vector>;
class Book{
    public: 
    std::string zanr;
    std::string nazev;
    std::string autor;
    std::string obsah;
    Person *p_pujc;
    Library *knihovna;
    bool volna=1;
    void vypujc(Person *person){
        volna=0; 
        p_pujc=person;
    };
    void vrat(Person *person){
        volna=1; 
        p_pujc=nullptr;
    };
    virtual std::string vypis(Person *person){
        return obsah;
    };

};

class Ebook:Book{
    Obsah_ebook data;
    
    std::string vypis(Person *person){
        std::string obsah_knihy=obsah;
        if(p_pujc->karticka==person->karticka){
            return obsah_knihy+ data.otevri();
        }
    };
    
};

class Obsah_ebook{
std::string data;
    public:
    std::string otevri(){
        return data;
    };
    void zavri(){
        return;
    };
};

class Library{
    public: 
    std::vector<Book*>books;

    std::string vypujcene_preson(Person *person){
        std::string seznam="";
        for(int i=0;i<books.size();i++){
            if(books[i]->volna==0 && books[i]->p_pujc->karticka==person->karticka){
                seznam+=books[i]->nazev+"\n";
            }
        }
    };
    
};

class Person{
    public: 
    std::string jmeno;
    std::string prijmeni;
    int karticka;
}; 