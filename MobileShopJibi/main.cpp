/*
 baraye tabe haye search chizi chap nashode.
 chon be nazaram return kardane list gooshi ha
 ba moshakhasate mored nazar karbordi tare ;RIP
 */




#include <iostream>
#include <vector>
using namespace std;

class mobile
{
public:
    mobile(string model ,string brand ,string color , int resolution , long long price){
        _model = model;
        _brand = brand;
        _color = color;

        _resolution = resolution;
        _price = price;

    }
    long long _price;
    int _resolution;

    string _color;
    string _brand;
    string _model;
};

class mobileShop
{
public:
    void addMobile(mobile item);
    vector<mobile> search(string type , vector<string> keys);
    vector<mobile> search(string type , long long limit);

private:
    vector<mobile> _mobileInfo;
    vector<mobile> filterBrand(vector<string> brands);
    vector<mobile> filterColor(vector<string> colors);
    vector<mobile> filterResolution(int key);
    vector<mobile> filterPrice(long long min , long long max);

};

void mobileShop::addMobile(mobile item)
{
        _mobileInfo.push_back(item);
}
vector<mobile> mobileShop::filterBrand(vector<string> brands)
{
    vector<mobile> result;

    if(!_mobileInfo.empty())
        for(const auto x : _mobileInfo)
        {
            for(auto &z : brands)
               if(x._brand == z)
                   result.push_back(x);
        }
    return result;
}
vector<mobile> mobileShop::filterColor(vector<string> colors)
{
    vector<mobile> result;

    if(!_mobileInfo.empty())
        for(const auto &x : _mobileInfo)
        {
            for(auto &z : colors)
                if(x._color == z)
                    result.push_back(x);
        }
    return result;
}
vector<mobile> mobileShop::filterResolution(int key)
{
    vector<mobile> result;

    if(!_mobileInfo.empty())
        for(const auto &x : _mobileInfo)
        {
            if(x._resolution == key)
                result.push_back(x);
        }
    return result;
}
vector<mobile> mobileShop::filterPrice(long long min , long long max)
{
    vector<mobile> result;

    if(!_mobileInfo.empty())
        for(const auto &x : _mobileInfo)
        {
            if(x._price >= min && x._price <= max)
                result.push_back(x);
        }
    return result;
}

vector<mobile> mobileShop::search(string type , vector<string> keys)
{
    if(type == "brand")
    {
        return filterBrand(keys);
    }
    else if(type == "color")
    {
        return filterColor(keys);
    }
    else cout << "No Entry for this type" << endl;
}
vector<mobile> mobileShop::search(string type , long long limit)
{
    if(type == "price")
    {
        return filterPrice(0 , limit);
    }
    else if(type == "resolution")
    {
        return filterResolution((int)limit);
    }
    else cout << "No Entry for this type" << endl;

}



int main()
{
    mobile phone("note10" , "samsung" , "black" , 89 , 10000);
    mobile phone2("note11" , "nokia" , "yellow" , 39 , 166000);
    mobile phone3("note12" , "blackberry" , "blue" , 79 , 106000);
    mobile phone4("note13" , "Apple" , "white" , 60 , 9900000);

    mobileShop shop;
    shop.addMobile(phone);
    shop.addMobile(phone4);
    shop.addMobile(phone2);
    shop.addMobile(phone3);

    //vector<mobile> result = shop.search("color" , {"black" , "blue" , "yellow"});
    //vector<mobile> result = shop.search("price" , 10000000 );
    vector<mobile> result = shop.search("resolution" , 79);
    //vector<mobile> result = shop.search("brand" , {"nokia" , "blackberry" , "Apple"});

    for(auto x : result)
        cout << x._model << endl;
    return 0;
}