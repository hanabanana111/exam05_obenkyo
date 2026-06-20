#ifndef VECT2_HPP
#define VECT2_HPP
#include <iostream>
#include <vector>

class vect2{
    private:
        std::vector<int> _container;

    public:
        vect2():_container(2,0){};
        vect2(int v1, int v2):_container{v1,v2}{};
        vect2(const vect2& other):_container(other._container){};
        ~vect2()=default;

        vect2& operator=(const vect2& other){
            if(this != &other){
                _container= other._container;
            }
            return *this;
        }

        int getContainer_elements(int index) const {return _container[index];}

        vect2 operator+(int add) const;
        vect2 operator+(const vect2& addon) const;
        vect2 operator-(int minus) const;
        vect2 operator-(const vect2& minuson) const;
        vect2 operator*(int multi) const;
        vect2 operator*(const vect2& multion) const;

        vect2& operator++() { ++_container[0]; ++_container[1]; return *this; }
        vect2 operator++(int) ;
        vect2& operator--() { --_container[0]; --_container[1]; return *this; }
        vect2 operator--(int) ;

        vect2& operator+=(int add) { _container[0] += add; _container[1] += add; return *this; }
        vect2& operator+=(const vect2& addon);
        vect2& operator-=(int minus) { _container[0] -= minus; _container[1] -= minus; return *this; }
        vect2& operator-=(const vect2& minuson);
        vect2& operator*=(int multi) { _container[0] *= multi; _container[1] *= multi; return *this; }
        vect2& operator*=(const vect2& multion);

        bool operator==(const vect2& other) const {
            return _container[0] == other._container[0] && _container[1] == other._container[1];
        }
        bool operator!=(const vect2& other) const { return !(*this == other); }
        
        friend vect2 operator*(int number, const vect2& vector){ return vector * number;}
        friend std::ostream& operator<<(std::ostream& out, const vect2& v){
            out <<"{"<<v._container[0]<<","<<v._container[1]<<"}";
            return out;
        }
};

#endif 