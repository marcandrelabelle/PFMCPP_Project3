/*
Project 3 - Part 1e / 5
Video:  Chapter 2 Part 5
User-Defined Types

Continue your work on branch Part1

Purpose: The entire purpose of this 5-part project is to get you writing C++ code that compiles and to 
reinforce the syntax habits that C++ requires.  
What you create in this project will be used as the basis of Project 5 in the course.   

************************
Part1 purpose:  Learn to write UDTs

You are going to write 10 UDTs in project3.  
    Part 1a: you will learn to think about an object in terms of its sub-objects.
    Part 1b: you will write 4 un-related UDTs in plain english
    Part 1c: you will write 1 UDT in plain english that will be made of 5 related sub-objects
    Part 1d: you will write plain-english UDTs for the 5 sub-objects that form the UDT defined in Part 1c
    Part 1e: you will convert those 10 plain-english UDTs into code that runs.
************************

Convert your 10 Plain-english UDTs into code.

I recommend compiling after finishing each one and making sure it compiles 
without errors or warnings before moving on to writing the next UDT. 

1) define an empty struct for each of your 10 types. i.e.:
*/
struct CellPhone
{

};
/*
2) Copy your 5 properties & 3 actions into the empty struct body.
    - comment them out.
    
3) declare your member variables and member functions underneath each plain-english comment in your struct's body.
    - give the member variables relevant data types
 
4) make the function parameter list for those member functions use some of your User-Defined Types
    - You'll write definitions/implementations for these functions in Project3 Part2
    - you'll call each of these functions in Project3 part3
 
5) make 2 of the 10 user-defined types have a nested class.  
    - this nested class also needs 5 properties and 3 actions.
    - these nested classes are not considered one of your 10 UDTs.
    - this nested class must be related to the class it is nested inside
 
6) your 10th UDT's properties should be instances of your #5-#9 UDTs.   
    - No primitives allowed!
 
7) After you finish defining each type, click the [run] button.  
    Clear up any errors or warnings as best you can. 
 */

/*
 example:  

Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#include <iostream>
#include <string>

struct CarWash //                                   1) define an empty struct for each of your 10 types.       
{
    //number of vacuum cleaners                     2) copied and commented-out plain-english property
    int numVacuumCleaners = 3; //                   3) member variables with relevant data types.
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car //5)                                 Note that the nested type 'Car' is related to the 'CarWash' 
    {
        //2) member variables with relevant data types.  the names are appropriate for the U.D.T.'s purpose.
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        //3) a member function whose parameter has a default value.
        //the parameter name is related to the work the function will perform.
        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar( Car car ); //4) a member function whose parameter is a UDT.
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior( Car car );
    
    //5) a member variable whose type is a UDT.
    Car carBeingServiced;  
};




/*
Thing 1) multi-head echo machines
5 properties:
    1) number of playback head 
    2) head spacing  
    3) tape saturation (input gain preamp)  
    4) spring reverb mix
    5) output level
3 things it can do:
    1) distort signal
    2) repeat sound source
    3) play tape slower or faster
 */

/*
Thing 2) solid state guitar amp
5 properties:
    1) number of speakers
    2) speaker size 
    3) master level
    4) number of amp modeling presets
    5) fx level
3 things it can do:
    1) digital signal processing
    2) imitate tube amp  
    3) amplifie sound 
 */

/*
Thing 3) Sampling Pad
5 properties:
    1) number of pads
    2) number of intergrated instruments 
    3) stereo or mono output 
    4) amount of sampling  memory space in sec
    5) number of integrated effects
3 things it can do:
    1) trigger  .wav sounds
    2) play a sequence
    3) send midi
 */

/*
Thing 4) analog console 
5 properties:
    1) number of channel strips
    2) number of audio send
    3) number of monitor out
    4) number of steroe chanels
    5) pre or post EQ selector
3 things it can do:
    1) Mix different sounds together 
    2) contrôl master output level
    3) add tone
 */

/*
Thing 5) Mixer
5 properties:
    1) maximum number of faders 
    2) Pan knob middle position value 
    3) record btn diameter 
    4) slider length
    5) number of inserts 
3 things it can do:
    1) record audio on track
    2) pan sound
    3) change audio volume  
 */

/*
Thing 6) Virtual MIDI Keyboard
5 properties:
    1) number of octaves 
    2) number of MIDI channel
    3) keyboard size in pixel 
    4) key colours
    5) velocity range 
3 things it can do:
    1) send midi notes 
    2) display MIDI numbers (note to MIDI)
    3) recieve input from computer keyboard
 */

/*
Thing 7) Toolbar Docker
5 properties:
    1) number of tools in docker
    2) tool selector size  
    3) docker position 
    4) docker size
    5) number of row
3 things it can do:
    1) change tool for editing
    2) customize displayed tools
    3) activate metronom
 */

/*
Thing 8) Performance Meter
5 properties:
    1) text size 
    2) window size
    3) font style
    4) background colour
    5) CPU graph clock speed 
3 things it can do:
    1) display CPU
    2) display RAM use
    3) display Disk read in Bytes/s
 */

/*
Thing 9) Tempo Enveloppe
5 properties:
    1) bpm
    2) default point shape ( linear/square )
    3) number of points
    4) tempo signature
    5) enveloppe line colour 
3 things it can do:
    1) change tempo bpm
    2) create new point 
    3) reduce number of points
 */

/*
Thing 10) Digital Audio Workstation (DAW)
5 properties:
    1) Mixer
    2) Virtual MIDI Keyboard
    3) Toolbar Docker
    4) Performance Meter
    5) Tempo Enveloppe 
3 things it can do:
    1) loop audio and midi sections
    2) record audio and midi performance 
    3) mix multiple recordings and tracks into a final       produced
 */

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main()
{
    std::cout << "good to go!" << std::endl;
}
