/*****************************************************************
//
// NAME: 			Lambert Leong
//
// HOMEWORK:		HW10
//
// CLASS: 			ICS 212
//
// INSTRUCTOR: 		Ravi Narayan
//
// DATE: 			August 8, 2016
//
// FILE: 			main
//
// DESCRIPTION: 	contains main
//
//****************************************************************/

#include "cow.h"
#include "bird.h"

using namespace std;
int main()
{
    int i;
    cow cow1, cow2;
    bird bird1, bird2;
    
    vector<animal*> animalptrs;
    map<string, cow*> cowmap;
    map<string, bird*> birdmap;
    
    cowmap["cowone"] = &cow1;
    cowmap["cowtwo"] = &cow2;
    birdmap["birdone"] = &bird1;
    birdmap["birdtwo"] = &bird2;
    
    animalptrs.push_back(birdmap["birdone"]);
    animalptrs.push_back(birdmap["birdtwo"]);
    animalptrs.push_back(cowmap["cowone"]);
    animalptrs.push_back(cowmap["cowtwo"]);
    
    i=0;
    while(i<animalptrs.size())
    {
        animalptrs[i]->displaydata();
        /*animalptrs[i]->animaldisplaydata(animalptrs[i]);*/
        cout<<endl;
        i++;
    }    
    
    cout<<"Clipping wings of bird1 \n\n";
    
    bird1.clipwings();
    
    i=0;
    while(i<animalptrs.size())
    {
        /*animalptrs[i]->displaydata();*/
        animalptrs[i]->animaldisplaydata(animalptrs[i]);
        cout<<endl;
        i++;
    } 
    return 1;
}
