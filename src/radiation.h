#ifndef RADIATION_H
#define RADIATION_H

#include<array>
#include<vector>
#include<string>
#include<cmath>
#include<stdexcept>
#include<trng/mt19937.hpp>
#include<trng/normal_dist.hpp>

class Beam;

class LumpedRad{
public:
    LumpedRad()=default;
    LumpedRad(const std::array<double,3> &turns, const std::array<double,3> &beta, const std::array<double,2> &alpha, const std::array<double,3> &sigma);
    LumpedRad &turn_on(){is_damping=true;is_excitation=true;return *this;}
    LumpedRad &turn_off(){is_damping=false;is_excitation=false;return *this;}
    LumpedRad &turn_on_damping(){is_damping=true;return *this;}
    LumpedRad &turn_off_damping(){is_damping=false;return *this;}
    LumpedRad &turn_on_excitation(){is_excitation=true;return *this;}
    LumpedRad &turn_off_excitation(){is_excitation=false;return *this;}
    void do_for(Beam &) const;
    /*
    double do_for(Beam&) const{
        if(!is_damping && !is_excitation){
            return 0.0;
        }else{
            throw std::runtime_error("Not implemented");
        }
    }
    */
private:
    bool is_damping=false, is_excitation=false;
    std::vector<double> excitation;
    std::vector<double> damping;
};

#endif
