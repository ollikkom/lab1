#include "TString.h"


TString::~TString(){
    delete[]  Data ;
}


/// <summary> Конструктор по умолчанию </summary>
TString::TString(){
    std::cout<< "Constructor po ym"<< std::endl;
    Data = new char;
    *Data = '\0';
}


/// <summary> Конструктор копирования </summary>
/// <param name="rhs">Объект, который копируем </param>
TString::TString(const TString& rhs){
    size_t len = rhs.Size();
    Data = new char[len + 1];
    for (int i = 0; i <= len; i++){
        Data[i]= (rhs.Data)[i];
    }
}


/// <summary> Пользовательский конструктор </summary>
/// <param name="data">Данные, которые требуется поместить в создаваемый объект </param>
TString::TString(const char * data){
    int len = 0;
    while (data[len]) len++;
    Data= new char[len + 1];
    for (int i = 0; i <= len; i++) {
        Data[i] = data[i];
    }
}


/// <summary> Оператор присваивания </summary>
/// <param name="data">Объект, который копируем </param>
/// <returns>Возвращаем ссылку на себя</returns>
TString& TString::operator=(const TString& rhs){
    if (*this != rhs){
        std::cout << "Prisvaivanie" << std::endl;
        delete[] Data;
        size_t len = rhs.Size();
        Data = new char[len + 1];
        for (size_t i = 0; i <= len; i++){
            Data[i] = (rhs.Data)[i];
        }
    }
    else {
        std::cout << "Samoprisvaivanie" << std::endl;
    }
    return *this;
}



/// <summary> Оператор += </summary>
/// <param name="rhs">Объект, который стоит после знака '+=' </param>
/// <returns>Возвращаем ссылку на себя</returns>
TString& TString::operator+=(const TString& rhs){
    size_t len = rhs.Size();
    size_t iter = 0;
    size_t dataLen = Size();
    char* Data = new char[len + dataLen]+1;

    while ((rhs.Data)[iter]) {
        Data[dataLen + iter] = (rhs.Data)[iter];
        iter++;
    }
    if (iter!=0) Data[dataLen + iter] = (rhs.Data)[iter];

    return *this;
}


/// <summary> Оператор == </summary>
/// <param name="rhs">Объект, который стоит после знака '==' </param>
/// <returns>Возвращаем значения равенства двух строк</returns>
bool TString::operator ==(const TString &rhs) const
{
    size_t len = rhs.Size();
    size_t dataLen = Size();
    if (len != dataLen) return false;
    int i = 0;
    while (Data[i] == rhs.Data[i] && Data[i] != '\0') i++;
    if (i == dataLen) return true;
    else return false;
}


/// <summary> Оператор &lt; </summary>
/// <param name="rhs">Объект, который стоит после знака "&lt;" </param>
/// <returns>Возвращаем значения сравнения двух строк</returns>
bool TString::operator <(const TString &rhs) const{
    int i = 0;
    size_t dataLen = Size();
    size_t len = rhs.Size();

    while (i <= dataLen && i <= len){
        if (Data[i] < rhs.Data[i]) return true;
        if (Data[i] > rhs.Data[i]) return false;
        i++;
    }
    return false;
}


/// <summary> Функция поиска подстроки</summary>
/// <param name="substr">Подстрока, которую необходимо найти </param>
/// <returns>Возвращаем позицию substr. Если подстрока не найдена, то возвратить -1</returns>
size_t TString::Find(const TString& substr) const{
    size_t i = 0;
    size_t k= -1;
    size_t dataLen = Size();
    size_t substrLen = substr.Size();

    for (i = 0; i < dataLen; i++) {
        if (Data[i] == substr[0]) {
            for (size_t j = 0; j < substrLen; j++) {
                if (Data[i + j] != substr[j]) continue;
                if (j == substrLen - 1) return i;
            }
        }
    }

    return k;
}


/// <summary> Функция замены букв </summary>
/// <param name="oldSymbol">Символ, который требуется заменить </param>
/// <param name="newSymbol">Символ, на который требуется заменить </param>
void TString::Replace(char oldSymbol, char newSymbol){
    size_t dataLen = Size();

    for (int i = 0; i < dataLen; i++) {
        if (Data[i] == oldSymbol) {
            Data[i] = newSymbol;
        }
    }

}


/// <summary> Функция возвращает длину строки </summary>
/// <returns>Возвращаем длину строки</returns>
size_t TString::Size() const{
    size_t len = 0;
    while(Data[len]) len++;
    return len;
}


/// <summary> Функция для определения пуста ли строка </summary>
bool TString::Empty() const {
    if (Data[0] != '\0') return false;
    else true;
}


/// <summary> Оператор [] </summary>
/// <example>
/// <code>
/// TString str = "some string";
/// char symbol = str[2]; // symbol == 'm'
/// </code>
/// </example>
/// <param name="index"> Индекс символа </param>
/// <returns> Значение символа в строке с индексом index</returns>
char TString::operator[](size_t index) const{
    return Data[index];
};


/// <summary> Оператор [] </summary>
/// <example>
/// <code>
/// TString str = "some string";
/// str[0] = 'S'; // теперь переменная str равна "Some string"
/// </code>
/// </example>
/// <param name="index"> Индекс символа </param>
/// <returns> Ссылка на символ в строке с индексом index</returns>
char& TString::operator[](size_t index){
    char& c = Data[index];
    return c;
};


/// <summary> Смотри пример </summary>
/// <example>
/// <code>
/// TString str = "___some string___";
/// str.RTrim('_'); // теперь переменная str равна "___some string"
/// </code>
/// </example>
/// <param name="symbol"> Значение символов, которе отрезаем </param>
void TString::RTrim(char symbol){
    size_t dataLen = Size();
    if (Data[dataLen] == symbol) {
        Data[dataLen] = '\0';
        dataLen--;
    }
else if (Data[dataLen-1] != symbol){
        std::cout <<"NO"<< std::endl;
    }
}

void TString::LTrim(char symbol){
    size_t dataLen = Size();
    TString s;
    int i = 0;
    if (Data[i] != symbol) std::cout <<"NO"<< std::endl;
    else{
        while (Data[i]==symbol){
            i++;
        }
       s.Data= new char[dataLen-i+1];
        for(int j=0; j<dataLen-i+1; j++){
            s.Data[dataLen-i+1]=Data[dataLen-j];
        }
        *this=s;
    }
}


/// <summary> Смотри пример </summary>
/// <example>
/// <code>
/// TString str = "___some string___";
/// str.LTrim('_'); // теперь переменная str равна "some string___"
/// </code>
/// </example>
/// <param name="symbol"> Значение символов, которе отрезаем </param>
// void LTrim(char symbol);

//friend std::ostream & operator<<(std::ostream &, const TString &);
//}

/// <summary> Оператор +</summary>
/// <example>
/// <code>
/// TString a = "Hello";
/// TString b = "World";
/// TString c = a + b; // c равна "HelloWorld"
/// </code>
/// </example>
/// <returns>Возвращаем строку равную a + b</returns>

TString operator+(const TString & a, const TString & b){
    size_t i = 0;
    size_t aLen = a.Size();
    size_t bLen = b.Size();
    char* c = new char[aLen + bLen];

    for (i = 0; i < aLen; i++) {
        c[i] = a[i];
    }
    size_t j;
    for (j=0; j < bLen; j++) {
        c[i + j] = b[j];
    }
    c[i + j] = '\0';
    return c;
}


/// <summary> Оператор !=</summary>
bool operator!=(const TString & a, const TString & b){
    if (a == b) {
        return false;
    } else {
        return true;
    }
}


/// <summary> Оператор &gt;</summary>
bool operator>(const TString & a, const TString & b) {
    if (a == b) return false;
    else
     if (a < b) return false;
    else return true;
}


/// <summary> Оператор вывода </summary>
/// <param name="out">Поток куда выводим строку </param>
/// <param name="str">Строка, которую выводим </param>
/// <returns>Возвращаем ссылку на поток</returns>
std::ostream & operator<<(std::ostream &out, const TString &str){
    out << str.Data;
    return out;
}



