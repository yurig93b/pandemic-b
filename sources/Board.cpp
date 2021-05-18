//
// Created by Yuri Grigorian on 05/05/2021.
//

#include "Board.hpp"
#include <iostream>
using namespace pandemic;


Board::Board(){
    this->cities = {};
    this->load_cities();

    this->colors = {};
    this->load_colors();
}

void Board::load_cities(){
    // Init cities
    this->cities.insert({Algiers,  CityInfo(Algiers, Black)});
    this->cities.insert({Atlanta,  CityInfo(Atlanta, Blue)});
    this->cities.insert({Baghdad,  CityInfo(Baghdad, Black)});
    this->cities.insert({Bangkok,  CityInfo(Bangkok, Red)});
    this->cities.insert({Beijing,  CityInfo(Beijing, Red)});
    this->cities.insert({Bogota,  CityInfo(Bogota, Yellow)});
    this->cities.insert({BuenosAires,  CityInfo(BuenosAires, Yellow)});
    this->cities.insert({Cairo,  CityInfo(Cairo, Black)});
    this->cities.insert({Chennai,  CityInfo(Chennai, Black)});
    this->cities.insert({Chicago,  CityInfo(Chicago, Blue)});
    this->cities.insert({Delhi,  CityInfo(Delhi, Black)});
    this->cities.insert({Essen,  CityInfo(Essen, Blue)});
    this->cities.insert({HoChiMinhCity,  CityInfo(HoChiMinhCity, Red)});
    this->cities.insert({HongKong,  CityInfo(HongKong, Red)});
    this->cities.insert({Istanbul,  CityInfo(Istanbul, Black)});
    this->cities.insert({Jakarta,  CityInfo(Jakarta, Red)});
    this->cities.insert({Johannesburg,  CityInfo(Johannesburg, Yellow)});
    this->cities.insert({Karachi,  CityInfo(Karachi, Black)});
    this->cities.insert({Khartoum,  CityInfo(Khartoum, Yellow)});
    this->cities.insert({Kinshasa,  CityInfo(Kinshasa, Yellow)});
    this->cities.insert({Kolkata,  CityInfo(Kolkata, Black)});
    this->cities.insert({Lagos,  CityInfo(Lagos, Yellow)});
    this->cities.insert({Lima,  CityInfo(Lima, Yellow)});
    this->cities.insert({London,  CityInfo(London, Blue)});
    this->cities.insert({LosAngeles,  CityInfo(LosAngeles, Yellow)});
    this->cities.insert({Madrid,  CityInfo(Madrid, Blue)});
    this->cities.insert({Manila,  CityInfo(Manila, Red)});
    this->cities.insert({MexicoCity,  CityInfo(MexicoCity, Yellow)});
    this->cities.insert({Miami,  CityInfo(Miami, Yellow)});
    this->cities.insert({Milan,  CityInfo(Milan, Blue)});
    this->cities.insert({Montreal,  CityInfo(Montreal, Blue)});
    this->cities.insert({Moscow,  CityInfo(Moscow, Black)});
    this->cities.insert({Mumbai,  CityInfo(Mumbai, Black)});
    this->cities.insert({NewYork,  CityInfo(NewYork, Blue)});
    this->cities.insert({Osaka,  CityInfo(Osaka, Red)});
    this->cities.insert({Paris,  CityInfo(Paris, Blue)});
    this->cities.insert({Riyadh,  CityInfo(Riyadh, Black)});
    this->cities.insert({SanFrancisco,  CityInfo(SanFrancisco, Blue)});
    this->cities.insert({Santiago,  CityInfo(Santiago, Yellow)});
    this->cities.insert({SaoPaulo,  CityInfo(SaoPaulo, Yellow)});
    this->cities.insert({Seoul,  CityInfo(Seoul, Red)});
    this->cities.insert({Shanghai,  CityInfo(Shanghai, Red)});
    this->cities.insert({StPetersburg,  CityInfo(StPetersburg, Blue)});
    this->cities.insert({Sydney,  CityInfo(Sydney, Red)});
    this->cities.insert({Taipei,  CityInfo(Taipei, Red)});
    this->cities.insert({Tehran,  CityInfo(Tehran, Black)});
    this->cities.insert({Tokyo,  CityInfo(Tokyo, Red)});
    this->cities.insert({Washington,  CityInfo(Washington, Blue)});


    // Make links
    this->cities.at(Algiers).add_link(Madrid);
    this->cities.at(Algiers).add_link(Paris);
    this->cities.at(Algiers).add_link(Istanbul);
    this->cities.at(Algiers).add_link(Cairo);
    this->cities.at(Atlanta).add_link(Chicago);
    this->cities.at(Atlanta).add_link(Miami);
    this->cities.at(Atlanta).add_link(Washington);
    this->cities.at(Baghdad).add_link(Tehran);
    this->cities.at(Baghdad).add_link(Istanbul);
    this->cities.at(Baghdad).add_link(Cairo);
    this->cities.at(Baghdad).add_link(Riyadh);
    this->cities.at(Baghdad).add_link(Karachi);
    this->cities.at(Bangkok).add_link(Kolkata);
    this->cities.at(Bangkok).add_link(Chennai);
    this->cities.at(Bangkok).add_link(Jakarta);
    this->cities.at(Bangkok).add_link(HoChiMinhCity);
    this->cities.at(Bangkok).add_link(HongKong);
    this->cities.at(Beijing).add_link(Shanghai);
    this->cities.at(Beijing).add_link(Seoul);
    this->cities.at(Bogota).add_link(MexicoCity);
    this->cities.at(Bogota).add_link(Lima);
    this->cities.at(Bogota).add_link(Miami);
    this->cities.at(Bogota).add_link(SaoPaulo);
    this->cities.at(Bogota).add_link(BuenosAires);
    this->cities.at(BuenosAires).add_link(Bogota);
    this->cities.at(BuenosAires).add_link(SaoPaulo);
    this->cities.at(Cairo).add_link(Algiers);
    this->cities.at(Cairo).add_link(Istanbul);
    this->cities.at(Cairo).add_link(Baghdad);
    this->cities.at(Cairo).add_link(Khartoum);
    this->cities.at(Cairo).add_link(Riyadh);
    this->cities.at(Chennai).add_link(Mumbai);
    this->cities.at(Chennai).add_link(Delhi);
    this->cities.at(Chennai).add_link(Kolkata);
    this->cities.at(Chennai).add_link(Bangkok);
    this->cities.at(Chennai).add_link(Jakarta);
    this->cities.at(Chicago).add_link(SanFrancisco);
    this->cities.at(Chicago).add_link(LosAngeles);
    this->cities.at(Chicago).add_link(MexicoCity);
    this->cities.at(Chicago).add_link(Atlanta);
    this->cities.at(Chicago).add_link(Montreal);
    this->cities.at(Delhi).add_link(Tehran);
    this->cities.at(Delhi).add_link(Karachi);
    this->cities.at(Delhi).add_link(Mumbai);
    this->cities.at(Delhi).add_link(Chennai);
    this->cities.at(Delhi).add_link(Kolkata);
    this->cities.at(Essen).add_link(London);
    this->cities.at(Essen).add_link(Paris);
    this->cities.at(Essen).add_link(Milan);
    this->cities.at(Essen).add_link(StPetersburg);
    this->cities.at(HoChiMinhCity).add_link(Jakarta);
    this->cities.at(HoChiMinhCity).add_link(Bangkok);
    this->cities.at(HoChiMinhCity).add_link(HongKong);
    this->cities.at(HoChiMinhCity).add_link(Manila);
    this->cities.at(HongKong).add_link(Bangkok);
    this->cities.at(HongKong).add_link(Kolkata);
    this->cities.at(HongKong).add_link(HoChiMinhCity);
    this->cities.at(HongKong).add_link(Shanghai);
    this->cities.at(HongKong).add_link(Manila);
    this->cities.at(HongKong).add_link(Taipei);
    this->cities.at(Istanbul).add_link(Milan);
    this->cities.at(Istanbul).add_link(Algiers);
    this->cities.at(Istanbul).add_link(StPetersburg);
    this->cities.at(Istanbul).add_link(Cairo);
    this->cities.at(Istanbul).add_link(Baghdad);
    this->cities.at(Istanbul).add_link(Moscow);
    this->cities.at(Jakarta).add_link(Chennai);
    this->cities.at(Jakarta).add_link(Bangkok);
    this->cities.at(Jakarta).add_link(HoChiMinhCity);
    this->cities.at(Jakarta).add_link(Sydney);
    this->cities.at(Johannesburg).add_link(Kinshasa);
    this->cities.at(Johannesburg).add_link(Khartoum);
    this->cities.at(Karachi).add_link(Tehran);
    this->cities.at(Karachi).add_link(Baghdad);
    this->cities.at(Karachi).add_link(Riyadh);
    this->cities.at(Karachi).add_link(Mumbai);
    this->cities.at(Karachi).add_link(Delhi);
    this->cities.at(Khartoum).add_link(Cairo);
    this->cities.at(Khartoum).add_link(Lagos);
    this->cities.at(Khartoum).add_link(Kinshasa);
    this->cities.at(Khartoum).add_link(Johannesburg);
    this->cities.at(Kinshasa).add_link(Lagos);
    this->cities.at(Kinshasa).add_link(Khartoum);
    this->cities.at(Kinshasa).add_link(Johannesburg);
    this->cities.at(Kolkata).add_link(Delhi);
    this->cities.at(Kolkata).add_link(Chennai);
    this->cities.at(Kolkata).add_link(Bangkok);
    this->cities.at(Kolkata).add_link(HongKong);
    this->cities.at(Lagos).add_link(SaoPaulo);
    this->cities.at(Lagos).add_link(Khartoum);
    this->cities.at(Lagos).add_link(Kinshasa);
    this->cities.at(Lima).add_link(MexicoCity);
    this->cities.at(Lima).add_link(Bogota);
    this->cities.at(Lima).add_link(Santiago);
    this->cities.at(London).add_link(NewYork);
    this->cities.at(London).add_link(Madrid);
    this->cities.at(London).add_link(Essen);
    this->cities.at(London).add_link(Paris);
    this->cities.at(LosAngeles).add_link(SanFrancisco);
    this->cities.at(LosAngeles).add_link(Chicago);
    this->cities.at(LosAngeles).add_link(MexicoCity);
    this->cities.at(LosAngeles).add_link(Sydney);
    this->cities.at(Madrid).add_link(London);
    this->cities.at(Madrid).add_link(NewYork);
    this->cities.at(Madrid).add_link(Paris);
    this->cities.at(Madrid).add_link(SaoPaulo);
    this->cities.at(Madrid).add_link(Algiers);
    this->cities.at(Manila).add_link(Taipei);
    this->cities.at(Manila).add_link(SanFrancisco);
    this->cities.at(Manila).add_link(HoChiMinhCity);
    this->cities.at(Manila).add_link(Sydney);
    this->cities.at(Manila).add_link(HongKong);
    this->cities.at(MexicoCity).add_link(LosAngeles);
    this->cities.at(MexicoCity).add_link(Chicago);
    this->cities.at(MexicoCity).add_link(Miami);
    this->cities.at(MexicoCity).add_link(Lima);
    this->cities.at(MexicoCity).add_link(Bogota);
    this->cities.at(Miami).add_link(Atlanta);
    this->cities.at(Miami).add_link(MexicoCity);
    this->cities.at(Miami).add_link(Washington);
    this->cities.at(Miami).add_link(Bogota);
    this->cities.at(Milan).add_link(Essen);
    this->cities.at(Milan).add_link(Paris);
    this->cities.at(Milan).add_link(Istanbul);
    this->cities.at(Montreal).add_link(Chicago);
    this->cities.at(Montreal).add_link(Washington);
    this->cities.at(Montreal).add_link(NewYork);
    this->cities.at(Moscow).add_link(StPetersburg);
    this->cities.at(Moscow).add_link(Istanbul);
    this->cities.at(Moscow).add_link(Tehran);
    this->cities.at(Mumbai).add_link(Karachi);
    this->cities.at(Mumbai).add_link(Delhi);
    this->cities.at(Mumbai).add_link(Chennai);
    this->cities.at(NewYork).add_link(Montreal);
    this->cities.at(NewYork).add_link(Washington);
    this->cities.at(NewYork).add_link(London);
    this->cities.at(NewYork).add_link(Madrid);
    this->cities.at(Osaka).add_link(Taipei);
    this->cities.at(Osaka).add_link(Tokyo);
    this->cities.at(Paris).add_link(Algiers);
    this->cities.at(Paris).add_link(Essen);
    this->cities.at(Paris).add_link(Madrid);
    this->cities.at(Paris).add_link(Milan);
    this->cities.at(Paris).add_link(London);
    this->cities.at(Riyadh).add_link(Baghdad);
    this->cities.at(Riyadh).add_link(Cairo);
    this->cities.at(Riyadh).add_link(Karachi);
    this->cities.at(SanFrancisco).add_link(LosAngeles);
    this->cities.at(SanFrancisco).add_link(Chicago);
    this->cities.at(SanFrancisco).add_link(Tokyo);
    this->cities.at(SanFrancisco).add_link(Manila);
    this->cities.at(Santiago).add_link(Lima);
    this->cities.at(SaoPaulo).add_link(Bogota);
    this->cities.at(SaoPaulo).add_link(BuenosAires);
    this->cities.at(SaoPaulo).add_link(Lagos);
    this->cities.at(SaoPaulo).add_link(Madrid);
    this->cities.at(Seoul).add_link(Beijing);
    this->cities.at(Seoul).add_link(Shanghai);
    this->cities.at(Seoul).add_link(Tokyo);
    this->cities.at(Shanghai).add_link(Beijing);
    this->cities.at(Shanghai).add_link(HongKong);
    this->cities.at(Shanghai).add_link(Taipei);
    this->cities.at(Shanghai).add_link(Seoul);
    this->cities.at(Shanghai).add_link(Tokyo);
    this->cities.at(StPetersburg).add_link(Essen);
    this->cities.at(StPetersburg).add_link(Istanbul);
    this->cities.at(StPetersburg).add_link(Moscow);
    this->cities.at(Sydney).add_link(Jakarta);
    this->cities.at(Sydney).add_link(Manila);
    this->cities.at(Sydney).add_link(LosAngeles);
    this->cities.at(Taipei).add_link(Shanghai);
    this->cities.at(Taipei).add_link(HongKong);
    this->cities.at(Taipei).add_link(Osaka);
    this->cities.at(Taipei).add_link(Manila);
    this->cities.at(Tehran).add_link(Baghdad);
    this->cities.at(Tehran).add_link(Moscow);
    this->cities.at(Tehran).add_link(Karachi);
    this->cities.at(Tehran).add_link(Delhi);
    this->cities.at(Tokyo).add_link(Seoul);
    this->cities.at(Tokyo).add_link(Shanghai);
    this->cities.at(Tokyo).add_link(Osaka);
    this->cities.at(Tokyo).add_link(SanFrancisco);
    this->cities.at(Washington).add_link(Atlanta);
    this->cities.at(Washington).add_link(NewYork);
    this->cities.at(Washington).add_link(Montreal);
    this->cities.at(Washington).add_link(Miami);

}

void Board::load_colors(){
    this->colors.insert({Yellow, ColorInfo(Yellow)});
    this->colors.insert({Black, ColorInfo(Black)});
    this->colors.insert({Red, ColorInfo(Red)});
    this->colors.insert({Blue, ColorInfo(Blue)});
}

int& Board::operator[](City c) {
    return this->get_city_info(c).disease_count;
}

bool Board::is_clean(){
    for(auto &kv: this->cities){
        // Can also maintain a global disease counter
        if(kv.second.disease_count > 0){
            return false;
        }
    }
    return true;
}

void Board::remove_cures(){
    for(auto &kv: this->colors){
        ColorInfo &ci = kv.second;
        ci.has_cure = false;
    }
};

CityInfo& Board::get_city_info(City c){
    std::unordered_map<City, CityInfo>::iterator it = this->cities.find(c);
    if(it == this->cities.end()){
        throw std::runtime_error("City not found.");
    }

    return it->second;
}


ColorInfo& Board::get_color_info(ColorInfo c){
    std::unordered_map<Color, ColorInfo>::iterator it = this->colors.find(c.color);

    if(it == this->colors.end()){
        throw std::runtime_error("Color not found.");
    }

    return it->second;
}
std::ostream& pandemic::operator<<(std::ostream& os, const pandemic::Board& b)
{
   return os;
}

