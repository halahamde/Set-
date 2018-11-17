// Course:  CS213 - Programming II  - 2018
// Title:   Assignment III -Task2
// Purpose: Finding number of ways can be found the target in the set
// Author:  Eng. Hala hamdy
// Date:    16 Novamber 2018
// Version: 1.0
#include <iostream>
#include<set>
using namespace std;

int Size ;
// Purpose : Finding number of ways can be found the target in the set
int countSubsetSumWays( set<int> & Set, int target)
{
    int counter = 0 ;
    set<int> Subset ;
    set<int> :: iterator it  ;
    set<int> :: iterator it1  ;

    it = Set.begin() ;
//Purpose: this loop to create a new set and store in this set the elements from the old set but from the next element
    for ( int i = 0 ; i < Size-1  ; i++)
    {
        Subset.insert(*++it) ;
    }
// purpose : this loop to check how many ways can be found the target
    for ( it = Set.begin() ; it != Set.end() ; it++  )
    {
        if ( target == *it )
        {
            counter++ ;
        }
        for ( it1 = Subset.begin() ; it1 != Subset.end() ; it1++ )
        {
            if ( target == ( *it + *it1 ) )
            {
                counter++ ;
            }
        }
        it1 = Subset.begin() ;
        Subset.erase(*it1) ;
    }
    return counter ;
}

int main()
{
    int x , y ;
    int counter = 0 ;
    set<int> :: iterator it  ;
    cout << "Enter size of the Set: " ;
    cin >> Size ;
    set<int> sampleSet ;
    for ( int i = 0 ; i < Size ; i++)
    {
        cin >> x ;
        sampleSet.insert(x) ;
    }
    cout << "The set is : "  ;
    for ( it = sampleSet.begin() ; it != sampleSet.end() ; it++ )
    {
        cout << *it << " " ;
    }
    cout << endl << "Enter the target: " ;
    cin >> y ;
    cout << "Target can be found by : " << countSubsetSumWays(sampleSet, y );
    cout <<" "<< "ways" ;
    return 0;
}
