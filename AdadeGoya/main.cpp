#include <iostream>
using namespace std;

class Rational {
public:
    Rational(){
        sorat = 0;
        makhraj = 1;
    }
    Rational(int _sorat ,int _makhraj){
        if(!(Rational::isZero(_makhraj))) {
            sorat = _sorat;
            makhraj = _makhraj;

        } else {
            cout << "Makhraj can not be zero I would set them as : 0 for sorat and 1 for makhraj."
            << endl <<" you can change it with setMakhraj and setSorat or by setRational functions." << endl;
            sorat = 0;
            makhraj = 1;
        }

    }
    //getters :
    int getSorat(){
        return sorat;
    }
    int getMakhraj(){
        return makhraj;
    }
    bool isZero(int _makhraj){
        if(_makhraj)
            return false;
        return true;
    }

    //setters
    void setSorat(int _sorat);
    void setMakhraj(int _makhraj);
    void setRational(int _sorat , int _makhraj);
    void setRational(string str);
    Rational add(Rational r);
    Rational subtract(Rational r);
    Rational multiply(Rational r);

private:
    int sorat;
    int makhraj;

};

void Rational::setSorat(int _sorat) {
    sorat = _sorat;
}
void Rational::setMakhraj(int _makhraj) {
    if(!isZero(_makhraj)) {
        makhraj = _makhraj;
        return;
    }
    cout << "Makhraj can not be zero! " << endl;
}
void Rational::setRational(int _sorat , int _makhraj){
    if(!isZero(_makhraj)){
        setMakhraj(_makhraj);
        setSorat(_sorat);
        return;
    }
    cout << "Did not set! Makhraj can not be ZERO !" << endl;
}
void Rational::setRational(string str){
    string sub;
    sub = str.substr(0 , str.find('/'));
    int _sorat = stoi(sub);
    sub = str.substr(str.find('/')+1);
    int _makhraj = stoi(sub);
    if(!isZero(_makhraj)) {
        setMakhraj(_makhraj);
        setSorat(_sorat);
        return;
    }
    cout << "Did not set ! Makhraj can not be ZERO !" << endl;
}
Rational Rational::add(Rational r){
    Rational res;
    res.sorat = sorat + r.sorat;
    res.makhraj = makhraj + r.makhraj;
    return res;
}
Rational Rational::subtract(Rational r){
    if((makhraj - r.makhraj) != 0) {
        Rational res;
        res.sorat = sorat - r.sorat;
        res.makhraj = makhraj - r.makhraj;
        return res;
    }
    cout << "This operation can not be done" << endl;
}
Rational Rational::multiply(Rational r){
    Rational res;
    res.sorat = sorat * r.sorat;
    res.makhraj = makhraj * r.makhraj;
    return res;
}



int main(){
    Rational test;
    Rational test2(2 , 0);
//    cout << test.getSorat() <<endl;
//    cout << test.getMakhraj() <<endl;

    //cout << test2.getMakhraj() << endl;
    //cout << test2.getSorat() << endl;

    //test.setSorat(10);
    //cout << test.getSorat() << endl;

    //test.setMakhraj(100);

    test.setRational(2 , 3);
//    test2.setRational("30/40");


//    Rational res = test.add(test2);
//    cout << res.getSorat() << endl;
//    cout << res.getMakhraj() << endl;

//    Rational res = test.subtract(test2);
//    cout << res.getSorat() << endl;
//    cout << res.getMakhraj() << endl;

//    Rational res = test.multiply(test2);
//    cout << res.getSorat() << endl;
//    cout << res.getMakhraj() << endl;

    //cout << test.getMakhraj() << endl;

    //test.setRational( 2 , 0);
    //test.setRational("11/0");
    cout << test.getMakhraj() << endl;
    cout << test.getSorat() << endl;




}