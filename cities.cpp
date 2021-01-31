#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<stdlib.h>
#include<iomanip>
#include<cmath>
#include<algorithm>

using namespace std;

float const PI = 3.1415928;
int const EARTHRADIUS = 3961;

struct CITY // used to store information about each city given in file
{
  string name;
  float latitude;
  float longitude;
};

struct CITYINFO // stores information regarding a city in relation to another
{
  string name;
  float dist;
};

// reads in the file containing all the city and city data and outputs a vector of structs
vector<CITY> readFile(string filename)
{
  ifstream file;
  file.open(filename);
  if(!file.is_open()) cout << "Could not open file." << endl;
  string line;
  vector<CITY> cities;
  while(getline(file,line))
  {
    stringstream ss(line);
    CITY temp;
    ss>>temp.name;
    ss>>temp.latitude;
    ss>>temp.longitude;
    cities.push_back(temp);
  }
  return cities;
}

// converts degrees to radians
float radians(float degrees)
{
  return degrees * (PI/180);
}

// distance between latitude and longitude using haversine's formula
float distance(CITY one, CITY two)
{
  float lat1 = radians(one.latitude);
  float lon1 = radians(one.longitude);
  float lat2 = radians(two.latitude);
  float lon2 = radians(two.longitude);

  float dlon = lon2 - lon1;
  float dlat = lat2 - lat1;
  float a = pow((sin(dlat/2)),2) + cos(lat1) * cos(lat2) * pow((sin(dlon/2)),2) ;
  float c = 2 * atan2(sqrt(a),sqrt(1-a));
  float d = EARTHRADIUS * c;

  return d;
}

// finds the closest city to a given city
CITYINFO closest(CITY homeCity, vector<CITY> cities)
{
  CITYINFO min;
  min.dist = 9999999;
  for(int i = 0; i < cities.size(); i++)
  {
    if(cities.at(i).name==homeCity.name) continue;
    float dist = distance(homeCity,cities.at(i));
    if(dist<min.dist)
    {
      min.name = cities.at(i).name;
      min.dist = dist;
    }
  }
  return min;
}

// finds the farthest city to a given city
CITYINFO farthest(CITY homeCity, vector<CITY> cities)
{
  CITYINFO max;
  max.dist = 0;
  for(int i = 0; i < cities.size(); i++)
  {
    if(cities.at(i).name==homeCity.name) continue;
    float dist = distance(homeCity,cities.at(i));
    if(dist>max.dist)
    {
      max.name = cities.at(i).name;
      max.dist = dist;
    }
  }
  return max;
}

// finds the two closest cities of all given cities
vector<string> twoClosest(vector<CITY> cities)
{
  CITY one;
  CITY two;
  float dist = 999999;
  vector<string> ret;
  for(int i = 0; i < cities.size(); i++)
  {
    for(int j = 0; j < cities.size(); j++)
    {
      if(cities.at(i).name==cities.at(j).name) continue;
      float tempDist = distance(cities.at(i),cities.at(j));
      if(tempDist<dist)
      {
        one = cities.at(i);
        two = cities.at(j);
        dist = tempDist;
      }
    }
  }
  ret.push_back(one.name);
  ret.push_back(two.name);
  ret.push_back(to_string(dist));
  return ret;
}

// finds the two farthest cities of all given cities
vector<string> twoFarthest(vector<CITY> cities)
{
  CITY one;
  CITY two;
  float dist = 0;
  vector<string> ret;
  for(int i = 0; i < cities.size(); i++)
  {
    for(int j = 0; j < cities.size(); j++)
    {
      if(cities.at(i).name==cities.at(j).name) continue;
      float tempDist = distance(cities.at(i),cities.at(j));
      if(tempDist>dist)
      {
        one = cities.at(i);
        two = cities.at(j);
        dist = tempDist;
      }
    }
  }
  ret.push_back(one.name);
  ret.push_back(two.name);
  ret.push_back(to_string(dist));
  return ret;
}

// how to compare CITYINFO's, (ascending dist)
int comp(CITYINFO a, CITYINFO b)
{
  return a.dist<b.dist;
}

// finds the closest cities to a given city
vector<CITYINFO> Nclosest(int testCityIndex, int count, vector<CITY> cities)
{
  vector<CITYINFO> cityInfos;
  for(int i = 0; i < cities.size(); i++)
  {
    if(i==testCityIndex) continue;
    float tempDist = distance(cities.at(testCityIndex),cities.at(i));
    CITYINFO tempCityInfo;
    tempCityInfo.name = cities.at(i).name;
    tempCityInfo.dist = tempDist;
    cityInfos.push_back(tempCityInfo);
  }
  sort(cityInfos.begin(),cityInfos.end(),comp);
  return cityInfos;
}

// find a city in the vecotr of cities
int findCity(string testCity, vector<CITY> cities)
{
  for(int i = 0; i < cities.size(); i++)
  {
    if(cities.at(i).name==testCity)
      return i;
  }
  return -1;
}

main(int argc, char** argv)
{
  vector<CITY> cities = readFile(argv[1]);
  if(argv[2]==NULL) // what to do if no specific city is given
  {
    for(int i = 0; i < cities.size(); i++)
    {
      CITYINFO close = closest(cities.at(i),cities);
      CITYINFO far = farthest(cities.at(i),cities);
      cout << setw(20) << left << cities.at(i).name << "closest=" << setw(20) << close.name;
      cout << "(" << fixed << setprecision(1) << setw(5) << close.dist << " mi), farthest=";
      cout << setw(20) << left << far.name << "(" << fixed << setprecision(1) << far.dist << " mi)" << endl;
    }

    cout << endl << endl;
    vector<string> twoClose = twoClosest(cities);
    vector<string> twoFar = twoFarthest(cities);

    cout << "closest cities: " << twoClose[0] << " and " << twoClose[1] << ", dist=" << setprecision(1);
    cout << stof(twoClose[2]) << " mi" << endl;
    cout << "farthest cities: " << twoFar[0] << " and " << twoFar[1] << ", dist=" << setprecision(1);
    cout << stof(twoFar[2]) << " mi" << endl;
  }
  else if(argv[2]!=NULL) // what to do if a given city and number of close cities is given
  {
    string testCity = argv[2];
    if(argv[3]==NULL) cout << "Please enter how many cities near your given city to show" << endl;
    else
    {
      int count = stoi(argv[3]);
      int index = findCity(testCity, cities);
      if(index==-1) cout << "Please enter a correct city" << endl;
      else
      {
        vector<CITYINFO> closeCities = Nclosest(index, count, cities);
        for(int i = 0; i < count; i++)
        {
          cout << closeCities.at(i).name << " (" << fixed << setprecision(1) << closeCities.at(i).dist;
          cout << " mi)" << endl;
        }
      }
    }
  }

}
