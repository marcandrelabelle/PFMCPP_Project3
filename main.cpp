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

struct EchoMachine
{
    //number of playback head
    int numPlaybackHead = 4;
    //head spacing in inch
    float headSpacing = 1.2f;
    //tape saturation (input gain preamp)
    float tapeSaturation = 9.9f;  
    //spring reverb mix
    float springReverbMix = 5.0f;
    //output level nomalized
    float outputLvl = 0.85f;

    struct Overdrive 
    {
        float clippingPoint = 0.8f;
        float lowPassFreq = 800.f;
        int inputSigIndex = 1;
        float sigMix = 0.5f;
        float outputLvl = 0.7f;

        void limitSig (int inputSig, int limiTresh, bool autoMakeUpGain);
        void filterSig (int inputSigIndex, float q, float freq, std::string filterType);
        void distortionType (char distoType);
    };

    //distort signal
    void distorSignal (Overdrive overDriveSig);
    //repeat sound source
    void repeatSoundSource (bool repeatState, float loopStart, float loopEnd);
    //play tape slower or faster
    void tapeSpeed (bool playTape, int tapeSpeed);
};

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

struct SolideStateAmp
{
    //number of speakers
    int numSpeakers = 2;
    //speaker size in inch;
    float speakerSize = 12.0f;
    //master level
    float masterLvl = 6.3f;
    //number of amp modeling presets
    int ampModelingPresets = 99;
    //fx level
    float fxvl = 4.3f;


    //digital signal processing
    void signalProcessing (bool processSignal, int sampleStart, int sampleEnd);
    //imitate tube amp 
    void imitateTubeAmp (int ampSelectIndex, std::string speakerIr); 
    //amplifie sound
    void amplifieSound (int inputSig, float gain);

};

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

struct SamplingPad
{
    //number of pads
    int numPads = 8;
    //number of intergrated instruments
    int numIntergratedInst = 25; 
    //stereo or mono output
    bool stereoOut = true; 
    //amount of sampling  memory space in sec
    int samplingSpaceSec = 120;
    //number of integrated effects
    int numIntegratedFx = 12;

    //trigger  .wav sounds
    void trigSnd (int padIndex, bool trig);
    //play a sequence
    void playSequence (int numSteps, int bpm, bool startSequence);
    //send midi
    void sendMidi (int midiNoteNum, int midiVel, bool noteEvent, bool isCc);
};

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

struct AnalogConsole
{
    //number of channel strips
    int numChannelStrips = 24;
    //number of audio send
    int numAudioSend = 2; 
    //number of monitor out
    int numMonitorOut = 4;
    //number of steroe chanels
    int numStereoChanels = 2;
    //pre or post EQ selector
    bool preFader = false;

    //Mix different sounds together
    void mixSounds (int trackNum, float trackLvl, float pan); 
    //contrôl master output level
    void masterOut (float masterOutdB);
    //add tone
    void addTone (float hiFreq, float hiBoost, float midFreq, float midBoost, float bassFreq, float bassBoost);
};

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

struct DawMixer
{
    //maximum number of faders
    int maxNumFaders = 175;
    //Pan knob middle position value range from -1.0 to 1.0
    float panPos = 0.0f; 
    //record btn diameter in pixels
    float recBtnDiameter = 45.5f;
    //slider length
    float sliderLenght = 250.25f;
    //number of inserts
    int numInserts = 20;

    //record audio on track
    void recordReady (bool recordOn);
    //pan sound
    void panSnd (float pan);
    //change audio volume
    void audioVolume (float laudioLvl);

};

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

struct VirtualMidiKey
{
    //number of octaves
    int numOctaves = 6; 
    //number of MIDI channel
    int numMidiChanels = 32;
    //keyboard size in pixel
    int keyboardSize = 500; 
    //key colours
    bool invertKeyColour = false;
    //velocity range
    int velocityRange = 127;

    //send midi notes 
    void sendMidi (int keyIndex, int velocity);
    //display MIDI numbers (note to MIDI)
    int displayMidi (char noteName);
    //recieve input from computer keyboard
    void receiveInputKey (int inputNum, int midiChanel);
};

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

struct ToolbarDocker
{
    //number of tools in docker
    int numDockerTools = 12;
    //tool selector size in pixels 
    float toolSelectorSize = 25.5f;
    //docker position 
    float dockerPosX = 255.0f;
    //docker size
    float dockerWidth = 500.0f;
    //number of row
    int numDockerRow = 2;

    //change tool for editing
    void changeTool (int toolListIndex, int replaceIndex);
    //customize displayed tools
    void customizeTool (int indexSwitch, int newToolIndex);
    //activate metronom
    void activateMetronom (bool mentroPlay);

};

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

struct PerformanceMeter
{
    //text size
    int textSize = 17;
    //window size
    float windowSize = 1080.0f;
    //font style
    std::string fontStyle = "arial";
    //background colour
    std::string backGroundColor = "green";
    //CPU graph clock speed in ms
    double cpuClockSpeed = 0.00025;

    //display CPU
    void displayCpu (int posX, int posY, float width, float height,bool active, double cpuClock);
    //display RAM use
    void displayRam (int posX, int posY, float width, float height,bool active);
    //display Disk read in Bytes/s
    void displayDiskRead (int posX, int posY, float width, float height, bool active);
};

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

struct TempoEnv
{
    //bpm
    int bpm = 128;
    //default point shape ( linear/square )
    bool linearPointShape = true;
    //number of points
    int numPoints = 200;    //tempo signature
    //tempo signature in 
    std::string tempoSignature = "7/8";
    //enveloppe line colour
    std::string envLineColour = "purple";

    //change tempo bpm
    void changeBpm (int newBpm);
    //create new point
    void newPoint (int newPointPosX, int newPointPosY, bool pointShap); 
    //reduce number of points
    void deletePoint (int pointIndex);

};

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

struct DigitalWorkstation
{
    //Mixer
    DawMixer mixer;
    //Virtual MIDI Keyboard
    VirtualMidiKey midiKeys;
    //Toolbar Docker
    ToolbarDocker toolDocker;
    //Performance Meter
    PerformanceMeter perfoMeter;
    //Tempo Enveloppe
    TempoEnv tempoEnveloppe;

    struct TransportBar
    {
        bool transportBarShow = true;
        bool playBtnActive = false;
        bool showPlayRate = true;
        float sartTimeSelectionPoint = 0.0f;
        float endTimeSelectionPoint = 24.0f;

        void loopSelection(bool loopSelcetion);
        int tapTempoBpm (int numTap, float time);
        void moveCursorPos (int beat, int mesure);
    };

    //loop audio and midi sections
    void loopAudioSection (float loopIn, float loopOut);
    //record audio and midi performance 
    void recordData (int input, bool isMidi);
    //mix multiple recordings and tracks into a final produced
    void bounce (int tracks, float startingPoint, float endingPoint);
};

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
