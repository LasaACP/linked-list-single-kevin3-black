//
//  main.cpp
//  LLTemplate
//
//  Created by James Shockey on 12/6/16.
//  Copyright © 2016 James Shockey. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include "slist.h"

using namespace std;


void quicksort(LinkedList<Airport*> *l, int left, int right);
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d);

int main()
{
    ifstream infile;
    int i=0;
    char cNum[20] ;
    Airport* airportArr[140000];
    int   airportCount;
    Airport* AUS;
    //Airport* a[13500];

    infile.open ("./USAirportCodes.csv", ifstream::in);
    if (infile.is_open())
    {
        int   c=0;
        while (infile.good())
        {
            airportArr[c] = new Airport();
            infile.getline(airportArr[c]->code, 256, ',');
            infile.getline(cNum, 256, ',');
            airportArr[c]->longitude = atof(cNum);
            infile.getline(cNum, 256, '\n');
            airportArr[c]->latitude = atof(cNum);

            if (std::strcmp(airportArr[c]->code, "AUS") == 0) AUS = airportArr[i];
            //cout << airportArr[c]->code << " long: " << airportArr[c]->longitude << " lat: " << airportArr[c]->latitude <<  endl;

            /*
            if (!(c % 1000))
            {
                cout << airportArr[c]->code << " long: " << airportArr[c]->longitude << " lat: " << airportArr[c]->latitude <<  endl;
                cout << airportArr[c+1]->code << endl; //" long: " << airportArr[c+1]->longitude << " lat: " << airportArr[c+1]->latitude <<  endl;
            }
            */


            i++ ;
            c++;
        }
        airportCount = c-1;
        infile.close();

        for (int j=0; j < airportCount; j++) {
          airportArr[j]->distanceAUS = distanceEarth(AUS->longitude, AUS->latitude, airportArr[j]->longitude, airportArr[j]->latitude);
         }
    }

    else
    {
        cout << "Error opening file";
    }


    LinkedList<Airport*> *l = new LinkedList<Airport*>();
    for (int i = 0; i < airportCount; i++) {
      l->add(airportArr[i]);
    }
    quicksort(l, 0, airportCount-1);

    for (int i = 0; i < airportCount; i++) {
      cout << l->get(i)->code << " " << l->get(i)->longitude << " " << l->get(i)->latitude << ' ' << l->get(i)->distanceAUS << '\n';
    }



}



#define pi 3.14159265358979323846
#define earthRadiusKm 6371.0

// This function converts decimal degrees to radians
double deg2rad(double deg) {
  return (deg * pi / 180);
}

//  This function converts radians to decimal degrees
double rad2deg(double rad) {
  return (rad * 180 / pi);
}


/**
 * Returns the distance between two points on the Earth.
 * Direct translation from http://en.wikipedia.org/wiki/Haversine_formula
 * @param lat1d Latitude of the first point in degrees
 * @param lon1d Longitude of the first point in degrees
 * @param lat2d Latitude of the second point in degrees
 * @param lon2d Longitude of the second point in degrees
 * @return The distance between the two points in kilometers
 */
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d) {
  double lat1r, lon1r, lat2r, lon2r, u, v;
  lat1r = deg2rad(lat1d);
  lon1r = deg2rad(lon1d);
  lat2r = deg2rad(lat2d);
  lon2r = deg2rad(lon2d);
  u = sin((lat2r - lat1r)/2);
  v = sin((lon2r - lon1r)/2);
  return 2.0 * earthRadiusKm * asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v));
}




void quicksort(LinkedList<Airport*> *l, int left, int right) {
  int i = left, j = right;
  double pivot = l->get((left + right) / 2)->distanceAUS;
  while (i <= j) {
    while (l->get(i)->distanceAUS < pivot)
      i++;
    while (l->get(j)->distanceAUS > pivot)
      j--;
    if (i <= j) {
      l->exchg(i, j);
      i++;
      j--;
    }
  }

  /* recursion */
  if (left < j)
    quicksort(l, left, j);
  if (i < right)
    quicksort(l, i, right);

}

